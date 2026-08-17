# Your First Study Session

This walks through one complete practice cycle, start to finish. Follow it in order — it is designed to work without decisions, and it touches every moving part of the vault exactly once.

---

## 1. Open the vault

Launch Obsidian and open the repository root as a vault. The `.obsidian/` settings are committed, so the templates folder and the build-directory exclusions are already configured.

## 2. Pick a question

From the repository root:

```bash
python3 randomizer.py
```

It prints one randomly chosen question and its path:

```
Q_09_Intersection_Two_Planes  (32 available in the whole vault)
01_Mathematics/01_Linear_Algebra/Exercises/05_Geometry/Questions/Q_09_Intersection_Two_Planes.md
```

To stay within one area, name it — `python3 randomizer.py geometry`.

## 3. Open it

Open that file in Obsidian, either by pasting the path or by typing the question name into the quick switcher (`Ctrl/Cmd + O`).

## 4. Solve it on paper

The question has two parts: *Part 1: Calculation* and *Part 2: Conceptual Understanding*. Work through both before looking at anything else. Writing the derivation out by hand is the point of the exercise.

## 5. Check your answer

Click the **Check Answer** link at the bottom of the question. The solution note gives the full derivation step by step, with the reasoning behind each move rather than just the result.

## 6. Follow one concept link

At the bottom of the solution, **Related Concepts** points back to the theory note the exercise came from. Open it and skim.

This is the habit the whole vault is built around: every solved problem leads back to the concept it exercises, so practice and theory stay connected instead of drifting apart.

---

## What you just used

* **`randomizer.py`** — the practice picker
* **Question → Solution → Concept** — the bidirectional chain that forms the knowledge graph

---

## Next steps

* [Run a practice session](../how-to/RunPracticeSession.md) — scoping the pick to a domain, subject or topic
* [Add a new exercise](../how-to/AddExercise.md) — when you find a problem worth keeping
* [The knowledge graph](../explanation/KnowledgeGraph.md) — why the notes link the way they do
