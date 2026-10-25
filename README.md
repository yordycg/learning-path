# Systems & Data Engineering Learning Path

Repositorio de estudio autodidacta para la transición de estudiante de Ingeniería en Informática a **Backend Engineer**. El horizonte actual es **oct 2026 – nov 2027** (graduación): el objetivo de este período no es cubrir un temario, es **sentar bases backend empleables y salir al mercado antes de graduarse**.

Contiene ejercicios atómicos, pruebas de concepto, el proyecto `taskapi` y práctica diaria de algoritmos. Las especializaciones (Data Engineering, Cloud/K8s, Mobile) quedan **diferidas a 2028+**, después del primer empleo.

---

## Strategic Roadmap & Sources

- **Roadmap:** [`docs/roadmap.md`](./docs/roadmap.md) — plan en Dos Etapas: Pre-Graduación (Fases 1–5 + Buffer, foco backend Go) y Especializaciones Post-Graduación (diferidas).
- **Sources:** [`docs/SOURCES.md`](./docs/SOURCES.md) — catálogo de recursos verificados por tema, con estado (activo / on demand / diferido).
- **Calendar & Dedication:** [`calendario.md`](./calendario.md) — modelo semestre/vacaciones, regímenes de horas e hitos de empleabilidad.
- **Career (repo aparte):** [`yordycg-portfolio`](https://github.com/yordycg/yordycg-portfolio) — CV, LinkedIn, tracker de postulaciones y búsqueda laboral. No se duplica aquí.

**Regímenes de dedicación:** 18 h/semana efectivas en semestre · 25 h/semana en vacaciones · 8 h en semanas de exámenes.

---

## Tech Stack & Tools

- **Ahora:** C (cerrado como track), Go, SQL (PostgreSQL), Linux, Docker, Git, Just
- **En F2–F3:** Redis, GitHub Actions, Prometheus/Grafana, `pprof`, `dlv`
- **Diferido a 2028+:** Python, Kafka, dbt, DuckDB, Kubernetes, Terraform, KMP
- **Entorno:** Neovim, Tmux, Makefiles, GDB, Valgrind, AddressSanitizer/UBSan

---

## Repository Structure

### Active Modules

- [`learning-dsa/`](./learning-dsa/) — DSA por patrones en Go (2–3 problemas/semana). El track de C (Big-O, dynamic array, linked list) quedó cerrado.
- [`learning-go/`](./learning-go/) — Go just-in-time hacia `taskapi`: Tour + 6 capítulos núcleo (TDD) y el resto on demand.
- [`learning-c/`](./learning-c/) — Linux Internals, memoria, syscalls, IPC y señales. **Cerrado** hasta `mysh v2.0`.
- [`projects/`](./projects/) — Proyectos standalone (e.g. [`projects/mysh/`](./projects/mysh/)) como repos independientes con su build system y documentación.

### Planned Modules (se crean cuando el proyecto los pida)

- `learning-postgres/` — SQL, modelado, índices, `EXPLAIN ANALYZE`, transacciones (F2–F3).
- `learning-infra/` — Docker, CI/CD, deploy, Redis, métricas y logs (F2–F3).
- `learning-taskapi/` — el proyecto estrella de F2–F4 (o `learning-go/taskapi/` si no amerita módulo propio).
- `learning-data-engineering/` — Kafka, DuckDB, dbt, arquitecturas Lambda/Kappa (**2028+**).

### Sister Repositories

- [`yordycg-portfolio`](https://github.com/yordycg/yordycg-portfolio) — CV, LinkedIn, tracker y postulaciones.
- [`ai-learning-path`](../ai-learning-path/) — AI Engineering (LLMs, RAG, agentes). Bloques estacionales en vacaciones, sin competir con la fase activa.


---

## Ergonomía de Ejecución (`Justfile`)

El repositorio cuenta con recetas automáticas para compilar y probar código sin teclear flags manuales:

```bash
just              # Lista las recetas disponibles
just run <file>   # Compila y ejecuta con ASan + UBSan en C, o -race en Go
just test <file>  # Ejecuta y reporta el código de retorno real ($?)
just check <file> # Comprobación estática rápida (gcc / gofmt + go vet)
just test-go      # Todos los tests de learning-go con -race
just bench-go     # Benchmarks de learning-go
just fmt-go       # Aplica gofmt a learning-go
just lint-go      # go vet sobre learning-go
just mysh         # Compila el proyecto semanal mysh
just clean        # Limpia binarios generados en build/
```

---

## Core Principles Applied

1. **No Code Spoonfed:** toda la lógica, punteros y estructuras se escriben a mano. La IA explica conceptos, diagnostica con herramientas y examina; no escribe el código de los ejercicios.
2. **Build First, Theory Just-in-Time:** nada de bloques de teoría previa. Un tema se estudia cuando el proyecto lo exige y se verifica con algo que corre.
3. **Ship It:** cada fase y cada semana terminan con algo desplegado, medido o mergeado. Un proyecto que no se puede levantar ni mostrar no cuenta.
4. **Empleo primario, freelance secundario:** el objetivo del período es el primer empleo de desarrollador; el freelance es un experimento acotado, no un segundo track.
5. **Deep over Broad:** un proyecto estrella bien hecho vale más que cinco a medias. Se recorta alcance antes que duplicar horas.
6. **Structured Documentation:** comentarios en el código y ADRs cortos dentro del proyecto; el vault de Obsidian guarda las notas conceptuales.

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
