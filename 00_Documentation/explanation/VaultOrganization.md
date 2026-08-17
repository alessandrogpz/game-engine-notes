# Vault Organization

---

## Domain first

Each top-level numbered folder is a domain. Each domain holds subjects. Each subject carries
its own `Concepts/`, `Exercises/` and `Assets/`.

```text
<NN_Domain>/<NN_Subject>/Concepts/<NN_Topic>/<NN_Note>.md
<NN_Domain>/<NN_Subject>/Exercises/<NN_Topic>/{Questions,Solutions}/
<NN_Domain>/<NN_Subject>/Assets/
```

Properties of this layout:

* Adding a domain is one folder.
* The top level lists the subject matter of the repository.
* Most links are between neighbours inside one subject, so relative paths stay short.
* Paths that cross subjects carry one extra level of nesting.

---

## Single vault

All domains live in one repository and one Obsidian vault.

Links cross domain boundaries: a model-view-projection note references homogeneous
coordinates, a frustum culling note references point-plane distance, a data-oriented design
note references entity systems. Obsidian resolves links only within a vault, so a single
vault is what makes those references possible.

One vault also means one set of conventions, one practice tool covering every subject, and
one `TODO.md`.

---

## Folder indexes

Every domain, every subject, and each top-level tooling folder carries a `README.md`: an index
of **what is in that folder now**.

Two things make this mandatory rather than optional.

**Navigation has to land somewhere.** A link to a bare folder does not resolve in Obsidian —
it offers to create a note instead. An index file gives every folder a real target, and
GitHub renders it automatically when browsing to the folder, so one file serves both surfaces.
See [Link Format](LinkFormat.md).

**An index is not a plan.** A domain's `00_Roadmap.md` describes what to study and what to
skip; it is deliberately about material that does not exist yet. Landing there from the root
README means arriving at a list of things that have not been written. The index is the
inventory, and it links on to the roadmap — plan and inventory answer different questions and
age differently, so they are separate files.

```text
01_Mathematics/
├── README.md         # what exists: subjects, note counts, links in
└── 00_Roadmap.md     # what does not: subjects to cover, and how much of each
```

The root README navigates to domains. Each domain index navigates to its subjects. Each subject
index documents its own contents — see
[Data-Oriented Design](../../08_Systems_and_Performance/01_Data_Oriented_Design/README.md),
which also carries the build instructions for its own examples.

Folders below subject level — `Concepts/`, `Assets/`, `Exercises/<Topic>/Questions/` — hold
leaf content and get no index; the subject index already lists what is in them.

---

## Numbering

File explorers and Obsidian sort alphabetically, and the reading order of a subject is rarely
alphabetical, so folders and notes carry numeric prefixes.

| Range | Contents |
| :--- | :--- |
| `00` | Documentation |
| `01`–`89` | Domains |
| `90` | Code |
| `99` | Templates |

Leave gaps when numbering. Renumbering requires rewriting every relative link in the affected
subtree.
