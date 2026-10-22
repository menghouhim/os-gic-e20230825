# Class Activity 1 — System Calls in Practice

- **Student Name:** Him Menghou
- **Student ID:** e20230825
- **Date:** October 22, 2026

---

## Task 1: File Creator & Reader

### Part A — File Creator
**Questions:**
1. **What flags did you pass to `open()`? What does each flag mean?**
   > `O_WRONLY` (write only), `O_CREAT` (create if it doesn't exist), `O_TRUNC` (truncate/overwrite if it already exists).
2. **What is `0644`? What does each digit represent?**
   > It sets file permissions. `6` = owner can read/write. `4` = group can read. `4` = others can read.
3. **What does `fopen("output.txt", "w")` do internally that you had to do manually?**
   > `fopen` handles the `open()` system call internally, but it also allocates a memory buffer and sets up a `FILE` structure to manage the file stream.

### Part B — File Reader
**Questions:**
1. **What does `read()` return? How is this different from `fgets()`?**
   > `read()` returns the exact number of bytes read (an integer). `fgets()` returns a pointer to the string.
2. **Why do you need a loop when using `read()`? When does it stop?**
   > `read()` only reads up to the buffer size. You need a loop to read the whole file. It stops when `read()` returns `0` (End of File).

---

## Task 2: Directory Listing & File Info

**Questions:**
1. **What struct does `readdir()` return? What fields does it contain?**
   > It returns a `struct dirent *`. It contains fields like `d_name` (the filename) and `d_ino` (inode number).
2. **What information does `stat()` provide beyond file size?**
   > It provides file permissions, owner/group IDs, file type, and modification times.
3. **Why can't you `write()` a number directly — why do you need `snprintf()` first?**
   > `write()` only accepts raw bytes/characters. It cannot format numbers. `snprintf()` converts the number into a formatted string first.

---

## Task 3: strace Analysis

**Questions:**
1. **How many system calls does the library version make compared to the system call version?**
   > The library version makes significantly more system calls (usually 30+), while the system call version makes very few (around 4).
2. **What extra system calls appear in the library version? What do they do?**
   > It shows `mmap`, `brk`, `fstat`, and `access`. These are used to load shared libraries (`libc.so`) and allocate memory for buffering.
3. **How many `write()` calls does `fprintf()` actually produce?**
   > Usually just **one** `write()` call. `fprintf()` buffers the text in memory and only writes it to the file when `fclose()` is called.
4. **In your own words, what is the real difference between a library function and a system call?**
   > A library function (like `printf`) runs in user space and handles formatting and buffering. A system call (like `write`) goes directly to the OS kernel to perform hardware operations.

---
## Reflection
This activity helped me understand what happens "under the hood" when I use simple C functions. It was surprising to see how many system calls `printf` actually makes compared to a direct `write()`.
