# Intro to Data-Oriented Design (DOD)

This repository serves as a personal learning vault for **Data-Oriented Design (DOD)**, **cache locality**, and **memory layout optimizations**. It covers how aligning software structures with modern CPU hardware realities yields massive performance gains.

---

## Core Philosophy

> [!NOTE]
> "Where there is one, there is many. Where there is data, there is structure. The purpose of all programs is to transform data from one format to another."
> — *Mike Acton*

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

## Why Data-Oriented Design?

Traditional Object-Oriented Programming (OOP) prioritizes objects containing both state and behavior. While intuitive, this abstraction conflicts with modern hardware:
* **Deep Inheritance:** Leads to complex, fragmented codebases.
* **Pointer Chasing:** Objects scattered across the heap trigger frequent cache misses.
* **Polymorphic Overhead:** Virtual function calls prevent compiler optimization (inlining) and degrade the instruction cache.

DOD focuses on organizing data in contiguous memory blocks first, then processing it in bulk, unlocking significant performance improvements.
