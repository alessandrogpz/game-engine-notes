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

Explore the core concepts step-by-step. Each entry links to the note; the
bullets under it list everything else in that folder.

1.  **[cache_locality](./01_Cache_Locality/Cache_Locality.md)**
    *   *Concept:* Understand CPU bottlenecks, memory latency tiers, 64-byte Cache Lines, and the difference between Array of Structures (AoS) and Structure of Arrays (SoA).
    *   *Companion Code:* [`aos_vs_soa.cpp`](./01_Cache_Locality/aos_vs_soa.cpp) (Simple particle AoS vs SoA layout benchmark).
2.  **[memory_alignment](./02_Memory_Alignment/Memory_Alignment.md)**
    *   *Concept:* Learn about hardware word sizes, compiler padding, and struct sorting rules to maximize cache line density.
    *   *Companion Code:* [`alignment.cpp`](./02_Memory_Alignment/alignment.cpp) (Size comparison of aligned vs. padded structures).
3.  **[Multi_Threading](./03_Multi_Threading/Multi_Threading.md)**
    *   *Concept:* Avoid False Sharing (cache line ping-ponging) — how threading interacts with the memory hierarchy.
    *   *See also:* the language primitives themselves live in [07_Concurrency_and_Parallelism](../../07_Concurrency_and_Parallelism/00_Roadmap.md) — [Concurrency_Cpp17](../../07_Concurrency_and_Parallelism/01_Foundations/Concurrency_Cpp17.md) (threads, mutexes, atomics, condition variables, deadlock, with synchronization cost measurements), [Concurrency_Glossary](../../07_Concurrency_and_Parallelism/01_Foundations/Concurrency_Glossary.md), and the [chef-customer simulation](../../07_Concurrency_and_Parallelism/01_Foundations/multi_threading.cpp).
4.  **[dod_optimizations](./04_DOD_Optimizations/DOD_Optimizations.md)**
    *   *Concept:* A practical, 8-step guide to refactoring OOP entities into DOD structures, achieving up to a 40x speedup.
5.  **[advanced_dod](./05_Advanced_DOD/Advanced_DOD.md)**
    *   *Concept:* Deep dive into advanced techniques: AoSoA hybrid layouts, SIMD vectorization, ECS architecture, Custom Allocators, and Instruction Cache optimizations.

---

## Compiling & Running the Programs

All examples in this subject use **C++23** (as does [multi_threading.cpp](../../07_Concurrency_and_Parallelism/01_Foundations/multi_threading.cpp), which moved to the concurrency domain). Compile and run any of them with:

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

**Race detection** — instruments memory accesses and reports data races even when the timing happened to work out. Costs a 5–15× slowdown, so it is a debug tool only (see [Concurrency_Cpp17](../../07_Concurrency_and_Parallelism/01_Foundations/Concurrency_Cpp17.md)):

```bash
g++ -std=c++23 -g -O1 -pthread -fsanitize=thread <path_to_file.cpp> -o main
```

> [!WARNING]
> **Use Capital `-O3`, Not Lowercase `-o3`**
> *   **`-O3` (Capital O)** enables Level 3 optimizations (loop unrolling, auto-vectorization, and function inlining).
> *   **`-o3` (Lowercase o)** is treated as an output directive, writing the executable to a file named `3` without enabling any code optimization.
> *   For benchmarks (like the AoS vs. SoA benchmark), compilation without `-O3` leaves standard library vector access (`operator[]`) un-inlined. The resulting function call overhead is so large that it masks cache locality benefits, causing the benchmark speedup to disappear.
