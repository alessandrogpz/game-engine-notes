---
topic: Geometry
tags: [exercise, solution, intersection-two-planes, implicit-plane, cross-product]
---
# Solution

## Part 1: Calculation

### 1. Two axis-aligned planes

$\mathbf{f}_1 = [1, 0, 0, -2]$, $\mathbf{f}_2 = [0, 1, 0, -3]$.

**Direction vector.**

$$
\mathbf{v} = \mathbf{n}_1 \times \mathbf{n}_2 = (1,0,0) \times (0,1,0)
= \big(0(0) - 0(1),\; 0(0) - 1(0),\; 1(1) - 0(0)\big) = (0, 0, 1)
$$

$$
\mathbf{v}^2 = \mathbf{v} \cdot \mathbf{v} = 0^2 + 0^2 + 1^2 = 1
$$

**$\mathbf{v}^2 = 1 \neq 0$, so the planes are not parallel.** Were they parallel the normals
would be proportional and their cross product the zero vector.

**The two cross products.**

$$
\mathbf{v} \times \mathbf{n}_2 = (0,0,1) \times (0,1,0) = (-1, 0, 0)
\qquad
\mathbf{n}_1 \times \mathbf{v} = (1,0,0) \times (0,0,1) = (0, -1, 0)
$$

**Solving for $\mathbf{p}$.** Introduce a third plane $[\mathbf{v} \mid 0]$ and apply the
three-plane formula. Stacking the normals as rows:

$$
\begin{bmatrix}
\leftarrow \mathbf{n}_1 \rightarrow \\\\
\leftarrow \mathbf{n}_2 \rightarrow \\\\
\leftarrow \mathbf{n}_3 \rightarrow
\end{bmatrix}
\mathbf{p}
=
\begin{bmatrix} -d_1 \\\\ -d_2 \\\\ 0 \end{bmatrix}
\qquad
\mathbf{p} = \frac{d_1(\mathbf{v} \times \mathbf{n}_2) + d_2(\mathbf{n}_1 \times \mathbf{v}) + d_3(\mathbf{n}_2 \times \mathbf{n}_1)}{(\mathbf{n}_1 \times \mathbf{n}_2) \cdot \mathbf{v}}
$$

With $d_3 = 0$ the third term vanishes, and since $\mathbf{n}_1 \times \mathbf{n}_2 = \mathbf{v}$
the denominator is $\mathbf{v} \cdot \mathbf{v} = \mathbf{v}^2$:

$$
\mathbf{p} = \frac{d_1(\mathbf{v} \times \mathbf{n}_2) + d_2(\mathbf{n}_1 \times \mathbf{v})}{\mathbf{v}^2}
= \frac{-2(-1,0,0) + (-3)(0,-1,0)}{1}
= \frac{(2,0,0) + (0,3,0)}{1}
$$

**$\mathbf{p} = (2, 3, 0)$, giving $L(t) = (2, 3, 0) + t(0, 0, 1)$.**

**Verification.**

$$
\mathbf{f}_1 \cdot \mathbf{p} = [1,0,0,-2] \cdot [2,3,0,1] = 2 + 0 + 0 - 2 = 0
$$

$$
\mathbf{f}_2 \cdot \mathbf{p} = [0,1,0,-3] \cdot [2,3,0,1] = 0 + 3 + 0 - 3 = 0
$$

Geometrically the two planes are $x = 2$ and $y = 3$, so their intersection is the vertical
line through $(2, 3, 0)$ running parallel to the $z$-axis — exactly $L(t)$, with $z$ left free
as the parameter.

---

### 2. Two general planes

$\mathbf{f}_1 = [1, 1, 0, -3]$, $\mathbf{f}_2 = [0, 1, 1, -5]$.

$$
\mathbf{v} = \mathbf{n}_1 \times \mathbf{n}_2 = (1,1,0) \times (0,1,1) = (1, -1, 1)
\qquad
\mathbf{v}^2 = 1 + 1 + 1 = 3
$$

$$
\mathbf{v} \times \mathbf{n}_2 = (1,-1,1) \times (0,1,1) = (-2, -1, 1)
\qquad
\mathbf{n}_1 \times \mathbf{v} = (1,1,0) \times (1,-1,1) = (1, -1, -2)
$$

$$
\mathbf{p} = \frac{-3(-2,-1,1) + (-5)(1,-1,-2)}{3}
= \frac{(6,3,-3) + (-5,5,10)}{3}
= \frac{(1,8,7)}{3}
$$

**$\mathbf{p} = \left(\frac{1}{3}, \frac{8}{3}, \frac{7}{3}\right)$.**

**Verification.**

$$
\mathbf{f}_1 \cdot \mathbf{p} = \frac{1}{3} + \frac{8}{3} + 0 - 3 = \frac{9}{3} - 3 = 0
$$

$$
\mathbf{f}_2 \cdot \mathbf{p} = 0 + \frac{8}{3} + \frac{7}{3} - 5 = \frac{15}{3} - 5 = 0
$$

---

### 3. Why the denominator collapses

The three planes are $\mathbf{f}_1 = [\mathbf{n}_1 \mid d_1]$,
$\mathbf{f}_2 = [\mathbf{n}_2 \mid d_2]$ and $\mathbf{f}_3 = [\mathbf{n}_3 \mid 0]$, where
$\mathbf{n}_3 = \mathbf{v}$ is parallel to both original planes. For the planes of question 2:

$$
\begin{bmatrix}
1 & 1 & 0 \\\\
0 & 1 & 1 \\\\
1 & -1 & 1
\end{bmatrix}
\mathbf{p}
=
\begin{bmatrix} 3 \\\\ 5 \\\\ 0 \end{bmatrix}
$$

Taking the determinant of that matrix directly:

$$
\det \mathbf{A} = 1\big(1(1) - 1(-1)\big) - 1\big(0(1) - 1(1)\big) + 0\big(0(-1) - 1(1)\big)
= 2 + 1 + 0 = 3
$$

And the scalar triple product, using $\mathbf{n}_3 = \mathbf{n}_1 \times \mathbf{n}_2$:

$$
[\mathbf{n}_1, \mathbf{n}_2, \mathbf{n}_3]
= (\mathbf{n}_1 \times \mathbf{n}_2) \cdot \mathbf{n}_3
= (\mathbf{n}_1 \times \mathbf{n}_2) \cdot (\mathbf{n}_1 \times \mathbf{n}_2)
= \mathbf{v} \cdot \mathbf{v} = \mathbf{v}^2 = 3
$$

**Both give $3$.** The collapse happens because the third normal was *chosen* to be
$\mathbf{n}_1 \times \mathbf{n}_2$, so the triple product becomes a vector dotted with itself.

This is also why $\mathbf{v}^2$ is a safe denominator to test: a self dot product is always
$\geq 0$, and it is zero only when the vector itself is zero.

---

### 4. Classifying parallel pairs

**(a)** $\mathbf{f}_1 = [1,0,0,-1]$, $\mathbf{f}_2 = [2,0,0,-6]$.

$$
\mathbf{v} = (1,0,0) \times (2,0,0) = (0,0,0) \qquad \mathbf{v}^2 = 0
$$

Here $\mathbf{n}_2 = 2\mathbf{n}_1$ but $d_2 \neq 2d_1$, since $2(-1) = -2 \neq -6$.
**The planes are parallel and distinct — no intersection.** They are $x = 1$ and $x = 3$.

**(b)** $\mathbf{f}_1 = [1,0,0,-1]$, $\mathbf{f}_2 = [2,0,0,-2]$.

$\mathbf{v}^2 = 0$ again, but now the whole 4-vector scales: $\mathbf{f}_2 = 2\mathbf{f}_1$.
**The planes are coincident — the intersection is the entire plane**, not a line. Both state
$x = 1$.

---

### 5. Which point on the line the formula returns

Using $\mathbf{p} = (2,3,0)$ and $\mathbf{v} = (0,0,1)$ from question 1:

$$
\mathbf{v} \cdot \mathbf{p} = (0,0,1) \cdot (2,3,0) = 0
\qquad
\lVert \mathbf{p} \rVert = \sqrt{2^2 + 3^2 + 0^2} = \sqrt{13}
$$

Stepping one unit along the line in each direction:

$$
\lVert L(1) \rVert = \lVert (2,3,1) \rVert = \sqrt{14}
\qquad
\lVert L(-1) \rVert = \lVert (2,3,-1) \rVert = \sqrt{14}
$$

Equal distances either side, so $\mathbf{p}$ sits at the symmetric centre — moving the same
amount in either direction produces the same displacement. **That symmetry identifies
$\mathbf{p}$ as the point on the line closest to the origin**, and it is no coincidence:

$$
\lVert \mathbf{p} + t\mathbf{v} \rVert^2
= \lVert \mathbf{p} \rVert^2 + 2t(\mathbf{v} \cdot \mathbf{p}) + t^2\mathbf{v}^2
= \lVert \mathbf{p} \rVert^2 + t^2\mathbf{v}^2
$$

The cross term vanishes precisely because $\mathbf{v} \cdot \mathbf{p} = 0$. What remains grows
with $t^2$ and $\mathbf{v}^2 > 0$, so the minimum is at $t = 0$ — the returned $\mathbf{p}$
itself. Here that reads $13 + t^2$, which is $14$ at both $t = \pm 1$.

---

## Part 2: Conceptual Understanding

### 1. Why the direction must be $\mathbf{n}_1 \times \mathbf{n}_2$

Assuming the two planes intersect, their intersection is a line. (Adding a third plane
intersecting both simultaneously would narrow that line to a point — the three-plane case.)

That line lies in plane 1, so it must be perpendicular to $\mathbf{n}_1$; and it lies in plane
2, so it must be perpendicular to $\mathbf{n}_2$. It has to be perpendicular to both normals at
once. The cross product is defined to produce exactly that vector, so
$\mathbf{v} = \mathbf{n}_1 \times \mathbf{n}_2$ is the direction.

The reason perpendicular-to-the-normal means *within* the plane is the plane equation itself.
A direction $\mathbf{d}$ stays inside a plane when moving along it changes nothing:

$$
\mathbf{n} \cdot (\mathbf{p} + \mathbf{d}) + d = (\mathbf{n} \cdot \mathbf{p} + d) + \mathbf{n} \cdot \mathbf{d}
$$

The bracket is already zero for a point on the plane, so the sum stays zero exactly when
$\mathbf{n} \cdot \mathbf{d} = 0$. A direction not perpendicular to a normal has a component
along it, and travelling that way climbs off the plane — it can only ever cross one plane at a
time. A direction perpendicular to both crosses neither, so it runs along the section belonging
to both at once.

### 2. What $d_3 = 0$ accomplishes, and the denominator

The third plane exists for its **normal**, not its position. $\mathbf{n}_3 = \mathbf{v}$ is
what supplies the missing third independent direction: two intersecting planes leave one degree
of freedom, and a third plane whose normal is linearly independent of both pins it down.

If $\mathbf{n}_1$ and $\mathbf{n}_2$ are independent, then $\mathbf{v} = \mathbf{n}_1 \times \mathbf{n}_2$
is non-zero and perpendicular to both, so the three are independent by construction and the
system has a unique solution.

$d_3$ is free — any value gives a valid plane containing the line's direction, and every choice
returns some point on the intersection line. Setting $d_3 = 0$ makes that third plane pass
**through the origin**, which is what turns the answer from arbitrary into canonical: the
returned point is where the line pierces a plane through the origin perpendicular to the line
itself, which is the closest point to the origin. It simplifies the algebra by dropping a term,
but that is the smaller half of what it buys.

For the denominator, substituting $\mathbf{n}_3 = \mathbf{n}_1 \times \mathbf{n}_2$:

$$
[\mathbf{n}_1, \mathbf{n}_2, \mathbf{v}]
= (\mathbf{n}_1 \times \mathbf{n}_2) \cdot \mathbf{v}
= (\mathbf{n}_1 \times \mathbf{n}_2) \cdot (\mathbf{n}_1 \times \mathbf{n}_2)
= \mathbf{v}^2
$$

A vector dotted with itself. This is useful beyond brevity: $\mathbf{v}^2 \geq 0$ always, and
it vanishes only when $\mathbf{v}$ is the zero vector — so the single quantity in the
denominator is also the degeneracy test.

### 3. Why $\mathbf{v} \cdot \mathbf{p} = 0$, and why canonical matters

Dot the formula through with $\mathbf{v}$:

$$
\mathbf{v} \cdot \mathbf{p} = \frac{d_1\,\mathbf{v} \cdot (\mathbf{v} \times \mathbf{n}_2) + d_2\,\mathbf{v} \cdot (\mathbf{n}_1 \times \mathbf{v})}{\mathbf{v}^2}
$$

A vector dotted with a cross product containing itself is always zero, since the cross product
is perpendicular to both its operands. Both numerator terms therefore vanish:

$$
\mathbf{v} \cdot (\mathbf{v} \times \mathbf{n}_2) = 0
\qquad
\mathbf{v} \cdot (\mathbf{n}_1 \times \mathbf{v}) = 0
\qquad\Longrightarrow\qquad
\mathbf{v} \cdot \mathbf{p} = \frac{0}{\mathbf{v}^2} = 0
$$

This holds for any input planes, not just the worked examples. And it is exactly the condition
that makes $\mathbf{p}$ the closest point to the origin, by the expansion in question 5:
$\lVert \mathbf{p} + t\mathbf{v} \rVert^2 = \lVert \mathbf{p} \rVert^2 + t^2\mathbf{v}^2$ once
the cross term drops out. Travelling any distance along the line only adds a $\mathbf{v}$
component orthogonal to $\mathbf{p}$, which can only lengthen the result.

A canonical choice is preferable because the same two planes then always produce the same
answer. Two descriptions of one line can be compared, cached or tested for equality directly;
with an arbitrary starting point, two correct results for the same line need not match, and
every equality check has to reduce both to a canonical form first. Being nearest the origin
also keeps the coordinates as small as the geometry allows, which loses less precision than a
point picked far out along the line.

### 4. The two parallel cases

$\mathbf{v}^2 = 0$ means the normals are proportional, so the planes are parallel. That covers
two situations:

* **Distinct parallel planes** — no intersection at all.
* **Coincident planes** — the same plane written twice; the intersection is the whole plane.

Comparing normals cannot separate them, because the normals are proportional in *both* cases —
that is what being parallel means, and it is precisely the information $\mathbf{v}^2 = 0$
already gave. The normals say nothing about how the planes are positioned along their shared
direction; only $d$ carries that.

What must be compared is the **whole 4-vector including $d$**. Find the scalar $k$ relating the
normals, then test whether it also relates the distance terms:

$$
\mathbf{n}_2 = k\,\mathbf{n}_1
\quad\text{and}\quad
d_2 = k\,d_1
\qquad\Longrightarrow\qquad
\mathbf{f}_2 = k\,\mathbf{f}_1
$$

If the full 4-vector scales, report **coincident** — the intersection is the entire plane. If
the normals scale but $d$ does not, report **parallel and disjoint** — no intersection. Both
are distinct from the ordinary case, and a caller needs to tell them apart: one has infinitely
many points in the answer, the other none.

In floating point neither test should be exact equality. $k$ comes from the largest-magnitude
normal component, to avoid dividing by something near zero, and $d_2 - k\,d_1$ is compared
against a tolerance scaled to the size of the terms rather than a fixed epsilon — the same
reasoning that applies to the determinant threshold in the three-plane case.

---
**Back to Question:** [Q_09_Intersection_Two_Planes](../Questions/Q_09_Intersection_Two_Planes.md) | **Related Concepts:** [09_Intersection_Two_Planes](../../../Concepts/05_Geometry/09_Intersection_Two_Planes.md)
