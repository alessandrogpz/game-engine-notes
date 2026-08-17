# C++17 Concurrency Primitives

This note covers the concurrency toolkit available up to **C++17**: launching
threads, the two ways to make shared state safe (mutexes and atomics), waiting
without burning CPU (condition variables), and the failure modes of each. The
scope here is the correctness and cost of the primitives themselves.

> [!NOTE]
> **In this folder**
> * [`multi_threading.md`](../../08_Systems_and_Performance/01_Data_Oriented_Design/03_Multi_Threading/Multi_Threading.md) — The DOD angle: why a fast program avoids these primitives in hot loops.
> * [`concurrency_glossary.md`](./Concurrency_Glossary.md) — One-line lookup for each class and function.
> * [`multi_threading.cpp`](./multi_threading.cpp) — Chef-customer queue simulation.

---

## 1. Launching Threads

```cpp
std::thread thread_name(callable, arg1, arg2, ...);
```

The callable is any function, functor, or lambda. The arguments are **copied
into the thread's own storage** — this is the rule that explains everything
below.

* **A reference parameter needs `std::ref`.** The copy would otherwise bind to
  a temporary, and the caller's variable would never change.
  ```cpp
  void increment(int& i);

  int count{};
  std::thread t1(increment, std::ref(count));
  ```
* **A pointer parameter is passed directly.** Copying a pointer still points at
  the same object.
  ```cpp
  void increment(int* i);

  int count{};
  std::thread t1(increment, &count);
  ```

### Every thread must be joined or detached

A `std::thread` that is destroyed while still joinable calls `std::terminate()`
— the program aborts. `.join()` must therefore run on **every** exit path,
including the ones an early `return` or a thrown exception takes.

> [!NOTE]
> C++20's `std::jthread` joins in its own destructor and removes this hazard
> entirely. See **[[concurrency_cpp20]]**.

---

## 2. Race Conditions

Two threads writing the same variable with no synchronization is a **data
race**: `count++` compiles to load / add / store, and the threads interleave
between those instructions, so updates are silently lost.

### Detecting them: ThreadSanitizer

Races are non-deterministic — a clean run proves nothing. TSan instruments
memory accesses and reports the race even when the timing happened to work out.

```bash
c++ -std=c++17 -pthread -g -O1 -fsanitize=thread main.cpp -o tsan_test
./tsan_test
```

Or as a makefile target:

```make
debug:      CXXFLAGS += -g -O1 -fsanitize=thread
debug:      LDFLAGS  += -fsanitize=thread
debug:      re
```

**Cost: 5–15× slowdown and a sharp rise in memory use.** A debug tool, never a
release flag.

The fix is either a **mutex** or an **atomic**.

---

## 3. Mutex

A mutex is a lock only one thread can hold at a time. Anyone else trying to
acquire it blocks until the holder releases it.

```cpp
#include <mutex>

void increment(int& i, std::mutex& m)
{
    for (int n = 0; n < 1000000; n++)
    {
        std::lock_guard<std::mutex> lock(m);   // locks here
        i++;
    }                                          // unlocks here
}

int main()
{
    int count = 0;
    std::mutex m;

    std::thread t1(increment, std::ref(count), std::ref(m));
    std::thread t2(increment, std::ref(count), std::ref(m));

    t1.join();
    t2.join();

    return 0;
}
```

`std::lock_guard` locks on construction and unlocks on destruction (RAII), so
the lock survives early returns and exceptions.

> [!WARNING]
> Never write `m.lock()` / `m.unlock()` by hand. An early return or a thrown
> exception between the two leaves the mutex locked forever.

### Lock granularity is a design decision

Where the `lock_guard` sits changes the meaning of the program, not just its
speed:

* **Inside the loop** (as above) — the lock is taken and released a million
  times. Threads genuinely interleave, but each iteration pays lock overhead.
* **Outside the loop** — `t1` runs its entire loop, then `t2` runs its entire
  loop. Far faster (see the benchmark below), and completely serial. It
  produces a correct number by **defeating the point of using threads**.

Fast and pointless is not an optimisation. Which one is right depends on
whether the work inside the critical section actually needs to be interleaved.

### Hold the lock only as long as you touch shared data

The lock wrappers release at end of scope, so an explicit `unlock()` is an
**optimisation, not a requirement**. Anything slow inside a critical section —
I/O, sleeping, computation — blocks every other thread for no benefit.

Two ways to shorten the critical section:

```cpp
// 1. manual unlock — works, but fragile
lock.unlock();
std::cout << value << "\n";     // nothing below may touch shared data
```

```cpp
// 2. explicit block — preferred
int value;
{
    std::lock_guard<std::mutex> lock(m);
    value = shared_data.front();
    shared_data.pop();
}                               // released here, compiler-enforced
std::cout << value << "\n";
```

Identical lock duration; the block version is safer. After a manual `unlock()`,
code added later *looks* protected but isn't. Braces make the critical section
a visible, compiler-enforced boundary.

### `std::cout` is not a substitute for a print mutex

`std::cout` has internal locking, so concurrent writes are not a data race —
but it does **not** guarantee that two threads' output stays on separate lines.
Messages can interleave mid-line. If output must stay readable, use a dedicated
mutex held only around the write itself.

---

## 4. Atomic

For a single operation on a single variable, an atomic is the cheaper tool: the
read-modify-write becomes one indivisible hardware instruction, no lock needed.

```cpp
void increment(std::atomic<int>& i)
{
    for (int n = 0; n < 1000000; n++)
        i++;
}

int main()
{
    std::atomic<int> count = 0;

    std::thread t1(increment, std::ref(count));
    std::thread t2(increment, std::ref(count));

    t1.join();
    t2.join();

    return 0;
}
```

### Atomics don't compose

**Atomics protect single operations; mutexes protect multi-step logic that must
appear indivisible as a whole.** Each individual step below is atomic, and the
pair is still broken:

```cpp
std::atomic<int> balance{100};

// in two threads:
if (balance >= 100)
    balance -= 100;
```

Both threads evaluate `balance >= 100` against a value that is still 100,
because neither has subtracted yet. Both take the branch, both subtract, and
the balance ends at **-100**.

The check and the subtraction have to be one indivisible unit, which is exactly
what a mutex provides:

```cpp
{
    std::lock_guard<std::mutex> lock(m);
    if (balance >= 100)
        balance -= 100;
}
```

Now no other thread can observe or modify `balance` between the check and the
subtraction. Real programs use both tools: atomics for counters and flags,
mutexes for invariants spanning more than one operation.

---

## 5. The Cost of Synchronization

Two threads, 1,000,000 increments each. Expected count: 2,000,000.

| Variant | Runtime | Count | What it shows |
| :--- | ---: | ---: | :--- |
| Single thread, no sync | 1 ms | 2,000,000 | The baseline. |
| Two threads, no sync | 1 ms | **1,573,347** | Fast and **wrong** — ~21% of updates lost. |
| Mutex outside the loop | 1 ms | 2,000,000 | Correct, but fully serialized — the threads never overlap. |
| Mutex inside the loop | **63 ms** | 2,000,000 | Correct and genuinely concurrent — 63× the baseline in lock overhead. |
| `std::atomic<int>` | 9 ms | 2,000,000 | Correct, concurrent, ~7× cheaper than the mutex. |

Read as a hierarchy: **no sharing > atomic > mutex**. Even the atomic costs 9×
the single-threaded run, because every increment has to be made visible to the
other core. This is the measurement behind the DOD advice in
**[multi_threading](../../08_Systems_and_Performance/01_Data_Oriented_Design/03_Multi_Threading/Multi_Threading.md)** — give each thread its own
destination and combine the results once at the end, so no synchronization is
needed in the hot loop at all.

---

## 6. Condition Variables

Everything above assumes threads always have work. Sometimes a thread has to
wait for one — and polling for it is the wrong way:

```cpp
while (true)
{
    std::lock_guard<std::mutex> lock(m);
    if (work_is_available) { take_it(); break; }
}
```

This pins a core at 100% doing nothing, and holds the mutex while doing it. A
**condition variable** lets the thread sleep and be woken only when the state
it cares about has changed.

```cpp
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

int main()
{
    std::queue<int> q;
    std::mutex m;
    std::condition_variable cv;
    bool done = false;

    std::thread consumer([&]{
        while (true)
        {
            int value;
            {
                std::unique_lock<std::mutex> lock(m);
                cv.wait(lock, [&]{ return !q.empty() || done; });

                if (q.empty() && done)
                    break;

                value = q.front();
                q.pop();
            }                                   // lock released before the slow part
            std::cout << "consumed " << value << "\n";
        }
    });

    for (int i = 1; i <= 5; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        {
            std::lock_guard<std::mutex> lock(m);
            q.push(i);
        }
        cv.notify_one();
    }

    {
        std::lock_guard<std::mutex> lock(m);
        done = true;
    }
    cv.notify_all();

    consumer.join();
    return 0;
}
```

### What `cv.wait` actually does

`cv.wait(lock, predicate)` performs three steps **atomically**:

1. **Releases the mutex** — essential, or the producer could never lock it to push.
2. **Sleeps the thread** — zero CPU, no spinning.
3. **Reacquires the mutex on wake**, before returning.

So when `wait()` returns, you are holding the lock again and can safely touch
the shared data.

### Why the predicate is a loop, not a check

The predicate overload is shorthand for:

```cpp
while (!predicate())
    cv.wait(lock);
```

`while`, never `if`, for two reasons:

* **Spurious wakeups** — a thread may wake with nothing changed. The standard
  allows it and it happens in practice.
* **`notify_all` wakes everyone**, but only one can win the resource; the losers
  must go back to sleep.

Always use the predicate overload — it makes the loop impossible to forget.

### `unique_lock` vs `lock_guard`

`cv.wait` has to unlock and relock, so it requires `std::unique_lock`, which
supports manual unlock/relock. `std::lock_guard` cannot do this. **Waiter side:
`unique_lock`. Everywhere else: `lock_guard`.**

### `notify_one` vs `notify_all`

`notify_one()` wakes one waiting thread (unspecified which); `notify_all()`
wakes every waiter. Neither does anything if nobody is waiting — notifications
are not queued or remembered.

**`notify_one` is correct only when all waiters are interchangeable** and the
event satisfies exactly one of them: several identical consumers, one item
pushed, any of them can take it. Waking all of them would have three threads
wake, re-check, and go straight back to sleep — a **thundering herd**, pure
waste.

**`notify_all` is required when:**

* **Waiters have different predicates.** Three threads waiting on the same
  condvar for *different* resources: `notify_one` may wake a thread whose
  predicate is still false. It sleeps again, the thread that *could* have
  proceeded was never woken, and the notification is consumed and lost. That is
  a **lost wakeup**, and it hangs the program.
* **Shutdown.** Every thread has to exit, so every thread has to wake.
* **One event unblocks several waiters** at once.

> [!TIP]
> Use `notify_one` only when you can argue that *any* waiter can handle the
> event. Otherwise `notify_all`: slower but correct, where `notify_one` is
> faster but can hang.

### The shutdown trap

A thread blocked in `cv.wait` **cannot see a flag being set** — it is asleep.
Setting `done = true` on its own changes nothing. Correct shutdown needs all
three of:

1. Set the flag **under the mutex**.
2. Call `notify_all()`.
3. Include the flag in **every** predicate.

Miss any one and `join()` hangs forever.

### Timed waiting

```cpp
cv.wait_until(lock, time_point, predicate);   // absolute deadline
cv.wait_for(lock, duration, predicate);       // relative timeout
```

Both return `false` if the wait timed out with the predicate still false. Use
these when something becomes true through the passage of time alone, with no
other thread having a reason to notify — a cooldown expiring, for example.

### The pattern in one shape

```
WAITER                          SIGNALLER
lock(m)                         lock(m)
cv.wait(lock, pred)             change shared state
  // released m, slept          unlock(m)
  // woke, reacquired m         cv.notify_one()
act on shared state
unlock(m)
```

> [!IMPORTANT]
> **The mutex protects the state; the condvar only announces that it changed.**
> They are always used together — a condvar alone protects nothing.

The chef/customer simulation in [multi_threading.cpp](./multi_threading.cpp) is
this pattern with a queue for fairness and a shared counter as the stop flag.

---

## 7. Deadlock

Two threads, two mutexes, opposite acquisition order → both block forever.

```cpp
// thread A                    // thread B
lock(m1);                      lock(m2);
lock(m2);   // waits for B     lock(m1);   // waits for A
```

**Coffman's four conditions** must *all* hold for a deadlock to occur, so
breaking any single one prevents it:

1. **Mutual exclusion** — the resource cannot be shared.
2. **Hold and wait** — a thread holds one resource while requesting another.
3. **No preemption** — a resource cannot be forcibly taken back.
4. **Circular wait** — a cycle exists in the "waits for" graph.

Practical fixes:

* **Fixed global lock order** — always acquire mutexes in the same order
  everywhere (breaks *circular wait*).
* **All-or-nothing** — take every resource at once or none (breaks *hold and
  wait*).
* **`std::scoped_lock(m1, m2)`** — C++17. Locks multiple mutexes with a
  deadlock-avoiding algorithm. Use it whenever locking more than one mutex;
  it is the default answer to this whole section.

---

## What C++20 Adds

The primitives above stay valid; C++20 mostly removes footguns and adds
higher-level coordination — `std::jthread` (auto-joining, cooperative
cancellation via `std::stop_token`), `std::latch` and `std::barrier`,
`std::counting_semaphore`, and atomic `wait`/`notify`.

Covered in **[[concurrency_cpp20]]**.

---
*Back to **[Foundations](README.md)** · **[multi_threading](../../08_Systems_and_Performance/01_Data_Oriented_Design/03_Multi_Threading/Multi_Threading.md)** · **[Concurrency and Parallelism](../README.md)***
