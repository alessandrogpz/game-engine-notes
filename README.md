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

## Learning Path

Explore the core concepts step-by-step:

1. **[[Cache_Locality_and_Memory_Layout]]**
   * Understand CPU bottlenecks, memory latency tiers, the 64-byte Cache Line, and AoS vs. SoA layouts.
   * *Companion Code:* [`aos_vs_soa.cpp`](./01_Cache_Locality_and_Memory_Layout/aos_vs_soa.cpp)
2. **[[Memory_Alignment]]**
   * Learn about hardware word sizes, compiler padding, and struct sorting rules.
   * *Companion Code:* [`alignment.cpp`](./02_Memory_Alignment/alignment.cpp)
3. **[[Multi_Threading_and_Parallelism]]**
   * Design lock-free parallel systems, analyze race conditions, and avoid False Sharing.
   * *Companion Code:* [`multi_threading.cpp`](./03_Multi_Threading_and_Parallelism/multi_threading.cpp)
4. **[[DOD_Optimization_Steps]]**
   * A practical, step-by-step guide to refactoring OOP entities into DOD structures, achieving up to a 40x speedup.
5. **[[Advanced_DOD_and_Hardware]]**
   * Deep dive into advanced techniques: AoSoA hybrid layouts, SIMD vectorization, ECS architecture, Custom Allocators, and Instruction Cache optimizations.

---

## Repository Structure

*   **[`01_Cache_Locality_and_Memory_Layout`](./01_Cache_Locality_and_Memory_Layout)**
    *   *Notes:* Memory latency hierarchy cycles, 64-byte Cache Lines, and Array of Structures (AoS) vs. Structure of Arrays (SoA).
    *   *Code:* [`aos_vs_soa.cpp`](./01_Cache_Locality_and_Memory_Layout/aos_vs_soa.cpp) — Stride vs. sequential access benchmark (Row-Major vs. Column-Major matrix traversal).
*   **[`02_Memory_Alignment`](./02_Memory_Alignment)**
    *   *Notes:* Hardware word boundaries, compiler padding rules, and struct member ordering to maximize cache line density.
    *   *Code:* [`alignment.cpp`](./02_Memory_Alignment/alignment.cpp) — Size comparison of aligned (`GoodLayout`) and padded (`BadLayout`) structures.
*   **[`03_Multi_Threading_and_Parallelism`](./03_Multi_Threading_and_Parallelism)**
    *   *Notes:* Concurrency without lock contention, atomic instruction costs, and the hardware mechanics of **False Sharing** (cache line ping-ponging).
    *   *Code:* [`multi_threading.cpp`](./03_Multi_Threading_and_Parallelism/multi_threading.cpp) — Race condition demonstration on shared memory.
*   **[`04_DOD_Optimization_Steps`](./04_DOD_Optimization_Steps)**
    *   *Notes:* The 8 sequential optimization steps to refactor traditional OOP systems into high-performance DOD systems to achieve up to a ~40x speedup.
*   **[`05_Advanced_DOD_and_Hardware`](./05_Advanced_DOD_and_Hardware)**
    *   *Notes:* Advanced architectures: Array of Structures of Arrays (AoSoA) hybrid layouts, SIMD vectorization (AVX/NEON), Entity Component System (ECS) principles, custom allocators (Arenas/Pools), and L1i instruction cache optimizations.
