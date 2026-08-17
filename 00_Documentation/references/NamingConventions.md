# Naming and Note Conventions

---

## File and folder names

| Item | Pattern | Example |
| :--- | :--- | :--- |
| Domain | `<NN>_<Title_Case>` | `08_Systems_and_Performance` |
| Subject | `<NN>_<Title_Case>` | `01_Data_Oriented_Design` |
| Topic folder | `<NN>_<Title_Case>` | `05_Geometry` |
| Concept note | `<NN>_<Title_Case>.md` | `04_Cross_Product.md` |
| Question | `Q_<NN>_<Name>.md` | `Q_05_Distance_Point_and_Plane.md` |
| Solution | `S_<NN>_<Name>.md` | `S_05_Distance_Point_and_Plane.md` |
| Domain roadmap | `00_Roadmap.md` | — |
| Folder index | `README.md` | — |
| Documentation | `PascalCase.md` | `AddExercise.md` |
| Asset | `lower_snake_case.webp` | `intersection_two_planes.webp` |

Connecting words stay lowercase: `05_Distance_Point_and_Plane`, not `05_Distance_Point_And_Plane`.

---

## Frontmatter

Question notes:

```yaml
---
topic: Geometry
difficulty: Medium
tags: [exercise, question, intersection-two-planes, cross-product]
---
```

Solution notes:

```yaml
---
topic: Geometry
tags: [exercise, solution, intersection-two-planes, cross-product]
---
```

`difficulty` is `Easy`, `Medium` or `Hard`, and is what `randomizer.py -d` filters on. Tags are what `-t` filters on, so keep them consistent across related exercises.

---

## Links

Use relative markdown links, never Obsidian `[[wikilinks]]`, and **never link a bare folder** —
see [why](../explanation/LinkFormat.md) for both. A target ending in `/` does not resolve in
Obsidian; link the folder's `README.md`.

Link the **first meaningful mention** of any subject that has its own note, not every occurrence, and never link a note's own subject back to itself.

| Context | Form |
| :--- | :--- |
| Concept reference | `[cross product](../02_Vectors/04_Cross_Product.md)` |
| Folder reference | `[00_Documentation](../../00_Documentation/README.md)` — never `.../00_Documentation/` |
| Domain reference | `[05_Data_Structures](../05_Data_Structures/README.md)` — the index, not the roadmap |
| Question footer | `**Check Answer:** [S_Name](../Solutions/S_Name.md) \| **Related Concepts:** [Note](../../../Concepts/<Topic>/Note.md)` |
| Solution footer | `**Back to Question:** [Q_Name](../Questions/Q_Name.md) \| **Related Concepts:** [Note](../../../Concepts/<Topic>/Note.md)` |
| Code reference | `* **C++ Source Code:** [File.cppm](../../../../90_Code/<Topic>/File.cppm)` |

---

## Formatting

* **Math** — LaTeX for mathematics; code spans for complexity and type notation such as `O(n log n)` or `std::vector`. Full rules in [Math formatting](MathFormatting.md).
* **Callouts** — GitHub alert syntax, which both Obsidian and GitHub render:

```markdown
> [!NOTE]
> [!IMPORTANT]
> [!WARNING]
```

* **Sections** — separate major sections with `---`.
* **Conclusions** — state the result of a derivation step in bold, so a solution can be skimmed as reference later.
