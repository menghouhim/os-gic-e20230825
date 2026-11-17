# Class Activity 2 — Processes & IPC

- **Student Name:** Him Menghou
- **Student ID:** e20230825

## Task 1: Process Creation on Linux
1. **What does `fork()` return?** It returns 0 to the child process and the child's PID to the parent process.
2. **What happens if you remove `waitpid()`?** The parent might finish and exit before the child, making the child an orphan. The output order would be unpredictable.
3. **What does `execlp()` do?** It replaces the current process image with a new program (`ls`).
4. **Process tree:** Parent -> Child.
5. **Command used:** `ps -ef --forest`.

## Task 2: Process Creation on Windows
1. **Key difference:** Linux uses two steps (`fork` then `exec`), while Windows uses one step (`CreateProcess`).
2. **WaitForSingleObject:** It waits for the child process to finish. The Linux equivalent is `waitpid()`.
3. **CloseHandle:** It releases system resources. If not called, it causes a handle leak.
4. **PIDs:** Parent PID 28736, Child PID 17092.
5. **Task Manager views:** The Processes tab (tree view) is easier to understand the parent-child relationship visually.

## Task 3: Shared Memory IPC
1. **shm_open vs open:** `shm_open` creates a memory object in `/dev/shm`, while `open` opens a file on disk.
2. **mmap:** Maps memory into the process address space. Shared memory is faster because it avoids copying data.
3. **Matching names:** Both processes must use the same name to access the same memory region.
4. **shm_unlink:** Removes the shared memory object. If not called, it stays in memory until restart.
5. **Run consumer first:** It will fail with "No such file or directory".

## Task 4: Message Queue IPC
1. **MQ vs SHM:** Message queues send distinct messages (FIFO), while shared memory is a raw block of data.
2. **Forward slash `/`:** POSIX message queues require a name starting with `/`.
3. **mq_unlink:** Removes the queue. If neither calls it, the queue stays in the system.
4. **Receiver first:** It will fail because the queue doesn't exist yet.
5. **Multiple senders/receivers:** Yes, multiple processes can send to and receive from the same queue.
