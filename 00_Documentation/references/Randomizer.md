# Randomizer

Picks one random question to practise. That is the whole tool.

```bash
python3 randomizer.py [scope]
```

Run it from the repository root — it discovers questions by globbing
`*/*/Exercises/*/Questions/Q_*.md`, which is relative to the working directory.

---

## The scope argument

Optional. Without it, the pick is from every question in the vault. With it, the pick is
restricted to a **domain**, a **subject** or a **topic** — whichever the argument names.

| Command | Picks from |
| :--- | :--- |
| `python3 randomizer.py` | Every question in the vault |
| `python3 randomizer.py mathematics` | Every subject in `01_Mathematics` |
| `python3 randomizer.py "linear algebra"` | Every topic in `01_Linear_Algebra` |
| `python3 randomizer.py vectors` | `02_Vectors` only |

Matching ignores numeric prefixes and reads underscores as spaces, so `02_Vectors` answers to
`vectors`, and `01_Linear_Algebra` to `linear algebra`, `linear_algebra` or `linear`. An exact
name wins over a substring; failing both, any scope containing the query matches.

## Output

The question name, how many were in scope, and the path:

```
Q_09_Intersection_Two_Planes  (10 available in geometry)
01_Mathematics/01_Linear_Algebra/Exercises/05_Geometry/Questions/Q_09_Intersection_Two_Planes.md
```

## When nothing matches

The tool exits non-zero and lists every scope it does know, rather than quietly falling back
to the whole vault:

```
Nothing matches 'rendering'.

Available scopes:
  geometry
  linear algebra
  mathematics
  matrices
  systems of equations
  transforms
  vectors
```

---

## What it does not do

Filtering by difficulty or tag, picking several questions at once, scaffolding new exercise
pairs, and generating a transcluded practice note were all removed. The tool does one thing.

* To create an exercise pair, see [Add a New Exercise](../how-to/AddExercise.md).
* `difficulty` and `tags` stay in question frontmatter — Obsidian's own search and tag pane
  read them, even though this tool no longer does.
