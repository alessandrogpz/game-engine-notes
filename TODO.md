# Project TODO List

Use this list to track the remaining exercises and code implementations that need to be completed in this project.

## 1. Exercise Solution Notes (Placeholders)

These solution files still contain `[Insert ...]` placeholders that need LaTeX mathematics or conceptual descriptions.

### Geometry
- [x] Complete **Triangle Meshes** derivation (Euler's formula calculations & conceptual answers): [S_01_Triangle_Meshes.md](02_Exercises/05_Geometry/Solutions/S_01_Triangle_Meshes.md)
- [x] Complete **Normal Vectors** derivation (cross product calculation & normal-transformation proofs): [S_02_Normal_Vectors.md](02_Exercises/05_Geometry/Solutions/S_02_Normal_Vectors.md)
- [x] Complete **Lines and Rays** derivation (point-to-line & skew line distance derivations): [S_03_Lines_and_Rays.md](02_Exercises/05_Geometry/Solutions/S_03_Lines_and_Rays.md)
- [x] Complete **Planes** derivation (parametric plane & 4D implicit plane calculations): [S_04_Planes.md](02_Exercises/05_Geometry/Solutions/S_04_Planes.md)
- [x] Complete **Distance Between a Point and a Plane** derivation (plane normalization & signed distance calculations): [S_05_Distance_Point_and_Plane.md](02_Exercises/05_Geometry/Solutions/S_05_Distance_Point_and_Plane.md)
- [x] Complete **Reflection Through a Plane** derivation (closest-point & reflected-point calculations, $4 \times 4$ reflection matrix construction): [S_06_Reflection_Through_Plane.md](02_Exercises/05_Geometry/Solutions/S_06_Reflection_Through_Plane.md)

---

## 2. Skeletal C++ Code Modules

These files contain only console-log helper tests and need their core mathematical functions and algorithms implemented.

### Systems of Equations
- [ ] Implement **Gaussian Elimination / Solver** logic: [Linear_Systems.cppm](03_Code/01_Systems_of_Equations/Linear_Systems.cppm)

### Geometry
- [ ] Implement **Triangle Mesh** representation (indexed vertex/index buffers, closed-mesh validation): [Triangle_Meshes.cppm](03_Code/05_Geometry/Triangle_Meshes.cppm)
- [ ] Implement **Normal Vector** calculation and transformation (face normal via cross product, inverse-transpose transform): [Normal_Vectors.cppm](03_Code/05_Geometry/Normal_Vectors.cppm)
- [ ] Implement **Lines and Rays** calculations (point-to-line & skew/parallel line distances): [Lines_and_Rays.cppm](03_Code/05_Geometry/Lines_and_Rays.cppm)
- [ ] Implement **Planes** representations (parametric plane, implicit plane dot product, 4D plane vector): [Planes.cppm](03_Code/05_Geometry/Planes.cppm)
- [ ] Implement **Distance Between a Point and a Plane** calculations (plane normalization, signed distance evaluation): [Distance_Point_and_Plane.cppm](03_Code/05_Geometry/Distance_Point_and_Plane.cppm)
- [ ] Implement **Reflection Through a Plane** calculations (closest point in plane, reflected point, $4 \times 4$ reflection matrix construction): [Reflection_Through_Plane.cppm](03_Code/05_Geometry/Reflection_Through_Plane.cppm)
