# Add a Subject or Domain

The vault is organized domain first: each top-level numbered folder is a domain, each domain holds subjects, each subject holds its own notes.

---

## Add a subject to an existing domain

1. Create the folder and its parts:

```bash
mkdir -p 02_Rendering/01_Model_View_Projection/{Concepts,Exercises,Assets}
```

2. Give the subject a `README.md` indexing its notes — this is what links point at, since a link to a bare folder does not resolve in Obsidian. See [Data-Oriented Design](../../08_Systems_and_Performance/01_Data_Oriented_Design/README.md) or [Linear Algebra](../../01_Mathematics/01_Linear_Algebra/README.md) for the pattern.
3. Add the subject to the domain's `README.md` subject table, and to its `00_Roadmap.md`, marking it *in progress*.

The randomizer discovers new topic folders automatically by globbing `*/*/Exercises/*`. No configuration is needed.

## Add a new domain

1. Create `<NN>_<Domain_Name>/` using the next free number below `89`.
2. Write a `README.md` — the domain **index**. Until notes exist it is short: one line on what the domain covers, a table of planned subjects, a "no notes yet" callout pointing at the roadmap, and links to the domains it builds on. See [02_Rendering](../../02_Rendering/README.md).
3. Write a `00_Roadmap.md` — the **plan**: subjects to cover, resources worth using, and, for broad academic fields, what to deliberately skip. See [Roadmap scoping](../explanation/RoadmapScoping.md) for why the exclusions matter.
4. Add a row to the domain table in the [root README](../../README.md), linking the **index**, not the roadmap.
5. Add a line to the [repository structure](../references/RepositoryStructure.md).

> [!NOTE]
> The index and the roadmap answer different questions — what exists versus what is planned —
> and are kept as separate files for that reason. [Vault organization](../explanation/VaultOrganization.md)
> explains the split.

## Numbering

Domains occupy `01`–`89`. `90_Code/` is the buildable C++ project, `99_Templates/` holds the scaffolder inputs, and `00_Documentation/` is this folder — sorting first because it is the entry point.

Leave gaps if a domain logically belongs between two existing ones; renumbering later means touching every relative link in the subtree.

---

## See also

* [Vault organization](../explanation/VaultOrganization.md) — why domain first
* [Naming conventions](../references/NamingConventions.md)
