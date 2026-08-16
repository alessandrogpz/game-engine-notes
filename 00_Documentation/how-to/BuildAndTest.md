# Build and Test the Code

Two kinds of code live in this repository, built two different ways.

---

## The CMake project

`90_Code/` is a single C++23 library with a shared utility module, an umbrella module, and a GoogleTest suite.

```bash
cmake -S 90_Code -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug
cmake --build build
ctest --test-dir build --output-on-failure
```

> [!IMPORTANT]
> The **Ninja generator is required**. `import std;` is not supported under Unix Makefiles, and configuring without `-G Ninja` fails with an unsupported-generator error.

Build a single target rather than everything:

```bash
cmake --build build --target EngineNotesLib
```

## Standalone examples

Some subjects ship single-file programs that are compiled directly rather than through CMake — for example the data-oriented design benchmarks:

```bash
g++ -std=c++23 -O3 -pthread <path_to_file.cpp> -o main && ./main
```

> [!WARNING]
> `-O3` is **mandatory** for anything measuring cache behaviour. Without it, `std::vector::operator[]` is not inlined, and the resulting call overhead swamps the effect being measured — making a real speedup disappear entirely.

Debug build, for stepping through code. Timings from it are meaningless:

```bash
g++ -std=c++23 -g -O0 -pthread <file>.cpp -o main
```

Race detection, which reports data races even when the timing happened to work out. Costs a 5–15× slowdown, so it is a debugging tool only:

```bash
g++ -std=c++23 -g -O1 -pthread -fsanitize=thread <file>.cpp -o main
```

---

## Stale build directories

CMake caches absolute paths. If the repository is moved or renamed, delete the build directory and reconfigure rather than trying to repair it.

---

## See also

* [Build requirements](../references/BuildRequirements.md)
* [Repository structure](../references/RepositoryStructure.md)
