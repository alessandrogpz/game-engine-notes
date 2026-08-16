# Run a Practice Session

Filter the exercise pool by topic, difficulty or tag.

---

## Pick questions

```bash
python3 randomizer.py geometry -n 5       # one topic, five questions
python3 randomizer.py -d Hard -n 3        # by difficulty
python3 randomizer.py -t cross-product    # by frontmatter tag
python3 randomizer.py                     # random difficulty distribution
```

The topic argument matches any topic folder by substring, so `vectors`, `geometry` and `transforms` all work regardless of their numeric prefix.

## Generate a workspace

Add `--practice` to any of the above to also write `Daily_Practice.md` in the root, with each selected question transcluded inline:

```bash
python3 randomizer.py geometry -d Medium -n 4 --practice
```

`Daily_Practice.md` is gitignored — delete it when finished.

## Combine filters

Filters stack. Topic, difficulty and tag can be applied together:

```bash
python3 randomizer.py geometry -d Hard -t implicit-plane -n 2
```

If no questions match, the tool reports the filters it applied rather than failing silently.

---

## See also

* [Randomizer reference](../references/Randomizer.md) — every flag
* [Add a new exercise](AddExercise.md)
