# Game Engine Notes

A personal knowledge base for building game and rendering engines — theory notes, worked exercises, and runnable implementations, spanning mathematics through rendering, physics, architecture and systems programming.

It is an **Obsidian** vault that stays fully readable on **GitHub**. Every cross-reference is a relative markdown link, so the knowledge graph works in both.

---

## Overview

The vault is organized **domain first**. Each top-level numbered folder is a domain, each domain holds subjects, and every subject carries its own `Concepts/`, `Exercises/` and `Assets/`.

Every domain has two files at its root: a `README.md` indexing what exists there now, and a `00_Roadmap.md` — a scoped study plan naming the subjects to cover and what to deliberately skip. Domains that have not been started yet have only the roadmap's worth of content.

Exercises are bound to the theory they practise: every question links to its solution, and every solution links back to the concept note it came from. Practice and theory stay connected rather than drifting apart.

New here? Start with [Your First Study Session](00_Documentation/tutorials/FirstStudySession.md).

---

## Domains

| Domain                                                                     | Covers                                                                      |
| :------------------------------------------------------------------------- | :-------------------------------------------------------------------------- |
| [01_Mathematics](01_Mathematics/README.md)                                 | Linear algebra, calculus, numerical methods, probability, signal processing |
| [02_Rendering](02_Rendering/README.md)                                     | MVP, rasterization, graphics APIs, shading, shadows                         |
| [03_Physics](03_Physics/README.md)                                         | Collision primitives, GJK/SAT, rigid body dynamics                          |
| [04_Engine_Architecture](04_Engine_Architecture/README.md)                 | Game loop, memory, ECS, resources, tooling patterns                         |
| [05_Data_Structures](05_Data_Structures/README.md)                         | Spatial structures, cache-aware containers                                  |
| [06_Algorithms](06_Algorithms/README.md)                                   | Computational geometry, pathfinding, procedural generation                  |
| [07_Concurrency_and_Parallelism](07_Concurrency_and_Parallelism/README.md) | Memory model, job systems, lock-free structures                             |
| [08_Systems_and_Performance](08_Systems_and_Performance/README.md)         | Cache hierarchy, data-oriented design, SIMD, profiling                      |
| [09_Tools_and_Pipeline](09_Tools_and_Pipeline/README.md)                   | Asset pipeline, serialization, build systems, editor tooling                |
| [10_Audio](10_Audio/README.md)                                             | Real-time audio, mixing, spatialization, DSP                                |
| [11_Networking](11_Networking/README.md)                                   | Transport, state sync, latency hiding, determinism                          |

Each domain link lands on that domain's **index** — what exists there now, and how much of it.
The index links on to `00_Roadmap.md`, the study plan for what does not exist yet.

Nothing here is ever finished — notes get revisited and deepened as the material gets used, and a domain reaching the end of its roadmap only means the first pass is done. Open threads are tracked in [TODO.md](TODO.md).

---

## Documentation

Documentation lives in [00_Documentation](00_Documentation/README.md), indexed there in full. It follows the [Diátaxis](https://diataxis.fr/) framework — separated by what you need at the moment you open it.

* [Tutorials](00_Documentation/README.md#tutorials)
* [How-to Guides](00_Documentation/README.md#how-to-guides)
* [Reference](00_Documentation/README.md#reference)
* [Explanation](00_Documentation/README.md#explanation)

---

## Tooling

| | |
| :--- | :--- |
| [randomizer.py](randomizer.py) | Picks practice questions and scaffolds new exercise pairs — [reference](00_Documentation/references/Randomizer.md) |
| [90_Code](90_Code/README.md) | C++23 CMake project with a GoogleTest suite — [build guide](00_Documentation/how-to/BuildAndTest.md) |
| [99_Templates](99_Templates/README.md) | Question and solution templates used by the scaffolder |
| [scripts](scripts/README.md) | Link and math checkers — run in CI on every push |

```bash
python3 randomizer.py -n 3 --practice     # today's practice
cmake -S 90_Code -B build -G Ninja        # configure the code project
```
