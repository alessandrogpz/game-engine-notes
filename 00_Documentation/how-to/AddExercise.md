# Add a New Exercise

Exercises come in pairs: a question note and a solution note, cross-linked to each other and to the concept they exercise.

---

## Create the pair

Copy the two templates in [99_Templates](../../99_Templates/README.md) into the topic's
`Questions/` and `Solutions/` folders, or insert them from inside Obsidian — see
[Use the templates](UseTemplates.md).

Name both after the concept note the exercise practises, carrying its number:

```
01_Mathematics/01_Linear_Algebra/Concepts/02_Vectors/06_Vector_Projection.md
01_Mathematics/01_Linear_Algebra/Exercises/02_Vectors/Questions/Q_06_Projection_Properties.md
01_Mathematics/01_Linear_Algebra/Exercises/02_Vectors/Solutions/S_06_Projection_Properties.md
```

The shared `06_` is what ties the pair to `06_Vector_Projection`. Several exercises may carry
the same number when they practise the same note.

## Write the question

Split the problem into two parts:

* **Part 1: Calculation** — concrete numbers to work through. Pick values that stay clean; fractions are fine, but arithmetic noise obscures the idea being tested.
* **Part 2: Conceptual Understanding** — why the method works, what breaks in degenerate cases, and where it shows up in an engine.

Fill in the frontmatter the template leaves blank:

```yaml
---
topic: Vectors
difficulty: Medium
tags: [exercise, question, vector-projection, orthogonality]
---
```

## Write the solution

Give the full derivation, not just the answer. State the conclusion of each step in bold so the note can be skimmed later as a reference.

Verify the arithmetic before committing — an exercise with a wrong answer is worse than no exercise.

## Bind it to the graph

Replace the placeholder names in both footers with the real files:

```markdown
**Check Answer:** [S_06_Projection_Properties](../Solutions/S_06_Projection_Properties.md) | **Related Concepts:** [06_Vector_Projection](../../../Concepts/02_Vectors/06_Vector_Projection.md)
```

Add the question to the subject index (`<Domain>/<Subject>/README.md`), in its topic's exercise list.

## Check it is discoverable

```bash
python3 randomizer.py vectors
```

The tool globs `*/*/Exercises/*/Questions/Q_*.md`, so a correctly placed and named question is picked up with no configuration. The count it reports should have gone up by one.

## Track it

If the solution is left unwritten, add a line to [TODO.md](../../TODO.md) so it is not forgotten.

---

## See also

* [Add a concept note](AddConceptNote.md)
* [Use the templates](UseTemplates.md)
* [Math formatting](../references/MathFormatting.md) — LaTeX that renders in both Obsidian and GitHub
* [Naming conventions](../references/NamingConventions.md)
