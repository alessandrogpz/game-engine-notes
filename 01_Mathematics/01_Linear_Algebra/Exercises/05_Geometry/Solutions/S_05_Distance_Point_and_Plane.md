---
topic: Geometry
tags: [exercise, solution, distance-point-plane, implicit-plane]
---

# Solution: Distance Between a Point and a Plane

This solution note details the step-by-step calculations and conceptual answers for the point-plane distance exercise.

---

## Part 1: Calculation

### Question 1: Normalizing a Plane & Signed Distance

A plane is defined by the non-normalized 4D vector $\mathbf{f} = [2, -1, 2, -12]$:

#### 1. Magnitude of the Normal Vector $\|\mathbf{n}\|$

$$
\|\mathbf{n}\| = \sqrt{\sum_{i=1}^{n} n_i^2} = \sqrt{2^2 + (-1)^2 + 2^2} = \sqrt{9} = 3
$$

#### 2. Normalizing the Plane Vector

Multiply all 4 components of $\mathbf{f} = [\mathbf{n} \mid d]$ by $\frac{1}{\|\mathbf{n}\|}$ to obtain $\mathbf{f}_{\text{norm}} = [\hat{n} \mid d_{\text{norm}}]$:

$$
\mathbf{f}_{\text{norm}} = \left[ \frac{2}{3}, -\frac{1}{3}, \frac{2}{3}, -\frac{12}{3} \right] \implies \mathbf{f}_{\text{norm}} = \left[ \frac{2}{3}, -\frac{1}{3}, \frac{2}{3}, -4 \right]
$$

#### 3. Signed Perpendicular Distance from $\mathbf{p} = (3, 4, 1)$

Classification by sign:

* $\mathbf{f}_{\text{norm}} \cdot \mathbf{p} = 0 \implies \mathbf{p}$ lies **on** the plane.
* $\mathbf{f}_{\text{norm}} \cdot \mathbf{p} < 0 \implies \mathbf{p}$ lies **behind** the plane.
* $\mathbf{f}_{\text{norm}} \cdot \mathbf{p} > 0 \implies \mathbf{p}$ lies in **front** of the plane.

Convert $\mathbf{p}$ to 4D [homogeneous coordinates](../../../Concepts/04_Transforms/07_Homogeneous_Coordinates.md) ($[3, 4, 1, 1]$) and evaluate the 4D [dot product](../../../Concepts/02_Vectors/02_Dot_Product.md):

$$
\mathbf{f}_{\text{norm}} \cdot \mathbf{p} = \left[ \frac{2}{3}, -\frac{1}{3}, \frac{2}{3}, -4 \right] \cdot [3, 4, 1, 1]
$$

$$
\mathbf{f}_{\text{norm}} \cdot \mathbf{p} = 2 - \frac{4}{3} + \frac{2}{3} - 4 = -2 - \frac{2}{3} = -\frac{6}{3} - \frac{2}{3} = -\frac{8}{3} = -2\frac{2}{3}
$$

* **Conclusion:** Since $\mathbf{f}_{\text{norm}} \cdot \mathbf{p} < 0$, the point $\mathbf{p}$ lies **behind** the plane.

---

### Question 2: Signed Distances from an Already-Normalized Plane

A normalized plane is given by $\mathbf{f} = \left[ 0, \frac{3}{5}, \frac{4}{5}, -10 \right]$:

#### 1. Signed Perpendicular Distance $D_1$ from $\mathbf{p}_1 = (1, 10, 5)$

$$
\mathbf{f}_{\text{norm}} \cdot \mathbf{p}_1 = \mathbf{n} \cdot \mathbf{p}_1 + d = 0(1) + 10\left(\frac{3}{5}\right) + 5\left(\frac{4}{5}\right) + (-10)
$$

$$
\mathbf{f}_{\text{norm}} \cdot \mathbf{p}_1 = 6 + 4 - 10 = 0
$$

* **Conclusion:** $D_1 = 0$, so $\mathbf{p}_1$ lies **on** the plane.

#### 2. Signed Perpendicular Distance $D_0$ from the Origin $\mathcal{O} = (0, 0, 0)$

$$
\mathbf{f}_{\text{norm}} \cdot \mathcal{O} = \mathbf{n} \cdot \mathcal{O} + d = 0(0) + 0\left(\frac{3}{5}\right) + 0\left(\frac{4}{5}\right) - 10 = -10
$$

* **Conclusion:** $D_0 = -10$, so the origin $\mathcal{O}$ lies $10$ units **behind** the plane.

---

## Part 2: Conceptual Understanding

### 1. Why the Plane Vector Must be Normalized

If the plane is **not** normalized, $\mathbf{f} \cdot \mathbf{p}$ yields the true signed perpendicular distance scaled by the magnitude of the [normal vector](../../../Concepts/05_Geometry/02_Normal_Vectors.md):

$$
\mathbf{f} \cdot \mathbf{p} = \text{Distance} \times \|\mathbf{n}\|
$$

Normalization is therefore necessary because it makes the projection produced by $\mathbf{f} \cdot \mathbf{p}$ translate perfectly into standard world units.

---

### 2. Why $\mathbf{f} \cdot \mathbf{p}$ is the Difference of Two Projections

Since $d = -\mathbf{n} \cdot \mathbf{q}$, where $\mathbf{q}$ is the reference point resting on the plane:

$$
\mathbf{f} \cdot \mathbf{p} = \mathbf{n} \cdot \mathbf{p} - \mathbf{n} \cdot \mathbf{q} \implies \mathbf{f} \cdot \mathbf{p} = \mathbf{n} \cdot (\mathbf{p} - \mathbf{q})
$$

Where:

* $\mathbf{n} \cdot \mathbf{p}$ is the projection of the point onto $\mathbf{n}$.
* $\mathbf{n} \cdot \mathbf{q}$ is the projection of the plane onto $\mathbf{n}$.

The difference between them is the distance between $\mathbf{p}$ and the plane (represented by $\mathbf{q}$). Geometrically, $\mathbf{p} - \mathbf{q}$ creates a displacement vector pointing from the plane to the point, and projecting that displacement onto $\hat{n}$ discards everything except the component perpendicular to the plane.

---

### 3. Frustum Culling: Classifying a Point Against the View Volume

A view frustum is not a single plane; it is a **volume** bounded by **six distinct planes** (Near, Far, Left, Right, Top, Bottom), each stored as a 4D vector $\mathbf{f}_i$ with its normal pointing **inward**. Classification is therefore not one test but six, and the sign of $\mathbf{f}_i \cdot \mathbf{p}$ for a single plane $\mathbf{f}_i$ only reports which side of **that one plane** the point lies on:

* $\mathbf{f}_i \cdot \mathbf{p} = 0 \implies \mathbf{p}$ lies **on** plane $i$.
* $\mathbf{f}_i \cdot \mathbf{p} > 0 \implies \mathbf{p}$ lies in **front of** (on the inward side of) plane $i$.
* $\mathbf{f}_i \cdot \mathbf{p} < 0 \implies \mathbf{p}$ lies **behind** (on the outward side of) plane $i$.

The volume-level classification is built from those six results:

* **Inside:** the point must satisfy $\mathbf{f}_i \cdot \mathbf{p} \ge 0$ against **all six** planes. A positive result against one plane alone is not sufficient.
* **Outside:** if $\mathbf{f}_i \cdot \mathbf{p} < 0$ against **any single** plane, the point is immediately rejected as outside the volume — the remaining planes need not be tested (early-out rejection).

This is also why the dot product does not need to be normalized for a pure inside/outside test: since $\mathbf{f} \cdot \mathbf{p} = \text{Distance} \times \|\mathbf{n}\|$ and $\|\mathbf{n}\| > 0$, scaling never changes the **sign**. Normalization is only required when the engine needs the actual distance in world units, such as testing a bounding sphere of radius $r$ (inside if $\mathbf{f}_{\text{norm}} \cdot \mathbf{p} \ge -r$) rather than a single point.

---

**Back to Question:** [Q_05_Distance_Point_and_Plane](../Questions/Q_05_Distance_Point_and_Plane.md) | **Related Concepts:** [05_Distance_Point_and_Plane](../../../Concepts/05_Geometry/05_Distance_Point_and_Plane.md)
