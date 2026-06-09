# Intro to Data-Oriented Design (DOD)

## Core Topics

1. **[[Cache_Locality_and_Memory_Layout]]**
   * CPU bottlenecks, latency costs, cache line behavior, and the difference between AoS and SoA.
   * *Code:* [aos_vs_soa.cpp](file:///home/aper/Documents/CacheLocalityAndMemoryLayout/01_Cache_Locality_and_Memory_Layout/aos_vs_soa.cpp)
2. **[[Memory_Alignment]]**
   * Understanding alignment boundary rules, compiler padding, and struct ordering.
   * *Code:* [alignment.cpp](file:///home/aper/Documents/CacheLocalityAndMemoryLayout/02_Memory_Alignment/alignment.cpp)
3. **[[Multi_Threading_and_Parallelism]]**
   * Designing independent streams of work, understanding race conditions, and avoiding False Sharing.
   * *Code:* [multi_threading.cpp](file:///home/aper/Documents/CacheLocalityAndMemoryLayout/03_Multi_Threading_and_Parallelism/multi_threading.cpp)
4. **[[DOD_Optimization_Steps]]**
   * The step-by-step refactoring process to clean up OOP code and achieve up to a **40x speedup**.
5. **[[Advanced_DOD_and_Hardware]]**
   * Advanced topics: AoSoA, SIMD/Vectorization, ECS architecture, Custom Allocators, and L1i instruction cache optimizations.

---

## Why Data-Oriented Design?

Traditional Object-Oriented Programming (OOP) prioritizes objects containing both state and behavior. While intuitive, this abstraction conflicts with modern hardware:
* **Deep Inheritance:** Leads to complex, fragmented codebases.
* **Pointer Chasing:** Objects scattered across the heap trigger frequent cache misses.
* **Polymorphic Overhead:** Virtual function calls prevent compiler optimization (inlining) and degrade the instruction cache.

DOD focuses on organizing data in contiguous memory blocks first, then processing it in bulk, unlocking significant performance improvements.
