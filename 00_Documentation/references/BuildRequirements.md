# Build Requirements

What the toolchain must provide. The commands to run are in
[Build and test](../how-to/BuildAndTest.md).

---

## The CMake project (`90_Code/`)

| | |
| :--- | :--- |
| Language standard | C++23 |
| Required feature | C++20 modules (`export module`) |
| Compiler | **GCC 15 or newer** |
| Generator | **Ninja** — Unix Makefiles are unsupported |
| CMake | 3.28 or newer, for `FILE_SET CXX_MODULES` |
| Test framework | GoogleTest, fetched automatically by CMake |
| Build types | `Debug`, `Release` |

### Why the compiler version

Module support improves sharply across GCC releases, and the failures are not obvious:

| Version | Behaviour |
| :--- | :--- |
| GCC 13 | Cannot scan module dependencies at all |
| GCC 14 | Scans, but corrupts its own module cache under parallel builds — *"failed to read compiled module cluster"* |
| GCC 15+ | Builds this project cleanly |

CI installs GCC 15 and builds serially (`-j 1`), which is what keeps the GCC 14 cache
behaviour from mattering if an older compiler is ever used.

### Targets

| Target | What it is |
| :--- | :--- |
| `EngineNotesLib` | Static library; every `.cppm` module |
| `EngineNotes` | Executable entry point (`main.cpp`) |
| `EngineNotesTests` | GoogleTest suite |

### If configuration fails

C++ modules need a generator that supports **dyndep** — dynamic dependency discovery —
because the compile order cannot be known until module dependencies are scanned. Unix
Makefiles cannot do this, so configuring without `-G Ninja` fails at the generate step:

```
CMake Generate step failed.  Build files cannot be regenerated correctly.
```

The fix is `-G Ninja`.

---

## Compile flags

Applied to the library target by CMake, and typed by hand for the standalone demos:

| Flag | Why |
| :--- | :--- |
| `-std=c++23` | Examples use `<print>` and CTAD on lock wrappers |
| `-O3` | Mandatory for cache benchmarks — without inlining, call overhead masks the effect |
| `-pthread` | Required by the threading examples; sets `-D_REENTRANT` |
| `-fsanitize=thread` | Reports data races regardless of timing; 5–15× slowdown |
| `-Wall -Wextra -Wpedantic -mavx` | Set on `EngineNotesLib` (`/W4` on MSVC). Warnings are fixed, never suppressed |
