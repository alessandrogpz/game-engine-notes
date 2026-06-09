# Advanced DOD & Hardware Concepts

This note covers advanced memory layouts, hardware vectorization, architectural patterns, and custom memory management techniques.

---

## 1. AoSoA (Array of Structures of Arrays)

While **SoA** is excellent for cache locality, it separates coordinate components (`x`, `y`, `z`) into different vectors. This can make managing elements difficult and is sometimes sub-optimal for hardware vector registers. 

**AoSoA** (or tiled/packeted SoA) groups data into small arrays (usually sized to match a CPU cache line or SIMD vector width, like 4, 8, or 16 elements) inside a struct, then stores those structs in a linear array.

### Layout Comparison
* **AoS:** `[XYZ][XYZ][XYZ][XYZ]...`
* **SoA:** `[XXXX...][YYYY...][ZZZZ...]`
* **AoSoA (Tiled by 4):** `[XXXX|YYYY|ZZZZ][XXXX|YYYY|ZZZZ]...`

```cpp
// AoSoA definition for a group of 8 particles (ideal for AVX-256 float vector)
struct ParticleBlock {
    float x[8];
    float y[8];
    float z[8];
};
std::vector<ParticleBlock> particleBlocks;
```

---

## 2. SIMD & Vectorization

**SIMD** (Single Instruction, Multiple Data) is a hardware feature allowing a CPU core to perform a single arithmetic operation (like addition or square root) on multiple values in a single instruction cycle.

* **Registers:** Modern CPUs contain vector registers:
  * **SSE (128-bit):** Can process 4 floats simultaneously.
  * **AVX / AVX2 (256-bit):** Can process 8 floats simultaneously.
  * **AVX-512 (512-bit):** Can process 16 floats simultaneously.
  * **ARM NEON (128-bit):** Can process 4 floats simultaneously.
* **Requirements:** Compilers can only auto-vectorize loops (turning them into SIMD instructions) if:
  1. The data is contiguous in memory (SoA or AoSoA).
  2. There are no data dependencies between iterations.
  3. The memory is aligned to the vector register size (e.g., 32-byte alignment for AVX).

---

## 3. ECS (Entity Component System)

**ECS** is an architectural pattern that implements DOD principles. It decouples state and behavior entirely.

```
       ┌───────────┐
       │  Entity   │ (Integer ID: 42)
       └─────┬─────┘
             │ has
   ┌─────────┴─────────┐
   ▼                   ▼
┌─────────────┐     ┌─────────────┐
│  Component  │     │  Component  │ (Pure Data Structs: Position, Velocity)
└─────────────┘     └─────────────┘
   ▲                   ▲
   └─────────┬─────────┘ processed by
       ┌─────┴─────┐
       │  System   │ (Global Function: PhysicsSystem)
       └───────────┘
```

* **Entities:** A simple unique identifier (e.g., `using EntityID = uint32_t`). It has no data and no methods.
* **Components:** Pure data structures containing no logic (e.g., `struct Position { float x, y; };`). They are stored back-to-back in contiguous arrays.
* **Systems:** Pure logic and functions that operate on entities with matching components (e.g., `void MovementSystem(Array<Position>& pos, Array<Velocity>& vel)`). Systems run simple, highly vectorized loops.

---

## 4. Custom Memory Allocators

General-purpose heap allocation (`new` or `malloc`) is slow and causes memory fragmentation because the allocator must search for a free memory block. In DOD, custom memory allocators allocate large blocks of memory upfront and partition them manually.

### Arena (Stack) Allocator
* **Mechanism:** Allocates a single large buffer. When memory is requested, it simply increments an offset pointer. 
* **Complexity:** Allocation is $O(1)$, and deallocation is a single operation that resets the offset pointer back to zero.
* **Ideal for:** Frame-based temporary allocations (e.g., clearing temporary buffers at the end of each frame).

### Pool Allocator
* **Mechanism:** Divides a block of memory into fixed-size slots (e.g., exactly 64 bytes each). It tracks free slots using a linked list of free blocks stored within the empty slots themselves.
* **Complexity:** Allocation and deallocation are both $O(1)$.
* **Ideal for:** Repeatedly spawning and destroying entities of a fixed type without causing fragmentation.

---

## 5. Instruction Cache (L1i) & Branch Elimination

CPUs do not just cache data; they also cache the compiled machine instructions in the **L1i (Instruction) Cache**.

* **The OOP vtable Problem:** OOP polymorphism calls virtual functions via a vtable pointer. This requires jumping to separate segments of memory containing the function's code, which frequently causes L1i cache misses and stalls the pipeline.
* **Branch Misprediction:** CPU branch predictors guess which path an `if` statement will take to execute instructions ahead of time. In a loop containing mixed states, the predictor fails, clearing the pipeline and costing up to 15–20 cycles.
* **DOD Fix:**
  * Process code in uniform streams (all objects in a loop run the *exact same* function).
  * Separate objects into different arrays based on state (Step 8 of DOD), replacing conditional branching with data organization.

---
*Back to **[[Intro to Data-Oriented Design (DOD)]]***
