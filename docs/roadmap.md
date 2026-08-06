# Roadmap 18 Meses — Backend & Data Engineer
> **Sistema de mentoreo personal** | Ingeniería en Informática 3er año → Junior Backend/Data Engineer
> Duración: 18 meses · ~25 horas semanales · Linux (Arch/Fedora) · Neovim · Warp terminal

---

## Cómo aprender en este roadmap — El método ajustado

Tu cerebro aprende por **activación**, no por recepción pasiva. Los libros te duermen porque son unidireccionales. Los videos te activan porque disparan el impulso de codear. Este roadmap usa eso a tu favor.

### El flujo diario de las 1.5h de teoría (reemplaza la lectura de libros)

```
1. Elegir el tema del día (ej: "pipes en Linux")
2. Ver el video del tema — 15 a 25 min máximo
3. Cerrar el video. Abrir Obsidian.
4. Escribir la nota atómica con TUS palabras — 20 min
   Si no puedes escribirlo sin ver el video, vuélvelo a ver.
5. Abrir Neovim → empieza el bloque de 2h de código
6. Cuando algo no funciona y no entiendes por qué
   → AHORA abres el libro o man pages como referencia puntual
```

> El paso 4 es donde ocurre el aprendizaje real. No en el video — sino cuando intentas reconstruirlo desde tu memoria.

### El rol de los libros cambia

Los libros no desaparecen — pasan a ser **referencia de consulta, no lectura lineal**. Cuando tu código falla y no entiendes por qué, abres K&R o CS:APP en la sección exacta. Así usan los libros los engineers en la vida real.

### Horario semanal base

| Día | Bloque | Actividad |
|-----|--------|-----------|
| Lunes – Viernes | 15–25 min | Video del tema del día |
| Lunes – Viernes | 20–30 min | Nota atómica en Obsidian con tus palabras |
| Lunes – Viernes | 2h | Código: implementar lo que viste |
| Sábado | 4–5h | Bloque masivo del Proyecto Principal |
| Domingo | Flexible | Refactor, revisar Zettels, planear semana |

---

## Vista general de las 6 fases

| Fase | Período | Foco | Stack |
|------|---------|------|-------|
| F1 | jun 14 – oct 18 2026 | Linux Internals, C & DSA base | C, GCC, Makefiles, Syscalls, DSA en C |
| F2 | oct 19 2026 – ene 18 2027 | Go + Python base + PostgreSQL + Seguridad | Go, Python, PostgreSQL, sqlx |
| F3 | ene 19 – abr 18 2027 | Sistemas Distribuidos + Docker + Redis + Observabilidad | Docker, Redis, CI/CD, OpenTelemetry |
| F4 | abr 19 – jul 18 2027 | Data Engineering + Python Experto | Python avanzado, Kafka, dbt, DuckDB |
| F5 | jul 19 – oct 18 2027 | System Design, Arquitectura Formal & DDD | CQRS, Event Sourcing, Saga, K8s conceptual |
| F6 | oct 19 2027 – ene 18 2028 | Portfolio, OSS, IA en proyectos & Job Hunt | Capstone, RAG básico, entrevistas |

> **Re-baseline (ago 2026):** La Fase 1 se extendió de 3 a ~4.5 meses (jun 14 – oct 18) tras un arranque más lento de lo previsto. El resto de fases se corren ~6 semanas. Las referencias internas tipo "mes 5" son relativas a esta nueva línea de tiempo. El detalle de recuperación está en [`learning-c/README.md`](../learning-c/README.md).

---

## Cuándo entra cada disciplina transversal

```
DSA
├── F1 (M1-3)  → Arrays, punteros, linked lists, hash tables implementados en C
├── F2 (M4-6)  → Árboles binarios, sorting, sliding window en Go
├── F3 (M7-9)  → Grafos BFS/DFS, consistent hashing con contexto real
└── F6 (M16-18)→ Repaso entrevistas, 80 problemas Leetcode

Modelado
├── F2 (M4-6)  → ER diagrams, normalización, schema design en PostgreSQL
└── F5 (M13-15)→ DDD: bounded contexts, entities, aggregates

Infraestructura
├── F3 (M7-9)  → CI/CD con GitHub Actions
├── F5 (M13-15)→ Kubernetes conceptual
└── F6 (M16-18)→ Terraform básico (opcional)

Observabilidad
└── F3 (M7-9)  → Logs JSON + Prometheus/Grafana + OpenTelemetry

Seguridad
└── F2 (M4-6)  → OWASP Top 10, secrets management, JWT correcto

IA como herramienta
├── F2 (M4-6)  → Usar IA con criterio: verificar, no confiar ciegamente
└── F6 (M16-18)→ Integrar IA en proyectos: embeddings, RAG básico

Comunicación técnica
└── F5 (M13-15)→ ADRs, RFCs, post-mortems, C4 diagrams

Arquitectura y patrones
├── F2 (M4-6)  → Repository Pattern (cuando la API crece)
├── F3 (M7-9)  → Circuit Breaker, Retry, Cache-aside
├── F4 (M10-12)→ Lambda Architecture, Kappa Architecture
└── F5 (M13-15)→ CQRS, Event Sourcing, Saga, Microservicios
```

---

## FASE 1 — Linux Internals, C & DSA Fundamentos
**Período:** Jun 14 – Oct 18 2026 (~4.5 meses)
**Núcleo:** Fundamentos absolutos del sistema. Sin esto, todo lo demás es magia negra.

### Objetivos técnicos

- Aritmética de punteros y gestión manual de heap
- Modelo de memoria: Stack vs Heap vs BSS vs Text segment
- Syscalls directas: `read`, `write`, `open`, `fork`, `exec`, `wait`
- Señales UNIX: `SIGINT`, `SIGCHLD`, `SIGPIPE`
- IPC con pipes y FIFOs
- Makefiles: compilación, tests, limpieza
- GDB y Valgrind desde el día 1
- DSA: arrays, linked lists, stacks, queues, hash tables — implementados en C desde cero
- Complejidad algorítmica: razonar sobre O(N), O(log N), O(1)

### Videos por tema — Fase 1

> Cada video es 15–25 min. Ver → Obsidian → codear. No ver el siguiente hasta implementar el anterior.

**C y memoria:**

| Tema | Video | Canal | Duración aprox |
|------|-------|-------|----------------|
| Intro a C | [Learn C in minutes (lesson 0)](https://www.youtube.com/watch?v=SC8uWXmDJs4) | Jacob Sorber | 10 min |
| Tipos, arrays, structs, punteros | [Learning C: Basic Types](https://www.youtube.com/watch?v=mib3ahMbq_0) | Jacob Sorber | 15 min |
| Tipos y cómo se estructuran en memoria | [They're Just Bits! Types and Structuring Memory in C](https://www.youtube.com/watch?v=phYM4L1BBjI) | Jacob Sorber | 15 min |
| Variables y memoria virtual | [Your Variables are Not Real](https://www.youtube.com/watch?v=YO6K5K1TUj4) | Jacob Sorber | 12 min |
| El Heap por dentro | [Pulling Back the Curtain on the Heap](https://www.youtube.com/watch?v=GIWeQ2I67rk) | Jacob Sorber | 18 min |
| Verificar punteros en runtime | [How to Check Your Pointers at Runtime](https://www.youtube.com/watch?v=yM9zteeTCiI) | Jacob Sorber | 14 min |
| Bitwise: máscaras | [What are Bit Masks, and how do I use them?](https://www.youtube.com/watch?v=Ew2QnDeTCCE) | Jacob Sorber | 3 min |
| Bitwise: set/clear/toggle un bit | [How do I Set, Clear, and Toggle a Single Bit?](https://www.youtube.com/watch?v=F9742wnBWRc) | Jacob Sorber | 6 min |

**Threads y sincronización (pthreads):**

| Tema | Video | Canal | Duración aprox |
|------|-------|-------|----------------|
| Crear y unir threads | [How to create and join threads in C (pthreads)](https://www.youtube.com/watch?v=uA8X5zNOGw8) | Jacob Sorber | 14 min |
| Race conditions, mutex y locks | [Safety and Speed Issues with Threads](https://www.youtube.com/watch?v=9axu8CUvOKY) | Jacob Sorber | 9 min |
| Semáforos | [What is a semaphore? (Example in C)](https://www.youtube.com/watch?v=ukM_zzrIeXs) | Jacob Sorber | 13 min |
| Variables atómicas | [Making variables atomic in C](https://www.youtube.com/watch?v=_xX25ThomIo) | Jacob Sorber | 8 min |

**Makefiles:**

| Tema | Video | Canal | Duración aprox |
|------|-------|-------|----------------|
| Makefiles básicos | [Why that "Perfect" Makefile Doesn't Work](https://www.youtube.com/watch?v=l5KqE0DMG-Q) | Jacob Sorber | 12 min |
| Variables automáticas en Make | [More make: automatic variables](https://www.youtube.com/watch?v=G5dNorAoeCM) | Jacob Sorber | 10 min |

**Linux Internals y Syscalls:**

| Tema | Video | Canal | Duración aprox |
|------|-------|-------|----------------|
| File descriptors explicados | [Inside Linux File Descriptors](https://www.youtube.com/watch?v=saMebwRO-Q8) | YouTube 2024 | 20 min |
| Crear procesos con fork() | [Creating new processes with fork()](https://www.youtube.com/watch?v=ss1-REMJ9GA) | Jacob Sorber | 15 min |
| Pipes y syscall pipe() | [Understanding the Pipe System Call](https://www.youtube.com/watch?v=8AXEHrQTf3I) | Jacob Sorber | 18 min |
| Señales: kill, signal, sigaction | [Sending and Handling Signals in C](https://www.youtube.com/watch?v=83M5-NPDeWs) | YouTube | 15 min |
| Señales — intro corta | [Short introduction to signals in C](https://www.youtube.com/watch?v=5We_HtLlAbs) | YouTube | 10 min |

**Debugging:**

| Tema | Video | Canal | Duración aprox |
|------|-------|-------|----------------|
| Valgrind para memory errors | [Finding memory errors with Valgrind](https://www.youtube.com/watch?v=Sddn1UjzSAo) | Jacob Sorber | 12 min |
| GDB + Valgrind juntos | [Using GDB and Valgrind together](https://www.youtube.com/watch?v=8JEEYwdrexc) | YouTube | 15 min |
| Ejecución reversa en GDB | [How to reverse execution in GDB](https://www.youtube.com/watch?v=237r-yWTSSg) | Jacob Sorber | 10 min |

**DSA:**

| Tema | Video | Canal | Duración aprox |
|------|-------|-------|----------------|
| Intro a estructuras de datos | [Data Structures intro — William Fiset](https://www.youtube.com/watch?v=Qmt0QwzEmh0) | WilliamFiset | 12 min |
| Curso completo de estructuras | [Data Structures Easy to Advanced — Full](https://www.youtube.com/watch?v=RBSGKlAvoiM) | freeCodeCamp/Fiset | 8h (ver por secciones) |

> Para el curso de Fiset: ver solo la sección que corresponde al tema de la semana. No es para ver completo de una vez.

**Playlists de referencia del canal Jacob Sorber:**
- [C programming playlist](https://www.youtube.com/playlist?list=PLs87dCfSJbLf-nPShgl5WhVkcgxRKZndb)
- [Debugging C playlist](https://www.youtube.com/playlist?list=PL9IEJIKnBJjHGWPN_S9NS_Ky1-tC8ZrUI)

**Clases universitarias CMU (CS:APP) — para cuando quieras profundidad extra:**
- [CMU 15-213 Introduction to Computer Systems — Playlist completa](https://www.youtube.com/playlist?list=PLMDSb3PWPnvhsmuSZ5R7c1JY2kaSdYYdh)

### Libros como referencia (no lectura lineal)

| Libro | Cuándo abrirlo |
|-------|----------------|
| *The C Programming Language* — K&R | Cuando no entiendes algo del video de C |
| *CS:APP* — Bryant & O'Hallaron | Para entender qué hace el hardware con tu código |
| *The Algorithm Design Manual* — Skiena | Caps. 1–4 cuando necesites profundizar en DSA |

### Repositorio — Fase 1

```
learning-c/
├── Makefile
├── README.md
├── chapter-01/           # K&R (ruta aparte)
├── 1-basics/             # Beej 2–7 + stdlib
│   ├── 06-functions/
│   ├── 07-arrays/
│   ├── 08-strings/
│   └── 09-standard-library/
├── 2-advanced/           # Beej 8–19 + tooling
│   ├── 01-pointers/
│   │   ├── pointer-arithmetic.c
│   │   └── README.md    # Qué aprendiste, qué falló, cómo lo resolviste
│   ├── 02-structs/
│   ├── 03-unions/
│   ├── 04-typedef-types/
│   ├── 05-memory-management/
│   ├── 06-scope/
│   ├── 07-file-io/
│   ├── 08-multifile-projects/
│   ├── 09-preprocessor/
│   ├── 10-error-handling/
│   └── 11-tooling/       # gcc, make, gdb & valgrind
├── 3-expert/             # Beej 20+
│   ├── 01-advanced-pointers/
│   ├── 02-dsa/
│   │   ├── dynamic_array.c
│   │   ├── linked_list.c
│   │   ├── stack.c
│   │   ├── queue.c
│   │   ├── hash_table.c
│   │   └── binary_search.c
│   ├── 03-oop-emulation/
│   ├── 04-bitwise/
│   ├── 05-threads-atomics/
│   ├── 06-variadic-jumps/
│   ├── 07-signals/
│   └── 08-modern-c/
└── 4-systems/            # OS: K&R 8, man 2 (no en Beej)
    ├── 01-syscalls-processes/
    │   ├── fork_exec.c
    │   └── open_read.c
    ├── 02-pipes-ipc/
    └── 03-file-descriptors/
```

### Proyecto Principal — `mysh`

**Mini shell UNIX desde cero en C**

- Parsear comandos del usuario
- Ejecutar con `fork` + `exec` (sin `system()`)
- Pipes: `cmd1 | cmd2 | cmd3`
- Redirección: `>`, `<`, `>>`
- `Ctrl+C` no mata el shell — solo el proceso hijo
- Historial en memoria usando tu propia linked list
- Built-ins: `cd`, `exit`, `echo`

**Cómo registrar bugs en Obsidian:**
```
Bug #001 - YYYY-MM-DD
Síntoma: segfault al ejecutar pipe de 3 comandos
Hypothesis: FD del pipe intermedio queda abierto en el padre
Herramienta: GDB backtrace
Root cause: close() del read-end no se llama en el proceso correcto
Fix: mover close() antes del waitpid()
Lección: cada extremo del pipe debe cerrarse en TODOS los procesos que no lo usan
```

### Horario semanal — Fase 1

| Día | Actividad |
|-----|-----------|
| Lunes | Video de C/memoria (15 min) → Obsidian (20 min) → ejercicio de punteros (2h) |
| Martes | Video de syscall del tema (15 min) → Obsidian → implementar en código (2h) |
| Miércoles | Video de Linux internals (15 min) → Obsidian → integrar al shell (2h) |
| Jueves | Video de DSA — Fiset sección correspondiente (20 min) → implementar estructura en C (2h) |
| Viernes | GDB/Valgrind sobre el código de la semana (1.5h) → commit + README del subtema (1h) |
| Sábado | 4–5h bloque mysh: feature nueva + debuggear + documentar |
| Domingo | Refactor, revisar Zettels, planear semana siguiente |

### Notas Zettelkasten — Fase 1

```
C - Stack vs Heap Memory Model.md
C - Pointer Arithmetic and Dereferencing.md
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
DSA - Binary Search and Loop Invariants.md
```

### Recovery Plan F1 — S0 a S10

> El plan semanal operativo de la fase vive en [`learning-c/README.md`](../learning-c/README.md). Las tablas semanales nunca van en el roadmap — solo en el README de la fase.

---

## FASE 2 — Go + Python Base + PostgreSQL Avanzado + Seguridad
**Período:** Oct 19 2026 – Ene 18 2027
**Núcleo:** Tu primer lenguaje de producción + Python desde ya + base de datos real + defensive coding.

### Sobre los dos lenguajes

**Go** es tu lenguaje de sistemas y backend. Lo que aprendiste en C se traduce directamente — compilado, tipado, concurrencia explícita. Para APIs, microservicios y sistemas de alto throughput.

**Python** entra aquí porque no puedes esperar a la Fase 4. Scripts de automatización, tests de integración, y herramientas de data aparecen antes de lo que imaginas. El objetivo en esta fase es Python sólido — no experto aún. El nivel experto llega en Fase 4.

### Videos por tema — Fase 2

**Go — fundamentos y concurrencia:**

| Tema | Video | Canal | Duración |
|------|-------|-------|----------|
| Tour oficial Go interactivo | [go.dev/tour](https://go.dev/tour) | Oficial | Semana 1 |
| Goroutines y channels | [Master Go Concurrency Patterns (40 min)](https://www.youtube.com/watch?v=qDi5M3bU3GQ) | YouTube | 40 min |
| HTTP server en Go sin frameworks | [Starting a HTTP Server in Go](https://www.youtube.com/watch?v=wKzX6qYA7sM) | YouTube | 15 min |
| Proyectos reales en Go | [Canal Anthony GG](https://www.youtube.com/@anthonygg_) | Anthony GG | varios |

**Go — concurrencia patrones de Rob Pike (clásicos):**

| Tema | Video | Canal |
|------|-------|-------|
| Go Concurrency Patterns | [Google I/O 2012 — Go Concurrency Patterns](https://www.youtube.com/watch?v=f6kdp27TYZs) | Google/Rob Pike |
| Advanced Go Concurrency | [Google I/O 2013 — Advanced Concurrency](https://www.youtube.com/watch?v=QDDwwePbDtw) | Google |

**PostgreSQL — índices y optimización:**

| Tema | Video | Canal | Duración |
|------|-------|-------|----------|
| Indexing explicado con PostgreSQL | [Database Indexing Explained (PostgreSQL)](https://www.youtube.com/watch?v=-qNSXK7s7_w) | Hussein Nasser | 25 min |
| Deep dive en índices PG | [A Deep Dive Into PostgreSQL Indexes](https://www.youtube.com/watch?v=pfbohxaZOSI) | YouTube | 45 min |
| Queries más rápidas con EXPLAIN | [Make PostgreSQL Queries Faster](https://www.youtube.com/watch?v=y4o2fKOK8go) | YouTube | 30 min |
| Ejercicios SQL interactivos | [pgexercises.com](https://pgexercises.com) | Web | diario |

**DSA en esta fase:**

| Tema | Video | Canal |
|------|-------|-------|
| Árboles binarios | [Fiset playlist — Binary Trees sección](https://www.youtube.com/playlist?list=PLDV1Zeh2NRsB6SWUrDFW2RmDotAfPbeHu) | WilliamFiset |
| Sliding window technique | Buscar "sliding window technique neetcode" en YouTube | NeetCode |

**Recursos web de referencia:**
- [use-the-index-luke.com](https://use-the-index-luke.com) — cómo funcionan los B-Tree indexes. Gratuito. Leer cuando trabajes con índices en el proyecto.
- [go.dev/tour](https://go.dev/tour) — empezar aquí la semana 1 de Go.

### Libros como referencia

| Libro | Cuándo abrirlo |
|-------|----------------|
| *The Go Programming Language* — Donovan & Kernighan | Cuando el video no alcanza para entender un concept de Go |
| *PostgreSQL: Up and Running* — Regina Obe | Referencia de PostgreSQL cuando necesitas más profundidad |
| DDIA cap. 2 — Kleppmann | Al mes 5, cuando diseñes el schema de taskapi |

### Repositorio — Fase 2

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
    └── sliding_window.go

learning-python-base/
├── README.md
├── 01-types-and-hints/
├── 02-error-handling/
├── 03-io-json-csv/
├── 04-testing-pytest/
└── 05-automation-scripts/
    ├── db_seed.py          # poblar PostgreSQL con datos de prueba
    └── log_parser.py       # parsear logs de tu taskapi

learning-postgres/
├── Makefile                # levanta PG con Docker
├── 01-schema-design/
│   ├── erd.md              # diagrama ER antes de escribir código
│   └── schema.sql
├── 02-indexes-btree/
├── 03-transactions-isolation/
├── 04-query-optimization/
└── 05-window-functions/
```

### Arquitectura que entra en esta fase

> **Repository Pattern — al mes 5, cuando duela:**
> Cuando tu HTTP server tenga 5+ endpoints y los handlers hagan queries directas, sentirás el dolor de mezclar lógica de negocio con acceso a datos. Ese momento: estudias Repository Pattern. No antes.

> **Modelado de datos — al mes 5-6:**
> Antes de escribir una sola línea de SQL de taskapi, dibuja el ER diagram. Normalización: cuándo aplicarla y cuándo desnormalizar conscientemente.

### Seguridad — checklist obligatorio antes de terminar la Fase 2

```
[ ] Todas las queries son parametrizadas (cero string interpolation)
[ ] Passwords hasheadas con bcrypt (nunca MD5, nunca SHA1 solo)
[ ] JWT tiene expiración configurada y se valida
[ ] Passwords y tokens nunca se loggean
[ ] No hay credenciales en el código ni en el historial de git
[ ] .env está en .gitignore desde el primer commit
[ ] Rate limiting activo en endpoints de autenticación
[ ] Inputs validados antes de llegar a la DB
```

**Video recomendado para OWASP:** buscar "OWASP Top 10 explained 2023" en YouTube — hay versiones de 20 min muy buenas.

### IA como herramienta — introducción (mes 4)

- Ver los primeros 2 videos del tema con IA apagada. Luego úsala para explorar.
- Regla: si no puedes explicar el código que la IA generó línea por línea, no lo incluyas.
- Úsala para: generar casos de prueba borde, explorar APIs desconocidas, refactorizar código ya entendido.

### Proyecto Principal — `taskapi`

**REST API productiva con Go + PostgreSQL**

- CRUD de tasks y usuarios con schema modelado (ER diagram primero, código después)
- JWT implementado sin librerías de auth — entender el algoritmo
- Passwords con bcrypt, secrets en variables de entorno
- Rate limiting con goroutines y channels
- Índices parciales en PostgreSQL (ej: solo tasks activas)
- Transacciones en operaciones multi-step
- Connection pool con `pgxpool`
- SQL puro con `sqlx` — cero ORMs
- Tests unitarios con mocking del repositorio vía interfaces
- Script Python para poblar la DB y parsear logs

**Benchmark que debes poder correr:**
```bash
wrk -t4 -c100 -d30s http://localhost:8080/api/tasks
```

### Horario semanal — Fase 2

| Día | Actividad |
|-----|-----------|
| Lunes–Martes | Go: video (15 min) → Obsidian → goroutines/channels/interfaces (2h) |
| Miércoles | PostgreSQL: video de índices o EXPLAIN → Obsidian → queries en el proyecto (2h) |
| Jueves | Python: scripts de automatización reales para taskapi (1.5h) + DSA un problema (1h) |
| Viernes | Seguridad: aplicar checklist a taskapi (1.5h) + modelado de datos (1h) |
| Sábado | 4–5h bloque taskapi: features + tests + benchmarks |
| Domingo | Refactor, Zettels, planear |

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
**Período:** Ene 19 – Abr 18 2027
**Núcleo:** Tu sistema tiene múltiples piezas. Algo siempre falla. Y ahora puedes verlo.

### Videos por tema — Fase 3

**Docker:**

| Tema | Video | Canal | Duración |
|------|-------|-------|----------|
| Docker crash course completo | [Docker Crash Course for Absolute Beginners](https://www.youtube.com/watch?v=pg19Z8LL06w) | TechWorld with Nana | 1h |
| Docker tutorial completo 3h | [Docker Tutorial for Beginners (Full 3h)](https://www.youtube.com/watch?v=3c-iBn73dDE) | TechWorld with Nana | 3h (ver en bloques) |
| Playlist Docker paso a paso | [Docker Tutorial for Beginners — Playlist](https://www.youtube.com/playlist?list=PLy7NrYWoggjzfAHlUusx2wuDwfCrmJYcs) | TechWorld with Nana | varios |

**Redis:**

| Tema | Video | Canal |
|------|-------|-------|
| Redis internals y patterns | [Canal Confluent — Redis patterns](https://www.youtube.com/@Confluent) | Confluent |
| Cache-aside explicado | Buscar "cache aside pattern redis" en YouTube | varios |

**Observabilidad (los tres pilares):**

| Tema | Recurso |
|------|---------|
| OpenTelemetry docs oficiales | [opentelemetry.io/docs](https://opentelemetry.io/docs) |
| Prometheus docs | [prometheus.io/docs](https://prometheus.io/docs) |
| Buscar en YouTube | "opentelemetry golang tutorial 2024" y "prometheus grafana go tutorial" |

**CI/CD con GitHub Actions:**

| Tema | Recurso |
|------|---------|
| Docs oficiales GitHub Actions | [docs.github.com/actions](https://docs.github.com/en/actions) |
| Buscar en YouTube | "github actions golang ci cd tutorial" |

**Patrones de resiliencia:**

| Tema | Recurso |
|------|---------|
| Circuit Breaker — artículo original | [martinfowler.com/bliki/CircuitBreaker](https://martinfowler.com/bliki/CircuitBreaker.html) |
| Buscar en YouTube | "circuit breaker pattern golang implementation" |

**DSA — Grafos:**

| Tema | Video | Canal |
|------|-------|-------|
| BFS y DFS | [Fiset playlist — Graph Theory sección](https://www.youtube.com/playlist?list=PLDV1Zeh2NRsB6SWUrDFW2RmDotAfPbeHu) | WilliamFiset |

### Libros como referencia

| Libro | Cuándo abrirlo |
|-------|----------------|
| DDIA caps. 5, 7, 8 — Kleppmann | Al estudiar replication, transactions distribuidas, CAP theorem |
| *Release It!* — Michael Nygard | Al implementar Circuit Breaker — para entender por qué existe |

### Repositorio — Fase 3

```
learning-distributed/
├── Makefile
├── README.md
├── 01-docker-fundamentals/
│   ├── Dockerfile              # multi-stage build de taskapi
│   └── .dockerignore
├── 02-docker-compose-multi/
│   └── docker-compose.yml      # api + postgres + redis + prometheus + grafana
├── 03-redis-patterns/
│   ├── cache_aside.go
│   ├── rate_limiter.go         # sliding window con sorted sets + Lua
│   └── pubsub_demo.go
├── 04-observability/
│   ├── structured_logger.go    # logger JSON con slog
│   ├── metrics.go              # Prometheus counters e histogramas
│   └── tracing.go              # OpenTelemetry setup
├── 05-circuit-breaker/
│   └── circuit_breaker.go      # implementación desde cero
├── 06-cicd/
│   └── .github/workflows/
│       └── ci.yml
└── 07-dsa-graphs/
    ├── bfs_dfs.go
    └── consistent_hash.go
```

### Proyecto Principal — `resilient-api`

**taskapi con Redis, múltiples servicios, observabilidad y CI/CD**

- `api-service` (Go): taskapi dockerizada con observabilidad completa
- `notifications-service` (Go): servicio separado con healthcheck
- Redis: cache-aside + rate limiting distribuido con Lua
- Circuit Breaker manual: se activa si notifications-service falla
- Logs JSON con `request_id` propagado entre servicios
- Métricas Prometheus: latencia, cache hit/miss, estado del Circuit Breaker
- Tracing OpenTelemetry: ver el flujo completo en un trace
- `docker compose up` levanta todo
- GitHub Actions: PR bloqueado si tests fallan

**Verificar que el Circuit Breaker funciona:**
```bash
docker compose stop notifications-service
wrk -t2 -c50 -d10s http://localhost:8080/api/tasks
# En Grafana: circuit_breaker_state == open
# api-service sigue respondiendo — no cayó con él
```

### Horario semanal — Fase 3

| Día | Actividad |
|-----|-----------|
| Lunes–Martes | Docker: video (20 min) → Obsidian → dockerizar taskapi (2h) |
| Miércoles | Redis: docs + video → Obsidian → cache-aside en código (2h) |
| Jueves | DDIA cap. correspondiente + observabilidad (Prometheus o OTel) (3.5h) |
| Viernes | CI/CD con GitHub Actions + DSA grafos (3.5h) |
| Sábado | 4–5h bloque resilient-api: integrar todo, verificar en Grafana |
| Domingo | Refactor, Zettels, planear |

### Notas Zettelkasten — Fase 3

```
Pattern - Circuit Breaker Pattern.md
Pattern - Retry with Exponential Backoff and Jitter.md
Pattern - Cache-Aside Pattern.md
Distributed - CAP Theorem.md
Distributed - Eventual Consistency.md
Observability - Structured Logging JSON.md
Observability - Prometheus Metrics Types.md
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
**Período:** Abr 19 – Jul 18 2027
**Núcleo:** El camino del Data Engineer. Python al nivel que el mercado paga bien.

### Videos por tema — Fase 4

**Python nivel experto:**

| Tema | Video/Recurso | Canal |
|------|---------------|-------|
| Generators y decorators | Buscar "python generators decorators real python" en YouTube | Real Python channel |
| Async/await y asyncio | Buscar "python asyncio explained 2024" en YouTube | varios |
| Profiling con cProfile | Buscar "python profiling cprofile tutorial" en YouTube | varios |

> Para Python experto, el libro *Fluent Python* de Ramalho es tan denso y bueno que en este caso sí recomiendo leer los capítulos específicos: caps. 14 (iterables/generators), 7 (decorators), 18 (async). Son capítulos con código en cada página — no lectura pasiva.

**Apache Kafka:**

| Tema | Video | Canal | Duración |
|------|-------|-------|----------|
| Kafka tutorial beginner completo | [Kafka Tutorial — Everything to get started](https://www.youtube.com/watch?v=QkdkLdMBuL0) | TechWorld with Nana | 30 min |
| Kafka para beginners práctico | [Apache Kafka for beginners practical](https://www.youtube.com/watch?v=HfJwUnW2EQ8) | YouTube 2025 | 45 min |
| Playlist Kafka — Confluent | [Apache Kafka for Beginners playlist](https://www.youtube.com/playlist?list=PLt1SIbA8guusxiHz9bveV-UHs_biWFegU) | Confluent oficial | varios |
| DataExpert boot camp — Data Engineering | [6-week DE Boot Camp — Zach Wilson](https://www.youtube.com/watch?v=HU2T03ckAno) | DataExpert.io | boot camp completo |
| Data modeling — Day 1 DataExpert | [Data Modeling Complex Types — Day 1](https://www.youtube.com/watch?v=5U-BbZ9G_xU) | DataExpert.io | 1h |

**Canal principal de Data Engineering:**
- [Data with Zach — YouTube](https://www.youtube.com/c/datawithzach) — experiencia real en Facebook y Netflix

**dbt y DuckDB:**

| Tema | Recurso |
|------|---------|
| Tutorial oficial dbt | [docs.getdbt.com](https://docs.getdbt.com) — seguir el tutorial oficial |
| DuckDB docs | [duckdb.org/docs](https://duckdb.org/docs) |
| Buscar en YouTube | "dbt tutorial beginner 2024" y "duckdb python tutorial" |

### Arquitecturas de datos — al mes 11

> Cuando diseñes tu pipeline y necesites decidir entre batch y streaming, ESE momento estudias estas arquitecturas.

**Videos:**

| Tema | Recurso |
|------|---------|
| Lambda vs Kappa | Buscar "lambda architecture vs kappa architecture explained" en YouTube — ByteByteGo tiene buenos videos |
| DDIA caps. 10–11 | Abrir el libro en esos capítulos como referencia al estudiar Kafka |

### Libros como referencia

| Libro | Cuándo abrirlo |
|-------|----------------|
| *Fundamentals of Data Engineering* — Reis & Housley | Referencia del campo — leer caps. correspondientes al tema de la semana |
| *Fluent Python* — Ramalho | Caps. 7, 14, 18 — los únicos que recomiendo leer de corrido por su densidad |
| DDIA caps. 10–11 | Batch y stream processing — al estudiar Kafka y dbt |

### Repositorio — Fase 4

```
learning-data-engineering/
├── Makefile            # levanta Kafka + PostgreSQL + dbt con Docker
├── README.md
├── 01-python-expert/
│   ├── generators.py
│   ├── decorators.py
│   ├── async_demo.py
│   └── profiling_demo.py
├── 02-pandas-polars-etl/
│   ├── pandas_transforms.py
│   ├── polars_intro.py
│   └── data_cleaning.py
├── 03-kafka-fundamentals/
│   ├── docker-compose.yml
│   ├── producer_basic.py
│   └── consumer_basic.py
├── 04-kafka-advanced/
│   ├── producer_events.py
│   ├── consumer_group.py   # commit manual de offsets
│   └── dlq_handler.py
├── 05-dbt-models/
│   ├── dbt_project.yml
│   └── models/
│       ├── raw/
│       ├── staging/
│       └── mart/
├── 06-duckdb-analytics/
│   └── analytics_queries.sql
└── 07-pipeline-patterns/
    ├── idempotent_pipeline.py
    └── backfill_strategy.py
```

### Proyecto Principal — `eventpipe`

**Pipeline completo de datos end-to-end**

```
[Go API: taskapi] → produce events → [Kafka: task.events]
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

**Prueba de idempotencia obligatoria:**
```bash
psql -c "SELECT COUNT(*) FROM events_raw"   # guardar número
# Reset consumer al offset 0 y reprocesar
kafka-consumer-groups.sh --reset-offsets --to-earliest --group event-processor --execute
python event_processor.py
psql -c "SELECT COUNT(*) FROM events_raw"   # debe ser IDÉNTICO
```

### Horario semanal — Fase 4

| Día | Actividad |
|-----|-----------|
| Lunes–Martes | Python experto: video (15 min) → Obsidian → generators/decorators/async (2h) |
| Miércoles | Kafka: video tutorial → Obsidian → producer + consumer en código (2h) |
| Jueves | DDIA caps. 10–11 (referencia) + Lambda/Kappa architecture video (3.5h) |
| Viernes | dbt models + DuckDB analytics sobre datos propios (3.5h) |
| Sábado | 4–5h bloque eventpipe: integrar todos los componentes |
| Domingo | Refactor, Zettels, planear |

### Notas Zettelkasten — Fase 4

```
Python - Generator Functions and yield Expression.md
Python - Decorators and Higher Order Functions.md
Python - Async Await and the Event Loop.md
Python - Profiling with cProfile.md
Kafka - Topic Partitioning and Ordering Guarantees.md
Kafka - Consumer Groups and Offset Management.md
Kafka - Dead Letter Queue Pattern.md
Kafka - Producer Acknowledgment Levels.md
Data - Lambda Architecture.md
Data - Kappa Architecture.md
Data - Idempotent Pipeline Design.md
Data - Schema Evolution Strategies.md
dbt - Model Layers Raw Staging Mart.md
dbt - Testing Data Quality with dbt test.md
```

---

## FASE 5 — System Design, Arquitectura Formal, DDD & Infraestructura
**Período:** Jul 19 – Oct 18 2027
**Núcleo:** Todo lo que sufriste ahora tiene nombre, diagrama y tradeoffs documentados.

### Por qué el mes 13 y no antes

A estas alturas has construido un shell en C, una REST API en Go, un sistema distribuido con Circuit Breaker, y un pipeline de datos con Kafka. Cuando leas "diseñar un sistema de mensajería a escala de WhatsApp", cada componente tendrá un rostro concreto. System Design sin experiencia previa es memorización. Con experiencia previa es **reconocimiento**.

### Videos por tema — Fase 5

**System Design — canal principal:**

| Canal | URL | Por qué |
|-------|-----|---------|
| ByteByteGo | [youtube.com/@ByteByteGo](https://www.youtube.com/@ByteByteGo) | Alex Xu, animaciones visuales, 1.2M subs. Empezar aquí. |
| Arpit Bhayani | [youtube.com/channel/UC_b1GUJv_2QiMP4BxC9-Dxg](https://www.youtube.com/channel/UC_b1GUJv_2QiMP4BxC9-Dxg) | Ex-Staff Engineer Google. Profundidad técnica real, sin simplificaciones. |
| Gaurav Sen | Buscar "Gaurav Sen system design" en YouTube | Muy didáctico para entrevistas |

**Videos de System Design específicos (ByteByteGo):**

| Tema | Video |
|------|-------|
| System Design fundamentals free PDF | [bytebytego.com newsletter](https://bytebytego.com) — suscribirse gratis |
| Arpit — cómo abordar System Design | [System Design with Arpit](https://www.youtube.com/watch?v=TEV7I1xYDlE) |

**DDD — fundamentos:**

| Tema | Recurso |
|------|---------|
| DDD intro | Buscar "domain driven design bounded contexts explained" en YouTube |
| Libro de referencia | *Domain-Driven Design Distilled* — Vaughn Vernon (caps. 1–4 como referencia) |

**Kubernetes conceptual:**

| Tema | Recurso |
|------|---------|
| K8s conceptual | Buscar "kubernetes explained in 15 minutes techworld nana" en YouTube — TechWorld with Nana tiene un video perfecto |

### Método de System Design Interview (45 min)

```
00-05 min → Clarify requirements
            "¿Cuántos usuarios? ¿Read-heavy o write-heavy? ¿Global?"
05-10 min → Capacity estimation
            "100M users × 10 req/día = ~12K QPS. Storage: 1KB × 100M = 100GB/día"
10-25 min → High-level design
            Componentes principales, flujo de datos, APIs
25-35 min → Deep dive
            El componente más crítico o el que el entrevistador elija
35-45 min → Tradeoffs
            "¿Qué sacrificaste? ¿Alternativas consideradas? ¿Qué fallaría primero?"
```

### Libros como referencia

| Libro | Cuándo abrirlo |
|-------|----------------|
| *System Design Interview Vol. 1 & 2* — Alex Xu | Al preparar cada caso de SD |
| [system-design-primer](https://github.com/donnemartin/system-design-primer) | Referencia gratuita completa — GitHub |
| DDIA completo — Kleppmann | Terminar los capítulos restantes |
| *Building Microservices* — Sam Newman | Al estudiar microservicios vs monolito |
| [microservices.io](https://microservices.io) | Catálogo de patrones — Chris Richardson |

### Repositorio — Fase 5

```
architecture-docs/
├── README.md
├── adr/
│   ├── template.md
│   ├── 001-why-go-over-java.md
│   ├── 002-postgresql-over-mongodb.md
│   └── 003-kafka-over-rabbitmq.md
├── rfc/
│   ├── template.md
│   └── 001-adding-search-to-taskapi.md
├── postmortem/
│   ├── template.md
│   └── 001-circuit-breaker-misconfiguration.md
├── c4-diagrams/
│   ├── taskapi/
│   └── eventpipe/
├── system-design-cases/
│   ├── url-shortener.md
│   ├── notification-system.md
│   ├── news-feed.md
│   └── chat-system.md
└── ddd/
    ├── taskapi-domain-model.md
    └── bounded-contexts.md
```

### Proyecto Principal — `architecture-docs`

**Re-arquitecturar tus proyectos como si fueran para 1M usuarios**

1. C4 Level 1 y 2 de `taskapi` y `eventpipe`
2. 4 ADRs reales de decisiones tomadas en tus proyectos
3. 1 RFC: "How would I add full-text search to taskapi?"
4. 1 post-mortem de un incidente real que hayas tenido
5. 5 casos de System Design resueltos con el método de 45 min
6. Documento DDD de taskapi: bounded contexts, entities, aggregates

### Horario semanal — Fase 5

| Día | Actividad |
|-----|-----------|
| Lunes | ByteByteGo video del tema (15 min) → Obsidian → leer system-design-primer sección (2h) |
| Martes | Implementar patrón de la semana en código de prueba (CQRS, Saga, etc.) (3.5h) |
| Miércoles | Alex Xu libro cap. correspondiente + escribir ADR o RFC (3.5h) |
| Jueves | DDD: modelar dominio de taskapi. DDIA cap. restante. (3.5h) |
| Viernes | Mock System Design 45 min (timer, papel) + 2 problemas Leetcode medium (3.5h) |
| Sábado | 4–5h bloque architecture-docs: caso SD completo o diagrama C4 |
| Domingo | Refactor Zettels de arquitectura, planear |

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

## FASE 6 — Portfolio, OSS, IA en Proyectos & Job Hunt
**Período:** Oct 19 2027 – Ene 18 2028
**Núcleo:** Convertir 15 meses de trabajo en empleo.

### Videos por tema — Fase 6

**IA en proyectos — RAG y embeddings:**

| Tema | Recurso |
|------|---------|
| Embeddings explicados | Buscar "embeddings explained simply 2024" en YouTube |
| RAG architecture | Buscar "RAG retrieval augmented generation tutorial python 2024" en YouTube |
| pgvector PostgreSQL | [github.com/pgvector/pgvector](https://github.com/pgvector/pgvector) — docs oficiales |
| Modelos locales sin API | [ollama.ai](https://ollama.ai) — correr LLMs localmente en Linux, gratis |

**Interviews — System Design:**

| Canal | URL |
|-------|-----|
| Gaurav Sen | Buscar "Gaurav Sen system design" en YouTube |
| ByteByteGo | [youtube.com/@ByteByteGo](https://www.youtube.com/@ByteByteGo) |
| Arpit Bhayani | [canal de Arpit](https://www.youtube.com/channel/UC_b1GUJv_2QiMP4BxC9-Dxg) |

**Mock interviews:**
- [interviewing.io](https://interviewing.io) — anónimas con engineers reales

### Proyecto Final — `capstone`

```
[Go API: taskapi v3]
    ├── produce events → [Kafka: task.events]
    │                          ↓
    │              [Python: event_processor]
    │                          ↓
    │                  [PostgreSQL + pgvector]
    │                          ↓
    │                  [dbt: staging → marts]
    │                          ↓
    │                  [DuckDB: analytics]
    │
    ├── GET /analytics/summary → consulta marts
    └── GET /search/semantic?q=... → RAG con pgvector

Observabilidad: Prometheus + Grafana + OpenTelemetry
CI/CD: GitHub Actions
Deployment: docker compose up
```

**Entregables:**
```
capstone/
├── README.md           # arquitectura, cómo correrlo, decisiones técnicas
├── ARCHITECTURE.md     # C4 diagrams + ADRs
├── BENCHMARKS.md       # throughput Kafka, latencia queries, tiempo dbt
├── RUNBOOK.md          # cómo operar y debuggear
└── docker-compose.yml
```

### Open Source — dónde contribuir

```bash
# Buscar en GitHub:
label:"good first issue" language:Go
label:"good first issue" language:Python
```

**Proyectos relevantes al stack:**
- `sqlc` — Go SQL code generator: documentación, tests
- `dbt-core` — Python: mejoras a tests o documentación
- `pgx` — Go PostgreSQL driver: issues good-first-issue
- `polars` — Python/Rust: documentación o ejemplos

### Leetcode — distribución de los 80 problemas

| Categoría | Cantidad | Por qué |
|-----------|----------|---------|
| SQL medium (window functions, CTEs, joins) | 25 | Directo al core de Data Engineering |
| Arrays y hashmaps en Go | 30 | El 80% de las preguntas de backend |
| Strings en Go | 15 | Común en entrevistas |
| Árboles básicos | 10 | Para completar el perfil |

> No necesitas dynamic programming avanzado para roles Backend/Data Jr.

### Horario semanal — Fase 6

| Día | Actividad |
|-----|-----------|
| Lunes–Miércoles | Leetcode o contribución OSS — 1h máximo. No más. |
| Jueves–Viernes | Portfolio refinement, aplicaciones a empleos, posts técnicos |
| Sábado | Mock interview (45 min) o trabajo en capstone |
| Domingo | Retrospectiva semanal de job hunt, ajustar estrategia |

### Notas Zettelkasten — Fase 6

```
AI - Embeddings and Cosine Similarity.md
AI - RAG Retrieval Augmented Generation Architecture.md
AI - pgvector Vector Search in PostgreSQL.md
AI - When Not to Use AI in a System.md
AI - Effective Technical Prompting.md
Career - Technical README Structure.md
Career - System Design Interview Framework 45min.md
Career - Elevator Pitch for Technical Projects.md
Interview - Capacity Estimation Cheatsheet.md
```

---

## El libro que amarra todo — DDIA

*Designing Data-Intensive Applications* de Kleppmann. No se lee de corrido — se abre como referencia en el momento que corresponde:

| Capítulos | Fase | Por qué en ese momento |
|-----------|------|------------------------|
| Cap. 2 — Data Models | F2 (M5) | Cuando diseñas el schema de taskapi |
| Cap. 5 — Replication | F3 (M7) | Cuando tu sistema tiene múltiples nodos |
| Cap. 7 — Transactions | F3 (M8) | Cuando implementas transacciones distribuidas |
| Cap. 8 — Distributed Problems | F3 (M9) | CAP Theorem, clocks, consensus |
| Cap. 10 — Batch Processing | F4 (M10) | Lambda Architecture |
| Cap. 11 — Stream Processing | F4 (M11) | Kappa Architecture, Kafka internals |
| Caps. 1, 3, 4, 6, 9, 12 | F5 (M13-14) | Completar el libro con toda la base construida |

---

## Resumen de proyectos principales

| Fase | Proyecto | Stack | Qué demuestra |
|------|----------|-------|---------------|
| F1 | `mysh` — Mini Shell UNIX | C, GCC, Make | Procesos, memoria, syscalls, DSA aplicado |
| F2 | `taskapi` — REST API segura | Go, Python, PostgreSQL | Backend productivo, seguridad, modelado |
| F3 | `resilient-api` — API distribuida | Go, Docker, Redis, OTel | Resiliencia, observabilidad, CI/CD |
| F4 | `eventpipe` — Pipeline de datos | Python experto, Kafka, dbt | Data Engineering end-to-end |
| F5 | `architecture-docs` — Docs técnicas | C4, ADRs, RFCs, DDD | Pensar y comunicar arquitectura |
| F6 | `capstone` — Sistema integrado | Todo el stack + RAG | Portfolio de empleabilidad |

---

## Canales de YouTube — referencia rápida

| Canal | Fases | Especialidad |
|-------|-------|-------------|
| [Jacob Sorber](https://www.youtube.com/channel/UCwd5VFu4KoJNjkWJZMFJGHQ) | F1 | C, Linux, sistemas UNIX |
| [WilliamFiset](https://www.youtube.com/channel/UCD8yeTczadqdARzQUp29PJw) | F1–F3 | DSA, estructuras de datos |
| [Anthony GG](https://www.youtube.com/@anthonygg_) | F2 | Go proyectos reales |
| [TechWorld with Nana](https://www.youtube.com/c/techworldwithnana) | F3 | Docker, Kubernetes, CI/CD |
| [Confluent oficial](https://www.youtube.com/@Confluent) | F4 | Kafka internals y patterns |
| [Data with Zach](https://www.youtube.com/c/datawithzach) | F4 | Data Engineering real |
| [DataExpert.io](https://www.youtube.com/@DataExpertio) | F4 | Boot camp Data Engineering gratuito |
| [ByteByteGo](https://www.youtube.com/@ByteByteGo) | F5–F6 | System Design visual |
| [Arpit Bhayani](https://www.youtube.com/channel/UC_b1GUJv_2QiMP4BxC9-Dxg) | F5–F6 | System Design profundo |

---

## Stack completo al mes 18

```
Sistemas y bajo nivel:     C, GCC, Makefiles, Linux Internals, GDB, Valgrind
Backend:                   Go (APIs, microservicios) + Python (data, scripting, IA)
Base de datos:             PostgreSQL (transaccional + vector) + DuckDB (analytics)
Mensajería:                Apache Kafka
Transformaciones:          dbt
Caché:                     Redis
Infraestructura:           Docker + Compose + GitHub Actions
Observabilidad:            Prometheus + Grafana + OpenTelemetry
IA aplicada:               Embeddings + pgvector + RAG básico
Arquitectura:              System Design, CQRS, Event Sourcing, Saga, DDD, C4, ADRs
```

---

## Perfil al mes 18

El engineer que sale de este roadmap:

- Entiende qué hace el kernel cuando llama a `fork()` y puede explicarlo
- Construye APIs que aguantan carga porque entiende concurrencia real
- Diseña pipelines de datos que no fallan silenciosamente
- Cuando algo explota en producción, sabe mirarlo: logs, métricas, traces
- Puede dibujar la arquitectura de un sistema y defender cada decisión
- Escribe código seguro por defecto, no como afterthought
- Usa IA con criterio — como herramienta, no como muleta

Ese perfil es competitivo para roles mid-level desde el primer empleo.

---

*Idioma del código: English only*
*Sistema de notas: Obsidian Flat Zettelkasten*
*Entorno: Linux (Arch/Fedora), Neovim, Warp terminal*
