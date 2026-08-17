# Physics

Collision detection and rigid body simulation.

> [!NOTE]
> **No notes yet.** This domain is at the roadmap stage. The plan — subjects, resources, and
> the order to take them in — is in [00_Roadmap.md](00_Roadmap.md).

---

## Planned subjects

| Subject | Covers |
| :--- | :--- |
| `01_Collision_Primitives` | Spheres, AABBs, OBBs, capsules, hulls; closest-point queries; ray casts |
| `02_Narrow_Phase` | SAT, GJK, EPA, contact manifold generation |
| `03_Broad_Phase` | Sweep and prune, spatial hashing, dynamic BVH |
| `04_Rigid_Body_Dynamics` | Inertia tensors, integrators, sequential impulses, constraints, friction |
| `05_Continuous_Collision` | Tunnelling, conservative advancement, time of impact |
| `06_Beyond_Rigid_Bodies` | *(optional)* Particles, cloth, soft bodies, fluids |

Subjects gain `Concepts/`, `Exercises/` and `Assets/` folders as work begins.

---

## Builds on

* [05_Geometry](../01_Mathematics/01_Linear_Algebra/README.md#05_geometry) — the intersection
  and distance machinery every collision query is built from
* [Numerical Methods](../01_Mathematics/00_Roadmap.md) — integrator stability decides whether a
  simulation holds together
