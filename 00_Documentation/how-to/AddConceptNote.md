# Add a Concept Note

Concept notes are the theory half of the vault — the thing exercises point back to.

---

## Create the file

Place it in the subject's `Concepts/<NN_Topic>/` folder, named `<NN>_<Title_Case>.md`:

```
01_Mathematics/01_Linear_Algebra/Concepts/05_Geometry/06_Reflection_Through_Plane.md
```

The number orders it within the topic; keep it in the order the material is best learned.

## Structure it

1. An `# H1` title matching the concept.
2. A short opening that states what the concept is, before any derivation.
3. Figures where geometry is involved — see [Add a figure](AddFigure.md).
4. `---` between major sections.
5. A **Code Implementation** section at the end pointing at the matching `.cppm`, if one exists.

## Link it into the graph

Link the **first mention** of any subject that already has a note elsewhere in the vault, using a relative markdown link:

```markdown
the [cross product](../02_Vectors/04_Cross_Product.md) produces exactly the vector orthogonal to both
```

Link the first meaningful mention only, not every occurrence, and never link the note's own subject back to itself. Cross-domain links are encouraged — a rendering note pointing at a linear algebra proof is exactly the point.

## Follow the math rules

Display math must sit at column 0 with blank lines around it, and matrix rows break with `\\\\`. The full rules are in [Math formatting](../references/MathFormatting.md); ignoring them produces notes that look fine in Obsidian and break on GitHub.

---

## See also

* [Add an exercise](AddExercise.md) — to give the concept something to practise against
* [The knowledge graph](../explanation/KnowledgeGraph.md)
