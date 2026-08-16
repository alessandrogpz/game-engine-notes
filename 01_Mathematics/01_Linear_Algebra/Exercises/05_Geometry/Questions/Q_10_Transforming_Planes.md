---
topic: Geometry
difficulty: Hard
tags: [exercise, question, transforming-planes, implicit-plane, adjugate, determinants, normal-vector]
---
# Question
## Part 1: Calculation
1. The plane $\mathbf{f}^A = [0, 0, 1, -5]$ (the plane $z = 5$) is transformed by a **pure translation** $\mathbf{t} = \langle 1, 2, 3 \rangle$, so $\mathbf{M} = \mathbf{I}_3$:
   * State $\det(\mathbf{M})$ and $\operatorname{adj}(\mathbf{M})$.
   * Compute $\mathbf{n}^B$ and $d^B$ using $d^B = \det(\mathbf{M})(d^A - \mathbf{n}^A\mathbf{M}^{-1}\mathbf{t})$.
   * State $\mathbf{f}^B$ and describe the resulting plane. Sanity-check it by transforming any point of $z = 5$ directly through $\mathbf{H}$ and confirming it satisfies $\mathbf{f}^B$.

2. The same plane $\mathbf{f}^A = [0, 0, 1, -5]$ is transformed by a **uniform scale** $\mathbf{M} = 2\mathbf{I}_3$ with $\mathbf{t} = \mathbf{0}$:
   * Compute $\det(\mathbf{M})$, $\operatorname{adj}(\mathbf{M})$, $\mathbf{n}^B$ and $d^B$.
   * State $\mathbf{f}^B$, then normalize it so that $\|\mathbf{n}^B\| = 1$.
   * Which plane does the normalized result describe, and what does this demonstrate about the role of the $\det(\mathbf{M})$ factor?

3. The plane $\mathbf{f}^A = [0, 0, 1, -5]$ is transformed by $\mathbf{M} = \operatorname{diag}(1, 1, 2)$ together with $\mathbf{t} = \langle 0, 0, 1 \rangle$:
   * Compute $\mathbf{f}^B$ in full.
   * Verify your answer independently by transforming the point $(0, 0, 5)$ through $\mathbf{H}$ and confirming the image satisfies $\mathbf{f}^B$.

4. The plane $\mathbf{f}^A = [1, 0, 0, 0]$ (the $yz$-plane, $x = 0$) is transformed by the **shear** below, with $\mathbf{t} = \mathbf{0}$:

$$
\mathbf{M} = \begin{bmatrix} 1 & 1 & 0 \\\\ 0 & 1 & 0 \\\\ 0 & 0 & 1 \end{bmatrix}
$$

   * Compute $\operatorname{adj}(\mathbf{M})$ and use it to obtain $\mathbf{n}^B$ and $\mathbf{f}^B$.
   * Now compute the **naive** result $\mathbf{M}\mathbf{n}^A$, treating the normal as an ordinary column vector.
   * Transform two distinct points of the plane $x = 0$ through $\mathbf{M}$ and determine which of the two candidate planes they actually lie on. Explain what this proves.

5. The plane $\mathbf{f}^A = [1, 0, 0, -2]$ (the plane $x = 2$) is transformed by the reflection $\mathbf{M} = \operatorname{diag}(-1, 1, 1)$ with $\mathbf{t} = \mathbf{0}$:
   * Compute $\det(\mathbf{M})$, $\operatorname{adj}(\mathbf{M})$ and $\mathbf{f}^B$.
   * Which plane results, and is that geometrically correct?
   * Compare $\mathbf{f}^A\mathbf{H}^{-1}$ against $\mathbf{f}^A\operatorname{adj}(\mathbf{H})$. Do they describe the same plane? Do they agree on which side is the front?

## Part 2: Conceptual Understanding
1. Explain why a plane's normal transforms by $\operatorname{adj}(\mathbf{M})$ rather than by $\mathbf{M}$ itself. Relate the row-vector form $\mathbf{n}^B = \mathbf{n}^A\operatorname{adj}(\mathbf{M})$ to the inverse-transpose rule for [normal vectors](../../../Concepts/05_Geometry/02_Normal_Vectors.md), and state why the two are the same statement.
2. In the derivation of $d^B$, the term $-\mathbf{n}^A\operatorname{adj}(\mathbf{M}) \cdot \mathbf{M}\mathbf{q}^A$ collapses to $-\mathbf{n}^A\det(\mathbf{M})\mathbf{q}^A$. Identify the [adjugate](../../../Concepts/03_Matrices/04_Matrix_Inversion.md) identity responsible, and show how the remaining translation term produces $-\mathbf{n}^A\mathbf{M}^{-1}\mathbf{t}$ after $\det(\mathbf{M})$ is factored out.
3. Points transform as $\mathbf{q}^B = \mathbf{H}\mathbf{q}^A$ — a column vector multiplied from the left — whereas planes transform as $\mathbf{f}^B = \mathbf{f}^A\operatorname{adj}(\mathbf{H})$, a row vector multiplied from the right by a *different* matrix. Explain what this asymmetry says about what a plane fundamentally is, and why applying $\mathbf{H}$ directly to $\mathbf{f}^A$ gives the wrong answer.
4. Prove that $\det(\mathbf{H}) = \det(\mathbf{M})$ for a matrix of the form below, and explain why this is what allows the 4D result to be written purely in terms of $\operatorname{adj}(\mathbf{H})$.

$$
\mathbf{H} = \begin{bmatrix} \mathbf{M} & \mathbf{t} \\\\ \mathbf{0} & 1 \end{bmatrix}
$$

5. The determinant factor is usually ignored in practice. State the condition under which dropping it is harmless, and the condition under which it is not. Why can renormalizing the plane afterwards recover a discarded magnitude but never a discarded sign?

---
**Check Answer:** [S_10_Transforming_Planes](../Solutions/S_10_Transforming_Planes.md) | **Related Concepts:** [10_Transforming_Planes](../../../Concepts/05_Geometry/10_Transforming_Planes.md)
