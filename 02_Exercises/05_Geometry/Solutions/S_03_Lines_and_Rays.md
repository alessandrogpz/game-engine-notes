---
topic: Geometry
tags: [exercise, solution, parametric-line, skew-lines, line-distance]
---

# Solution: Lines and Rays

This solution note provides the step-by-step calculations and conceptual explanations for the lines and rays exercise.

---

## Part 1: Calculation

### Question 1: Parametric Ray Evaluation & Unit Direction

Given ray $L(t) = P + t \mathbf{v}$, where $P = (1, 2, 3)$ and $\mathbf{v} = \langle 2, -1, 2 \rangle$:

#### 1. Point Coordinates at $t = 3$
Substitute $t = 3$ into the parametric equation:

$$
L(3) = (1, 2, 3) + 3 \langle 2, -1, 2 \rangle
$$

$$
L(3) = (1, 2, 3) + \langle 6, -3, 6 \rangle = (7, -1, 9)
$$

The point on the line corresponding to $t = 3$ is **$(7, -1, 9)$**.

#### 2. Unit Direction Vector $\hat{v}$
Calculate the magnitude of direction vector $\mathbf{v}$:

$$
\|\mathbf{v}\| = \sqrt{2^2 + (-1)^2 + 2^2} = \sqrt{4 + 1 + 4} = \sqrt{9} = 3
$$

Normalize $\mathbf{v}$ to get the unit direction vector $\hat{v}$:

$$
\hat{v} = \frac{\mathbf{v}}{\|\mathbf{v}\|} = \left\langle \frac{2}{3}, -\frac{1}{3}, \frac{2}{3} \right\rangle
$$

---

### Question 2: Point-to-Line Distance (Rejection vs. Parallelogram)

Given point $q = (4, 5, 6)$ and line $L(t) = P + t \mathbf{v}$ with $P = (1, 1, 1)$ and $\mathbf{v} = \langle 1, 0, 0 \rangle$:

#### 1. Displacement Vector $\mathbf{u}$

$$
\mathbf{u} = q - P = (4, 5, 6) - (1, 1, 1) = \langle 3, 4, 5 \rangle
$$

#### 2. Shortest Distance $d$ via Rejection Method
Compute the projection of $\mathbf{u}$ onto $\mathbf{v}$:

$$
\mathbf{u} \cdot \mathbf{v} = \langle 3, 4, 5 \rangle \cdot \langle 1, 0, 0 \rangle = 3
$$

$$
\|\mathbf{v}\|^2 = 1^2 + 0^2 + 0^2 = 1
$$

$$
\text{proj}_{\mathbf{v}}\mathbf{u} = \frac{\mathbf{u} \cdot \mathbf{v}}{\|\mathbf{v}\|^2} \mathbf{v} = 3 \langle 1, 0, 0 \rangle = \langle 3, 0, 0 \rangle
$$

Subtract projection from $\mathbf{u}$ to get the rejection vector $\text{rej}_{\mathbf{v}}\mathbf{u}$:

$$
\text{rej}_{\mathbf{v}}\mathbf{u} = \mathbf{u} - \text{proj}_{\mathbf{v}}\mathbf{u} = \langle 3, 4, 5 \rangle - \langle 3, 0, 0 \rangle = \langle 0, 4, 5 \rangle
$$

The distance $d$ is the magnitude of the rejection vector:

$$
d = \|\text{rej}_{\mathbf{v}}\mathbf{u}\| = \sqrt{0^2 + 4^2 + 5^2} = \sqrt{16 + 25} = \sqrt{41}
$$

#### 3. Shortest Distance $d$ via Parallelogram Area Method
Compute the [cross product](../../../01_Concepts/02_Vectors/04_Cross_Product.md) $\mathbf{u} \times \mathbf{v}$:

$$
\mathbf{u} \times \mathbf{v} = \langle 3, 4, 5 \rangle \times \langle 1, 0, 0 \rangle = \langle (4)(0) - (5)(0),\; (5)(1) - (3)(0),\; (3)(0) - (4)(1) \rangle = \langle 0, 5, -4 \rangle
$$

Compute the magnitude $\|\mathbf{u} \times \mathbf{v}\|$:

$$
\|\mathbf{u} \times \mathbf{v}\| = \sqrt{0^2 + 5^2 + (-4)^2} = \sqrt{25 + 16} = \sqrt{41}
$$

Using the area formula:

$$
d = \frac{\|\mathbf{u} \times \mathbf{v}\|}{\|\mathbf{v}\|} = \frac{\sqrt{41}}{1} = \sqrt{41}
$$

Both methods yield **$d = \sqrt{41}$** ($\approx 6.403$).

---

### Question 3: Orientation of Two 3D Lines

Given $\mathbf{v}_1 = \langle 1, 2, 0 \rangle$ and $\mathbf{v}_2 = \langle 2, 4, 0 \rangle$:

#### 1. Evaluating $(\mathbf{v}_1 \cdot \mathbf{v}_2)^2 - \mathbf{v}_1^2 \mathbf{v}_2^2$

$$
\mathbf{v}_1 \cdot \mathbf{v}_2 = \langle 1, 2, 0 \rangle \cdot \langle 2, 4, 0 \rangle = 1(2) + 2(4) + 0(0) = 10 \implies (\mathbf{v}_1 \cdot \mathbf{v}_2)^2 = 100
$$

$$
\mathbf{v}_1^2 = 1^2 + 2^2 + 0^2 = 5
$$

$$
\mathbf{v}_2^2 = 2^2 + 4^2 + 0^2 = 20
$$

$$
\mathbf{v}_1^2 \mathbf{v}_2^2 = (5)(20) = 100
$$

$$
(\mathbf{v}_1 \cdot \mathbf{v}_2)^2 - \mathbf{v}_1^2 \mathbf{v}_2^2 = 100 - 100 = 0
$$

#### 2. Relative Orientation
The result $0$ indicates that the two lines are **parallel** ($\mathbf{v}_2 = 2 \mathbf{v}_1$). Mathematically, by Lagrange's identity, $\|\mathbf{v}_1 \times \mathbf{v}_2\|^2 = \mathbf{v}_1^2 \mathbf{v}_2^2 - (\mathbf{v}_1 \cdot \mathbf{v}_2)^2 = 0$.

---

## Part 2: Conceptual Understanding

### 1. 2D vs. 3D Line Intersections (Skew Lines)

* **In 2D Space:** Any two non-parallel lines lie entirely within the same 2D plane. Because they span two independent directions in a 2D surface, they are mathematically guaranteed to cross at a single intersection point.
* **In 3D Space:** Lines have a 3rd dimension ($z$/depth). Two non-parallel lines can pass above or below each other at different depths along the $z$-axis without ever touching. Lines in 3D that are neither parallel nor intersecting are called **skew lines**.

---

### 2. Geometrically Why the Matrix Denominator Becomes 0 for Parallel Lines

When finding the parameters $t_1, t_2$ of closest approach between two 3D lines, we set up the requirement that the connecting vector $(L_2(t_2) - L_1(t_1))$ is perpendicular to both direction vectors:

$$
\begin{cases}
(L_2(t_2) - L_1(t_1)) \cdot \mathbf{v}_1 = 0 \\\\
(L_2(t_2) - L_1(t_1)) \cdot \mathbf{v}_2 = 0
\end{cases}
$$

Rearranging into a matrix system:

$$
\begin{bmatrix} \mathbf{v}_1^2 & -\mathbf{v}_1 \cdot \mathbf{v}_2 \\\\ \mathbf{v}_1 \cdot \mathbf{v}_2 & -\mathbf{v}_2^2 \end{bmatrix} \begin{bmatrix} t_1 \\\\ t_2 \end{bmatrix} = \begin{bmatrix} (P_2 - P_1) \cdot \mathbf{v}_1 \\\\ (P_2 - P_1) \cdot \mathbf{v}_2 \end{bmatrix}
$$

Inverting the matrix yields the [determinant](../../../01_Concepts/03_Matrices/03_Determinants.md) in the denominator:

$$
\begin{bmatrix} t_1 \\\\ t_2 \end{bmatrix} = \frac{1}{(\mathbf{v}_1 \cdot \mathbf{v}_2)^2 - \mathbf{v}_1^2 \mathbf{v}_2^2} \begin{bmatrix} -\mathbf{v}_2^2 & \mathbf{v}_1 \cdot \mathbf{v}_2 \\\\ -\mathbf{v}_1 \cdot \mathbf{v}_2 & \mathbf{v}_1^2 \end{bmatrix} \begin{bmatrix} (P_2 - P_1) \cdot \mathbf{v}_1 \\\\ (P_2 - P_1) \cdot \mathbf{v}_2 \end{bmatrix}
$$

When the lines are **parallel**, the denominator $(\mathbf{v}_1 \cdot \mathbf{v}_2)^2 - \mathbf{v}_1^2 \mathbf{v}_2^2$ becomes **$0$**. Geometrically, parallel lines remain at a constant distance everywhere, so there is no single unique point of closest approach—instead, there are infinitely many perpendicular connecting segments of equal length.

---

### 3. Performance Optimization in Graphics (Single `sqrt` Operation)

* The formula $d = \sqrt{\frac{(\mathbf{u} \times \mathbf{v})^2}{v^2}}$ contains only **one** square root operation (`sqrt`).
* The formula $d = \frac{\|\mathbf{u} \times \mathbf{v}\|}{\|\mathbf{v}\|}$ contains **two** separate square root operations (`sqrt`).

Because square root instructions are computationally heavy and slow on CPU/GPU hardware, keeping terms squared inside a single radical reduces the number of `sqrt` calls per frame, optimizing code performance.

---

**Back to Question:** [Q_03_Lines_and_Rays](../Questions/Q_03_Lines_and_Rays.md) | **Related Concepts:** [03_Lines_and_Rays](../../../01_Concepts/05_Geometry/03_Lines_and_Rays.md)
