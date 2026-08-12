# Cache Locality & Memory Layout

This note covers the hardware-level details of CPU cache locality and how data layouts affect memory access speed.

> [!NOTE]
> **In this folder**
> * [`aos_vs_soa.cpp`](./aos_vs_soa.cpp) — Particle AoS vs SoA layout benchmark.

---

## The Core Problem

Modern processors are incredibly fast at executing instructions, but relatively slow at retrieving data from main memory. As a result, software performance is frequently bottlenecked by the CPU waiting for memory reads.

* **Moore's Law Plateau:** Single-threaded CPU performance has plateaued. Slow CPU code written today will remain slow on hardware in the future; we can no longer rely on hardware upgrades to fix poorly designed software.
* **No Scale Knobs:** Unlike GPUs (which can dynamically scale down resolution or mesh detail to maintain frame rates), CPUs have no settings slider to scale down logic, physics updates, or AI.

---

## The Kitchen Analogy

To visualize memory and execution relationships:

* **CPU Core = Chef:** Executes sequential tasks. Adding cores is like hiring multiple chefs.
* **Instructions = Tools:** What the core uses (e.g., knives, pans).
* **Data = Ingredients:** What the instructions operate on.

### The Big O Fallacy
Big O notation (e.g., $O(n \log n)$) only measures the number of operations performed once data is in the workspace. It ignores the massive latency cost of moving data into the registers (fetching ingredients from the pantry or refrigerator). 

---

## Memory Hierarchy & Latency Costs

Operations cannot occur directly in RAM or cache; data must first be loaded into CPU Registers. Fetching data from farther away causes cache misses, stalling the CPU.

Latency costs in CPU cycles:

```
[Registers: 0 cycles] ---> [L1 Cache: ~3 cycles] ---> [L2 Cache: ~20 cycles] ---> [L3 Cache: ~100 cycles] ---> [DRAM: 200-300 cycles]
```

| Memory Tier | Latency | Size | Notes |
| :--- | :--- | :--- | :--- |
| **Registers** | **0 cycles** | Bytes | Immediate workspace. |
| **L1 Cache** | **~3 cycles** | ~64 KB/core | Fastest cache, split into instruction (L1i) and data (L1d). |
| **L2 Cache** | **~20 cycles** | ~2 MB/core | Dedicated to a single core. |
| **L3 Cache** | **~100 cycles** | ~32 MB | Shared across all cores. |
| **Main Memory (DRAM)** | **200–300 cycles** | Gigabytes | Extremely slow relative to CPU execution speed. |

---

## The Cache Line (64 Bytes)

The CPU retrieves memory in linear **64-byte chunks** (Cache Lines). Requesting a single 4-byte variable pulls the next 60 bytes of memory along with it. Fast code ensures these 64 bytes are packed with useful, contiguous data rather than padding or unrelated fields.

### AoS (Array of Structures) vs. SoA (Structure of Arrays)

How you arrange structures in memory dramatically affects cache line utilization.

```
AoS (OOP Style):   [ X, Y, Z, R, G, B ][ X, Y, Z, R, G, B ][ X, Y, Z, R, G, B ]
SoA (DOD Style):   [ X, X, X... ][ Y, Y, Y... ][ Z, Z, Z... ][ R, R, R... ]
```

* **AoS (Array of Structures):**
  ```cpp
  struct Particle {
      float x, y, z;
      uint8_t r, g, b, a;
  };
  std::vector<Particle> particles;
  ```
  If you only want to update positions (`x, y, z`), loading a particle also loads its color data (`r, g, b, a`) into the cache line. This wastes cache bandwidth.
  
* **SoA (Structure of Arrays):**
  ```cpp
  struct Particles {
      std::vector<float> x, y, z;
      std::vector<uint8_t> r, g, b, a;
  };
  ```
  Updating positions only loads the position arrays. The cache lines are 100% packed with relevant position data, maximizing cache efficiency.

### Code Demonstration: Spatial Locality
C++ multidimensional arrays are stored in **Row-Major** format (contiguous rows).
* Compare the performance in [aos_vs_soa.cpp](./aos_vs_soa.cpp).

* **Row-Major Traversal (Contiguous access):**
  ```cpp
  for (int row = 0; row < 10000; row++) {
      for (int column = 0; column < 10000; column++) {
          matrix[row][column] += 1; // Contiguous memory access: utilizes the cache line perfectly
      }
  }
  ```

* **Column-Major Traversal (Strided access):**
  ```cpp
  for (int column = 0; column < 10000; column++) {
      for (int row = 0; row < 10000; row++) {
          matrix[row][column] += 1; // Strides by 40KB, causing a cache miss on almost every loop iteration
      }
  }
  ```

---
*Back to **[README](../README.md)***
