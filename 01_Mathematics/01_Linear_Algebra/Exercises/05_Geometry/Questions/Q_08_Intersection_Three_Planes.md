---
topic: Geometry
difficulty: Hard
tags: [exercise, question, intersection-three-planes, implicit-plane, cross-product, determinants]
---
# Question
## Part 1: Calculation
1. Three axis-aligned planes are given by $\mathbf{f}_1 = [1, 0, 0, -2]$, $\mathbf{f}_2 = [0, 1, 0, -3]$ and $\mathbf{f}_3 = [0, 0, 1, -4]$:
   * Write the system in the form $\mathbf{A}\mathbf{p} = \mathbf{b}$, stating $\mathbf{A}$ and $\mathbf{b}$ explicitly.
   * Compute the scalar triple product $[\mathbf{n}_1, \mathbf{n}_2, \mathbf{n}_3]$ and confirm a unique intersection point exists.
   * Solve for $\mathbf{p}$ and verify by confirming $\mathbf{f}_i \cdot \mathbf{p} = 0$ for all three planes. Sanity-check the answer against what the three plane equations state directly.

2. Three general planes are given by $\mathbf{f}_1 = [1, 1, 0, -3]$, $\mathbf{f}_2 = [0, 1, 1, -5]$ and $\mathbf{f}_3 = [1, 0, 1, -4]$:
   * Compute the three cross products $\mathbf{n}_3 \times \mathbf{n}_2$, $\mathbf{n}_1 \times \mathbf{n}_3$ and $\mathbf{n}_2 \times \mathbf{n}_1$.
   * Compute the determinant $[\mathbf{n}_1, \mathbf{n}_2, \mathbf{n}_3]$.
   * Solve for the intersection point $\mathbf{p}$ and verify it satisfies all three planes.

3. Classify each of the following triples, computing $[\mathbf{n}_1, \mathbf{n}_2, \mathbf{n}_3]$ first and then determining whether there is no solution or infinitely many. Describe what each arrangement looks like geometrically:
   * $\mathbf{f}_1 = [1, 0, 0, 0]$, $\mathbf{f}_2 = [0, 1, 0, 0]$, $\mathbf{f}_3 = [1, 1, 0, 0]$
   * $\mathbf{f}_1 = [1, 0, 0, 0]$, $\mathbf{f}_2 = [0, 1, 0, 0]$, $\mathbf{f}_3 = [1, 1, 0, -1]$
   * $\mathbf{f}_1 = [1, 0, 0, -1]$, $\mathbf{f}_2 = [1, 0, 0, -3]$, $\mathbf{f}_3 = [0, 1, 0, 0]$

4. Take the planes from Question 2 and swap the order of the operands in every cross product of the solution formula — that is, compute $d_1(\mathbf{n}_2 \times \mathbf{n}_3) + d_2(\mathbf{n}_3 \times \mathbf{n}_1) + d_3(\mathbf{n}_1 \times \mathbf{n}_2)$ over the same determinant. What point results, and what does the relationship to the correct $\mathbf{p}$ demonstrate about why the reversal is required?

## Part 2: Conceptual Understanding
1. Explain why linear independence of $\mathbf{n}_1$, $\mathbf{n}_2$ and $\mathbf{n}_3$ is exactly the condition needed for a unique intersection point. Relate your answer to the [determinant](../../../Concepts/03_Matrices/03_Determinants.md) of $\mathbf{A}$ and to the [scalar triple product](../../../Concepts/02_Vectors/05_Scalar_Triple_Product.md) interpreted as a volume.
2. In the derivation, $\mathbf{b} = (-d_1, -d_2, -d_3)$ carries a minus sign on every component. Show how reversing the operand order of each cross product absorbs that sign, and state which algebraic property of the [cross product](../../../Concepts/02_Vectors/04_Cross_Product.md) makes this legal.
3. When $\det \mathbf{A} = 0$, the system has either no solution or infinitely many. Explain what distinguishes the two cases algebraically, and describe the geometric arrangement of the planes in each. Why is it insufficient to report only "the matrix is singular"?
4. The normals forming the rows of $\mathbf{A}$ are not required to be unit length for this calculation. Explain why, and contrast this with the [point-plane distance](../../../Concepts/05_Geometry/05_Distance_Point_and_Plane.md). What happens numerically as $[\mathbf{n}_1, \mathbf{n}_2, \mathbf{n}_3]$ approaches — but does not equal — zero, and what should a robust implementation do about it?

---
**Check Answer:** [S_08_Intersection_Three_Planes](../Solutions/S_08_Intersection_Three_Planes.md) | **Related Concepts:** [08_Intersection_Three_Planes](../../../Concepts/05_Geometry/08_Intersection_Three_Planes.md)
