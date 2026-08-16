# Rendering — Study Roadmap

Getting geometry onto a screen, correctly and quickly. This is the domain with the most direct payoff from the [linear algebra](../01_Mathematics/01_Linear_Algebra/) already covered — transforms, planes and point-plane distance are the machinery of the pipeline.

> [!NOTE]
> Placeholder. Subjects gain `Concepts/`, `Exercises/` and `Assets/` folders as work begins, following the layout in the root README.

---

## Suggested Subjects

### 01_Model_View_Projection
The single highest-value topic to start with. Builds directly on [04_Transforms](../01_Mathematics/01_Linear_Algebra/Concepts/04_Transforms/) and [07_Homogeneous_Coordinates](../01_Mathematics/01_Linear_Algebra/Concepts/04_Transforms/07_Homogeneous_Coordinates.md).

* Model, view and projection matrices, and why the order is what it is
* Perspective vs orthographic projection; deriving the perspective matrix
* Clip space, the perspective divide, NDC, the viewport transform
* Depth: the non-linearity of `z/w`, precision loss, reversed-Z
* Extracting the six frustum planes — connects to [05_Distance_Point_and_Plane](../01_Mathematics/01_Linear_Algebra/Concepts/05_Geometry/05_Distance_Point_and_Plane.md)
* Convention traps: handedness, row vs column vectors, depth range `[-1,1]` vs `[0,1]`

### 02_Rasterization_Pipeline
Best learned by writing a software rasterizer with no graphics API at all.

* Triangle setup, edge functions, barycentric coordinates
* Clipping (Sutherland–Hodgman) and guard-band clipping
* Depth buffering, early-Z, overdraw
* Perspective-correct interpolation — and why naive interpolation is wrong
* Backface culling, winding order, fill rules

### 03_Graphics_APIs
* One modern API end to end. OpenGL first for lower friction, Vulkan for where the industry is
* Command buffers, pipeline state, descriptor sets, synchronization
* Buffers, textures, samplers, render passes
* The CPU/GPU boundary: uploads, staging, frames in flight

### 04_Shading_and_Lighting
* The rendering equation, read as an integral
* BRDFs; diffuse and specular; energy conservation
* Physically based rendering: microfacet models, Cook–Torrance, GGX
* Normal mapping, tangent space — reuses [02_Normal_Vectors](../01_Mathematics/01_Linear_Algebra/Concepts/05_Geometry/02_Normal_Vectors.md) and the inverse-transpose rule
* Image-based lighting, irradiance and prefiltered environment maps
* Colour: linear vs sRGB, gamma, tone mapping, HDR

### 05_Shadows_and_Visibility
* Shadow mapping, cascades, peter-panning and acne
* Shadow volumes — the stencil approach, and where Plücker sidedness tests appear
* Frustum culling, occlusion culling, portals, PVS
* Level of detail

### 06_Advanced
* Deferred vs forward vs forward+ / clustered
* Post-processing: bloom, SSAO, motion blur, depth of field
* Antialiasing: MSAA, FXAA, TAA — where [signal processing](../01_Mathematics/00_Roadmap.md) pays off
* Ray tracing and path tracing; hardware RT
* Compute shaders, GPU-driven rendering

---

## Resources

| Resource | Use |
| :--- | :--- |
| Lengyel, *FGED Vol 2: Rendering* | The math, rigorously. Read projections/clipping closely; treat the rest as reference |
| Akenine-Möller et al., *Real-Time Rendering* (4th ed) | The comprehensive survey. Reference, not sequential |
| [pbr-book.org](https://pbr-book.org/) | Physically Based Rendering, free online. The definitive path-tracing text |
| [learnopengl.com](https://learnopengl.com/) | Fastest route to a working renderer |
| [vkguide.dev](https://vkguide.dev/) | Vulkan, modern structure |
| [tinyrenderer](https://github.com/ssloy/tinyrenderer) | Software rasterizer from scratch |
| [Ray Tracing in One Weekend](https://raytracing.github.io/) | Short, complete, satisfying |

---

## Suggested Order

MVP → software rasterizer → one real API → shading → shadows → advanced. Do not read Volume 2 front to back before writing code; it assumes you are implementing.
