---
topic: Geometry
tags: [exercise, solution, planes, implicit-plane, parametric-plane]
---

# Solution: Planes

This solution note details the step-by-step calculations and conceptual answers for the planes exercise.

---

## Part 1: Calculation

### Question 1: Parametric Equation & Normal Vector

A parametric plane passes through starting position $\mathbf{p} = (1, 2, 3)$ with direction vectors $\mathbf{u} = \langle 1, 0, 2 \rangle$ and $\mathbf{v} = \langle 0, 3, 1 \rangle$:

#### 1. Parametric Equation $Q(s, t)$

$$
Q(s, t) = \mathbf{p} + s\mathbf{u} + t\mathbf{v}
$$

$$
Q(s, t) = (1, 2, 3) + s\langle 1, 0, 2 \rangle + t\langle 0, 3, 1 \rangle
$$

#### 2. Normal Vector $\mathbf{n} = \mathbf{u} \times \mathbf{v}$

$$
\mathbf{n} = \mathbf{u} \times \mathbf{v} = \begin{bmatrix} 1 \\\\ 0 \\\\ 2 \end{bmatrix} \times \begin{bmatrix} 0 \\\\ 3 \\\\ 1 \end{bmatrix}
$$

$$
\mathbf{n} = \left\langle (0)(1) - (2)(3),\; (2)(0) - (1)(1),\; (1)(3) - (0)(0) \right\rangle = \langle -6, -1, 3 \rangle
$$

---

### Question 2: Implicit Plane & 4D Vector Point Testing

A plane has a known point $\mathbf{q} = (2, -1, 4)$ lying on its surface and normal vector $\mathbf{n} = \langle 2, 3, -1 \rangle$:

#### 1. Plane Constant $d = -\mathbf{n} \cdot \mathbf{q}$

$$
d = -\mathbf{n} \cdot \mathbf{q} = -\langle 2, 3, -1 \rangle \cdot (2, -1, 4)
$$

$$
d = -\left( (2)(2) + (3)(-1) + (-1)(4) \right) = -(4 - 3 - 4) = 3
$$

#### 2. Implicit Plane Equation $\mathbf{n} \cdot \mathbf{p} + d = 0$

$$
\langle 2, 3, -1 \rangle \cdot \mathbf{p} + 3 = 0
$$

#### 3. 4D Vector Representation $\mathbf{f} = [n_x, n_y, n_z, d]$

$$
\mathbf{f} = [2, 3, -1, 3]
$$

#### 4. Testing Point $\mathbf{p}_1 = (1, 2, 2)$
Convert $\mathbf{p}_1$ to 4D homogeneous coordinates by appending $1$ ($\mathbf{p}_{1,\text{4D}} = [1, 2, 2, 1]$), and evaluate the 4D dot product:

$$
\mathbf{f} \cdot \mathbf{p}_1 = [2, 3, -1, 3] \cdot [1, 2, 2, 1] = (2)(1) + (3)(2) + (-1)(2) + (3)(1) = 2 + 6 - 2 + 3 = 9
$$

* **Conclusion:** The point $\mathbf{p}_1$ does **not** lie on the plane (since $\mathbf{f} \cdot \mathbf{p}_1 = 9 \neq 0$).
* **Classification by Sign:**
  * $\mathbf{f} \cdot \mathbf{p} = 0 \implies \mathbf{p}$ lies **on the plane**.
  * $\mathbf{f} \cdot \mathbf{p} > 0 \implies \mathbf{p}_1$ lies in **front** of the plane.
  * $\mathbf{f} \cdot \mathbf{p} < 0 \implies \mathbf{p}$ lies **behind** the plane.

---

## Part 2: Conceptual Understanding

### 1. Why 2 Non-Parallel Direction Vectors are Required

* A line is a 1D collection of infinite points; any 2 distinct points establish a path/direction vector defining a line.
* A plane is a 2D surface; 2 non-parallel intersecting lines (or 2 independent direction vectors $\mathbf{u}$ and $\mathbf{v}$) are required to span the 2 dimensions of the plane.

---

### 2. Proof: Why $d = -\mathbf{n} \cdot \mathbf{q}$ is Constant for Every Point on the Plane

For any vector $\mathbf{v}$ lying flat inside the plane, the dot product with the perpendicular normal vector $\mathbf{n}$ is zero ($\mathbf{n} \cdot \mathbf{v} = 0$).

Let $\mathbf{v}$ be the displacement vector between any two points $\mathbf{q}_1$ and $\mathbf{q}_2$ on the plane ($\mathbf{v} = \mathbf{q}_2 - \mathbf{q}_1$):

$$
\mathbf{n} \cdot (\mathbf{q}_2 - \mathbf{q}_1) = 0
$$

Distributing the dot product:

$$
(\mathbf{n} \cdot \mathbf{q}_2) - (\mathbf{n} \cdot \mathbf{q}_1) = 0 \implies \mathbf{n} \cdot \mathbf{q}_2 = \mathbf{n} \cdot \mathbf{q}_1
$$

This proves that taking the dot product of $\mathbf{n}$ with **any** point on the plane always yields the exact same constant value.

---

### 3. Why 3D Graphics Prefer the Implicit 4D Representation

* **Storage Efficiency:** The 4D implicit representation $\mathbf{f} = [n_x, n_y, n_z, d]$ needs to store only **4 scalar values**, whereas storing a plane via an explicit reference point $\mathbf{q}$ and normal $\mathbf{n}$ requires 2 separate 3D vectors (**6 scalar values**).
* **Computational Speed:** Testing whether a 3D point lies on a plane, in front of a plane, or behind a plane simplifies to a single 4D dot product operation ($\mathbf{f} \cdot \mathbf{p}$).

---

**Back to Question:** [[Q_04_Planes]] | **Related Concepts:** [[04_Planes]]
