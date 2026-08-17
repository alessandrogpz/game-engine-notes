# Concurrency and Parallelism

Using more than one core without introducing bugs that only appear on someone else's machine.

---

## Subjects

| Subject | Status | Contents |
| :--- | :--- | :--- |
| [01_Foundations](01_Foundations/README.md) | **Under study** | 2 notes and a runnable simulation |
| `02_Memory_Model` | Planned | Acquire/release, reordering, atomics, cache coherence |
| `03_Job_Systems` | Planned | Task graphs, work stealing, fibers, frame pipelining |
| `04_Lock_Free_Structures` | Planned | SPSC and MPMC queues, the ABA problem |
| `05_Parallel_Patterns_in_Engines` | Planned | Render vs simulation threads, buffering, async loading |

---

## Foundations at a glance

| Note | Covers |
| :--- | :--- |
| [Concurrency_Cpp17](01_Foundations/Concurrency_Cpp17.md) | Threads, join/detach, races and ThreadSanitizer, mutexes, atomics, condition variables, deadlock |
| [Concurrency_Glossary](01_Foundations/Concurrency_Glossary.md) | One-line lookup for each class and function |
| [multi_threading.cpp](01_Foundations/multi_threading.cpp) | Chef-customer queue simulation |

---

## Related

* [00_Roadmap.md](00_Roadmap.md) — the remaining subjects, resources, and why a job system
  comes before lock-free programming
* [Multi_Threading](../08_Systems_and_Performance/01_Data_Oriented_Design/03_Multi_Threading/Multi_Threading.md)
  — false sharing, the hardware side of the same story
