---
topic: Geometry
difficulty: Medium
tags: [exercise, question, intersection-line-plane, implicit-plane, parametric-line, ray-casting]
---
# Question
## Part 1: Calculation
1. A plane is given by the normalized vector $\mathbf{f} = [0, 0, 1, -5]$, and a line by $L(t) = \mathbf{p} + t\mathbf{v}$ with $\mathbf{p} = (1, 2, 1)$ and $\mathbf{v} = \langle 1, 1, 2 \rangle$:
   * Evaluate $\mathbf{f} \cdot \mathbf{p}$ and $\mathbf{f} \cdot \mathbf{v}$, stating for each whether it is a 4D or an effectively 3D calculation, and confirm the line is not parallel to the plane.
   * Solve for the parameter $t$ at the intersection.
   * Compute the intersection point $\mathbf{q}$ and verify your result by confirming $\mathbf{f} \cdot \mathbf{q} = 0$.

2. A **non-normalized** plane is given by $\mathbf{f} = [2, -1, 2, -12]$, with a line defined by $\mathbf{p} = (1, 1, 1)$ and $\mathbf{v} = \langle 1, 0, 1 \rangle$:
   * Compute $t$ and the intersection point $\mathbf{q}$ directly, without normalizing the plane. Verify that $\mathbf{f} \cdot \mathbf{q} = 0$.
   * Now normalize the plane to $\mathbf{f}_{\text{norm}}$ (recall $\|\mathbf{n}\| = 3$) and recompute $t$ from the normalized values.
   * Compare the two values of $t$. What does the result tell you about whether normalization is required for this calculation, and how does that contrast with computing a point-plane distance?

3. Using the plane $\mathbf{f} = [0, 0, 1, -5]$ from Question 1, classify each of the following lines and explain what happens geometrically in each case:
   * $\mathbf{p} = (0, 0, 2)$, $\mathbf{v} = \langle 1, 1, 0 \rangle$
   * $\mathbf{p} = (0, 0, 5)$, $\mathbf{v} = \langle 1, 1, 0 \rangle$

4. A **ray** starts at $\mathbf{p} = (0, 0, 8)$ against the plane $\mathbf{f} = [0, 0, 1, -5]$:
   * For the direction $\mathbf{v} = \langle 0, 0, 1 \rangle$, compute $\mathbf{f} \cdot \mathbf{p}$, $\mathbf{f} \cdot \mathbf{v}$, and $t$. Does the ray hit the plane? Does the infinite line?
   * Repeat for the direction $\mathbf{v} = \langle 0, 0, -1 \rangle$ and compute the intersection point where one exists.
   * State which sign conditions on $\mathbf{f} \cdot \mathbf{p}$ and $\mathbf{f} \cdot \mathbf{v}$ your two results confirm.

## Part 2: Conceptual Understanding
1. In the expression $t = -\frac{\mathbf{f} \cdot \mathbf{p}}{\mathbf{f} \cdot \mathbf{v}}$, explain why $\mathbf{f} \cdot \mathbf{p}$ is a genuine 4D [dot product](../../../Concepts/02_Vectors/02_Dot_Product.md) while $\mathbf{f} \cdot \mathbf{v}$ collapses to the 3D product $\mathbf{n} \cdot \mathbf{v}$. What role does the $w$ coordinate play in producing that difference?
2. Prove that scaling the plane vector $\mathbf{f}$ by any non-zero factor $s$ leaves $t$ unchanged. Why does the [point-plane distance](../../../Concepts/05_Geometry/05_Distance_Point_and_Plane.md) calculation *not* share this property?
3. The denominator vanishing ($\mathbf{f} \cdot \mathbf{v} = 0$) covers two geometrically distinct situations. Identify both, explain how the value of $\mathbf{f} \cdot \mathbf{p}$ separates them, and describe how a robust implementation should report each case.
4. In ray casting, a hit is accepted only when $t \ge 0$, and a ray starting in front of the plane additionally requires $\mathbf{f} \cdot \mathbf{v} < 0$. Explain what each condition rejects geometrically, why the second is equivalent to a backface cull, and why testing signs before dividing is preferable in an engine implementation.

---
**Check Answer:** [S_07_Intersection_Line_and_Plane](../Solutions/S_07_Intersection_Line_and_Plane.md) | **Related Concepts:** [07_Intersection_Line_and_Plane](../../../Concepts/05_Geometry/07_Intersection_Line_and_Plane.md)
