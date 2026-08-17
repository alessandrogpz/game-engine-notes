# Concurrency and Parallelism — Study Roadmap

Using more than one core without introducing bugs that only appear on someone else's machine. Modern engines are fundamentally parallel; this stops being optional quickly.

> [!NOTE]
> [01_Foundations](01_Foundations/README.md) is populated. The remaining subjects are placeholders.
> What already exists in this domain is indexed in [README.md](README.md); this file is the plan
> for what does not.

---

## Suggested Subjects

### 01_Foundations — *in progress*
* [Concurrency_Cpp17](01_Foundations/Concurrency_Cpp17.md) — launching threads, join/detach, race conditions and ThreadSanitizer, mutexes and lock granularity, atomics, the cost of synchronization, condition variables, deadlock, and what C++20 adds
* [Concurrency_Glossary](01_Foundations/Concurrency_Glossary.md) — one-line lookup for each class and function
* [multi_threading.cpp](01_Foundations/multi_threading.cpp) — chef-customer queue simulation

Still to cover: why raw threads are the wrong abstraction for a frame loop; livelock and priority inversion.

### 02_Memory_Model
The part that is genuinely hard and genuinely necessary.
* Sequential consistency, acquire/release, relaxed ordering
* Compiler and CPU reordering; why "it works on my machine" proves nothing
* Atomics and compare-and-swap
* Cache coherence, and false sharing — mechanism covered in [Multi_Threading](../08_Systems_and_Performance/01_Data_Oriented_Design/03_Multi_Threading/Multi_Threading.md)

### 03_Job_Systems
How engines actually parallelize.
* Task graphs and dependencies
* Work stealing schedulers
* Fibers vs threads — Naughty Dog's approach
* Frame pipelining; parallel-for over entity arrays
* Determinism under parallel execution

### 04_Lock_Free_Structures
* SPSC and MPMC queues
* The ABA problem
* When lock-free is worth it — usually less often than it seems

### 05_Parallel_Patterns_in_Engines
* Render thread vs simulation thread; command buffer recording
* Double/triple buffering of state
* Async asset loading and streaming
* GPU as an asynchronous device: fences, semaphores, frames in flight

---

## Resources

| Resource | Use |
| :--- | :--- |
| Williams, *C++ Concurrency in Action* (2nd ed) | The standard C++ text. Read the memory model chapters twice |
| [preshing.com](https://preshing.com/) | The clearest writing anywhere on memory ordering and lock-free |
| Gyrling, *Parallelizing the Naughty Dog Engine* (GDC 2015) | The canonical fiber-based job system talk |
| Fedor Pikus, CppCon talks | Practical lock-free, with honest benchmarks |

---

## Suggested Order

Foundations → memory model → job system → (only then) lock-free. Build a job system before reaching for atomics; most parallelism in an engine is expressed as tasks, not as hand-written synchronization.

> [!WARNING]
> Concurrency bugs are the least reproducible class of bug you will meet. Invest early in deterministic replay, thread sanitizers and stress tests rather than debugging by inspection.
