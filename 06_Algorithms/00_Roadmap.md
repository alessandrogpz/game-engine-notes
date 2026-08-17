# Algorithms — Study Roadmap

Algorithmic technique, scoped to what engines actually run. Computational geometry and pathfinding carry far more weight here than a typical algorithms curriculum would suggest.

> [!NOTE]
> Placeholder. Subjects gain `Concepts/`, `Exercises/` and `Assets/` folders as work begins.

---

## Scope

A standard algorithms course is calibrated for interviews and theory. An engine needs a different distribution.

**Emphasize:** computational geometry, pathfinding, sorting for cache and for determinism, numerical robustness of geometric predicates.

**De-emphasize:** NP-completeness theory, advanced dynamic programming, string algorithms (unless writing tooling), amortized analysis proofs. Worth recognizing; rarely worth deep study for this purpose.

---

## Suggested Subjects

### 01_Fundamentals
* Complexity as a *tool*, plus the constant factors it hides
* Sorting: quicksort/introsort, radix sort for keys, stability and determinism
* Binary search and its off-by-one failure modes
* Divide and conquer, greedy, dynamic programming — recognition-level fluency

### 02_Computational_Geometry
The most engine-relevant branch, and where [05_Geometry](../01_Mathematics/01_Linear_Algebra/README.md#05_geometry) continues.
* Orientation and in-circle predicates; **robustness and exact arithmetic**
* Convex hulls: quickhull, gift wrapping
* Polygon triangulation, ear clipping
* Line/polygon clipping: Sutherland–Hodgman, Cohen–Sutherland
* Delaunay triangulation and Voronoi diagrams
* Point-in-polygon, winding numbers
* Closest pair, sweep-line techniques

### 03_Pathfinding_and_Search
* Dijkstra, A\*, and admissible heuristics
* Hierarchical pathfinding; jump point search
* Navigation mesh generation and string pulling
* Flow fields for crowds
* Steering behaviours and local avoidance

### 04_Randomness_and_Procedural
* PRNGs: quality, speed, reproducibility, seeding
* Value/Perlin/simplex noise; fBm
* Poisson disk sampling, blue noise
* Wave function collapse, L-systems, maze and dungeon generation

### 05_Compression_and_Encoding *(as needed)*
* Quantization of positions, normals, quaternions
* Delta encoding for network and animation data
* Texture compression formats conceptually (BC/ASTC)

---

## Resources

| Resource | Use |
| :--- | :--- |
| Cormen et al., *CLRS* | Reference for the classics — dip, don't read |
| Skiena, *The Algorithm Design Manual* | More practical framing than CLRS |
| de Berg et al., *Computational Geometry* | The standard text for the geometry branch |
| Ericson, *Real-Time Collision Detection* | Robustness of geometric predicates, done properly |
| [Red Blob Games](https://www.redblobgames.com/) | Outstanding interactive explanations of A\*, grids, noise |

---

## Suggested Order

Computational geometry first — it continues directly from the geometry work already done. Then pathfinding, then procedural generation. Treat classical algorithms as reference unless a specific need arises.
