# Phase 1 — Linux Internals, C & DSA Fundamentals

This phase covers the absolute foundations of systems programming. By working with C, manual memory management, and Unix system calls, you will demystify how hardware executes code and how the operating system manages resources.

> **Re-baseline (2026-08):** Phase 1 was extended to ~4.5 months (Jun 14 – Oct 18 2026). The weekly recovery plan (S0–S10) is below.

---

## Progress Tracker

> Structure mirrors the Obsidian C vault in 3 language levels + a systems track. Numbers = study order within each level.

| Directory | Topic | Status |
|-----------|-------|--------|
| `chapter-01/` | K&R chapter 01 exercises (hello, vars, loops, I/O, functions) | ✅ done |
| `1-basics/06-functions/` | Functions, params/args (Beej 4, 18.1) | 🔄 in progress — file empty, fill it |
| `1-basics/07-arrays/` | Arrays, array length, arrays to functions, matrix (Beej 6) | ✅ done |
| `1-basics/08-strings/` | Strings: pointer vs array notation, `strlen`, `strcpy` (Beej 7) | ✅ done |
| `2-advanced/01-pointers/` | Pointer basics, pointers & arrays, pointers & functions (Beej 5) | 🟡 pending: pointer arithmetic, `void*`, double pointers (Beej 11, 23) |
| `2-advanced/02-structs/` | Structs, initializers, copy, arrow operator (Beej 8) | ✅ done |
| `2-advanced/07-file-io/` | File I/O: read/write text, formatted, binary (Beej 9) | ✅ done |
| `2-advanced/05-memory-management/` | Stack vs Heap, `malloc`/`calloc`/`realloc`/`free`, valgrind (Beej 12) | 🔴 not started |
| `2-advanced/11-tooling/` | Makefile rules, targets, dependencies, variables | 🔴 not started |
| `4-systems/01-syscalls-processes/` | `open`/`read`/`write`/`close`, `fork`/`exec`/`wait`, zombies (K&R 8) | 🔴 not started |
| `3-expert/07-signals/` | `SIGINT`, `SIGTERM`, `SIGCHLD`, `SIGPIPE` (Beej 29) | 🔴 not started |
| `4-systems/02-pipes-ipc/` | `pipe()`, FIFOs | 🔴 not started |
| `4-systems/03-file-descriptors/` | FDs under the hood, `dup`/`dup2`, redirection | 🔴 not started |
| `2-advanced/11-tooling/` | GDB (breakpoints, backtrace, watch), Valgrind | 🔴 not started |
| `3-expert/02-dsa/` | Dynamic array, linked list, stack, queue, hash table, binary search, sorting | 🔴 not started |

**Legend:** ✅ done · 🟡 partial (see notes) · 🔄 in progress · 🔴 not started

---

## Recovery Plan F1 (S0–S10)

> Re-baseline plan (2026-08). Weeks run Monday→Sunday; S0 is partial (Wed Aug 5 – Sun Aug 9). Every week: 1 atomic commit, compile with `-Wall -Wextra -g`, and run valgrind on anything using dynamic memory. Day-by-day detail stays flexible in Obsidian; this table is the tracker.

| Week | Dates | Topic | Resource | Deliverable | ✔ |
|------|-------|-------|----------|-------------|---|
| S0 | Aug 5–9 | Prep (mid-week start) | Beej 9–11 | Base Makefile `-Wall -Wextra -g`, valgrind OK, commit | [ ] |
| S1 | Aug 10–16 | Stack/Heap + `malloc`/`free` | Beej 12, 12.4–12.5 | alloc with NULL check, `binary_search`, valgrind | [ ] |
| S2 | Aug 17–23 | Syscalls + FDs | K&R 8, `man 2` | `open/read/write/close`, `dup2`; **mysh v0.5** (read + parse + builtins) | [ ] |
| S3 | Aug 24–30 | Processes | K&R 8, Sorber (fork) video | `fork/exec/wait`, zombies; **mysh v1.0** (no `system()`) | [ ] |
| S4 | Aug 31 – Sep 6 | Signals | Beej 29 + videos | `sigaction`; **mysh v1.5** (Ctrl+C only kills child) | [ ] |
| S5 | Sep 7–13 | Pipes / IPC | Sorber (pipe) video | `pipe()`, FIFOs; **mysh v2.0** (`cmd1 \| cmd2 \| cmd3`) | [ ] |
| S6 | Sep 14–20 | GDB deep dive | Sorber (debug) videos | `watch`/`bt`, valgrind on shell; **mysh v2.5** (`>` `<` `>>`) | [ ] |
| S7 | Sep 21–27 | DSA: linked list | Beej 20.3 + Fiset | linked list from scratch; **mysh v3.0** (history) | [ ] |
| S8 | Sep 28 – Oct 4 | DSA: stack + queue | Fiset | manual stack and queue | [ ] |
| S9 | Oct 5–11 | DSA: hash table + sorting | Beej 24 + Fiset | hash (separate chaining), merge sort | [ ] |
| S10 | Oct 12–18 | Integration & close | — | full mysh demo + Phase 1 checklist done | [ ] |

> Beej resource: [beej.us/guide/bgc](https://beej.us/guide/bgc/html/split/index.html). Beej does NOT cover syscalls/processes/pipes/GDB/makefiles: those come from roadmap videos, `man 2`, and K&R ch. 8.

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
- [Beej's Guide to C](https://beej.us/guide/bgc/html/split/index.html) – main C language resource for Phase 1.
- Linux Man Pages – Sections 2 (`man 2 syscall`) and 3 (`man 3 library`).
