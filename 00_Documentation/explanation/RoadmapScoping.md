# Why Roadmaps Say What to Skip

Every domain here carries a `00_Roadmap.md`. Each one names the subjects to cover, the resources worth using, and — for the broad academic fields — **what to deliberately leave out**.

The exclusions are the load-bearing part.

---

## The problem they solve

Most of these domains are full academic fields. Calculus, probability, algorithms and signal processing each contain vastly more material than an engine needs. Treated as complete curricula, any one of them absorbs a year and none of them finish.

A roadmap that only lists what to study is a wish. A roadmap that also states what *not* to study is a plan.

---

## What the scoping looks like

**Calculus** — study derivatives, gradients, Jacobians, integrals as accumulation, Taylor series, and ODEs solved numerically. Skip epsilon-delta proofs, series convergence tests, Calculus II integration techniques and real analysis. Engines integrate numerically, never symbolically.

**Probability** — study sampling, importance sampling, variance reduction, low-discrepancy sequences. Skip hypothesis testing, confidence intervals and regression; that is inferential statistics, a different discipline serving a different question.

**Algorithms** — emphasize computational geometry and pathfinding. De-emphasize NP-completeness theory, advanced dynamic programming and string algorithms. A standard algorithms curriculum is calibrated for interviews and theory, not for engines.

**Data structures** — emphasize contiguous layouts and spatial structures. De-emphasize red-black tree rotations and Fibonacci heaps. An engine optimizes for a known access pattern over contiguous memory, where a linked list with perfect asymptotics loses badly to a vector that fits in cache.

---

## The reasoning

Scope is set by the question *"what does an engine actually run?"* — not by what a textbook's table of contents covers.

That test is what makes the exclusions defensible rather than lazy. Skipping real analysis is not avoiding difficulty; it is recognizing that no engine has ever needed an epsilon-delta proof. Meanwhile numerical methods — often skipped as unglamorous — is flagged as the highest value-per-hour subject in the mathematics domain, because floating-point behaviour and integrator stability are behind a large share of otherwise inexplicable engine bugs.

---

## Marking things optional rather than deleting them

Some material is genuinely worthwhile but genuinely not required. Geometric algebra is the clearest case: it unifies the intersection formulas already derived in the geometry notes into a single operation, and it is intellectually excellent — but no mainstream engine is built on it.

Rather than silently dropping it, the roadmap keeps it as an explicitly optional subject and records **what would make it worth returning to**. That way the decision is recorded rather than re-litigated every time the topic resurfaces.

---

## Status markers

Roadmaps also carry status. A subject is marked *in progress* once it has real notes, and the roadmap links to them directly instead of describing them.

This keeps the roadmap honest as the domain fills in: it starts as a plan and gradually becomes an index.
