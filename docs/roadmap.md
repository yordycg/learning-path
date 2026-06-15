# Roadmap 18 Meses — Backend & Data Engineer
> **Sistema de mentoreo personal** | Ingeniería en Informática 3er año → Junior Backend/Data Engineer  
> Duración: 18 meses · ~25 horas semanales · Linux (Arch/Fedora) · Neovim · Warp terminal

---

## Principios del roadmap

1. **No code spoonfed** — arquitectura, diagramas y pseudocódigo primero. La lógica la escribes tú.
2. **20% teoría / 80% práctica** — cada concepto se traduce inmediatamente en código o terminal.
3. **Fundamentos atemporales** — cero dependencia de modas de IA.
4. **Todo en inglés** — código, variables, commits, documentación, READMEs.
5. **Arquitectura cuando duele** — los patrones y diseño de sistemas se estudian cuando el problema ya existe en tu código, nunca antes.
6. **Dos lenguajes complementarios** — Go para Backend (sistemas, APIs, alto throughput) + Python para Data Engineering (pipelines, transformaciones, ecosistema de datos). No compiten: se complementan exactamente en el mercado que apuntas.

---

## Vista general de las 6 fases

| Fase | Período | Foco principal | Stack |
|------|---------|----------------|-------|
| F1 | Meses 1–3 | Linux Internals, C & DSA Fundamentos | C, GCC, Makefiles, Linux Syscalls, DSA básico |
| F2 | Meses 4–6 | Go + Python base + PostgreSQL Avanzado | Go, Python, PostgreSQL, sqlx, seguridad básica |
| F3 | Meses 7–9 | Sistemas Distribuidos + Docker + Redis + Observabilidad | Docker, Redis, CI/CD, OpenTelemetry |
| F4 | Meses 10–12 | Data Engineering + Python Experto | Python avanzado, Kafka, dbt, DuckDB |
| F5 | Meses 13–15 | System Design, Arquitectura Formal & DDD | CQRS, Event Sourcing, Saga, K8s conceptual, DDD |
| F6 | Meses 16–18 | Portfolio, OSS, IA en proyectos & Job Hunt | Capstone, RAG básico, entrevistas |

---

## Cuándo entra cada disciplina transversal

```
DSA
├── F1 (M1-3)  → Arrays, punteros, complejidad O(N), linked lists en C
├── F2 (M4-6)  → Hashmaps, árboles binarios, sorting en Go
├── F3 (M7-9)  → Grafos básicos, consistent hashing (contexto real)
└── F6 (M16-18)→ Repaso para entrevistas, 80 problemas Leetcode

Modelado
├── F2 (M4-6)  → Modelado de datos: ER diagrams, normalización, schema design
└── F5 (M13-15)→ Modelado de dominio: DDD básico, bounded contexts, ubiquitous language

Infraestructura
├── F3 (M7-9)  → CI/CD con GitHub Actions (build, test, lint automático)
├── F5 (M13-15)→ Kubernetes conceptual (para hablar en entrevistas)
└── F6 (M16-18)→ Terraform básico (opcional, si el tiempo lo permite)

Observabilidad
└── F3 (M7-9)  → Logs estructurados JSON + métricas Prometheus + tracing OpenTelemetry

Seguridad
└── F2 (M4-6)  → OWASP Top 10 aplicado, secrets management, autenticación correcta

IA como herramienta de desarrollo
├── F2 (M4-6)  → Cómo usar IA con criterio: verificar, no confiar ciegamente
└── F6 (M16-18)→ Integrar APIs de IA en proyectos (embeddings, RAG básico)

Comunicación técnica escrita
└── F5 (M13-15)→ ADRs, RFCs, post-mortems, propuestas técnicas

Arquitectura y patrones
├── F2 (M4-6)  → Repository Pattern (cuando la API crece)
├── F3 (M7-9)  → Circuit Breaker, Retry, Cache-aside
├── F4 (M10-12)→ Lambda Architecture, Kappa Architecture
└── F5 (M13-15)→ System Design formal: CQRS, Event Sourcing, Saga, Microservicios
```

> **Regla de oro:** estudia un patrón la semana que lo necesitas en tu proyecto, no antes.

---

## Horario semanal base (aplica a todas las fases)

| Día | Bloque | Actividad |
|-----|--------|-----------|
| Lunes – Viernes | 1.5h | Asimilación teórica / lectura profunda del tema de la semana |
| Lunes – Viernes | 2h | Código enfocado en ejercicios atómicos del tema |
| Sábado | 4–5h | Bloque masivo del Proyecto Principal de la fase |
| Domingo | Flexible | Descanso activo: revisar Zettelkasten, refactor de código, planear semana siguiente |

---

## FASE 1 — Linux Internals, C & DSA Fundamentos
**Período:** Meses 1–3
**Núcleo:** Fundamentos absolutos del sistema. Sin esto, todo lo demás es magia negra.

### Objetivos técnicos

- Dominar aritmética de punteros y gestión manual de heap
- Entender el modelo de memoria: Stack vs Heap vs BSS vs Text segment
- Usar syscalls directamente: `read`, `write`, `open`, `fork`, `exec`, `wait`
- Manejar señales UNIX: `SIGINT`, `SIGCHLD`, `SIGPIPE`
- Implementar comunicación entre procesos con pipes y FIFOs
- Escribir Makefiles que automaticen compilación, tests y limpieza
- Debuggear con GDB y detectar memory leaks con Valgrind
- Entender file descriptors: herencia en `fork`, redirección manual
- **DSA Fase 1:** arrays, linked lists, stacks, queues implementados en C desde cero
- **DSA Fase 1:** complejidad algorítmica O(N), O(log N), O(1) — razonar sobre el costo de tus operaciones

### DSA en esta fase — implementar en C, no memorizar

```
Estructuras a implementar manualmente:
├── Dynamic array (tu propio vector)
├── Singly linked list con insert/delete/search
├── Stack con array dinámico
├── Queue con linked list
└── Hash table con separate chaining

Algoritmos a entender (no memorizar, entender):
├── Binary search — O(log N) y por qué
├── Bubble sort vs merge sort — O(N²) vs O(N log N)
└── Two pointers technique
```

> **Por qué en C:** implementar una linked list en C donde tienes que manejar los punteros manualmente graba en tu memoria lo que ningún tutorial de Python puede. Cuando en Go uses un slice, sabrás exactamente qué hay debajo.

### Subtemas atómicos y estructura del repositorio

```
learning-c/
├── Makefile
├── README.md
├── 01-memory-pointers/
│   ├── main.c              # aritmética de punteros, double pointers
│   └── README.md
├── 02-stack-heap/
│   ├── main.c              # malloc/free, stack frames visualizados con GDB
│   └── README.md
├── 03-makefiles/
│   ├── Makefile            # targets, variables, patrones, phony targets
│   └── README.md
├── 04-syscalls-processes/
│   ├── fork_exec.c         # fork/exec/wait, zombie processes
│   ├── open_read.c         # file descriptors a mano
│   └── README.md
├── 05-signals/
│   ├── signal_handler.c
│   └── README.md
├── 06-pipes-ipc/
│   ├── pipe_basic.c
│   ├── fifo_ipc.c
│   └── README.md
├── 07-file-descriptors/
│   ├── redirect.c          # redirigir stdout a un archivo manualmente
│   └── README.md
├── 08-debugging-gdb/
│   ├── buggy.c             # código con bugs intencionales para practicar GDB
│   └── README.md
└── 09-dsa-fundamentals/
    ├── dynamic_array.c
    ├── linked_list.c
    ├── stack.c
    ├── queue.c
    ├── hash_table.c
    ├── binary_search.c
    ├── sorting.c           # bubble, merge, comparar en benchmarks
    └── README.md
```

### Recursos de alta calidad

| Tipo | Recurso | Notas |
|------|---------|-------|
| 📖 Libro | *The C Programming Language* — Kernighan & Ritchie | Leer completo. El libro más influyente en la historia de la programación. |
| 📖 Libro | *Computer Systems: A Programmer's Perspective* (CS:APP) — Bryant & O'Hallaron | Caps. 1–9 esta fase. Referencia definitiva de cómo el hardware ejecuta tu C. |
| 📖 Libro | *The Algorithm Design Manual* — Skiena | Para DSA. Más práctico que Cormen. Leer caps. 1–4 esta fase. |
| 🌐 Web | `man2` y `man3` en la terminal | Tu biblia. `man 2 fork`, `man 2 read`. |
| 🌐 Web | [beej.us/guide/bgc](https://beej.us/guide/bgc) | Guía de C gratuita y excelente. |
| 🎥 YouTube | Jacob Sorber | Series de C y sistemas UNIX. Cortas, densas, sin relleno. |
| 🛠 Herramienta | `gdb` + `valgrind` | Instalar día 1. Usar en cada ejercicio. |

### Proyecto Principal — `mysh`

**Mini shell UNIX desde cero en C**

**Qué debe hacer el software:**
- Parsear comandos ingresados por el usuario
- Ejecutar comandos externos con `fork` + `exec` (sin usar `system()`)
- Pipes: `cmd1 | cmd2 | cmd3`
- Redirección de I/O: `>`, `<`, `>>`
- Manejo de señales: `Ctrl+C` no mata el shell, solo el proceso hijo
- Historial de comandos en memoria usando tu propia linked list (sin libreadline)
- Built-ins: `cd`, `exit`, `echo`

**Habilidades que desarrolla:** fork/exec real, file descriptors como pipes, signal handlers, DSA aplicado (linked list para historial).

**Cómo registrar bugs en bitácora Obsidian:**
```
Bug #001 - YYYY-MM-DD
Síntoma: segfault al ejecutar pipe de 3 comandos
Hypothesis: el FD del pipe intermedio queda abierto en el proceso padre
Herramienta: GDB backtrace
Root cause: close() del read-end no se llama en el proceso correcto
Fix: mover close() antes del waitpid()
Lección: cada extremo del pipe debe cerrarse en TODOS los procesos que no lo usan
```

### Horario semanal — Fase 1

| Día | Actividad detallada |
|-----|---------------------|
| Lunes | K&R cap. correspondiente (1.5h) + ejercicios de punteros (2h) |
| Martes | CS:APP cap. correspondiente (1.5h) + implementar syscall del tema (2h) |
| Miércoles | man pages de las syscalls usadas (1.5h) + integrar al shell (2h) |
| Jueves | Skiena DSA cap. correspondiente (1.5h) + implementar estructura de datos en C (2h) |
| Viernes | Refactor + commit + README del subtema (1.5h) + GDB/Valgrind sobre código de la semana (2h) |
| Sábado | 4–5h bloque mysh: agregar feature, debuggear, documentar |
| Domingo | Revisar Zettels, refactor menor, planear semana siguiente |

### Notas Zettelkasten — Fase 1

```
C - Stack vs Heap Memory Model.md
C - Pointer Arithmetic and Dereferencing.md
C - Double Pointers and Pointer to Pointer.md
C - malloc free and Memory Leak Patterns.md
C - Memory Leak Detection with Valgrind.md
Linux - Process Creation with fork-exec.md
Linux - File Descriptors and open-read-write.md
Linux - IPC with Pipes and FIFOs.md
Linux - Signal Handling SIGINT SIGCHLD.md
Linux - Zombie Processes and waitpid.md
DSA - Big O Notation and Complexity Analysis.md
DSA - Dynamic Array vs Linked List Tradeoffs.md
DSA - Hash Table Collision Resolution.md
DSA - Binary Search and Invariants.md
```

---

## FASE 2 — Go + Python Base + PostgreSQL Avanzado + Seguridad
**Período:** Meses 4–6
**Núcleo:** Tu primer lenguaje de producción + Python desde ya + base de datos real bien usada + defensive coding.

### Sobre los dos lenguajes

**Go** es tu lenguaje de sistemas y backend: compilado, tipado estático, concurrencia nativa. Lo que aprendiste en C se traduce directamente. Para APIs, microservicios, herramientas de infraestructura y sistemas de alto throughput.

**Python** entra aquí porque no puedes esperar a la Fase 4. Scripts de automatización, tests de integración, herramientas de data desde el backend — Python aparece antes de lo que imaginas. En esta fase el objetivo es Python sólido (no experto aún): tipos, funciones, manejo de errores, I/O, testing básico. El nivel experto llega en Fase 4.

### Objetivos técnicos

**Go:**
- Sistema de tipos: interfaces, structs, embedding, generics básicos
- Concurrencia: goroutines, channels, select, sync.Mutex, sync.WaitGroup
- HTTP server desde `net/http` sin frameworks
- Error handling idiomático (no excepciones — valores de error)
- Testing: `testing` package, table-driven tests, mocking con interfaces
- Context: cancelación, timeouts, propagación

**Python base:**
- Type hints y mypy para tipado estático
- Manejo de errores con excepciones bien definidas
- I/O de archivos, JSON, CSV
- Testing con pytest
- Virtual environments y gestión de dependencias con `uv`
- Scripts de automatización real (usar desde el día 1 para tasks del proyecto)

**PostgreSQL:**
- SQL avanzado: CTEs, window functions, subqueries correlacionadas
- Índices B-Tree: estructura interna, índices parciales, índices compuestos
- `EXPLAIN ANALYZE`: leer e interpretar el plan de ejecución real
- Transacciones ACID: niveles de aislamiento, deadlocks, savepoints
- Connection pooling con `pgxpool`

**DSA Fase 2:**
- Hashmaps y su implementación interna (ya la hiciste en C, ahora la usas en Go)
- Árboles binarios: BST, traversals, altura
- Sorting avanzado: quicksort, heapsort
- Sliding window, two pointers aplicados a problemas reales

**Seguridad básica para engineers:**
- OWASP Top 10: qué es y cómo aplica a tu código
- SQL injection: por qué las queries parametrizadas funcionan
- Autenticación correcta: JWT bien implementado, bcrypt para passwords
- Secrets management: nunca hardcodear credenciales, variables de entorno, `.gitignore` de `.env`
- HTTPS/TLS básico: qué protege y qué no
- Rate limiting como medida de seguridad (no solo performance)

**IA como herramienta — introducción:**
- Cómo hacer prompts técnicos precisos (contexto + restricciones + formato esperado)
- Cuándo verificar el output de la IA y cómo
- La IA no reemplaza entender el código que genera — debes poder explicar cada línea
- Usar IA para: explorar APIs desconocidas, generar tests de casos borde, refactorizar código ya entendido

**Repository Pattern (entra al mes 5):**
> Cuando tu HTTP server tenga más de 5 endpoints y los handlers hagan queries directas, sentirás el dolor de mezclar lógica de negocio con acceso a datos. ESE momento estudias Repository Pattern.

**Modelado de datos (entra al mes 5-6):**
- Diagramas ER: entidades, relaciones, cardinalidad
- Normalización: 1NF, 2NF, 3NF — cuándo normalizar y cuándo desnormalizar conscientemente
- Schema design en PostgreSQL: tipos correctos, constraints, foreign keys
- Nota: `DB - Schema Design Decisions.md` con los tradeoffs de tu diseño

### Subtemas atómicos y estructura del repositorio

```
learning-go/
├── Makefile
├── README.md
├── 01-types-interfaces/
├── 02-goroutines-channels/
├── 03-http-server/
├── 04-error-handling/
├── 05-testing/
├── 06-context/
└── 07-dsa-go/
    ├── bst.go
    ├── sorting.go
    ├── sliding_window.go
    └── README.md

learning-python-base/
├── README.md
├── 01-types-and-hints/
│   ├── types_demo.py
│   └── README.md
├── 02-error-handling/
├── 03-io-json-csv/
├── 04-testing-pytest/
└── 05-automation-scripts/
    ├── db_seed.py          # script real: poblar PostgreSQL con datos de prueba
    ├── log_parser.py       # parsear logs de tu taskapi
    └── README.md

learning-postgres/
├── Makefile
├── README.md
├── 01-schema-design/
│   ├── erd.md              # diagrama ER del schema de taskapi
│   ├── schema.sql
│   └── README.md
├── 02-indexes-btree/
├── 03-transactions-isolation/
├── 04-query-optimization/
└── 05-window-functions/
```

### Recursos de alta calidad

| Tipo | Recurso | Notas |
|------|---------|-------|
| 📖 Libro | *The Go Programming Language* — Donovan & Kernighan | El K&R de Go. Leer completo. |
| 🌐 Web | [go.dev/tour](https://go.dev/tour) | Tour oficial interactivo. Semana 1 de Go. |
| 🎥 YouTube | Anthony GG | Proyectos reales en Go, concurrencia bien explicada. |
| 🌐 Web | [docs.astral.sh/uv](https://docs.astral.sh/uv) | Gestión moderna de entornos Python. |
| 🌐 Web | [docs.pytest.org](https://docs.pytest.org) | Documentación oficial de pytest. |
| 📖 Libro | *PostgreSQL: Up and Running* — Regina Obe | Fundamentos sólidos de PostgreSQL. |
| 🌐 Web | [use-the-index-luke.com](https://use-the-index-luke.com) | Cómo funcionan los índices B-Tree. Gratuito. Imprescindible. |
| 🌐 Web | [pgexercises.com](https://pgexercises.com) | Ejercicios SQL interactivos en el navegador. |
| 🌐 Web | [owasp.org/www-project-top-ten](https://owasp.org/www-project-top-ten) | OWASP Top 10. Leer completo y aplicar. |
| 📖 Libro | *Designing Data-Intensive Applications* — Kleppmann, cap. 2 | Primer contacto con el libro más importante del roadmap. |

### Proyecto Principal — `taskapi`

**REST API productiva con Go + PostgreSQL**

**Qué debe hacer el software:**
- CRUD completo de tasks y usuarios con schema bien modelado (ER diagram primero, código después)
- Autenticación JWT implementada sin librerías de auth (entender el algoritmo)
- Passwords hasheadas con bcrypt
- Secrets en variables de entorno, nunca hardcodeados (`.env` en `.gitignore`)
- Rate limiting con goroutines y channels
- Queries con índices parciales en PostgreSQL
- Transacciones en operaciones multi-step
- Connection pool configurado con `pgxpool`
- SQL puro con `sqlx` (cero ORMs)
- Tests unitarios con mocking del repositorio vía interfaces
- Script Python para poblar la DB con datos de prueba y para parsear logs

**Benchmarks:**
```bash
wrk -t4 -c100 -d30s http://localhost:8080/api/tasks
```

**Security checklist antes de considerar terminado el proyecto:**
```
[ ] Todas las queries son parametrizadas
[ ] JWT tiene expiración configurada
[ ] Passwords nunca se loggean
[ ] No hay credenciales en el código ni en el historial de git
[ ] Rate limiting activo en endpoints de autenticación
[ ] Inputs validados antes de llegar a la DB
```

### Horario semanal — Fase 2

| Día | Actividad detallada |
|-----|---------------------|
| Lunes–Martes | Go: goroutines, channels, interfaces. K&R de Go + ejercicios de concurrencia. |
| Miércoles | PostgreSQL: EXPLAIN ANALYZE, schema design, modelado ER. |
| Jueves | Python: scripts de automatización reales para el proyecto. |
| Viernes | Seguridad: aplicar checklist a taskapi. DSA: un problema en Go. |
| Sábado | 4–5h bloque taskapi: features + tests + benchmarks. |
| Domingo | Refactor, Zettels, planear. |

### Notas Zettelkasten — Fase 2

```
Go - Goroutines and the Go Scheduler.md
Go - Channels Unbuffered vs Buffered.md
Go - Interface Satisfaction and Duck Typing.md
Go - Error Wrapping with fmt.Errorf and errors.Is.md
Python - Type Hints and mypy.md
Python - pytest Fixtures and Parametrize.md
DB - B-Tree Index Internal Structure.md
DB - ACID Transactions and Isolation Levels.md
DB - EXPLAIN ANALYZE Output Reading.md
DB - Schema Design Normalization Tradeoffs.md
DB - ER Diagram Notation.md
Pattern - Repository Pattern in Go.md
Security - OWASP Top 10 Applied to Backend.md
Security - JWT Implementation Pitfalls.md
Security - Secrets Management Best Practices.md
DSA - Binary Search Tree Operations.md
DSA - Sliding Window Technique.md
AI - How to Write Effective Technical Prompts.md
```

---

## FASE 3 — Sistemas Distribuidos + Docker + Redis + Observabilidad + CI/CD
**Período:** Meses 7–9
**Núcleo:** Tu sistema ahora tiene múltiples piezas. Algo siempre falla. Y ahora puedes verlo.

### Objetivos técnicos

**Docker e infraestructura:**
- Docker desde cero: imágenes, capas, networking, volúmenes
- Docker Compose multi-service con dependencias y healthchecks
- Multi-stage builds para imágenes de producción pequeñas
- CI/CD con GitHub Actions: pipeline que hace build + test + lint automático en cada push

**Redis:**
- Data types: strings, hashes, sorted sets, lists
- Cache-aside pattern
- Rate limiting distribuido con Lua scripts (atomicidad garantizada)
- Pub/Sub para eventos simples
- TTL y políticas de evicción

**Observabilidad — los tres pilares:**
- **Logs estructurados en JSON**: nivel, timestamp, request_id, duración — todo queryable
- **Métricas con Prometheus**: counters, gauges, histogramas de latencia — Grafana para visualizar
- **Tracing distribuido con OpenTelemetry**: seguir una request a través de múltiples servicios

> **Por qué observabilidad aquí:** cuando tienes dos servicios comunicándose y algo falla, los logs de texto plano no alcanzan. Necesitas saber exactamente dónde en el flujo falló, cuánto tardó cada parte, y qué estaba pasando en ese momento. Sin observabilidad, operar sistemas distribuidos es adivinar.

**DSA Fase 3:**
- Grafos: BFS, DFS — aplicado a consistent hashing y service discovery
- Consistent hashing ring (lo usarás al leer sobre sharding en DDIA)
- Priority queues / heaps

**Patrones de resiliencia (entran cuando algo falla en tu proyecto):**
- Circuit Breaker: Closed → Open → Half-Open, implementar en Go sin librerías
- Retry con Exponential Backoff y Jitter (evitar thundering herd)
- Cache-aside Pattern: invalidación, stale data, tradeoffs

**DDIA esta fase:** caps. 5 (Replication), 7 (Transactions), 8 (Distributed Systems Problems)

### Subtemas atómicos y estructura del repositorio

```
learning-distributed/
├── Makefile
├── README.md
├── 01-docker-fundamentals/
│   ├── Dockerfile              # multi-stage build de taskapi
│   ├── .dockerignore
│   └── README.md
├── 02-docker-compose-multi/
│   ├── docker-compose.yml      # api + postgres + redis + prometheus + grafana
│   └── README.md
├── 03-redis-patterns/
│   ├── cache_aside.go
│   ├── rate_limiter.go         # sliding window con sorted sets + Lua
│   ├── pubsub_demo.go
│   └── README.md
├── 04-observability/
│   ├── structured_logger.go    # logger JSON con zerolog o slog
│   ├── metrics.go              # Prometheus counters e histogramas
│   ├── tracing.go              # OpenTelemetry setup
│   └── README.md
├── 05-circuit-breaker/
│   ├── circuit_breaker.go      # implementación desde cero, sin librerías
│   └── README.md
├── 06-cicd/
│   ├── .github/workflows/
│   │   └── ci.yml              # build + test + lint en cada PR
│   └── README.md
├── 07-cap-theorem-demos/
│   └── README.md
└── 08-dsa-graphs/
    ├── bfs_dfs.go
    ├── consistent_hash.go
    └── README.md
```

### Recursos de alta calidad

| Tipo | Recurso | Notas |
|------|---------|-------|
| 📖 Libro | *Designing Data-Intensive Applications* — Kleppmann, caps. 5, 7, 8 | El libro más importante de tu carrera. |
| 📖 Libro | *Release It!* — Michael Nygard | Patrones de resiliencia en producción. Muy práctico. |
| 🌐 Web | [redis.io/docs](https://redis.io/docs) | Documentación oficial de Redis. |
| 🎥 YouTube | TechWorld with Nana | Docker y Docker Compose, claro para arrancar. |
| 🌐 Web | [martinfowler.com/bliki/CircuitBreaker](https://martinfowler.com/bliki/CircuitBreaker.html) | Artículo original de Fowler sobre Circuit Breaker. |
| 🌐 Web | [opentelemetry.io/docs](https://opentelemetry.io/docs) | Documentación oficial de OpenTelemetry. |
| 🌐 Web | [prometheus.io/docs](https://prometheus.io/docs) | Documentación oficial de Prometheus. |
| 🌐 Web | [docs.github.com/actions](https://docs.github.com/en/actions) | CI/CD con GitHub Actions. |

### Proyecto Principal — `resilient-api`

**taskapi extendida con Redis, múltiples servicios, observabilidad y CI/CD**

**Qué debe hacer el software:**
- `api-service` (Go): taskapi dockerizada con observabilidad completa
- `notifications-service` (Go): servicio separado, healthcheck expuesto
- Redis: cache-aside para queries frecuentes + rate limiting distribuido
- Circuit Breaker manual que se activa si notifications-service falla
- Logs estructurados en JSON con request_id propagado entre servicios
- Métricas Prometheus: latencia de endpoints, hit/miss del cache, estado del Circuit Breaker
- Tracing OpenTelemetry: ver el flujo api → notifications en un trace único
- Docker Compose que levanta todo: `docker compose up`
- GitHub Actions: cada push corre tests y lint, PR bloqueado si falla

**Cómo verificar que el Circuit Breaker funciona:**
```bash
docker compose stop notifications-service
wrk -t2 -c50 -d10s http://localhost:8080/api/tasks
# Verificar en Grafana: métrica circuit_breaker_state == open
# Verificar: api-service sigue respondiendo
```

**Cómo verificar la observabilidad:**
```bash
# Un request debe generar:
# 1. Log JSON con request_id, duration_ms, status_code
# 2. Métrica en Prometheus: http_request_duration_seconds{endpoint="/api/tasks"}
# 3. Trace en OpenTelemetry con spans de: handler → repository → redis → postgres
```

### Horario semanal — Fase 3

| Día | Actividad detallada |
|-----|---------------------|
| Lunes–Martes | Docker: imágenes, compose, networking. Dockerizar taskapi. |
| Miércoles | Redis: data types, cache-aside en código. |
| Jueves | DDIA cap. correspondiente + observabilidad (Prometheus o OpenTelemetry). |
| Viernes | CI/CD con GitHub Actions + DSA: grafos o consistent hashing. |
| Sábado | 4–5h bloque resilient-api: integrar todo, verificar con Grafana. |
| Domingo | Refactor, Zettels, planear. |

### Notas Zettelkasten — Fase 3

```
Pattern - Circuit Breaker Pattern.md
Pattern - Retry with Exponential Backoff and Jitter.md
Pattern - Cache-Aside Pattern.md
Distributed - CAP Theorem.md
Distributed - Eventual Consistency.md
Observability - Structured Logging JSON.md
Observability - Prometheus Metrics Types Counter Gauge Histogram.md
Observability - Distributed Tracing with OpenTelemetry.md
Observability - The Three Pillars Logs Metrics Traces.md
Redis - Sorted Sets and Use Cases.md
Redis - Lua Scripts for Atomic Operations.md
Docker - Multi-stage Build Optimization.md
Infra - GitHub Actions CI CD Pipeline.md
DSA - Graph BFS DFS Applications.md
DSA - Consistent Hashing Ring.md
```

---

## FASE 4 — Data Engineering + Python Experto
**Período:** Meses 10–12
**Núcleo:** El camino del Data Engineer. Datos en movimiento a escala. Python al nivel que el mercado paga bien.

### Objetivos técnicos

**Python nivel experto:**
- Generators e iterators: `yield`, lazy evaluation, memory efficiency
- Decorators: implementar desde cero, casos de uso reales (retry, timing, caching)
- Context managers: `__enter__`/`__exit__`, uso con archivos y conexiones DB
- Async/await: asyncio, aiohttp — cuándo ayuda y cuándo no
- Profiling: `cProfile`, `memory_profiler` — encontrar bottlenecks reales
- Type hints avanzados: generics, protocols, TypeVar
- Dataclasses y attrs para modelos de datos
- Testing avanzado: fixtures complejos, parametrize, mocking de I/O y red

**Apache Kafka:**
- Topics, partitions, replication factor
- Producers: acks, compression, batching
- Consumers: consumer groups, offset management, commit manual vs automático
- Dead Letter Queue (DLQ) para mensajes fallidos
- Kafka Streams básico (conceptual)
- Schema Registry con Avro (opcional pero muy empleable)

**dbt:**
- Modelos: raw → staging → mart
- Tests de calidad de datos: `not_null`, `unique`, `accepted_values`, tests custom
- Macros y Jinja templating
- Documentación automática con `dbt docs generate`

**DuckDB:**
- SQL analytics sobre archivos Parquet y CSV
- Integración con Python (duckdb Python package)
- Cuándo usar DuckDB vs PostgreSQL vs Spark

**Pipelines ETL/ELT:**
- Idempotencia: correr el mismo pipeline dos veces no duplica datos
- Backfill strategy: reprocesar datos históricos
- Data quality checks antes y después de transformar
- Manejo de schema evolution (qué pasa cuando cambia el formato del evento)

**Arquitecturas de datos (entran al mes 11):**

> Cuando diseñes tu pipeline y necesites decidir entre batch y streaming, ESE momento estudias estas arquitecturas.

**Lambda Architecture:**
- Batch layer + Speed layer + Serving layer
- Por qué existe y por qué se está abandonando gradualmente

**Kappa Architecture:**
- Todo es streaming, el batch es un caso especial
- Por qué Kafka hace posible Kappa
- Tradeoffs vs Lambda: cuándo cada una tiene sentido

**DDIA esta fase:** caps. 10 (Batch Processing), 11 (Stream Processing)

### Subtemas atómicos y estructura del repositorio

```
learning-data-engineering/
├── Makefile            # levanta Kafka + Zookeeper + PostgreSQL + dbt con Docker
├── README.md
├── 01-python-expert/
│   ├── generators.py
│   ├── decorators.py
│   ├── async_demo.py
│   ├── profiling_demo.py
│   └── README.md
├── 02-pandas-polars-etl/
│   ├── pandas_transforms.py
│   ├── polars_intro.py
│   ├── data_cleaning.py    # nulls, type casting, deduplication
│   └── README.md
├── 03-kafka-fundamentals/
│   ├── docker-compose.yml  # Kafka + Zookeeper/KRaft
│   ├── producer_basic.py
│   ├── consumer_basic.py
│   └── README.md
├── 04-kafka-advanced/
│   ├── producer_events.py  # eventos con schema definido
│   ├── consumer_group.py   # commit manual de offsets
│   ├── dlq_handler.py
│   └── README.md
├── 05-dbt-models/
│   ├── dbt_project.yml
│   ├── models/
│   │   ├── raw/
│   │   ├── staging/
│   │   └── mart/
│   ├── tests/
│   └── README.md
├── 06-duckdb-analytics/
│   ├── analytics_queries.sql
│   ├── duckdb_demo.py
│   └── README.md
└── 07-pipeline-patterns/
    ├── idempotent_pipeline.py
    ├── backfill_strategy.py
    ├── schema_evolution.py
    └── README.md
```

### Recursos de alta calidad

| Tipo | Recurso | Notas |
|------|---------|-------|
| 📖 Libro | *Fundamentals of Data Engineering* — Reis & Housley (2022) | Nuevo estándar del campo. Leer completo. |
| 📖 Libro | *Fluent Python* — Luciano Ramalho | Para Python nivel experto. Generators, decorators, protocols. |
| 📖 Libro | DDIA caps. 10–11 — Kleppmann | Batch y Stream Processing. |
| 🌐 Web | [kafka.apache.org/documentation](https://kafka.apache.org/documentation) | Docs oficiales. Especialmente la sección "Design". |
| 🌐 Web | [docs.getdbt.com](https://docs.getdbt.com) | Tutorial oficial de dbt. |
| 🎥 YouTube | Zach Wilson / DataExpert.io | Data engineering desde fundamentos reales. |
| 🎥 YouTube | Confluent channel | Kafka internals y patterns. Canal oficial. |
| 🌐 Web | [duckdb.org/docs](https://duckdb.org/docs) | DuckDB para analytics locales. |

### Proyecto Principal — `eventpipe`

**Pipeline completo de datos end-to-end**

**Arquitectura:**
```
[Go API: taskapi] → produce task events → [Kafka topic: task.events]
                                                    ↓
                                      [Python Consumer: event_processor.py]
                                                    ↓
                                         [PostgreSQL: events_raw]
                                                    ↓
                                         [dbt: staging → marts]
                                                    ↓
                                    [DuckDB: analytics queries]
                                                    ↓
                              [Go API: endpoint /analytics/summary]
```

**Qué debe hacer el software:**
- Producer en Go (integrado en taskapi): cada operación CRUD produce un evento Kafka
- Consumer Python con commit manual, validación de schema, upsert idempotente por `event_id`
- DLQ: eventos con schema inválido van a `task.events.dlq`
- dbt models: `raw_task_events` → `stg_task_events` → `mart_daily_activity` y `mart_user_stats`
- DuckDB: queries ad-hoc sobre los marts exportados a Parquet
- Endpoint en Go que consulta las métricas procesadas

**Prueba de idempotencia obligatoria:**
```bash
# Guardar row count inicial
psql -c "SELECT COUNT(*) FROM events_raw"
# Reset consumer al offset 0 y reprocesar
kafka-consumer-groups.sh --reset-offsets --to-earliest --group event-processor --execute
python event_processor.py
# Row count debe ser IDÉNTICO al inicial
psql -c "SELECT COUNT(*) FROM events_raw"
```

### Horario semanal — Fase 4

| Día | Actividad detallada |
|-----|---------------------|
| Lunes–Martes | Python experto: generators, decorators, async. Fluent Python + ejercicios. |
| Miércoles | Kafka: producers, consumers, offset management. |
| Jueves | DDIA caps. 10–11 + arquitecturas Lambda/Kappa. |
| Viernes | dbt models + DuckDB analytics sobre datos propios. |
| Sábado | 4–5h bloque eventpipe: integrar todos los componentes. |
| Domingo | Refactor, Zettels, planear. |

### Notas Zettelkasten — Fase 4

```
Python - Generator Functions and yield Expression.md
Python - Decorators and Higher Order Functions.md
Python - Async Await and the Event Loop.md
Python - Profiling with cProfile and memory_profiler.md
Kafka - Topic Partitioning and Ordering Guarantees.md
Kafka - Consumer Groups and Offset Management.md
Kafka - Dead Letter Queue Pattern.md
Kafka - Producer Acknowledgment Levels acks.md
Data - Lambda Architecture.md
Data - Kappa Architecture.md
Data - Idempotent Pipeline Design.md
Data - Schema Evolution Strategies.md
dbt - Model Layers Raw Staging Mart.md
dbt - Testing Data Quality with dbt test.md
```

---

## FASE 5 — System Design, Arquitectura Formal, DDD & Infraestructura
**Período:** Meses 13–15
**Núcleo:** Todo lo que sufriste ahora tiene nombre, diagrama y tradeoffs documentados.

### Por qué el mes 13 y no antes

A estas alturas has construido:
- Un shell en C que maneja procesos y señales
- Una REST API en Go con PostgreSQL, seguridad y tests
- Un sistema distribuido con Docker, Redis, Circuit Breaker y observabilidad
- Un pipeline de datos con Kafka, dbt y DuckDB

Cuando leas "diseñar un sistema de mensajería a escala de WhatsApp", cada componente tendrá un rostro concreto en tu memoria. System Design sin experiencia previa es memorización. Con experiencia previa es **reconocimiento de patrones que ya viviste**.

### Objetivos técnicos

**System Design — fundamentos de escalabilidad:**
- Vertical vs horizontal scaling y por qué stateless services son la clave
- Load balancing: Round Robin, Least Connections, Consistent Hashing
- Caching en capas: L1 (proceso), L2 (Redis), L3 (CDN)
- Database sharding: horizontal partitioning strategies
- Read replicas y cuándo no son suficientes

**Patrones de arquitectura distribuida:**
- CQRS (Command Query Responsibility Segregation)
- Event Sourcing vs CRUD: cuándo cada uno tiene sentido
- Saga Pattern: Choreography vs Orchestration
- API Gateway Pattern
- Strangler Fig Pattern (migrar un monolito sin detenerlo)
- Sidecar Pattern (introducción a service mesh)

**Algoritmos de rate limiting:**
- Token Bucket, Leaky Bucket, Sliding Window Counter, Fixed Window Counter
- Cuál usar en qué contexto y por qué

**Domain-Driven Design — fundamentos:**
- Ubiquitous Language: hablar el idioma del dominio en el código
- Bounded Contexts: dividir un sistema complejo en dominios coherentes
- Entities vs Value Objects
- Aggregates y por qué protegen invariantes
- Application a tu taskapi: ¿cuáles son los bounded contexts?

> **Por qué DDD aquí:** cuando hagas system design interviews y diseñes sistemas complejos, DDD te da el vocabulario y las herramientas para descomponer el problema. No es metodología de proceso — es forma de modelar.

**Comunicación técnica escrita:**
- Architecture Decision Records (ADRs): formato, cuándo escribirlos
- RFCs (Request for Comments): proponer cambios técnicos por escrito
- Post-mortems: analizar incidentes sin culpas, con root cause y acciones
- C4 Model: diagramas de arquitectura en 4 niveles de zoom

**Infraestructura — Kubernetes conceptual:**
- Qué problema resuelve K8s que Docker Compose no puede
- Pods, Deployments, Services, ConfigMaps, Secrets
- NO necesitas operarlo — necesitas entender los conceptos para entrevistas y para leer job descriptions
- Opcional si el tiempo lo permite: instalar minikube y desplegar tu resilient-api

**DSA Fase 5 — repaso de entrevistas:**
- Revisar estructuras implementadas en Fases 1–3
- 20 problemas Leetcode medium: arrays, hashmaps, strings en Go
- 15 problemas Leetcode SQL: window functions, CTEs, joins complejos

**DDIA esta fase:** caps. 1, 3, 4, 6, 9, 12 (completar el libro)

### Estructura del repositorio

```
architecture-docs/
├── README.md
├── adr/
│   ├── template.md
│   ├── 001-why-go-over-java.md
│   ├── 002-postgresql-over-mongodb.md
│   ├── 003-kafka-over-rabbitmq.md
│   └── 004-cache-aside-over-read-through.md
├── rfc/
│   ├── template.md
│   └── 001-adding-search-to-taskapi.md
├── postmortem/
│   ├── template.md
│   └── 001-circuit-breaker-misconfiguration.md
├── c4-diagrams/
│   ├── taskapi/
│   │   ├── 01-context.md
│   │   ├── 02-container.md
│   │   └── 03-component.md
│   └── eventpipe/
│       ├── 01-context.md
│       └── 02-container.md
├── system-design-cases/
│   ├── url-shortener.md
│   ├── notification-system.md
│   ├── news-feed.md
│   ├── chat-system.md
│   └── data-pipeline-at-scale.md
└── ddd/
    ├── taskapi-domain-model.md
    └── bounded-contexts.md
```

### Formato de ADR

```markdown
# ADR-003: Kafka over RabbitMQ for Event Streaming

**Date:** YYYY-MM-DD
**Status:** Accepted
**Context:** We need a message broker for eventpipe. Two main candidates.
**Decision:** We use Apache Kafka.
**Rationale:**
- Kafka retains messages after consumption — enables replay and backfill
- Log-based storage makes Kappa Architecture possible
- RabbitMQ deletes after ACK — no time-travel debugging
**Consequences:**
- Higher operational complexity (requires ZooKeeper/KRaft)
- Consumer group semantics require explicit offset management
- Gain: reprocess all historical events when business logic changes
```

### Método de System Design Interview (45 min)

```
00-05 min → Clarify requirements
            "How many users? Read-heavy or write-heavy? Global or single region?"
05-10 min → Capacity estimation
            "100M users × 10 requests/day = ~12K QPS. Storage: 1KB × 100M = 100GB/day"
10-25 min → High-level design
            Componentes principales, flujo de datos, APIs
25-35 min → Deep dive
            El componente más crítico o el que el entrevistador elija
35-45 min → Tradeoffs
            "¿Qué sacrificaste? ¿Qué alternativas consideraste? ¿Qué fallaría primero?"
```

### Recursos de alta calidad

| Tipo | Recurso | Notas |
|------|---------|-------|
| 📖 Libro | *System Design Interview Vol. 1 & 2* — Alex Xu | Estándar de la industria para entrevistas. |
| 🌐 Web | [github.com/donnemartin/system-design-primer](https://github.com/donnemartin/system-design-primer) | Gratis. El recurso más completo de SD. |
| 📖 Libro | *Designing Data-Intensive Applications* — DDIA completo | Terminar el libro en esta fase. |
| 🎥 YouTube | ByteByteGo | Alex Xu. System design visual y bien explicado. |
| 🎥 YouTube | Arpit Bhayani | System design con profundidad técnica real. |
| 📖 Libro | *Building Microservices* — Sam Newman | Referencia estándar de microservicios. |
| 🌐 Web | [microservices.io](https://microservices.io) | Chris Richardson. Catálogo de patrones. |
| 📖 Libro | *Domain-Driven Design Distilled* — Vaughn Vernon | DDD sin el peso del libro original de Evans. |

### Proyecto Principal — `architecture-docs`

**Re-arquitecturar tus proyectos como si fueran para 1M usuarios**

**Entregables concretos:**
1. C4 Level 1 y Level 2 de `taskapi` y `eventpipe` en Mermaid or draw.io
2. 4 ADRs reales de decisiones tomadas en tus proyectos
3. 1 RFC: "How would I add full-text search to taskapi?"
4. 1 post-mortem de un incidente real que hayas tenido en tu código
5. 5 casos de System Design resueltos con el método de 45 min
6. Documento de dominio DDD de taskapi: bounded contexts, entities, aggregates

### Horario semanal — Fase 5

| Día | Actividad detallada |
|-----|---------------------|
| Lunes | System Design Primer + ByteByteGo. 1.5h teoría, notas en Zettelkasten. |
| Martes | Implementar patrón de la semana en código de prueba (CQRS, Saga, etc.). |
| Miércoles | Alex Xu cap. correspondiente + escribir ADR o RFC. |
| Jueves | DDD: modelar dominio de taskapi. DDIA cap. restante. |
| Viernes | Mock System Design 45 min (timer, papel) + Leetcode: 2 problemas medium. |
| Sábado | 4–5h bloque architecture-docs: caso SD completo o diagrama C4. |
| Domingo | Refactor Zettels de arquitectura, planear. |

### Notas Zettelkasten — Fase 5

```
Architecture - CQRS Command Query Responsibility Segregation.md
Architecture - Event Sourcing vs CRUD.md
Architecture - Saga Pattern Choreography vs Orchestration.md
Architecture - Consistent Hashing Ring.md
Architecture - C4 Model for Documentation.md
Architecture - ADR Architecture Decision Record.md
Architecture - RFC Request for Comments Template.md
Architecture - Post-mortem Template and Blameless Culture.md
Architecture - Microservices vs Monolith Tradeoffs.md
Architecture - Strangler Fig Migration Pattern.md
Architecture - Database Sharding Strategies.md
Architecture - Rate Limiting Algorithms Token Bucket.md
DDD - Ubiquitous Language.md
DDD - Bounded Contexts.md
DDD - Entities vs Value Objects.md
DDD - Aggregates and Invariants.md
Infra - Kubernetes Core Concepts Pod Deployment Service.md
System Design - URL Shortener.md
System Design - Notification System.md
System Design - News Feed Timeline.md
System Design - Chat System.md
```

---

## FASE 6 — Portfolio, Open Source, IA en Proyectos & Job Hunt
**Período:** Meses 16–18
**Núcleo:** Convertir 15 meses de trabajo en empleo.

### Objetivos

- READMEs profesionales con arquitectura, benchmarks y decisiones técnicas
- 2 proyectos estrella completamente documentados en GitHub
- 1–2 contribuciones a proyectos Open Source fusionadas
- 1–2 posts técnicos publicados (blog propio, dev.to o medium)
- Integrar IA (embeddings, RAG básico) en el capstone como feature real
- 80 problemas Leetcode completados y entendidos
- 15+ mock interviews completadas
- CV con métricas reales, LinkedIn optimizado

### IA en proyectos — nivel de integración

> **Por qué aquí:** Para integrar IA correctamente en un proyecto necesitas entender el sistema completo que hay alrededor. Llamar a una API de OpenAI o Anthropic es trivial — lo difícil es el pipeline de datos que alimenta el contexto, el sistema de retrieval, y la evaluación de calidad. Ahora tienes todas esas piezas.

**Qué aprender:**
- Embeddings: qué son, cómo se generan, cómo se comparan (cosine similarity)
- Vector search básico: pgvector en PostgreSQL (no necesitas un vector DB separado)
- RAG (Retrieval Augmented Generation): arquitectura completa
  - Chunking de documentos
  - Generación de embeddings con API (OpenAI, Anthropic, o modelos locales con Ollama)
  - Retrieval: buscar chunks relevantes por similitud
  - Generation: enviar contexto + query al LLM
- Evaluación de calidad: cómo saber si tu RAG responde bien
- Cuándo NO usar IA: si un query SQL resuelve el problema, úsalo

**Feature para el capstone:**
Agregar a tu sistema un endpoint `/search/semantic` que use RAG para buscar tasks por significado semántico, no solo texto exacto.

**Cómo usar IA como herramienta en tu día a día (consolidación):**
- Prompt engineering técnico: contexto preciso, ejemplos, formato esperado
- Usar IA para explorar una librería nueva antes de leer la documentación completa
- Generar casos de prueba borde que no se te habrían ocurrido
- Revisar código propio con IA antes de hacer code review humano
- **Regla de oro:** si no puedes explicar el código que la IA generó, no lo incluyas

### Los dos proyectos estrella de tu portfolio

**Proyecto 1: `resilient-api`** (de Fase 3, pulido)
- README con: arquitectura C4, instrucciones de instalación con `docker compose up`, benchmarks reales
- Métricas concretas: "handles X req/s con p99 < Y ms en hardware Z"
- ADRs de las decisiones de diseño principales
- GitHub Actions badge en el README

**Proyecto 2: `capstone`** (nuevo, todo integrado)
- Pipeline end-to-end documentado completamente
- Feature de búsqueda semántica con RAG + pgvector
- Diagrama C4 Level 1 y 2
- `ARCHITECTURE.md`, `BENCHMARKS.md`, `RUNBOOK.md`

### Proyecto Final — `capstone`

**Sistema de analytics end-to-end con búsqueda semántica**

```
[Go API: taskapi v3]
    ├── produce events → [Kafka: task.events]
    │                          ↓
    │              [Python: event_processor]
    │                          ↓
    │                  [PostgreSQL: raw + pgvector]
    │                          ↓
    │                  [dbt: staging → marts]
    │                          ↓
    │                  [DuckDB: analytics]
    │
    ├── GET /analytics/summary → consulta marts
    └── GET /search/semantic?q=... → RAG con pgvector

Observabilidad: Prometheus + Grafana + OpenTelemetry
CI/CD: GitHub Actions
Deployment: Docker Compose
```

**Entregables del capstone:**
```
capstone/
├── README.md           # arquitectura, cómo correrlo, decisiones de diseño
├── ARCHITECTURE.md     # C4 diagrams + ADRs
├── BENCHMARKS.md       # throughput Kafka, latencia queries, tiempo dbt
├── RUNBOOK.md          # cómo operar, cómo debuggear problemas comunes
├── CHANGELOG.md        # historial de cambios significativos
└── docker-compose.yml  # todo levanta con un comando
```

### Contribución Open Source

**Dónde buscar issues para contribuir:**
```bash
# En GitHub:
label:"good first issue" language:Go
label:"good first issue" language:Python
```

**Proyectos relevantes al stack:**
- `sqlc` (Go SQL code generator) — documentación, tests
- `dbt-core` (Python) — mejoras a tests o documentación
- `pgx` (Go PostgreSQL driver) — issues good-first-issue
- `polars` (Python/Rust) — documentación o ejemplos
- `OpenTelemetry Go` — documentación o ejemplos

**Lo que importa:** que el PR sea fusionado. Aunque sea un fix de documentación — aparece en tu historial y demuestra que sabes trabajar con código de otros.

### Preparación para entrevistas técnicas

**Leetcode — distribución de los 80 problemas:**
- SQL medium (window functions, CTEs, joins complejos): 25 problemas
- Arrays y hashmaps en Go: 30 problemas
- Strings en Go: 15 problemas
- Árboles básicos: 10 problemas
- **NO** necesitas dynamic programming avanzado para roles Backend/Data Jr.

**Mock interviews:**
- [interviewing.io](https://interviewing.io) — con ingenieros reales, anónimo
- Practicar System Design 2 veces por semana con timer y papel
- Practicar explicar tus proyectos en 5 minutos (elevator pitch técnico)

### Recursos para Fase 6

| Tipo | Recurso | Notas |
|------|---------|-------|
| 🌐 Web | [leetcode.com](https://leetcode.com) | 80 problemas bien entendidos > 500 memorizados. |
| 🌐 Web | [interviewing.io](https://interviewing.io) | Mock interviews anónimas con engineers reales. |
| 🎥 YouTube | Gaurav Sen | System design interview prep. Casos reales. |
| 🌐 Web | [pgvector docs](https://github.com/pgvector/pgvector) | Vector search en PostgreSQL. |
| 🌐 Web | Levels.fyi / Glassdoor | Salarios reales y preguntas de entrevistas. |
| 🌐 Web | [ollama.ai](https://ollama.ai) | Modelos de lenguaje locales para el RAG (sin pagar API). |

### Horario semanal — Fase 6

| Día | Actividad detallada |
|-----|---------------------|
| Lunes–Miércoles | Leetcode o contribución OSS. 1h máximo. No más. |
| Jueves–Viernes | Portfolio refinement, aplicaciones a empleos, posts técnicos. |
| Sábado | Mock interview o trabajo en capstone. |
| Domingo | Retrospectiva semanal de job hunt, ajustar estrategia. |

### Notas Zettelkasten — Fase 6

```
AI - Embeddings and Cosine Similarity.md
AI - RAG Retrieval Augmented Generation Architecture.md
AI - pgvector Vector Search in PostgreSQL.md
AI - When Not to Use AI in a System.md
AI - Effective Technical Prompting.md
Career - Technical README Structure.md
Career - System Design Interview Framework.md
Career - Elevator Pitch for Technical Projects.md
Interview - Capacity Estimation Cheatsheet.md
```

---

## El libro que amarra todo — DDIA

*Designing Data-Intensive Applications* de Martin Kleppmann se lee distribuido a lo largo del roadmap:

| Capítulos | Fase | Contexto en ese momento |
|-----------|------|------------------------|
| Cap. 2 — Data Models | F2 (M5) | Justo cuando diseñas el schema de taskapi |
| Cap. 5 — Replication | F3 (M7) | Cuando tu sistema tiene múltiples nodos |
| Cap. 7 — Transactions | F3 (M8) | Cuando implementas transacciones distribuidas |
| Cap. 8 — Distributed Problems | F3 (M9) | CAP Theorem, clocks, consensus |
| Cap. 10 — Batch Processing | F4 (M10) | Lambda Architecture |
| Cap. 11 — Stream Processing | F4 (M11) | Kappa Architecture, Kafka internals |
| Caps. 1, 3, 4, 6, 9, 12 | F5 (M13-14) | Completar el libro con toda la base construida |

---

## 📈 Roadmap V2: Architectural & Learning Adjustments

The following improvements have been incorporated into the roadmap to optimize learning efficiency and adapt to modern production standards:

### 1. Socratic Learning & Editor Environment (Phases 1 & 2)
- **Constraint:** AI code generation tools (inline completions) are disabled in the editor during Phase 1 & 2.
- **Method:** Errors must be solved using socratic debugging, encouraging deep understanding of pointer arithmetic and goroutine life cycles.

### 2. Local Storage Simulation (Phase 4 - Data Engineering)
- **Improvement:** Introduce **MinIO** containerization.
- **Goal:** Simulate a cloud-based Amazon S3 Data Lake locally. Exported DuckDB Parquet files and dbt staging models will interact with MinIO APIs to mirror modern data architecture patterns.

### 3. Lightweight Local Orchestration (Phase 5 - System Design & Infra)
- **Improvement:** Use **K3d / Kind** instead of raw/heavy Kubernetes setups.
- **Goal:** Deploy the `resilient-api` in a local, single-node cluster utilizing YAML manifest declarations without draining system resources.

### 4. Systematic Obsidian Fail Log
- **Process:** Use the `Template__Bug-Log.md` structure whenever a bug takes more than 15 minutes to solve. This builds a foundation for system post-mortems in Phase 5.
