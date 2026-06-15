# Systems & Data Engineering Learning Path

This repository serves as a personal sandbox and centralized codebase for my 18-month journey transition from Computer Science student to Systems & Data Engineer.

It contains code snippets, atomic exercises, conceptual proofs of concept (PoCs), and daily algorithm practices.

---

## Tech Stack & Tools

- **Languages:** C, Go, Python, SQL (PostgreSQL)
- **Infrastructure & Systems:** Linux (Arch/Fedora), Docker, Redis, Apache Kafka, Kubernetes
- **Data Engineering:** dbt, DuckDB, Polars
- **Development Environment:** Neovim, Tmux, Makefiles, GDB, Valgrind

---

## Repository Structure

The code is organized by technology and core concepts corresponding to the roadmap phases:

- [`learning-c/`](./learning-c/) - Linux Internals, Memory Management (Stack/Heap), Syscalls, IPC, Signals and basic DSA in C.
- [`learning-go/`](./learning-go/) - Go fundamentals, Concurrency (Goroutines, Channels), idiomatic error handling, testing, and HTTP.
- [`learning-postgres/`](./learning-postgres/) - Advanced SQL, schema design, index analysis (`EXPLAIN ANALYZE`), and transaction isolation.
- [`learning-python-base/`](./learning-python-base/) - Python automation scripting, typing (mypy), testing with pytest, and tooling.
- [`learning-distributed/`](./learning-distributed/) - Containerization (Docker Compose), caching (Redis), resilience patterns, and observability (Prometheus, OpenTelemetry).
- [`learning-data-engineering/`](./learning-data-engineering/) - Event streaming (Kafka), analytics database engines (DuckDB), data modeling (dbt), and advanced Python.

---

## Core Principles Applied

1. **No Code Spoonfed:** All logic, pointers, and structures are written manually. No dependency on AI code generation tools for foundational learning.
2. **20% Theory / 80% Practice:** Concepts read in books are immediately translated into compile-ready or executable code.
3. **Architecture When it Hurts:** Patterns are introduced only when structural problems arise in the code, never prematurely.
4. **Structured Documentation:** Every atomic topic is backed by conceptual notes, located in my Obsidian vault.

---

## Key References

- *The C Programming Language* (K&R) - Kernighan & Ritchie
- *Computer Systems: A Programmer's Perspective* (CS:APP) - Bryant & O'Hallaron
- *Designing Data-Intensive Applications* (DDIA) - Martin Kleppmann
- *The Go Programming Language* - Alan Donovan & Brian Kernighan
- *Fluent Python* - Luciano Ramalho

