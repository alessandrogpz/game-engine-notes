# Link Format

Cross-references use standard markdown links with relative paths.

```markdown
the [cross product](../02_Vectors/04_Cross_Product.md) produces ...
```

---

## Surfaces

Notes are read in two places, and the link syntax must work in both.

| Syntax | Obsidian | GitHub |
| :--- | :--- | :--- |
| `[label](relative/path.md)` | Resolves; counted in Graph View and backlinks | Renders as a link |
| `[[wikilink]]` | Resolves | Renders as literal text, brackets included |

Wikilinks are an Obsidian extension rather than markdown, so GitHub does not interpret them.
Relative markdown links carry no such restriction and lose nothing in Obsidian.

---

## Trade-off

Wikilinks are location-independent: `[[02_Dot_Product]]` resolves from anywhere. Relative
links are position-dependent and break when either file moves.

Every move is therefore followed by a link-rewriting pass and
[`scripts/check_links.py`](../../scripts/check_links.py), which resolves every relative
target against the filesystem and exits non-zero on failure. CI runs it on each push.

---

## Transclusion

`![[Note]]` embeds one file's rendered content inside another. Markdown has no equivalent.

It appears only in the generated `Daily_Practice.md`, which is gitignored and read only in
Obsidian.

---

## Conventions

See [Naming and note conventions](../references/NamingConventions.md) for link forms, and
[The Knowledge Graph](KnowledgeGraph.md) for what to link.
