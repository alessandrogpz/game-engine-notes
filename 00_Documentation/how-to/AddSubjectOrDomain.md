# Add a Subject or Domain

The vault is organized domain first: each top-level numbered folder is a domain, each domain holds subjects, each subject holds its own notes.

---

## Add a subject to an existing domain

1. Create the folder and its parts:

```bash
mkdir -p 02_Rendering/01_Model_View_Projection/{Concepts,Exercises,Assets}
```

2. Add the subject to that domain's `00_Roadmap.md`, marking it *in progress* and linking to its notes as they appear.
3. If the subject grows its own build instructions or a long index, give it a `README.md` — see [Data-Oriented Design](../../08_Systems_and_Performance/01_Data_Oriented_Design/README.md) for the pattern.

The randomizer discovers new topic folders automatically by globbing `*/*/Exercises/*`. No configuration is needed.

## Add a new domain

1. Create `<NN>_<Domain_Name>/` using the next free number below `89`.
2. Write a `00_Roadmap.md` listing the subjects to cover, the resources worth using, and — for broad academic fields — what to deliberately skip. See [Roadmap scoping](../explanation/RoadmapScoping.md) for why the exclusions matter.
3. Add a row to the domain table in the [root README](../../README.md).
4. Add a line to the [repository structure](../references/RepositoryStructure.md).

## Numbering

Domains occupy `01`–`89`. `90_Code/` is the buildable C++ project, `99_Templates/` holds the scaffolder inputs, and `00_Documentation/` is this folder — sorting first because it is the entry point.

Leave gaps if a domain logically belongs between two existing ones; renumbering later means touching every relative link in the subtree.

---

## See also

* [Vault organization](../explanation/VaultOrganization.md) — why domain first
* [Naming conventions](../references/NamingConventions.md)
