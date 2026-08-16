#!/usr/bin/env python3
"""Verify that LaTeX in the vault renders on GitHub, not just in Obsidian.

Obsidian's renderer is permissive; GitHub's is not, and it fails loudly —
replacing an entire equation with an error box. Because local preview looks
fine, these breakages are invisible until someone opens the note on GitHub.

Rules enforced (see 00_Documentation/references/MathFormatting.md):

  A  $$ delimiters and their contents start at column 0
  B  a blank line before the opening $$ and after the closing $$
  C  matrix rows break with \\\\, never \\
  D  no macros outside GitHub's allowlist (\\operatorname, \\tag, ...)
  E  no matrices inside inline $...$
  F  no unsupported environments (align, equation, gather, multline)

Usage:
    python3 scripts/check_math.py

Exits non-zero if any rule is violated, so it can gate CI.
"""

from __future__ import annotations

import os
import re
import subprocess

# The formatting reference quotes every forbidden construct as an example.
EXEMPT = {"00_Documentation/references/MathFormatting.md"}

BANNED_MACRO = re.compile(r"\\(operatorname|tag|label|eqref|def|newcommand|DeclareMathOperator)\b")
BANNED_ENV = re.compile(r"\\begin\{(align|equation|gather|multline)\*?\}")
BARE_ROWBREAK = re.compile(r"(?<!\\)\\\\(?!\\)")
INLINE_MATRIX = re.compile(r"(?<!\$)\$([^$\n]*\\begin\{[a-z]*matrix\}[^$\n]*)\$(?!\$)")


def tracked_markdown() -> list[str]:
    out = subprocess.run(
        ["git", "ls-files", "*.md"], capture_output=True, text=True, check=True
    ).stdout.split()
    return [f for f in out if "cmake-build" not in f and os.path.exists(f)]


def check(path: str) -> list[str]:
    lines = open(path, encoding="utf-8").read().split("\n")
    problems: list[str] = []
    in_math = in_code = False

    for i, line in enumerate(lines, start=1):
        stripped = line.strip()

        if stripped.startswith("```"):
            in_code = not in_code
            continue
        if in_code:
            continue

        if stripped == "$$":
            if line != "$$":
                problems.append(f"{path}:{i}  [A] $$ is indented; must start at column 0")
            if not in_math:  # opening
                if i > 1 and lines[i - 2].strip() != "":
                    problems.append(f"{path}:{i}  [B] no blank line before the opening $$")
                in_math = True
            else:            # closing
                if i < len(lines) and lines[i].strip() != "":
                    problems.append(f"{path}:{i}  [B] no blank line after the closing $$")
                in_math = False
            continue

        if in_math:
            if line != line.lstrip():
                problems.append(f"{path}:{i}  [A] indented line inside a $$ block")
            if BARE_ROWBREAK.search(line):
                problems.append(rf"{path}:{i}  [C] uses \\ for a row break; needs \\\\")

        if BANNED_MACRO.search(line):
            macro = BANNED_MACRO.search(line).group(1)
            problems.append(rf"{path}:{i}  [D] \{macro} is not on GitHub's macro allowlist")
        if BANNED_ENV.search(line):
            env = BANNED_ENV.search(line).group(1)
            problems.append(f"{path}:{i}  [F] {env} environment is unsupported; use aligned")
        if not in_math and INLINE_MATRIX.search(line):
            problems.append(f"{path}:{i}  [E] matrix inside inline $...$; promote to a $$ block")

    if in_math:
        problems.append(f"{path}  [A] a $$ block is never closed")
    return problems


def main() -> int:
    files = tracked_markdown()
    problems: list[str] = []
    for path in files:
        if path in EXEMPT:
            continue
        problems.extend(check(path))

    print(f"Scanned {len(files)} markdown files.")
    if problems:
        print(f"\n{len(problems)} violation(s):\n")
        for p in problems:
            print(f"  {p}")
        print("\nSee 00_Documentation/references/MathFormatting.md")
        return 1

    print("All math conforms.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
