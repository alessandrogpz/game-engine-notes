# Networking — Study Roadmap

Multiplayer as an engine subsystem. Only relevant if the games you want require it — but if they do, it constrains architecture deeply enough that retrofitting is painful.

> [!NOTE]
> Placeholder. Skip entirely unless building multiplayer. If you *are*, read the architectural implications early rather than late.

---

## Suggested Subjects

### 01_Transport_Foundations
* UDP vs TCP, and why games almost always build on UDP
* Packet loss, reordering, duplication, jitter
* Reliability layers built over UDP; selective acknowledgement
* Bandwidth budgets and MTU
* Connection handling, timeouts, keep-alives

### 02_Network_Models
* Client-server vs peer-to-peer
* Authoritative server and why it is the default
* Deterministic lockstep — the RTS model
* Trade-offs in bandwidth, latency tolerance and cheat resistance

### 03_State_Synchronization
* Snapshot interpolation
* Delta compression against acknowledged baselines
* Relevancy and interest management
* Quantization and bit packing — connects to [06_Algorithms](../06_Algorithms/README.md)

### 04_Latency_Hiding
The techniques that make an unresponsive medium feel responsive.
* Client-side prediction
* Server reconciliation and replay
* Entity interpolation and extrapolation
* Lag compensation (rewinding for hit detection)
* Rollback netcode for fighting games

### 05_Determinism
* Floating point determinism across compilers and platforms — genuinely hard
* Fixed-point alternatives
* Deterministic simulation as a prerequisite for lockstep and replays

### 06_Security_and_Operations
* Never trust the client; server-side validation
* Common cheat vectors
* Matchmaking, lobbies, dedicated server hosting

---

## Resources

| Resource | Use |
| :--- | :--- |
| [gafferongames.com](https://gafferongames.com/) | Glenn Fiedler. The canonical game networking series — start here |
| [Valve's Source Multiplayer Networking](https://developer.valvesoftware.com/wiki/Source_Multiplayer_Networking) | Prediction and lag compensation, concisely |
| Fabien Sanglard's Quake 3 network write-up | A complete real system, explained |
| GDC rollback netcode talks | If fighting-game-style responsiveness matters |

---

## Suggested Order

Transport foundations → network model choice → state sync → latency hiding. The model choice constrains everything downstream, so make it deliberately and early.
