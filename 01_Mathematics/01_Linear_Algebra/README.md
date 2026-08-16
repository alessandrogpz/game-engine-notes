# Linear Algebra

The mathematical foundation everything else in this vault builds on — vectors and matrices,
the transforms an engine applies to them, and the geometry those transforms operate on.

Worked from Eric Lengyel's *Foundations of Game Engine Development, Volume 1*, with
derivations expanded where the book is terse and exercises added throughout.

**35 concept notes · 32 exercise pairs · 5 topics**

---

## 01_Systems_of_Equations

Solving simultaneous equations, and what the solution set looks like geometrically.

| Note | Exercise |
| :--- | :--- |
| [01_Linear_Systems](Concepts/01_Systems_of_Equations/01_Linear_Systems.md) | [Q](Exercises/01_Systems_of_Equations/Questions/) |

---

## 02_Vectors

The primitives. Every later topic is expressed in terms of these operations.

| Note | Covers |
| :--- | :--- |
| [01_Basics](Concepts/02_Vectors/01_Basics.md) | Magnitude, normalization, addition, scaling |
| [02_Dot_Product](Concepts/02_Vectors/02_Dot_Product.md) | Projection onto a direction; the angle test |
| [03_Coordinate_Systems](Concepts/02_Vectors/03_Coordinate_Systems.md) | Handedness, bases, the three-finger rule |
| [04_Cross_Product](Concepts/02_Vectors/04_Cross_Product.md) | The perpendicular generator; anti-commutativity |
| [05_Scalar_Triple_Product](Concepts/02_Vectors/05_Scalar_Triple_Product.md) | Parallelepiped volume; the determinant connection |
| [06_Vector_Projection](Concepts/02_Vectors/06_Vector_Projection.md) | Decomposing a vector into parallel and perpendicular parts |

Exercises: [Questions](Exercises/02_Vectors/Questions/) · [Solutions](Exercises/02_Vectors/Solutions/)

---

## 03_Matrices

Linear maps as objects — and the properties that decide whether a map can be undone.

| Note | Covers |
| :--- | :--- |
| [01_Basics](Concepts/03_Matrices/01_Basics.md) | Notation, indexing, identity |
| [02_Matrix_Multiplication](Concepts/03_Matrices/02_Matrix_Multiplication.md) | Composition of maps; why it is not commutative |
| [03_Determinants](Concepts/03_Matrices/03_Determinants.md) | Signed volume scale; invertibility test |
| [04_Matrix_Inversion](Concepts/03_Matrices/04_Matrix_Inversion.md) | Adjugate, cofactors, the inverse |
| [05_Orthogonal_Matrices](Concepts/03_Matrices/05_Orthogonal_Matrices.md) | Transpose as inverse; rigid motions |
| [06_Projection_Matrices](Concepts/03_Matrices/06_Projection_Matrices.md) | Projection onto a subspace; idempotence |
| [07_Rank_Nullity](Concepts/03_Matrices/07_Rank_Nullity.md) | Rank, nullity, and solvability |

Exercises: [Questions](Exercises/03_Matrices/Questions/) · [Solutions](Exercises/03_Matrices/Solutions/)

> [!NOTE]
> `06_Projection_Matrices` is the *linear algebra* sense — projecting onto a subspace,
> $\mathbf{P} = \hat{u}\hat{u}^T$. Perspective projection is a different operation entirely and
> belongs to [02_Rendering](../../02_Rendering/00_Roadmap.md).

---

## 04_Transforms

Moving objects between coordinate spaces — the chapter an engine uses every frame.

| Note | Covers |
| :--- | :--- |
| [01_Transformation_Matrices](Concepts/04_Transforms/01_Transformation_Matrices.md) | Change of basis; the transform pipeline |
| [02_Rotations](Concepts/04_Transforms/02_Rotations.md) | Principal-axis and arbitrary-axis rotation |
| [03_Reflections](Concepts/04_Transforms/03_Reflections.md) | Mirroring; the handedness flip |
| [04_Scales](Concepts/04_Transforms/04_Scales.md) | Uniform and non-uniform scaling |
| [05_Skews](Concepts/04_Transforms/05_Skews.md) | Shearing along an axis |
| [06_Translations](Concepts/04_Transforms/06_Translations.md) | Why translation needs a fourth dimension |
| [07_Homogeneous_Coordinates](Concepts/04_Transforms/07_Homogeneous_Coordinates.md) | $w = 1$ for points, $w = 0$ for directions |
| [08_Matrix_Composition_4x4](Concepts/04_Transforms/08_Matrix_Composition_4x4.md) | Combining transforms; order dependence |
| [09_Quaternion_Intuition](Concepts/04_Transforms/09_Quaternion_Intuition.md) | Building intuition before the algebra |
| [09a_Stereographic_Projection_Derivation](Concepts/04_Transforms/09a_Stereographic_Projection_Derivation.md) | Mapping a hypersphere down a dimension |
| [10_Quaternions](Concepts/04_Transforms/10_Quaternions.md) | Hamilton product, sandwich rotation, slerp |

Exercises: [Questions](Exercises/04_Transforms/Questions/) · [Solutions](Exercises/04_Transforms/Solutions/)

---

## 05_Geometry

Planes, lines and their intersections — the machinery behind culling, collision and ray casting.

| Note | Covers |
| :--- | :--- |
| [01_Triangle_Meshes](Concepts/05_Geometry/01_Triangle_Meshes.md) | Vertex and index buffers; Euler's formula |
| [02_Normal_Vectors](Concepts/05_Geometry/02_Normal_Vectors.md) | Winding order; the inverse-transpose rule |
| [03_Lines_and_Rays](Concepts/05_Geometry/03_Lines_and_Rays.md) | Parametric form; point-line and line-line distance |
| [04_Planes](Concepts/05_Geometry/04_Planes.md) | Parametric and implicit forms; the 4D plane vector |
| [05_Distance_Point_and_Plane](Concepts/05_Geometry/05_Distance_Point_and_Plane.md) | Signed distance; frustum culling |
| [06_Reflection_Through_Plane](Concepts/05_Geometry/06_Reflection_Through_Plane.md) | Mirroring a point; the $4 \times 4$ reflection matrix |
| [07_Intersection_Line_and_Plane](Concepts/05_Geometry/07_Intersection_Line_and_Plane.md) | Solving for $t$; ray sign conditions and backface culling |
| [08_Intersection_Three_Planes](Concepts/05_Geometry/08_Intersection_Three_Planes.md) | The linear system; singular cases |
| [09_Intersection_Two_Planes](Concepts/05_Geometry/09_Intersection_Two_Planes.md) | The intersection line; closest point to the origin |
| [10_Transforming_Planes](Concepts/05_Geometry/10_Transforming_Planes.md) | Why planes transform by $\mathrm{adj}(\mathbf{H})$ |

Exercises: [Questions](Exercises/05_Geometry/Questions/) · [Solutions](Exercises/05_Geometry/Solutions/)

---

## Related

* [Mathematics roadmap](../00_Roadmap.md) — the remaining subjects and how much of each to learn
* [C++ implementations](../../90_Code/) — one module per concept note, with tests
* [Figures](Assets/) — diagrams embedded by the notes

Open threads for this subject are in [TODO.md](../../TODO.md).
