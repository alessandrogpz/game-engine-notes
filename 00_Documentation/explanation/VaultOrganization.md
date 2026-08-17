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
├── README.md         # what exists: the subjects, and links into them
└── 00_Roadmap.md     # what does not: subjects to cover, and how much of each
```

The root README navigates to domains. Each domain index navigates to its subjects. Each subject
index documents its own contents — see
[Data-Oriented Design](../../08_Systems_and_Performance/01_Data_Oriented_Design/README.md),
which also carries the build instructions for its own examples.

Folders below subject level — `Concepts/`, `Assets/`, `Exercises/<Topic>/Questions/` — hold
leaf content and get no index; the subject index already lists what is in them.

---

## An index is a list, not a page

An index carries navigation and nothing else. Anything a reader could get from the folder name,
or from the file one click away, is duplication that will fall out of date on its own.

| Kept out | Why |
| :--- | :--- |
| A description paragraph under the title | The folder name already said it |
| A `Status` column | A subject that exists is a link; a planned one is a code span. The list already shows which is which |
| Note, exercise or module counts | Wrong the next time anything is added, and nothing depends on the number |
| A table of a subject's contents | That is the subject index, one click away and maintained in one place |
| A trailing `Related` or `Builds on` section | Those pointers belong beside the material that discusses them, which is the roadmap |
| A `— description` after each link in a list | Titles like *Build Requirements* are already self-describing |

Scoping markers stay, because they record a decision rather than progress:
`` `06_Geometric_Algebra` *(optional)* `` sits in the subject cell rather than earning a column.

> [!IMPORTANT]
> This applies to indexes only. A concept note still opens by stating what the concept **is**
> before any derivation — see [Add a Concept Note](../how-to/AddConceptNote.md). Stripping
> prose out of a note makes it worse, not tighter.

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
