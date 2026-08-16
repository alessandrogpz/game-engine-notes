# Engine Architecture — Study Roadmap

How the pieces fit together. This is the domain that turns a renderer and a physics library into an *engine*, and the one least covered by mathematics books.

> [!NOTE]
> Placeholder. Subjects gain `Concepts/`, `Exercises/` and `Assets/` folders as work begins.

---

## Suggested Subjects

### 01_Engine_Overview
* Subsystem inventory and startup/shutdown ordering
* The game loop: fixed vs variable timestep, accumulators, interpolation
* Layered architecture and dependency direction

### 02_Memory_Management
* Custom allocators: linear/arena, stack, pool, free list
* Frame allocators and scratch memory
* Alignment, padding, and why `new`/`delete` per object is a design smell
* Ownership models and handles vs raw pointers

### 03_Entity_Systems
* Object model options: inheritance, composition, ECS
* ECS in depth: archetypes vs sparse sets, iteration order, structural change
* `entt` as a reference implementation to read

### 04_Resource_Management
* Asset loading, reference counting, lifetimes
* Streaming and async loading
* Handle/ID indirection instead of pointers
* Hot reload

### 05_Scene_Representation
* Transform hierarchies and dirty-flag propagation
* Spatial partitioning for queries and culling
* Visibility and culling systems

### 06_Common_Patterns
* Event/messaging systems, service locators, state machines
* Update ordering and the tick pipeline
* Data-driven design and reflection/serialization

### 07_Debugging_and_Diagnostics
* Assertions, logging, in-game consoles
* Profilers, frame capture, GPU timing
* Deterministic replay

---

## Resources

| Resource | Use |
| :--- | :--- |
| Gregory, *Game Engine Architecture* (3rd ed) | **Read sequentially, cover to cover.** The map of the whole territory |
| [gameprogrammingpatterns.com](https://gameprogrammingpatterns.com/) | Nystrom, free online. Short, practical, excellent |
| [entt](https://github.com/skypjack/entt) | Modern ECS worth reading rather than just using |
| Handmade Hero | From-scratch mentality; long but formative |
| Bitsquid / Our Machinery blog archives | Hard-won production engine design notes |

---

## Suggested Order

Read Gregory end to end early — it reveals how much of an engine has nothing to do with math. Then memory management, then entity systems, then the rest driven by whatever the current project actually needs.

> [!IMPORTANT]
> This is the domain where reading substitutes least well for building. Pick a small game that must exist, and implement only the engine it requires.
