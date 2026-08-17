# Templates

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
