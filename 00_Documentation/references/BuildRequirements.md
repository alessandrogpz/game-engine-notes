# Build Requirements

---

## The CMake project (`90_Code/`)

| | |
| :--- | :--- |
| Language standard | C++23 |
| Required feature | `import std;` (standard library modules) |
| Generator | **Ninja** — Unix Makefiles are unsupported |
| Test framework | GoogleTest, fetched automatically by CMake |
| Build types | `Debug`, `Release` |

```bash
cmake -S 90_Code -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug
cmake --build build
ctest --test-dir build --output-on-failure
```

### Targets

| Target | What it is |
| :--- | :--- |
| `EngineNotesLib` | Static library; every `.cppm` module |
| `EngineNotes` | Executable entry point (`main.cpp`) |
| `EngineNotesTests` | GoogleTest suite |

### If configuration fails

`import std;` support is gated behind a generator check and a CMake-version-specific activation UUID. Configuring under Makefiles produces:

```
`import std;` support was not enabled for CMake <version>.
Reason: Unsupported generator: Unix Makefiles
```

The fix is `-G Ninja`.

---

## Standalone examples

Single-file programs compiled directly, outside CMake:

| Purpose | Command |
| :--- | :--- |
| Benchmark / normal run | `g++ -std=c++23 -O3 -pthread <file>.cpp -o main` |
| Debugging | `g++ -std=c++23 -g -O0 -pthread <file>.cpp -o main` |
| Race detection | `g++ -std=c++23 -g -O1 -pthread -fsanitize=thread <file>.cpp -o main` |

| Flag | Why |
| :--- | :--- |
| `-std=c++23` | Examples use `<print>` and CTAD on lock wrappers |
| `-O3` | Mandatory for cache benchmarks — without inlining, call overhead masks the effect |
| `-pthread` | Required by the threading examples; sets `-D_REENTRANT` |
| `-fsanitize=thread` | Reports data races regardless of timing; 5–15× slowdown |

> [!WARNING]
> `-O3` is a capital letter O. Lowercase `-o3` is an output directive that writes an executable named `3` and enables no optimization at all.
