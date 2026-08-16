# C++ Concurrency Glossary

A quick-reference guide to all the multithreading concepts, classes, and functions we have covered so far. Standard versions are marked per entry.

> [!NOTE]
> **In this folder**
> * [`concurrency_cpp17.md`](./concurrency_cpp17.md) — The full explanation behind every entry here, with synchronization cost measurements.
> * [`multi_threading.md`](./multi_threading.md) — The DOD angle: why a fast program avoids these primitives in hot loops.
> * [`multi_threading.cpp`](./multi_threading.cpp) — Chef-customer queue simulation.

---

## 1. Threads & Execution

### `std::jthread` (C++20)
*   **Concept:** A "Joining Thread" that manages an asynchronous thread of execution.
*   **Key Feature:** Automatically waits for the thread to finish (`join()`) when the object is destroyed (goes out of scope), preventing program crashes.
*   **Usage:**
    ```cpp
    std::jthread worker_thread(function_name, arg1, arg2);
    ```

### `std::this_thread` (Namespace)
*   **Concept:** A utility namespace containing helper functions that interact with the **currently running** thread executing that line of code.
*   **Key Functions:**
    *   `std::this_thread::sleep_for(duration)`: Pauses execution of the current thread for a set time (e.g., `200ms`, `2s`).
    *   `std::this_thread::get_id()`: Returns the unique operating system ID of the current thread.

---

## 2. Synchronization & Mutexes

### `std::mutex` ("Mutual Exclusion")
*   **Concept:** A lock used to protect shared resources (variables, printing, etc.) from being accessed by more than one thread at the same time.
*   **Usage:**
    ```cpp
    std::mutex mtx;
    ```

### `std::lock_guard` (C++11)
*   **Concept:** A simple, lightweight wrapper that locks a mutex when created and automatically unlocks it when it goes out of scope (destructor runs).
*   **Best for:** Standard, quick critical sections (like protecting log printing).
*   **Usage:**
    ```cpp
    {
        std::lock_guard<std::mutex> lock(mtx); // Locked
        // Safe operations here
    } // Unlocked automatically
    ```

### `std::unique_lock` (C++11)
*   **Concept:** A more advanced and flexible lock wrapper. Unlike `std::lock_guard`, it allows you to manually call `.lock()` and `.unlock()` anywhere in the code.
*   **Best for:** Complex coordination (required when using `std::condition_variable`).
*   **Usage:**
    ```cpp
    std::unique_lock<std::mutex> lock(mtx);
    lock.unlock(); // Can unlock manually early
    ```

### Template Type Deduction (CTAD - C++17)
*   **Concept:** In modern C++ (C++17/20/23), you do not need to specify `<std::mutex>` when creating lock wrappers. The compiler automatically deduces the type from the constructor argument.
*   **Shorthand Usage:**
    ```cpp
    std::lock_guard lock(mtx);  // Deduced as std::lock_guard<std::mutex>
    std::unique_lock lock(mtx); // Deduced as std::unique_lock<std::mutex>
    ```

---

## 3. Data Safety

### `std::atomic<T>`
*   **Concept:** A wrapper that makes operations on a single variable (e.g., `int`, `bool`) thread-safe at the hardware/CPU level without needing a mutex.
*   **Best for:** Simple flag changes or simple mathematical counters.
*   **Key Functions:**
    *   `var.load()`: Safely reads the atomic value.
    *   `var.store(val)`: Safely writes a new value to the atomic variable.
*   **Usage:**
    ```cpp
    std::atomic<int> counter = 0;
    counter++; // Safe atomic increment
    ```

---

## 4. Thread Coordination

### `std::condition_variable`
*   **Concept:** A coordination tool that allows threads to safely sleep (wait) until notified by another thread that a condition is met. Prevents CPU-burning busy loops.
*   **Key Functions:**
    *   `cv.wait(unique_lock, predicate)`: Puts the thread to sleep. It temporarily unlocks the mutex. When woken up, it checks if the `predicate` (boolean condition) is true. If true, it re-locks the mutex and continues.
    *   `cv.notify_one()`: Wakes up exactly **one** thread that is currently sleeping on this condition variable. Excellent for resource sharing (like a free dongle) where only one thread can consume the resource, avoiding CPU waste.
    *   `cv.notify_all()`: Wakes up **all** threads currently sleeping on this condition variable. Excellent for global events where every thread needs to act (such as stopping the entire simulation).
*   **Usage:**
    ```cpp
    std::condition_variable cv;
    // To wait:
    cv.wait(lock, []() { return is_ready; });
    // To wake up one thread:
    cv.notify_one();
    // To wake up all threads:
    cv.notify_all();
    ```

---

## 5. Timing & Duration (`<chrono>`)

### `std::chrono::steady_clock`
*   **Concept:** A monotonic clock that is guaranteed to never go backward (behaves like a stopwatch). Perfect for measuring durations and deadlines in simulations.
*   **Usage:**
    ```cpp
    auto start = std::chrono::steady_clock::now();
    ```

### `std::chrono_literals` (Namespace)
*   **Concept:** Allows you to write clean time values using suffixes (e.g. `2s`, `250ms`).
*   **Usage:**
    ```cpp
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(500ms);
    ```

---
*Back to **[multi_threading](./multi_threading.md)** · **[README](../README.md)***
