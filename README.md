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

*   **[`01_cache_locality`](./01_cache_locality)** — **[[cache_locality]]**
    *   *Concept:* Understand CPU bottlenecks, memory latency tiers, 64-byte Cache Lines, and the difference between Array of Structures (AoS) and Structure of Arrays (SoA).
    *   *Companion Code:* [`aos_vs_soa.cpp`](./01_cache_locality/aos_vs_soa.cpp) (Simple particle AoS vs SoA layout benchmark).
*   **[`02_memory_alignment`](./02_memory_alignment)** — **[[memory_alignment]]**
    *   *Concept:* Learn about hardware word sizes, compiler padding, and struct sorting rules to maximize cache line density.
    *   *Companion Code:* [`alignment.cpp`](./02_memory_alignment/alignment.cpp) (Size comparison of aligned vs. padded structures).
*   **[`03_multi_threading`](./03_multi_threading)** — **[[multi_threading]]**
    *   *Concept:* Design lock-free parallel systems, analyze race conditions, and avoid False Sharing (cache line ping-ponging).
    *   *Companion Code:* [`multi_threading.cpp`](./03_multi_threading/multi_threading.cpp) (Race condition demonstration on shared memory).
*   **[`04_dod_optimizations`](./04_dod_optimizations)** — **[[dod_optimizations]]**
    *   *Concept:* A practical, 8-step guide to refactoring OOP entities into DOD structures, achieving up to a 40x speedup.
*   **[`05_advanced_dod`](./05_advanced_dod)** — **[[advanced_dod]]**
    *   *Concept:* Deep dive into advanced techniques: AoSoA hybrid layouts, SIMD vectorization, ECS architecture, Custom Allocators, and Instruction Cache optimizations.

---

## Compiling & Running Benchmarks

To compile the C++ benchmark examples, make sure to enable optimizations using the **capital `-O3` flag**:

```bash
g++ -O3 -std=c++20 01_cache_locality/aos_vs_soa.cpp -o main
./main
```

> [!WARNING]
> **Use Capital `-O3`, Not Lowercase `-o3`**
> *   **`-O3` (Capital O)** enables Level 3 optimizations (loop unrolling, auto-vectorization, and function inlining).
> *   **`-o3` (Lowercase o)** is treated as an output directive, writing the executable to a file named `3` without enabling any code optimization.
> *   Without optimizations, standard library vector access (`operator[]`) incurs function call overhead on every iteration. This overhead is so large that it masks cache locality benefits, causing the benchmark speedup to disappear.
