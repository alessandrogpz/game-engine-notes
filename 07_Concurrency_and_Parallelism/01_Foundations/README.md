# Foundations

## Notes

### [Concurrency_Cpp17](Concurrency_Cpp17.md)

The main note, worked through in order:

| Section | Covers |
| :--- | :--- |
| Launching Threads | `std::thread`, join vs detach, and what happens if you do neither |
| Race Conditions | Why unsynchronized access is undefined, and catching it with ThreadSanitizer |
| Mutex | `lock_guard`, `unique_lock`, `scoped_lock`; lock granularity |
| Atomic | `std::atomic`, when it replaces a mutex and when it does not |
| The Cost of Synchronization | Measured overhead — the numbers that motivate job systems |
| Condition Variables | Waiting without spinning; spurious wakeups and the predicate loop |
| Deadlock | The four conditions, and lock ordering as the practical fix |
| What C++20 Adds | `jthread`, `stop_token`, latches, barriers, semaphores |

### [Concurrency_Glossary](Concurrency_Glossary.md)

One-line lookup for each class and function, grouped by threads and execution,
synchronization, data safety, coordination, and `<chrono>` timing.

---

## Runnable code

[multi_threading.cpp](multi_threading.cpp) — a chef-customer queue simulation exercising
threads, a mutex, a condition variable and atomics together.

```bash
g++ -std=c++23 -O3 -pthread 07_Concurrency_and_Parallelism/01_Foundations/multi_threading.cpp -o /tmp/multi_threading
```

Add `-fsanitize=thread` (with `-O1 -g`) to check for races.

---

## Still to cover

Why raw threads are the wrong abstraction for a frame loop; livelock and priority inversion.

---

## Related

* [Concurrency and Parallelism](../README.md) — the rest of the domain
* [Multi_Threading](../../08_Systems_and_Performance/01_Data_Oriented_Design/03_Multi_Threading/Multi_Threading.md)
  — false sharing: the same synchronization seen from the cache's side
