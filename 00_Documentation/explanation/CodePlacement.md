# Why Code Lives Where It Does

Code appears in two places in this repository, and the split is deliberate rather than historical accident.

---

## Library code: centralized in `90_Code/`

`90_Code/` is a single C++23 CMake project — one static library, a shared utility module, an umbrella module re-exporting every sub-module, and one GoogleTest suite.

It is centralized because its parts depend on each other:

* `00_Utils/` provides `floatEqual`, used across every topic. Scattering the modules would mean duplicating that helper or reaching across the notes tree to include it.
* `linear_algebra.cppm` re-exports every sub-module, so it needs them in one module graph.
* One test suite, one `ctest` invocation, one place where a build failure shows up.

Fragmenting it across `Concepts/` folders would trade all of that for filesystem adjacency to the notes — and the notes already link to the code explicitly.

The directory mirrors the topic structure, so `05_Geometry/Planes.cppm` sits opposite `Concepts/05_Geometry/04_Planes.md`, and each `.cppm` opens with a link back to its concept note.

---

## Standalone demos: beside the note

Some notes ship a single-file program that exists purely to demonstrate that one note — the AoS-versus-SoA benchmark, the struct padding comparison, the producer-consumer simulation.

These live in the same folder as the note. They compile independently with a one-line `g++` invocation, share nothing with any other file, and are meaningless away from the prose that explains them. Pulling them into `90_Code/` would add them to a build they do not belong in and separate them from their only context.

---

## The rule

> Library code that is part of the built project lives in `90_Code/`.
> Standalone illustrative snippets live beside the note they illustrate.

The distinguishing question is whether the file has dependents. If something else includes or imports it, it belongs in the project. If it only ever runs on its own to make one point, it belongs next to the point it makes.

---

## Why build artifacts do not pollute the vault

Build directories are gitignored, and Obsidian is separately configured to exclude them via `userIgnoreFilters` in `.obsidian/app.json`. Without that second step a CMake build directory adds thousands of files to Obsidian's index and search results, which makes the vault unusable long before it makes the repository large.

---

## See also

* [Build and test](../how-to/BuildAndTest.md)
* [Build requirements](../references/BuildRequirements.md)
