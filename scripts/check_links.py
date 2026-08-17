#!/usr/bin/env python3
"""Verify that every relative link and image source in the vault resolves.

Relative markdown links are fragile by design — moving a file breaks every link
into it. This is the sweep that makes that trade acceptable.

Two failure modes are reported:

  * **broken** — the target does not exist.
  * **folder** — the target is a directory. GitHub renders these as a folder
    listing, so they look fine there, but Obsidian resolves links against files
    only: clicking one offers to create a new note instead of navigating. Link
    the folder's ``README.md`` explicitly.

Usage:
    python3 scripts/check_links.py            # check tracked files
    python3 scripts/check_links.py --verbose  # also print the totals per file

Exits non-zero if anything is broken, so it can gate CI.
"""

from __future__ import annotations

import os
import re
import subprocess
import sys

# Documentation legitimately shows link *syntax* as an example. Those live inside
# code spans and fences, which are stripped before scanning — but these files also
# contain deliberate placeholders outside them.
PLACEHOLDER_FILES = {
    "99_Templates/Template_Question.md",
    "99_Templates/Template_Solution.md",
}

LINK_RE = re.compile(r'(?<!!)\[[^\]]*\]\(([^)]+)\)|src="([^"]+)"')
FENCE_RE = re.compile(r"```.*?```", re.S)
INLINE_RE = re.compile(r"`[^`\n]*`")

# C++ syntax that looks like a markdown link: operator[](args), lambdas [](args)
CPP_FALSE_POSITIVE = re.compile(r"\b(operator|std::)")


def tracked_files() -> list[str]:
    out = subprocess.run(
        ["git", "ls-files"], capture_output=True, text=True, check=True
    ).stdout.split()
    return [
        f
        for f in out
        if f.endswith((".md", ".cppm", ".cpp"))
        and "cmake-build" not in f
        and os.path.exists(f)
    ]


def scan(path: str) -> tuple[list[tuple[str, str]], list[tuple[str, str]]]:
    """Return (broken, folder) lists of (file, target) for one file."""
    text = open(path, encoding="utf-8").read()
    text = FENCE_RE.sub("", text)   # fenced code blocks
    text = INLINE_RE.sub("", text)  # inline code spans

    base = os.path.dirname(path) or "."
    broken: list[tuple[str, str]] = []
    folder: list[tuple[str, str]] = []
    for match in LINK_RE.finditer(text):
        target = (match.group(1) or match.group(2)).split("#")[0]
        if not target or target.startswith(("http://", "https://", "mailto:")):
            continue
        if path.endswith((".cppm", ".cpp")) and CPP_FALSE_POSITIVE.search(target):
            continue  # operator[](...) and lambdas, not links
        resolved = os.path.normpath(os.path.join(base, target))
        if not os.path.exists(resolved):
            broken.append((path, target))
        elif os.path.isdir(resolved):
            folder.append((path, target))
    return broken, folder


def main() -> int:
    verbose = "--verbose" in sys.argv
    files = tracked_files()
    broken: list[tuple[str, str]] = []
    folder: list[tuple[str, str]] = []
    checked = 0

    for path in files:
        if path in PLACEHOLDER_FILES:
            continue
        text = FENCE_RE.sub("", open(path, encoding="utf-8").read())
        checked += len(LINK_RE.findall(INLINE_RE.sub("", text)))
        file_broken, file_folder = scan(path)
        broken.extend(file_broken)
        folder.extend(file_folder)

    print(f"Scanned {len(files)} files, {checked} relative links.")
    if broken:
        print(f"\n{len(broken)} broken — target does not exist:\n")
        for path, target in broken:
            print(f"  {path}\n      -> {target}")
    if folder:
        print(f"\n{len(folder)} point at a folder — Obsidian cannot resolve these.")
        print("Link the folder's README.md instead:\n")
        for path, target in folder:
            print(f"  {path}\n      -> {target}")
    if broken or folder:
        return 1

    print("All links resolve, and none point at a folder.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
