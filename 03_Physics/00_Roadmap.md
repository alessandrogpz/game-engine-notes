# Physics — Study Roadmap

Collision detection and rigid body simulation. Heavily dependent on [05_Geometry](../01_Mathematics/01_Linear_Algebra/Concepts/05_Geometry/) and on numerical stability.

> [!NOTE]
> Placeholder. Subjects gain `Concepts/`, `Exercises/` and `Assets/` folders as work begins.

---

## Suggested Subjects

### 01_Collision_Primitives
* Spheres, AABBs, OBBs, capsules, convex hulls
* Closest-point queries: point–segment, point–triangle, segment–segment
* Ray casts against each primitive — extends [07_Intersection_Line_and_Plane](../01_Mathematics/01_Linear_Algebra/Concepts/05_Geometry/07_Intersection_Line_and_Plane.md)

### 02_Narrow_Phase
* Separating Axis Theorem for convex shapes
* GJK — distance between convex sets via Minkowski difference
* EPA — penetration depth once GJK reports overlap
* Contact manifold generation: the part everyone underestimates
* Sutherland–Hodgman clipping for face-face contacts

### 03_Broad_Phase
* Sweep and prune, spatial hashing, dynamic BVH
* Shares structures with [05_Data_Structures](../05_Data_Structures/00_Roadmap.md) and rendering culling

### 04_Rigid_Body_Dynamics
* Linear and angular motion; inertia tensors
* Integrators: semi-implicit Euler and Verlet, and why not RK4 — see [Numerical Methods](../01_Mathematics/00_Roadmap.md)
* Impulses and sequential impulse solvers
* Constraints and joints; Baumgarte stabilization; warm starting
* Friction and restitution
* Sleeping and islands

### 05_Continuous_Collision
* Tunnelling and why discrete tests miss fast objects
* Conservative advancement, time of impact, speculative contacts

### 06_Beyond_Rigid_Bodies *(optional)*
* Particles, cloth (position-based dynamics), soft bodies, fluids

---

## Resources

| Resource | Use |
| :--- | :--- |
| Ericson, *Real-Time Collision Detection* | The standard. Read sequentially — it is genuinely excellent |
| Millington, *Game Physics Engine Development* | Builds an engine step by step |
| Erin Catto's GDC talks / Box2D source | Sequential impulses, solver design. Box2D is small enough to read whole |
| Dirk Gregorius's GDC talks | SAT, convex hulls, contact generation |
| [gafferongames.com](https://gafferongames.com/) physics articles | Integrators and networked physics |

---

## Suggested Order

Primitives and closest-point queries → broad phase → SAT/GJK → integrators → constraint solver → continuous collision. Build a particle system before a rigid body system; get integration right before adding rotation.
