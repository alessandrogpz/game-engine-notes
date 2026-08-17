# Roadmap Scoping

Every domain carries a `00_Roadmap.md` naming the subjects to cover, the resources to use,
and — for broad academic fields — the material to leave out.

---

## Scope is set by use

The selection criterion is what an engine runs, not what a textbook's table of contents
covers.

Calculus, probability, algorithms and signal processing each contain far more material than
an engine uses. Stating only what to study leaves each of them unbounded; stating what to
exclude bounds them.

---

## Worked scopes

**Calculus** — derivatives, gradients, Jacobians, integrals as accumulation, Taylor series,
ODEs solved numerically. Excluded: epsilon-delta proofs, series convergence tests, Calculus
II integration techniques, real analysis. Engines integrate numerically.

**Probability** — sampling, importance sampling, variance reduction, low-discrepancy
sequences. Excluded: hypothesis testing, confidence intervals, regression.

**Algorithms** — computational geometry and pathfinding carry the weight. De-emphasized:
NP-completeness theory, advanced dynamic programming, string algorithms.

**Data structures** — contiguous layouts and spatial structures. De-emphasized: balanced BST
rotations, exotic heaps. An engine's workload is a known access pattern over contiguous
memory.

Numerical methods is marked highest value-per-hour in the mathematics domain: floating-point
behaviour and integrator stability account for a large share of engine defects.

---

## Optional subjects

Material that is worthwhile but not required is marked optional and kept, together with the
conditions that would make it worth studying.

Geometric algebra is the current example: it unifies the intersection formulas in the
geometry notes into a single operation, and no mainstream engine is built on it.

---

## Status

A subject is marked *in progress* once it has notes, and the roadmap links to them directly
rather than describing them.

A roadmap does **not** become the domain's index, though. That is what
`<Domain>/README.md` is for, and it is where the root README links: an inventory of what
exists, which links on to the roadmap for what does not.

Keeping them separate keeps each honest. A roadmap that doubles as an index accumulates
completed material until the scoping decisions — the "Skip" sections that are the point of the
file — are buried under a list of finished work. See
[Vault Organization](VaultOrganization.md).
