# Team Reference Document

Based on [KACTL](https://github.com/kth-competitive-programming/kactl); see [Credits](#credits).

## Building

Needs `pdflatex` (MiKTeX/TeX Live), `python3`, `make`, `sh` and `cpp`. Run from Git Bash:

```sh
PATH="/c/msys64/ucrt64/bin:$PATH" make trd   # full build (two LaTeX passes) -> trd.pdf
PATH="/c/msys64/ucrt64/bin:$PATH" make fast  # one pass, table of contents may be stale
make label                                   # binder label -> label.pdf
```

ICPC/EUC rules: up to 25 single-sided pages, the university and team name in the upper
left and the page number in the upper right of every page, in a folder with the
institution's name on the front. For the folder, print `label.pdf` at actual size, cut
it out and stick it on the front.

The `PATH` prefix matters: Git Bash puts its own `/mingw64/bin` first, which breaks
`cpp`, and then every code hash silently comes out as `d41d8c` (the hash of nothing).

## Layout

```text
content/
  trd.tex            main document: cover page details, chapter order
  label.tex          binder label: KCL logo, team, members, university, date (set at the top)
  tex/               format (style, preprocessor, KCL logo), not content
  <chapter>/
    chapter.tex      \chapter{...}, \section{...} and the list of imported files
    *.h, *.sh, ...   the files that get printed
```

## Adding things

* New file: put it in the chapter folder and add `\kactlimport{Name.h}` to that
  `chapter.tex`. Non-code files need a language: `\kactlimport[-l raw]{notes.txt}`.
* New chapter: create `content/<name>/chapter.tex` and add `\kactlchapter{<name>}`
  to `content/trd.tex`.
* `.h`/`.cpp`/`.java` files must start with a header comment, or the build errors.
  `Author` and `Description` are required; `Time`, `Memory`, `Usage`, `Source`,
  `Date`, `License`, `Status`, `Details` are optional:

  ```cpp
  /**
   * Author: Your Name
   * Description: What it does. LaTeX math works: $O(n \log n)$
   * Time: O(N \log N)
   */
  #pragma once
  ```

  `///` comments are stripped from the printout, `//` comments are kept.
* `content/contest/hash.sh` is used by the preprocessor to print each listing's
  hash, so keep it even if it is removed from the document.
* `make showexcluded` lists code files that are not imported anywhere.
* Cover page: off by default. Fill in `\university`, `\team` and `\contest` in
  `content/trd.tex` and uncomment `\maketeampage`.

## Credits

This TRD's format is taken from **KACTL** (KTH Algorithm Competition Template Library),
the ICPC team reference document of KTH Royal Institute of Technology, by Simon Lindholm
and the KACTL contributors: <https://github.com/kth-competitive-programming/kactl>.

Most of the content is also from KACTL:

* Format: `content/tex/kactlpkg.sty` (cover-page logo made optional, subsection
  spacing fixed so headings cannot overlap the text above, and a file's title is
  kept in the same column as its description),
  `content/tex/preprocessor.py`, and `Makefile` / `content/trd.tex` (adapted from
  KACTL's `Makefile` / `content/kactl.tex`).
* `content/contest/`: `template.cpp`, `hash.sh`, `troubleshoot.txt`.
* Every `.h` file, `combinatorial/factorial.tex` and the figures (`*.pdf`). The code
  is unchanged; some descriptions are shortened or say when to use the algorithm.
  Each file keeps its original header with authors, source and license: most are
  [CC0](https://creativecommons.org/publicdomain/zero/1.0/), but `ConvexHull.h` is
  Unlicense, `HullDiameter.h` is Boost and `FastDelaunay.h` is MIT.
* Chapter text (`chapter.tex`), e.g. the Mathematics chapter by Anders Sjöqvist and
  Ulf Lundström, Pythagorean triples, and the bit hacks.

Written for this TRD: `math/StdMath.cpp`, `math/ModBinomial.cpp`, `math/SteadyState.cpp`,
`data-structures/StdContainers.cpp`, `data-structures/BinarySearch.cpp`,
`data-structures/FenwickTree.cpp`, `data-structures/LazySegmentTree.cpp`, `graph/GraphBasics.cpp`,
`graph/Bipartite.cpp`, `graph/Dijkstra.cpp`, `graph/BellmanFord.cpp`, `graph/Kruskal.cpp`,
`graph/LCA.cpp`, `graph/Dinic.cpp`, `strings/Hashing.cpp`, `number-theory/Eratosthenes.cpp`,
`number-theory/Factorization.cpp`, `various/SubsetSums.cpp`, the Counting subsection, the shortened
Markov chains section, the notes on cycles and choosing a shortest-path algorithm in the Graph
chapter, the Essentials chapter (`essentials/`), the "What to use when" chapter (`guide/`) and the
Techniques chapter (`techniques/`, apart from KACTL's `LIS.h`, moved there from Various).

Written for this TRD but closely following KACTL: `graph/FloydWarshall.cpp` (the clamping and the
$-\infty$ pass of KACTL's `FloydWarshall.h`) and `strings/KMP.cpp` (KACTL's `KMP.h`: same separator
trick and `match` interface). `techniques/TernarySearch.cpp` uses the same idea as KACTL's
`TernarySearch.h` for integers; KACTL's `GoldenSectionSearch.h` does reals with fewer calls of f.
`euclid` in `number-theory/Factorization.cpp` follows KACTL's `euclid.h`.

The Fenwick tree, lazy segment tree, `Factorization.cpp`, every file in `essentials/` and
`techniques/` (the cheat sheets compiled and checked line by line), and all of the graph and string
files above except `GraphBasics.cpp` and `Dijkstra.cpp` were stress-tested against brute force.

`content/tex/kcl-logo.tex` draws the King's College London logo in TikZ, converted from
[the SVG on Wikimedia Commons](https://commons.wikimedia.org/wiki/File:King%27s_College_London_logo.svg)
(public domain as simple text and shapes, but a KCL trademark).
