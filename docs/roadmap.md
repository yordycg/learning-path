# Roadmap — Backend & Data Engineer

> **Ingeniería en Informática 3er año → Junior Backend/Data Engineer Ruta principal:** 18 meses (F1–F6). Extensiones diferidas sin fecha fija: F7 (Cloud/AWS) y F8 (Mobile).

> **Stack:** Linux (Arch/Fedora), C, Go, Python, PostgreSQL, Docker, Kafka, dbt/DuckDB.

> **Fuentes de este documento:** estructura y fases del roadmap original + recursos
> verificados en `SOURCES.md` (metodología: 2 IAs con búsqueda web + comparación cruzada +
> verificación propia). Donde SOURCES.md investigó un tema, sus recursos reemplazan a los
> originales. Donde no lo investigó, se mantienen los recursos originales sin marca especial
> salvo que se indique lo contrario.

---

## Resumen de fases

| Fase   | Período                     | Foco                                                                       |
| ------ | --------------------------- | -------------------------------------------------------------------------- |
| F1     | 14 jun – 1 nov 2026         | Linux Internals, C & DSA base                                              |
| F2     | 2 nov – 27 dic 2026         | Go + Python base + PostgreSQL + Seguridad                                  |
| F3     | 28 dic 2026 – 21 feb 2027   | Sistemas Distribuidos + Docker + Redis + Observabilidad + CI/CD            |
| F4     | 22 feb – 30 may 2027        | Data Engineering + Python idiomático                                       |
| F5     | 31 may – 29 ago 2027        | System Design, Arquitectura, Patrones de Diseño & DDD      |
| F6     | 30 ago – 28 nov 2027        | Portfolio (Backend + Data Engineering) & Job Hunt          |
| **F7** | **Diferida, post-18 meses** | **Cloud (AWS)** — aplicar el stack ya construido a servicios administrados |
| **F8** | **Diferida, después de F7** | **Mobile multiplataforma** (Kotlin + Compose Multiplatform / KMP)          |

**Disciplinas que atraviesan varias fases:**

- **DSA:** F1 (arrays, punteros, linked lists, hash tables en C) → F2 (árboles, sorting, sliding window en Go) → F3 (grafos, consistent hashing) → F6 (repaso de entrevista).
- **Seguridad:** F2 (OWASP, JWT, secrets).
- **Arquitectura & Patrones:** F2 (Repository) → F3 (Circuit Breaker, Retry, Cache-aside) → F4 (Lambda/Kappa) → F5 (Nivel 0 DDD, Nivel 1 System Design, Nivel 2 Arq. Hexagonal/CQRS, Nivel 3 Patrones GoF en Python y Go).
- **Comunicación técnica:** F5 (ADRs, RFCs, post-mortems, C4).

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

## FASE 2 — Go + Python Base + PostgreSQL + Seguridad

**Período:** 2 nov – 27 dic 2026

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

CRUD de tasks/usuarios con schema modelado (ER diagram primero), JWT propio (sin librerías de auth), bcrypt, rate limiting con goroutines/channels, índices parciales, transacciones multi-step, `pgxpool`, `sqlx` (cero ORMs), tests con mocking vía interfaces, script Python para poblar la DB y parsear logs.

---

## FASE 3 — Sistemas Distribuidos + Docker + Redis + Observabilidad + CI/CD

**Período:** 28 dic 2026 – 21 feb 2027

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

## FASE 4 — Data Engineering + Python Idiomático

**Período:** 22 feb – 30 may 2027

### Python idiomático para backend/pipelines

El objetivo es Python de producción real (generators, context managers, type hints, testing, empaquetado) — no metaclasses ni internals del intérprete.

| Rol                      | Recurso                                                                                                              | Confianza | Notas                                                                                    |
| ------------------------ | -------------------------------------------------------------------------------------------------------------------- | --------- | ---------------------------------------------------------------------------------------- |
| Principal                | [Practical Python Programming](https://dabeaz-course.github.io/practical-python/Notes/Contents.html) (David Beazley) | Alta      | Gratis, CC-BY-SA-4.0. Foco en Secciones 2-4 y 6-7                                        |
| Referencia               | [Documentación oficial de Python — tutorial](https://docs.python.org/3/tutorial/)                                    | Alta      | Functions, Modules, I/O, Errors and Exceptions, Classes, Virtual Environments            |
| Referencia (complemento) | [`contextlib`](https://docs.python.org/3/library/contextlib.html), [`typing`](https://docs.python.org/3/library/typing.html), [`datetime`](https://docs.python.org/3/library/datetime.html) + [`zoneinfo`](https://docs.python.org/3/library/zoneinfo.html), [`asyncio`](https://docs.python.org/3/library/asyncio.html) | Alta | Context managers, `Protocol` (≈ interfaces de Go), fechas timezone-aware, async básico |
| Arquitectura/diseño      | [Architecture Patterns with Python ("Cosmic Python")](https://www.cosmicpython.com/book/preface.html)                | Alta      | Versión web gratuita bajo CC. Repository Pattern y Unit of Work desde `interfaces` de Go |
| Testing                  | [pytest — documentación oficial](https://docs.pytest.org/en/stable/)                                                 | Alta      | Fixtures, parametrización, `monkeypatch`                                                 |
| Empaquetado              | [Python Packaging User Guide](https://packaging.python.org/) → luego [uv](https://docs.astral.sh/uv/)                | Alta      | `uv` es lo recomendado hoy sobre Poetry para proyectos nuevos                            |
| Proyecto de cierre       | [Data Engineering Zoomcamp — Módulo 1](https://github.com/DataTalksClub/data-engineering-zoomcamp)                   | Alta      | API pública → chunks con pandas/generators → Postgres en Docker                          |

**Ruta sugerida (5 semanas):**

1. Núcleo idiomático: Practical Python 2-4 + docs oficiales. Proyecto: lector de CSV/JSON con clases y type hints.
2. Generators y recursos: Practical Python sección 6 + `contextlib`. Proyecto: pipeline línea por línea sin cargar todo en memoria.
3. APIs y fechas: cliente HTTP con timeout/reintentos/paginación; `datetime`+`zoneinfo`. Proyecto: extraer de API pública y cargar en Postgres.
4. Testing y arquitectura: pytest + Cosmic Python caps. 1-2. Tests de integración contra Postgres en Docker.
5. Async y empaquetado: `asyncio` básico, migrar a `pyproject.toml`+`uv`. Cierre con Módulo 1 del Zoomcamp.

### Apache Kafka

| Rol                      | Recurso                                                                                                                                                          | Confianza  | Notas                                                                                                                                        |
| ------------------------ | ---------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------- | -------------------------------------------------------------------------------------------------------------------------------------------- |
| Principal (curso)        | [Confluent Developer — Apache Kafka 101](https://developer.confluent.io/courses/apache-kafka/events/) + Kafka Streams 101 + ksqlDB 101                           | Alta       | Gratis para el contenido teórico; labs interactivos pueden empujar a Confluent Cloud — usar el Quickstart oficial para lo local              |
| Apoyo (CLI, sin Java)    | [Conduktor Kafkademy](https://www.conduktor.io/kafka/)                                                                                                           | Media-alta | Ignorar la promoción de su herramienta comercial                                                                                             |
| Práctica local (oficial) | [Apache Kafka Quickstart](https://kafka.apache.org/quickstart/)                                                                                                  | Alta       | Kafka 4.x (oct 2024) eliminó ZooKeeper por completo — KRaft es el único modo soportado. Ignorar tutoriales con ZooKeeper aunque sean de 2023 |
| Referencia densa         | [Kafka: The Definitive Guide, 2ª ed.](https://www.confluent.io/resources/ebook/kafka-the-definitive-guide/)                                                      | Media      | Gratis vía formulario de Confluent. De 2021 — código en Java, mapear a `segmentio/kafka-go` o `confluent-kafka-go`                           |
| Referencia (sistemas)    | [Documentación oficial — sección Design](https://kafka.apache.org/documentation/#design)                                                                         | Alta       | Log append-only, `sendfile` (zero-copy), page cache, particiones                                                                             |
| Ensayo fundacional       | Jay Kreps — ["The Log"](https://engineering.linkedin.com/distributed-systems/log-what-every-software-engineer-should-know-about-real-time-datas-unifying) (2013) | Alta       | Del cocreador de Kafka. Lectura corta y muy citada                                                                                           |
| Práctica integrada       | [Data Engineering Zoomcamp — módulo de Kafka](https://github.com/DataTalksClub/data-engineering-zoomcamp)                                                        | Alta       | Producer/consumer, particionado, replicación, Kafka Streams, ksqlDB, Avro                                                                    |

**Ruta sugerida (6 semanas):** modelo mental (Kafka 101 + "The Log") → producer/consumer → persistencia y garantías de entrega → integración (Connect, Schema Registry, Avro) → Go nativo (`segmentio/kafka-go`) → proyecto final con DLQ y Docker Compose.

### Analytics Engineering — dbt + DuckDB

| Rol                    | Recurso                                                                                                              | Confianza  | Notas                                                                                              |
| ---------------------- | -------------------------------------------------------------------------------------------------------------------- | ---------- | -------------------------------------------------------------------------------------------------- |
| Principal              | [Quickstart dbt Core v1 con DuckDB + Jaffle Shop](https://docs.getdbt.com/guides/duckdb)                             | Alta       | Gratis, oficial, sin cuenta de warehouse cloud. Rama estable (preferir sobre "v2"/Fusion en alpha) |
| Práctica local         | [jaffle_shop_duckdb](https://github.com/dbt-labs/jaffle_shop_duckdb)                                                 | Alta       | Playground reutilizable                                                                            |
| Adaptador (referencia) | [dbt-duckdb](https://github.com/duckdb/dbt-duckdb)                                                                   | Alta       | Apache-2.0. Leer desde S3/R2/Parquet vía `profiles.yml`                                            |
| DuckDB — referencia    | [DuckDB Guides](https://duckdb.org/docs/current/guides/overview)                                                     | Alta       | CSV/JSON/Parquet, HTTP/S3, Postgres, API de Go                                                     |
| DuckDB — tutorial      | ["Fully Local Data Transformation with dbt and DuckDB"](https://duckdb.org/2025/04/04/dbt-duckdb.html)               | Media-alta | Modelo dimensional completo, materializations, reverse ETL — mejor como proyecto de semana 4-5     |
| Buenas prácticas       | [dbt — How we style our dbt projects](https://docs.getdbt.com/best-practices/how-we-style/6-how-we-style-conclusion) | Alta       | Estructura `staging/intermediate/marts`                                                            |
| Práctica integrada     | [Data Engineering Zoomcamp — Analytics Engineering](https://github.com/DataTalksClub/data-engineering-zoomcamp)      | Alta       | Módulo 4 — usar como cierre integrador, no primer recurso                                          |

**Ruta sugerida (5 semanas):** DuckDB básico → datos externos → dbt local → calidad y modelado (tests, seeds, macros, materializations) → proyecto de portfolio integrador.

### Arquitecturas de datos (Lambda / Kappa)

| Rol                               | Recurso                                                                                                                             | Confianza | Notas                                                                                                            |
| --------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------- | --------- | ---------------------------------------------------------------------------------------------------------------- |
| Fuente primaria (Kappa)           | Jay Kreps — ["Questioning the Lambda Architecture"](https://www.oreilly.com/radar/questioning-the-lambda-architecture/) (2014)      | Alta      | Propone Kappa: mantener dos bases de código (batch/stream) para la misma lógica es la falla que señala           |
| Fuente primaria (base técnica)    | Jay Kreps — ["The Log"](https://engineering.linkedin.com/distributed-systems/log-what-every-software-engineer-should-know-about-real-time-datas-unifying) (2013) | Alta | Por qué Kappa funciona: log inmutable + replay |
| Fuente primaria (Lambda)          | Nathan Marz — post original ["How to beat the CAP theorem"](http://nathanmarz.com/blog/how-to-beat-the-cap-theorem.html)            | Media     | El libro _Big Data_ (Manning, 2015) es pago — el post gratis alcanza                                             |
| Síntesis (Lambda)                 | Ericsson — [Lambda and Kappa](https://www.ericsson.com/en/blog/2015/11/data-processing-architectures--lambda-and-kappa)             | Media     | De 2015, patrón conceptual estable                                                                               |
| Síntesis (Kappa)                  | Materialize — [Does Kappa architecture improve on Lambda?](https://materialize.com/blog/does-kappa-architecture-improve-on-lambda/) | Media     | 2026, fuente con interés comercial en streaming                                                                  |
| Práctica integrada                | [Data Engineering Zoomcamp — Streaming](https://github.com/DataTalksClub/data-engineering-zoomcamp)                                 | Alta      | Da las piezas (Kafka, ventanas, Flink/PyFlink) para comparar ambas arquitecturas                                 |
| Referencia (motor Kappa)          | [Apache Flink — Concepts](https://nightlies.apache.org/flink/flink-docs-stable/docs/concepts/overview/)                             | Alta      | Alcanza con los conceptos, no hace falta dominarlo                                                               |
| Complemento gratuito de streaming | Tyler Akidau — ["Streaming 101"](https://www.oreilly.com/radar/the-world-beyond-batch-streaming-101/) y ["Streaming 102"](https://www.oreilly.com/radar/streaming-102-the-world-beyond-batch/) | Alta | Watermarks, event time vs. processing time, windowing — la base gratuita del libro comercial _Streaming Systems_ |

Nota: es el tema más teórico de F4 — el objetivo es razonar sobre trade-offs, no construir algo desde cero. Se convierte más adelante en un write-up técnico (ver F6).

### Proyecto principal — `eventpipe`

Pipeline de datos end-to-end: `taskapi` produce eventos → Kafka (`task.events`) → consumer en Python → PostgreSQL (`events_raw`) → dbt (staging → marts) → DuckDB (analytics) → endpoint `/analytics/summary`. Incluye prueba de idempotencia obligatoria (reset de offsets + reprocesamiento, el conteo final debe ser idéntico).

---

## FASE 5 — System Design, Arquitectura de Software, Patrones de Diseño & DDD

**Período:** 31 may – 29 ago 2027

> **Reordenada según un mapa de 4 niveles**, de negocio a código, en vez de agrupar todo
> por "temas sueltos". Cada nivel responde una pregunta distinta y se apoya en el anterior:
>
> - **Nivel 0 — DDD (el negocio):** ¿cómo dividimos el problema en áreas de responsabilidad
>   (Bounded Contexts) y cómo modelamos las reglas del negocio?
> - **Nivel 1 — System Design (la infraestructura):** ¿cómo comunican esos contextos entre
>   sí a gran escala (colas, RPC, bases de datos distribuidas, consenso)?
> - **Nivel 2 — Patrones de Arquitectura (la estructura del servicio):** ¿cómo aislamos el
>   dominio, dentro de cada servicio, de agentes externos como la base de datos o el
>   framework (Hexagonal/Clean Architecture)?
> - **Nivel 3 — Patrones de Diseño (el código):** ¿cómo escribimos las clases/funciones
>   dentro del dominio para que colaboren bien (Strategy, Factory, Decorator, State...)?
>
> El Nivel 3 (catálogo GoF) había quedado descartado en una versión anterior de este
> documento con el argumento de que "en Go pesa menos que en Java/C#". Eso mezclaba dos
> cosas distintas: el catálogo de patrones es un tema en sí mismo (aparece en cualquier
> entrevista, libro o codebase, sea cual sea el lenguaje); Go simplemente lo implementa
> distinto en algunos casos. Se restituye como sección propia — ver Nivel 3 abajo.
>
> **Nota de lenguaje:** Niveles 0-2 se trabajan en Go, como el resto del roadmap. El
> **Nivel 3 se aprende primero en Python**, no en Go — el catálogo GoF asume herencia,
> clases abstractas e interfaces explícitas, algo que Go no tiene; aprenderlo directo en Go
> significa verlo ya "disuelto" antes de entender la forma canónica que después te van a
> preguntar en una entrevista o vas a leer en cualquier libro. Python ya lo conocés de F4,
> así que no es un lenguaje nuevo — solo se usa para este nivel específico.

### Nivel 0 — Domain-Driven Design (el negocio)

| Rol | Recurso | Confianza | Notas |
|-----|---------|-----------|-------|
| Principal — táctico en Go | [DDD Lite / Three Dots Labs](https://threedots.tech/) — series `ddd-lite-in-go`, `repository-pattern-in-go`, `basic-cqrs-in-go` | Alta | Refactors reales de modelo anémico a modelo rico |
| Principal — estratégico | [DDD-Crew — Bounded Context Canvas](https://github.com/ddd-crew/bounded-context-canvas) + [Context Mapping](https://github.com/ddd-crew/context-mapping) | Alta | Plantillas abiertas, adoptadas en DDD Europe/GOTO |
| Referencia — filosofía | ["The First 15 Years"](https://leanpub.com/ddd_first_15_years) (Leanpub) | Alta | Gratis ($0.00). Ensayos de Fowler, Coplien, Khononov, Brandolini |
| Referencia extra | ["The Anatomy of DDD"](https://leanpub.com/theanatomyofdomain-drivendesign) y ["DDD Referenz"](https://leanpub.com/ddd-referenz) (Eric Evans) | Alta | Ambos gratis (pay-what-you-want) |
| Apoyo — modelado con código | [DDD by Examples: Library](https://github.com/ddd-by-examples/library) | Media-alta | Java/Spring, pero diagramas/Context Maps son agnósticos |
| Apoyo — package layout | Ben Johnson — ["Standard Package Layout"](https://medium.com/@benbjohnson/standard-package-layout-7cd488332d16) | Alta | Citado en la wiki oficial de Go |
| Índice adicional | [DDD-Crew — Free DDD Learning Resources](https://github.com/ddd-crew/free-ddd-learning-resources) | Alta | Colección curada oficial |

**Mapeo DDD → Go:**

| Concepto DDD | Equivalente en Go |
|---|---|
| Value Object | Struct inmutable por convención, igualdad por comparación de campos |
| Entity | Struct con ID explícito e inmutable |
| Aggregate Root | Struct con campos no exportados, mutación solo vía métodos |
| Domain Event | Struct con timestamp+payload, se despacha tras persistir (Outbox) |
| Repository | `interface` definida en el dominio, no en el productor |
| Anti-Corruption Layer | Paquete adaptador con función traductora pura |

**Ruta sugerida (5-6 semanas):** estratégico/Bounded Contexts → Value Objects/Entidades → Agregados → Repositorios/UoW/ACL → Domain Events y Outbox hacia Kafka.

### Nivel 1 — System Design (la infraestructura)

| Rol | Recurso | Confianza | Notas |
|-----|---------|-----------|-------|
| Principal — práctica dura | [MIT 6.5840 (Distributed Systems)](https://pdos.csail.mit.edu/6.824/) | Alta | Labs 100% en Go (MapReduce, Raft, KV tolerante a fallos, sharded KV). Público, sin paywall |
| Principal — retos con validación | [Fly.io Distributed Systems Challenges (Gossip Glomers)](https://fly.io/dist-sys/) | Alta | 6 retos con validación automática (Maelstrom). SDK nativo en Go. Requiere JDK |
| Apoyo — vocabulario/entrevista | [System Design Primer](https://github.com/donnemartin/system-design-primer) | Alta | Compendio + casos resueltos + flashcards Anki |
| Apoyo — patrones internos | [Catalog of Patterns of Distributed Systems](https://martinfowler.com/articles/patterns-of-distributed-systems/) | Alta | Cómo están hechos por dentro Kafka, Cassandra, etcd |
| Referencia — operación real | [Google SRE Book](https://sre.google/sre-book/) | Alta | SLOs, error budgets, monitoring |
| Referencia — papers fundacionales | [Dynamo](https://www.allthingsdistributed.com/files/amazon-dynamo-sosp2007.pdf), [GFS](https://static.googleusercontent.com/media/research.google.com/en//archive/gfs-sosp2003.pdf), [Bigtable](https://static.googleusercontent.com/media/research.google.com/en//archive/bigtable-osdi06.pdf) (originales, libres) | Alta | Origen real de los patrones enseñados en todos los cursos |
| Preparación de entrevista | [ByteByteGo](https://www.youtube.com/@ByteByteGo), [Arpit Bhayani](https://www.youtube.com/channel/UC_b1GUJv_2QiMP4BxC9-Dxg), *System Design Interview Vol. 1 & 2* (Alex Xu), [Silver.dev — System Design Meta](https://docs.silver.dev/interview-ready/system-design-interviews/system-design-meta) (en español), [HelloInterview](https://www.hellointerview.com/) | — | Complementario a la profundidad técnica de arriba |

**Ruta sugerida (10-12 semanas):** fundamentos/estimaciones (System Design Primer) → consistencia/replicación (Fly.io retos 1-4) → mensajería/consenso (Fly.io retos 5-6 o MIT Labs 1-2) → APIs robustas a escala → simulacros cronometrados.

### Nivel 2 — Patrones de Arquitectura (la estructura del servicio)

Cómo aislar el dominio, dentro de un mismo servicio, de la base de datos y el framework.

| Rol | Recurso | Confianza | Notas |
|-----|---------|-----------|-------|
| Principal — código real en Go | [Wild Workouts (Three Dots Labs)](https://github.com/ThreeDotsLabs/wild-workouts-go-ddd-example) | Alta | Refactorización progresiva a Clean Architecture + CQRS. Correrlo local exige Docker |
| Apoyo — estructura comparada | [go-structure-examples](https://github.com/katzien/go-structure-examples) (Kat Zien) | Alta | Mismo servicio bajo 4 filosofías (flat, layered, hexagonal, domain-driven). De 2018-19, sin actualizaciones |
| Apoyo — EDA/CQRS conceptual | Martin Fowler — ["What do you mean by Event-Driven?"](https://martinfowler.com/articles/201701-event-driven.html) | Alta | Antídoto contra usar CQRS/Event Sourcing por defecto |
| Referencia — patrones cloud | [Azure Architecture Center — Patterns](https://learn.microsoft.com/en-us/azure/architecture/patterns/) | Alta | CQRS, Event Sourcing, Compensating Transaction, Throttling |
| Referencia — monolito modular | [Modular Monolith with DDD](https://github.com/kamilgrzybek/modular-monolith-with-ddd) | Media-alta | C#/.NET, pero Outbox pattern mapea a Postgres/Go |
| Referencia — diseño de APIs | [Microsoft REST API Guidelines](https://github.com/microsoft/api-guidelines) + [Google API Design Guide](https://cloud.google.com/apis/design) | Alta | Usar como checklist, no dogma |

**Ruta sugerida (6-8 semanas):** Hexagonal/Clean Architecture → monolito modular vs. microservicios → Event-Driven/CQRS/Event Sourcing → diseño de APIs y contratos.

### Nivel 3 — Patrones de Diseño (el código)

El catálogo clásico "Gang of Four" (Creacionales, Estructurales, De Comportamiento): Factory, Builder, Singleton, Adapter, Decorator, Facade, Strategy, Observer, State, Command, etc.

> **Lenguaje: Python, no Go.** El catálogo GoF asume OOP clásica completa (herencia,
> clases abstractas, interfaces explícitas, visibilidad). El estándar de facto para
> *aprenderlo por primera vez* es Java/C#; Python es la alternativa reconocida cuando no
> se quiere sumar un lenguaje nuevo solo para esto (hay literatura seria que enseña los
> patrones en Java+Python+TypeScript en paralelo). Go, en cambio, no es un buen primer
> lenguaje para este catálogo: al no tener herencia ni interfaces explícitas, varios
> patrones (Builder, Singleton, parte de Factory) se disuelven o cambian de forma antes de
> verse en su forma canónica — incluso el material oficial de Go sobre el tema asume que el
> lector ya conoce los patrones desde Java/C#/Python. Como ya tenés Python de F4 (clases,
> `abc.ABC`, `typing.Protocol`, `dataclasses`), no hace falta aprender un lenguaje nuevo:
> se escribe el patrón en su forma de libro en Python, y **después** se compara con su
> equivalente idiomático en Go (ver nota al final) — así se ve tanto el concepto puro como
> la simplificación real que ya usás en el día a día.

| Rol | Recurso | Confianza | Notas |
|-----|---------|-----------|-------|
| Principal — catálogo conceptual | [Refactoring.Guru — Design Patterns](https://refactoring.guru/design-patterns) | Alta | El catálogo web (los 23 patrones GoF, con intención, estructura y pros/contras de cada uno) es gratis para leer online. El "ebook" descargable es un producto pago aparte — no hace falta comprarlo |
| Principal — código en Python | [RefactoringGuru/design-patterns-python](https://github.com/RefactoringGuru/design-patterns-python) | Alta | Repo oficial del mismo proyecto: los 23 patrones GoF en Python 3.7+, con ejemplo "Conceptual" (estructura pura) y "RealWorld" (aplicado) por cada uno |
| Referencia — catálogo extendido | [java-design-patterns.com](https://java-design-patterns.com/patterns) (iluwatar) | Media-alta | Va más allá de los 23 de GoF (incluye Circuit Breaker, CQRS, DAO — algunos ya vistos en Nivel 1-2). Código en Java, la referencia "de libro" si hace falta comparar contra el estándar más estricto |
| Referencia — texto original | *Design Patterns: Elements of Reusable Object-Oriented Software* (Gamma, Helm, Johnson, Vlissides — "GoF") | — | El libro que originó el catálogo. Es pago y los ejemplos son en C++/Smalltalk; Refactoring.Guru cubre el mismo contenido gratis y en Python — no es necesario comprarlo salvo interés histórico |

**De vuelta a Go — dónde el lenguaje simplifica el patrón clásico** (no reemplaza el concepto que ya viste en Python, cambia la implementación):
- **Strategy** → interfaces implícitas: cualquier struct que satisfaga una interfaz de un solo método ya es una estrategia intercambiable, sin jerarquía de clases.
- **Decorator** → middleware/embedding: `func(http.Handler) http.Handler`, o struct embedding para envolver una interfaz.
- **Builder** → Functional Options: `type Option func(*Server)` → `NewServer(addr, WithTimeout(5*time.Second))`.
- **Singleton** → generalmente se evita: en Go se prefiere inyectar la dependencia explícitamente (pasar el `*sql.DB` o el logger) en vez de un singleton global.

**Ruta sugerida (3-4 semanas):** Creacionales (Factory Method, Builder, Singleton) → Estructurales (Adapter, Decorator, Facade, Composite) → De Comportamiento (Strategy, Observer, State, Command, Template Method) — para cada uno: leer el catálogo, implementarlo en Python (ejemplo Conceptual + uno RealWorld propio), y recién después buscar el equivalente idiomático en Go y en el código que ya tenés (`http.Handler` ya es Decorator; `io.Reader`/`io.Writer` ya son Strategy).

### Kubernetes (conceptual)

| Rol | Recurso | Confianza | Notas |
|-----|---------|-----------|-------|
| Principal — mecánica del sistema | [Kubernetes the Hard Way](https://github.com/kelseyhightower/kubernetes-the-hard-way) | Alta | Licencia Apache 2.0. 14 labs manuales (PKI/TLS, etcd HA, `systemd`, `containerd`). Adaptable a VMs locales |
| Apoyo — de proceso a Pod | Ian Lewis — ["What are Kubernetes Pods anyway?"](https://www.ianlewis.org/en/what-are-kubernetes-pods-anyway) (4 partes) | Alta | Construye un "Pod" a mano con `unshare(1)`/`setns(2)` |
| Apoyo — red a bajo nivel | Arthur Chiao — ["Kubernetes Networking: Behind the Scenes"](https://arthurchiao.art/blog/k8s-net-journey/) | Alta | Service/ClusterIP con iptables/IPVS y `veth` |
| Apoyo — control plane en Go | ["A Deep Dive into Kubernetes Controllers"](https://engineering.bitnami.com/articles/a-deep-dive-into-kubernetes-controllers.html) | Alta | Reflector/Informer/WorkQueue de `client-go` |
| Referencia formal | [Kubernetes Docs — Concepts/Architecture](https://kubernetes.io/docs/concepts/architecture/) | Alta | Oficial, CNCF |

**Ruta sugerida (3-4 semanas):** la unidad atómica (Ian Lewis) → el plano de control como sistema distribuido → red sin magia (Arthur Chiao) → anatomía de un clúster real (Kubernetes the Hard Way).

### Proyecto principal — `architecture-docs`

C4 (Nivel 1 y 2) de `taskapi` y `eventpipe`, 4 ADRs reales, 1 RFC ("cómo agregaría full-text search a taskapi"), 1 post-mortem de un incidente real, 5 casos de System Design resueltos (método de 45 min), documento DDD de `taskapi` (bounded contexts, entities, aggregates), y 3-4 patrones de diseño implementados en Python (forma canónica) con nota de cuál sería su equivalente idiomático si se reescribieran en Go.

**Método de entrevista de System Design (45 min):** clarificar requerimientos (0-5) → estimación de capacidad (5-10) → diseño de alto nivel (10-25) → deep dive del componente crítico (25-35) → trade-offs (35-45).

---

## FASE 6 — Portfolio (Backend + Data Engineering) + Entrevistas

**Período:** 30 ago – 28 nov 2027

### Portfolio

**Regla central:** 2-3 proyectos de alta fidelidad, no 8-10 a medias.

**Filtro para decidir qué proyecto mostrar:**

1. ¿Se levanta con un solo comando? (`docker compose up -d` → sistema corriendo con métricas vivas en ~90s).
2. ¿Muestra qué pasa cuando algo falla? (DLQ, timeouts, circuit breaker — no solo el camino feliz).
3. ¿Hay un benchmark medible? ("throughput de 450 a 3,800 req/s con p99 bajo 25ms" vale más que "usé Redis para mejorar el rendimiento").

**Mapeo de proyectos a case studies:**

| Case study                                       | De qué sale                                          | Qué valida                                                                                         |
| ------------------------------------------------ | ---------------------------------------------------- | -------------------------------------------------------------------------------------------------- |
| Pipeline streaming (Backend/Distributed Systems) | Go + Postgres + Kafka de F2-F4                       | Concurrencia real, backpressure, garantías de entrega, resiliencia (retries, circuit breaker, DLQ) |
| Plataforma analítica (Data Engineering)          | dbt + DuckDB de F4                                   | Modelado dimensional, transformaciones idempotentes, tests de calidad, linaje                      |
| (Opcional) Systems/Distributed primitive         | Shell en C de F1, o mejor, Gossip Glomers/Raft de F5 | Diferencia real frente a otros candidatos                                                          |

**README que convierte:** título + problema en una línea → diagrama de arquitectura → stack → decisiones de diseño explicadas → métricas/resultados → cómo correrlo (3-4 comandos) → links.

**Qué hacer con el resto:** el shell en C no se descarta, se usa como contexto narrativo en la entrevista. El ejercicio comparativo Lambda vs. Kappa (F4) se convierte en un write-up técnico/ADR, no queda como código suelto. Observabilidad/CI-CD sueltos quedan como evidencia secundaria en el README de perfil.

### Entrevistas — contenido técnico Data/Backend

| Tema                           | Qué evalúan realmente                                                                                                            | Recurso                                                                  |
| ------------------------------ | -------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------ |
| SQL avanzado                   | Modelo mental del motor (`FROM→WHERE→GROUP BY→HAVING→SELECT→WINDOW→ORDER BY`), window functions, "Gaps and Islands", SARGability | [Use The Index, Luke!](https://use-the-index-luke.com)                   |
| Optimización / EXPLAIN ANALYZE | Seq Scan vs Index Scan vs Bitmap Index Scan, algoritmos de join                                                                  | Práctica con `EXPLAIN (ANALYZE, BUFFERS)` sobre dataset sintético grande |
| Diseño de pipelines            | Trade-offs batch vs. streaming justificados por SLA, datos sucios/duplicados                                                     | Conecta con Lambda/Kappa de F4                                           |
| Kafka en entrevista            | Orden a nivel de partición, rebalance, "effectively once"                                                                        | Conecta con Kafka de F4                                                  |
| dbt en entrevista              | `view`/`table`/`incremental`/`ephemeral`, "late arriving facts"                                                                  | Conecta con dbt+DuckDB de F4                                             |
| Práctica con problemas reales  | [StrataScratch](https://www.stratascratch.com/) (freemium, ~$30/mes), [DataDriven.io](https://datadriven.io/) (gratis, guía 8-10 semanas) | Confianza media |

### Behavioral

Framework **STAR** (Situation, Task, Action, Result), 20/10/60/10. Contar los proyectos de estudio como casos reales, con trade-offs de ingeniería explícitos ("hice un tutorial de Kafka" no sirve).

### Plataformas de preparación LatAm → EE.UU./Europa

**Silver.dev** — agencia LatAm↔startups EE.UU. fundada por Gabriel Benmergui (OpenSea, Robinhood, Scribd, CircleMedical). Recursos gratuitos en español: [LinkedIn/CV](https://docs.silver.dev/interview-ready/consiguiendo-entrevistas/preparando-linkedin), [recruiter screening](https://docs.silver.dev/interview-ready/recruiter-screening/trabajando-con-recruiters), behavioral ([I](https://docs.silver.dev/interview-ready/hiring-manager-screening/behavioral-preguntas-clasicas), [II](https://docs.silver.dev/interview-ready/hiring-manager-screening/behavioral-storytelling), [III](https://docs.silver.dev/interview-ready/hiring-manager-screening/behavioral-cultura-americana)), [negociación](https://docs.silver.dev/interview-ready/manejando-ofertas/negociando-salarios), [takehomes](https://docs.silver.dev/interview-ready/takehomes/guia-de-takehomes). El curso pago "Interview Ready" no está verificado en precio/contenido — probar primero el canal gratuito.

**Otras plataformas:** [DataDriven.io](https://datadriven.io/) (gratis); [Pramp](https://www.pramp.com/) / [Exponent](https://www.tryexponent.com/) free tier (mocks P2P gratis); [interviewing.io](https://interviewing.io/) (mocks pagos $150-250/sesión, pero su [canal de YouTube gratis](https://www.youtube.com/@interviewing_io) es de alto valor); [DataExpert.io](https://www.dataexpert.io/) (blog de behavioral gratis).

### Negociación salarial sin historial previo en USD

Fuente: Patrick McKenzie (patio11) — ["Salary Negotiation"](https://www.kalzumeus.com/2012/01/23/salary-negotiation/) y ["Kalzumeus Podcast Ep. 12"](https://www.kalzumeus.com/2016/06/03/kalzumeus-podcast-episode-12-salary-negotiation-with-josh-doody/).

Principios: nunca dar un número primero (anclar con investigación de mercado, no con salario previo en moneda local); definir 3 números antes de negociar (aspiracional, target, mínimo); negociar por valor de mercado, no por costo de vida; negociar el total comp; nunca aceptar en la llamada — pedir 48hs.

**Ruta sugerida (8 semanas):** SQL avanzado + `EXPLAIN` → arquitectura de pipelines documentada → behavioral en inglés (historias STAR grabadas) → simulacros y prospección activa.

### Proyecto principal — `capstone`

Sistema integrado: `taskapi v3` → eventos a Kafka → consumer Python → PostgreSQL → dbt (staging → marts) → DuckDB → endpoint `/analytics/summary`. Observabilidad completa, CI/CD, `docker compose up`. Entregables: `README.md`, `ARCHITECTURE.md`, `BENCHMARKS.md`, `RUNBOOK.md`.

### Open Source y repaso de entrevista técnica

Buscar `label:"good first issue"` en Go/Python. Proyectos relevantes al stack: `sqlc`, `dbt-core`, `pgx`, `polars`. Distribución sugerida de ~80 problemas de práctica: SQL medium (25), arrays/hashmaps en Go (30), strings en Go (15), árboles básicos (10) — no hace falta dynamic programming avanzado para roles Backend/Data Jr.

---

## FASE 7 — Cloud (AWS)

**Período:** diferida, después de F6, sin fecha fija.
**Núcleo:** aplicar el stack ya construido (PostgreSQL, Redis, Kafka, dbt, Docker) a servicios administrados de AWS — el mercado LatAm lo pide casi siempre.

> Esta fase todavía no pasó por el proceso de verificación de `SOURCES.md`. El contenido de
> abajo es el que traía el roadmap original, sin corroborar vigencia de nombres de
> servicios, precios de certificación ni condiciones de los programas de descuento.

### Servicios a aprender

**Núcleo universal:** IAM, EC2, S3, Lambda, VPC, CloudWatch.
**Backend:** ECS/EKS, RDS (PostgreSQL), API Gateway, Secrets Manager, CloudFront — deploy de `resilient-api`.
**Data Engineering:** S3 (data lake), Glue (ETL serverless), Athena (SQL sobre S3), Redshift, Kinesis Data Streams, MSK, Step Functions, EventBridge — variante AWS de `eventpipe`.
**IaC:** Terraform (cloud-agnostic) o CloudFormation/CDK.

### Recursos de aprendizaje

| Recurso                                                                                        | Tipo                                     |
| ---------------------------------------------------------------------------------------------- | ---------------------------------------- |
| [AWS Skill Builder](https://skillbuilder.aws)                                                  | Cursos oficiales gratuitos + labs        |
| [AWS Ramp-Up Guide: Data Engineer](https://aws.amazon.com/training/ramp-up-guides/)            | Ruta oficial                             |
| [freeCodeCamp — AWS Certified Cloud Practitioner](https://www.youtube.com/watch?v=NhDYbskXRgc) | Video 4h gratuito                        |
| [AWS Academy](https://aws.amazon.com/training/awsacademy/)                                     | Vía universidad — Learner Lab + vouchers |

**Cuenta AWS:** créditos disponibles del curso de Admin de BD. Estrategia: free tier + budget alert en $5 + preferir servicios serverless.

### Certificaciones

| Cert                                  | Foco                                     | Costo aprox. |
| ------------------------------------- | ---------------------------------------- | ------------ |
| CLF-C02 Cloud Practitioner            | Fundamentos cloud                        | ~$100 USD    |
| SAA-C03 Solutions Architect Associate | Arquitectura backend + deploy            | ~$150 USD    |
| DEA-C01 Data Engineer Associate       | Data pipelines (S3/Glue/Athena/Redshift) | ~$150 USD    |

Orden sugerido: CLF → SAA → DEA-C01. Vouchers: AWS Academy (universidad), AWS 16 Days of Cloud (~abril/noviembre), 50% off tras aprobar cualquier examen, AWS re/Start / AWS Educate.

**Proyectos a extender con esta fase:** deploy de `resilient-api` a ECS Fargate + RDS + Secrets Manager + CloudWatch; variante AWS de `eventpipe` (S3 + Glue + Athena, Kinesis o MSK); `capstone` corriendo en la nube como demo final de empleabilidad.

---

## FASE 8 — Mobile Multiplataforma (KMP + Compose Multiplatform)

**Período:** diferida, después de F7, sin fecha fija.
**Núcleo:** Kotlin y Compose Multiplatform como cliente del propio stack backend.

> Esta fase tampoco pasó por el proceso de verificación de `SOURCES.md` (Kotlin, Compose
> Multiplatform, KMP, Ktor, SQLDelight, Koin no fueron investigados). Se mantiene tal cual
> el roadmap original.

**Decisiones de diseño fijadas:** UI en Compose Multiplatform desde el día 1 (código UI ya iOS-ready); navegación multiplatform (Voyager o Decompose) en vez de Navigation-Compose; SQLDelight (no Room); Koin (no Kodein); target iOS y publishing diferidos hasta tener Mac/cuentas.

**Orden de aprendizaje:** Kotlin (corrutinas/Flow ≈ goroutines/channels de Go, null-safety, sealed classes, extension functions) → fundamentos de plataforma Android + Compose → núcleo KMP compartido (`expect`/`actual`, Ktor Client, SQLDelight, Koin) → estados de UI y Offline-First → proyecto `mobile-app`.

**Proyecto principal — `mobile-app`:** cliente multiplatform (Android primero, iOS al tener Mac) que consume `resilient-api`/`taskapi`/`capstone`. Auth JWT con refresh, dashboard reactivo consumiendo `/analytics/summary` con estados loading/empty/error, Offline-First (SQLite local, sync con Go + PostgreSQL al volver en línea), misma UI en Android e iOS desde un solo código Compose Multiplatform.

---

## El libro que amarra todo — DDIA

_Designing Data-Intensive Applications_ (Kleppmann). No se lee de corrido — se abre como referencia en el momento que corresponde:

| Capítulos                     | Fase | Por qué en ese momento                         |
| ----------------------------- | ---- | ---------------------------------------------- |
| Cap. 2 — Data Models          | F2   | Al diseñar el schema de `taskapi`              |
| Cap. 5 — Replication          | F3   | Cuando el sistema tiene múltiples nodos        |
| Cap. 7 — Transactions         | F3   | Al implementar transacciones distribuidas      |
| Cap. 8 — Distributed Problems | F3   | CAP Theorem, clocks, consensus                 |
| Cap. 10 — Batch Processing    | F4   | Lambda Architecture                            |
| Cap. 11 — Stream Processing   | F4   | Kappa Architecture, Kafka internals            |
| Caps. 1, 3, 4, 6, 9, 12       | F5   | Completar el libro con toda la base construida |

---

## Resumen de proyectos principales

| Fase | Proyecto                                      | Stack                              | Qué demuestra                             |
| ---- | --------------------------------------------- | ---------------------------------- | ----------------------------------------- |
| F1   | `mysh` — Mini Shell UNIX                      | C, GCC, Make                       | Procesos, memoria, syscalls, DSA aplicado |
| F2   | `taskapi` — REST API segura                   | Go, Python, PostgreSQL             | Backend productivo, seguridad, modelado   |
| F3   | `resilient-api` — API distribuida             | Go, Docker, Redis, OTel            | Resiliencia, observabilidad, CI/CD        |
| F4   | `eventpipe` — Pipeline de datos               | Python idiomático, Kafka, dbt      | Data Engineering end-to-end               |
| F5   | `architecture-docs` — Docs técnicas           | C4, ADRs, RFCs, DDD                | Pensar y comunicar arquitectura           |
| F6   | `capstone` — Sistema integrado                | Todo el stack                      | Portfolio de empleabilidad                |
| F7   | `resilient-api`/`eventpipe`/`capstone` en AWS | ECS, RDS, S3, Glue, Athena         | Deploy y operación en la nube             |
| F8   | `mobile-app`                                  | Kotlin, Compose Multiplatform, KMP | Cliente multiplatform del propio stack    |

---

## Stack completo

```
Sistemas y bajo nivel:     C, GCC, Makefiles, Linux Internals, GDB, Valgrind
Backend:                   Go (APIs, microservicios) + Python (data, scripting)
Base de datos:             PostgreSQL (transaccional) + DuckDB (analytics)
Mensajería:                Apache Kafka
Transformaciones:          dbt
Caché:                     Redis
Infraestructura:           Docker + Compose + GitHub Actions
Observabilidad:            Prometheus + Grafana + OpenTelemetry
Arquitectura:              System Design, CQRS, Event Sourcing, Saga, DDD, C4, ADRs

— Extensiones diferidas —
Cloud (F7):                AWS: S3 · ECS · RDS · Lambda · Glue · Athena · Kinesis · IAM · CloudWatch
Certificaciones (F7):      AWS CLF-C02 · SAA-C03 · DEA-C01
Móvil (F8):                Kotlin + Compose Multiplatform + KMP (Ktor, SQLDelight, Koin)
```

---

## Perfil al cierre de F6 (18 meses)

- Entiende qué hace el kernel cuando llama a `fork()` y puede explicarlo.
- Construye APIs que aguantan carga porque entiende concurrencia real.
- Diseña pipelines de datos que no fallan silenciosamente.
- Cuando algo explota en producción, sabe mirarlo: logs, métricas, traces.
- Puede dibujar la arquitectura de un sistema y defender cada decisión.
- Escribe código seguro por defecto, no como afterthought.

Con F7 y F8 sumados: despliega y opera en AWS (no solo en docker compose local) y tiene un cliente multiplatform funcional sobre su propio backend.

---

## Notas de investigación

- **Removidos/reemplazados durante la verificación con SOURCES.md:** SQLShed (dbt/DuckDB, no corroborado), `runbook.academy` y `systeminternals.dev` (Kubernetes, no corroborados), el libro _Streaming Systems_ como recurso gratuito (es pago — reemplazado por los ensayos gratis de Akidau), _Fluent Python_ como lectura obligatoria (ya no aplica al alcance idiomático de F4), AlgoMaster.io (nunca verificado, se sacó del documento), nombre "RU101" de Redis University (desactualizado), tutoriales de Kafka con ZooKeeper (desactualizados desde Kafka 4.x), OpenTracing/`jaeger-client-go` (obsoletos), la URL "threedots.labs" (no existe, es threedots.tech), la licencia CC BY-NC-SA atribuida a _Kubernetes the Hard Way_ (es Apache 2.0), y el libro _Big Data_ de Nathan Marz como "gratis" (es pago).
- **Fuera de scope de este roadmap:** RAG/Embeddings — se cubre en el roadmap paralelo de AI Engineering.
- **No verificado por SOURCES.md, se mantiene sin marca especial de riesgo por tratarse de referencias muy conocidas y de bajo riesgo de identidad/licencia:** DDIA (Kleppmann), AWS (F7 completa), Mobile/KMP (F8 completa), canales de YouTube complementarios (Fiset, Stoney codes, Anthony GG, TechWorld with Nana), OSS good-first-issue y distribución de Leetcode.
