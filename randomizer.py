#!/usr/bin/env python3
"""Pick one random question to practise.

Usage:
    python3 randomizer.py                    # anywhere in the vault
    python3 randomizer.py vectors            # only 02_Vectors
    python3 randomizer.py "linear algebra"   # every topic in 01_Linear_Algebra
    python3 randomizer.py mathematics        # every subject in 01_Mathematics

The scope argument matches a domain, a subject or a topic folder. Numeric
prefixes are ignored and underscores read as spaces, so `02_Vectors` answers to
`vectors`, and `01_Linear_Algebra` to `linear algebra`, `linear_algebra` or
`linear`.
"""

from __future__ import annotations

import argparse
import glob
import os
import random
import re
import sys

# Exercises live at <NN_Domain>/<NN_Subject>/Exercises/<NN_Topic>/Questions/Q_*.md
QUESTION_GLOB = os.path.join("*", "*", "Exercises", "*", "Questions", "Q_*.md")

# Path components that name something a scope can match: domain, subject, topic.
SCOPE_PARTS = (0, 1, 3)


def question_files() -> list[str]:
    return sorted(glob.glob(QUESTION_GLOB))


def normalize(name: str) -> str:
    """`01_Linear_Algebra` -> `linear algebra`, so a query can be typed naturally."""
    return re.sub(r"^\d+_", "", name).replace("_", " ").strip().lower()


def scopes_of(path: str) -> list[str]:
    """The domain, subject and topic names a question path sits under."""
    parts = path.split(os.sep)
    return [normalize(parts[i]) for i in SCOPE_PARTS if i < len(parts)]


def matching(paths: list[str], query: str) -> list[str]:
    """Questions whose domain, subject or topic matches. Exact wins over substring."""
    q = normalize(query)
    exact = [p for p in paths if q in scopes_of(p)]
    if exact:
        return exact
    return [p for p in paths if any(q in s for s in scopes_of(p))]


def available_scopes(paths: list[str]) -> list[str]:
    """Every name a scope argument could take, for the error message."""
    return sorted({s for p in paths for s in scopes_of(p)})


def main() -> int:
    parser = argparse.ArgumentParser(
        description="Pick one random question to practise.",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="The scope matches a domain, subject or topic folder — "
               'e.g. "vectors", "linear algebra", "mathematics".',
    )
    parser.add_argument(
        "scope",
        nargs="?",
        help="Optional domain, subject or topic to pick from (default: anywhere)",
    )
    args = parser.parse_args()

    questions = question_files()
    if not questions:
        print("No questions found. Run from the repository root.", file=sys.stderr)
        return 1

    label = "the whole vault"
    if args.scope:
        questions = matching(questions, args.scope)
        if not questions:
            print(f"Nothing matches {args.scope!r}.\n", file=sys.stderr)
            print("Available scopes:", file=sys.stderr)
            for scope in available_scopes(question_files()):
                print(f"  {scope}", file=sys.stderr)
            return 1
        label = args.scope

    chosen = random.choice(questions)
    print(f"{os.path.basename(chosen)[:-3]}  ({len(questions)} available in {label})")
    print(chosen)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
