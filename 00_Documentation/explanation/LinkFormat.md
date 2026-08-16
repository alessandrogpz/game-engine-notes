# Why Relative Markdown Links, Not Wikilinks

---

## The problem

Obsidian's `[[wikilink]]` syntax is not markdown. It is an Obsidian extension, and GitHub has no idea what to do with it — so a note written like this:

```markdown
Unlike the [[02_Dot_Product|dot product]] which gives a number, the cross product gives a vector.
```

renders on GitHub as the literal text `[[02_Dot_Product|dot product]]`, brackets and pipe included. Every cross-reference in the vault was unreadable there.

## The fix

Standard markdown links with relative paths work in **both** tools:

```markdown
Unlike the [dot product](../02_Vectors/02_Dot_Product.md) which gives a number, the cross product gives a vector.
```

Obsidian resolves relative markdown links and counts them in Graph View and the backlinks panel, so nothing is lost by avoiding wikilinks. GitHub renders them as ordinary links. The vault reads correctly on both surfaces from the same source.

## The cost

Wikilinks are location-independent: `[[02_Dot_Product]]` resolves no matter where either file sits. Relative links are not — move a file and its links break.

That is a real trade, and it is why moves in this repository are always followed by a link-rewriting pass and a verification sweep that resolves every relative target against the filesystem. The tooling makes the cost manageable; the alternative was notes that only worked in one of the two places they are read.

---

## The one exception

Transclusion (`![[Note]]`) has no markdown equivalent. Nothing in standard markdown embeds one file's rendered content inside another.

It survives in exactly one place: the generated `Daily_Practice.md`, which inlines the day's questions into a single note. That file is gitignored and read only inside Obsidian, so it never reaches GitHub and the limitation costs nothing.

---

## Convention

Full rules in [Naming and note conventions](../references/NamingConventions.md). In short: relative markdown links everywhere, link the first meaningful mention, verify targets resolve after any move.
