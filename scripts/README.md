# Scripts

| Script | Enforces |
| :--- | :--- |
| [check_links.py](check_links.py) | Every relative link and image source resolves, **and none points at a folder** |
| [check_math.py](check_math.py) | LaTeX renders on GitHub, not only in Obsidian |

```bash
python3 scripts/check_links.py
python3 scripts/check_math.py
```

Run both from the repository root — they scope to `git ls-files`, which is relative to the
working directory.

---

## Why these two

Both catch failures that are **invisible in Obsidian**.

A link pointing at a folder browses fine on GitHub, so it looks correct there, but Obsidian
resolves links against files only — clicking one offers to create a new note. `check_links.py`
reports those separately from genuinely broken targets. See
[Link Format](../00_Documentation/explanation/LinkFormat.md).

Obsidian's math renderer is permissive; GitHub's is strict and fails loudly, replacing a whole
equation with an error box. Local preview therefore proves nothing. See
[Math Formatting](../00_Documentation/references/MathFormatting.md).

---

## Related

* [randomizer.py](../randomizer.py) — picks one random question to practise, documented in
  [Randomizer](../00_Documentation/references/Randomizer.md)
