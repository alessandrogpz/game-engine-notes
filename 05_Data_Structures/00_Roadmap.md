# Data Structures — Study Roadmap

Structures chosen for cache behaviour and access pattern, not asymptotic elegance. An engine's constraints are different from an interview's.

> [!NOTE]
> Placeholder. The existing `dsa-reference` vault is a candidate to fold in here.

---

## Scope

A general DSA course optimizes for big-O on arbitrary workloads. An engine optimizes for **a known access pattern on contiguous memory**, where a linked list with perfect asymptotics loses badly to a vector that fits in cache.

**Emphasize:** contiguous layouts, spatial structures, allocation-free designs, structures whose iteration order matches how they are consumed.

**De-emphasize:** balanced BST minutiae (red-black rotations), exotic heaps (Fibonacci), self-referential pointer structures. Know they exist; rarely reach for them.

---

## Suggested Subjects

### 01_Linear_and_Contiguous
* Dynamic arrays, growth policies, small-buffer optimization
* Ring buffers, stacks, deques
* Sparse sets — the backbone of many ECS implementations
* Free lists and slot maps; generational handles for safe references

### 02_Associative
* Hash maps: open addressing vs chaining, robin hood, swiss tables
* Why `std::unordered_map` is usually the wrong choice in a hot loop
* Sorted flat maps and binary search over arrays

### 03_Spatial
The engine-specific heart of this domain.
* BVH: construction (SAH), traversal, refitting
* Octrees and quadtrees; loose octrees
* k-d trees, BSP trees
* Uniform grids and spatial hashing
* Trade-offs: build cost vs query cost vs update cost for dynamic scenes

### 04_Graphs_and_Hierarchies
* Adjacency representations; flattened hierarchies
* Scene graph as an array with parent indices, not pointers
* Navigation meshes

### 05_Memory_Aware_Design
* AoS vs SoA; structure splitting by access frequency
* Cache lines, false sharing, prefetching
* Overlaps heavily with [08_Systems_and_Performance](../08_Systems_and_Performance/00_Roadmap.md)

---

## Resources

| Resource | Use |
| :--- | :--- |
| Existing `dsa-reference` vault | Fundamentals already gathered |
| Ericson, *Real-Time Collision Detection* | Best practical treatment of spatial structures |
| Sedgewick, *Algorithms* | Solid reference for the classics |
| [Sparse sets / entt internals](https://github.com/skypjack/entt) | Reading the source teaches the pattern |

---

## Suggested Order

Contiguous structures first, then spatial (immediately useful for both rendering culling and physics broad phase), then memory-aware refactoring of what you already wrote.
