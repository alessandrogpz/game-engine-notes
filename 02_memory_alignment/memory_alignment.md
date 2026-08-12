# Memory Alignment

This note covers how data alignment, padding, and layout in memory affect structural sizes and CPU cache line packing.

> [!NOTE]
> **In this folder**
> * [`alignment.cpp`](./alignment.cpp) — Size comparison of aligned vs. padded structures.

---

## What is Memory Alignment?

CPUs do not read from and write to physical memory in single-byte increments. Instead, they access memory in **word-sized blocks** (typically 4 bytes on 32-bit systems or 8 bytes on 64-bit systems). 

* **Aligned Access:** When a variable of size $N$ bytes is stored at a memory address that is a multiple of $N$, the CPU can retrieve it in a single memory cycle.
* **Unaligned Access:** If data is unaligned (e.g., a 4-byte integer starting at address `0x03`), the CPU must execute two separate memory reads, mask out the unwanted bytes, and merge the remaining bytes. This degrades performance and, on some architectures, causes hardware exceptions.

---

## Compiler Padding

To guarantee that variables are aligned at addresses corresponding to their type size, compilers automatically inject empty **padding bytes** inside and at the end of structures.

### Member Ordering Rule
To minimize padding bytes and reduce structure size:
> **Declare struct members in order from largest data type size to smallest.**

---

### Code Demonstration: Struct Alignment & Size
Compare the sizes of the two structures implemented in [alignment.cpp](./alignment.cpp):

#### 1. Bad Layout (12 Bytes)
```cpp
struct BadLayout {
    char a;    // 1 byte
    // (3 padding bytes injected here so 'b' starts at a 4-byte boundary)
    int b;     // 4 bytes
    char c;    // 1 byte
    // (3 padding bytes injected at the end to make structure multiple of 4 bytes)
}; // Total size: 12 bytes
```
* **Memory Visualizer:**
  `[a][pad][pad][pad][ b ][ b ][ b ][ b ][c][pad][pad][pad]`
* *Code Link:* [BadLayout struct](./alignment.cpp#L3-L7)

#### 2. Good Layout (8 Bytes)
```cpp
struct GoodLayout {
    int b;     // 4 bytes
    char a;    // 1 byte
    char c;    // 1 byte
    // (2 padding bytes injected at the end to round up to a 4-byte boundary)
}; // Total size: 8 bytes
```
* **Memory Visualizer:**
  `[ b ][ b ][ b ][ b ][a][c][pad][pad]`
* *Code Link:* [GoodLayout struct](./alignment.cpp#L9-L13)

### Performance Impact
By ordering from largest to smallest, we save **4 bytes per struct** (a 33% size reduction). At scale:
* **10,000 entities:** Saves **40 KB** of memory.
* **Cache Line Packing:** More struct instances fit into a single 64-byte cache line, reducing the number of cache misses during array iteration.

---
*Back to **[README](../README.md)***
