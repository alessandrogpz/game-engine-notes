# Repository Structure

Numbered prefixes fix the order in the file explorer. Domains occupy `01`–`89`; documentation and tooling sit outside that range.

---

```text
game-engine-notes/
├── 00_Documentation/                  # This folder — Diátaxis-organized docs
│   ├── tutorials/                     #   Learning-oriented walkthroughs
│   ├── how-to/                        #   Task recipes
│   ├── references/                    #   Conventions, CLI flags, structure
│   └── explanation/                   #   Design decisions and rationale
│
├── 01_Mathematics/                    # DOMAIN
│   ├── 00_Roadmap.md                  #   Subjects to cover, and how much of each
│   └── 01_Linear_Algebra/             #   SUBJECT
│       ├── Concepts/                  #     Theory notes, grouped by topic
│       │   ├── 01_Systems_of_Equations/
│       │   ├── 02_Vectors/
│       │   ├── 03_Matrices/
│       │   ├── 04_Transforms/
│       │   └── 05_Geometry/
│       ├── Exercises/                 #     Questions and step-by-step solutions
│       │   └── <NN_Topic>/
│       │       ├── Questions/         #       Q_[Exercise_Name].md
│       │       └── Solutions/         #       S_[Exercise_Name].md
│       └── Assets/                    #     Diagrams embedded by the notes
│
├── 02_Rendering/                      # Roadmap only
├── 03_Physics/                        # Roadmap only
├── 04_Engine_Architecture/            # Roadmap only
├── 05_Data_Structures/                # Roadmap only
├── 06_Algorithms/                     # Roadmap only
├── 07_Concurrency_and_Parallelism/
│   └── 01_Foundations/                #   C++ primitives, glossary, runnable demo
├── 08_Systems_and_Performance/
│   └── 01_Data_Oriented_Design/       #   Own README; notes beside runnable examples
├── 09_Tools_and_Pipeline/             # Roadmap only
├── 10_Audio/                          # Roadmap only
├── 11_Networking/                     # Roadmap only
│
├── 90_Code/                           # One buildable C++23 project
│   ├── 00_Utils/                      #   Shared helpers (float comparison)
│   ├── 01_Systems_of_Equations/       #   One .cppm per concept note
│   ├── 02_Vectors/ … 05_Geometry/
│   ├── engine_notes.cppm              #   Umbrella module re-exporting each sub-module
│   ├── tests/                         #   GoogleTest, one file per module
│   └── CMakeLists.txt
│
├── 99_Templates/                      # Scaffolder inputs
│   ├── Template_Question.md
│   └── Template_Solution.md
│
├── scripts/                           # Verification checks, also run in CI
│   ├── check_links.py                 #   Every relative link resolves
│   └── check_math.py                  #   LaTeX renders on GitHub, not just Obsidian
├── .github/workflows/checks.yml       # Runs both checks plus the build and tests
├── randomizer.py                      # Practice picker and exercise scaffolder
├── TODO.md                            # Pending solutions and unimplemented modules
└── README.md                          # Entry point and domain index
```

---

## Where things go

| Item | Location |
| :--- | :--- |
| Theory note | `<Domain>/<Subject>/Concepts/<Topic>/` |
| Exercise pair | `<Domain>/<Subject>/Exercises/<Topic>/{Questions,Solutions}/` |
| Figure | `<Domain>/<Subject>/Assets/` |
| Library code | `90_Code/<Topic>/` |
| Standalone demo | Beside the note it illustrates |
| Domain plan | `<Domain>/00_Roadmap.md` |
| Subject index | `<Domain>/<Subject>/README.md` (only when substantial) |

---

## Common relative paths

| From | To | Path |
| :--- | :--- | :--- |
| Concept note | Sibling concept, same topic | `Other_Note.md` |
| Concept note | Concept in another topic | `../<Topic>/Note.md` |
| Concept note | Figure | `../../Assets/figure.webp` |
| Concept note | Its `.cppm` | `../../../../90_Code/<Topic>/File.cppm` |
| Question | Its solution | `../Solutions/S_Name.md` |
| Question or solution | Concept note | `../../../Concepts/<Topic>/Note.md` |
