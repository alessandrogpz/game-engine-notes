---
topic: Geometry
difficulty: Medium
tags: [exercise, question, reflection-plane, implicit-plane, normal-vector]
---
# Question
## Part 1: Calculation
1. A plane is defined by the non-normalized 4D vector $\mathbf{f} = [1, 2, 2, -6]$, and a point is given as $\mathbf{p} = (3, 3, 3)$:
   * Compute $\|\mathbf{n}\|$ and normalize the plane to obtain $\mathbf{f}_{\text{norm}} = [\hat{n} \mid d_{\text{norm}}]$.
   * Calculate the [[05_Distance_Point_and_Plane|signed perpendicular distance]] $\mathbf{f}_{\text{norm}} \cdot \mathbf{p}$.
   * Compute the closest point $\mathbf{q}$ lying in the plane using $\mathbf{q} = \mathbf{p} - (\mathbf{f} \cdot \mathbf{p})\hat{n}$, and verify your result by confirming that $\mathbf{f} \cdot \mathbf{q} = 0$.
   * Compute the reflected point $\mathbf{p}'$ using $\mathbf{p}' = \mathbf{p} - 2(\mathbf{f} \cdot \mathbf{p})\hat{n}$, then verify that $\mathbf{f}_{\text{norm}} \cdot \mathbf{p}'$ has the same magnitude as $\mathbf{f}_{\text{norm}} \cdot \mathbf{p}$ but the opposite sign.

2. Consider the axis-aligned plane $z = 2$:
   * Express the plane as a normalized 4D vector $\mathbf{f} = [\hat{n} \mid d]$.
   * Construct the full $4 \times 4$ matrix $\mathbf{H}_{\text{reflect}}(\mathbf{f})$ using $\mathbf{I}_4 - 2\mathbf{n} \otimes \mathbf{f}$.
   * Apply the matrix to the homogeneous point $\mathbf{p} = (3, 4, 5, 1)$ and confirm the result matches what $\mathbf{p}' = \mathbf{p} - 2(\mathbf{f} \cdot \mathbf{p})\mathbf{n}$ produces.

3. Using the normalized plane from Question 1 ($\hat{n} = \left(\frac{1}{3}, \frac{2}{3}, \frac{2}{3}\right)$, $d = -2$):
   * Build the complete $4 \times 4$ reflection matrix $\mathbf{H}_{\text{reflect}}(\mathbf{f})$.
   * Multiply it by $\mathbf{p} = (3, 3, 3, 1)$ and confirm it reproduces the $\mathbf{p}'$ you obtained in Question 1.

## Part 2: Conceptual Understanding
1. Explain geometrically why the vector separating $\mathbf{p}$ from its closest plane point $\mathbf{q}$ is exactly $(\mathbf{f} \cdot \mathbf{p})\mathbf{n}$, and why subtracting that same vector a **second** time lands precisely on the mirror image rather than merely somewhere behind the plane.
2. The derivation writes an arbitrary point as $\mathbf{p} = \mathbf{q} + t\mathbf{n}$ and concludes $\mathbf{f} \cdot \mathbf{p} = t$. Identify which two facts cause the terms $(\mathbf{n} \cdot \mathbf{q} + d)$ and $(\mathbf{n} \cdot \mathbf{n})$ to collapse, and state what $\mathbf{f} \cdot \mathbf{p}$ would evaluate to if $\mathbf{n}$ were **not** unit length. Why does a non-unit normal corrupt the reflection formula in **two** separate ways?
3. When building the $4 \times 4$ matrix, $\mathbf{n}$ is regarded as a 4D column vector with a $w$ coordinate of **zero**, while $\mathbf{p}$ carries $w = 1$. Explain why the normal must have $w = 0$, and what the bottom row $[0, 0, 0, 1]$ guarantees about the transformation.
4. Show that reflecting a point twice returns the original point ($\mathbf{H}_{\text{reflect}}^2 = \mathbf{I}_4$). What is $\det(\mathbf{H}_{\text{reflect}})$, and how does that value connect to the sign correction $\text{sign}(\det(\mathbf{M}))$ required when transforming [[02_Normal_Vectors|normal vectors]] through a reflection?

---
**Check Answer:** [[S_06_Reflection_Through_Plane]] | **Related Concepts:** [[06_Reflection_Through_Plane]]
