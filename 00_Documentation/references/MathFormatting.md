# Math Formatting Conventions

This guide documents the formatting rules and conventions for writing LaTeX equations, matrices, and formulas in this repository. Following these rules ensures that math renders identically and beautifully in both **Obsidian** and **GitHub**.

---

## 1. Display Math Blocks (`$$ ... $$`)

Display math blocks must follow these strict rules to render properly on GitHub and prevent collapsing into raw text:

### A. Zero Indentation
Display math opening/closing tokens (`$$`) and the equations inside them **must start at column 0 (no leading spaces)**. 
*   **Problem:** GitHub does not support indented math blocks (e.g. inside list items). They will fail to render and stack vertically.
*   **Correct:**
    ```markdown
    - **Addition:**
    
    $$
    (A + B)_{ij} = A_{ij} + B_{ij}
    $$
    ```
*   **Incorrect:**
    ```markdown
    - **Addition:**
      $$
      (A + B)_{ij} = A_{ij} + B_{ij}
      $$
    ```

### B. Surrounding Blank Lines
Every display math block must have a blank line (empty line) before the opening `$$` and after the closing `$$`.
*   **Problem:** Lacking blank lines causes the math block to merge into adjacent paragraphs, rendering as inline raw text.
*   **Correct:**
    ```markdown
    Let the vector be:
    
    $$
    \vec{v} = \begin{bmatrix} x \\\\ y \\\\ z \end{bmatrix}
    $$
    
    This vector represents...
    ```

### C. Row Breaks in Matrices (`\\\\`)
Inside any matrix environment (like `bmatrix` or `pmatrix`), you must use **quadruple backslashes (`\\\\`)** to break rows.
*   **Problem:** GitHub's markdown parser pre-processes and escapes double backslashes (`\\`) to a single backslash (`\`) in block math, which collapses matrices into a single line. Quadruple backslashes survive the parser and arrive at the math engine as a proper line break.
*   **Correct:**
    ```markdown
    $$
    A = \begin{bmatrix} a & b \\\\ c & d \end{bmatrix}
    $$
    ```

### D. Avoid `\tag{...}` for Equation Numbers
Do not use the LaTeX `\tag{...}` command to number equations.
*   **Problem:** GitHub's MathJax renderer has a layout bug with tags that forces display math blocks to stack vertically, rendering every symbol on a new line.
*   **Correct:** Place a bold identifier on the line above the block, separated by a blank line.
    ```markdown
    **(2.1)**
    
    $$
    \vec{p}_B = \mathbf{M}\vec{p}_A + \vec{t}
    $$
    ```

---

## 2. Inline Math (`$ ... $`)

Inline math should be kept simple. Do not put complex structures inside single dollar signs:

### A. No Inline Matrices
Never put matrices (`\begin{bmatrix}`) or multi-line environments inside inline math.
*   **Problem:** GitHub's markdown parser is too strict for inline matrices and will fail to render them.
*   **Correct:** Convert the math block to a display math block (`$$`) on its own line:
    ```markdown
    Given the vector:
    $$
    \vec{v} = \begin{bmatrix} 1 \\\\ 0 \\\\ 0 \end{bmatrix}
    $$
    ```

### B. Underscore Conflicts (Italics)
Avoid having multiple subscripts using underscores (`_`) on the same line in inline math.
*   **Problem:** GitHub's Markdown parser processes underscores as italic markers *before* passing the text to the math rendering engine. This strips the underscores and turns the text between them into italics, breaking the math.
*   **Correct:** Convert the equation into a display math block (`$$`):
    ```markdown
    $$
    (A + B)_{ij} = A_{ij} + B_{ij}
    $$
    ```

---

## 3. Summary Cheat Sheet

| Feature | Formatting Pattern |
| :--- | :--- |
| **Simple Inline Math** | `$x^2 + y^2 = r^2$` |
| **Display Math** | `$$` block starting at column 0, surrounded by blank lines |
| **Matrix Row Breaks** | Use `\\\\` (quadruple backslashes) |
| **Equation Labels** | `**(2.1)**` on the line above the `$$` block |
| **Subscript Operations** | Put in `$$` blocks to avoid underscore-italics conflict |
