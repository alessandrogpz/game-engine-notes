---
topic: Geometry
tags: [exercise, solution, reflection-plane, implicit-plane]
---

# Solution: Reflection Through a Plane

This solution note details the step-by-step calculations and conceptual answers for the reflection-through-a-plane exercise.

---

## Part 1: Calculation

### Question 1: Reflecting a Point Through a Non-Normalized Plane

A plane is defined by the non-normalized vector $\mathbf{f} = [1, 2, 2, -6]$, and a point is given by $\mathbf{p} = (3, 3, 3)$.

#### 1. Magnitude of the Normal and Normalization

$$
\|\mathbf{n}\| = \sqrt{\sum_{i=1}^{n} n_i^2} = \sqrt{1^2 + 2^2 + 2^2} = \sqrt{9} = 3
$$

Dividing all four components by $\|\mathbf{n}\|$:

$$
\mathbf{f}_{\text{norm}} = \frac{\mathbf{f}}{\|\mathbf{n}\|} = \frac{[1, 2, 2, -6]}{3} = \left[ \frac{1}{3}, \frac{2}{3}, \frac{2}{3}, -2 \right]
$$

#### 2. Signed Perpendicular Distance

$$
\mathbf{f}_{\text{norm}} \cdot \mathbf{p} = \hat{n} \cdot \mathbf{p} + d_{\text{norm}} = \frac{1}{3}(3) + \frac{2}{3}(3) + \frac{2}{3}(3) + (-2)
$$

$$
\mathbf{f}_{\text{norm}} \cdot \mathbf{p} = 1 + 2 + 2 - 2 = 3
$$

* **Conclusion:** $\mathbf{p}$ lies $3$ units in **front** of the plane.

#### 3. Closest Point $\mathbf{q}$ in the Plane

$$
\mathbf{q} = \mathbf{p} - (\mathbf{f} \cdot \mathbf{p})\hat{n} = (3, 3, 3) - 3\left( \frac{1}{3}, \frac{2}{3}, \frac{2}{3} \right)
$$

$$
\mathbf{q} = (3, 3, 3) - (1, 2, 2) = (2, 1, 1)
$$

Verifying that $\mathbf{q}$ lies on the plane by confirming $\mathbf{f} \cdot \mathbf{q} = 0$:

$$
\mathbf{f}_{\text{norm}} \cdot \mathbf{q} = \frac{1}{3}(2) + \frac{2}{3}(1) + \frac{2}{3}(1) - 2 = \frac{2}{3} + \frac{2}{3} + \frac{2}{3} - 2 = 2 - 2 = 0
$$

* **Conclusion:** $\mathbf{q} = (2, 1, 1)$ lies **on** the plane, as required.

#### 4. Reflected Point $\mathbf{p}'$

The displacement vector to subtract is $(\mathbf{f} \cdot \mathbf{p})\hat{n} = (1, 2, 2)$, so doubling it gives $2(\mathbf{f} \cdot \mathbf{p})\hat{n} = (2, 4, 4)$:

$$
\mathbf{p}' = \mathbf{p} - 2(\mathbf{f} \cdot \mathbf{p})\hat{n} = (3, 3, 3) - (2, 4, 4) = (1, -1, -1)
$$

Verifying the signed distance of the reflected point:

$$
\mathbf{f}_{\text{norm}} \cdot \mathbf{p}' = \frac{1}{3}(1) + \frac{2}{3}(-1) + \frac{2}{3}(-1) - 2 = \frac{1}{3} - \frac{2}{3} - \frac{2}{3} - 2 = -1 - 2 = -3
$$

* **Conclusion:** $\mathbf{f}_{\text{norm}} \cdot \mathbf{p}' = -3$ against $\mathbf{f}_{\text{norm}} \cdot \mathbf{p} = 3$ — the same magnitude with the opposite sign, confirming $\mathbf{p}'$ sits the same distance away but **behind** the plane.

---

### Question 2: The Axis-Aligned Plane $z = 2$

#### 1. Expressing the Plane as a Normalized 4D Vector

A plane is the set of points satisfying $\mathbf{n} \cdot \mathbf{x} + d = 0$. Writing $z = 2$ in that form:

$$
0x + 0y + 1z - 2 = 0
$$

This gives $\mathbf{n} = (0, 0, 1)$ and $d = -2$. The normal is already unit length ($\|\mathbf{n}\| = 1$), so no scaling is needed:

$$
\mathbf{f}_{\text{norm}} = [\hat{n} \mid d_{\text{norm}}] = [0, 0, 1, -2]
$$

#### 2. Constructing $\mathbf{H}_{\text{reflect}}(\mathbf{f})$

Treating $\mathbf{n}$ as a 4D column vector with $w = 0$, so $\mathbf{n} = (0, 0, 1, 0)$:

$$
\mathbf{n} \otimes \mathbf{f} = \mathbf{n}\mathbf{f}^T = \begin{bmatrix} 0 & 0 & 0 & 0 \\\\ 0 & 0 & 0 & 0 \\\\ 0 & 0 & 1 & -2 \\\\ 0 & 0 & 0 & 0 \end{bmatrix}
$$

$$
\mathbf{H}_{\text{reflect}}(\mathbf{f}) = \mathbf{I}_4 - 2(\mathbf{n} \otimes \mathbf{f}) = \begin{bmatrix} 1 & 0 & 0 & 0 \\\\ 0 & 1 & 0 & 0 \\\\ 0 & 0 & -1 & 4 \\\\ 0 & 0 & 0 & 1 \end{bmatrix}
$$

Only the $z$ row is affected, which is exactly what a reflection through a plane of constant $z$ should do.

#### 3. Applying the Matrix to $\mathbf{p} = (3, 4, 5, 1)$

$$
\mathbf{H}_{\text{reflect}}(\mathbf{f})\,\mathbf{p} = \begin{bmatrix} 1 & 0 & 0 & 0 \\\\ 0 & 1 & 0 & 0 \\\\ 0 & 0 & -1 & 4 \\\\ 0 & 0 & 0 & 1 \end{bmatrix} \begin{bmatrix} 3 \\\\ 4 \\\\ 5 \\\\ 1 \end{bmatrix} = \begin{bmatrix} 3 \\\\ 4 \\\\ -5 + 4 \\\\ 1 \end{bmatrix} = \begin{bmatrix} 3 \\\\ 4 \\\\ -1 \\\\ 1 \end{bmatrix}
$$

Cross-checking against the direct vector formula, where $\mathbf{f} \cdot \mathbf{p} = 0 + 0 + 5 - 2 = 3$:

$$
\mathbf{p}' = \mathbf{p} - 2(\mathbf{f} \cdot \mathbf{p})\mathbf{n} = (3, 4, 5) - 6(0, 0, 1) = (3, 4, -1)
$$

* **Conclusion:** Both routes agree on $\mathbf{p}' = (3, 4, -1)$. The point sat $3$ units above $z = 2$, and its reflection sits $3$ units below it.

---

### Question 3: Building the Full Matrix for the Question 1 Plane

Using the normalized plane from Question 1, where $\hat{n} = \left( \frac{1}{3}, \frac{2}{3}, \frac{2}{3} \right)$ and $d = -2$:

$$
\mathbf{f} = \left( \frac{1}{3}, \frac{2}{3}, \frac{2}{3}, -2 \right), \qquad \mathbf{n} = \left( \frac{1}{3}, \frac{2}{3}, \frac{2}{3}, 0 \right)
$$

#### 1. The Outer Product $\mathbf{n} \otimes \mathbf{f}$

$$
\mathbf{n} \otimes \mathbf{f} = \mathbf{n}\mathbf{f}^T = \begin{bmatrix} \frac{1}{9} & \frac{2}{9} & \frac{2}{9} & -\frac{2}{3} \\\\ \frac{2}{9} & \frac{4}{9} & \frac{4}{9} & -\frac{4}{3} \\\\ \frac{2}{9} & \frac{4}{9} & \frac{4}{9} & -\frac{4}{3} \\\\ 0 & 0 & 0 & 0 \end{bmatrix}
$$

Doubling it:

$$
2(\mathbf{n} \otimes \mathbf{f}) = \begin{bmatrix} \frac{2}{9} & \frac{4}{9} & \frac{4}{9} & -\frac{4}{3} \\\\ \frac{4}{9} & \frac{8}{9} & \frac{8}{9} & -\frac{8}{3} \\\\ \frac{4}{9} & \frac{8}{9} & \frac{8}{9} & -\frac{8}{3} \\\\ 0 & 0 & 0 & 0 \end{bmatrix}
$$

#### 2. The Reflection Matrix

$$
\mathbf{H}_{\text{reflect}}(\mathbf{f}) = \mathbf{I}_4 - 2(\mathbf{n} \otimes \mathbf{f}) = \begin{bmatrix} \frac{7}{9} & -\frac{4}{9} & -\frac{4}{9} & \frac{4}{3} \\\\ -\frac{4}{9} & \frac{1}{9} & -\frac{8}{9} & \frac{8}{3} \\\\ -\frac{4}{9} & -\frac{8}{9} & \frac{1}{9} & \frac{8}{3} \\\\ 0 & 0 & 0 & 1 \end{bmatrix}
$$

#### 3. Multiplying by $\mathbf{p} = (3, 3, 3, 1)$

$$
\mathbf{H}_{\text{reflect}}(\mathbf{f})\,\mathbf{p} = \begin{bmatrix} \frac{21}{9} - \frac{12}{9} - \frac{12}{9} + \frac{12}{9} \\\\ -\frac{12}{9} + \frac{3}{9} - \frac{24}{9} + \frac{24}{9} \\\\ -\frac{12}{9} - \frac{24}{9} + \frac{3}{9} + \frac{24}{9} \\\\ 0 + 0 + 0 + 1 \end{bmatrix} = \begin{bmatrix} \frac{9}{9} \\\\ -\frac{9}{9} \\\\ -\frac{9}{9} \\\\ 1 \end{bmatrix} = \begin{bmatrix} 1 \\\\ -1 \\\\ -1 \\\\ 1 \end{bmatrix}
$$

* **Conclusion:** The matrix yields $\mathbf{p}' = (1, -1, -1)$, the same result calculated directly in Question 1. The matrix form packages the translation term $d$ into the fourth column, which is why it reproduces the vector formula without needing $\mathbf{f} \cdot \mathbf{p}$ to be computed separately.

---

## Part 2: Conceptual Understanding

### 1. Why the Separating Vector is $(\mathbf{f} \cdot \mathbf{p})\mathbf{n}$, and Why Doubling It Mirrors

$\mathbf{f} \cdot \mathbf{p}$ is the perpendicular distance between the plane $\mathbf{f}$ and the point $\mathbf{p}$ — but this holds **only if $\mathbf{f}$ is normalized**. That scalar carries the *how far*, but no direction.

Multiplying it by the plane normal $\mathbf{n}$ attaches the direction, producing a vector that runs from $\mathbf{q}$ to $\mathbf{p}$. Because $\mathbf{n}$ is perpendicular to the plane, this displacement has **no component lying within the plane** — it is pure perpendicular travel. That is precisely why subtracting it lands on the *closest* point rather than some arbitrary point of the plane: any other path to the plane would carry a sideways component and therefore be longer (it would be the hypotenuse of a right triangle whose leg is $(\mathbf{f} \cdot \mathbf{p})\mathbf{n}$).

So $\mathbf{p} - (\mathbf{f} \cdot \mathbf{p})\mathbf{n}$ is $\mathbf{q}$. Since $\mathbf{p}'$ and $\mathbf{p}$ have the same **unsigned** distance to the plane and lie along that same perpendicular line, we double $(\mathbf{f} \cdot \mathbf{p})\mathbf{n}$ and arrive at $\mathbf{p}'$: the first subtraction spends the distance getting to the plane, and the second spends an identical distance continuing beyond it.

---

### 2. Which Terms Collapse, and What a Non-Unit Normal Breaks

Writing $\mathbf{p} = \mathbf{q} + t\mathbf{n}$ simply means that the point $\mathbf{p}$ is the point $\mathbf{q}$ (which lies on the plane) after traveling a distance $t$ along the normal vector.

Substituting that into $\mathbf{f} \cdot \mathbf{p} = \mathbf{n} \cdot \mathbf{p} + d$:

$$
\mathbf{f} \cdot \mathbf{p} = \mathbf{n} \cdot (\mathbf{q} + t\mathbf{n}) + d
$$

$$
\mathbf{f} \cdot \mathbf{p} = (\mathbf{n} \cdot \mathbf{q} + d) + t(\mathbf{n} \cdot \mathbf{n})
$$

$$
\mathbf{f} \cdot \mathbf{p} = 0 + t \cdot 1 = t
$$

The **two facts** causing the collapse are:

* $\mathbf{n} \cdot \mathbf{q} + d = 0$, because $\mathbf{q}$ is on the plane and therefore satisfies the plane equation by definition.
* $\mathbf{n} \cdot \mathbf{n} = 1$, because $\mathbf{n}$ is of unit length.

Therefore $\mathbf{f} \cdot \mathbf{p}$ is the signed distance from the plane to $\mathbf{p}$.

#### Why a Non-Unit Normal Corrupts the Formula Twice

If $\mathbf{n}$ is not unit length, then $\mathbf{n} \cdot \mathbf{n} = \|\mathbf{n}\|^2$ rather than $1$, and the derivation instead terminates at:

$$
\mathbf{f} \cdot \mathbf{p} = t\|\mathbf{n}\|^2
$$

The corruption then enters $\mathbf{p}' = \mathbf{p} - 2(\mathbf{f} \cdot \mathbf{p})\mathbf{n}$ at **two separate points**:

1. **Inside the dot product:** $\mathbf{f} \cdot \mathbf{p}$ returns the distance already scaled by $\|\mathbf{n}\|^2$ instead of the true distance.
2. **In the multiplication outside:** that scalar is then multiplied by $\mathbf{n}$, whose own length is $\|\mathbf{n}\|$ rather than $1$, contributing yet another factor.

The resulting displacement vector has magnitude $t\|\mathbf{n}\|^3$, when the correct displacement $\mathbf{p} - \mathbf{q} = t\mathbf{n}$ has magnitude $t\|\mathbf{n}\|$ — an overshoot by a factor of $\|\mathbf{n}\|^2$. The reflected point flies far past its true mirror position along the correct line. Recovering the formula requires dividing by $\|\mathbf{n}\|^2$:

$$
\mathbf{p}' = \mathbf{p} - \frac{2(\mathbf{f} \cdot \mathbf{p})}{\|\mathbf{n}\|^2}\mathbf{n}
$$

---

### 3. Why the Normal Needs $w = 0$ and What the Bottom Row Guarantees

$\mathbf{n}$ is a **vector** — it is a direction, so it must have $w = 0$. $\mathbf{p}$, by contrast, is a **position**, which has $w = 1$.

Setting $w = 0$ makes the normal ignore the matrix's translation column entirely, so moving the origin does not move the vector. A direction is defined only by its orientation and magnitude, not by where it sits in space; translating a direction must leave it unchanged, and the $w = 0$ component is what enforces that. See [[07_Homogeneous_Coordinates|Homogeneous Coordinates]].

The bottom row $[0, 0, 0, 1]$ guarantees that the transformation is **affine**: it keeps points as points and directions as directions ($w = 1$ stays $1$, and $w = 0$ stays $0$). It never introduces a perspective divide, so no amount of reflecting will convert a position into a direction or vice versa.

This also explains the zero bottom row of the outer product $\mathbf{n} \otimes \mathbf{f}$ in Questions 2 and 3: because $\mathbf{n}$ has $w = 0$, its last row is entirely zero, leaving $\mathbf{I}_4$'s bottom row $[0, 0, 0, 1]$ untouched by the subtraction.

---

### 4. Reflecting Twice, the Determinant, and the Normal Sign Correction

#### Reflecting Twice Returns the Original Point

Reflecting $\mathbf{p}'$ a second time gives $\mathbf{p}'' = \mathbf{p}' - 2(\mathbf{f} \cdot \mathbf{p}')\mathbf{n}$. From Question 1 we know $\mathbf{f} \cdot \mathbf{p}' = -(\mathbf{f} \cdot \mathbf{p})$, so:

$$
\mathbf{p}'' = \mathbf{p}' + 2(\mathbf{f} \cdot \mathbf{p})\mathbf{n} = \left[ \mathbf{p} - 2(\mathbf{f} \cdot \mathbf{p})\mathbf{n} \right] + 2(\mathbf{f} \cdot \mathbf{p})\mathbf{n} = \mathbf{p}
$$

The same result follows algebraically from the matrix. Expanding $\mathbf{H}_{\text{reflect}}^2$ with $\mathbf{H}_{\text{reflect}} = \mathbf{I}_4 - 2\mathbf{n}\mathbf{f}^T$:

$$
\mathbf{H}_{\text{reflect}}^2 = \mathbf{I}_4 - 4\mathbf{n}\mathbf{f}^T + 4\mathbf{n}(\mathbf{f}^T\mathbf{n})\mathbf{f}^T
$$

The inner scalar $\mathbf{f}^T\mathbf{n}$ is $\mathbf{f} \cdot \mathbf{n} = \mathbf{n} \cdot \mathbf{n} + d(0) = 1$, since $\mathbf{n}$ carries $w = 0$ and so never picks up $d$. The last two terms cancel exactly:

$$
\mathbf{H}_{\text{reflect}}^2 = \mathbf{I}_4 - 4\mathbf{n}\mathbf{f}^T + 4\mathbf{n}\mathbf{f}^T = \mathbf{I}_4
$$

A reflection is therefore an **involution**: it is its own inverse, $\mathbf{H}_{\text{reflect}}^{-1} = \mathbf{H}_{\text{reflect}}$.

#### The Determinant

The upper-left $3 \times 3$ block $\mathbf{I}_3 - 2\hat{n}\hat{n}^T$ negates the single direction along $\hat{n}$ while leaving the two directions spanning the plane untouched — eigenvalues $-1, +1, +1$. Since the matrix is block-triangular with a bottom row of $[0, 0, 0, 1]$:

$$
\det(\mathbf{H}_{\text{reflect}}) = (-1)(+1)(+1)(1) = -1
$$

Both matrices built in Part 1 confirm this. A negative determinant means the transformation is **orientation-reversing**: it flips handedness, turning a right-handed basis into a left-handed one. The magnitude of $1$ confirms that no volume is lost or gained — a reflection only mirrors.

#### Connection to Transforming Normal Vectors

This is exactly the case flagged in [[02_Normal_Vectors|Normal Vectors]]. Normals transform by the inverse transpose, $(\mathbf{M}^{-1})^T$, which preserves orthogonality to the surface but not the *direction along* that perpendicular line. Under an orientation-reversing transformation, every face of the object is mirrored, and the inverse transpose alone leaves the resulting normal pointing **inward** instead of outward.

Because $\det(\mathbf{H}_{\text{reflect}}) = -1 < 0$, the sign correction is what restores the outward direction:

$$
\mathbf{n}_B = \text{sign}(\det(\mathbf{M}))(\mathbf{M}^{-1})^T\mathbf{n}_A = -(\mathbf{M}^{-1})^T\mathbf{n}_A
$$

For a pure reflection this simplifies further: since $\mathbf{H}_{\text{reflect}}$ is its own inverse and its $3 \times 3$ block is symmetric, $(\mathbf{M}^{-1})^T$ is just that block again, so the transformed normal reduces to $-\mathbf{H}_{\text{reflect}}\mathbf{n}_A$.

> [!IMPORTANT]
> **Practical consequence in engines:** because reflection flips handedness, the **winding order** of every reflected triangle reverses (a counter-clockwise triangle becomes clockwise when viewed from the same side). Rendering a mirrored object therefore requires flipping the backface-culling winding order alongside the sign correction on normals — otherwise the mirrored geometry disappears or lights incorrectly.

---

**Back to Question:** [[Q_06_Reflection_Through_Plane]] | **Related Concepts:** [[06_Reflection_Through_Plane]]
