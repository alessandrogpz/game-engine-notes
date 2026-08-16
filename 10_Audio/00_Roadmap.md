# Audio — Study Roadmap

A smaller domain than rendering, but a real-time system with harder latency constraints and no tolerance for a dropped buffer.

> [!NOTE]
> Placeholder. Lower priority than rendering, physics and architecture — but note that audio glitches are more noticeable to players than a dropped frame.

---

## Suggested Subjects

### 01_Digital_Audio_Foundations
* Sampling rate, bit depth, PCM
* Nyquist and aliasing — shares theory with [signal processing](../01_Mathematics/00_Roadmap.md)
* Buffers, callbacks and the real-time audio thread
* **The cardinal rule:** no allocation, no locks, no I/O on the audio callback

### 02_Mixing_and_Playback
* Summing, gain staging, clipping
* Sample rate conversion and resampling
* Voice management and prioritization
* Streaming long assets vs fully loaded short ones

### 03_Spatial_Audio
* Panning, distance attenuation, Doppler
* HRTF and binaural rendering
* Occlusion, obstruction, reverb zones
* Ambisonics conceptually

### 04_DSP_Effects
* Filters: low-pass, high-pass, biquads
* Delay, reverb, compression
* Convolution reverb; FFT-based processing

### 05_Engine_Integration
* Event-driven audio design rather than "play this file"
* Middleware concepts: FMOD, Wwise
* Music systems: layering, stingers, adaptive transitions

---

## Resources

| Resource | Use |
| :--- | :--- |
| [miniaudio](https://miniaud.io/) | Single-header library, small enough to read and learn from |
| Zölzer, *DAFX: Digital Audio Effects* | The effects reference |
| Ross Bencina, *Real-time audio programming 101* | The definitive "what not to do on the audio thread" article |
| Wwise / FMOD documentation | How production audio is actually authored |

---

## Suggested Order

Foundations and the real-time constraint first, then simple mixing, then spatialization, then effects. Getting a clean sine wave out with no glitches teaches more than it sounds like it should.
