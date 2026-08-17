# Templates

| Template | Produces |
| :--- | :--- |
| [Template_Question.md](Template_Question.md) | `Q_<NN>_<Name>.md` — frontmatter, Part 1 calculation, Part 2 conceptual, footer to the solution |
| [Template_Solution.md](Template_Solution.md) | `S_<NN>_<Name>.md` — frontmatter and footer back to the question |

---

## Use

Copy both into the topic's `Questions/` and `Solutions/` folders, or insert them from inside
Obsidian — see [Use the Templates](../00_Documentation/how-to/UseTemplates.md). Then fill in
the frontmatter and replace the placeholder names in both footers with the real files, as
[Add a New Exercise](../00_Documentation/how-to/AddExercise.md) describes.

The placeholder links inside these two files point at names that do not exist, so
[check_links.py](../scripts/check_links.py) skips them by path.

Nothing else belongs in this folder.
