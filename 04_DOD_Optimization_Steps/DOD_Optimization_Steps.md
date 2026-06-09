# DOD Optimization Steps

This guide outlines the 8 sequential steps to optimize CPU-bound code. Converting a codebase from Object-Oriented design to Data-Oriented structure can achieve a **~40x cumulative speedup**.

---

## Step 1: Centralized Update Manager
* **Fix:** Remove individual `Update()` or `Tick()` loops from entity classes.
* **Why:** Iterating through a linear array of packed data is drastically faster than accessing fragmented objects scattered in memory.
* **OOP vs. DOD Pattern:**
  * **Before (OOP):** 10,000 entities, each containing its own tick loop. Calling `entity->Update()` triggers virtual method lookups and jumps to disparate memory addresses.
    ```cpp
    // BAD: Scatters execution across the heap
    for (auto* entity : entities) {
        entity->Update(deltaTime); 
    }
    ```
  * **After (DOD):** A single manager updates all components in a simple, flat loop.
    ```cpp
    // GOOD: Single instruction stream, linear memory access
    void PhysicsSystem::Update(float deltaTime) {
        for (size_t i = 0; i < count; ++i) {
            positions[i] += velocities[i] * deltaTime;
        }
    }
    ```

---

## Step 2: Eliminate Callbacks & Observers
* **Fix:** Inline event logic and remove unmanaged delegates or function pointers.
* **Why:** Callbacks break visibility, prevent compiler inlining, and can completely evict the L1 cache.
* **DOD Pattern:** Instead of firing events on behavior, write flags or indices to a "pending queue" (buffer). Process these queued actions in bulk during a dedicated phase.

---

## Step 3: Hoist Invariants
* **Fix:** Move non-changing variables or global config reads out of loops.
* **Why:** Stops the CPU from making unnecessary, repetitive memory loads on every single iteration (~10% speedup).
* **OOP vs. DOD Pattern:**
  * **Before (OOP):**
    ```cpp
    for (int i = 0; i < count; i++) {
        // BAD: Repeatedly accessing configuration pointer inside hot loop
        float limit = GameManager::GetInstance()->GetConfig()->speedLimit; 
        if (velocities[i] > limit) velocities[i] = limit;
    }
    ```
  * **After (DOD):**
    ```cpp
    float limit = GameManager::GetInstance()->GetConfig()->speedLimit; // Loaded once
    for (int i = 0; i < count; i++) {
        if (velocities[i] > limit) velocities[i] = limit;
    }
    ```

---

## Step 4: Convert Classes to Structs
* **Fix:** Swap class types (reference types) to value-type structs.
* **Why:** Arrays of classes are arrays of pointers to random heap locations. Arrays of structs sit perfectly back-to-back in memory, guaranteeing clean cache lines (~30% speedup).
* **Memory Visualizer:**
  * **Array of Classes (OOP):** `[Pointer] -> [Heap Object A]`, `[Pointer] -> [Heap Object B]`
  * **Array of Structs (DOD):** `[Struct A][Struct B][Struct C]` (Contiguous memory layout)

---

## Step 5: Enforce Memory Alignment
* **Fix:** Order variables declared inside structs from largest data type to smallest.
* **Why:** Prevents the compiler from injecting empty padding bytes to satisfy hardware alignment rules, reducing data structure size (~10% speedup).
* *For detail and code examples, see the dedicated note:* **[[Memory_Alignment]]**

---

## Step 6: Eliminate Strings and Shrink Enums
* **Fix:** Change string IDs to integers (pre-hashed hashes/uint) and explicitly size state enums to a single byte (e.g., `enum class State : uint8_t`).
* **Why:** Strings introduce heap allocation, variable size, and pointer indirection. Shrinking data types decreases the struct size so more elements fit into a cache line (~20% speedup).
* **Example:**
  ```cpp
  // BAD: Large struct
  struct Entity {
      std::string tag; // 32 bytes (indirection to heap string)
      int state;       // 4 bytes
  };

  // GOOD: Small struct
  struct EntityDOD {
      uint32_t tagHash; // 4 bytes (pre-hashed string ID)
      uint8_t  state;    // 1 byte
  };
  ```

---

## Step 7: Use Swap-Back Arrays for Deletion
* **Fix:** Avoid standard list removals (which shift elements down). Instead, copy the last element of the array over the deleted slot, then decrement the array count.
* **Why:** Standard list deletion shifts subsequent elements, causing high memory overhead ($O(n)$). Swap-back arrays perform a single copy operation ($O(1)$), running ~4x faster.
* **C++ Implementation:**
  ```cpp
  void RemoveAt(std::vector<Entity>& list, size_t index) {
      if (index < list.size() - 1) {
          list[index] = list.back(); // Copy last element over target
      }
      list.pop_back(); // Remove last element (fast O(1))
  }
  ```

---

## Step 8: Take Information Out-of-Band
* **Fix:** Remove `if` statements and `switch` blocks inside hot loops. Instead, split entities into distinct arrays based on state (e.g., `activeEnemies[]`, `deadEnemies[]`) and process them sequentially.
* **Why:** Eliminates branch mispredictions, which stall CPU pipelines. Additionally, the state is implied by array membership, allowing you to delete state variables from the struct entirely. This step achieves the final ~40x speedup.
* **OOP vs. DOD Pattern:**
  * **Before (Branching):**
    ```cpp
    for (int i = 0; i < count; i++) {
        if (entities[i].state == ACTIVE) {
            UpdatePhysics(entities[i]); // Branch prediction fails randomly
        }
    }
    ```
  * **After (Out-of-Band):**
    ```cpp
    // No branches, perfect hardware pipelining!
    for (int i = 0; i < activeCount; i++) {
        UpdatePhysics(activeEntities[i]); 
    }
    ```

---
*Back to **[[README]]***
