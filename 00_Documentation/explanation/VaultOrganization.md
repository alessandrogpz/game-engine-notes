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

## Subject READMEs

A subject carries its own `README.md` when it has build instructions of its own, or enough
notes that their reading order is not evident from the filenames. See
[Data-Oriented Design](../../08_Systems_and_Performance/01_Data_Oriented_Design/README.md).

The root README navigates to subjects. Each subject README documents its own contents.

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
