# Your First Study Session

This walks through one complete practice cycle, start to finish. Follow it in order — it is designed to work without decisions, and it touches every moving part of the vault exactly once.

---

## 1. Open the vault

Launch Obsidian and open the repository root as a vault. The `.obsidian/` settings are committed, so the templates folder and the build-directory exclusions are already configured.

## 2. Generate today's practice

From the repository root:

```bash
python3 randomizer.py -n 3 --practice
```

This picks three random questions and writes `Daily_Practice.md` into the root.

## 3. Open the practice note

Open `Daily_Practice.md` in Obsidian. All three questions appear inline — they are transcluded, so you do not need to open them separately.

## 4. Solve them on paper

Each question has two parts: *Part 1: Calculation* and *Part 2: Conceptual Understanding*. Work through both before looking at anything else. Writing the derivation out by hand is the point of the exercise.

## 5. Check your answers

Click the **Check Answer** link at the bottom of each question. The solution note gives the full derivation step by step, with the reasoning behind each move rather than just the result.

## 6. Follow one concept link

At the bottom of the solution, **Related Concepts** points back to the theory note the exercise came from. Open it and skim.

This is the habit the whole vault is built around: every solved problem leads back to the concept it exercises, so practice and theory stay connected instead of drifting apart.

## 7. Clean up

Delete `Daily_Practice.md`. It is gitignored scratch space and will be regenerated next time.

---

## What you just used

* **`randomizer.py`** — the practice picker
* **Transclusion** — the single-note workspace
* **Question → Solution → Concept** — the bidirectional chain that forms the knowledge graph

---

## Next steps

* [Run a filtered practice session](../how-to/RunPracticeSession.md) — by topic, difficulty or tag
* [Add a new exercise](../how-to/AddExercise.md) — when you find a problem worth keeping
* [The knowledge graph](../explanation/KnowledgeGraph.md) — why the notes link the way they do
