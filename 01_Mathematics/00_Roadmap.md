# Mathematics — Study Roadmap

The mathematics an engine actually runs on. [01_Linear_Algebra](01_Linear_Algebra/README.md) is complete; this roadmap covers the remaining subjects and, crucially, **how much of each is worth learning**.

What already exists in this domain is indexed in [README.md](README.md); this file is the plan for what does not.

> [!IMPORTANT]
> Every subject here is a full academic field. An engine needs a specific slice of each. The "Skip" sections are as important as the "Study" sections — they are what keeps this finite.

---

## 02_Calculus

Needed for lighting models, physics integration, optimization, and anything continuous that gets sampled.

**Study:**
* **Derivatives** — rate of change, chain rule. Underpins normals, shading, and every optimizer.
* **Partial derivatives and gradients** — the gradient is the surface normal of an implicit surface, and the direction of steepest descent.
* **Jacobians** — how a transformation distorts area/volume locally. Shows up in texture filtering (derivatives of UV) and change of variables.
* **Integrals as accumulation** — the rendering equation is an integral; you need to *read* it fluently more than solve it analytically.
* **Taylor series** — the justification for every fast approximation you will write.
* **Ordinary differential equations, numerically** — `F = ma` is an ODE. Euler, semi-implicit Euler, Verlet, RK4.

**Skip:** epsilon-delta proofs, convergence tests for infinite series, most Calculus II integration techniques (trig substitution, partial fractions), real analysis. Engines integrate numerically, not symbolically.

**Resources:** 3Blue1Brown *Essence of Calculus* for intuition; Paul's Online Math Notes for mechanics.

---

## 03_Numerical_Methods

The highest value-per-hour subject on this list, and the one most often skipped. Nearly every "mysterious" engine bug is a numerical one.

**Study:**
* **Floating point** — IEEE 754, precision loss, catastrophic cancellation, why `==` is a trap, ULP-based comparison. Read *What Every Computer Scientist Should Know About Floating-Point Arithmetic* (Goldberg).
* **Conditioning and stability** — why a near-parallel line/plane test explodes.
* **Root finding** — Newton–Raphson, bisection, and their failure modes.
* **ODE integrators** — accuracy vs stability vs energy behaviour. Why games use semi-implicit Euler and Verlet rather than RK4.
* **Iterative linear solvers** — Gauss–Seidel and projected Gauss–Seidel, the basis of constraint solvers.

**Skip:** most of classical numerical analysis (quadrature rules, interpolation theory, PDE methods) unless you write a fluid or cloth solver.

---

## 04_Probability_and_Statistics

Needed for Monte Carlo rendering and procedural content.

**Study:** probability distributions, expected value, variance; sampling and inverse transform sampling; importance sampling; variance reduction; low-discrepancy sequences (Halton, Sobol); the law of large numbers as the reason path tracing converges.

**Skip:** hypothesis testing, confidence intervals, regression, most inferential statistics. Different discipline entirely.

---

## 05_Signal_Processing

The theory behind aliasing, which is the root cause of a surprising share of visual artifacts.

**Study:** sampling theorem and Nyquist; aliasing and pre-filtering; convolution and filter kernels; reconstruction; mipmapping as pre-filtering; the Fourier transform conceptually (what a frequency domain *is*), plus FFT if you touch audio.

**Skip:** analog filter design, z-transforms, control theory.

---

## 06_Geometric_Algebra *(optional)*

Grassmann algebra, bivectors and Plücker coordinates — Chapter 4 of Lengyel Volume 1, deliberately deferred.

Unifies the intersection formulas already derived in [05_Geometry](01_Linear_Algebra/README.md#05_geometry) into a single operation, and generalizes quaternions to include translation (motors). Intellectually excellent, practically optional: no mainstream engine is built on it, and the pieces that proved their worth — quaternions, dual quaternions — were absorbed under other names.

Good triggers to come back: writing watertight ray–triangle intersection, or wanting to know why all those formulas rhyme.

---

## Suggested Order

1. **Numerical Methods** — immediately useful, and retroactively explains bugs in code already written.
2. **Calculus** — as far as gradients and numerical ODEs.
3. **Signal Processing** — before or alongside texture filtering and antialiasing work.
4. **Probability** — when reaching Monte Carlo / path tracing.
5. **Geometric Algebra** — whenever curiosity strikes.
