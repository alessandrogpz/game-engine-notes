# Code Conventions

Applies to `90_Code/` and to standalone demos beside notes.

---

## Standard

C++23, with C++20 modules. No `import std;` — see [Includes](#includes).

---

## Module structure

One module per concept note. A module interface unit (`.cppm`) has this shape:

```cpp
// Related Concept: [04_Planes](../../01_Mathematics/01_Linear_Algebra/Concepts/05_Geometry/04_Planes.md)
module;

#include <cmath>
#include <cstddef>

export module geometry_planes;

import engine_notes_util;

export namespace geometry {
    ...
}
```

| Element | Rule |
| :--- | :--- |
| First line | `// Related Concept:` with a relative link to the note |
| Global module fragment | `module;` followed by `#include` directives |
| Module name | `<topic>_<name>`, lowercase — `geometry_planes`, `vectors_dot_product` |
| Module imports | After `export module`, never inside the fragment |
| Namespace | Per topic — `systems`, `vectors`, `matrices`, `transforms`, `geometry` |

`00_Utils/util.cppm` is the one exception to the first rule: it is a shared utility rather than
the implementation of a concept, so there is no note for it to link.

---

## Includes

Standard library headers go in the **global module fragment**, introduced by a bare `module;`
before `export module`. `#include` is not permitted in the module purview.

Include only what the file uses:

| Facility | Header |
| :--- | :--- |
| `std::size_t` | `<cstddef>` |
| `std::cout`, `std::endl` | `<iostream>` |
| `std::setw`, `std::setprecision` | `<iomanip>` |
| `std::ios_base::fmtflags`, `std::streamsize` | `<ios>` |
| `std::cos`, `sin`, `tan`, `sqrt`, `abs`, `acos`, `atan2` | `<cmath>` |
| `std::numbers` | `<numbers>` |
| `std::clamp` | `<algorithm>` |

`import std;` is not used. Its CMake support is experimental, gated behind an activation UUID
that changes each release, and it requires a toolchain newer than CI provides.

Plain translation units (`.cpp` — tests, `main.cpp`) take `#include` at the top with no
module fragment.

---

## Shared utilities

`00_Utils/util.cppm` exports module `engine_notes_util`, namespace `util`. Float comparison
lives there:

```cpp
util::floatEqual(a, b)            // never a == b on floating point
```

`engine_notes.cppm` is the umbrella module and re-exports every sub-module. A new module is
added to it and to `target_sources` in `90_Code/CMakeLists.txt`.

---

## Stream formatting

`setw`, `setprecision` and `fixed` are sticky on the stream. Save and restore the caller's
formatting around any function that sets them:

```cpp
const std::ios_base::fmtflags savedFlags = std::cout.flags();
const std::streamsize savedPrecision = std::cout.precision();
std::cout << std::fixed << std::setprecision(4);
...
std::cout.flags(savedFlags);
std::cout.precision(savedPrecision);
```

---

## Tests

One test file per module, under `90_Code/tests/<Topic>/<Name>_tests.cpp`, GoogleTest.

| Assertion | Use |
| :--- | :--- |
| `EXPECT_FLOAT_EQ` | Exact float results |
| `EXPECT_NEAR` | Results carrying accumulated error; state the tolerance |
| `EXPECT_TRUE` / `EXPECT_FALSE` | Predicates |

A module that is still a placeholder gets a placeholder test asserting it runs. Both are
replaced together when the module is implemented.

---

## Compiler warnings

Targets build with `-Wall -Wextra -Wpedantic -mavx`. Warnings are not suppressed; they are
fixed.

---

## See also

* [Build requirements](BuildRequirements.md)
* [Build and test](../how-to/BuildAndTest.md)
* [Code placement](../explanation/CodePlacement.md)
