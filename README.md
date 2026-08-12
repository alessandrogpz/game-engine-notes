# Data-Oriented Design (DOD) & Cache Locality Vault

This repository is a personal learning vault dedicated to **Data-Oriented Design (DOD)**, **CPU cache locality**, and **memory layout optimizations**.

---

## Why Data-Oriented Design?

Traditional Object-Oriented Programming (OOP) prioritizes objects containing both state and behavior. While intuitive, this abstraction conflicts with modern hardware:
* **Deep Inheritance:** Leads to complex, fragmented codebases.
* **Pointer Chasing:** Objects scattered across the heap trigger frequent cache misses.
* **Polymorphic Overhead:** Virtual function calls prevent compiler optimization (inlining) and degrade the instruction cache.

DOD focuses on organizing data in contiguous memory blocks first, then processing it in bulk, unlocking significant performance improvements.

---

## Learning Path & Repository Structure

Explore the core concepts step-by-step:

*   **[`01_cache_locality`](./01_cache_locality)** — **[cache_locality](./01_cache_locality/cache_locality.md)**
    *   *Concept:* Understand CPU bottlenecks, memory latency tiers, 64-byte Cache Lines, and the difference between Array of Structures (AoS) and Structure of Arrays (SoA).
    *   *Companion Code:* [`aos_vs_soa.cpp`](./01_cache_locality/aos_vs_soa.cpp) (Simple particle AoS vs SoA layout benchmark).
*   **[`02_memory_alignment`](./02_memory_alignment)** — **[memory_alignment](./02_memory_alignment/memory_alignment.md)**
    *   *Concept:* Learn about hardware word sizes, compiler padding, and struct sorting rules to maximize cache line density.
    *   *Companion Code:* [`alignment.cpp`](./02_memory_alignment/alignment.cpp) (Size comparison of aligned vs. padded structures).
*   **[`03_multi_threading`](./03_multi_threading)** — **[multi_threading](./03_multi_threading/multi_threading.md)**
    *   *Concept:* Design lock-free parallel systems, analyze race conditions, and avoid False Sharing (cache line ping-ponging).
    *   *Companion Code:* [`multi_threading.cpp`](./03_multi_threading/multi_threading.cpp) (Chef-customer queue concurrency simulation).
    *   *Primitives:* [`concurrency_cpp17.md`](./03_multi_threading/concurrency_cpp17.md) (Threads, mutexes, atomics, condition variables, and deadlock, with synchronization cost measurements).
    *   *Glossary:* [`concurrency_glossary.md`](./03_multi_threading/concurrency_glossary.md) (Reference guide for C++ concurrency terms and primitives).
*   **[`04_dod_optimizations`](./04_dod_optimizations)** — **[dod_optimizations](./04_dod_optimizations/dod_optimizations.md)**
    *   *Concept:* A practical, 8-step guide to refactoring OOP entities into DOD structures, achieving up to a 40x speedup.
*   **[`05_advanced_dod`](./05_advanced_dod)** — **[advanced_dod](./05_advanced_dod/advanced_dod.md)**
    *   *Concept:* Deep dive into advanced techniques: AoSoA hybrid layouts, SIMD vectorization, ECS architecture, Custom Allocators, and Instruction Cache optimizations.

---

## Compiling & Running the Programs

All examples in this project use **C++23**. You can compile and run any of the C++ files from the root of the repository using this general command:

```bash
g++ -std=c++23 -O3 -pthread <path_to_file.cpp> -o main
./main
```

| Flag | Why it is required |
| :--- | :--- |
| `-std=c++23` | The examples use `<print>` / `std::println` and CTAD on lock wrappers. Set your editor's IntelliSense standard to `c++23` as well, or it will report false errors on code that compiles cleanly. |
| `-O3` | Mandatory for every benchmark — see the warning below. |
| `-pthread` | Needed by the threading examples. Modern glibc links `std::thread` without it, but it is the correct portable flag and sets `-D_REENTRANT`. |

**Debug build** — for stepping through code. Timings from this build are meaningless:

```bash
g++ -std=c++23 -g -O0 -pthread <path_to_file.cpp> -o main
```

**Race detection** — instruments memory accesses and reports data races even when the timing happened to work out. Costs a 5–15× slowdown, so it is a debug tool only (see [`concurrency_cpp17.md`](./03_multi_threading/concurrency_cpp17.md)):

```bash
g++ -std=c++23 -g -O1 -pthread -fsanitize=thread <path_to_file.cpp> -o main
```

> [!WARNING]
> **Use Capital `-O3`, Not Lowercase `-o3`**
> *   **`-O3` (Capital O)** enables Level 3 optimizations (loop unrolling, auto-vectorization, and function inlining).
> *   **`-o3` (Lowercase o)** is treated as an output directive, writing the executable to a file named `3` without enabling any code optimization.
> *   For benchmarks (like the AoS vs. SoA benchmark), compilation without `-O3` leaves standard library vector access (`operator[]`) un-inlined. The resulting function call overhead is so large that it masks cache locality benefits, causing the benchmark speedup to disappear.
