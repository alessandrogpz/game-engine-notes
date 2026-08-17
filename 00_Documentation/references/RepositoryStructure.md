# Repository Structure

Numbered prefixes fix the order in the file explorer. Domains occupy `01`–`89`; documentation and tooling sit outside that range.

---

Every folder listed here carries a `README.md` index — it is what links point at, since a link
to a bare folder does not resolve in Obsidian. Folders below subject level hold leaf content
and have none.

```text
game-engine-notes/
├── 00_Documentation/                  # This folder — Diátaxis-organized docs
│   ├── README.md                      #   Index of all four categories
│   ├── tutorials/                     #   Learning-oriented walkthroughs
│   ├── how-to/                        #   Task recipes
│   ├── references/                    #   Conventions, CLI flags, structure
│   └── explanation/                   #   Design decisions and rationale
│
├── 01_Mathematics/                    # DOMAIN
│   ├── README.md                      #   Index — subjects that exist, and their contents
│   ├── 00_Roadmap.md                  #   Plan — subjects to cover, and how much of each
│   └── 01_Linear_Algebra/             #   SUBJECT
│       ├── README.md                  #     Index — every note and exercise in this subject
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
├── 02_Rendering/                      # README.md + 00_Roadmap.md; no notes yet
├── 03_Physics/                        # README.md + 00_Roadmap.md; no notes yet
├── 04_Engine_Architecture/            # README.md + 00_Roadmap.md; no notes yet
├── 05_Data_Structures/                # README.md + 00_Roadmap.md; no notes yet
├── 06_Algorithms/                     # README.md + 00_Roadmap.md; no notes yet
├── 07_Concurrency_and_Parallelism/
│   └── 01_Foundations/                #   C++ primitives, glossary, runnable demo
├── 08_Systems_and_Performance/
│   └── 01_Data_Oriented_Design/       #   Notes beside runnable examples
├── 09_Tools_and_Pipeline/             # README.md + 00_Roadmap.md; no notes yet
├── 10_Audio/                          # README.md + 00_Roadmap.md; no notes yet
├── 11_Networking/                     # README.md + 00_Roadmap.md; no notes yet
│
├── 90_Code/                           # One buildable C++23 project
│   ├── README.md                      #   Index — every module, and the build commands
│   ├── 00_Utils/                      #   Shared helpers (float comparison)
│   ├── 01_Systems_of_Equations/       #   One .cppm per concept note
│   ├── 02_Vectors/ … 05_Geometry/
│   ├── engine_notes.cppm              #   Umbrella module re-exporting each sub-module
│   ├── tests/                         #   GoogleTest, one file per module
│   └── CMakeLists.txt
│
├── 99_Templates/                      # Scaffolder inputs
│   ├── README.md
│   ├── Template_Question.md
│   └── Template_Solution.md
│
├── scripts/                           # Verification checks, also run in CI
│   ├── README.md
│   ├── check_links.py                 #   Links resolve, and none points at a folder
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
| Domain index | `<Domain>/README.md` — what exists now |
| Domain plan | `<Domain>/00_Roadmap.md` — what does not exist yet |
| Subject index | `<Domain>/<Subject>/README.md` |

---

## Index or roadmap?

Both live in the domain folder and they are not interchangeable.

| Link to | When the reference means |
| :--- | :--- |
| `<Domain>/README.md` | The domain itself — "see also 05_Data_Structures" |
| `<Domain>/00_Roadmap.md` | A named subject that does not exist yet — "see Numerical Methods" |

The root README links every domain to its index. Cross-domain references in prose follow the
table above: name a domain, link the index; name planned material, link the roadmap.

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
