# Add a Figure

Figures live in the subject's `Assets/` folder and are embedded with an explicit size.

---

## Save the file

Convert to `.webp` and name it after the note it illustrates:

```bash
magick source.png -fuzz 8% -trim +repage -bordercolor white -border 18 \
  -quality 88 01_Mathematics/01_Linear_Algebra/Assets/reflection_through_plane.webp
```

Trimming removes surrounding whitespace so the figure fills its box; the border adds a small consistent margin back.

## Embed it

Use an HTML tag rather than markdown image syntax, so the display size is explicit:

```html
<center>
	<img src="../../Assets/reflection_through_plane.webp" width="450" height="288" alt="Reflection of a Point Through a Plane">
</center>
```

## Match the aspect ratio

Set `width` and `height` to the file's real proportions, or the figure renders distorted:

```bash
magick identify -format "%w x %h  (aspect %[fx:w/h])\n" path/to/figure.webp
```

For a 794×508 source at 450 wide, the height is `450 / (794/508) ≈ 288`.

## Write real alt text

Describe what the figure shows, not what it is called. `alt="Reflection of a Point Through a Plane"` is useful; `alt="figure1"` is not.

---

## Path depth

`Assets/` sits at the subject root, so from a note inside `Concepts/<Topic>/` the path is always `../../Assets/`.

---

## See also

* [Add a concept note](AddConceptNote.md)
* [Repository structure](../references/RepositoryStructure.md)
