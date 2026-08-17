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
| `[label](relative/folder/)` | **Does not resolve** — offers to create a note | Browses the folder |

Wikilinks are an Obsidian extension rather than markdown, so GitHub does not interpret them.
Relative markdown links carry no such restriction and lose nothing in Obsidian.

---

## Never link a bare folder

Obsidian resolves a link target against **files**. A target ending in `/` matches no file, so
Obsidian treats it as an unresolved link: clicking it offers to create a new note of that name,
and accepting leaves a stray empty file behind.

GitHub renders the same link as a folder listing, which is why the problem is easy to miss —
the link looks correct on the surface where it is not read daily.

Link the folder's `README.md` explicitly instead:

```markdown
[00_Documentation](../00_Documentation/README.md)     ✓ resolves in both
[00_Documentation](../00_Documentation/)              ✗ Obsidian offers to create a note
```

This costs nothing on GitHub — browsing to a folder renders its `README.md` anyway, so the
explicit path lands on exactly the same page.

Every folder that is a link target therefore carries a `README.md` index. Where a folder holds
only leaf content and has no index — `Assets/`, `Exercises/<Topic>/Questions/` — link a
specific file inside it, or a heading anchor in the subject index, rather than the folder.

[`check_links.py`](../../scripts/check_links.py) reports folder targets separately from broken
ones, and CI fails on both.

---

## Trade-off

Wikilinks are location-independent: `[[02_Dot_Product]]` resolves from anywhere. Relative
links are position-dependent and break when either file moves.

Every move is therefore followed by a link-rewriting pass and
[`scripts/check_links.py`](../../scripts/check_links.py), which resolves every relative
target against the filesystem and exits non-zero on failure. CI runs it on each push.

---

## Transclusion

`![[Note]]` embeds one file's rendered content inside another. Markdown has no equivalent, so
it would render as literal text on GitHub.

Nothing in the vault uses it. It is available in Obsidian for scratch notes that are never
committed, but no committed file may rely on it.

---

## Conventions

See [Naming and note conventions](../references/NamingConventions.md) for link forms, and
[The Knowledge Graph](KnowledgeGraph.md) for what to link.
