# TODO

Open threads, grouped by **domain** so each stays findable as the vault grows. Completed
items are kept rather than deleted — they record what has been worked through.

| Domain | Open |
| :--- | :--- |
| [Mathematics](#mathematics) | 1 solution · 9 modules |

---

## Mathematics

### Linear Algebra — solution derivations

Solution files still holding an `[Insert ...]` placeholder.

*Geometry*

- [x] **Triangle Meshes** — Euler's formula calculations and conceptual answers: [S_01](01_Mathematics/01_Linear_Algebra/Exercises/05_Geometry/Solutions/S_01_Triangle_Meshes.md)
- [x] **Normal Vectors** — cross product calculation and normal-transformation proofs: [S_02](01_Mathematics/01_Linear_Algebra/Exercises/05_Geometry/Solutions/S_02_Normal_Vectors.md)
- [x] **Lines and Rays** — point-to-line and skew line distance derivations: [S_03](01_Mathematics/01_Linear_Algebra/Exercises/05_Geometry/Solutions/S_03_Lines_and_Rays.md)
- [x] **Planes** — parametric plane and 4D implicit plane calculations: [S_04](01_Mathematics/01_Linear_Algebra/Exercises/05_Geometry/Solutions/S_04_Planes.md)
- [x] **Distance Between a Point and a Plane** — plane normalization and signed distance: [S_05](01_Mathematics/01_Linear_Algebra/Exercises/05_Geometry/Solutions/S_05_Distance_Point_and_Plane.md)
- [x] **Reflection Through a Plane** — closest-point and reflected-point calculations, $4 \times 4$ reflection matrix: [S_06](01_Mathematics/01_Linear_Algebra/Exercises/05_Geometry/Solutions/S_06_Reflection_Through_Plane.md)
- [x] **Intersection of a Line and a Plane** — solving for $t$, parallel-case classification, ray sign conditions: [S_07](01_Mathematics/01_Linear_Algebra/Exercises/05_Geometry/Solutions/S_07_Intersection_Line_and_Plane.md)
- [x] **Intersection of Three Planes** — linear system setup, scalar triple product, cross-product solution, singular cases: [S_08](01_Mathematics/01_Linear_Algebra/Exercises/05_Geometry/Solutions/S_08_Intersection_Three_Planes.md)
- [x] **Intersection of Two Planes** — direction via cross product, third-plane construction, closest-point property, parallel cases: [S_09](01_Mathematics/01_Linear_Algebra/Exercises/05_Geometry/Solutions/S_09_Intersection_Two_Planes.md)
- [ ] **Transforming Planes** — adjugate normal transform, $d^B$ derivation, shear and reflection cases, determinant sign: [S_10](01_Mathematics/01_Linear_Algebra/Exercises/05_Geometry/Solutions/S_10_Transforming_Planes.md)

### Linear Algebra — C++ modules

Modules that currently contain only a console-log placeholder. Their test files are
placeholders too, and become real tests once the module is implemented.

*Systems of Equations*

- [ ] **Gaussian Elimination / Solver**: [Linear_Systems.cppm](90_Code/01_Systems_of_Equations/Linear_Systems.cppm)

*Geometry*

- [ ] **Triangle Meshes** — indexed vertex/index buffers, closed-mesh validation: [Triangle_Meshes.cppm](90_Code/05_Geometry/Triangle_Meshes.cppm)
- [x] **Normal Vectors** — face normal via cross product, inverse-transpose transform: [Normal_Vectors.cppm](90_Code/05_Geometry/Normal_Vectors.cppm)
- [x] **Lines and Rays** — point-to-line and skew/parallel line distances: [Lines_and_Rays.cppm](90_Code/05_Geometry/Lines_and_Rays.cppm)
- [ ] **Planes** — parametric plane, implicit plane dot product, 4D plane vector: [Planes.cppm](90_Code/05_Geometry/Planes.cppm)
- [ ] **Distance Between a Point and a Plane** — normalization, signed distance evaluation: [Distance_Point_and_Plane.cppm](90_Code/05_Geometry/Distance_Point_and_Plane.cppm)
- [ ] **Reflection Through a Plane** — closest point, reflected point, $4 \times 4$ matrix: [Reflection_Through_Plane.cppm](90_Code/05_Geometry/Reflection_Through_Plane.cppm)
- [ ] **Intersection of a Line and a Plane** — parameter $t$, intersection point, parallel guard, ray $t \ge 0$ test: [Intersection_Line_and_Plane.cppm](90_Code/05_Geometry/Intersection_Line_and_Plane.cppm)
- [ ] **Intersection of Three Planes** — scalar triple product determinant, cross-product solution, singular handling: [Intersection_Three_Planes.cppm](90_Code/05_Geometry/Intersection_Three_Planes.cppm)
- [ ] **Intersection of Two Planes** — direction cross product, point solution, parallel and coincident guards: [Intersection_Two_Planes.cppm](90_Code/05_Geometry/Intersection_Two_Planes.cppm)
- [ ] **Transforming Planes** — adjugate construction, transform via $\mathrm{adj}(\mathbf{H})$, determinant sign correction: [Transforming_Planes.cppm](90_Code/05_Geometry/Transforming_Planes.cppm)

---

## Other domains

No open items — [02_Rendering](02_Rendering/00_Roadmap.md) through
[11_Networking](11_Networking/00_Roadmap.md) are still at the roadmap stage. Work lands here
once a subject has notes or code.

---

## Conventions

* Group by **domain first**, then by kind — solutions, modules, notes.
* Add the entry when the placeholder is created, not later.
* Keep completed items checked rather than deleting them.
