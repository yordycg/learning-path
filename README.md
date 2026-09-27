# Systems & Data Engineering Learning Path

This repository serves as a personal sandbox and centralized codebase for my transition from Computer Science student to Backend & Systems Engineer (with ongoing post-graduation specializations in Data Engineering, Cloud/K8s, and Mobile).

It contains code snippets, atomic exercises, conceptual proofs of concept (PoCs), and daily algorithm practices.

---

## Strategic Roadmap & Sources

- **Roadmap:** [`docs/roadmap.md`](./docs/roadmap.md) — Two-Stage strategic plan: Pre-Graduation (Phases 1–5 + Career Buffer, Go Backend focus) and Post-Graduation Specializations (A: Data Engineering, B: Cloud & K8s, C: Mobile KMP).
- **Verified Sources:** [`docs/SOURCES.md`](./docs/SOURCES.md) — Exhaustive catalog of verified learning resources, official documentation, courses, and design papers.
- **Calendar & Dedication:** [`calendario.md`](./calendario.md) — Seasonal model (University semester vs. Vacation AI sprint) and 20h/week study structure.

---

## Tech Stack & Tools

- **Languages:** C, Go, Python, SQL (PostgreSQL)
- **Infrastructure & Systems:** Linux (Arch/Fedora), Docker, Redis, Apache Kafka, Kubernetes
- **Data Engineering:** dbt, DuckDB, Polars
- **Development Environment:** Neovim, Tmux, Makefiles, GDB, Valgrind, Just

---

## Repository Structure

The repository is organized by active modules, planned roadmap phases, and standalone projects:

### Active Modules & Projects
- [`projects/`](./projects/) — Standalone roadmap projects (e.g., [`projects/mysh/`](./projects/mysh/)) managed as independent Git repositories with their own commit history, source code (`src/`), build system (`Makefile`), and architecture docs (`docs/`).
- [`learning-c/`](./learning-c/) — Linux Internals, Memory Management (Stack/Heap), Syscalls, IPC, Signals (Phase 1, complete up to `mysh v2.0`).
- [`learning-dsa/`](./learning-dsa/) — Data Structures & Algorithms (criterio de selección), implemented in C (S6–S10; future: Go, graphs).

### Planned Roadmap Modules (Created on module arrival)
- `learning-go/` — Go fundamentals, Concurrency (Goroutines, Channels), idiomatic error handling, testing (TDD), and HTTP stdlib (Phase 2).
- `learning-postgres/` — Advanced SQL, schema design, ER modeling, index analysis (`EXPLAIN ANALYZE`), and transaction isolation (Phase 2).
- `learning-distributed/` — Containerization (Docker Compose), caching (Redis), resilience patterns (Circuit Breaker, Rate Limiting), and observability (Prometheus, OpenTelemetry) (Phase 3).
- `learning-architecture/` — Software Architecture, DDD pragmático, System Design fundamentals, and Design Patterns (GoF pragmático) (Phase 4).
- `learning-data-engineering/` — Event streaming (Kafka KRaft), analytics engines (DuckDB), data transformation (dbt), and pipeline architectures (Lambda/Kappa) (Post-Graduation Specialization A).

### Sister Repositories
- [`ai-learning-path`](../ai-learning-path/) — AI Engineering track (LLMs, RAG, Agentic Systems, Evaluation, Production). Operates in seasonal blocks during vacation periods.

---

## Ergonomía de Ejecución (`Justfile`)

El repositorio cuenta con recetas automáticas para compilar y probar código sin teclear flags manuales:

```bash
just              # Lista las recetas disponibles
just run <file>   # Compila y ejecuta con ASan + UBSan en C, o -race en Go
just test <file>  # Ejecuta y valida el código de retorno ($?)
just check <file> # Comprobación de sintaxis estática rápida
just mysh         # Compila el proyecto semanal mysh
just clean        # Limpia binarios generados en build/
```

---

## Core Principles Applied

1. **No Code Spoonfed:** All logic, pointers, and structures are written manually. No dependency on AI code generation tools for foundational learning.
2. **20% Theory / 80% Practice:** Concepts read in books and tutorials are immediately translated into compile-ready or executable code.
3. **Architecture When it Hurts:** Patterns are introduced only when structural problems arise in the code, never prematurely.
4. **Structured Documentation:** Every atomic topic is backed by conceptual notes, located in my Obsidian vault.

---

## Key References

- *The C Programming Language* (K&R) — Kernighan & Ritchie
- *Computer Systems: A Programmer's Perspective* (CS:APP) — Bryant & O'Hallaron
- *Designing Data-Intensive Applications* (DDIA) — Martin Kleppmann
- *The Go Programming Language* — Alan Donovan & Brian Kernighan
- *Learn Go with Tests* — Chris James
- *Practical Python Programming* — David Beazley
- *Architecture Patterns with Python* ("Cosmic Python") — Percival & Gregory
- See [`docs/SOURCES.md`](./docs/SOURCES.md) for the complete, verified bibliography.
