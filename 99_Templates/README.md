# Templates

The two files [randomizer.py](../randomizer.py) reads when scaffolding an exercise pair.
Nothing else belongs in this folder — the scaffolder copies whatever it finds here verbatim.

| Template | Produces |
| :--- | :--- |
| [Template_Question.md](Template_Question.md) | `Q_<NN>_<Name>.md` — frontmatter, Part 1 calculation, Part 2 conceptual, footer to the solution |
| [Template_Solution.md](Template_Solution.md) | `S_<NN>_<Name>.md` — frontmatter and footer back to the question |

---

## Use

Scaffold both halves of a pair at once rather than copying by hand — the tool fills in the
frontmatter and both footers:

```bash
python3 randomizer.py <topic> --new <Name> --difficulty <Easy|Medium|Hard>
```

Then replace the `Concept_Name` placeholder in both footers with the real concept note.

The placeholder links inside these two files point at names that do not exist, so
[check_links.py](../scripts/check_links.py) skips them by path.

---

## Related

* [Add a New Exercise](../00_Documentation/how-to/AddExercise.md) — the full workflow
* [Use the Templates](../00_Documentation/how-to/UseTemplates.md) — inserting one by hand from Obsidian
* [Naming Conventions](../00_Documentation/references/NamingConventions.md) — frontmatter and footer forms
