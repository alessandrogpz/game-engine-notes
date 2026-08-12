# Multi-Threading & Parallelism

This note covers how to write high-performance multi-threaded code by aligning software structure with hardware concurrency limits.

*For the language primitives themselves — threads, mutexes, atomics, condition variables — see **[[concurrency_cpp17]]**.*

---

## The Concurrency Goal

To leverage modern multi-core processors, you must keep cores busy with **independent streams of work** that do not require constant synchronization.

* **Avoid Lock Contention:** Thread synchronization primitives (mutexes, locks, semaphores) stall CPU execution. Stalled cores do not perform work.
* **Avoid Cache Ping-Ponging:** When threads constantly request ownership of the same memory location, the containing cache line is transferred back and forth between the cores' L1 caches, halting execution.

---

## Race Conditions & Synchronization Costs

In [multi_threading.cpp](./multi_threading.cpp), we see a race condition where multiple threads attempt to modify a single global variable concurrently:

```cpp
int counter = 0;

void increment_task(){
    for ( int i = 0; i < 100'000; ++i ) {
        counter++; // Not atomic: reads, modifies, and writes back the value
    }
}
```

* **The Problem:** The compiler translates `counter++` into multiple assembly instructions. Because the operation is not atomic, threads interrupt each other, causing lost updates.
* **The Cost of Synchronization:** Adding a `std::mutex` or using `std::atomic<int>` solves the correctness problem but degrades performance:
  * Mutexes force threads to wait, removing parallel execution benefits.
  * Atomics bypass L1/L2 caches to coordinate values at the hardware bus level, slowing down operations significantly.
* **The DOD Solution:** Give each thread its own independent write destination (e.g., thread-local variable or index in a thread-isolated array), then sum the results in a single, fast step on the main thread when work completes.

---

## False Sharing (Cache Line Collision)

> [!CAUTION]
> **What is False Sharing?**
> False sharing is a hardware performance bottleneck that occurs when two or more threads running on separate cores modify independent variables that reside on the **same 64-byte cache line**.

### Hardware Mechanics
1. Core A modifies `data.var1`. It loads the cache line containing `var1` and marks it as *Modified (M)* in its L1 cache.
2. Core B wants to modify `data.var2` (which is in the same cache line). Since Core A modified the line, Core B's L1 cache line is marked as *Invalid (I)*.
3. Core B must wait for Core A to write back its cache line, then fetch the updated 64-byte line from Core A's cache (or L3 cache/RAM).
4. Now, Core B modifies `var2`, invalidating Core A's cache line.
5. This cycle repeats continuously, causing the cache line to "ping-pong" between core L1 caches.

```
[Core A L1 Cache] <--- (64-Byte Cache Line Ping-Pong) ---> [Core B L1 Cache]
    [var1 | var2]                                              [var1 | var2]
```

### How to Avoid False Sharing
* **Align to Cache Line Size:** Align thread-local structures to 64-byte boundaries (e.g., using `alignas(64)` in C++).
* **Separate Write Destinations:** Ensure the memory addresses written by separate threads are separated by at least 64 bytes of distance.
* **Accumulate Locally:** Do not write directly to shared memory inside loops. Keep accumulation inside registers (local variables) and write to the shared array once upon task completion.

---
*Back to **[[README]]***
