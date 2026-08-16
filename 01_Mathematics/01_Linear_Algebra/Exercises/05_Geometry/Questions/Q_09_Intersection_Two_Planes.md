---
topic: Geometry
difficulty: Medium
tags: [exercise, question, intersection-two-planes, implicit-plane, cross-product, parametric-line]
---
# Question
## Part 1: Calculation
1. Two planes are given by $\mathbf{f}_1 = [1, 0, 0, -2]$ and $\mathbf{f}_2 = [0, 1, 0, -3]$:
   * Compute the direction vector $\mathbf{v} = \mathbf{n}_1 \times \mathbf{n}_2$ and $\mathbf{v}^2$, confirming the planes are not parallel.
   * Compute the two [cross products](../../../Concepts/02_Vectors/04_Cross_Product.md) $\mathbf{v} \times \mathbf{n}_2$ and $\mathbf{n}_1 \times \mathbf{v}$.
   * Solve for the point $\mathbf{p}$ and state the full [parametric line](../../../Concepts/05_Geometry/03_Lines_and_Rays.md) $L(t) = \mathbf{p} + t\mathbf{v}$.
   * Verify the result by confirming $\mathbf{f}_1 \cdot \mathbf{p} = 0$ and $\mathbf{f}_2 \cdot \mathbf{p} = 0$. Describe the line geometrically and sanity-check it against what the two plane equations state directly.

2. Two general planes are given by $\mathbf{f}_1 = [1, 1, 0, -3]$ and $\mathbf{f}_2 = [0, 1, 1, -5]$:
   * Compute $\mathbf{v}$ and $\mathbf{v}^2$.
   * Solve for $\mathbf{p}$, leaving the components as fractions.
   * Verify that $\mathbf{p}$ satisfies both planes.

3. Confirm the identity that makes the denominator collapse. For the planes in Question 2, compute the [scalar triple product](../../../Concepts/02_Vectors/05_Scalar_Triple_Product.md) $[\mathbf{n}_1, \mathbf{n}_2, \mathbf{v}]$ directly from the [determinant](../../../Concepts/03_Matrices/03_Determinants.md) of the $3 \times 3$ matrix whose rows are $\mathbf{n}_1$, $\mathbf{n}_2$ and $\mathbf{v}$, and show it equals $\mathbf{v}^2$.

4. Classify each of the following pairs, computing $\mathbf{v}^2$ first and then determining what the intersection actually is:
   * $\mathbf{f}_1 = [1, 0, 0, -1]$ and $\mathbf{f}_2 = [2, 0, 0, -6]$
   * $\mathbf{f}_1 = [1, 0, 0, -1]$ and $\mathbf{f}_2 = [2, 0, 0, -2]$

5. Using the point $\mathbf{p}$ and direction $\mathbf{v}$ from Question 1, compute $\mathbf{v} \cdot \mathbf{p}$ and $\|\mathbf{p}\|$. Then compute $\|\mathbf{p} + t\mathbf{v}\|$ for $t = 1$ and $t = -1$, and state what this demonstrates about which point on the line the formula returns.

## Part 2: Conceptual Understanding
1. Explain why the direction of the intersection line must be $\mathbf{n}_1 \times \mathbf{n}_2$. Why does a vector perpendicular to both normals necessarily lie *within* both planes?
2. The construction introduces a third plane $[\mathbf{v} \mid 0]$ and then solves a three-plane intersection. Explain what setting $d_3 = 0$ accomplishes in the general three-plane formula, and derive why the denominator $[\mathbf{n}_1, \mathbf{n}_2, \mathbf{v}]$ reduces to $\mathbf{v}^2$.
3. A line has infinitely many valid starting points, so $\mathbf{p}$ is not unique. Show that the $\mathbf{p}$ this formula returns always satisfies $\mathbf{v} \cdot \mathbf{p} = 0$, and explain why that makes it the point on the line closest to the origin. Why is a canonical choice preferable to an arbitrary one?
4. When $\mathbf{v}^2 = 0$ the planes are parallel, but this covers two distinct situations. Identify both, explain why comparing the normals alone cannot separate them, and state what an implementation must compare instead. What should it report in each case?

---
**Check Answer:** [S_09_Intersection_Two_Planes](../Solutions/S_09_Intersection_Two_Planes.md) | **Related Concepts:** [09_Intersection_Two_Planes](../../../Concepts/05_Geometry/09_Intersection_Two_Planes.md)
