# Code Placement

Code lives in two places.

---

## Library code: `90_Code/`

A single C++23 CMake project — one static library, a shared utility module, an umbrella
module re-exporting every sub-module, and one GoogleTest suite.

Its parts depend on each other:

* `00_Utils/` provides `floatEqual`, used across every topic.
* `engine_notes.cppm` re-exports every sub-module, requiring them in one module graph.
* One test suite, one `ctest` invocation.

The directory mirrors the topic structure: `05_Geometry/Planes.cppm` corresponds to
`Concepts/05_Geometry/04_Planes.md`, and each `.cppm` opens with a link to its concept note.

---

## Standalone demos: beside the note

Single-file programs that demonstrate one note — the AoS-versus-SoA benchmark, the struct
padding comparison, the producer-consumer simulation.

They compile independently with one `g++` invocation, share nothing with other files, and
carry no meaning apart from the prose that explains them.

---

## The rule

> Code with dependents belongs in `90_Code/`.
> Code that only ever runs alone to demonstrate one note belongs beside that note.

The test is whether anything else includes or imports the file.

---

## Build artifacts

Build directories are gitignored, and Obsidian excludes them through `userIgnoreFilters` in
`.obsidian/app.json`. Without the second exclusion, a CMake build directory adds thousands of
files to Obsidian's index and search results.

---

## See also

* [Build and test](../how-to/BuildAndTest.md)
* [Code conventions](../references/CodeConventions.md)
* [Build requirements](../references/BuildRequirements.md)
