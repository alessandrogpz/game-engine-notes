# Why the Vault Is Organized This Way

---

## Domain first, not kind first

The vault was originally organized by *kind*: `Concepts/`, `Exercises/` and `Code/` at the top level, with subjects nested inside each.

That works for one subject and collapses at ten. Every new topic has to be created in three parallel trees and kept in sync forever; every rename touches three places; and the top level tells you nothing about what the repository is actually about.

Inverting it — each domain owns its subjects, each subject carries its own `Concepts/`, `Exercises/` and `Assets/` — means:

* Adding a domain is a single folder, not three coordinated edits.
* The top level reads as a table of contents.
* Relative links get **shorter**, because most references are between neighbours inside one subject.

The cost is one extra level of nesting for the paths that do cross subjects. That trade is worth it: cross-subject links are the minority, and they are the ones you write deliberately.

---

## One vault, not one repository per subject

Rendering, physics, mathematics and systems programming could each be their own repository. They are not, and that is the single most important structural decision here.

The most valuable links are the ones that cross domain boundaries:

* A model-view-projection note pointing at homogeneous coordinates
* A frustum culling note pointing at point-plane distance
* A data-oriented design note pointing at entity systems
* A BVH traversal note pointing at ray-plane intersection

Separate repositories would mean four disconnected graphs — and the understanding lives in the edges between them, not inside any one of them. Obsidian cannot link across vaults, so splitting would permanently sever exactly the connections worth having.

The secondary benefits are real too: one set of conventions instead of four drifting ones, one practice tool that can mix a geometry proof with a cache-locality question in the same session, and one place to look.

---

## Subject-level READMEs

Large subjects carry their own `README.md` as a local index — see [Data-Oriented Design](../../08_Systems_and_Performance/01_Data_Oriented_Design/README.md), which documents its own compile flags and orders its notes into a learning path.

This is deliberate rather than accidental duplication. As the vault grows, a single root README cannot stay both complete and readable. The root navigates *to* subjects; each substantial subject documents *itself*. A subject earns a README when it has build instructions of its own, or enough notes that their reading order is not obvious from the filenames.

---

## Numbering

Prefixes exist because file explorers and Obsidian both sort alphabetically, and the natural reading order of a subject is almost never alphabetical.

Domains occupy `01`–`89`, leaving room to insert one between two existing domains without renumbering. `00_Documentation/` sorts first because it is the entry point; `90_Code/` and `99_Templates/` sort last because they are machinery rather than content.

Renumbering after the fact means touching every relative link in the affected subtree, so leave gaps rather than packing the numbers tightly.
