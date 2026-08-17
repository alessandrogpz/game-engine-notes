# Networking

Multiplayer as an engine subsystem — only relevant if the games you want require it, but if
they do, it constrains architecture deeply enough that retrofitting is painful.

> [!NOTE]
> **No notes yet.** This domain is at the roadmap stage. The plan — subjects, resources, and
> the order to take them in — is in [00_Roadmap.md](00_Roadmap.md).

---

## Planned subjects

| Subject | Covers |
| :--- | :--- |
| `01_Transport_Foundations` | UDP vs TCP, loss and jitter, reliability layers, bandwidth budgets |
| `02_Network_Models` | Client-server vs peer-to-peer, authoritative servers, deterministic lockstep |
| `03_State_Synchronization` | Snapshot interpolation, delta compression, relevancy, bit packing |
| `04_Latency_Hiding` | Client-side prediction, reconciliation, lag compensation, rollback |
| `05_Determinism` | Cross-platform floating point, fixed point, deterministic simulation |
| `06_Security_and_Operations` | Server-side validation, cheat vectors, matchmaking, hosting |

Subjects gain `Concepts/`, `Exercises/` and `Assets/` folders as work begins.

