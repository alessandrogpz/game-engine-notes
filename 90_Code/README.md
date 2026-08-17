# Code

One buildable C++23 project. Every concept note that has an implementation has exactly one
module here, and the folder layout mirrors the topic folders in
[01_Linear_Algebra](../01_Mathematics/01_Linear_Algebra/README.md).

**30 modules · GoogleTest suite · CMake + Ninja**

---

## Build

```bash
cmake -S 90_Code -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug
cmake --build build
ctest --test-dir build --output-on-failure
```

> [!IMPORTANT]
> The **Ninja generator is required** — C++ modules need dyndep to discover compile order, and
> Unix Makefiles cannot provide it. **GCC 15 or newer** is required as well.

Full instructions in [Build and Test the Code](../00_Documentation/how-to/BuildAndTest.md);
toolchain details in [Build Requirements](../00_Documentation/references/BuildRequirements.md).

---

## Layout

| File | Contents |
| :--- | :--- |
| [engine_notes.cppm](engine_notes.cppm) | Umbrella module re-exporting every sub-module |
| [main.cpp](main.cpp) | Scratch entry point for trying a module by hand |
| [CMakeLists.txt](CMakeLists.txt) | Library target and the `FILE_SET CXX_MODULES` list |
| [tests/CMakeLists.txt](tests/CMakeLists.txt) | GoogleTest, one file per module |

### Modules

| Topic | Modules |
| :--- | :--- |
| `00_Utils` | [util](00_Utils/util.cppm) — `util::floatEqual`, never compare floats with `==` |
| `01_Systems_of_Equations` | [Linear_Systems](01_Systems_of_Equations/Linear_Systems.cppm) |
| `02_Vectors` | [Basics](02_Vectors/Basics.cppm) · [Dot_Product](02_Vectors/Dot_Product.cppm) · [Coordinate_Systems](02_Vectors/Coordinate_Systems.cppm) · [Cross_Product](02_Vectors/Cross_Product.cppm) · [Scalar_Triple_Product](02_Vectors/Scalar_Triple_Product.cppm) · [Vector_Projection](02_Vectors/Vector_Projection.cppm) |
| `03_Matrices` | [Basics](03_Matrices/Basics.cppm) · [Matrix_Multiplication](03_Matrices/Matrix_Multiplication.cppm) · [Determinants](03_Matrices/Determinants.cppm) · [Matrix_Inversion](03_Matrices/Matrix_Inversion.cppm) · [Orthogonal_Matrices](03_Matrices/Orthogonal_Matrices.cppm) · [Projection_Matrices](03_Matrices/Projection_Matrices.cppm) |
| `04_Transforms` | [Rotations](04_Transforms/Rotations.cppm) · [Reflections](04_Transforms/Reflections.cppm) · [Scales](04_Transforms/Scales.cppm) · [Skews](04_Transforms/Skews.cppm) · [Translations](04_Transforms/Translations.cppm) · [Quaternions](04_Transforms/Quaternions.cppm) |
| `05_Geometry` | [Triangle_Meshes](05_Geometry/Triangle_Meshes.cppm) · [Normal_Vectors](05_Geometry/Normal_Vectors.cppm) · [Lines_and_Rays](05_Geometry/Lines_and_Rays.cppm) · [Planes](05_Geometry/Planes.cppm) · [Distance_Point_and_Plane](05_Geometry/Distance_Point_and_Plane.cppm) · [Reflection_Through_Plane](05_Geometry/Reflection_Through_Plane.cppm) · [Intersection_Line_and_Plane](05_Geometry/Intersection_Line_and_Plane.cppm) · [Intersection_Three_Planes](05_Geometry/Intersection_Three_Planes.cppm) · [Intersection_Two_Planes](05_Geometry/Intersection_Two_Planes.cppm) · [Transforming_Planes](05_Geometry/Transforming_Planes.cppm) |

---

## Conventions

Module names are `<topic>_<name>`, lowercase — `geometry_intersection_two_planes`. Each
`.cppm` opens with a `// Related Concept:` link back to its note, and `#include` goes in the
global module fragment. **Never `import std;`.**

A new module is registered in two places: [engine_notes.cppm](engine_notes.cppm) and the
`target_sources` list in [CMakeLists.txt](CMakeLists.txt).

Full rules in [Code Conventions](../00_Documentation/references/CodeConventions.md).

---

## Related

* [Linear Algebra](../01_Mathematics/01_Linear_Algebra/README.md) — the notes these modules implement
* [Code Placement](../00_Documentation/explanation/CodePlacement.md) — why some code lives here
  and some lives beside its note
* Unimplemented modules are tracked in [TODO.md](../TODO.md)
