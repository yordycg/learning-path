# Roadmap — Backend & Systems Engineering

> **Ingeniería en Informática → Especialista en Backend & Systems Engineering (Go + PostgreSQL)**
> 
> **Estrategia en Dos Etapas:**
> 1. **Etapa 1 (Pre-Graduación, hasta Dic 2027):** 5 fases enfocadas 100% en fundamentos de acero, Go idiomático, PostgreSQL profundo, Docker, Redis, Arquitectura Hexagonal, DDD y System Design práctico, con buffer de 14 semanas para tesis y contratación remota en USD.
> 2. **Etapa 2 (Post-Graduación, 2028+):** Especializaciones continuas mientras se trabaja o emprende: Data Engineering (Kafka, dbt, DuckDB), Cloud (AWS) & Kubernetes, y Mobile Multiplataforma (KMP).

---

## Resumen de fases — Etapa 1: Pre-Graduación (Universidad)

| Fase | Período Proyectado | Foco Técnico Principal | Entregable / Hito |
| :--- | :--- | :--- | :--- |
| **F1** | 14 jun – 1 nov 2026 | Linux Internals, C & DSA Fundamentos | `mysh v2.0` (cerrado) + DSA en C desde cero |
| **F2** | 2 nov 2026 – 31 ene 2027 | Go Idiomático + PostgreSQL Profundo + Seguridad | Proyecto `taskapi` (REST API segura en Go + Postgres) |
| **F3** | 1 feb – 28 mar 2027 | Sistemas Distribuidos + Docker + Redis + Observabilidad + CI/CD | Proyecto `resilient-api` (microservicio con métricas OTel) |
| **F4** | 29 mar – 13 jun 2027 | Arquitectura de Software, DDD & System Design Práctico | Proyecto `architecture-docs` (Fly.io retos 1-4, C4, ADRs) |
| **F5** | 14 jun – 29 ago 2027 | Portfolio de Alto Impacto & Preparación de Entrevistas | 2 proyectos estrella en GitHub + mocks STAR (Silver.dev) |
| **BUFFER** | **30 ago – 15 dic 2027** | **Tesis de grado, certámenes finales y contratación remota USD** | 🎓 **Graduación con empleo asegurado** |

---

## Especializaciones — Etapa 2: Post-Graduación (2028+)

| Especialización | Ámbito | Foco y Tecnologías |
| :--- | :--- | :--- |
| **Esp. A** | **Data Engineering** | Python idiomático, Kafka streaming, dbt, DuckDB, modelado Kimball (`eventpipe`) |
| **Esp. B** | **Cloud (AWS) & Kubernetes** | ECS/EKS, *Kubernetes the Hard Way*, RDS, Terraform, cert. SAA-C03 |
| **Esp. C** | **Mobile Multiplataforma** | Kotlin + Compose Multiplatform (KMP) como cliente del stack backend |

---

**Disciplinas que atraviesan varias fases:**

- **DSA:** F1 (arrays, punteros, linked lists, hash tables en C) → F2 (árboles, sorting, slices en Go) → F3 (consistent hashing, caching) → F5 (repaso continuo para entrevistas en Go).
- **Seguridad:** F2 (OWASP, JWT, secrets, bcrypt).
- **Arquitectura & Patrones:** F2 (Repository, interfaces) → F3 (Circuit Breaker, Retry, Cache-aside) → F4 (Clean Architecture/Hexagonal, DDD táctico, Monolito Modular, Fly.io retos distribuidos).
- **Comunicación técnica:** F4 (ADRs, RFCs, post-mortems, C4) → F5 (READMEs que convierten, behavioral STAR).

---

## FASE 1 — Linux Internals, C & DSA Fundamentos

**Período:** 14 jun – 1 nov 2026

### Objetivos

- Aritmética de punteros y gestión manual de heap. Modelo de memoria (Stack/Heap/BSS/Text).
- Syscalls directas (`read`, `write`, `open`, `fork`, `exec`, `wait`), señales UNIX, IPC con pipes/FIFOs.
- Makefiles, GDB y Valgrind.
- DSA en C desde cero: arrays, linked lists, stacks, queues, hash tables. Complejidad algorítmica.

### C, memoria, threads, Linux Internals, debugging

**Confirmado en la práctica** (ya completado por el estudiante hasta `mysh` v2.0):

- Canal principal: **Jacob Sorber** (YouTube) — C, memoria, pthreads, syscalls, Makefiles, GDB/Valgrind. [Playlist C](https://www.youtube.com/playlist?list=PLs87dCfSJbLf-nPShgl5WhVkcgxRKZndb) · [Playlist Debugging](https://www.youtube.com/playlist?list=PL9IEJIKnBJjHGWPN_S9NS_Ky1-tC8ZrUI)
- Referencia futura (reputación conocida): [Beej's Guide to Network Programming](https://beej.us/guide/bgnet/) para sockets en Go (F2); **OSTEP** (Operating Systems: Three Easy Pieces) para profundizar procesos/memoria si hace falta.
- Libros de referencia puntual: _The C Programming Language_ (K&R), _CS:APP_ (Bryant & O'Hallaron), _The Algorithm Design Manual_ caps. 1–4 (Skiena).
- Extra: [CMU 15-213 — playlist completa](https://www.youtube.com/playlist?list=PLMDSb3PWPnvhsmuSZ5R7c1JY2kaSdYYdh)

### DSA

| Rol                        | Recurso                                       | Confianza | Notas                                                                |
| -------------------------- | --------------------------------------------- | --------- | -------------------------------------------------------------------- |
| Concepto (videos)          | [Princeton Algorithms Part I](https://www.coursera.org/learn/algorithms-part1) — solo los videos | Alta      | Gratis (audit). En Java — se implementa en C/Go                      |
| Apoyo interactivo          | [OpenDSA](https://opendsa-server.cs.vt.edu/)  | Alta      | Gratis, ejercicios interactivos de código                            |
| Apoyo interactivo          | [VisuAlgo](https://visualgo.net/)             | Media     | No verificado con búsqueda dedicada, pero muy recomendado en general |
| Práctica (hilo permanente) | [NeetCode — Blind 75 → 150](https://neetcode.io/practice) | Alta      | Mayormente gratis, Pro opcional. Resolver en Go                      |
| Referencia                 | [Open Data Structures](https://opendatastructures.org/) | Media     | Recomendado, no verificado con búsqueda dedicada                     |
| Repaso espaciado           | [Anki](https://apps.ankiweb.net/) (escritorio) | —         | Una tarjeta por error cometido                                       |

**Plan:** 3 semanas en C (dynamic array, linked list, hash table), resto de estructuras (stack, queue, BST, sorting) directo en Go desde F2 (~3h/semana, 2-3 problemas nuevos + 1h de repaso espaciado). Si tras 30-45 min no sale un problema: ver la solución en NeetCode, entender el patrón, y al día siguiente reescribirlo desde cero. Repasos a 1 día, 3 días, 1 semana, 2 semanas, 1 mes, 3 meses.

**Complementos del roadmap original (no verificados por SOURCES.md, útiles como práctica adicional):** [Data Structures Easy to Advanced](https://www.youtube.com/watch?v=RBSGKlAvoiM) (freeCodeCamp/Fiset, ver por secciones); [70 Leetcode problems](https://www.youtube.com/watch?v=lvO88XxNAzs) (Stoney codes, problemas reales por estructura).

### Proyecto principal — `mysh` (Mini Shell UNIX en C)

Parseo de comandos, ejecución con `fork`+`exec` (sin `system()`), pipes (`cmd1 | cmd2 | cmd3`), redirección (`>`, `<`, `>>`), manejo de `Ctrl+C` sin matar el shell, historial en memoria con linked list propia, built-ins (`cd`, `exit`, `echo`).

---

## FASE 2 — Go + PostgreSQL Profundo + Seguridad

**Período:** 2 nov 2026 – 31 ene 2027 (~13 semanas: semestre + vacaciones + buffer)

### Go

| Rol                 | Recurso                                                                                                                                         | Confianza  | Notas                                                                        |
| ------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------- | ---------- | ---------------------------------------------------------------------------- |
| Arranque            | [A Tour of Go](https://go.dev/tour/)                                                                                                            | Alta       | Oficial, gratis, ejercicios en el navegador                                  |
| Principal           | [Learn Go with Tests](https://quii.gitbook.io/learn-go-with-tests)                                                                              | Alta       | Gratis, TDD. Interfaces, DI, mocking, concurrencia, context, HTTP con stdlib |
| Práctica idiomática | Exercism — pista de Go                                                                                                                          | Media-alta | Gratis, 165 ejercicios, mentoría humana voluntaria                           |
| Referencia          | [Go by Example](https://gobyexample.com/), [Effective Go](https://go.dev/doc/effective_go), [go.dev/doc/tutorial](https://go.dev/doc/tutorial/) | Media-alta | Consulta mientras se construye                                               |
| Opcional            | Gophercises                                                                                                                                     | Media-baja | Gratis pero antiguo (~2018), dependencias pueden requerir adaptación         |
| Repaso posterior    | 100 Go Mistakes (versión web)                                                                                                                   | —          | Cuando ya haya código real escrito                                           |

Complemento: canal [Anthony GG](https://www.youtube.com/@anthonygg_) (proyectos reales en Go); charlas de Rob Pike ([Concurrency Patterns](https://www.youtube.com/watch?v=f6kdp27TYZs), [Advanced Concurrency](https://www.youtube.com/watch?v=QDDwwePbDtw)); _The Go Programming Language_ (Donovan & Kernighan).

### PostgreSQL

| Rol                  | Recurso                                                            | Confianza | Notas                                                   |
| -------------------- | ------------------------------------------------------------------ | --------- | ------------------------------------------------------- |
| Principal (SQL)      | [pgexercises.com](https://pgexercises.com)                         | Alta      | Gratis, listado en recursos oficiales de postgresql.org |
| Apoyo interactivo    | [Postgres Playground](https://www.snowflake.com/en/developers/postgres/learn-postgres-tutorials/) (Snowflake / ex-Crunchy Data) | Media     | Verificar el link vigente antes de usar                 |
| Índices              | [Use The Index, Luke](https://use-the-index-luke.com)              | Alta      | Gratis, mantenido activamente                           |
| Referencia           | Documentación oficial — [Concurrency Control](https://www.postgresql.org/docs/current/mvcc.html) y [Performance Tips](https://www.postgresql.org/docs/current/performance-tips.html) | Alta      | Transacciones, aislamiento, `EXPLAIN`                   |
| Consulta rápida      | [postgresqltutorial.com](https://www.postgresqltutorial.com/) (alojado en Neon) | Media     | Solo para sintaxis puntual                              |
| Profundidad opcional | [CMU 15-445](https://www.youtube.com/playlist?list=PLSE8ODhjZXjaKScG3l0nuOiDTTqpfnWFf) (Andy Pavlo, YouTube) | —         | Storage, índices, transacciones                         |

Complemento: [Database Indexing Explained](https://www.youtube.com/watch?v=-qNSXK7s7_w) (Hussein Nasser); _PostgreSQL: Up and Running_ (Regina Obe).

### Modelado de datos / ER

| Rol           | Recurso                                           | Confianza | Notas                                                             |
| ------------- | ------------------------------------------------- | --------- | ----------------------------------------------------------------- |
| Principal     | [CS50 SQL (Harvard OCW)](https://cs50.harvard.edu/sql/) — semanas 1-4 | Alta      | Gratis. Lecture 2 "Designing" cubre schemas, tipos, normalización |
| Apoyo (video) | [freeCodeCamp — "Learn Relational Database Design"](https://www.youtube.com/watch?v=ztHopE5Wnpc) | Alta      | El curso es gratis (el libro en que se basa, no)                  |
| Referencia    | [UC Berkeley CS 186, Note 13 (DB Design)](https://cs186berkeley.net/notes/note13/) | Media     | No verificado con búsqueda dedicada                               |

### Seguridad backend

| Rol                  | Recurso                                                                                                          | Confianza | Notas                                                    |
| -------------------- | ---------------------------------------------------------------------------------------------------------------- | --------- | -------------------------------------------------------- |
| Principal (práctica) | [PortSwigger Web Security Academy](https://portswigger.net/web-security) — solo SQL Injection, Authentication y JWT | Alta      | 100% gratis. Enfoque en explotar — traducir a la defensa |
| Apoyo (checklist)    | [OWASP Cheat Sheet Series](https://cheatsheetseries.owasp.org/) — Password Storage, JWT, Input Validation, SQL Injection Prevention, Secrets Management | Alta      | Es checklist, no curso                                   |
| Referencia           | [OWASP Top 10](https://owasp.org/www-project-top-ten/) (versión **2025**, la vigente)                           | Alta      | —                                                        |

Flujo sugerido: resolver el lab de PortSwigger → volver al código en Go y aplicar la cheat sheet correspondiente.

**Checklist obligatorio antes de cerrar F2:**

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

### Proyecto principal — `taskapi` (REST API con Go + PostgreSQL)

CRUD de tasks/usuarios con schema modelado (ER diagram primero), JWT propio (sin librerías de auth), bcrypt, rate limiting con goroutines/channels, índices parciales, transacciones multi-step, `pgxpool`, `sqlx` (cero ORMs), tests con mocking vía interfaces, script Go/SQL para poblar la DB y parsear logs.

---

## FASE 3 — Sistemas Distribuidos + Docker + Redis + Observabilidad + CI/CD

**Período:** 1 feb – 28 mar 2027 (8 semanas)

### Docker

| Rol                               | Recurso                                                                    | Confianza | Notas                                                                           |
| --------------------------------- | -------------------------------------------------------------------------- | --------- | ------------------------------------------------------------------------------- |
| Principal                         | [docker-curriculum.com](https://docker-curriculum.com) (Prakhar Srivastav) | Alta      | Gratis, MIT license, activamente mantenido. Autor es Docker Captain             |
| Apoyo interactivo                 | [Docker 101 Tutorial](https://www.docker.com/101-tutorial/)                | Alta      | Oficial. No requiere Docker Desktop ("Play with Docker" o Docker Engine nativo) |
| Para entender "no es magia negra" | [Liz Rice — Build Your Own Container](https://www.youtube.com/watch?v=8fi7uSYlOdc) ([charla](https://www.youtube.com/watch?v=8fi7uSYlOdc) + [repo en Go](https://github.com/lizrice/containers-from-scratch)) | Alta | Conecta con procesos/namespaces/syscalls de F1 |
| Referencia                        | [Documentación oficial — Dockerfile best practices](https://docs.docker.com/build/building/best-practices/) | Alta      | Multi-stage build de `taskapi`                                                  |

Complemento: canal TechWorld with Nana (crash course, playlist) para formato video largo.

### Redis

| Rol        | Recurso                                                          | Confianza  | Notas                                                          |
| ---------- | ---------------------------------------------------------------- | ---------- | -------------------------------------------------------------- |
| Principal  | [Redis University — "Get Started with Redis"](https://university.redis.com/) | Alta       | Gratis. El curso reemplazó al antiguo "RU101" en 2024          |
| Apoyo      | [Build Your Own Redis (CodeCrafters)](https://codecrafters.io/challenges/redis), en Go | Media-alta | Verificar si la capa gratuita alcanza para el material teórico |
| Referencia | Documentación oficial de Redis — [Data Types](https://redis.io/docs/latest/develop/data-types/) + [Commands Reference](https://redis.io/docs/latest/commands/) | Alta       | Cada comando trae su complejidad Big-O                         |

### Observabilidad (Prometheus + Grafana + OpenTelemetry)

| Rol                      | Recurso                                                                                                                              | Confianza | Notas                                                               |
| ------------------------ | ------------------------------------------------------------------------------------------------------------------------------------ | --------- | ------------------------------------------------------------------- |
| Principal                | [Monitor a Golang application with Prometheus and Grafana](https://docs.docker.com/guides/go-prometheus-monitoring/) (Docker Guides) | Alta      | Guía oficial de Docker, código Go completo, `compose.yml` funcional |
| Apoyo (tracing)          | OpenTelemetry Go — [Getting Started](https://opentelemetry.io/docs/languages/go/getting-started/)                                    | Alta      | Oficial, spans, contexto, exportación OTLP a Jaeger                 |
| Referencia               | Prometheus Docs — [Understanding metric types](https://prometheus.io/docs/tutorials/understanding_metric_types/)                     | Alta      | Counter vs gauge vs histogram                                       |
| Marco teórico (opcional) | Peter Bourgon — "Metrics, tracing, and logging"                                                                                      | Media     | Explica el "por qué"                                                |

> OpenTracing y `jaeger-client-go` están oficialmente obsoletos, reemplazados por OpenTelemetry.

### CI/CD (GitHub Actions)

| Rol                      | Recurso                                                                                                                                                                      | Confianza | Notas                                                                         |
| ------------------------ | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | --------- | ----------------------------------------------------------------------------- |
| Principal                | [GitHub Skills — Continuous Integration](https://github.com/skills/continuous-integration)                                                                                   | Alta      | Curso interactivo real, <2h                                                   |
| Apoyo                    | [Tutorials for GitHub Actions](https://docs.github.com/en/actions/tutorials)                                                                                                 | Alta      | 12 tutoriales, incl. build/test en Go, service containers de Postgres y Redis |
| Referencia               | [Quickstart](https://docs.github.com/en/actions/get-started/quickstart) + [Building and testing your code](https://docs.github.com/en/actions/tutorials/build-and-test-code) | Alta      | —                                                                             |
| Apoyo teórico (opcional) | [Full Stack Open — Part 11: CI/CD](https://fullstackopen.com/en/part11)                                                                                                      | Media     | Proyecto en Node/JS — adaptar comandos                                        |

### Circuit Breaker / Patrones de resiliencia

| Rol                       | Recurso                                                                                                                              | Confianza  | Notas                                                               |
| ------------------------- | ------------------------------------------------------------------------------------------------------------------------------------ | ---------- | ------------------------------------------------------------------- |
| Principal (fundamentos)   | [sony/gobreaker](https://github.com/sony/gobreaker)                                                                                  | Alta       | Estándar de facto para Circuit Breaker en Go                        |
| Principal (rate limiting) | [golang.org/x/time/rate](https://pkg.go.dev/golang.org/x/time/rate)                                                                  | Alta       | Oficial, Token Bucket. Solo en memoria local — para réplicas, Redis |
| Apoyo                     | [failsafe-go](https://github.com/failsafe-go/failsafe-go)                                                                            | Alta       | Retry, Circuit Breaker, Bulkhead, Rate Limiter, Timeout, Fallback   |
| Apoyo (práctica aplicada) | [threedots.tech](https://threedots.tech/) (Three Dots Labs)                                                                          | Media-alta | —                                                                   |
| Referencia                | [Azure Architecture Center — Circuit Breaker pattern](https://learn.microsoft.com/en-us/azure/architecture/patterns/circuit-breaker) | Alta       | Agnóstica al lenguaje                                               |
| Apoyo teórico (opcional)  | [kat-co/concurrency-in-go-src](https://github.com/kat-co/concurrency-in-go-src)                                                      | Alta       | Bulkhead/Timeout con stdlib desde cero                              |

Complemento: artículo original de Martin Fowler ([martinfowler.com/bliki/CircuitBreaker](https://martinfowler.com/bliki/CircuitBreaker.html)); _Release It!_ (Michael Nygard).

### Proyecto principal — `resilient-api`

`taskapi` con Redis (cache-aside + rate limiting distribuido con Lua), un segundo servicio (`notifications-service`) con Circuit Breaker manual, logs JSON con `request_id` propagado, métricas Prometheus, tracing OpenTelemetry, `docker compose up`, CI con GitHub Actions bloqueando el PR si fallan los tests.

---

## FASE 4 — Arquitectura de Software, DDD & System Design Práctico

**Período:** 29 mar – 13 jun 2027 (11 semanas)

> **Enfoque de esta fase:** Dominar los principios de diseño de sistemas distribuidos y arquitectura de software necesarios para diseñar, estructurar y defender sistemas backend en producción y entrevistas técnicas de nivel internacional.
>
> - **System Design & Sistemas Distribuidos:** Consistencia, replicación, particionamiento, trade-offs CAP/PACELC y colas distribuidas. Se enfoca en criterio de ingeniería y resolución de problemas reales (método de 45 min), complementado con retos prácticos de validación automática en Go ([Fly.io Gossip Glomers](https://fly.io/dist-sys/)).
> - **Domain-Driven Design (DDD Táctico & Estratégico en Go):** Modelar el negocio separando Bounded Contexts y construyendo un dominio rico (Value Objects, Entities, Aggregates, Repositories, Domain Events + Outbox Pattern) sobre `taskapi`/`resilient-api`.
> - **Patrones de Arquitectura:** Aislar el dominio de la infraestructura mediante Clean / Hexagonal Architecture en Go y diseño de Monolito Modular.
> - **Patrones de Diseño (GoF idiomático):** Comprender los 23 patrones clásicos a nivel conceptual (intención y trade-offs) y su implementación idiomática en Go (interfaces implícitas, Functional Options, middleware y composición).

### 1. System Design & Sistemas Distribuidos

| Rol | Recurso | Confianza | Notas |
|-----|---------|-----------|-------|
| Principal — retos con validación | [Fly.io Distributed Systems Challenges (Gossip Glomers)](https://fly.io/dist-sys/) | Alta | Retos 1 al 4 (Echo, Unique ID, Broadcast, CRDTs). Validación automática con Maelstrom. SDK nativo en Go |
| Principal — guía integral | [System Design Primer](https://github.com/donnemartin/system-design-primer) | Alta | Compendio de arquitectura, casos resueltos (URL shortener, Pastebin, feed) y flashcards Anki |
| Apoyo — patrones internos | [Catalog of Patterns of Distributed Systems](https://martinfowler.com/articles/patterns-of-distributed-systems/) (Martin Fowler / Unmesh Joshi) | Alta | Cómo resuelven replicación, consenso y logs etcd, Kafka y Cassandra |
| Referencia — papers fundacionales | [Dynamo (Amazon)](https://www.allthingsdistributed.com/files/amazon-dynamo-sosp2007.pdf), [GFS (Google)](https://static.googleusercontent.com/media/research.google.com/en//archive/gfs-sosp2003.pdf), [Bigtable (Google)](https://static.googleusercontent.com/media/research.google.com/en//archive/bigtable-osdi06.pdf) | Alta | Lectura obligada para entender el origen de los sistemas NoSQL y distribuidos modernos |
| Referencia — operaciones reales | [Google SRE Book](https://sre.google/sre-book/) | Alta | SLOs, SLIs, SLAs, error budgets, gestión de fallos en producción |
| Preparación de entrevistas | [ByteByteGo](https://www.youtube.com/@ByteByteGo), [Arpit Bhayani](https://www.youtube.com/channel/UC_b1GUJv_2QiMP4BxC9-Dxg), *System Design Interview Vol. 1 & 2* (Alex Xu), [Silver.dev — System Design Meta](https://docs.silver.dev/interview-ready/system-design-interviews/system-design-meta) (en español), [HelloInterview](https://www.hellointerview.com/) | Alta | Framework de resolución en 45 minutos y mocks |

**Ruta sugerida (4-5 semanas):**
1. Fundamentos y estimaciones de capacidad (QPS, storage, bandwidth, memory) con System Design Primer.
2. Replicación, consistencia (strong vs eventual), particionamiento y teoremas CAP / PACELC.
3. Retos de sistemas distribuidos prácticos: Fly.io Gossip Glomers (Retos 1 a 4 en Go).
4. Lectura de papers clásicos (Dynamo paper: consistent hashing, vector clocks, sloopy quorums).
5. Casos prácticos de entrevista simulados con cronómetro (45 min).

### 2. Domain-Driven Design (DDD Táctico & Estratégico en Go)

| Rol | Recurso | Confianza | Notas |
|-----|---------|-----------|-------|
| Principal — táctico en Go | [DDD Lite / Three Dots Labs](https://threedots.tech/) — series `ddd-lite-in-go`, `repository-pattern-in-go`, `basic-cqrs-in-go` | Alta | Refactoring real de modelo anémico a modelo rico en Go con tests |
| Principal — estratégico | [DDD-Crew — Bounded Context Canvas](https://github.com/ddd-crew/bounded-context-canvas) + [Context Mapping](https://github.com/ddd-crew/context-mapping) | Alta | Plantillas abiertas para modelar dominios y relaciones entre contextos |
| Referencia — filosofía | ["The First 15 Years"](https://leanpub.com/ddd_first_15_years) (Leanpub) | Alta | Gratis ($0.00). Ensayos de Fowler, Evans, Brandolini |
| Referencia extra | ["The Anatomy of DDD"](https://leanpub.com/theanatomyofdomain-drivendesign) y ["DDD Referenz"](https://leanpub.com/ddd-referenz) (Eric Evans) | Alta | Gratis (pay-what-you-want) |
| Apoyo — package layout | Ben Johnson — ["Standard Package Layout"](https://medium.com/@benbjohnson/standard-package-layout-7cd488332d16) | Alta | Estructura idiomática de paquetes en Go citada en la wiki oficial |
| Índice adicional | [DDD-Crew — Free DDD Learning Resources](https://github.com/ddd-crew/free-ddd-learning-resources) | Alta | Colección curada de recursos abiertos de DDD |

**Mapeo DDD → Go:**

| Concepto DDD | Equivalente idiomático en Go |
|---|---|
| Value Object | Struct inmutable por convención, igualdad por valor de sus campos (sin ID) |
| Entity | Struct con identificador explícito (`UUID`/`ULID`) y métodos de mutación que validan invariantes |
| Aggregate Root | Struct que controla el acceso a sus entidades internas, garantizando consistencia transaccional |
| Domain Event | Struct con timestamp y payload inmutable que representa un hecho ocurrido en el dominio |
| Outbox Pattern | Guardar evento en tabla `outbox` en la misma transacción SQL que el agregado; worker en segundo plano publica |
| Repository | `interface` definida en la capa de dominio (`domain`), implementada en infraestructura (`postgres`) |
| Anti-Corruption Layer (ACL) | Paquete adaptador con funciones de traducción puras para aislar modelos externos |

**Ruta sugerida (3 semanas):**
1. Bounded Context Canvas y Context Mapping aplicados a `taskapi` (división entre gestión de tareas y notificaciones/usuarios).
2. Refactor de `taskapi` a modelo rico: Entidades, Value Objects e invariantes de negocio.
3. Agregados y Repository Pattern con interfaces en Go.
4. Domain Events y patrón Transaccional Outbox con PostgreSQL.

### 3. Patrones de Arquitectura en Go

| Rol | Recurso | Confianza | Notas |
|-----|---------|-----------|-------|
| Principal — código real en Go | [Wild Workouts (Three Dots Labs)](https://github.com/ThreeDotsLabs/wild-workouts-go-ddd-example) | Alta | Ejemplo de referencia de Clean/Hexagonal Architecture + CQRS en Go |
| Apoyo — estructura comparada | [go-structure-examples](https://github.com/katzien/go-structure-examples) (Kat Zien) | Alta | Comparativa del mismo servicio: flat, layered, hexagonal y domain-driven |
| Apoyo — EDA/CQRS conceptual | Martin Fowler — ["What do you mean by Event-Driven?"](https://martinfowler.com/articles/201701-event-driven.html) | Alta | Análisis de pros y contras de arquitecturas basadas en eventos |
| Referencia — monolito modular | [Modular Monolith with DDD](https://github.com/kamilgrzybek/modular-monolith-with-ddd) | Media-alta | Principios aplicables al diseño modular en Go |
| Referencia — diseño de APIs | [Microsoft REST API Guidelines](https://github.com/microsoft/api-guidelines) + [Google API Design Guide](https://cloud.google.com/apis/design) | Alta | Estándares de diseño de endpoints, paginación, filtros y códigos HTTP |

**Ruta sugerida (2 semanas):**
1. Arquitectura Hexagonal (Ports & Adapters) en Go: desacoplar HTTP (`handler`) y PostgreSQL (`repository`) del núcleo de negocio.
2. Monolito Modular: encapsular submódulos independientes antes de pensar en microservicios.
3. Diseño de contratos y APIs resilientes.

### 4. Patrones de Diseño (GoF idiomático en Go)

| Rol | Recurso | Confianza | Notas |
|-----|---------|-----------|-------|
| Principal — catálogo conceptual | [Refactoring.Guru — Design Patterns](https://refactoring.guru/design-patterns) | Alta | Catálogo web gratuito con los 23 patrones GoF: intención, diagramas y pros/contras |
| Referencia — Go idiomático | [kat-co/concurrency-in-go-src](https://github.com/kat-co/concurrency-in-go-src) | Alta | Patrones concurrentes en Go (pipeline, fan-out/fan-in, or-done-channel, bridge) |

**Mapeo de Patrones GoF a Go:**
- **Strategy:** Interfaces implícitas de Go (cualquier struct que cumpla un método `Execute()` es una estrategia intercambiable sin jerarquías).
- **Decorator:** Middlewares HTTP (`func(http.Handler) http.Handler`) y struct embedding envolviendo interfaces (`io.Reader` con compresión o hashing).
- **Builder:** Pattern de *Functional Options* (`type Option func(*Server)` → `NewServer(addr, WithTimeout(5*time.Second))`).
- **Factory Method:** Funciones constructoras idiomáticas (`NewUser(...)`, `NewRepository(...)`) que retornan structs o interfaces.
- **Singleton:** Evitado en Go en favor de inyección explícita de dependencias (pasar `*sql.DB`, config o logger como argumento).
- **Adapter:** Struct que implementa una interfaz requerida por el dominio adaptando una librería de terceros.

**Ruta sugerida (1 semana):**
Lectura del catálogo GoF en Refactoring.Guru → identificación y mapeo a equivalentes idiomáticos en Go dentro de `taskapi` y `resilient-api`.

### Proyecto principal — `architecture-docs`

Suite documental de arquitectura profesional que acompaña a los proyectos estrella:
1. **Diagramas C4 (Nivel 1 Contexto y Nivel 2 Contenedores)** para `taskapi` y `resilient-api`.
2. **4 ADRs (Architecture Decision Records):**
   - Elección de PostgreSQL vs NoSQL para el modelo de datos.
   - Estrategia de caching (Cache-Aside con Redis + invalidación).
   - Patrón Transaccional Outbox vs dual-write directo.
   - Autenticación con JWT stateless vs sesiones con Redis.
3. **1 RFC (Request for Comments):** "Propuesta técnica para implementar búsqueda full-text distribuida en taskapi".
4. **1 Post-mortem de incidente simulado:** Análisis de causa raíz (RCA), línea de tiempo y acciones preventivas ante una caída por saturación de conexiones en la base de datos.
5. **5 Casos de System Design resueltos:** Soluciones documentadas siguiendo el método de 45 minutos (URL shortener, Rate Limiter distribuido, Notification Service, Key-Value Store distribuido, Metric Monitoring Service).


---

## FASE 5 — Portfolio de Alto Impacto & Preparación de Entrevistas

**Período:** 14 jun – 29 ago 2027 (11 semanas)

> **Enfoque de esta fase:** Consolidar 2 proyectos estrella de nivel de producción que demuestren dominio de Backend y Sistemas en Go, dominar los filtros de entrevistas técnicas (algoritmos en Go, SQL avanzado, System Design) y preparar la búsqueda laboral remota en USD para el egreso universitario.

### Portfolio

**Regla central:** 2 proyectos estrella de alta fidelidad, no repositorios dispersos a medias.

**Filtro de calidad técnica:**
1. ¿Se levanta con un solo comando? (`docker compose up -d` → sistema corriendo con endpoints y telemetría viva en <90s).
2. ¿Muestra resiliencia ante fallos reales? (Circuit breakers, rate limiting distribuido, transacciones seguras con Outbox, logs estructurados correlacionados por `request_id`).
3. ¿Tiene benchmarks medibles reproducibles? ("throughput de 450 a 3,800 req/s con p99 bajo 25ms bajo carga k6").
4. ¿Tiene documentación de arquitectura profesional? (Diagramas C4, ADRs, RFC, Post-mortem y Runbook operativo).

**Proyectos estrella del portfolio:**

| Proyecto | Base técnica | Qué valida ante reclutadores y líderes técnicos |
|---|---|---|
| **`taskapi` (Backend Production-Ready)** | Go, PostgreSQL, Hexagonal Architecture, DDD táctico, JWT stateless, Outbox Pattern | Dominio del backend moderno: concurrencia segura, arquitectura limpia desacoplada, modelado de datos relacional y transaccionalidad estricta sin ORMs mágicos |
| **`resilient-api` (Distributed & Resilient Backend)** | Go, Redis (caching + rate limiting distribuido con Lua), Circuit Breaker, Prometheus, Grafana, OpenTelemetry, Docker Compose, GitHub Actions CI/CD | Resiliencia distribuida, observabilidad completa en producción (métricas, traces, logs JSON estructurados) y automatización CI/CD profesional |
| *(Diferenciador narrativo)* **`mysh`** | C, POSIX syscalls, procesos UNIX, memoria manual, ASan/UBSan | Criterio de bajo nivel y fundamentos de sistemas: entender qué hace el sistema operativo debajo del runtime de Go |
| *(Suite documental)* **`architecture-docs`** | Diagramas C4, 4 ADRs, 1 RFC, 1 Post-mortem, 5 casos de System Design | Capacidad de comunicar trade-offs, liderar decisiones técnicas y defender diseños ante paneles senior |

**Estructura de un README que convierte:**
- Título + descripción del problema de ingeniería resuelto en una línea.
- Diagrama de arquitectura (C4 Nivel 2 interactivo o imagen limpia).
- Decisiones técnicas y trade-offs justificados (por qué PostgreSQL vs NoSQL, por qué Outbox vs dual-write).
- Tabla de benchmarks de rendimiento reproducibles (`k6` o `vegeta`).
- Guía de inicio rápido en 3 comandos (`git clone`, `docker compose up -d`, `make test`).
- Enlaces a documentación profunda (`ARCHITECTURE.md`, `ADR/`, `RUNBOOK.md`).

### Preparación técnica para entrevistas Backend

| Tema | Qué evalúan realmente | Recurso de preparación |
|---|---|---|
| **SQL avanzado y optimización** | Comprensión del motor relacional (`FROM→WHERE→GROUP BY→HAVING→SELECT→WINDOW→ORDER BY`), índices B-Tree, optimización de queries con `EXPLAIN (ANALYZE, BUFFERS)` | [Use The Index, Luke!](https://use-the-index-luke.com) + práctica sobre PostgreSQL |
| **Estructuras de datos y algoritmos en Go** | Resolución fluida y limpia en Go idiomático (slices, maps, structs, punteros) sin librerías externas. Foco en arrays, strings, dos punteros, hash maps, árboles binarios, heaps y grafos básicos | Práctica intensiva de ~60-80 problemas medium en LeetCode / HackerRank en Go puro |
| **System Design en vivo** | Capacidad de guiar una conversación de diseño de 45 min: clarificar requerimientos (5 min), estimar capacidad (5 min), diseño alto nivel (15 min), deep dive en cuello de botella (10 min), trade-offs y resiliencia (10 min) | [Silver.dev — System Design Meta](https://docs.silver.dev/interview-ready/system-design-interviews/system-design-meta), [ByteByteGo](https://www.youtube.com/@ByteByteGo), [HelloInterview](https://www.hellointerview.com/) |
| **Open Source Contribution** | Capacidad de navegar codebases ajenas y seguir guías de contribución | Buscar issues `good first issue` en proyectos Go del stack (`sqlc`, `pgx`) |

### Behavioral & Búsqueda Laboral Global (LatAm → USD)

- **Framework STAR en inglés:** Preparar y grabar 6 historias técnicas sólidas siguiendo *Situation, Task, Action, Result* (20% contexto, 10% rol, 60% acción técnica/decisiones/código, 10% resultado medible).
- **Recursos gratuitos de Silver.dev (Gabriel Benmergui):**
  - [LinkedIn y CV para startups globales](https://docs.silver.dev/interview-ready/consiguiendo-entrevistas/preparando-linkedin)
  - [Trabajando con recruiters y screenings](https://docs.silver.dev/interview-ready/recruiter-screening/trabajando-con-recruiters)
  - Behavioral questions y storytelling ([Parte I](https://docs.silver.dev/interview-ready/hiring-manager-screening/behavioral-preguntas-clasicas), [Parte II](https://docs.silver.dev/interview-ready/hiring-manager-screening/behavioral-storytelling), [Parte III](https://docs.silver.dev/interview-ready/hiring-manager-screening/behavioral-cultura-americana))
  - [Guía de take-homes de alto nivel](https://docs.silver.dev/interview-ready/takehomes/guia-de-takehomes)
  - [Estrategia de negociación salarial](https://docs.silver.dev/interview-ready/manejando-ofertas/negociando-salarios)
- **Simulacros y feedback:** Mocks P2P gratuitos en [Pramp](https://www.pramp.com/) / [Exponent](https://www.tryexponent.com/), y análisis de entrevistas reales en el [canal de interviewing.io](https://www.youtube.com/@interviewing_io).
- **Negociación salarial para primer empleo internacional en USD:** Patrick McKenzie (patio11) — ["Salary Negotiation"](https://www.kalzumeus.com/2012/01/23/salary-negotiation/) y [Podcast Ep. 12](https://www.kalzumeus.com/2016/06/03/kalzumeus-podcast-episode-12-salary-negotiation-with-josh-doody/). Reglas de oro: no dar números antes de investigar rangos de mercado en USD, negociar paquete completo, anclar en valor de mercado y pedir siempre 48 horas antes de aceptar una oferta.

### Proyecto principal — `capstone-backend`

Consolidación definitiva del backend: `taskapi` + `resilient-api` operando como un sistema modular cohesionado con métricas vivas, dashboards de Grafana preconfigurados, tracing distribuido Jaeger/OTel, CI/CD automatizado en GitHub Actions y suite de tests con cobertura de integración. Entregables: `README.md` estelar, `ARCHITECTURE.md`, `BENCHMARKS.md` (k6), `RUNBOOK.md`.

---

### Buffer Pre-Graduación y Búsqueda Laboral (30 ago – 15 dic 2027, ~15 semanas)

> **Propósito estratégico del colchón de 15 semanas:**
> 1. **Prioridad Universitaria:** Finalizar tesis de grado, proyectos de título y exámenes finales de Ingeniería en Informática con excelencia y sin riesgo de burnout ni fatiga acumulada.
> 2. **Búsqueda Laboral Activa:** Enviar postulaciones personalizadas a startups de EE.UU./Europa y empresas tecnológicas líderes para roles Go Backend Engineer Jr/Mid con salarios en USD.
> 3. **Procesos de Entrevista:** Atender screenings técnicos, pruebas take-home y entrevistas en vivo con la mente fresca y los proyectos listos para mostrar.
> 4. **Mantenimiento Técnico Ligero:** Rutina sostenible de 4-6 horas semanales: 1 kata de algoritmos por semana en Go y 1 simulacro técnico o lectura de paper cada 15 días.

---

# ETAPA 2 — Especializaciones Post-Graduación (2028+)

> **Estrategia Post-Graduación:** Estas especializaciones se abordan **después de titularse y mientras se trabaja como ingeniero**, o como pivot estratégico según oportunidades laborales reales o emprendimientos. No compiten con el foco de graduación ni saturan el tiempo universitario.

## ESPECIALIZACIÓN A — Data Engineering (Post-Graduación)

**Objetivo:** Extender las capacidades de backend hacia ingeniería de datos analíticos masivos, pipelines en tiempo real y arquitecturas de eventos.

### Python idiomático para backend/pipelines

El objetivo es Python de producción real (generators, context managers, type hints, testing, empaquetado) — no metaclasses ni internals del intérprete.

| Rol | Recurso | Confianza | Notas |
|---|---|---|---|
| Principal | [Practical Python Programming](https://dabeaz-course.github.io/practical-python/Notes/Contents.html) (David Beazley) | Alta | Gratis, CC-BY-SA-4.0. Foco en Secciones 2-4 y 6-7 |
| Referencia | [Documentación oficial de Python — tutorial](https://docs.python.org/3/tutorial/) | Alta | Functions, Modules, I/O, Errors and Exceptions, Classes, Virtual Environments |
| Referencia (complemento) | [`contextlib`](https://docs.python.org/3/library/contextlib.html), [`typing`](https://docs.python.org/3/library/typing.html), [`datetime`](https://docs.python.org/3/library/datetime.html) + [`zoneinfo`](https://docs.python.org/3/library/zoneinfo.html), [`asyncio`](https://docs.python.org/3/library/asyncio.html) | Alta | Context managers, `Protocol` (≈ interfaces de Go), fechas timezone-aware, async básico |
| Arquitectura/diseño | [Architecture Patterns with Python ("Cosmic Python")](https://www.cosmicpython.com/book/preface.html) | Alta | Versión web gratuita bajo CC. Repository Pattern y Unit of Work desde `interfaces` de Go |
| Testing | [pytest — documentación oficial](https://docs.pytest.org/en/stable/) | Alta | Fixtures, parametrización, `monkeypatch` |
| Empaquetado | [Python Packaging User Guide](https://packaging.python.org/) → luego [uv](https://docs.astral.sh/uv/) | Alta | `uv` es lo recomendado hoy sobre Poetry para proyectos nuevos |
| Proyecto de cierre | [Data Engineering Zoomcamp — Módulo 1](https://github.com/DataTalksClub/data-engineering-zoomcamp) | Alta | API pública → chunks con pandas/generators → Postgres en Docker |

**Ruta sugerida (5 semanas):**
1. Núcleo idiomático: Practical Python 2-4 + docs oficiales. Proyecto: lector de CSV/JSON con clases y type hints.
2. Generators y recursos: Practical Python sección 6 + `contextlib`. Proyecto: pipeline línea por línea sin cargar todo en memoria.
3. APIs y fechas: cliente HTTP con timeout/reintentos/paginación; `datetime`+`zoneinfo`. Proyecto: extraer de API pública y cargar en Postgres.
4. Testing y arquitectura: pytest + Cosmic Python caps. 1-2. Tests de integración contra Postgres en Docker.
5. Async y empaquetado: `asyncio` básico, migrar a `pyproject.toml`+`uv`. Cierre con Módulo 1 del Zoomcamp.

### Apache Kafka

| Rol | Recurso | Confianza | Notas |
|---|---|---|---|
| Principal (curso) | [Confluent Developer — Apache Kafka 101](https://developer.confluent.io/courses/apache-kafka/events/) + Kafka Streams 101 + ksqlDB 101 | Alta | Gratis para el contenido teórico; labs interactivos pueden empujar a Confluent Cloud — usar el Quickstart oficial para lo local |
| Apoyo (CLI, sin Java) | [Conduktor Kafkademy](https://www.conduktor.io/kafka/) | Media-alta | Ignorar la promoción de su herramienta comercial |
| Práctica local (oficial) | [Apache Kafka Quickstart](https://kafka.apache.org/quickstart/) | Alta | Kafka 4.x (oct 2024) eliminó ZooKeeper por completo — KRaft es el único modo soportado. Ignorar tutoriales con ZooKeeper aunque sean de 2023 |
| Referencia densa | [Kafka: The Definitive Guide, 2ª ed.](https://www.confluent.io/resources/ebook/kafka-the-definitive-guide/) | Media | Gratis vía formulario de Confluent. De 2021 — código en Java, mapear a `segmentio/kafka-go` o `confluent-kafka-go` |
| Referencia (sistemas) | [Documentación oficial — sección Design](https://kafka.apache.org/documentation/#design) | Alta | Log append-only, `sendfile` (zero-copy), page cache, particiones |
| Ensayo fundacional | Jay Kreps — ["The Log"](https://engineering.linkedin.com/distributed-systems/log-what-every-software-engineer-should-know-about-real-time-datas-unifying) (2013) | Alta | Del cocreador de Kafka. Lectura corta y muy citada |
| Práctica integrada | [Data Engineering Zoomcamp — módulo de Kafka](https://github.com/DataTalksClub/data-engineering-zoomcamp) | Alta | Producer/consumer, particionado, replicación, Kafka Streams, ksqlDB, Avro |

**Ruta sugerida (6 semanas):** modelo mental (Kafka 101 + "The Log") → producer/consumer → persistencia y garantías de entrega → integración (Connect, Schema Registry, Avro) → Go nativo (`segmentio/kafka-go`) → proyecto final con DLQ y Docker Compose.

### Analytics Engineering — dbt + DuckDB

| Rol | Recurso | Confianza | Notas |
|---|---|---|---|
| Principal | [Quickstart dbt Core v1 con DuckDB + Jaffle Shop](https://docs.getdbt.com/guides/duckdb) | Alta | Gratis, oficial, sin cuenta de warehouse cloud. Rama estable (preferir sobre "v2"/Fusion en alpha) |
| Práctica local | [jaffle_shop_duckdb](https://github.com/dbt-labs/jaffle_shop_duckdb) | Alta | Playground reutilizable |
| Adaptador (referencia) | [dbt-duckdb](https://github.com/duckdb/dbt-duckdb) | Alta | Apache-2.0. Leer desde S3/R2/Parquet vía `profiles.yml` |
| DuckDB — referencia | [DuckDB Guides](https://duckdb.org/docs/current/guides/overview) | Alta | CSV/JSON/Parquet, HTTP/S3, Postgres, API de Go |
| DuckDB — tutorial | ["Fully Local Data Transformation with dbt and DuckDB"](https://duckdb.org/2025/04/04/dbt-duckdb.html) | Media-alta | Modelo dimensional completo, materializations, reverse ETL — mejor como proyecto de semana 4-5 |
| Buenas prácticas | [dbt — How we style our dbt projects](https://docs.getdbt.com/best-practices/how-we-style/6-how-we-style-conclusion) | Alta | Estructura `staging/intermediate/marts` |
| Práctica integrada | [Data Engineering Zoomcamp — Analytics Engineering](https://github.com/DataTalksClub/data-engineering-zoomcamp) | Alta | Módulo 4 — usar como cierre integrador, no primer recurso |

**Ruta sugerida (5 semanas):** DuckDB básico → datos externos → dbt local → calidad y modelado (tests, seeds, macros, materializations) → proyecto de portfolio integrador.

### Arquitecturas de datos (Lambda / Kappa)

| Rol | Recurso | Confianza | Notas |
|---|---|---|---|
| Fuente primaria (Kappa) | Jay Kreps — ["Questioning the Lambda Architecture"](https://www.oreilly.com/radar/questioning-the-lambda-architecture/) (2014) | Alta | Propone Kappa: mantener dos bases de código (batch/stream) para la misma lógica es la falla que señala |
| Fuente primaria (base técnica) | Jay Kreps — ["The Log"](https://engineering.linkedin.com/distributed-systems/log-what-every-software-engineer-should-know-about-real-time-datas-unifying) (2013) | Alta | Por qué Kappa funciona: log inmutable + replay |
| Fuente primaria (Lambda) | Nathan Marz — post original ["How to beat the CAP theorem"](http://nathanmarz.com/blog/how-to-beat-the-cap-theorem.html) | Media | El libro _Big Data_ (Manning, 2015) es pago — el post gratis alcanza |
| Síntesis (Lambda) | Ericsson — [Lambda and Kappa](https://www.ericsson.com/en/blog/2015/11/data-processing-architectures--lambda-and-kappa) | Media | De 2015, patrón conceptual estable |
| Síntesis (Kappa) | Materialize — [Does Kappa architecture improve on Lambda?](https://materialize.com/blog/does-kappa-architecture-improve-on-lambda/) | Media | 2026, fuente con interés comercial en streaming |
| Práctica integrada | [Data Engineering Zoomcamp — Streaming](https://github.com/DataTalksClub/data-engineering-zoomcamp) | Alta | Da las piezas (Kafka, ventanas, Flink/PyFlink) para comparar ambas arquitecturas |
| Referencia (motor Kappa) | [Apache Flink — Concepts](https://nightlies.apache.org/flink/flink-docs-stable/docs/concepts/overview/) | Alta | Alcanza con los conceptos, no hace falta dominarlo |
| Complemento gratuito de streaming | Tyler Akidau — ["Streaming 101"](https://www.oreilly.com/radar/the-world-beyond-batch-streaming-101/) y ["Streaming 102"](https://www.oreilly.com/radar/streaming-102-the-world-beyond-batch/) | Alta | Watermarks, event time vs. processing time, windowing — la base gratuita del libro comercial _Streaming Systems_ |

### Proyecto de especialización — `eventpipe`

Pipeline de datos end-to-end: `taskapi` produce eventos → Kafka (`task.events`) → consumer en Python → PostgreSQL (`events_raw`) → dbt (staging → marts) → DuckDB (analytics) → endpoint `/analytics/summary`. Incluye prueba de idempotencia obligatoria (reset de offsets + reprocesamiento, el conteo final debe ser idéntico).

---

## ESPECIALIZACIÓN B — Cloud (AWS) & Kubernetes (Post-Graduación)

**Objetivo:** Operar el stack de backend en infraestructuras cloud administradas y comprender a fondo la orquestación distribuida con Kubernetes.

### Kubernetes (conceptual y bajo nivel)

| Rol | Recurso | Confianza | Notas |
|---|---|---|---|
| Principal — mecánica del sistema | [Kubernetes the Hard Way](https://github.com/kelseyhightower/kubernetes-the-hard-way) | Alta | Licencia Apache 2.0. 14 labs manuales (PKI/TLS, etcd HA, `systemd`, `containerd`). Adaptable a VMs locales |
| Apoyo — de proceso a Pod | Ian Lewis — ["What are Kubernetes Pods anyway?"](https://www.ianlewis.org/en/what-are-kubernetes-pods-anyway) (4 partes) | Alta | Construye un "Pod" a mano con `unshare(1)`/`setns(2)` |
| Apoyo — red a bajo nivel | Arthur Chiao — ["Kubernetes Networking: Behind the Scenes"](https://arthurchiao.art/blog/k8s-net-journey/) | Alta | Service/ClusterIP con iptables/IPVS y `veth` |
| Apoyo — control plane en Go | ["A Deep Dive into Kubernetes Controllers"](https://engineering.bitnami.com/articles/a-deep-dive-into-kubernetes-controllers.html) | Alta | Reflector/Informer/WorkQueue de `client-go` |
| Referencia formal | [Kubernetes Docs — Concepts/Architecture](https://kubernetes.io/docs/concepts/architecture/) | Alta | Oficial, CNCF |

**Ruta sugerida (4 semanas):** la unidad atómica (Ian Lewis) → el plano de control como sistema distribuido → red sin magia (Arthur Chiao) → anatomía de un clúster real (Kubernetes the Hard Way).

### Servicios Cloud AWS

**Núcleo universal:** IAM, EC2, S3, Lambda, VPC, CloudWatch.
**Backend & Contenedores:** ECS Fargate, EKS (Kubernetes administrado), RDS (PostgreSQL), API Gateway, Secrets Manager, CloudFront — deploy de `resilient-api`.
**Data Engineering Cloud:** S3 (data lake), Glue (ETL serverless), Athena (SQL sobre S3), Redshift, Kinesis Data Streams, MSK (Managed Kafka), Step Functions, EventBridge — variante AWS de `eventpipe`.
**IaC:** Terraform (cloud-agnostic) o AWS CDK/CloudFormation.

### Recursos de aprendizaje AWS

| Recurso | Tipo |
|---|---|
| [AWS Skill Builder](https://skillbuilder.aws) | Cursos oficiales gratuitos + labs |
| [AWS Ramp-Up Guide: Data Engineer](https://aws.amazon.com/training/ramp-up-guides/) | Ruta oficial |
| [freeCodeCamp — AWS Certified Cloud Practitioner](https://www.youtube.com/watch?v=NhDYbskXRgc) | Video 4h gratuito |
| [AWS Academy](https://aws.amazon.com/training/awsacademy/) | Vía universidad — Learner Lab + vouchers |

**Cuenta AWS:** créditos disponibles del curso de Admin de BD. Estrategia: free tier + budget alert en $5 + preferir servicios serverless.

### Certificaciones sugeridas

| Cert | Foco | Costo aprox. |
|---|---|---|
| CLF-C02 Cloud Practitioner | Fundamentos cloud | ~$100 USD |
| SAA-C03 Solutions Architect Associate | Arquitectura backend + deploy | ~$150 USD |
| DEA-C01 Data Engineer Associate | Data pipelines (S3/Glue/Athena/Redshift) | ~$150 USD |

Orden sugerido: CLF → SAA → DEA-C01. Vouchers: AWS Academy (universidad), AWS 16 Days of Cloud (~abril/noviembre), 50% off tras aprobar cualquier examen, AWS re/Start / AWS Educate.

**Proyecto de especialización — `cloud-deploy`:** Deploy de `resilient-api` a AWS ECS Fargate + RDS + Secrets Manager + CloudWatch, o clúster EKS administrado con Terraform.

---

## ESPECIALIZACIÓN C — Mobile Multiplataforma (KMP + Compose Multiplatform) (Post-Graduación)

**Objetivo:** Desarrollar clientes móviles modernos para Android e iOS compartiendo lógica de negocio en Kotlin y UI declarativa en Compose Multiplatform.

**Decisiones de diseño fijadas:** UI en Compose Multiplatform desde el día 1 (código UI ya iOS-ready); navegación multiplatform (Voyager o Decompose) en vez de Navigation-Compose; SQLDelight (no Room); Koin (no Kodein); target iOS y publishing diferidos hasta tener Mac/cuentas.

**Orden de aprendizaje:** Kotlin (corrutinas/Flow ≈ goroutines/channels de Go, null-safety, sealed classes, extension functions) → fundamentos de plataforma Android + Compose → núcleo KMP compartido (`expect`/`actual`, Ktor Client, SQLDelight, Koin) → estados de UI y Offline-First → proyecto `mobile-app`.

**Proyecto de especialización — `mobile-app`:** cliente multiplatform (Android primero, iOS al tener Mac) que consume `resilient-api`/`taskapi`. Auth JWT con refresh, dashboard reactivo con estados loading/empty/error, Offline-First (SQLite local vía SQLDelight, sync con Go + PostgreSQL al volver en línea), misma UI en Android e iOS desde un solo código Compose Multiplatform.

---

## El libro que amarra todo — DDIA

_Designing Data-Intensive Applications_ (Kleppmann). No se lee de corrido — se abre como referencia en el momento que corresponde:

| Capítulos | Fase / Especialización | Por qué en ese momento |
|---|---|---|
| Cap. 2 — Data Models | F2 (Go + Postgres) | Al diseñar el schema relacional de `taskapi` |
| Cap. 5 — Replication | F3 / F4 | Al escalar con réplicas de lectura y caching Redis |
| Cap. 7 — Transactions | F2 / F3 | Transacciones ACID y consistencia con PostgreSQL |
| Cap. 8 — The Trouble with Distributed Systems | F4 (System Design) | Clocks, partitions, split-brain, fallos parciales |
| Cap. 9 — Consistency and Consensus | F4 (System Design) | Linearizability, 2PC, Raft, Paxos en Gossip Glomers |
| Caps. 1, 3, 4, 6 | F4 (System Design) | Storage engines (LSM vs B-Tree), codificación (Protobuf), particionamiento |
| Cap. 10 — Batch Processing | Espec. A (Data Eng.) | MapReduce, procesamiento masivo por lotes |
| Cap. 11 — Stream Processing | Espec. A (Data Eng.) | Kafka internals, event time, stream joins |
| Cap. 12 — The Future of Data Systems | F4 / Espec. A | Unificación de sistemas derivados y arquitectura orientada a datos |

---

## Resumen de proyectos principales

### Etapa 1 — Pre-Graduación (Núcleo de Empleabilidad Backend Go)

| Fase | Proyecto | Stack | Qué demuestra |
|---|---|---|---|
| **F1** | `mysh` — Mini Shell UNIX | C, GCC, Make, POSIX | Procesos, memoria manual, syscalls, DSA aplicado |
| **F2** | `taskapi` — Production Backend | Go, PostgreSQL, pgx | Backend productivo, concurrencia, transaccionalidad, JWT |
| **F3** | `resilient-api` — API Distribuida | Go, Docker, Redis, OTel | Resiliencia (Circuit Breaker, Lua rate limit), observabilidad y CI/CD |
| **F4** | `architecture-docs` — Docs Técnicas | C4, ADRs, RFC, Post-mortem | Criterio de arquitectura, DDD táctico, diseño de sistemas |
| **F5** | `capstone-backend` — Backend Estrella | Go, PostgreSQL, Redis, OTel | Integración del portfolio, benchmarks medibles y calidad de producción |

### Etapa 2 — Post-Graduación (Especializaciones Profesionales)

| Especialización | Proyecto | Stack | Qué demuestra |
|---|---|---|---|
| **Espec. A** | `eventpipe` — Pipeline de Datos | Python, Kafka, dbt, DuckDB | Data Engineering end-to-end e idempotencia analítica |
| **Espec. B** | `cloud-deploy` — Infraestructura Cloud | AWS (ECS/EKS, RDS, S3), K8s, Terraform | Despliegue, IaC y orquestación cloud |
| **Espec. C** | `mobile-app` — Cliente Multiplataforma | Kotlin, Compose Multiplatform, KMP | Mobile cross-platform Offline-First sobre el backend propio |

---

## Stack completo

```
— ETAPA 1: NÚCLEO PRE-GRADUACIÓN (Backend & Sistemas) —
Sistemas y bajo nivel:     C (C11), GCC, Makefiles, Linux Internals, GDB, Valgrind, ASan, UBSan
Backend principal:         Go (APIs REST, concurrencia, microservicios, stdlib, pgx)
Bases de datos:            PostgreSQL (transaccional, optimización, EXPLAIN ANALYZE, aislamiento ACID)
Caché & Resiliencia:       Redis (Cache-Aside, Distributed Rate Limiting con Lua scripts, Circuit Breaker)
Contenerización & CI/CD:   Docker + Docker Compose + GitHub Actions
Observabilidad:            OpenTelemetry + Prometheus + Grafana (traces, métricas, logs JSON estructurados)
Arquitectura & Diseño:     Domain-Driven Design (táctico/estratégico), Clean/Hexagonal Architecture, System Design (CAP, replicación), GoF idiomático, C4, ADRs

— ETAPA 2: ESPECIALIZACIONES POST-GRADUACIÓN —
Data Engineering (A):      Python idiomático, Apache Kafka (KRaft), dbt Core, DuckDB, Lambda/Kappa
Cloud & K8s (B):           AWS (IAM, EC2, S3, RDS, ECS, EKS, CloudWatch), Kubernetes internals, Terraform
Mobile Multiplatform (C):  Kotlin, Compose Multiplatform, KMP (Ktor, SQLDelight, Koin)
```

---

## Perfil al egreso de Ingeniería (Diciembre 2027)

Al completar la Etapa 1 previo a la titulación universitaria:
- **Bajo nivel:** Entiende qué hace el kernel cuando llama a `fork()` o crea un thread y puede explicarlo con rigor.
- **Backend de alto rendimiento:** Construye APIs en Go que soportan alta carga porque domina la concurrencia nativa (goroutines, channels, sync primitives) y el pool de conexiones.
- **Bases de datos profundas:** Optimiza consultas en PostgreSQL entendiendo cómo el motor ejecuta `Seq Scan`, `Index Scan` y joins sin depender de abstracciones mágicas.
- **Resiliencia en producción:** Diseña servicios que toleran caídas parciales mediante Circuit Breakers, timeouts y rate limiting distribuido.
- **Observabilidad real:** Diagnostica anomalías en producción analizando traces distribuidos, métricas en Grafana y logs correlacionados por `request_id`.
- **Criterio arquitectónico:** Puede defender decisiones técnicas con diagramas C4 y ADRs formales, articulando trade-offs con vocabulario de nivel senior.

---

## Notas de investigación

- **Removidos/reemplazados durante la verificación con SOURCES.md:** SQLShed (dbt/DuckDB, no corroborado), `runbook.academy` y `systeminternals.dev` (Kubernetes, no corroborados), el libro _Streaming Systems_ como recurso gratuito (es pago — reemplazado por los ensayos gratis de Akidau), _Fluent Python_ como lectura obligatoria (ya no aplica al alcance idiomático), AlgoMaster.io (nunca verificado, se sacó del documento), nombre "RU101" de Redis University (desactualizado), tutoriales de Kafka con ZooKeeper (desactualizados desde Kafka 4.x), OpenTracing/`jaeger-client-go` (obsoletos), la URL "threedots.labs" (no existe, es threedots.tech), la licencia CC BY-NC-SA atribuida a _Kubernetes the Hard Way_ (es Apache 2.0), y el libro _Big Data_ de Nathan Marz como "gratis" (es pago).
- **Fuera de scope de este roadmap:** RAG/Embeddings — se cubre en el roadmap paralelo de AI Engineering.
- **No verificado por SOURCES.md, se mantiene sin marca especial de riesgo por tratarse de referencias muy conocidas y de bajo riesgo de identidad/licencia:** DDIA (Kleppmann), AWS (Especialización B), Mobile/KMP (Especialización C), canales de YouTube complementarios (Fiset, Stoney codes, Anthony GG, TechWorld with Nana), OSS good-first-issue y distribución de LeetCode.
