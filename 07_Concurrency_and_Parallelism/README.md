# Concurrency and Parallelism

## Subjects

| Subject | Covers |
| :--- | :--- |
| [01_Foundations](01_Foundations/README.md) | Threads, mutexes, atomics, condition variables, deadlock |
| `02_Memory_Model` | Acquire/release, reordering, atomics, cache coherence |
| `03_Job_Systems` | Task graphs, work stealing, fibers, frame pipelining |
| `04_Lock_Free_Structures` | SPSC and MPMC queues, the ABA problem |
| `05_Parallel_Patterns_in_Engines` | Render vs simulation threads, buffering, async loading |

[00_Roadmap.md](00_Roadmap.md) covers the planned subjects and why a job system comes before
lock-free programming.

---

## Foundations at a glance

| Note | Covers |
| :--- | :--- |
| [Concurrency_Cpp17](01_Foundations/Concurrency_Cpp17.md) | Threads, join/detach, races and ThreadSanitizer, mutexes, atomics, condition variables, deadlock |
| [Concurrency_Glossary](01_Foundations/Concurrency_Glossary.md) | One-line lookup for each class and function |
| [multi_threading.cpp](01_Foundations/multi_threading.cpp) | Chef-customer queue simulation |

