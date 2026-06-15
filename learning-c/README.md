# Phase 1 — Linux Internals, C & DSA Fundamentals

This phase covers the absolute foundations of systems programming. By working with C, manual memory management, and Unix system calls, you will demystify how hardware executes code and how the operating system manages resources.

---

## Phase 1 Syllabus & Checklist

Use this checklist to track your progress as you create and complete each directory:

- [ ] **`01-memory-pointers/`**
  - [ ] Pointer arithmetic and dereferencing.
  - [ ] Double pointers (pointers to pointers) and their applications.
- [ ] **`02-stack-heap/`**
  - [ ] Stack vs. Heap memory models.
  - [ ] Dynamic memory allocation (`malloc`, `calloc`, `realloc`, `free`).
  - [ ] Finding memory leaks and invalid writes using `valgrind`.
- [ ] **`03-makefiles/`**
  - [ ] Makefile rules, targets, dependencies, and variables.
  - [ ] Clean, build, and run automation.
- [ ] **`04-syscalls-processes/`**
  - [ ] Direct kernel interactions via syscalls (`open`, `read`, `write`, `close`).
  - [ ] Process creation and control (`fork`, `execve`, `wait`, `waitpid`).
  - [ ] Managing zombie and orphan processes.
- [ ] **`05-signals/`**
  - [ ] UNIX signal concepts and handlers (`SIGINT`, `SIGTERM`, `SIGCHLD`, `SIGPIPE`).
- [ ] **`06-pipes-ipc/`**
  - [ ] Inter-Process Communication (IPC).
  - [ ] Unidirectional pipes (`pipe()`) and named FIFOs.
- [ ] **`07-file-descriptors/`**
  - [ ] Under-the-hood analysis of File Descriptors (FD).
  - [ ] Standard I/O redirection (`dup`, `dup2`).
- [ ] **`08-debugging-gdb/`**
  - [ ] Debugging segfaults, checking variables, and stack frames using `gdb`.
- [ ] **`09-dsa-fundamentals/`**
  - [ ] Manually implementing DSA in C:
    - [ ] Dynamic Array (vector)
    - [ ] Singly Linked List
    - [ ] Stack and Queue
    - [ ] Hash Table (separate chaining)
    - [ ] Binary Search ($O(\log N)$)
    - [ ] Sorting ($O(N^2)$ vs $O(N \log N)$)

---

## Phase 1 Project: mysh

A mini UNIX shell written from scratch in C.

### Requirements:
- Execute external commands with `fork` + `exec` (no usage of `system()`).
- Handle I/O redirection (`>`, `<`, `>>`) and multi-stage pipes (`cmd1 | cmd2 | cmd3`).
- Custom signal handling (e.g., `Ctrl+C` kills the child process, not the shell).
- Command history managed via your custom Singly Linked List.
- Built-in commands: `cd`, `exit`, `echo`.

---

## Key Reference Materials

- *The C Programming Language* (K&R) – Chapters 1 to 8.
- *Computer Systems: A Programmer's Perspective* (CS:APP) – Chapters 1 to 9.
- *The Algorithm Design Manual* (Skiena) – Chapters 1 to 4.
- Linux Man Pages – Sections 2 (`man 2 syscall`) and 3 (`man 3 library`).
