# Use the Templates

Exercise notes are scaffolded from the templates in `99_Templates/`. The [randomizer](../references/Randomizer.md) fills them in automatically with `--new`; this describes using them by hand from inside Obsidian.

---

When you create a new note for a math problem, press `Ctrl/Cmd + P`, type `Insert template`, and select your exercise template.

## Linking Strategy
* **Tags:** Use tags in the frontmatter (the `---` block at the top) for broad filtering (e.g., `#geometry`, `#cross-product`, `#cpp`).
* **Links:** Use standard markdown links with a relative path at the bottom of the exercise to link it directly to the theoretical concept note, e.g. `[02_Dot_Product](../../../Concepts/02_Vectors/02_Dot_Product.md)`. This builds a graph where all your matrix exercises physically point back to your main "Matrix Transformations" note. Relative markdown links resolve in **both** Obsidian and GitHub, whereas `[[wikilinks]]` render as raw text on GitHub.


---

## See also

* [Add a new exercise](AddExercise.md) — the scaffolded route
* [Naming conventions](../references/NamingConventions.md) — frontmatter and footer forms
