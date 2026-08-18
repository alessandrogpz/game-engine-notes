---
topic: Geometry
tags: [exercise, solution, intersection-three-planes, implicit-plane, cross-product]
---
# Solution

## Part 1: Calculation

### 1. Three axis-aligned planes

$\mathbf{f}_1 = [1, 0, 0, -2]$, $\mathbf{f}_2 = [0, 1, 0, -3]$, $\mathbf{f}_3 = [0, 0, 1, -4]$.

**Writing the system.** A point lies on a plane when the 4D dot product vanishes, so for each
$i$:

$$
[\mathbf{n}_i \mid d_i] \cdot \mathbf{p} = 0
\quad\Longrightarrow\quad
(\mathbf{n}_i \cdot \mathbf{p}) + d_i = 0
\quad\Longrightarrow\quad
\mathbf{n}_i \cdot \mathbf{p} = -d_i
$$

Stacking the three normals as rows puts this in the form $\mathbf{A}\mathbf{p} = \mathbf{b}$:

$$
\begin{bmatrix}
n_{1x} & n_{1y} & n_{1z} \\\\
n_{2x} & n_{2y} & n_{2z} \\\\
n_{3x} & n_{3y} & n_{3z}
\end{bmatrix}
\mathbf{p}
=
\begin{bmatrix} -d_1 \\\\ -d_2 \\\\ -d_3 \end{bmatrix}
\quad\Longrightarrow\quad
\begin{bmatrix}
1 & 0 & 0 \\\\
0 & 1 & 0 \\\\
0 & 0 & 1
\end{bmatrix}
\mathbf{p}
=
\begin{bmatrix} 2 \\\\ 3 \\\\ 4 \end{bmatrix}
$$

**$\mathbf{A} = \mathbf{I}$ and $\mathbf{b} = (2, 3, 4)$.**

**Scalar triple product.**

$$
(\mathbf{n}_1 \times \mathbf{n}_2) \cdot \mathbf{n}_3
= \big([1,0,0] \times [0,1,0]\big) \cdot [0,0,1]
$$

$$
= [\,0(0) - 0(1),\; 0(0) - 1(0),\; 1(1) - 0(0)\,] \cdot [0,0,1]
= [0,0,1] \cdot [0,0,1] = 1
$$

**$[\mathbf{n}_1, \mathbf{n}_2, \mathbf{n}_3] = 1 \neq 0$, so a unique intersection point exists.**
Two planes intersect in a line — its direction is $\mathbf{n}_1 \times \mathbf{n}_2$ — and the
third narrows that line down to a point.

**Solving.** With $\mathbf{A} = \mathbf{I}$ the system is already solved, but applying the
general formula as a check:

$$
\mathbf{p} = \frac{d_1(\mathbf{n}_3 \times \mathbf{n}_2) + d_2(\mathbf{n}_1 \times \mathbf{n}_3) + d_3(\mathbf{n}_2 \times \mathbf{n}_1)}{[\mathbf{n}_1, \mathbf{n}_2, \mathbf{n}_3]}
= \frac{2(1,0,0) + 3(0,1,0) + 4(0,0,1)}{1}
$$

**$\mathbf{p} = (2, 3, 4)$.**

Verifying against all three planes:

$$
\mathbf{f}_1 \cdot \mathbf{p} = 2 - 2 = 0, \qquad
\mathbf{f}_2 \cdot \mathbf{p} = 3 - 3 = 0, \qquad
\mathbf{f}_3 \cdot \mathbf{p} = 4 - 4 = 0
$$

The sanity check is immediate: the three equations read $x = 2$, $y = 3$, $z = 4$ directly.

---

### 2. Three general planes

$\mathbf{f}_1 = [1, 1, 0, -3]$, $\mathbf{f}_2 = [0, 1, 1, -5]$, $\mathbf{f}_3 = [1, 0, 1, -4]$.

**The three cross products.**

$$
\mathbf{n}_3 \times \mathbf{n}_2 = (1,0,1) \times (0,1,1) = \big(0(1) - 1(1),\; 1(0) - 1(1),\; 1(1) - 0(0)\big) = (-1, -1, 1)
$$

$$
\mathbf{n}_1 \times \mathbf{n}_3 = (1,1,0) \times (1,0,1) = \big(1(1) - 0(0),\; 0(1) - 1(1),\; 1(0) - 1(1)\big) = (1, -1, -1)
$$

$$
\mathbf{n}_2 \times \mathbf{n}_1 = (0,1,1) \times (1,1,0) = \big(1(0) - 1(1),\; 1(1) - 0(0),\; 0(1) - 1(1)\big) = (-1, 1, -1)
$$

**The determinant.**

$$
\det \mathbf{A} = \det
\begin{bmatrix}
1 & 1 & 0 \\\\
0 & 1 & 1 \\\\
1 & 0 & 1
\end{bmatrix}
= (1 + 1 + 0) - (0 + 0 + 0) = 2
$$

**Solving.** With $d_1 = -3$, $d_2 = -5$, $d_3 = -4$:

$$
\mathbf{p} = \frac{-3(-1,-1,1) + (-5)(1,-1,-1) + (-4)(-1,1,-1)}{2}
= \frac{(3,3,-3) + (-5,5,5) + (4,-4,4)}{2}
= \frac{(2,4,6)}{2}
$$

**$\mathbf{p} = (1, 2, 3)$.**

Verifying:

$$
\mathbf{f}_1 \cdot \mathbf{p} = (1,1,0,-3) \cdot (1,2,3,1) = 1 + 2 + 0 - 3 = 0
$$

$$
\mathbf{f}_2 \cdot \mathbf{p} = (0,1,1,-5) \cdot (1,2,3,1) = 0 + 2 + 3 - 5 = 0
$$

$$
\mathbf{f}_3 \cdot \mathbf{p} = (1,0,1,-4) \cdot (1,2,3,1) = 1 + 0 + 3 - 4 = 0
$$

---

### 3. Classifying degenerate triples

**(a)** $\mathbf{f}_1 = [1,0,0,0]$, $\mathbf{f}_2 = [0,1,0,0]$, $\mathbf{f}_3 = [1,1,0,0]$.

$$
\begin{bmatrix}
1 & 0 & 0 \\\\
0 & 1 & 0 \\\\
1 & 1 & 0
\end{bmatrix}
\mathbf{p} =
\begin{bmatrix} 0 \\\\ 0 \\\\ 0 \end{bmatrix}
\qquad\longrightarrow\qquad
\begin{bmatrix}
1 & 0 & 0 \\\\
0 & 1 & 0 \\\\
0 & 0 & 0
\end{bmatrix}
\mathbf{p} =
\begin{bmatrix} 0 \\\\ 0 \\\\ 0 \end{bmatrix}
$$

Row 3 reduces to $0 = 0$, and $z$ is never constrained. **Infinitely many solutions**, because
$\mathbf{n}_3 = \mathbf{n}_1 + \mathbf{n}_2$. Geometrically all three planes contain the
$z$-axis — a sheaf of planes hinged on one common line.

**(b)** $\mathbf{f}_1 = [1,0,0,0]$, $\mathbf{f}_2 = [0,1,0,0]$, $\mathbf{f}_3 = [1,1,0,-1]$.

$$
\begin{bmatrix}
1 & 0 & 0 \\\\
0 & 1 & 0 \\\\
1 & 1 & 0
\end{bmatrix}
\mathbf{p} =
\begin{bmatrix} 0 \\\\ 0 \\\\ 1 \end{bmatrix}
\qquad\longrightarrow\qquad
\begin{bmatrix}
1 & 0 & 0 \\\\
0 & 1 & 0 \\\\
0 & 0 & 0
\end{bmatrix}
\mathbf{p} =
\begin{bmatrix} 0 \\\\ 0 \\\\ 1 \end{bmatrix}
$$

Same left-hand side, but row 3 now reads $0 = 1$. **The system is impossible — no solutions.**
The third plane is parallel to the line the first two share, displaced off it: a triangular
prism, with three parallel intersection lines and no common point.

**(c)** $\mathbf{f}_1 = [1,0,0,-1]$, $\mathbf{f}_2 = [1,0,0,-3]$, $\mathbf{f}_3 = [0,1,0,0]$.

$$
\begin{bmatrix}
1 & 0 & 0 \\\\
1 & 0 & 0 \\\\
0 & 1 & 0
\end{bmatrix}
\mathbf{p} =
\begin{bmatrix} 1 \\\\ 3 \\\\ 0 \end{bmatrix}
$$

Row 1 demands $x = 1$ and row 2 demands $x = 3$. **Impossible — no solutions.** The first two
planes are parallel and distinct; the third crosses both but there is no point common to all.

In all three cases $[\mathbf{n}_1, \mathbf{n}_2, \mathbf{n}_3] = 0$, which is why the
determinant alone cannot separate them.

---

### 4. Swapping the operand order

Reversing every cross product negates it, since
$\mathbf{a} \times \mathbf{b} = -(\mathbf{b} \times \mathbf{a})$:

$$
\mathbf{n}_2 \times \mathbf{n}_3 = (1,1,-1), \qquad
\mathbf{n}_3 \times \mathbf{n}_1 = (-1,1,1), \qquad
\mathbf{n}_1 \times \mathbf{n}_2 = (1,-1,1)
$$

$$
\mathbf{p}' = \frac{-3(1,1,-1) + (-5)(-1,1,1) + (-4)(1,-1,1)}{2}
= \frac{(-2,-4,-6)}{2} = (-1,-2,-3)
$$

**$\mathbf{p}' = -\mathbf{p}$ exactly** — the correct point negated, which is its reflection
through the **origin**, not through any of the planes. Every term in the numerator flipped
sign while the determinant did not, so the whole quotient flipped.

That $\mathbf{p}'$ is not merely wrong but *systematically* wrong is the point: it satisfies
none of the three planes, giving $\mathbf{f}_1 \cdot \mathbf{p}' = -6$,
$\mathbf{f}_2 \cdot \mathbf{p}' = -10$ and $\mathbf{f}_3 \cdot \mathbf{p}' = -8$. The reversal
in the correct formula is what absorbs the minus sign carried by
$\mathbf{b} = (-d_1, -d_2, -d_3)$; drop it and the sign survives to the answer.

---

## Part 2: Conceptual Understanding

### 1. Why linear independence is exactly the condition

Linear independence means no plane normal can be written as a combination of the other two.
Two linearly independent planes intersect in a line; a third, independent of both, cuts that
line at a single point. If one normal *is* a combination of the others, that configuration is
lost — the third plane adds no new constraint, and instead of narrowing the line to a point it
either contains the line or misses it entirely.

Both tests certify the same thing. Arranging the normals as the rows of $\mathbf{A}$ and taking
$\det \mathbf{A}$, or taking the scalar triple product
$[\mathbf{n}_1, \mathbf{n}_2, \mathbf{n}_3]$, yields the same number:

$$
\det \mathbf{A} = [\mathbf{n}_1, \mathbf{n}_2, \mathbf{n}_3] = (\mathbf{n}_1 \times \mathbf{n}_2) \cdot \mathbf{n}_3
$$

If the result is non-zero the normals are linearly independent and a unique solution exists.
If it is zero, at least two of the planes fail to be independent, and the system has either
infinitely many solutions or none.

Read as a volume, the triple product is the signed volume of the parallelepiped spanned by the
three normals. That volume collapses to zero exactly when the three normals become
**coplanar** — all lying in a single plane through the origin — which is the same statement as
one being a combination of the other two. So "unique intersection point" and "the normals span
a non-degenerate volume" are the same condition seen from two directions.

### 2. How the operand reversal absorbs the minus sign

Start from where the $-d_i$ comes from. A plane is $\mathbf{f} = [\mathbf{n}_i \mid d_i]$, and
a point on it satisfies:

$$
[\mathbf{n}_i \mid d_i] \cdot \mathbf{p} = 0
\quad\Longrightarrow\quad
(\mathbf{n}_i \cdot \mathbf{p}) + d_i = 0
\quad\Longrightarrow\quad
\mathbf{n}_i \cdot \mathbf{p} = -d_i
$$

With three linearly independent planes, solving that system gives:

$$
\mathbf{p} = \frac{-d_1(\mathbf{n}_2 \times \mathbf{n}_3) - d_2(\mathbf{n}_3 \times \mathbf{n}_1) - d_3(\mathbf{n}_1 \times \mathbf{n}_2)}{[\mathbf{n}_1, \mathbf{n}_2, \mathbf{n}_3]}
$$

This works, but it is cumbersome: the formula carries a minus on every term while $d_i$ is
frequently already negative, so the signs cancel twice over. With $d_1 = 2$, for instance, the
first term reads $-(-2)(\mathbf{n}_2 \times \mathbf{n}_3)$.

The cross product is **anticommutative** —
$\mathbf{a} \times \mathbf{b} = -(\mathbf{b} \times \mathbf{a})$ — so each minus sign can be
pushed into its cross product by swapping the operands:

$$
\mathbf{p} = \frac{d_1(\mathbf{n}_3 \times \mathbf{n}_2) + d_2(\mathbf{n}_1 \times \mathbf{n}_3) + d_3(\mathbf{n}_2 \times \mathbf{n}_1)}{[\mathbf{n}_1, \mathbf{n}_2, \mathbf{n}_3]}
$$

Identical result, and a much better formula to work with. Part 1 question 4 is what happens
when the reversal is dropped but the signs are not put back: every term flips and the answer
comes out as $-\mathbf{p}$.

### 3. What separates no solution from infinitely many

When $\det \mathbf{A} = 0$ the three planes have no single point in common, and there are two
ways that happens geometrically:

* **(A)** at least two of the planes are parallel, or
* **(B)** each pair meets in a line but the three lines never coincide — the triangular prism.

In neither case is there a clean three-plane intersection.

Which one you have is settled by solving the system with Gauss–Jordan and reading the final
rows. If a row reduces to $0 = 0$, that equation was a multiple — or a sum — of the others and
constrained nothing; the solution set is a whole line or plane, so there are **infinitely
many** solutions. If a row reduces to $0 = c$ for some non-zero $c$, the equations contradict
each other and there are **none**. Part 1 question 3 shows the pair side by side: identical
left-hand sides, and only the right-hand side deciding between $0 = 0$ and $0 = 1$.

Stated in general terms, this is a rank comparison. Writing $[\mathbf{A} \mid \mathbf{b}]$ for
the augmented matrix:

$$
\mathrm{rank}(\mathbf{A}) = \mathrm{rank}([\mathbf{A} \mid \mathbf{b}]) < 3 \;\Rightarrow\; \text{infinitely many}
$$

$$
\mathrm{rank}(\mathbf{A}) < \mathrm{rank}([\mathbf{A} \mid \mathbf{b}]) \;\Rightarrow\; \text{none}
$$

Adding $\mathbf{b}$ raises the rank exactly when it introduces a constraint the normals cannot
express — which is the algebraic form of "the third plane is displaced off the line the other
two share".

Reporting only "the matrix is singular" is insufficient because the two cases demand different
responses. Infinitely many solutions means the answer is a line or a plane, and a caller may
legitimately want it. No solution means the query is void and there is nothing to return. A
routine that collapses both into one failure code forces the caller to redo the classification
it already had the information to make.

### 4. Why the normals need not be unit length

The plane equation is homogeneous: scaling $[\mathbf{n} \mid d]$ by any non-zero constant $k$
gives $k\mathbf{n} \cdot \mathbf{p} + kd = k(\mathbf{n} \cdot \mathbf{p} + d)$, which is zero
for exactly the same points. The normal and the distance term scale together, so nothing
distorts. In the solution formula the same $k$ appears in the numerator and in the determinant
and cancels outright.

Point-plane distance is different, because there the two halves do *not* scale together. The
distance is a dot product divided by the normal's length:

$$
\mathrm{dist}(\mathbf{p}) = \frac{\mathbf{n} \cdot \mathbf{p} + d}{\lVert \mathbf{n} \rVert}
$$

Leave $\mathbf{n}$ un-normalized and the numerator scales by $k$ while the geometry does not —
the reported distance is stretched by exactly that factor. Only the *sign* survives scaling
unharmed, which is why an un-normalized plane is still fine for a half-space test but not for a
measurement.

As $[\mathbf{n}_1, \mathbf{n}_2, \mathbf{n}_3]$ approaches zero without reaching it, the
configuration is degenerate in all but name: the planes are nearly parallel or nearly share a
line, and the true intersection point runs off toward infinity. Dividing by that shrinking
determinant amplifies whatever error is already in the inputs, so $\mathbf{p}$ blows up.

A robust implementation therefore does not test $\det \mathbf{A} = 0$ exactly — with floating
point it almost never will be — but compares $\lvert \det \mathbf{A} \rvert$ against a minimum
threshold and rejects the configuration below it. The threshold has to be **relative**, not a
fixed epsilon: because the normals need not be unit length, $\det \mathbf{A}$ can be made
arbitrarily large or small by rescaling planes that describe identical geometry. Normalizing
the three normals first, or comparing against
$\lVert \mathbf{n}_1 \rVert \lVert \mathbf{n}_2 \rVert \lVert \mathbf{n}_3 \rVert$, makes the
test mean the same thing regardless of how the planes were written down.

---
**Back to Question:** [Q_08_Intersection_Three_Planes](../Questions/Q_08_Intersection_Three_Planes.md) | **Related Concepts:** [08_Intersection_Three_Planes](../../../Concepts/05_Geometry/08_Intersection_Three_Planes.md)
