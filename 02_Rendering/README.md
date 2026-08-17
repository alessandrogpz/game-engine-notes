# Rendering

Getting geometry onto a screen, correctly and quickly.

> [!NOTE]
> **No notes yet.** This domain is at the roadmap stage. The plan — subjects, resources, and
> the order to take them in — is in [00_Roadmap.md](00_Roadmap.md).

---

## Planned subjects

| Subject | Covers |
| :--- | :--- |
| `01_Model_View_Projection` | Model/view/projection matrices, clip space, the perspective divide, reversed-Z |
| `02_Rasterization_Pipeline` | Edge functions, barycentrics, clipping, perspective-correct interpolation |
| `03_Graphics_APIs` | One modern API end to end; command buffers, pipeline state, frames in flight |
| `04_Shading_and_Lighting` | The rendering equation, BRDFs, microfacet models, colour and tone mapping |
| `05_Shadows_and_Visibility` | Shadow mapping and cascades, frustum and occlusion culling, LOD |
| `06_Advanced` | Deferred and clustered shading, post-processing, antialiasing, ray tracing |

Subjects gain `Concepts/`, `Exercises/` and `Assets/` folders as work begins.

---

## Builds on

* [Linear Algebra](../01_Mathematics/01_Linear_Algebra/README.md) — the transforms, planes and
  point-plane distances that are the machinery of the pipeline
* [04_Transforms](../01_Mathematics/01_Linear_Algebra/README.md#04_transforms) in particular,
  and [07_Homogeneous_Coordinates](../01_Mathematics/01_Linear_Algebra/Concepts/04_Transforms/07_Homogeneous_Coordinates.md)
