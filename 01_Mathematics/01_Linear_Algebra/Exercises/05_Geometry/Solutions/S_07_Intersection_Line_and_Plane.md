---
topic: Geometry
tags: [exercise, solution, intersection-line-plane, implicit-plane, parametric-line]
---

# Solution: Intersection of a Line and a Plane

This solution note details the step-by-step calculations and conceptual answers for the line-plane intersection exercise.

---

## Part 1: Calculation

### Question 1: Intersection Against a Normalized Plane

A plane is given by the normalized vector $\mathbf{f} = [0, 0, 1, -5]$, and a line by $L(t) = \mathbf{p} + t\mathbf{v}$ with $\mathbf{p} = (1, 2, 1)$ and $\mathbf{v} = \langle 1, 1, 2 \rangle$.

#### 1. Evaluating the Dot Products

For the line to be **parallel** to the plane, we would need $\mathbf{n} \cdot \mathbf{v} = 0$. Testing with $\mathbf{n} = (0, 0, 1)$:

$$
\mathbf{n} \cdot \mathbf{v} = 0(1) + 0(1) + 1(2) = 2
$$

Since $\mathbf{n} \cdot \mathbf{v} = 2 \neq 0$, the line is guaranteed **not parallel** to the plane, so exactly one intersection exists.

$$
\mathbf{f} \cdot \mathbf{p} = 0(1) + 0(2) + 1(1) + (-5)(1) = -4
$$

$$
\mathbf{f} \cdot \mathbf{v} = 0(1) + 0(1) + 1(2) + (-5)(0) = 2
$$

* $\mathbf{f} \cdot \mathbf{p} = -4$ is a **4D calculation**, because $w = 1$ for a point, so the term $d = -5$ contributes.
* $\mathbf{f} \cdot \mathbf{v} = 2$ is effectively a **3D calculation**, because $w = 0$ for a direction, so $d$ is annihilated and the result equals $\mathbf{n} \cdot \mathbf{v}$.

#### 2. Solving for the Parameter $t$

$$
\mathbf{f} \cdot (\mathbf{p} + t\mathbf{v}) = 0 \implies (\mathbf{f} \cdot \mathbf{p}) + t(\mathbf{f} \cdot \mathbf{v}) = 0
$$

$$
-4 + t(2) = 0 \implies t = 2
$$

#### 3. The Intersection Point

$$
\mathbf{q} = \mathbf{p} + t\mathbf{v} = (1, 2, 1) + 2\langle 1, 1, 2 \rangle = (3, 4, 5)
$$

Verifying the result by confirming $\mathbf{f} \cdot \mathbf{q} = 0$:

$$
\mathbf{f} \cdot \mathbf{q} = 0(3) + 0(4) + 1(5) + (-5)(1) = 0
$$

* **Conclusion:** The line meets the plane at $\mathbf{q} = (3, 4, 5)$, which satisfies the plane equation exactly.

---

### Question 2: A Non-Normalized Plane

A non-normalized plane $\mathbf{f} = [2, -1, 2, -12]$ is given, with a line defined by $\mathbf{p} = (1, 1, 1)$ and $\mathbf{v} = \langle 1, 0, 1 \rangle$.

#### 1. Computing $t$ and $\mathbf{q}$ Without Normalizing

$$
\mathbf{f} \cdot \mathbf{p} = 2(1) - 1(1) + 2(1) - 12(1) = -9
$$

$$
\mathbf{f} \cdot \mathbf{v} = 2(1) - 1(0) + 2(1) - 12(0) = 4
$$

$$
t = -\frac{\mathbf{f} \cdot \mathbf{p}}{\mathbf{f} \cdot \mathbf{v}} = -\frac{-9}{4} = \frac{9}{4}
$$

$$
\mathbf{q} = \mathbf{p} + t\mathbf{v} = (1, 1, 1) + \frac{9}{4}\langle 1, 0, 1 \rangle = \left( \frac{13}{4}, 1, \frac{13}{4} \right)
$$

Verifying $\mathbf{f} \cdot \mathbf{q} = 0$:

$$
\mathbf{f} \cdot \mathbf{q} = 2\left( \frac{13}{4} \right) - 1(1) + 2\left( \frac{13}{4} \right) - 12(1) = \frac{26}{4} + \frac{26}{4} - 13 = 13 - 13 = 0
$$

#### 2. Recomputing From the Normalized Plane

$$
\|\mathbf{n}\| = \sqrt{2^2 + (-1)^2 + 2^2} = \sqrt{9} = 3
$$

$$
\mathbf{f}_{\text{norm}} = \frac{\mathbf{f}}{\|\mathbf{n}\|} = \left[ \frac{2}{3}, -\frac{1}{3}, \frac{2}{3}, -4 \right]
$$

$$
\mathbf{f}_{\text{norm}} \cdot \mathbf{p} = \frac{2}{3} - \frac{1}{3} + \frac{2}{3} - 4 = 1 - 4 = -3
$$

$$
\mathbf{f}_{\text{norm}} \cdot \mathbf{v} = \frac{2}{3} - \frac{1}{3}(0) + \frac{2}{3} = \frac{4}{3}
$$

$$
t = -\frac{-3}{\frac{4}{3}} = 3 \cdot \frac{3}{4} = \frac{9}{4}
$$

#### 3. Comparison

* **Conclusion:** Both routes yield the same $t = \frac{9}{4}$, so **normalization is not necessary** for this calculation. Dividing the plane by $\|\mathbf{n}\| = 3$ divided the numerator and the denominator by the same factor, and the ratio absorbed it.

This contrasts sharply with the [point-plane distance](../../../Concepts/05_Geometry/05_Distance_Point_and_Plane.md), which is a single [dot product](../../../Concepts/02_Vectors/02_Dot_Product.md) rather than a ratio. There, $\mathbf{f} \cdot \mathbf{p} = D\|\mathbf{n}\|$, so any scale left in $\mathbf{f}$ passes straight through into the answer and corrupts the measured length. A ratio cancels scale; a lone dot product does not.

---

### Question 3: Classifying Parallel Lines

Using the plane $\mathbf{f} = [0, 0, 1, -5]$, where $\mathbf{n} = (0, 0, 1)$.

#### 1. $\mathbf{p} = (0, 0, 2)$, $\mathbf{v} = \langle 1, 1, 0 \rangle$

If $\mathbf{n} \cdot \mathbf{v} = 0$, then the line is parallel to the plane:

$$
\mathbf{n} \cdot \mathbf{v} = (0, 0, 1) \cdot \langle 1, 1, 0 \rangle = 0
$$

The line is therefore parallel to $\mathbf{f}$. Now that we know it is parallel, we need to check whether it is *contained in* the plane or lies fully outside it. If $\mathbf{f} \cdot \mathbf{p} = 0$, the line is in the plane:

$$
\mathbf{f} \cdot \mathbf{p} = (0, 0, 1, -5) \cdot (0, 0, 2, 1) = 2 - 5 = -3
$$

* **Conclusion:** $\mathbf{f} \cdot \mathbf{p} = -3 \neq 0$, so the line lies **outside** the plane. It runs parallel at a constant signed distance of $-3$ and **never intersects** — there is no solution for $t$.

#### 2. $\mathbf{p} = (0, 0, 5)$, $\mathbf{v} = \langle 1, 1, 0 \rangle$

$$
\mathbf{n} \cdot \mathbf{v} = (0, 0, 1) \cdot \langle 1, 1, 0 \rangle = 0
$$

The line is also parallel to the plane. Checking the starting point:

$$
\mathbf{f} \cdot \mathbf{p} = (0, 0, 1, -5) \cdot (0, 0, 5, 1) = 5 - 5 = 0
$$

Attempting to solve for $t$ produces an **indeterminate** form rather than a value:

$$
t = -\frac{\mathbf{f} \cdot \mathbf{p}}{\mathbf{f} \cdot \mathbf{v}} = -\frac{0}{0}
$$

The indeterminacy is the correct signal here. Substituting back into the intersection condition shows why every $t$ works:

$$
\mathbf{f} \cdot L(t) = (\mathbf{f} \cdot \mathbf{p}) + t(\mathbf{f} \cdot \mathbf{v}) = 0 + t(0) = 0 \quad \text{for all } t
$$

* **Conclusion:** The line starts *on* the plane ($\mathbf{f} \cdot \mathbf{p} = 0$) and never leaves it ($\mathbf{f} \cdot \mathbf{v} = 0$ means travelling along $\mathbf{v}$ changes the signed distance by nothing). The whole line is **contained within** the plane, giving **infinitely many** intersection points rather than one.

---

### Question 4: Ray Intersection and Direction

A ray starts at $\mathbf{p} = (0, 0, 8)$ against the plane $\mathbf{f} = [0, 0, 1, -5]$.

#### 1. Direction $\mathbf{v} = \langle 0, 0, 1 \rangle$

$$
\mathbf{f} \cdot \mathbf{v} = (0, 0, 1) \cdot \langle 0, 0, 1 \rangle = 1
$$

$$
\mathbf{f} \cdot \mathbf{p} = 0(0) + 0(0) + 1(8) + (-5)(1) = 3
$$

The ray starts $3$ units in **front** of the plane. Solving for $t$:

$$
t = -\frac{3}{1} = -3
$$

* **Conclusion:** The **ray does not intersect** the plane, because $t = -3 < 0$ places the crossing behind the ray's start position. The **infinite line does** still hit the plane at $t = -3$ — the intersection exists mathematically, but it lies in the direction the ray is travelling away from.

#### 2. Direction $\mathbf{v} = \langle 0, 0, -1 \rangle$

$$
\mathbf{f} \cdot \mathbf{v} = (0, 0, 1) \cdot \langle 0, 0, -1 \rangle = -1
$$

$$
\mathbf{f} \cdot \mathbf{p} = 3 \quad \text{(the ray still starts in front of the plane)}
$$

$$
t = -\frac{3}{-1} = 3
$$

Since $t = 3 \ge 0$, the intersection is valid:

$$
\mathbf{q} = \mathbf{p} + t\mathbf{v} = (0, 0, 8) + 3\langle 0, 0, -1 \rangle = (0, 0, 5)
$$

#### 3. Which Sign Conditions the Results Confirm

Both cases start in front of the plane ($\mathbf{f} \cdot \mathbf{p} = 3 > 0$) and differ only in direction, isolating the role of the denominator:

* $\mathbf{f} \cdot \mathbf{v} > 0$ gave $t < 0$ — the ray travels **along** the normal, away from the front face, and misses.
* $\mathbf{f} \cdot \mathbf{v} < 0$ gave $t > 0$ — the ray travels **against** the normal, back toward the front face, and hits.

* **Conclusion:** For a ray starting in front of the plane ($\mathbf{f} \cdot \mathbf{p} > 0$), a valid hit requires $\mathbf{f} \cdot \mathbf{v} < 0$. The formula makes this automatic: a positive numerator over a negative denominator is the only way to produce $t = -\frac{(+)}{(-)} > 0$.

---

## Part 2: Conceptual Understanding

### 1. Why $\mathbf{f} \cdot \mathbf{p}$ is 4D While $\mathbf{f} \cdot \mathbf{v}$ Collapses to 3D

The difference comes entirely from the fourth component each operand carries, because the fourth component of the plane is $d$.

For **points** as a 4D element, $w$ is represented as $1$, which in a dot product carries real importance, since it multiplies the corresponding fourth element ($d$) by $1$ and therefore preserves it. For a **direction vector**, the $w$ component is $0$, which in a dot product transforms into $0$ any component it is multiplied by — so $d$ is annihilated and only the $\mathbf{n} \cdot \mathbf{v}$ part survives:

$$
\mathbf{f} \cdot \mathbf{p} = \mathbf{n} \cdot \mathbf{p} + d(1) = \mathbf{n} \cdot \mathbf{p} + d
$$

$$
\mathbf{f} \cdot \mathbf{v} = \mathbf{n} \cdot \mathbf{v} + d(0) = \mathbf{n} \cdot \mathbf{v}
$$

The underlying reason is geometric: points have an absolute position in space ($w = 1$), while vectors do not ($w = 0$). $d$ encodes *where* the plane sits relative to the origin, so it is meaningful only when asking about a location. A direction has no location, so the offset of the plane cannot affect it — which is exactly why the denominator measures only the line's orientation relative to the plane, and the numerator measures its displacement.

---

### 2. Proving that Scaling $\mathbf{f}$ Leaves $t$ Unchanged

Let $\mathbf{f}' = s\mathbf{f}$ for some non-zero factor $s$, and let $t'$ be the parameter it produces:

$$
t = -\frac{\mathbf{f} \cdot \mathbf{p}}{\mathbf{f} \cdot \mathbf{v}}, \qquad t' = -\frac{(s\mathbf{f}) \cdot \mathbf{p}}{(s\mathbf{f}) \cdot \mathbf{v}}
$$

Because the dot product is linear, the scalar factors straight out of both the numerator and the denominator:

$$
t' = -\frac{s(\mathbf{f} \cdot \mathbf{p})}{s(\mathbf{f} \cdot \mathbf{v})} = -\frac{\mathbf{f} \cdot \mathbf{p}}{\mathbf{f} \cdot \mathbf{v}} = t
$$

* **Conclusion:** $t = t'$ for every non-zero $s$. The intersection parameter is scale-invariant.

#### Why the Point-Plane Distance Does Not Share This

The distance formula is a **single dot product**, not a ratio, so there is no second factor of $s$ to cancel against:

$$
\mathbf{f} \cdot \mathbf{p} = D\|\mathbf{n}\|
$$

Scaling $\mathbf{f}$ scales the reported distance by exactly the same amount, which is precisely why the plane must be normalized before the result can be read as a physical length.

Even if the scaled plane is re-normalized afterwards, the recovery is not perfect, because normalizing divides by $\|s\mathbf{n}\| = |s|\|\mathbf{n}\|$ — an **absolute** value:

$$
\frac{s\mathbf{f}}{\|s\mathbf{n}\|} = \frac{s}{|s|} \cdot \frac{\mathbf{f}}{\|\mathbf{n}\|}
$$

For $s > 0$ the factor $\frac{s}{|s|}$ is $1$ and the distance is unchanged, but for $s < 0$ it is $-1$ and **the sign flips**: the normal is reversed, so front and back swap. The intersection ratio is immune to this because it divides two quantities that both flipped sign, whereas the distance keeps the flip.

---

### 3. The Two Cases Hidden Behind a Vanishing Denominator

If $\mathbf{f} \cdot \mathbf{v} = 0$, it means the line is **parallel** to the plane — but it could be either inside the plane or outside it, and we cannot determine which from $\mathbf{f} \cdot \mathbf{v}$ alone. The value of $\mathbf{f} \cdot \mathbf{p}$ is what separates them, because it reports whether the line's starting point already satisfies the plane equation:

| Case | Meaning |
| :--- | :--- |
| $\mathbf{f} \cdot \mathbf{v} = 0$ and $\mathbf{f} \cdot \mathbf{p} = 0$ | The point is contained in the plane, and since the line never leaves it, the **whole line is contained in the plane** — infinitely many intersections. |
| $\mathbf{f} \cdot \mathbf{v} = 0$ and $\mathbf{f} \cdot \mathbf{p} \neq 0$ | The line is parallel but sits off the plane at a constant distance — **no intersection**. |

#### How a Robust Implementation Should Report Each Case

A robust implementation would **first check $\mathbf{f} \cdot \mathbf{v}$**. If it differs from $0$, we know we have exactly one point of intersection and the division is safe to perform. Otherwise we check $\mathbf{f} \cdot \mathbf{p}$ to distinguish no intersection (line parallel and outside the plane) from infinitely many intersections (line parallel and inside the plane).

Critically, the ordering matters: the denominator must be tested **before** dividing, never after, since the division would otherwise produce a division-by-zero or a meaningless infinity. These are three genuinely different outcomes — one point, no points, every point — so the function should report them as distinct states rather than returning a single number.

> [!IMPORTANT]
> In floating-point code, neither test should compare against exact zero. A line that is very nearly parallel produces a denominator close to zero and a wildly unstable $t$, so both checks belong behind an epsilon comparison such as the repository's shared `util::floatEqual` helper.

---

### 4. The Ray Conditions and Backface Culling

$\mathbf{f} \cdot \mathbf{v}$ reflects whether the ray is travelling toward the front or the back of the plane, while $\mathbf{f} \cdot \mathbf{p}$ reports which side the ray *starts* on. The two are independent, and a valid hit needs both.

**What the direction test rejects.** For a ray starting in front of the plane:

* $\mathbf{f} \cdot \mathbf{v} < 0$ — the ray travels against the normal, back toward the front face, so it approaches the plane.
* $\mathbf{f} \cdot \mathbf{v} > 0$ — the ray travels along the normal, away from the front face, so it recedes and can never arrive.

**What the parameter test rejects.**

* $t > 0$ — the plane lies ahead of the ray's origin; the hit is real.
* $t < 0$ — the intersection lies behind the ray's start position, so the ray is facing away from the plane and the hit is discarded.
* $t = 0$ — the ray starts exactly on the plane.

In a real simulation scenario, we are only concerned with rays that begin between the observer and the plane (or start on it), travelling in a direction that faces the plane.

* **Preferred scenario:** $t \ge 0$ **and** $\mathbf{f} \cdot \mathbf{v} < 0$.

#### Why $\mathbf{f} \cdot \mathbf{v} < 0$ is a Backface Cull

The sign of $\mathbf{f} \cdot \mathbf{v}$ is the angle relationship between the ray and the surface normal. When it is negative, the ray opposes the normal and therefore strikes the surface's **front** face. When it is positive, the ray arrives from behind and would strike the **back** face — exactly the surfaces a renderer discards. Rejecting $\mathbf{f} \cdot \mathbf{v} > 0$ is therefore the same operation as backface culling, expressed as a single sign test. See [Normal Vectors](../../../Concepts/05_Geometry/02_Normal_Vectors.md) for why consistent winding order is what makes that normal point outward in the first place.

#### Why Testing Signs Before Dividing is Preferable

We prefer testing the sign first because unless $\mathbf{f} \cdot \mathbf{v} < 0$, it is not worth calculating $t$ at all — the surface is facing away and the result would be discarded regardless.

The performance argument reinforces it: computing $\mathbf{f} \cdot \mathbf{v}$ requires only multiplications and additions, which map onto a single fused multiply-add pipeline, whereas computing $t$ additionally requires a **division** — substantially more expensive on a CPU than multiply-add, and not pipelined in the same way. Since ray casts run per-pixel or per-object across a whole scene, rejecting a surface with a couple of multiply-adds instead of a division is a large aggregate saving.

The correctness argument matters even more than the speed: the sign test is what **guarantees** the denominator is non-zero, so the division that follows can never fault or return an infinity.

---

**Back to Question:** [Q_07_Intersection_Line_and_Plane](../Questions/Q_07_Intersection_Line_and_Plane.md) | **Related Concepts:** [07_Intersection_Line_and_Plane](../../../Concepts/05_Geometry/07_Intersection_Line_and_Plane.md)
