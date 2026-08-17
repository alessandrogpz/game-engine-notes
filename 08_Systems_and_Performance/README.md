# Systems and Performance

What the hardware actually does, and how to write code that suits it.

---

## Subjects

| Subject | Status | Contents |
| :--- | :--- | :--- |
| [01_Data_Oriented_Design](01_Data_Oriented_Design/README.md) | **Under study** | 5 notes, each with a runnable companion program |
| `02_Memory_Hierarchy` | Planned | Cache levels and associativity, locality, prefetching, TLB |
| `03_CPU_Architecture` | Planned | Pipelining, branch prediction, ILP, out-of-order execution |
| `04_SIMD` | Planned | SSE/AVX and NEON, intrinsics vs autovectorization, SoA as prerequisite |
| `05_Profiling_and_Measurement` | Planned | Sampling vs instrumenting, flame graphs, `perf` counters |
| `06_Compilers_and_Toolchain` | Planned | Optimization levels, inlining, aliasing, reading disassembly |

---

## Data-Oriented Design at a glance

Its own [index](01_Data_Oriented_Design/README.md) carries the reading order and the compile
commands. The notes:

| Note | Covers |
| :--- | :--- |
| [Cache_Locality](01_Data_Oriented_Design/01_Cache_Locality/Cache_Locality.md) | Memory latency tiers, 64-byte cache lines, AoS vs SoA |
| [Memory_Alignment](01_Data_Oriented_Design/02_Memory_Alignment/Memory_Alignment.md) | Word sizes, compiler padding, struct field ordering |
| [Multi_Threading](01_Data_Oriented_Design/03_Multi_Threading/Multi_Threading.md) | False sharing and cache line ping-ponging |
| [DOD_Optimizations](01_Data_Oriented_Design/04_DOD_Optimizations/DOD_Optimizations.md) | An 8-step OOP-to-DOD refactor |
| [Advanced_DOD](01_Data_Oriented_Design/05_Advanced_DOD/Advanced_DOD.md) | AoSoA, SIMD, ECS, custom allocators, instruction cache |

---

## Related

* [00_Roadmap.md](00_Roadmap.md) — the remaining subjects and the order to take them in
* [07_Concurrency_and_Parallelism](../07_Concurrency_and_Parallelism/README.md) — the language
  primitives whose hardware cost the false-sharing note measures
* [05_Data_Structures](../05_Data_Structures/README.md) — the same cache reasoning, applied to
  container choice
