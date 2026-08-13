When you create a new note for a math problem, press `Ctrl/Cmd + P`, type `Insert template`, and select your exercise template.

### Linking Strategy
* **Tags:** Use tags in the frontmatter (the `---` block at the top) for broad filtering (e.g., `#linear_algebra`, `#game_engine`, `#cpp`).
* **Links:** Use standard markdown links with a relative path at the bottom of the exercise to link it directly to the theoretical concept note, e.g. `[02_Dot_Product](../../../01_Concepts/02_Vectors/02_Dot_Product.md)`. This builds a graph where all your matrix exercises physically point back to your main "Matrix Transformations" note. Relative markdown links resolve in **both** Obsidian and GitHub, whereas `[[wikilinks]]` render as raw text on GitHub.
