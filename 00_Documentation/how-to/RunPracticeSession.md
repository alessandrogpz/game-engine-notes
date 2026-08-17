# Run a Practice Session

Pick a question, solve it on paper, check it against the solution.

---

## Pick a question

From the repository root:

```bash
python3 randomizer.py
```

One question, drawn from anywhere in the vault. To stay inside a domain, subject or topic,
name it:

```bash
python3 randomizer.py mathematics          # anywhere in 01_Mathematics
python3 randomizer.py "linear algebra"     # anywhere in 01_Linear_Algebra
python3 randomizer.py geometry             # 05_Geometry only
```

Numeric prefixes are ignored and underscores read as spaces, so `vectors` finds `02_Vectors`.
If the scope matches nothing, the tool lists the ones it knows rather than silently widening
to the whole vault. Every flag is in the [randomizer reference](../references/Randomizer.md).

## Work it

Open the file it printed. Every question has two parts:

* **Part 1: Calculation** — work the numbers by hand. Writing the derivation out is the point.
* **Part 2: Conceptual Understanding** — why the method works, and what breaks in the
  degenerate cases.

## Check it

The **Check Answer** link at the bottom of the question opens the solution, which gives the
full derivation rather than just the result. From there, **Related Concepts** leads back to
the theory note the exercise came from.

That round trip — question, solution, concept — is the habit the vault is built around.

---

## See also

* [Randomizer reference](../references/Randomizer.md)
* [Add a new exercise](AddExercise.md) — when you find a problem worth keeping
