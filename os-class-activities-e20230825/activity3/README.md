# Class Activity 3 — Socket Communication & Multithreading

- **Student Name:** Him Menghou
- **Student ID:** e20230825

## Task 1: TCP Socket
1. **Role of `bind()`:** It assigns a specific local IP address and port number to the server socket.
2. **What `accept()` returns:** A new socket file descriptor specifically for communication with the connected client.
3. **Starting client before server:** The client will fail to connect with a "Connection refused" error because no server is listening.
4. **What `htons()` does:** It converts a port number from host byte order to network byte order (big-endian) so it can be sent over the network.
5. **Socket call sequence:** Server: `socket` -> `bind` -> `listen` -> `accept` -> `read/write` -> `close`. Client: `socket` -> `connect` -> `read/write` -> `close`.

## Task 2: POSIX Threads
1. **Race condition:** Multiple threads access and modify `shared_counter` at the same time without synchronization, leading to incorrect results.
2. **What `pthread_mutex_lock()` does:** It locks the mutex, preventing other threads from entering the critical section until it is unlocked.
3. **Removing `pthread_join()`:** The main thread will exit immediately without waiting for the worker threads, causing unpredictable behavior.
4. **Thread vs Process:** Threads share the same memory space (data, heap) but have their own stack and registers; processes have separate memory spaces.

## Task 3: Java Multithreading
1. **Thread vs Runnable:** Extending `Thread` means you cannot extend any other class. Implementing `Runnable` allows you to extend another class and is more flexible.
2. **Pool size limiting concurrency:** The `Executors.newFixedThreadPool(2)` limits the number of active threads to 2, even though 4 tasks are submitted.
3. **`Thread.join()` in Java:** It tells the main thread to wait until the specified thread finishes execution.
4. **ExecutorService advantages:** It manages the thread pool automatically, reducing the overhead of creating and destroying threads manually.

## Task 4: Observing Threads
1. **LWP column:** It stands for Light Weight Process, which represents the thread ID.
2. **/proc/PID/task:** It lists all threads associated with the process.
3. **Extra Java Threads:** Java creates threads like Garbage Collector (GC), JIT Compiler, and Finalizer, which are hidden from the user.
4. **Linux vs Windows Thread viewing:** Linux provides more detailed visibility into thread-specific system calls via `/proc` and `ps -L`.
5. **kthreadd and kernel threads:** `kthreadd` (PID 2) is the parent of all kernel threads. You can see them in `ps --ppid 2`.
6. **TID vs PID:** For a single-threaded program, the TID and PID are the same. For a multi-threaded program, each thread has its own TID but shares the same PID.
7. **`H` and `K` in htop:** `H` toggles the display of user threads, and `K` toggles the display of kernel threads.
