# Linear Algebra

## 01_Systems_of_Equations

Solving simultaneous equations, and what the solution set looks like geometrically.

| Note | Exercise |
| :--- | :--- |
| [01_Linear_Systems](Concepts/01_Systems_of_Equations/01_Linear_Systems.md) | [Q_01_Linear_Systems](Exercises/01_Systems_of_Equations/Questions/Q_01_Linear_Systems.md) |

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

**Exercises** — each question links its own solution:
[Q_02_Dot_Product](Exercises/02_Vectors/Questions/Q_02_Dot_Product.md) ·
[Q_04_Cross_Product](Exercises/02_Vectors/Questions/Q_04_Cross_Product.md) ·
[Q_05_Scalar_Triple_Product](Exercises/02_Vectors/Questions/Q_05_Scalar_Triple_Product.md) ·
[Q_06_Vector_Projection](Exercises/02_Vectors/Questions/Q_06_Vector_Projection.md) ·
[Q_06_Projection_Orthogonality](Exercises/02_Vectors/Questions/Q_06_Projection_Orthogonality.md) ·
[Q_06_Projection_Properties](Exercises/02_Vectors/Questions/Q_06_Projection_Properties.md)

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

**Exercises** — each question links its own solution:
[Q_02_Matrix_Multiplication](Exercises/03_Matrices/Questions/Q_02_Matrix_Multiplication.md) ·
[Q_03_Determinants](Exercises/03_Matrices/Questions/Q_03_Determinants.md) ·
[Q_04_Matrix_Inversion_2x2](Exercises/03_Matrices/Questions/Q_04_Matrix_Inversion_2x2.md) ·
[Q_04_Gauss_Jordan_3x3](Exercises/03_Matrices/Questions/Q_04_Gauss_Jordan_3x3.md) ·
[Q_06_Projection_Matrix](Exercises/03_Matrices/Questions/Q_06_Projection_Matrix.md)

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

**Exercises** — each question links its own solution:
[Q_01_Transformation_Matrices](Exercises/04_Transforms/Questions/Q_01_Transformation_Matrices.md) ·
[Q_02_Rotations](Exercises/04_Transforms/Questions/Q_02_Rotations.md) ·
[Q_03_Reflections](Exercises/04_Transforms/Questions/Q_03_Reflections.md) ·
[Q_04_Scales](Exercises/04_Transforms/Questions/Q_04_Scales.md) ·
[Q_05_Skews](Exercises/04_Transforms/Questions/Q_05_Skews.md) ·
[Q_06_Translations](Exercises/04_Transforms/Questions/Q_06_Translations.md) ·
[Q_07_Homogeneous_Coordinates](Exercises/04_Transforms/Questions/Q_07_Homogeneous_Coordinates.md) ·
[Q_08_Matrix_Composition_4x4](Exercises/04_Transforms/Questions/Q_08_Matrix_Composition_4x4.md) ·
[Q_09_Quaternion_Intuition](Exercises/04_Transforms/Questions/Q_09_Quaternion_Intuition.md) ·
[Q_10_Quaternions](Exercises/04_Transforms/Questions/Q_10_Quaternions.md)

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

**Exercises** — each question links its own solution:
[Q_01_Triangle_Meshes](Exercises/05_Geometry/Questions/Q_01_Triangle_Meshes.md) ·
[Q_02_Normal_Vectors](Exercises/05_Geometry/Questions/Q_02_Normal_Vectors.md) ·
[Q_03_Lines_and_Rays](Exercises/05_Geometry/Questions/Q_03_Lines_and_Rays.md) ·
[Q_04_Planes](Exercises/05_Geometry/Questions/Q_04_Planes.md) ·
[Q_05_Distance_Point_and_Plane](Exercises/05_Geometry/Questions/Q_05_Distance_Point_and_Plane.md) ·
[Q_06_Reflection_Through_Plane](Exercises/05_Geometry/Questions/Q_06_Reflection_Through_Plane.md) ·
[Q_07_Intersection_Line_and_Plane](Exercises/05_Geometry/Questions/Q_07_Intersection_Line_and_Plane.md) ·
[Q_08_Intersection_Three_Planes](Exercises/05_Geometry/Questions/Q_08_Intersection_Three_Planes.md) ·
[Q_09_Intersection_Two_Planes](Exercises/05_Geometry/Questions/Q_09_Intersection_Two_Planes.md) ·
[Q_10_Transforming_Planes](Exercises/05_Geometry/Questions/Q_10_Transforming_Planes.md)
