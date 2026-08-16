# Game Engine Notes

A personal knowledge base for building game and rendering engines — theory notes, worked exercises, and runnable implementations, spanning mathematics through rendering, physics, architecture and systems programming.

It is an **Obsidian** vault that stays fully readable on **GitHub**. Every cross-reference is a relative markdown link, so the knowledge graph works in both.

---

## Overview

The vault is organized **domain first**. Each top-level numbered folder is a domain, each domain holds subjects, and every subject carries its own `Concepts/`, `Exercises/` and `Assets/`. Domains that have not been started yet contain only a roadmap — a scoped study plan naming the subjects to cover and what to deliberately skip.

Exercises are bound to the theory they practise: every question links to its solution, and every solution links back to the concept note it came from. Practice and theory stay connected rather than drifting apart.

New here? Start with [Your First Study Session](00_Documentation/tutorials/FirstStudySession.md).

---

## Domains

| Domain                                                                         | Covers                                                                      | Coverage                                                                                             |
| :----------------------------------------------------------------------------- | :-------------------------------------------------------------------------- | :--------------------------------------------------------------------------------------------------- |
| [01_Mathematics](01_Mathematics/00_Roadmap.md)                                 | Linear algebra, calculus, numerical methods, probability, signal processing | **Under study** — [Linear Algebra](01_Mathematics/01_Linear_Algebra/README.md): 35 notes, 32 exercise pairs |
| [02_Rendering](02_Rendering/00_Roadmap.md)                                     | MVP, rasterization, graphics APIs, shading, shadows                         | Roadmap — *next up*                                                                                  |
| [03_Physics](03_Physics/00_Roadmap.md)                                         | Collision primitives, GJK/SAT, rigid body dynamics                          | Roadmap                                                                                              |
| [04_Engine_Architecture](04_Engine_Architecture/00_Roadmap.md)                 | Game loop, memory, ECS, resources, tooling patterns                         | Roadmap                                                                                              |
| [05_Data_Structures](05_Data_Structures/00_Roadmap.md)                         | Spatial structures, cache-aware containers                                  | Roadmap                                                                                              |
| [06_Algorithms](06_Algorithms/00_Roadmap.md)                                   | Computational geometry, pathfinding, procedural generation                  | Roadmap                                                                                              |
| [07_Concurrency_and_Parallelism](07_Concurrency_and_Parallelism/00_Roadmap.md) | Memory model, job systems, lock-free structures                             | **Under study** — [Foundations](07_Concurrency_and_Parallelism/01_Foundations/): 2 notes             |
| [08_Systems_and_Performance](08_Systems_and_Performance/00_Roadmap.md)         | Cache hierarchy, data-oriented design, SIMD, profiling                      | **Under study** — [Data-Oriented Design](08_Systems_and_Performance/01_Data_Oriented_Design/): 5 notes |
| [09_Tools_and_Pipeline](09_Tools_and_Pipeline/00_Roadmap.md)                   | Asset pipeline, serialization, build systems, editor tooling                | Roadmap                                                                                              |
| [10_Audio](10_Audio/00_Roadmap.md)                                             | Real-time audio, mixing, spatialization, DSP                                | Roadmap                                                                                              |
| [11_Networking](11_Networking/00_Roadmap.md)                                   | Transport, state sync, latency hiding, determinism                          | Roadmap                                                                                              |

**Roadmap** means the study plan exists but no notes yet. **Under study** means notes exist and are actively being added to and revised.

Nothing here is ever finished — notes get revisited and deepened as the material gets used, and a domain reaching the end of its roadmap only means the first pass is done. Open threads are tracked in [TODO.md](TODO.md).

---

## Documentation

Documentation lives in [00_Documentation](00_Documentation/) and follows the [Diátaxis](https://diataxis.fr/) framework — separated by what you need at the moment you open it.

### Tutorials

* [Your First Study Session](00_Documentation/tutorials/FirstStudySession.md) — one complete practice cycle, start to finish

### How-to Guides

* [Run a Practice Session](00_Documentation/how-to/RunPracticeSession.md) — filter by topic, difficulty or tag
* [Add a New Exercise](00_Documentation/how-to/AddExercise.md)
* [Add a Concept Note](00_Documentation/how-to/AddConceptNote.md)
* [Add a Subject or Domain](00_Documentation/how-to/AddSubjectOrDomain.md)
* [Add a Figure](00_Documentation/how-to/AddFigure.md)
* [Build and Test the Code](00_Documentation/how-to/BuildAndTest.md)
* [Use the Templates](00_Documentation/how-to/UseTemplates.md)

### Reference

* [Repository Structure](00_Documentation/references/RepositoryStructure.md) — the full tree and common relative paths
* [Naming Conventions](00_Documentation/references/NamingConventions.md) — file names, frontmatter, link forms
* [Math Formatting](00_Documentation/references/MathFormatting.md) — LaTeX that renders in both Obsidian and GitHub
* [Randomizer](00_Documentation/references/Randomizer.md) — full CLI documentation
* [Code Conventions](00_Documentation/references/CodeConventions.md) — module structure, includes, tests
* [Build Requirements](00_Documentation/references/BuildRequirements.md) — toolchain, targets, compile flags

### Explanation

* [Vault Organization](00_Documentation/explanation/VaultOrganization.md) — why domain first, and why one vault rather than many
* [The Knowledge Graph](00_Documentation/explanation/KnowledgeGraph.md) — how notes link, and what to link
* [Link Format](00_Documentation/explanation/LinkFormat.md) — why relative markdown links instead of wikilinks
* [Code Placement](00_Documentation/explanation/CodePlacement.md) — why some code is centralized and some is not
* [Roadmap Scoping](00_Documentation/explanation/RoadmapScoping.md) — why roadmaps state what to skip

---

## Tooling

| | |
| :--- | :--- |
| `randomizer.py` | Picks practice questions and scaffolds new exercise pairs — [reference](00_Documentation/references/Randomizer.md) |
| `90_Code/` | C++23 CMake project with a GoogleTest suite — [build guide](00_Documentation/how-to/BuildAndTest.md) |
| `99_Templates/` | Question and solution templates used by the scaffolder |
| `scripts/` | Link and math checkers — run in CI on every push |

```bash
python3 randomizer.py -n 3 --practice     # today's practice
cmake -S 90_Code -B build -G Ninja        # configure the code project
```
