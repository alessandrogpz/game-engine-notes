---
topic: Geometry
difficulty: Medium
tags: [exercise, question, distance-point-plane, implicit-plane, normal-vector]
---
# Question
## Part 1: Calculation
1. A plane is defined by the non-normalized 4D vector $\mathbf{f} = [2, -1, 2, -12]$:
   * Compute the magnitude of the [normal vector](../../../Concepts/05_Geometry/02_Normal_Vectors.md) $\|\mathbf{n}\|$.
   * Normalize the plane vector $\mathbf{f}$ by multiplying all 4 components by $\frac{1}{\|\mathbf{n}\|}$ to obtain $\mathbf{f}_{\text{norm}} = [\hat{n} \mid d_{\text{norm}}]$.
   * Calculate the signed perpendicular distance from point $\mathbf{p} = (3, 4, 1)$ to the plane by evaluating $\mathbf{f}_{\text{norm}} \cdot \mathbf{p}$. State whether $\mathbf{p}$ is in front of, behind, or on the plane.

2. A normalized plane is given by $\mathbf{f} = \left[ 0, \frac{3}{5}, \frac{4}{5}, -10 \right]$:
   * Calculate the signed perpendicular distance $D_1$ from point $\mathbf{p}_1 = (1, 10, 5)$ to the plane.
   * Calculate the signed perpendicular distance $D_0$ from the origin $\mathcal{O} = (0, 0, 0)$ to the plane.

## Part 2: Conceptual Understanding
1. Why is it necessary to normalize the plane vector $\mathbf{f} = [\mathbf{n} \mid d]$ before using $\mathbf{f} \cdot \mathbf{p}$ to compute physical distances? What does $\mathbf{f} \cdot \mathbf{p}$ yield if $\mathbf{n}$ is not unit length?
2. Explain geometrically why the signed distance $\mathbf{f} \cdot \mathbf{p} = \mathbf{n} \cdot \mathbf{p} + d$ represents the difference between the projection of $\mathbf{p}$ onto $\mathbf{n}$ and the projection of plane reference point $\mathbf{q}$ onto $\mathbf{n}$.
3. In camera frustum culling, how do game engines use the sign of $\mathbf{f} \cdot \mathbf{p}$ to classify whether an object lies inside, outside, or intersecting a view plane?

---
**Check Answer:** [S_05_Distance_Point_and_Plane](../Solutions/S_05_Distance_Point_and_Plane.md) | **Related Concepts:** [05_Distance_Point_and_Plane](../../../Concepts/05_Geometry/05_Distance_Point_and_Plane.md)
