# Transforming Planes

Let $\mathbf{f}^A = [\mathbf{n}^A \mid d^A]$ be a [plane](04_Planes.md) that contains the point $\mathbf{q}^A$ in coordinate system $A$, and let $\mathbf{H}$ be a $4 \times 4$ matrix having the form:

$$
\mathbf{H} = \begin{bmatrix} \mathbf{M} & \mathbf{t} \\\\ \mathbf{0} & 1 \end{bmatrix}
$$

where $\mathbf{M}$ is a $3 \times 3$ matrix and $\mathbf{t}$ is a 3D translation, that performs an [affine transformation](../04_Transforms/08_Matrix_Composition_4x4.md) from coordinate system $A$ to coordinate system $B$.

We need to find a way to transform $\mathbf{f}^A$ into $\mathbf{f}^B$. We already know that the [normal vector](02_Normal_Vectors.md) must transform as:

$$
\mathbf{n}^B = \mathbf{n}^A \operatorname{adj}(\mathbf{M})
$$

so we only need to know what to do with $d^A$ to transform it into $d^B$.

> [!NOTE]
> $\operatorname{adj}(\mathbf{M})$ is the **adjugate**, related to the [inverse](../03_Matrices/04_Matrix_Inversion.md) by $\operatorname{adj}(\mathbf{M}) = \det(\mathbf{M})\mathbf{M}^{-1}$. Normals are written here as **row vectors multiplied from the left**, which is the same rule as the inverse-transpose form $(\mathbf{M}^{-1})^T\mathbf{n}$ used for column vectors — only the convention differs.

---

## Deriving $d^B$

Because the original plane contains $\mathbf{q}^A$, we know that:

$$
d^A = -\mathbf{n}^A \cdot \mathbf{q}^A
$$

and for the transformed plane we must likewise have $d^B = -\mathbf{n}^B \cdot \mathbf{q}^B$, where the point itself transforms as $\mathbf{q}^B = \mathbf{H}\mathbf{q}^A$.

Substituting each of these in turn:

$$
d^B = -\left( \mathbf{n}^A \operatorname{adj}(\mathbf{M}) \right) \cdot \mathbf{q}^B
$$

$$
d^B = -\mathbf{n}^A \operatorname{adj}(\mathbf{M}) \cdot \mathbf{H}\mathbf{q}^A
$$

Expanding $\mathbf{H}\mathbf{q}^A$ into its rotation-scale and translation parts:

$$
d^B = -\mathbf{n}^A \operatorname{adj}(\mathbf{M}) \cdot \left( \mathbf{M}\mathbf{q}^A + \mathbf{t} \right)
$$

$$
d^B = -\mathbf{n}^A \det(\mathbf{M})\mathbf{q}^A - \mathbf{n}^A \operatorname{adj}(\mathbf{M})\mathbf{t}
$$

$$
d^B = \det(\mathbf{M})\left( d^A - \mathbf{n}^A \mathbf{M}^{-1}\mathbf{t} \right)
$$

The first term collapses because the adjugate satisfies $\operatorname{adj}(\mathbf{M})\mathbf{M} = \det(\mathbf{M})\mathbf{I}$, and the second because $\operatorname{adj}(\mathbf{M}) = \det(\mathbf{M})\mathbf{M}^{-1}$ lets $\det(\mathbf{M})$ be factored out of both terms. Recognising $-\mathbf{n}^A \cdot \mathbf{q}^A$ as $d^A$ completes it.

Except for the extra factor of $\det(\mathbf{M})$, this is exactly the value produced by multiplying the plane $\mathbf{f}^A$ by the **fourth column of $\mathbf{H}^{-1}$**. That inverse has the form:

$$
\mathbf{H}^{-1} = \begin{bmatrix} \mathbf{M}^{-1} & -\mathbf{M}^{-1}\mathbf{t} \\\\ \mathbf{0} & 1 \end{bmatrix}
$$

so multiplying the row vector $[\mathbf{n}^A \mid d^A]$ by that fourth column gives precisely $d^A - \mathbf{n}^A\mathbf{M}^{-1}\mathbf{t}$.

---

## The Complete Transformation

Using the fact that $\det(\mathbf{H}) = \det(\mathbf{M})$ — which holds due to the specific form of $\mathbf{H}$, whose bottom row is $[0, 0, 0, 1]$ — we come to the conclusion that the plane is transformed as:

$$
\mathbf{f}^B = \mathbf{f}^A \det(\mathbf{H})\mathbf{H}^{-1} = \mathbf{f}^A \operatorname{adj}(\mathbf{H})
$$

> [!IMPORTANT]
> Note the **side** of the multiplication. A point is a column vector transformed from the left, $\mathbf{q}^B = \mathbf{H}\mathbf{q}^A$, while a plane is a **row vector transformed from the right** by a different matrix entirely. Planes are not objects that live in space the way points do — they are linear functionals *measuring* space, and that dual nature is exactly why they transform by $\operatorname{adj}(\mathbf{H})$ on the opposite side rather than by $\mathbf{H}$.

---

## The 4D Analog of Normal Vector Transformation

This is the 4D analog of:

$$
\mathbf{n}^B = \mathbf{n}^A \det(\mathbf{M})\mathbf{M}^{-1} = \mathbf{n}^A \operatorname{adj}(\mathbf{M})
$$

for [transforming normal vectors](02_Normal_Vectors.md). The structure is identical, one dimension up: where a normal uses the $3 \times 3$ part alone, a plane uses the full $4 \times 4$ matrix, and the fourth component $d$ automatically picks up the translation that the normal correctly ignores.

---

## Ignoring the Determinant

As with normal vectors, the determinant is usually ignored, because planes are typically normalized so that $(f_x, f_y, f_z)$ are unit vectors. Any uniform factor applied to all four components describes the same plane, so a renormalization afterwards discards $\det(\mathbf{H})$ entirely and the cheaper $\mathbf{f}^A\mathbf{H}^{-1}$ suffices.

> [!WARNING]
> The determinant can only be dropped when its **sign** is positive. If $\det(\mathbf{H}) < 0$ the transformation is orientation-reversing — a [reflection](../04_Transforms/03_Reflections.md) — and discarding the factor leaves the normal pointing the wrong way through the surface. This is the same sign correction flagged for [normal vectors](02_Normal_Vectors.md), and normalizing by $\|\mathbf{n}\|$ cannot recover it, since a magnitude is always positive.

---

## Code Implementation

* **C++ Source Code:** [Transforming_Planes.cppm](../../03_Code/05_Geometry/Transforming_Planes.cppm)
