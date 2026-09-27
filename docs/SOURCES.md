# SOURCES.md — Fuentes de aprendizaje verificadas

> Documento vivo. Cada fase tiene un estado (CERRADO / ACTIVO / LISTO, sin empezar).

> Metodología: para cada tema se investigó con 2 IAs (con búsqueda web), se compararon

> resultados. "Confianza" indica qué tan verificado quedó cada recurso, no su calidad.

---

## F1 — Linux Internals, C & DSA Fundamentos

### C y Linux Internals — **CERRADO** (hasta mysh v2.0)

Estado: completado por el estudiante (fork/exec, señales, pipes). No requiere más
investigación en este momento — se retoma solo si hace falta repasar algo puntual.

**Recursos usados y confirmados en la práctica:**

- Jacob Sorber (YouTube) — videos de C, memoria, pthreads, syscalls, Makefiles, GDB/Valgrind
- Playlists de referencia: [C programming playlist](https://www.youtube.com/playlist?list=PLs87dCfSJbLf-nPShgl5WhVkcgxRKZndb), [Debugging C playlist](https://www.youtube.com/playlist?list=PL9IEJIKnBJjHGWPN_S9NS_Ky1-tC8ZrUI)

**Referencia futura (no verificados con búsqueda dedicada en esta sesión, pero de
reputación conocida y ampliamente recomendados):**

- [Beej's Guide to Network Programming](https://beej.us/guide/bgnet/) — para cuando se
  toquen sockets en Go (F2) o si se quiere repasar C de red
- OSTEP (Operating Systems: Three Easy Pieces) — libro + homeworks/projects gratis,
  para profundizar en procesos/memoria si hace falta

**Pendiente si se retoma:** `mysh` quedó en v2.0 (redirección `>`/`<`/`>>` e historial
con linked list no implementados, decisión consciente de cerrar aquí).

---

### DSA — **ACTIVO** (S6–S10 en C, luego hilo permanente en Go desde F2)

**Plan:** 3 semanas en C (dynamic array, linked list, hash table — donde la memoria
manual enseña algo), resto de estructuras (stack, queue, BST, sorting) directo en Go.
Desde F2 en adelante: ~3h/semana, 2-3 problemas nuevos + 1h de repaso espaciado.

| Rol                        | Recurso                                                               | Confianza | Notas                                                                                                  |
| -------------------------- | --------------------------------------------------------------------- | --------- | ------------------------------------------------------------------------------------------------------ |
| Concepto (videos por tema) | Princeton Algorithms Part I — **solo los videos**, no los assignments | Alta      | Gratis confirmado (sin certificado). En Java — se implementa en C/Go, no se copian los assignments     |
| Apoyo interactivo          | OpenDSA (opendsa-server.cs.vt.edu)                                    | Alta      | Gratis confirmado, no exige matrícula, ejercicios interactivos de código y manipulación de estructuras |
| Apoyo interactivo          | VisuAlgo                                                              | Media     | No verificado con búsqueda dedicada hoy, pero aparece en listas de recursos gratuitos repetidamente    |
| Práctica (hilo permanente) | NeetCode — Blind 75 → 150                                             | Alta      | Plataforma mayormente gratuita, Pro opcional. Resolver en Go                                           |
| Referencia                 | Open Data Structures (opendatastructures.org)                         | Media     | Recomendado por fuentes, no verificado con búsqueda dedicada hoy                                       |
| Repaso espaciado           | Anki (escritorio)                                                     | —         | Una tarjeta por error cometido, no por concepto genérico                                               |

**Método de práctica sin IA:** si tras 30-45 min no sale, mirar la solución en NeetCode,
entender el patrón, y al día siguiente reescribirla desde cero sin mirar. Repasos a 1
día, 3 días, 1 semana, 2 semanas, 1 mes, 3 meses.

---

## F2 — Go + PostgreSQL + Seguridad + Modelado de Datos

### Go

| Rol                        | Recurso                                                                                                                                         | Confianza  | Notas                                                                                                                                                                        |
| -------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------- | ---------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Arranque (1-2 días)        | [A Tour of Go](https://go.dev/tour/)                                                                                                            | Alta       | Oficial, gratis, ejercicios en el navegador                                                                                                                                  |
| Principal                  | [Learn Go with Tests](https://quii.gitbook.io/learn-go-with-tests)                                                                              | Alta       | Gratis, TDD. Cubre interfaces, DI, mocking, concurrencia, context, HTTP con stdlib. Puede tener algún ejemplo desactualizado (variables de bucle en goroutines, pre-Go 1.22) |
| Práctica idiomática        | Exercism — pista de Go                                                                                                                          | Media-alta | Gratis, 165 ejercicios, mentoría humana voluntaria. El track mostraba una señal de "necesita atención" en su gestión — mantenimiento limitado pero funcional                 |
| Referencia                 | [Go by Example](https://gobyexample.com/), [Effective Go](https://go.dev/doc/effective_go), [go.dev/doc/tutorial](https://go.dev/doc/tutorial/) | Media-alta | Para consultar mientras se construye                                                                                                                                         |
| Opcional (proyectos extra) | Gophercises                                                                                                                                     | Media-baja | Gratis pero antiguo (~2018), dependencias que pueden requerir adaptación (BoltDB, APIs viejas)                                                                               |
| Repaso posterior           | 100 Go Mistakes (versión web)                                                                                                                   | —          | Para cuando ya haya código real escrito                                                                                                                                      |

---

### PostgreSQL

| Rol                  | Recurso                                                                      | Confianza | Notas                                                                                                                                                         |
| -------------------- | ---------------------------------------------------------------------------- | --------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Principal (SQL)      | [pgexercises.com](https://pgexercises.com)                                   | Alta      | Gratis, con ejercicios, listado en recursos oficiales de postgresql.org                                                                                       |
| Apoyo interactivo    | Postgres Playground (ahora bajo Snowflake, antes Crunchy Data)               | Media     | Crunchy Data fue adquirida por Snowflake en 2025 — verificar el link vigente antes de usar (`snowflake.com/en/developers/postgres/learn-postgres-tutorials/`) |
| Índices              | [Use The Index, Luke](https://use-the-index-luke.com)                        | Alta      | Gratis, mantenido activamente. Solo leer los capítulos de índices y `WHERE`, no de corrido                                                                    |
| Referencia           | Documentación oficial — capítulos _Concurrency Control_ y _Performance Tips_ | Alta      | Para transacciones, aislamiento, `EXPLAIN`                                                                                                                    |
| Consulta rápida      | postgresqltutorial.com (ahora alojado en neon.com, patrocinado por Neon)     | Media     | Solo para sintaxis puntual                                                                                                                                    |
| Profundidad opcional | CMU 15-445 (Andy Pavlo, YouTube)                                             | —         | Solo clases de storage, índices, transacciones                                                                                                                |

---

### Modelado de datos / ER

| Rol           | Recurso                                                                                       | Confianza | Notas                                                                                                                      |
| ------------- | --------------------------------------------------------------------------------------------- | --------- | -------------------------------------------------------------------------------------------------------------------------- |
| Principal     | CS50 SQL (Harvard, OpenCourseWare) — semanas 1-4 (Querying, Relating, **Designing**, Writing) | Alta      | Gratis confirmado. Lecture 2 "Designing" cubre schemas, tipos, normalización. Problem sets propios                         |
| Apoyo (video) | Curso de freeCodeCamp en YouTube "Learn Relational Database Design"                           | Alta      | Gratis, basado en el libro de pago _Grokking Relational Database Design_ (Manning) — el curso en sí es gratis, el libro no |
| Referencia    | UC Berkeley CS 186, Note 13 (DB Design)                                                       | Media     | No verificado con búsqueda dedicada hoy, pero consistente con el patrón de Berkeley de publicar notas abiertas             |

---

### Seguridad backend

| Rol                  | Recurso                                                                                                                | Confianza | Notas                                                                                                                                                                          |
| -------------------- | ---------------------------------------------------------------------------------------------------------------------- | --------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| Principal (práctica) | PortSwigger Web Security Academy — solo rutas de **SQL Injection, Authentication y JWT**                               | Alta      | 100% gratis confirmado, sin paywall alguno. Requiere cuenta gratuita (cada lab levanta instancia aislada). Enfoque en explotar, no en prevenir — hay que traducir a la defensa |
| Apoyo (checklist)    | OWASP Cheat Sheet Series — solo: Password Storage, JWT, Input Validation, SQL Injection Prevention, Secrets Management | Alta      | Gratis, sin ejercicios (es checklist, no curso)                                                                                                                                |
| Referencia           | OWASP Top 10 (versión 2025, la vigente)                                                                                | Alta      | Confirmado como versión actual                                                                                                                                                 |

**Nota práctica:** flujo sugerido = resolver el lab de PortSwigger (ver la
vulnerabilidad en acción) → volver al código en Go y aplicar la cheat sheet
correspondiente.

---

## F3 — Docker + Redis + Observabilidad + CI/CD + Resiliencia

### Docker

| Rol                               | Recurso                                                                    | Confianza | Notas                                                                                                                                           |
| --------------------------------- | -------------------------------------------------------------------------- | --------- | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| Principal                         | [docker-curriculum.com](https://docker-curriculum.com) (Prakhar Srivastav) | Alta      | Gratis, MIT license, 6k+ estrellas en GitHub, último commit feb 2026 — activamente mantenido. Autor es Docker Captain reconocido                |
| Apoyo interactivo                 | [Docker 101 Tutorial](https://www.docker.com/101-tutorial/)                | Alta      | Oficial. **No requiere Docker Desktop** — tiene opción de correr vía "Play with Docker" en el navegador, o contra Docker Engine nativo en Linux |
| Para entender "no es magia negra" | Liz Rice — Build Your Own Container (charla + repo en Go)                  | Alta      | Conecta con la base de F1 (procesos, namespaces, syscalls). Muy recomendado dado el perfil                                                      |
| Referencia                        | Documentación oficial — Dockerfile best practices                          | Alta      | Para el multi-stage build de `taskapi`                                                                                                          |

**Nota de secuencia:** Docker entra dos veces — mini-módulo al inicio de F2 (solo
`docker run postgres`), y a fondo aquí en F3 con docker-curriculum.com completo.

---

### Redis

| Rol                             | Recurso                                                          | Confianza  | Notas                                                                                                                                                            |
| ------------------------------- | ---------------------------------------------------------------- | ---------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Principal                       | Redis University — **"Get Started with Redis"**                  | Alta       | Gratis confirmado. **Ojo con el nombre:** el antiguo "RU101" fue reemplazado por este curso en 2024 — si alguna fuente lo cita como "RU101", está desactualizada |
| Apoyo (construir para entender) | Build Your Own Redis (CodeCrafters), en Go                       | Media-alta | Conecta con la base de sistemas. Verificar antes si la capa gratuita alcanza para el material teórico completo                                                   |
| Referencia                      | Documentación oficial de Redis — Data Types + Commands Reference | Alta       | Cada comando trae su complejidad Big-O                                                                                                                           |

---

### Observabilidad (Prometheus + Grafana + OpenTelemetry)

| Rol                      | Recurso                                                                                                                                        | Confianza | Notas                                                                                                                                                                                                                                        |
| ------------------------ | ---------------------------------------------------------------------------------------------------------------------------------------------- | --------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Principal                | [Monitor a Golang application with Prometheus and Grafana](https://docs.docker.com/guides/go-prometheus-monitoring/) (Docker Guides)           | Alta      | Verificado en detalle: guía oficial de Docker, con código Go completo, Dockerfile, `compose.yml` funcional (Prometheus v2.55.0, Grafana v11.3.0), dashboard JSON importable. Usa framework Gin — adaptar el middleware si se usa otro router |
| Apoyo (tracing)          | OpenTelemetry Go — [Getting Started](https://opentelemetry.io/docs/languages/go/getting-started/) + ejemplo oficial `otel-collector` en GitHub | Alta      | Oficial, gratis, cubre spans, contexto, exportación OTLP a Jaeger                                                                                                                                                                            |
| Referencia               | Prometheus Docs — [Understanding metric types](https://prometheus.io/docs/tutorials/understanding_metric_types/)                               | Alta      | Counter vs gauge vs histogram, cuándo usar cada uno                                                                                                                                                                                          |
| Marco teórico (opcional) | Ensayo de Peter Bourgon — "Metrics, tracing, and logging"                                                                                      | Media     | Clásico reconocido del campo, no verificado con búsqueda dedicada hoy. Explica el "por qué", no el "cómo"                                                                                                                                    |

**Dato adicional confirmado:** las librerías de OpenTracing y el cliente nativo
`jaeger-client-go` están oficialmente obsoletas, reemplazadas por OpenTelemetry.
Cualquier tutorial que las use está desactualizado.

---

### CI/CD (GitHub Actions)

| Rol                      | Recurso                                                                                                                                                                      | Confianza | Notas                                                                                                                                                                                                                         |
| ------------------------ | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | --------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Principal                | [GitHub Skills — Continuous Integration](https://github.com/skills/continuous-integration)                                                                                   | Alta      | Verificado: curso interactivo real, bot crea issues/PRs en un repo propio, valida workflow YAML, triggers, branch protections. Menos de 2 horas                                                                               |
| Apoyo                    | [Tutorials for GitHub Actions](https://docs.github.com/en/actions/tutorials) (docs oficiales)                                                                                | Alta      | Verificado: 12 tutoriales modulares confirmados, incluyendo build/test en Go, service containers de PostgreSQL y Redis, publicación de paquetes                                                                               |
| Referencia               | [Quickstart](https://docs.github.com/en/actions/get-started/quickstart) + [Building and testing your code](https://docs.github.com/en/actions/tutorials/build-and-test-code) | Alta      | Para primer "hello world" y recetas concretas de build/test por lenguaje mientras se arma el pipeline propio                                                                                                                  |
| Apoyo teórico (opcional) | [Full Stack Open — Part 11: CI/CD](https://fullstackopen.com/en/part11) (U. Helsinki)                                                                                        | Media     | Verificado que existe y trata CI/CD con GitHub Actions. Proyecto base en Node.js/JavaScript — hay que adaptar comandos (`npm test` → `go test ./...`). Usar solo si la mecánica de GitHub Skills no explica bien el "por qué" |

---

### Circuit Breaker / Patrones de resiliencia (Timeout, Bulkhead, Rate Limiting)

| Rol                       | Recurso                                                                                                                                        | Confianza  | Notas                                                                                                                                                                                          |
| ------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------- | ---------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Principal (fundamentos)   | [sony/gobreaker](https://github.com/sony/gobreaker)                                                                                            | Alta       | Verificado: 3.4k estrellas, librería madura y estándar de facto para Circuit Breaker en Go. Máquina de estados clásica (Closed/Open/Half-Open)                                                 |
| Principal (rate limiting) | [golang.org/x/time/rate](https://pkg.go.dev/golang.org/x/time/rate)                                                                            | Alta       | Verificado: paquete oficial del equipo de Go, Token Bucket, thread-safe. Solo en memoria local — no sincroniza entre réplicas (para eso, Redis)                                                |
| Apoyo                     | [failsafe-go](https://github.com/failsafe-go/failsafe-go)                                                                                      | Alta       | Verificado: librería real y activa. Compone Retry, Circuit Breaker, Bulkhead, Rate Limiter, Timeout y Fallback en un mismo framework — es el "todo en uno" que gobreaker por sí solo no ofrece |
| Apoyo (práctica aplicada) | Three Dots Labs — [threedots.tech](https://threedots.tech/) (blog + Watermill)                                                                 | Media-alta | **URL corregida** — una de las IAs citó "threedots.labs", que no existe. El recurso real (blog de 270k+ visitas/año, autores de Watermill) está en threedots.tech                              |
| Referencia                | [Microsoft Azure Architecture Center — Circuit Breaker pattern](https://learn.microsoft.com/en-us/azure/architecture/patterns/circuit-breaker) | Alta       | Fuente conceptual agnóstica al lenguaje: los 3 estados, fallos transitorios vs. estructurales, ventanas de recuperación. Mapear a Go con gobreaker/failsafe-go                                 |
| Apoyo teórico (opcional)  | [kat-co/concurrency-in-go-src](https://github.com/kat-co/concurrency-in-go-src) (companion del libro _Concurrency in Go_, O'Reilly)            | Alta       | Si Bulkhead (canales con buffer como semáforo) o Timeout (`context.WithTimeout` + `select`) no hacen clic con las librerías, para verlo construido desde cero con stdlib                       |

---

## F4 — Arquitectura de Software, DDD & System Design Práctico

**Organización en 4 niveles (de negocio a código):**
Esta fase se estructura en 4 niveles jerárquicos donde cada uno responde una pregunta distinta y se apoya en el anterior:
- **Nivel 0 — DDD (el negocio):** Bounded Contexts y modelado de reglas de negocio en Go.
- **Nivel 1 — System Design (la infraestructura):** Comunicación a escala, consistencia, colas, bases distribuidas (Fly.io Gossip Glomers retos 1-4).
- **Nivel 2 — Patrones de Arquitectura (la estructura del servicio):** Hexagonal / Clean Architecture, aislamiento del dominio.
- **Nivel 3 — Patrones de Diseño (el código):** Catálogo GoF clásico comprendido a nivel conceptual y mapeado a Go idiomático (Functional Options, middleware, interfaces implícitas).

---

### Nivel 0 — Domain-Driven Design (DDD)

| Rol                                  | Recurso                                                                                                                                                                                                          | Confianza  | Notas                                                                                                                                                                                                                                                                                                                                    |
| ------------------------------------ | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Principal — táctico en Go            | [Practical DDD in Go / DDD Lite (Three Dots Labs)](https://threedots.tech/) — series `ddd-lite-in-go`, `repository-pattern-in-go`, `basic-cqrs-in-go`                                                            | Alta       | Mismo ecosistema que Wild Workouts (arquitectura). Refactors reales de problemas de dominio (reservas, bloqueo de inventario) de modelo anémico a modelo rico con invariantes protegidas                                                                                                                                                 |
| Principal — diseño estratégico       | [DDD-Crew — Bounded Context Canvas](https://github.com/ddd-crew/bounded-context-canvas) + [Context Mapping](https://github.com/ddd-crew/context-mapping)                                                         | Alta       | Plantillas abiertas (CC/MIT) ampliamente adoptadas en conferencias (DDD Europe, GOTO). Cubren Shared Kernel, Customer-Supplier, Conformist, Anti-Corruption Layer — el diseño estratégico que los libros pagos cobran caro                                                                                                               |
| Referencia — filosofía y lecciones   | ["Domain-Driven Design: The First 15 Years"](https://leanpub.com/ddd_first_15_years) (ensayos, Leanpub)                                                                                                          | Alta       | **Verificado hoy:** precio mínimo real $0.00 ("Free!"), sin tarjeta. Ensayos genuinos de Fowler, Coplien, Vladik Khononov, Alberto Brandolini y otros. Los propios creadores de DDD reconocen que la comunidad se obsesionó con patrones tácticos (repos, fábricas) y descuidó el diseño estratégico — lectura de criterio, no de código |
| Referencia extra (hallazgo propio)   | ["The Anatomy of Domain-Driven Design"](https://leanpub.com/theanatomyofdomain-drivendesign) (Scott Millett, Leanpub) — y la ["DDD Referenz"](https://leanpub.com/ddd-referenz) escrita por el propio Eric Evans | Alta       | **Verificado hoy:** ambos gratis bajo el mismo modelo pay-what-you-want de Leanpub ($0.00 mínimo). La "Referenz" en particular es un resumen corto escrito por el creador original de DDD — buen complemento de una página para tener a mano                                                                                             |
| Apoyo — modelado completo con código | [DDD by Examples: Library](https://github.com/ddd-by-examples/library) (DDD-Crew)                                                                                                                                | Media-alta | Muestra el proceso completo: tableros de Event Storming, Context Maps, ADRs, y código. El código está en Java/Spring, pero ~70% del valor (diagramas, mapas de contexto) es agnóstico y transferible a Go                                                                                                                                |
| Apoyo — package layout pragmático    | Ben Johnson — ["Standard Package Layout"](https://medium.com/@benbjohnson/standard-package-layout-7cd488332d16)                                                                                                  | Alta       | Artículo fundacional (citado en la wiki oficial de Go) que aplica DDD de forma pragmática sin usar la jerga formal — domain models en el paquete raíz, adaptadores en subpaquetes                                                                                                                                                        |
| Referencia adicional (índice)        | [DDD-Crew — Free DDD Learning Resources](https://github.com/ddd-crew/free-ddd-learning-resources)                                                                                                                | Alta       | Colección curada oficial de la organización DDD-Crew — buen punto de partida si alguno de los recursos de arriba no termina de encajar                                                                                                                                                                                                   |

**Mapeo mental DDD → Go:**

| Concepto DDD          | Equivalente en Go                                                       | Regla                                                                                                                                            |
| --------------------- | ----------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------ |
| Value Object          | Struct inmutable por convención                                         | Sin punteros ni mutadores; se pasa por valor, igualdad por comparación de campos (`m1 == m2`)                                                    |
| Entity                | Struct con ID explícito                                                 | El ID es inmutable; dos entidades son iguales solo si el ID coincide, aunque cambie el resto                                                     |
| Aggregate Root        | Struct con campos **no exportados**                                     | Ningún paquete externo puede mutar directo; toda mutación pasa por métodos exportados (`func (o *Order) Pay(...) error`)                         |
| Domain Event          | Struct simple con timestamp + payload                                   | Se acumula en una slice interna del agregado y se despacha tras persistir con éxito (conecta con el patrón Outbox de la sección de Arquitectura) |
| Repository            | `interface` definida en el **consumidor** (dominio), no en el productor | Solo métodos del agregado completo: `Get(ctx, id)`, `Save(ctx, *Order)` — nunca filtrar por columnas de la DB desde el dominio                   |
| Anti-Corruption Layer | Paquete adaptador con función traductora pura                           | `func toDomain(dto ExternalUserDTO) (User, error)` — transforma antes de que el DTO externo cruce al dominio                                     |

**Ruta sugerida (3 semanas, ~10-12h/semana):**
1. **S1 — Estratégico, Bounded Contexts, Lenguaje Ubicuo:** canvas de DDD-Crew + primeros ensayos de "The First 15 Years". Práctica: Bounded Context Canvas de `taskapi`.
2. **S2 — Táctico: Value Objects, Entidades y Agregados:** refactor en Go con invariantes protegidas en `taskapi`.
3. **S3 — Repositorios y Domain Events con Outbox:** desacoplamiento mediante interfaces e implementación del Outbox Pattern en PostgreSQL.

---

### Nivel 1 — System Design (la infraestructura)

| Rol                               | Recurso                                                                                                                                         | Confianza | Notas                                                                                                                                                                                                                                                               |
| --------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------- | --------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Principal — retos con validación  | [Fly.io Distributed Systems Challenges (Gossip Glomers)](https://fly.io/dist-sys/)                                                              | Alta      | Retos 1 al 4 con validación automática (Maelstrom). SDK de referencia nativo en Go. Retos: Echo, Unique ID Generation, Broadcast, Grow-only Counter (CRDT). Requiere JDK para el runner                                                                               |
| Principal — guía integral         | [System Design Primer](https://github.com/donnemartin/system-design-primer)                                                                     | Alta      | Compendio de referencia + casos resueltos (Pastebin, Twitter timeline, web crawler) + flashcards Anki. Ideal para estructurar el marco conceptual y estimaciones                                                                                                     |
| Apoyo — patrones internos         | [Catalog of Patterns of Distributed Systems](https://martinfowler.com/articles/patterns-of-distributed-systems/) (Unmesh Joshi / Martin Fowler) | Alta      | Desarma la "magia" de cómo están hechos por dentro Kafka, Cassandra, etcd (WAL, Leader-Follower, Quorum, Idempotent Receiver). Mapea directo a Linux/Go                                                                                                             |
| Referencia — papers fundacionales | Dynamo, GFS, Bigtable (papers originales de Amazon/Google, libres)                                                                              | Alta      | Lectura densa pero son el origen real de los patrones que se enseñan en todos los cursos de arriba (consistent hashing, vector clocks, sloopy quorums)                                                                                                             |
| Referencia — operación real       | [Google SRE Book](https://sre.google/sre-book/)                                                                                                 | Alta      | SLOs, error budgets, monitoring. Complementa la base de observabilidad de F3                                                                                                                                                                                         |
| Preparación de entrevistas        | [ByteByteGo](https://www.youtube.com/@ByteByteGo), [Arpit Bhayani](https://www.youtube.com/channel/UC_b1GUJv_2QiMP4BxC9-Dxg), *System Design Interview Vol. 1 & 2* (Alex Xu), [Silver.dev — System Design Meta](https://docs.silver.dev/interview-ready/system-design-interviews/system-design-meta), [HelloInterview](https://www.hellointerview.com/) | Alta | Guías prácticas para estructurar simulacros de 45 minutos                                                                                                                                                                           |

**Ruta sugerida (4-5 semanas, ~10-12h/semana):**
1. **S1-2 — Fundamentos y estimaciones:** back-of-the-envelope, load balancing L4 vs L7, caching (write-through, cache-aside), particionado (range/hash/consistent hashing).
2. **S3-4 — Consistencia y replicación en Go:** CAP/PACELC real, leader/follower, CRDTs, gossip protocols. Práctica: retos 1-4 de Fly.io Gossip Glomers en Go.
3. **S5 — Simulacros de entrevista:** 5 casos clásicos cronometrados (45 min), foco en trade-offs (latencia vs. consistencia, escala vertical vs. horizontal).

---

### Nivel 2 — Patrones de Arquitectura (la estructura del servicio)

| Rol                           | Recurso                                                                                                                                              | Confianza  | Notas                                                                                                                                                                                                                                                                                                                    |
| ----------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------- | ---------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| Principal — código real en Go | [Wild Workouts (Three Dots Labs)](https://github.com/ThreeDotsLabs/wild-workouts-go-ddd-example)                                                     | Alta       | Repo real y activo, refactorización progresiva a Clean Architecture + CQRS. Integra gRPC, HTTP/OpenAPI y eventos con Watermill                                                                                                                                                                                           |
| Apoyo — estructura comparada  | [go-structure-examples](https://github.com/katzien/go-structure-examples) (Kat Zien, charla GopherCon)                                               | Alta       | Mismo servicio bajo 4 filosofías (flat, layered, hexagonal, domain-driven) para comparar directamente                                                                                                                                                                                                                    |
| Apoyo — EDA/CQRS conceptual   | Martin Fowler — ["What do you mean by Event-Driven?"](https://martinfowler.com/articles/201701-event-driven.html) + artículos de CQRS/Event Sourcing | Alta       | Antídoto contra usar CQRS/Event Sourcing por defecto. Taxonomía de eventos estándar                                                                                                                                                                                                                                       |
| Referencia — patrones cloud   | [Microsoft Azure Architecture Center — Patterns](https://learn.microsoft.com/en-us/azure/architecture/patterns/)                                     | Alta       | CQRS, Event Sourcing, Compensating Transaction, Throttling. Agnóstico a Go                                                                                                                                                                                                                                                |
| Referencia — monolito modular | [Modular Monolith with DDD](https://github.com/kamilgrzybek/modular-monolith-with-ddd) (Kamil Grzybek)                                               | Media-alta | Principios aplicables al diseño modular desacoplado en Go                                                                                                                                                                                                                                                                |
| Referencia — diseño de APIs   | [Microsoft REST API Guidelines](https://github.com/microsoft/api-guidelines) + [Google API Design Guide](https://cloud.google.com/apis/design)       | Alta       | Estándares battle-tested para versionado, paginación, idempotencia, errores canónicos                                                                                                                                                                                                                                    |

**Ruta sugerida (2 semanas, ~10-12h/semana):**
1. **S1 — Hexagonal/Clean Architecture en Go:** separar dominio de adaptadores HTTP (`net/http`) y Postgres (`pgx`).
2. **S2 — Monolito modular y contratos:** encapsulación modular y diseño de APIs robustas.

---

### Nivel 3 — Patrones de Diseño (GoF idiomático en Go)

| Rol | Recurso | Confianza | Notas |
|---|---|---|---|
| Principal — catálogo conceptual | [Refactoring.Guru — Design Patterns](https://refactoring.guru/design-patterns) | Alta | Catálogo web con los 23 patrones GoF: intención, diagramas y pros/contras |
| Referencia — Go idiomático | [kat-co/concurrency-in-go-src](https://github.com/kat-co/concurrency-in-go-src) | Alta | Patrones concurrentes en Go (pipeline, fan-out/fan-in, or-done-channel, bridge) |

**Mapeo de Patrones GoF a Go:**
- **Strategy:** Interfaces implícitas de Go (`io.Reader`, single-method interfaces).
- **Decorator:** Middleware HTTP (`func(http.Handler) http.Handler`) y struct embedding envolviendo interfaces.
- **Builder:** Functional Options (`type Option func(*Server)`).
- **Factory Method:** Constructores idiomáticos (`NewUser(...)`, `NewRepository(...)`).
- **Singleton:** Evitado en favor de inyección explícita de dependencias.
- **Adapter:** Struct adaptador que implementa una interfaz del dominio.

**Ruta sugerida (1-2 semanas):** Catálogo GoF en Refactoring.Guru → identificación y mapeo a equivalentes idiomáticos en Go dentro de `taskapi` y `resilient-api`.
---

## F5 — Portfolio de Alto Impacto & Preparación de Entrevistas

**Nota de estrategia:** F5 consolida la Etapa 1 (Pre-Graduación). El objetivo es tener un portfolio de **2 proyectos estrella de nivel de producción en Go** listos para deslumbrar en entrevistas técnicas remotas en USD, además de dominar los filtros de algoritmos, SQL y System Design antes de graduarse.

---

### Portfolio (Backend & Systems Engineering)

**La regla central:** **2 proyectos de alta fidelidad, no 8-10 a medias.** Los reclutadores y hiring managers técnicos escanean en segundos: título, stack, diagrama C4, problema/solución en 2-3 frases, y métricas reproducibles (latencia p99, throughput, uptime) — no leen código crudo antes de decidir si entrevistar.

**Filtro para decidir qué proyecto mostrar:**

1. **¿Se levanta con un solo comando?** Si `docker compose up -d` no deja el sistema corriendo con métricas vivas en ~90 segundos, el proyecto "no existe" para quien lo evalúa.
2. **¿Muestra qué pasa cuando algo falla?** Un proyecto junior muestra el camino feliz. Uno mid muestra Circuit Breakers actuando, rate limiting distribuido con Lua en Redis, transacciones seguras con Outbox Pattern, y graceful shutdown drenando peticiones activas.
3. **¿Hay un benchmark medible?** "Usé Redis para mejorar el rendimiento" es teoría. "El throughput pasó de 450 a 3,800 req/s con p99 cayendo de 180ms a 14ms bajo k6" es una entrevista asegurada.
4. **¿Tiene documentación de arquitectura profesional?** Diagramas C4, ADRs justificando trade-offs, y Runbook operativo.

**Mapeo de proyectos del portfolio:**

| Proyecto estrella | De qué ejercicios sale | Qué señal valida ante el mercado |
|---|---|---|
| **`taskapi` (Backend Production-Ready)** | Go + PostgreSQL + Hexagonal Architecture + DDD táctico + Outbox Pattern de F2 y F4 | Concurrencia real en Go, transacciones ACID estrictas sin ORMs mágicos, arquitectura limpia desacoplada y autenticación JWT segura |
| **`resilient-api` (Distributed & Resilient Backend)** | Go + Docker + Redis + Circuit Breaker + OpenTelemetry + CI/CD de F3 | Resiliencia distribuida (rate limiting en Redis con Lua, circuit breaker manual), observabilidad completa en producción (Prometheus, Grafana, Jaeger) y automatización CI/CD con GitHub Actions |
| *(Diferenciador narrativo)* **`mysh`** | Shell en C de F1 | Fundamentos de sistemas operativos y bajo nivel: gestión manual de memoria (ASan/UBSan), syscalls POSIX (`fork`, `execvp`, `pipe`), demostrando que no se depende de abstracciones a ciegas |
| *(Suite documental)* **`architecture-docs`** | Diagramas C4, 4 ADRs, 1 RFC, 1 Post-mortem, 5 casos de System Design de F4 | Capacidad de diseñar sistemas a gran escala, comunicar trade-offs arquitectónicos y defender decisiones ante ingenieros senior |

**Estructura de README que convierte (case-study, no manual de instalación):** título + una línea de problema → 1 diagrama de arquitectura (C4 Nivel 2) → stack → decisiones de diseño explicadas con trade-offs → métricas/benchmarks medibles con k6 → cómo correrlo (3 comandos) → links a `ARCHITECTURE.md` y `RUNBOOK.md`.

---

### Entrevistas (Backend & Systems + Behavioral + LatAm→Remoto USD)

#### Contenido técnico específico de Backend & Sistemas

| Tema | Qué evalúan realmente | Recurso de referencia |
|---|---|---|
| **SQL avanzado y optimización** | Modelo mental del motor (`FROM→WHERE→GROUP BY→HAVING→SELECT→WINDOW→ORDER BY`), window functions (`ROW_NUMBER`, `RANK`, `LAG/LEAD`), SARGability, algoritmos de join (`Nested Loop`, `Hash Join`, `Merge Join`) y lectura de planes de ejecución | [Use The Index, Luke!](https://use-the-index-luke.com) + práctica directa con `EXPLAIN (ANALYZE, BUFFERS)` sobre PostgreSQL |
| **Estructuras de datos y algoritmos en Go** | Resolución limpia, eficiente e idiomática en Go puro (slices, maps, punteros, structs) sin librerías externas. Foco en arrays, strings, dos punteros, hash maps, árboles binarios, heaps y grafos básicos | [NeetCode — Blind 75 / 150](https://neetcode.io/) implementado en Go (hilo permanente desde F2) |
| **System Design en vivo** | Conducir una sesión de diseño arquitectónico de 45 minutos: clarificar requerimientos, estimar capacidad, diseñar alto nivel, deep dive en componentes críticos, trade-offs CAP/PACELC y mitigación de fallos | [Silver.dev — System Design Meta](https://docs.silver.dev/interview-ready/system-design-interviews/system-design-meta) (en español), [ByteByteGo](https://www.youtube.com/@ByteByteGo), [HelloInterview](https://www.hellointerview.com/) |
| **Open Source en el ecosistema Go** | Capacidad de navegar codebases grandes, entender convenciones ajenas y enviar PRs limpios | Buscar issues con etiqueta `good first issue` en repositorios del stack (`sqlc`, `pgx`, `chi`) |

#### Behavioral / "Work Experience" con proyectos propios

Framework estándar: **STAR** (Situation, Task, Action, Result), con distribución de tiempo sugerida 20/10/60/10. La clave para proyectos de estudio sin experiencia laboral formal: contarlos igual que casos reales, con **trade-offs de ingeniería explícitos**.

Ejemplo de estructura (usando `resilient-api`):
- _Situation_: "Peticiones concurrentes a un microservicio dependiente degradaban el tiempo de respuesta del backend principal bajo ráfagas de 4,000 req/s."
- _Task_: "Garantizar resiliencia ante caídas del servicio externo sin saturar los recursos de red ni bloquear peticiones de otros usuarios."
- _Action_: "Implementé un Circuit Breaker manual con estados Closed/Open/Half-Open, un rate limiter distribuido en Redis ejecutado mediante scripts atómicos en Lua, y propagación de `request_id` a través de OpenTelemetry."
- _Result_: "Throughput de 450 a 3,800 req/s con p99 cayendo de 180ms a 14ms bajo k6. Descubrí cómo el pooling de conexiones HTTP en Go evita agotamiento de file descriptors en Linux."

#### Plataformas para preparación LatAm → EE.UU./Europa

**Silver.dev (Gabriel Benmergui — OpenSea, Robinhood, Scribd):**
- Guías gratuitas abiertas en español de alto valor:
  - [LinkedIn y CV para startups globales](https://docs.silver.dev/interview-ready/consiguiendo-entrevistas/preparando-linkedin)
  - [Trabajando con recruiters y screenings](https://docs.silver.dev/interview-ready/recruiter-screening/trabajando-con-recruiters)
  - Behavioral questions y storytelling ([Parte I](https://docs.silver.dev/interview-ready/hiring-manager-screening/behavioral-preguntas-clasicas), [Parte II](https://docs.silver.dev/interview-ready/hiring-manager-screening/behavioral-storytelling), [Parte III](https://docs.silver.dev/interview-ready/hiring-manager-screening/behavioral-cultura-americana))
  - [Guía de take-homes de alto nivel](https://docs.silver.dev/interview-ready/takehomes/guia-de-takehomes)
  - [Estrategia de negociación salarial](https://docs.silver.dev/interview-ready/manejando-ofertas/negociando-salarios)

**Alternativas de práctica:**
- [Pramp](https://www.pramp.com/) / [Exponent](https://www.tryexponent.com/) free tier: mock interviews P2P gratuitas en inglés.
- [interviewing.io (canal YouTube gratis)](https://www.youtube.com/@interviewing_io): grabaciones reales de entrevistas senior y negociación salarial.

#### Negociación de oferta sin historial salarial previo en USD

**Fuente central, de alta confianza:**
Patrick McKenzie (patio11) — ["Salary Negotiation: Make More Money, Be More Valued"](https://www.kalzumeus.com/2012/01/23/salary-negotiation/) y su ["Kalzumeus Podcast Ep. 12"](https://www.kalzumeus.com/2016/06/03/kalzumeus-podcast-episode-12-salary-negotiation-with-josh-doody/).

Principios centrales:
1. **Nunca des un número primero:** Redirigir a entender el alcance del rol; anclar con bandas salariales de mercado en USD, nunca con ingresos en moneda local.
2. **Definir 3 números antes de negociar:** Aspiracional (percentil 75+), target (lo que se desea), mínimo de aceptación (walk-away).
3. **Negociar por valor de mercado, no por costo de vida.**
4. **Negociar el total compensation** (salario base, equity, bono anual, equipamiento, días libres).
5. **Nunca aceptar en vivo:** Pedir 48 horas para analizar los detalles de la oferta escrita.

**Ruta sugerida (8 semanas, ~8-10h/semana):**
1. **S1-2 — SQL avanzado y planes de ejecución:** problemas diarios de window functions/joins complejos + `EXPLAIN (ANALYZE, BUFFERS)` en Postgres local.
2. **S3-4 — Estructuras de datos y algoritmos en Go:** 2-3 problemas diarios en NeetCode / LeetCode en Go puro.
3. **S5-6 — Behavioral en inglés técnico:** ensayar y grabar en voz alta 6 historias STAR basadas en `taskapi`, `resilient-api` y `mysh`.
4. **S7-8 — Mocks y prospección activa:** simulacros P2P en Pramp, postulaciones a través de Silver.dev y redes de empleo remoto USD.

---

### Buffer Pre-Graduación y Búsqueda Laboral (30 ago – 15 dic 2027, ~15 semanas)

**Objetivo:** Proteger el cierre de la carrera universitaria y ejecutar la búsqueda laboral remota en USD sin saturación.
- **Universidad:** Dedicación plena a la tesis de grado y asignaturas finales de Ingeniería en Informática.
- **Búsqueda activa:** Postulaciones personalizadas a startups de EE.UU./Europa y empresas globales para puestos Backend Go Jr/Mid.
- **Entrevistas:** Atender entrevistas técnicas en vivo, live-coding y pruebas take-home con la mente descansada.
- **Mantenimiento:** 4-6h semanales: 1 kata semanal en Go y 1 simulación de entrevista cada 15 días.

---

# ETAPA 2 — Especializaciones Post-Graduación (2028+)

> **Estrategia Post-Graduación:** Estas especializaciones se abordan **después de titularse y mientras se trabaja como ingeniero**, o como pivot estratégico según oportunidades laborales reales o emprendimientos.

## ESPECIALIZACIÓN A — Data Engineering (Post-Graduación)

### Python para Data Engineering

Objetivo: no repetir fundamentos (ya aprendidos en Go), sino dominar lo idiomático de Python para pipelines en producción: generators, context managers, type hints, testing y empaquetado moderno.

| Rol | Recurso | Confianza | Notas |
|---|---|---|---|
| Principal | [Practical Python Programming](https://dabeaz-course.github.io/practical-python/Notes/Contents.html) (David Beazley) | Alta | Gratis, CC-BY-SA-4.0. Foco en Secciones 2-4 (organización, clases, excepciones) y 6-7 (generators, temas avanzados) |
| Referencia | [Documentación oficial de Python — tutorial](https://docs.python.org/3/tutorial/) | Alta | Functions, Modules, I/O, Errors and Exceptions, Classes, Virtual Environments |
| Referencia (complemento) | [`contextlib`](https://docs.python.org/3/library/contextlib.html), [`typing`](https://docs.python.org/3/library/typing.html), [`datetime`](https://docs.python.org/3/library/datetime.html) + [`zoneinfo`](https://docs.python.org/3/library/zoneinfo.html), [`asyncio`](https://docs.python.org/3/library/asyncio.html) | Alta | Context managers, `Protocol` (equivalente a interfaces de Go), fechas timezone-aware, async básico |
| Arquitectura/diseño | [Architecture Patterns with Python ("Cosmic Python")](https://www.cosmicpython.com/book/preface.html) | Alta | Versión web gratuita bajo CC. Repository Pattern y Unit of Work desde `interfaces` de Go a `typing.Protocol` / `abc.ABC` |
| Testing | [pytest — documentación oficial](https://docs.pytest.org/en/stable/) | Alta | Fixtures, parametrización, `monkeypatch`, mocks por etapas del pipeline |
| Empaquetado | [Python Packaging User Guide](https://packaging.python.org/) → luego [uv](https://docs.astral.sh/uv/) | Alta | `uv` (`pyproject.toml` + `uv.lock`) para proyectos modernos |
| Proyecto de cierre | [Data Engineering Zoomcamp — Módulo 1](https://github.com/DataTalksClub/data-engineering-zoomcamp) | Alta | API pública → chunks con pandas/generators → Postgres en Docker |

**Ruta sugerida (5 semanas):** Practical Python 2-4 → generators y `contextlib` → APIs y `zoneinfo` → pytest y Cosmic Python → empaquetado con `uv`.

### Kafka / Streaming

| Rol | Recurso | Confianza | Notas |
|---|---|---|---|
| Principal (curso) | [Confluent Developer — Apache Kafka 101](https://developer.confluent.io/courses/apache-kafka/events/) + Kafka Streams 101 + ksqlDB 101 | Alta | Gratis para teoría; labs interactivos en Quickstart local con Docker |
| Apoyo (CLI, sin Java) | [Conduktor Kafkademy](https://www.conduktor.io/kafka/) | Media-alta | Contenido teórico y de CLI agnóstico a Java |
| Práctica local (oficial) | [Apache Kafka Quickstart](https://kafka.apache.org/quickstart/) | Alta | Kafka 4.x con KRaft (ZooKeeper eliminado por completo) |
| Referencia densa | [Kafka: The Definitive Guide, 2ª ed.](https://www.confluent.io/resources/ebook/kafka-the-definitive-guide/) | Media | Gratis vía formulario Confluent. Diseño, replicación y arquitectura interna. Mapear a `segmentio/kafka-go` |
| Referencia (sistemas) | [Documentación oficial — sección Design](https://kafka.apache.org/documentation/#design) | Alta | Log append-only en disco, `sendfile` (zero-copy), page cache del kernel, particiones |
| Ensayo fundacional | Jay Kreps — ["The Log"](https://engineering.linkedin.com/distributed-systems/log-what-every-software-engineer-should-know-about-real-time-datas-unifying) (2013) | Alta | El log como abstracción unificadora |
| Práctica integrada | [Data Engineering Zoomcamp — módulo de Kafka](https://github.com/DataTalksClub/data-engineering-zoomcamp) | Alta | Producer/consumer, particionado, replicación, Kafka Streams, schemas con Avro |

**Ruta sugerida (6 semanas):** Modelo mental → Producer/Consumer → Persistencia y garantías de entrega → Integración (Connect, Avro) → Go nativo (`segmentio/kafka-go`) → Pipeline final `eventpipe`.

### Analytics Engineering — dbt + DuckDB

| Rol | Recurso | Confianza | Notas |
|---|---|---|---|
| Principal (curso guiado) | [Quickstart dbt Core v1 con DuckDB + Jaffle Shop](https://docs.getdbt.com/guides/duckdb) | Alta | Gratis, oficial, sin warehouse cloud. Rama estable |
| Práctica local (repo) | [jaffle_shop_duckdb](https://github.com/dbt-labs/jaffle_shop_duckdb) | Alta | Playground reutilizable oficial |
| Adaptador (referencia) | [dbt-duckdb](https://github.com/duckdb/dbt-duckdb) | Alta | Lectura desde S3/Parquet vía `profiles.yml` |
| DuckDB — referencia | [DuckDB Guides](https://duckdb.org/docs/current/guides/overview) | Alta | CSV/Parquet, HTTP/S3, Postgres, API de Go |
| DuckDB — tutorial | ["Fully Local Data Transformation with dbt and DuckDB"](https://duckdb.org/2025/04/04/dbt-duckdb.html) | Media-alta | Modelo dimensional completo, materializations `table`/`incremental`/`snapshot` |
| Buenas prácticas | [dbt — How we style our dbt projects](https://docs.getdbt.com/best-practices/how-we-style/6-how-we-style-conclusion) | Alta | Estructura canónica `staging/intermediate/marts` |
| Práctica integrada | [Data Engineering Zoomcamp — módulo Analytics Engineering](https://github.com/DataTalksClub/data-engineering-zoomcamp) | Alta | Módulo 4 de cierre integrador |

**Ruta sugerida (5 semanas):** DuckDB básico → Datos externos → dbt local → Calidad y modelado → Proyecto de portfolio integrador.

### Arquitecturas de datos (Lambda / Kappa)

| Rol | Recurso | Confianza | Notas |
|---|---|---|---|
| Fuente primaria (Kappa) | Jay Kreps — ["Questioning the Lambda Architecture"](https://www.oreilly.com/radar/questioning-the-lambda-architecture/) (2014) | Alta | Crítica a mantener dos codebases batch/stream |
| Fuente primaria (base técnica) | Jay Kreps — ["The Log"](https://engineering.linkedin.com/distributed-systems/log-what-every-software-engineer-should-know-about-real-time-datas-unifying) (2013) | Alta | Log inmutable + replay = reprocesamiento unificado |
| Fuente primaria (Lambda) | Nathan Marz — post original ["How to beat the CAP theorem"](http://nathanmarz.com/blog/how-to-beat-the-cap-theorem.html) | Media | Ensayo original libre (libro impreso es pago) |
| Síntesis (Lambda) | Ericsson — [Data processing architectures: Lambda and Kappa](https://www.ericsson.com/en/blog/2015/11/data-processing-architectures--lambda-and-kappa) | Media | Patrón conceptual de batch vs stream |
| Síntesis (Kappa) | Materialize — [Does Kappa architecture improve on Lambda?](https://materialize.com/blog/does-kappa-architecture-improve-on-lambda/) | Media | Replay, estado y eventos fuera de orden |
| Complemento streaming | Tyler Akidau — ["Streaming 101"](https://www.oreilly.com/radar/the-world-beyond-batch-streaming-101/) y ["Streaming 102"](https://www.oreilly.com/radar/streaming-102-the-world-beyond-batch/) | Alta | Watermarks, event time vs processing time, windowing |
| Práctica integrada | [Data Engineering Zoomcamp — Streaming](https://github.com/DataTalksClub/data-engineering-zoomcamp) | Alta | Comparación empírica Lambda vs Kappa |
| Referencia motor | [Apache Flink — Concepts](https://nightlies.apache.org/flink/flink-docs-stable/docs/concepts/overview/) | Alta | Motor streaming de referencia |

---

## ESPECIALIZACIÓN B — Cloud (AWS) & Kubernetes (Post-Graduación)

### Kubernetes (conceptual y bajo nivel)

| Rol | Recurso | Confianza | Notas |
|---|---|---|---|
| Principal — mecánica del sistema | [Kubernetes the Hard Way](https://github.com/kelseyhightower/kubernetes-the-hard-way) (Kelsey Hightower) | Alta | Licencia Apache 2.0. 14 labs manuales (PKI/TLS, etcd HA, `systemd`, `containerd`). Adaptable a VMs locales |
| Apoyo — de proceso Linux a Pod | Ian Lewis — ["What are Kubernetes Pods anyway?"](https://www.ianlewis.org/en/what-are-kubernetes-pods-anyway) (4 partes) | Alta | Construye un "Pod" a mano con `unshare(1)`/`setns(2)` sin tener Kubernetes instalado |
| Apoyo — red a bajo nivel | Arthur Chiao — ["Kubernetes Networking: Behind the Scenes"](https://arthurchiao.art/blog/k8s-net-journey/) | Alta | Service/ClusterIP con iptables/IPVS y manipulación de `veth` entre namespaces |
| Apoyo — control plane en Go | ["A Deep Dive into Kubernetes Controllers"](https://engineering.bitnami.com/articles/a-deep-dive-into-kubernetes-controllers.html) (Bitnami) | Alta | Reflector/Informer/WorkQueue de `client-go` con código Go real |
| Referencia formal | [Kubernetes Docs — Concepts/Architecture](https://kubernetes.io/docs/concepts/architecture/) | Alta | Oficial, CNCF |

**Ruta sugerida (3-4 semanas):** De proceso a Pod (Ian Lewis) → Plano de control distribuido → Red sin magia (Arthur Chiao) → Kubernetes the Hard Way.

### Cloud AWS

| Recurso | Tipo |
|---|---|
| [AWS Skill Builder](https://skillbuilder.aws) | Cursos oficiales gratuitos + labs |
| [AWS Ramp-Up Guide: Data Engineer](https://aws.amazon.com/training/ramp-up-guides/) | Ruta oficial de arquitectura y datos |
| [freeCodeCamp — AWS Certified Cloud Practitioner](https://www.youtube.com/watch?v=NhDYbskXRgc) | Video 4h gratuito de fundamentos |
| [AWS Academy](https://aws.amazon.com/training/awsacademy/) | Vía universidad: Learner Lab + vouchers de certificación |

**Certificaciones sugeridas:** CLF-C02 (Cloud Practitioner) → SAA-C03 (Solutions Architect Associate) → DEA-C01 (Data Engineer Associate).

---

## ESPECIALIZACIÓN C — Mobile Multiplataforma (Post-Graduación)

- **Tecnologías:** Kotlin + Compose Multiplatform (KMP), Ktor Client, SQLDelight, Koin.
- **Foco:** Construir un cliente móvil multiplataforma (Android e iOS) moderno, reactivo y Offline-First sobre los backends construidos en Go.
- **Estado:** Pendiente de verificación formal en `SOURCES.md` (roadmap futuro).

---

## Próximos pasos (actualizado)

- [x] RAG/Embeddings removido de scope — cubierto en el roadmap paralelo de AI Engineering (F2: `doc-rag`, pgvector, chunking)
- [x] Roadmap reestructurado en Modelo de Dos Etapas: Etapa 1 Pre-Graduación (F1 a F5 + Buffer de 15 semanas) y Etapa 2 Post-Graduación (Especializaciones A, B y C)
- [ ] Al llegar a F2 en la práctica: validar la integración de `pgx` y `sqlc` en `taskapi`
- [ ] Al llegar a F3 en la práctica: validar Redis rate limiting con scripts Lua y tracing con OpenTelemetry
- [ ] Al llegar a F4 en la práctica: completar los Retos 1 al 4 de Fly.io Gossip Glomers en Go
- [ ] Al llegar a F5 en la práctica: aplicar primero por el canal gratuito de Silver.dev antes de evaluar programas pagos; preparar historias STAR grabadas
- [ ] En Especialización B (post-graduación): validar la ejecución de Kubernetes the Hard Way sobre VMs locales
