# Data-Oriented Design (DOD) & Cache Locality Vault

This repository is a personal learning vault dedicated to **Data-Oriented Design (DOD)**, **CPU cache locality**, and **memory layout optimizations**. It contains structured Obsidian notes alongside runnable C++ benchmarks that demonstrate how memory layouts affect real-world execution speeds.

---

## Repository Structure

The project is organized into self-contained folders, each containing study notes and companion code:

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

---

## Compiling & Running Benchmarks

All code files are written in modern C++ (C++20). You can compile and run them using any standard compiler (like GCC or Clang).

### 1. Cache Locality (AoS vs. SoA / Matrix Traversal)
Compare sequential memory access with stride memory access:
```bash
g++ -std=c++20 01_Cache_Locality_and_Memory_Layout/aos_vs_soa.cpp -o aos_benchmark
./aos_benchmark
```

### 2. Memory Alignment & Padding
See how data member ordering changes structure size:
```bash
g++ -std=c++20 02_Memory_Alignment/alignment.cpp -o alignment_benchmark
./alignment_benchmark
```

### 3. Multi-Threading Concurrency
Observe the behavior of concurrent thread writes on a shared variable:
```bash
g++ -std=c++20 03_Multi_Threading_and_Parallelism/multi_threading.cpp -o mt_benchmark
./mt_benchmark
```

---

## Obsidian Vault Integration

This repository is formatted as a local **Obsidian Vault**. You can open the root folder directly in Obsidian to navigate the notes with full backlink resolution. 

*   Start with the master note: **[`Intro to Data-Oriented Design (DOD).md`](./Intro%20to%20Data-Oriented%20Design%20(DOD).md)**
