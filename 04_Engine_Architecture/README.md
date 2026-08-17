# Engine Architecture

How the pieces fit together — the domain that turns a renderer and a physics library into an
*engine*, and the one least covered by mathematics books.

> [!NOTE]
> **No notes yet.** This domain is at the roadmap stage. The plan — subjects, resources, and
> the order to take them in — is in [00_Roadmap.md](00_Roadmap.md).

---

## Planned subjects

| Subject | Covers |
| :--- | :--- |
| `01_Engine_Overview` | Subsystem inventory, startup ordering, the game loop, layering |
| `02_Memory_Management` | Arena, stack, pool and free-list allocators; ownership and handles |
| `03_Entity_Systems` | Inheritance vs composition vs ECS; archetypes and sparse sets |
| `04_Resource_Management` | Asset loading, lifetimes, streaming, handle indirection, hot reload |
| `05_Scene_Representation` | Transform hierarchies, dirty flags, spatial partitioning, culling |
| `06_Common_Patterns` | Events, state machines, tick ordering, data-driven design |
| `07_Debugging_and_Diagnostics` | Assertions, logging, profilers, deterministic replay |

Subjects gain `Concepts/`, `Exercises/` and `Assets/` folders as work begins.

