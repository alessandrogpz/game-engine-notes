# Tools and Pipeline — Study Roadmap

Everything between an artist's file and bytes the runtime can consume. Chronically under-taught relative to how much engine work it actually is.

> [!NOTE]
> Placeholder. Subjects gain `Concepts/`, `Exercises/` and `Assets/` folders as work begins.

---

## Suggested Subjects

### 01_Asset_Pipeline
* Source assets vs runtime formats, and why they must differ
* Offline bake step: compression, optimization, platform variants
* Dependency tracking and incremental builds
* Content hashing and caching
* glTF as a well-specified interchange format worth reading

### 02_Serialization
* Binary vs text; when each is right
* Versioning and backwards compatibility — the hard part
* Reflection systems in C++: manual registration, macros, code generation
* Endianness, alignment, and safe in-place loading
* Pointer patching vs offset-based layouts

### 03_Build_Systems
* CMake beyond copy-paste; targets and properties as the mental model
* Compile time as a first-class concern: unity builds, PCH, C++ modules
* Dependency management
* CI for a native project

### 04_Editor_and_Tooling
* Immediate mode UI (Dear ImGui) for debug tooling
* Scene editing, gizmos, undo/redo (command pattern)
* Live reload of assets, shaders and code
* In-game debug visualization and consoles

### 05_Platform_Layer
* Windowing, input, timing abstractions
* File I/O and virtual file systems
* Platform abstraction without over-abstracting
* Cross-platform build and test

---

## Resources

| Resource | Use |
| :--- | :--- |
| Gregory, *Game Engine Architecture* | Asset pipeline and tools chapters |
| [Dear ImGui](https://github.com/ocornut/imgui) | The de-facto debug UI; read its examples |
| [glTF specification](https://registry.khronos.org/glTF/) | A well-designed asset format, worth studying as a spec |
| *Professional CMake: A Practical Guide* | If CMake remains a source of pain |

---

## Suggested Order

Serialization first — everything else depends on getting data in and out. Then the platform layer, then ImGui-based tooling (the fastest path to a debuggable engine), then the offline pipeline when asset counts start to hurt.

> [!NOTE]
> Good tooling compounds. An hour spent on a debug visualizer often repays itself the same week.
