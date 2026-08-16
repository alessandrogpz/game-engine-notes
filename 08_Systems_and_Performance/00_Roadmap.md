# Systems and Performance — Study Roadmap

What the hardware actually does, and how to write code that suits it. This is where the existing `data-oriented-design` vault belongs.

> [!NOTE]
> Placeholder. The existing `data-oriented-design` vault is a candidate to fold in here as a subject.

---

## Suggested Subjects

### 01_Memory_Hierarchy
* Cache lines, levels, associativity
* Latency numbers worth memorizing
* Spatial and temporal locality
* Prefetching, hardware and manual
* TLB and page behaviour; why huge allocations behave oddly

### 02_Data_Oriented_Design
* Think about data transformations, not objects
* AoS vs SoA; hot/cold splitting
* Existing material: `01_cache_locality`, `02_memory_alignment`, `03_multi_threading`, `04_dod_optimizations`, `05_advanced_dod`
* Where OOP costs you: virtual dispatch, pointer chasing, allocation churn

### 03_CPU_Architecture
* Pipelining, superscalar execution, branch prediction
* Branch misprediction cost; branchless techniques
* Instruction-level parallelism and dependency chains
* Out-of-order execution and what actually stalls

### 04_SIMD
* SSE/AVX and NEON; intrinsics vs autovectorization
* Structuring data so vectorization is possible at all
* SoA as a prerequisite
* Practical wins: batch transforms, culling, particles

### 05_Profiling_and_Measurement
The discipline that makes the rest meaningful.
* Sampling vs instrumenting profilers
* Reading a flame graph
* Cache miss and branch miss counters (`perf`, VTune)
* Microbenchmarking, and how easily it lies
* **Measure before optimizing** — every time

### 06_Compilers_and_Toolchain
* Optimization levels and what they actually do
* Inlining, LTO, PGO
* Reading disassembly; [Compiler Explorer](https://godbolt.org/)
* Undefined behaviour as an optimization license
* Linking, symbols, ABI stability

---

## Resources

| Resource | Use |
| :--- | :--- |
| Fabian, *Data-Oriented Design* (free online) | The book-length treatment |
| Acton, *Data-Oriented Design and C++* (CppCon 2014) | The talk that popularized the mindset |
| Drepper, *What Every Programmer Should Know About Memory* | Dense, dated in specifics, still the best on caches |
| Bryant & O'Hallaron, *CS:APP* | Excellent foundation if the hardware model feels shaky |
| [Agner Fog's manuals](https://www.agner.org/optimize/) | Instruction tables and microarchitecture detail |
| [godbolt.org](https://godbolt.org/) | Habitual use teaches more than any book |

---

## Suggested Order

Memory hierarchy → data-oriented design → profiling → SIMD → CPU internals as curiosity demands. Learn profiling early: optimizing without measurement is how people spend a week making something 2% faster.
