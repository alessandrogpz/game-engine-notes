# Add a New Exercise

Exercises come in pairs: a question note and a solution note, cross-linked to each other and to the concept they exercise.

---

## Scaffold the pair

```bash
python3 randomizer.py vectors --new Projection_Properties --difficulty Medium
```

This creates both files from the templates, pre-filled with frontmatter and the bidirectional links between them:

```
01_Mathematics/01_Linear_Algebra/Exercises/02_Vectors/Questions/Q_Projection_Properties.md
01_Mathematics/01_Linear_Algebra/Exercises/02_Vectors/Solutions/S_Projection_Properties.md
```

## Write the question

Split the problem into two parts:

* **Part 1: Calculation** — concrete numbers to work through. Pick values that stay clean; fractions are fine, but arithmetic noise obscures the idea being tested.
* **Part 2: Conceptual Understanding** — why the method works, what breaks in degenerate cases, and where it shows up in an engine.

## Write the solution

Give the full derivation, not just the answer. State the conclusion of each step in bold so the note can be skimmed later as a reference.

Verify the arithmetic before committing — an exercise with a wrong answer is worse than no exercise.

## Bind it to the graph

Replace the `Concept_Name` placeholder in both footers with the real concept note:

```markdown
**Check Answer:** [S_Projection_Properties](../Solutions/S_Projection_Properties.md) | **Related Concepts:** [06_Vector_Projection](../../../Concepts/02_Vectors/06_Vector_Projection.md)
```

## Track it

If the solution is left unwritten, add a line to [TODO.md](../../TODO.md) so it is not forgotten.

---

## See also

* [Add a concept note](AddConceptNote.md)
* [Math formatting](../references/MathFormatting.md) — LaTeX that renders in both Obsidian and GitHub
* [Naming conventions](../references/NamingConventions.md)
