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

## F4 — Python para Data Engineering + Kafka + dbt/DuckDB + Arquitecturas de Datos

### Python para Data Engineering

Objetivo: no repetir fundamentos (ya los tenés de Go), sino cubrir lo idiomático de
Python que un pipeline en producción realmente usa — generators, context managers,
excepciones, type hints, testing y empaquetado moderno.

| Rol                      | Recurso                                                                                                                                                                                                                                                                                                                  | Confianza | Notas                                                                                                                                                                                                                                                                                       |
| ------------------------ | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ | --------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Principal                | [Practical Python Programming](https://dabeaz-course.github.io/practical-python/Notes/Contents.html) (David Beazley)                                                                                                                                                                                                     | Alta      | **Verificado hoy:** gratis, CC-BY-SA-4.0, repo activo (10k+ estrellas, último push 2024). Ambas IAs coinciden en que es el mejor punto de entrada. Foco en Secciones 2-4 (organización, clases, excepciones) y 6-7 (generators, temas avanzados)                                            |
| Referencia               | [Documentación oficial de Python — tutorial](https://docs.python.org/3/tutorial/)                                                                                                                                                                                                                                        | Alta      | Pensado para gente que ya sabe programar (no principiantes absolutos), encaja bien viniendo de Go. Priorizar: Functions, Modules, I/O, Errors and Exceptions, Classes, Virtual Environments                                                                                                 |
| Referencia (complemento) | [`contextlib`](https://docs.python.org/3/library/contextlib.html), [`typing`](https://docs.python.org/3/library/typing.html), [`datetime`](https://docs.python.org/3/library/datetime.html) + [`zoneinfo`](https://docs.python.org/3/library/zoneinfo.html), [`asyncio`](https://docs.python.org/3/library/asyncio.html) | Alta      | Context managers, `Protocol` (equivalente a interfaces de Go), fechas timezone-aware, y lo básico de async/await para I/O concurrente (APIs, DB)                                                                                                                                            |
| Arquitectura/diseño      | [Architecture Patterns with Python ("Cosmic Python")](https://www.cosmicpython.com/book/preface.html)                                                                                                                                                                                                                    | Alta      | **Verificado hoy:** versión web gratuita bajo CC sigue activa (repo `cosmic-python-book`); la versión O'Reilly impresa es paga, pero el contenido completo está online gratis. Repository Pattern y Unit of Work se mapean directo desde `interfaces` de Go a `typing.Protocol` / `abc.ABC` |
| Testing                  | [pytest — documentación oficial](https://docs.pytest.org/en/stable/)                                                                                                                                                                                                                                                     | Alta      | Fixtures, parametrización, `monkeypatch`, mocks. Probar por _etapas del pipeline_ (parser → validator → transformer → loader), no solo funciones sueltas                                                                                                                                    |
| Empaquetado              | [Python Packaging User Guide](https://packaging.python.org/) → luego [uv](https://docs.astral.sh/uv/)                                                                                                                                                                                                                    | Alta      | Empezar con `venv`+`pip` para entender lo básico, migrar a `uv` (`pyproject.toml` + `uv.lock`) para proyectos nuevos. Es la herramienta que recomienda el ecosistema actualmente sobre Poetry para proyectos nuevos                                                                         |
| Proyecto de cierre       | [Data Engineering Zoomcamp — Módulo 1](https://github.com/DataTalksClub/data-engineering-zoomcamp) (ingesta con Python + Docker + Postgres)                                                                                                                                                                              | Alta      | Ver tabla de Kafka/dbt abajo — mismo repo cubre varias fases. Módulo 1 es standalone: API pública → chunks con pandas/generators → Postgres en Docker                                                                                                                                       |

**Ruta sugerida (5 semanas, ~4h/semana):**

1. **S1 — Núcleo idiomático:** Practical Python secciones 2-4 + docs oficiales (módulos,
   excepciones). Proyecto: lector de CSV/JSON con clases pequeñas y type hints.
2. **S2 — Generators y recursos:** Practical Python sección 6 + `contextlib`. Proyecto:
   pipeline que procesa un archivo grande línea por línea sin cargarlo entero en memoria.
3. **S3 — APIs y fechas:** cliente HTTP (`httpx` o `requests`) con timeout/reintentos/paginación;
   `datetime` + `zoneinfo` (todo en UTC internamente). Proyecto: extraer de una API pública y
   cargar en Postgres.
4. **S4 — Testing y arquitectura:** pytest (fixtures, parametrize, monkeypatch) + capítulos 1-2
   de Cosmic Python (Domain Modeling, Repository Pattern). Tests de integración contra Postgres
   en Docker.
5. **S5 — Async y empaquetado:** `asyncio` básico (cuándo vale la pena para I/O-bound), migrar el
   proyecto a `pyproject.toml` + `uv`. Cerrar con el Módulo 1 del Zoomcamp como proyecto integrador.

---

### Kafka / Streaming

| Rol                             | Recurso                                                                                                                                                                                              | Confianza  | Notas                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
| ------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Principal (curso)               | [Confluent Developer — Apache Kafka 101](https://developer.confluent.io/courses/apache-kafka/events/) + Kafka Streams 101 + ksqlDB 101                                                               | Alta       | Coinciden ambas IAs y la comunidad (`r/apachekafka`). Gratis sin muro de pago, sin necesidad de crear cuenta para el contenido teórico; los labs interactivos sí pueden empujar hacia Confluent Cloud — usar el Quickstart oficial (abajo) para la parte hands-on local                                                                                                                                                                                          |
| Apoyo (CLI, sin Java)           | [Conduktor Kafkademy](https://www.conduktor.io/kafka/)                                                                                                                                               | Media-alta | No verificado con búsqueda dedicada hoy (solo viene de una de las dos IAs), pero coincide con el perfil: contenido teórico y de CLI agnóstico al lenguaje, sin forzar Java. Ojo: promociona su propia herramienta gráfica comercial (Conduktor Desktop) en algunas páginas — ignorar esa parte                                                                                                                                                                   |
| Práctica local (oficial)        | [Apache Kafka Quickstart](https://kafka.apache.org/quickstart/)                                                                                                                                      | Alta       | **Verificado hoy:** la versión actual de Kafka es la **4.x** (Kafka 4.0 salió en octubre 2024 y **eliminó ZooKeeper por completo** — KRaft es el único modo soportado desde entonces). Cualquier tutorial que enseñe a levantar ZooKeeper junto a Kafka está desactualizado, aunque sea de 2023                                                                                                                                                                  |
| Referencia densa (arquitectura) | [Kafka: The Definitive Guide, 2ª ed.](https://www.confluent.io/resources/ebook/kafka-the-definitive-guide/)                                                                                          | Media      | Gratis vía formulario de contacto de Confluent (ambas IAs lo confirman). Es de 2021 — cubre bien diseño, replicación y arquitectura interna (relevante para tu perfil de C/OS), pero los ejemplos de configuración pueden no reflejar Kafka 4.x/KRaft al 100%. Código de cliente mayormente en Java: para Go, mapear conceptualmente a `segmentio/kafka-go` o `confluent-kafka-go` (este último envuelve `librdkafka` en C, el puente más directo desde tu base) |
| Referencia (sistemas)           | [Documentación oficial — sección Design](https://kafka.apache.org/documentation/#design)                                                                                                             | Alta       | Citada por ambas IAs como uno de los mejores textos de ingeniería de sistemas distribuidos disponibles gratis. Conecta directo con tu base de C/Linux: log append-only en disco, `sendfile` (zero-copy), page cache del kernel, particiones                                                                                                                                                                                                                      |
| Ensayo fundacional              | Jay Kreps — [The Log: What every software engineer should know...](https://engineering.linkedin.com/distributed-systems/log-what-every-software-engineer-should-know-about-real-time-datas-unifying) | Alta       | **Verificado hoy:** el enlace sigue activo. Escrito en 2013 por el cocreador de Kafka — el porqué conceptual (log como abstracción unificadora) antes de tocar código. Lectura corta, muy citada en HN como lectura obligatoria previa a escribir la primera línea de Kafka                                                                                                                                                                                      |
| Práctica integrada              | [Data Engineering Zoomcamp — módulo de Kafka](https://github.com/DataTalksClub/data-engineering-zoomcamp)                                                                                            | Alta       | Módulo activo en el syllabus 2026 (producer/consumer, particionado, replicación, Kafka Streams, ksqlDB, schemas con Avro). Útil para integrar Kafka con Postgres/Docker en un pipeline end-to-end en vez de dejarlo aislado                                                                                                                                                                                                                                      |

**Ruta sugerida (6 semanas, ~4h/semana):**

1. **S1 — Modelo mental:** Kafka 101 (Confluent) + "The Log" de Kreps. Log distribuido,
   topics, particiones, brokers, diferencia con una cola tradicional (AMQP/RabbitMQ).
2. **S2 — Producer/consumer:** particionamiento por key, offsets, consumer groups,
   rebalanceo. Ejercicios de Kafka 101 + repetir el Quickstart oficial con Docker local (KRaft).
3. **S3 — Persistencia y garantías de entrega:** retención, replicación, `acks`,
   idempotencia, at-least-once vs. exactly-once. Leer los capítulos correspondientes de
   _The Definitive Guide_ + la sección Design de la documentación oficial.
4. **S4 — Integración:** Kafka Connect (source/sink), Schema Registry, Avro/JSON.
   Proyecto chico: archivo → Kafka → Postgres.
5. **S5 — Go nativo:** producer y consumer propios en Go (`segmentio/kafka-go` o
   `confluent-kafka-go`), manejo de errores/timeouts/reintentos, comparar contra la CLI.
6. **S6 — Proyecto final:** pipeline `API/archivo → producer Go → topic con varias
particiones → consumer group (2+ consumers) en Go → Postgres`, con commit manual de
   offsets, reintentos, dead-letter topic y Docker Compose reproducible.

---

### Analytics Engineering — dbt + DuckDB

| Rol                            | Recurso                                                                                                                      | Confianza  | Notas                                                                                                                                                                                                                                                                                                                                          |
| ------------------------------ | ---------------------------------------------------------------------------------------------------------------------------- | ---------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Principal (curso guiado)       | [Quickstart dbt Core v1 con DuckDB + Jaffle Shop](https://docs.getdbt.com/guides/duckdb)                                     | Alta       | Coincide en ambas IAs. Gratis, oficial, sin cuenta de warehouse cloud. Corre `seeds`, modelos, tests y docs sobre un `jaffle_shop.duckdb` local. Es la rama **estable** — preferirla sobre la guía "v2" hasta que el Fusion engine salga de alpha                                                                                              |
| Práctica local (repo)          | [jaffle_shop_duckdb](https://github.com/dbt-labs/jaffle_shop_duckdb) (repo oficial dbt-labs)                                 | Alta       | Mismo proyecto que usa el quickstart, pero como playground reutilizable — bueno para experimentar sin rehacer el tutorial completo cada vez                                                                                                                                                                                                    |
| Adaptador (referencia técnica) | [dbt-duckdb](https://github.com/duckdb/dbt-duckdb) (ahora bajo la org de GitHub de DuckDB)                                   | Alta       | Apache-2.0, activo. Documenta cómo leer directo desde S3/R2/Parquet remoto vía `profiles.yml` — asume que ya entendés los conceptos básicos de dbt, no es para el primer contacto                                                                                                                                                              |
| DuckDB — referencia            | [DuckDB Guides](https://duckdb.org/docs/current/guides/overview)                                                             | Alta       | Cubre CSV/JSON/Parquet, HTTP/S3, Postgres, **API de Go** (además de Python/C/C++) — para tu perfil podés practicar consultas desde Go directamente, sin pasar por Python                                                                                                                                                                       |
| DuckDB — tutorial corto        | ["Fully Local Data Transformation with dbt and DuckDB"](https://duckdb.org/2025/04/04/dbt-duckdb.html) (blog oficial DuckDB) | Media-alta | Artículo técnico con modelo dimensional completo (hechos/dimensiones), materializations `table`/`incremental`/`snapshot`/`external`, reverse ETL a Postgres. Denso — no es para el primer contacto, mejor como proyecto de la semana 4-5                                                                                                       |
| Buenas prácticas               | [dbt — How we style our dbt projects](https://docs.getdbt.com/best-practices/how-we-style/6-how-we-style-conclusion)         | Alta       | Referencia canónica de la industria para estructurar `staging/intermediate/marts` y no terminar con SQL caótico                                                                                                                                                                                                                                |
| Práctica integrada             | [Data Engineering Zoomcamp — módulo de Analytics Engineering](https://github.com/DataTalksClub/data-engineering-zoomcamp)    | Alta       | Módulo 4 del syllabus 2026 usa dbt con DuckDB y BigQuery. No usarlo como primer recurso (mete Docker/BigQuery en el medio) — sí como cierre integrador                                                                                                                                                                                         |
| SQL de base (si hace falta)    | [SQLShed](https://sqlshed.com/)                                                                                              | Baja       | Solo lo trae una de las dos IAs y **ninguna encontró testimonios independientes** de gente que lo haya usado (lo marcan explícitamente como NO VERIFICADO). Motor DuckDB en el navegador, sin instalación. Usar solo si hace falta repasar SQL analítico puro antes de meterse con dbt — no es prioritario dado que ya tenés pgexercises de F2 |

**Ruta sugerida (5 semanas, ~4h/semana):**

1. **S1 — DuckDB básico:** CLI, bases persistentes vs. en memoria, consultar CSV/Parquet,
   `GROUP BY`/joins/window functions/`EXPLAIN`.
2. **S2 — Datos externos:** leer JSON/Parquet/HTTP directo con DuckDB, tipos y nulls.
3. **S3 — dbt local:** instalar dbt Core v1 + `dbt-duckdb`, `profiles.yml`, modelos
   staging/marts, `dbt run`/`dbt test`/`dbt build`/`dbt docs`.
4. **S4 — Calidad y modelado:** `source()`, `ref()`, tests (`unique`, `not_null`,
   `relationships`, `accepted_values`), seeds, macros, materializations (`view`, `table`,
   `incremental`).
5. **S5 — Proyecto de portfolio:** `CSV/Parquet → DuckDB raw → staging → intermediate →
marts → Parquet/Postgres`, con al menos 5 modelos, tests, docs, un modelo incremental,
   y opcionalmente una utilidad de ingesta propia en Go.

---

### Arquitecturas de datos (Lambda / Kappa)

| Rol                                    | Recurso                                                                                                                                                          | Confianza | Notas                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
| -------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------- | --------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Fuente primaria (Kappa)                | Jay Kreps — ["Questioning the Lambda Architecture"](https://www.oreilly.com/radar/questioning-the-lambda-architecture/) (2014)                                   | Alta      | Coincide en ambas IAs. El artículo donde el cocreador de Kafka propone Kappa como alternativa más simple a Lambda — la principal falla que señala es mantener dos bases de código (batch y stream) para la misma lógica                                                                                                                                                                                                                                                |
| Fuente primaria (base técnica)         | Jay Kreps — ["The Log"](https://engineering.linkedin.com/distributed-systems/log-what-every-software-engineer-should-know-about-real-time-datas-unifying) (2013) | Alta      | Ya la tenías en la sección de Kafka — se reutiliza acá porque es la base técnica exacta que explica por qué Kappa funciona (log inmutable + replay = reprocesamiento sin duplicar lógica)                                                                                                                                                                                                                                                                              |
| Fuente primaria (Lambda)               | Nathan Marz — post original ["How to beat the CAP theorem"](http://nathanmarz.com/blog/how-to-beat-the-cap-theorem.html)                                         | Media     | El post de blog gratuito donde Marz introduce la idea antes de convertirla en libro. El libro _Big Data_ (Manning, 2015) es **pago** — confirmé que Manning solo ofrece vista previa parcial de capítulos individuales (no el libro completo gratis, aunque una de las IAs lo daba por hecho); el post + los artículos de síntesis de abajo alcanzan sin comprarlo                                                                                                     |
| Síntesis corta (Lambda)                | Ericsson — [Data processing architectures: Lambda and Kappa](https://www.ericsson.com/en/blog/2015/11/data-processing-architectures--lambda-and-kappa)           | Media     | De 2015 (viejo para el estándar del resto del documento), pero el patrón conceptual que explica —por qué Lambda sigue teniendo sentido cuando el batch necesita algoritmos distintos al streaming— es estable y agnóstico a herramientas                                                                                                                                                                                                                               |
| Síntesis actual (Kappa)                | Materialize — [Does Kappa architecture improve on Lambda?](https://materialize.com/blog/does-kappa-architecture-improve-on-lambda/)                              | Media     | Artículo de 2026 de una empresa con interés comercial en streaming (sesgo a tener en cuenta), pero trae la discusión actualizada sobre replay, estado y eventos fuera de orden que Ericsson no cubre                                                                                                                                                                                                                                                                   |
| **Descartado — verificado hoy**        | _Streaming Systems_ (Akidau, Chernyak, Lax — O'Reilly, 2018)                                                                                                     | —         | **No es gratis.** Confirmé que es un libro comercial de O'Reilly (349 páginas, sin versión completa legal gratuita). Lo que sí es gratis y es la base de la que salió el libro: los artículos originales **["Streaming 101"](https://www.oreilly.com/radar/the-world-beyond-batch-streaming-101/) y "Streaming 102"** de Tyler Akidau en O'Reilly Radar — cubren watermarks, event time vs. processing time y windowing, que es lo que necesitás de ahí para este tema |
| Práctica integrada                     | [Data Engineering Zoomcamp — módulo de Streaming](https://github.com/DataTalksClub/data-engineering-zoomcamp)                                                    | Alta      | Coincide en ambas IAs. No enseña Lambda/Kappa como curso lineal — te da las piezas (Kafka, ventanas, a veces Flink/PyFlink) para armar y comparar ambas arquitecturas vos mismo con un proyecto propio                                                                                                                                                                                                                                                                 |
| Referencia (motor Kappa en producción) | [Apache Flink — Concepts](https://nightlies.apache.org/flink/flink-docs-stable/docs/concepts/overview/)                                                          | Alta      | El motor que hizo viable Kappa en producción real (event time, watermarks, checkpoints). APIs en Java/Scala, soporte secundario en Python — no hay necesidad de aprenderlo a fondo ahora, alcanza con los conceptos                                                                                                                                                                                                                                                    |

**Nota:** este es el tema más "teórico" de F4 — el objetivo es poder razonar sobre
trade-offs (latencia vs. complejidad vs. reprocesamiento histórico) en una entrevista o
en una decisión de diseño, no construir algo desde cero. Por eso no tiene curso
dedicado ni ruta semana a semana propia: se resuelve leyendo los 4-5 artículos de la
tabla y, sobre todo, con el proyecto comparativo de abajo.

---

## F5 — System Design + Patrones de Arquitectura + DDD + Kubernetes (conceptual)

**Decisión de scope tomada al planificar esta fase:** se descartó una sección propia de
"Design Patterns" estilo Gang of Four. En Go estos patrones pesan mucho menos que en
Java/C# (el lenguaje favorece composición e interfaces implícitas sobre herencia), y
parte del terreno ya se cubrió con Repository Pattern/Unit of Work en Cosmic Python
(F4). En su lugar, los patrones idiomáticos de Go que cumplen ese rol (Functional
Options, Strategy vía interfaces, Decorator vía middleware/embedding) quedan como nota
breve dentro del bloque de Arquitectura, no como ruta de estudio propia.

---

### System Design

| Rol                               | Recurso                                                                                                                                         | Confianza | Notas                                                                                                                                                                                                                                                               |
| --------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------- | --------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Principal — práctica dura         | [MIT 6.5840 (Distributed Systems)](https://pdos.csail.mit.edu/6.824/)                                                                           | Alta      | Coincide en ambas IAs, ambas la llaman "gold standard". Labs 100% en Go (MapReduce, Raft, KV service tolerante a fallos, sharded KV con balanceo dinámico). Material completamente público, sin paywall — solo la evaluación oficial es exclusiva de alumnos de MIT |
| Principal — retos con validación  | [Fly.io Distributed Systems Challenges (Gossip Glomers)](https://fly.io/dist-sys/)                                                              | Alta      | 6 retos con validación automática de consistencia (Maelstrom, del creador de Jepsen). SDK de referencia nativo en Go, coste de adaptación ~0%. Requiere JDK instalado para correr el orquestador Clojure de Maelstrom, dato menor a tener en cuenta                 |
| Apoyo — vocabulario/entrevista    | [System Design Primer](https://github.com/donnemartin/system-design-primer)                                                                     | Alta      | Coincide en ambas IAs. No es un curso lineal, es un compendio de referencia + casos resueltos (Pastebin, Twitter timeline, web crawler) + flashcards Anki. Bueno para la cadencia de una entrevista, no para profundidad de implementación                          |
| Apoyo — patrones internos         | [Catalog of Patterns of Distributed Systems](https://martinfowler.com/articles/patterns-of-distributed-systems/) (Unmesh Joshi / Martin Fowler) | Alta      | Desarma la "magia" de cómo están hechos por dentro Kafka, Cassandra, etcd (WAL, Leader-Follower, Quorum, Idempotent Receiver). Ejemplos en Java pero a nivel de socket/disco/buffer, mapea directo a Linux/Go                                                       |
| Referencia — operación real       | [Google SRE Book](https://sre.google/sre-book/)                                                                                                 | Alta      | No es un curso de entrevista, es sobre cómo se opera en producción a escala (SLOs, error budgets, monitoring). Complementa bien tu base de observabilidad de F3                                                                                                     |
| Referencia — papers fundacionales | Dynamo, GFS, Bigtable (papers originales de Amazon/Google, libres)                                                                              | Alta      | Lectura densa pero son el origen real de los patrones que se enseñan en todos los cursos de arriba — vale la pena para el nivel de profundidad que ya tenés                                                                                                         |

**Ruta sugerida (10-12 semanas, ~10-12h/semana):**

1. **S1-2 — Fundamentos y estimaciones:** back-of-the-envelope, load balancing L4 vs L7,
   caching (write-through, cache-aside), particionado (range/hash/consistent hashing).
   Material: System Design Primer.
2. **S3-5 — Consistencia y replicación en Go:** CAP/PACELC real, leader/follower vs.
   multi-leader vs. sin líder, CRDTs, gossip protocols. Práctica: retos 1-4 de Fly.io.
3. **S6-8 — Mensajería, logs distribuidos y consenso:** WAL, semánticas de entrega
   (at-least-once, idempotent receiver), Raft. Práctica: retos 5-6 de Fly.io o Labs 1-2
   de MIT 6.5840 (esto conecta directo con Kafka de F4).
4. **S9-10 — APIs robustas a escala:** rate limiting distribuido (token bucket/leaky
   bucket sobre Redis), idempotencia, circuit breakers a nivel de gateway, Sagas vs. 2PC.
5. **S11-12 — Simulacros de entrevista:** 6-8 casos clásicos cronometrados (45 min),
   foco en trade-offs (latencia vs. consistencia, escala vertical vs. horizontal).

---

### Patrones de Arquitectura de Software

| Rol                           | Recurso                                                                                                                                              | Confianza  | Notas                                                                                                                                                                                                                                                                                                                    |
| ----------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------- | ---------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| Principal — código real en Go | [Wild Workouts (Three Dots Labs)](https://github.com/ThreeDotsLabs/wild-workouts-go-ddd-example)                                                     | Alta       | **Verificado hoy:** repo real y activo, con la serie completa de artículos de refactorización progresiva (de "app demasiado moderna" a Clean Architecture + CQRS). Integra gRPC, HTTP/OpenAPI y eventos con Watermill — correrlo completo en local exige Docker                                                          |
| Apoyo — estructura comparada  | [go-structure-examples](https://github.com/katzien/go-structure-examples) (Kat Zien, charla GopherCon)                                               | Alta       | **Verificado hoy:** real, mismo servicio de juguete implementado bajo 4 filosofías (flat, layered, hexagonal, domain-driven) para comparar directamente. **De 2018-2019, sin actualizaciones desde entonces** — el contenido (estructura de carpetas) envejece lento, pero hay que marcarlo como desactualizado en fecha |
| Apoyo — EDA/CQRS conceptual   | Martin Fowler — ["What do you mean by Event-Driven?"](https://martinfowler.com/articles/201701-event-driven.html) + artículos de CQRS/Event Sourcing | Alta       | Antídoto contra usar CQRS/Event Sourcing por defecto en vez de como herramienta especializada. Taxonomía de 4 tipos de evento que es estándar citado en la industria                                                                                                                                                     |
| Referencia — patrones cloud   | [Microsoft Azure Architecture Center — Patterns](https://learn.microsoft.com/en-us/azure/architecture/patterns/)                                     | Alta       | Ya la tenías parcialmente de F3 (Circuit Breaker) — se reutiliza acá para CQRS, Event Sourcing, Compensating Transaction, Throttling. Agnóstico a Go, sin código, solo definiciones y trade-offs                                                                                                                         |
| Referencia — monolito modular | [Modular Monolith with DDD](https://github.com/kamilgrzybek/modular-monolith-with-ddd) (Kamil Grzybek)                                               | Media-alta | Implementación de referencia en C#/.NET, pero sin "magia" de framework — Outbox pattern transaccional y segregación de esquemas SQL mapean línea por línea a Postgres/Go. Útil si te interesa monolito modular vs. microservicios prematuros                                                                             |
| Referencia — diseño de APIs   | [Microsoft REST API Guidelines](https://github.com/microsoft/api-guidelines) + [Google API Design Guide](https://cloud.google.com/apis/design)       | Alta       | Estándares battle-tested para versionado, paginación por cursor, idempotencia, errores canónicos. Aplicarlos completos a un microservicio de 2 endpoints es excesivo — usarlos como checklist, no como dogma                                                                                                             |

**Nota técnica — patrones idiomáticos de Go (reemplazo del catálogo GoF, tal como se
acordó no darle sección propia):**

- **Functional Options** (reemplaza Builder/constructores sobrecargados): `type Option
func(*Server)`, permite `NewServer(addr, WithTimeout(5*time.Second))` con defaults
  seguros.
- **Strategy vía interfaces implícitas**: cualquier struct/función que satisfaga una
  interfaz de un solo método (como `io.Reader`) actúa como estrategia intercambiable,
  sin árboles de herencia.
- **Decorator vía middleware/embedding**: el patrón estándar `func(http.Handler)
http.Handler` en HTTP/gRPC, o struct embedding para envolver una interfaz y añadir
  métricas/logs/caché.
- **Interfaces definidas en el consumidor, no en el productor**: a diferencia de
  Java/C#, en Go idiomático el paquete de dominio declara `type UserSaver interface {
SaveUser(...) error }` con solo lo que necesita — desacopla sin mocks gigantescos.

**Ruta sugerida (6-8 semanas, ~10-12h/semana):**

1. **S1-2 — Hexagonal/Clean Architecture en Go:** estudiar `go-structure-examples`
   (comparar carpeta `hexagonal` vs. `module`) + primeros artículos de Wild Workouts.
   Práctica: refactorizar un CRUD propio separando dominio de adaptadores (Postgres,
   Chi/Gin).
2. **S3-4 — Monolito modular vs. microservicios:** diagramas C4/ADRs de Modular
   Monolith Primer. Práctica: simular comunicación entre módulos con interfaces de
   paquetes internos (`internal/pkg/...`) antes de saltar a red.
3. **S5-6 — Event-Driven, CQRS y Event Sourcing:** ensayo de Fowler + eventos en Wild
   Workouts con Watermill. Identificar el umbral real donde CQRS deja de ser
   sobre-ingeniería.
4. **S7-8 — Diseño de APIs y contratos:** guías de Microsoft/Google. Práctica: diseñar
   un contrato gRPC (.proto) + uno REST/OpenAPI, implementar middleware de idempotencia
   con `Idempotency-Key` en Redis.

---

### Domain-Driven Design (DDD)

| Rol                                  | Recurso                                                                                                                                                                                                          | Confianza  | Notas                                                                                                                                                                                                                                                                                                                                    |
| ------------------------------------ | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Principal — táctico en Go            | [Practical DDD in Go / DDD Lite (Three Dots Labs)](https://threedots.tech/) — series `ddd-lite-in-go`, `repository-pattern-in-go`, `basic-cqrs-in-go`                                                            | Alta       | Mismo ecosistema que Wild Workouts (arquitectura). Refactors reales de problemas de dominio (reservas, bloqueo de inventario) de modelo anémico a modelo rico con invariantes protegidas                                                                                                                                                 |
| Principal — diseño estratégico       | [DDD-Crew — Bounded Context Canvas](https://github.com/ddd-crew/bounded-context-canvas) + [Context Mapping](https://github.com/ddd-crew/context-mapping)                                                         | Alta       | Plantillas abiertas (CC/MIT) ampliamente adoptadas en conferencias (DDD Europe, GOTO). Cubren Shared Kernel, Customer-Supplier, Conformist, Anti-Corruption Layer — el diseño estratégico que los libros pagos cobran caro                                                                                                               |
| Referencia — filosofía y lecciones   | ["Domain-Driven Design: The First 15 Years"](https://leanpub.com/ddd_first_15_years) (ensayos, Leanpub)                                                                                                          | Alta       | **Verificado hoy:** precio mínimo real $0.00 ("Free!"), sin tarjeta. Ensayos genuinos de Fowler, Coplien, Vladik Khononov, Alberto Brandolini y otros. Los propios creadores de DDD reconocen que la comunidad se obsesionó con patrones tácticos (repos, fábricas) y descuidó el diseño estratégico — lectura de criterio, no de código |
| Referencia extra (hallazgo propio)   | ["The Anatomy of Domain-Driven Design"](https://leanpub.com/theanatomyofdomain-drivendesign) (Scott Millett, Leanpub) — y la ["DDD Referenz"](https://leanpub.com/ddd-referenz) escrita por el propio Eric Evans | Alta       | **Verificado hoy:** ambos gratis bajo el mismo modelo pay-what-you-want de Leanpub ($0.00 mínimo). La "Referenz" en particular es un resumen corto escrito por el creador original de DDD — buen complemento de una página para tener a mano                                                                                             |
| Apoyo — modelado completo con código | [DDD by Examples: Library](https://github.com/ddd-by-examples/library) (DDD-Crew)                                                                                                                                | Media-alta | Muestra el proceso completo: tableros de Event Storming, Context Maps, ADRs, y código. El código está en Java/Spring, pero ~70% del valor (diagramas, mapas de contexto) es agnóstico y transferible a Go                                                                                                                                |
| Apoyo — package layout pragmático    | Ben Johnson — ["Standard Package Layout"](https://medium.com/@benbjohnson/standard-package-layout-7cd488332d16)                                                                                                  | Alta       | Artículo fundacional (citado en la wiki oficial de Go) que aplica DDD de forma pragmática sin usar la jerga formal — domain models en el paquete raíz, adaptadores en subpaquetes                                                                                                                                                        |
| Referencia adicional (índice)        | [DDD-Crew — Free DDD Learning Resources](https://github.com/ddd-crew/free-ddd-learning-resources)                                                                                                                | Alta       | Colección curada oficial de la organización DDD-Crew — buen punto de partida si alguno de los recursos de arriba no termina de encajar                                                                                                                                                                                                   |

**Mapeo mental DDD → Go** (tabla de referencia rápida, útil tenerla a mano):

| Concepto DDD          | Equivalente en Go                                                       | Regla                                                                                                                                            |
| --------------------- | ----------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------ |
| Value Object          | Struct inmutable por convención                                         | Sin punteros ni mutadores; se pasa por valor, igualdad por comparación de campos (`m1 == m2`)                                                    |
| Entity                | Struct con ID explícito                                                 | El ID es inmutable; dos entidades son iguales solo si el ID coincide, aunque cambie el resto                                                     |
| Aggregate Root        | Struct con campos **no exportados**                                     | Ningún paquete externo puede mutar directo; toda mutación pasa por métodos exportados (`func (o *Order) Pay(...) error`)                         |
| Domain Event          | Struct simple con timestamp + payload                                   | Se acumula en una slice interna del agregado y se despacha tras persistir con éxito (conecta con el patrón Outbox de la sección de Arquitectura) |
| Repository            | `interface` definida en el **consumidor** (dominio), no en el productor | Solo métodos del agregado completo: `Get(ctx, id)`, `Save(ctx, *Order)` — nunca filtrar por columnas de la DB desde el dominio                   |
| Anti-Corruption Layer | Paquete adaptador con función traductora pura                           | `func toDomain(dto ExternalUserDTO) (User, error)` — transforma antes de que el DTO externo cruce al dominio                                     |

**Ruta sugerida (5-6 semanas, ~10-12h/semana):**

1. **S1 — Estratégico, Bounded Contexts, Lenguaje Ubicuo:** canvas de DDD-Crew +
   primeros ensayos de "The First 15 Years". Práctica: analizar los diagramas de
   contexto de DDD by Examples: Library.
2. **S2 — Táctico: Value Objects y Entidades:** evitar la "obsesión por primitivos".
   Práctica en Go: implementar un Value Object `Money` o `EmailAddress` (struct
   inmutable, constructor validante, comparación, operaciones que retornan nuevas
   instancias).
3. **S3 — Agregados y fronteras transaccionales:** regla de Evans — un agregado se
   modifica dentro de una única transacción. Práctica: modelar `Order` con
   `OrderItem`s, exponiendo solo métodos de negocio (`order.AddItem(...)`).
4. **S4 — Repositorios, Unit of Work y ACL:** diferencia entre Repository de dominio y
   DAO de base de datos. Práctica: interfaz `OrderRepository` en el dominio + adaptador
   Postgres que hidrata el agregado sin exponer campos privados.
5. **S5-6 — Domain Events y desacoplamiento asíncrono:** despacho en memoria vs.
   Transactional Outbox hacia Kafka/Watermill (conecta directo con Kafka de F4).
   Práctica: extender el agregado para registrar eventos y conectar con una tabla
   outbox.

---

### Kubernetes (conceptual)

| Rol                              | Recurso                                                                                                                                                                                                                                                                            | Confianza | Notas                                                                                                                                                                                                                                                                                                                                                                             |
| -------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | --------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Principal — mecánica del sistema | [Kubernetes the Hard Way](https://github.com/kelseyhightower/kubernetes-the-hard-way) (Kelsey Hightower)                                                                                                                                                                           | Alta      | **Verificado hoy:** licencia real **Apache 2.0** (no CC BY-NC-SA como afirmó una de las dos fuentes — corregido). 14 labs manuales: PKI/TLS, bootstrapping de etcd en HA, binarios del control plane vía `systemd`, `containerd` como runtime OCI. Documenta pasos originalmente sobre GCP — adaptable 100% a VMs locales (KVM/libvirt/VirtualBox) sin gastar crédito de nube     |
| Apoyo — de proceso Linux a Pod   | Ian Lewis — ["What are Kubernetes Pods anyway?"](https://www.ianlewis.org/en/what-are-kubernetes-pods-anyway) (serie de 4 partes)                                                                                                                                                  | Alta      | Autor identificable (ex Staff Developer Advocate, Google Cloud). Construye un "Pod" a mano con `unshare(1)`/`setns(2)` sin tener Kubernetes instalado — cierra exactamente la brecha entre "contenedor" y "Pod" para alguien que ya conoce `clone(2)`                                                                                                                             |
| Apoyo — red a bajo nivel         | Arthur Chiao — ["Kubernetes Networking: Behind the Scenes"](https://arthurchiao.art/blog/k8s-net-journey/) y artículos relacionados                                                                                                                                                | Alta      | Conecta `Service`/ClusterIP con reglas DNAT de iptables/IPVS y manipulación de `veth` entre namespaces — denso, requiere el stack de red de Linux que ya tenés de F1                                                                                                                                                                                                              |
| Apoyo — control plane en Go      | ["A Deep Dive into Kubernetes Controllers"](https://engineering.bitnami.com/articles/a-deep-dive-into-kubernetes-controllers.html) (Bitnami) + [docs de diseño oficiales](https://github.com/kubernetes/community/blob/master/contributors/devel/sig-api-machinery/controllers.md) | Alta      | Explica Reflector/Informer/WorkQueue de `client-go` con código Go real — el patrón detrás de cualquier Controller/Operator                                                                                                                                                                                                                                                        |
| Referencia formal                | [Kubernetes Docs — Concepts/Architecture](https://kubernetes.io/docs/concepts/architecture/)                                                                                                                                                                                       | Alta      | Oficial, CNCF. Deliberadamente agnóstica al kernel de Linux — sirve para la nomenclatura estándar, no para el "por qué" a bajo nivel (eso lo dan los recursos de arriba)                                                                                                                                                                                                          |
| Descartado — verificado hoy      | `runbook.academy` y `systeminternals.dev` (recursos "principales" de una de las dos IAs consultadas)                                                                                                                                                                               | Baja      | **No se pudo corroborar su existencia/tracción independiente** con búsqueda propia — ni reseñas, ni menciones externas, ni huella más allá de lo que reporta el documento que las cita. Puede que sean sitios chicos y legítimos, pero no alcanza la barra de confianza del resto del documento. No se recomiendan como recurso principal hasta poder verificarlos en la práctica |

**Ruta sugerida (3-4 semanas, ~8-10h/semana):**

1. **S1 — La unidad atómica:** serie de Ian Lewis. Práctica: crear a mano dos
   contenedores que compartan namespace de red (`--net=container:...`) y verificar
   comunicación por `localhost`.
2. **S2 — El plano de control como sistema distribuido:** docs oficiales de
   arquitectura + Bitnami sobre Controllers/Informers. Entender la jerarquía Deployment
   → ReplicaSet → Pods y por qué solo `kube-apiserver` habla con `etcd`.
3. **S3 — Red sin magia:** artículos de Arthur Chiao. Modelo CNI, cómo `kube-proxy`
   traduce un Service a reglas de iptables/IPVS.
4. **S4 — Anatomía de un clúster real:** ejecutar (o al menos revisar en detalle)
   Kubernetes the Hard Way sobre VMs locales. Inspeccionar certificados TLS, flags de
   los binarios, manifiestos estáticos de `kubelet`.

---

## F6 — Portfolio (Backend + Data Engineering) + Entrevistas

**Nota de scope importante:** esta fase originalmente incluía RAG/Embeddings en el
roadmap general, pero ese tema **se removió** porque ya está cubierto con más
profundidad en el roadmap paralelo de AI Engineering (F2 de ese roadmap: `doc-rag`,
JSON schema enforcement, chunking, `pgvector`, búsqueda híbrida — proyecto propio con
exit criteria clara). No se duplica acá. F6 de este documento queda exclusivamente
como el cierre de la ruta de Backend + Data Engineering: **consolidar proyectos en un
portfolio real y preparación de entrevistas específicas del rubro**.

---

### Portfolio (Backend + Data Engineering)

**La regla central:** **2-3 proyectos de
alta fidelidad, no 8-10 a medias.** Los reclutadores/hiring managers técnicos escanean
en segundos: título, stack, diagrama, problema/solución en 2-3 frases, y números
(latencia, throughput, uptime) — no leen código crudo antes de decidir si entrevistar.

**Filtro para decidir qué proyecto mostrar:**

1. **¿Se levanta con un solo comando?** Si `docker compose up -d` no deja el sistema
   corriendo con métricas vivas en ~90 segundos, el proyecto "no existe" para quien lo
   evalúa.
2. **¿Muestra qué pasa cuando algo falla?** Un proyecto junior muestra el camino feliz.
   Uno mid muestra qué pasa cuando Kafka se desconecta, la DB da timeout, o cómo se
   gestiona una Dead Letter Queue con reintentos exponenciales.
3. **¿Hay un benchmark medible?** "Usé Redis para mejorar el rendimiento" es teoría.
   "El throughput pasó de 450 a 3,800 req/s con p99 cayendo de 180ms a 14ms bajo k6" es
   una entrevista asegurada.

**Mapeo concreto de tus proyectos dispersos a 2-3 "case studies":**

| Proyecto propuesto                                   | De qué ejercicios sale                                                  | Qué señal valida                                                                                                                                                             |
| ---------------------------------------------------- | ----------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Pipeline streaming (Backend/Distributed Systems)** | Tu ejercicio de Go + Postgres + Kafka de F2-F4                          | Concurrencia real, backpressure, consumer groups, garantías de entrega elegidas y justificadas (at-least-once vs. exactly-once), resiliencia (retries, circuit breaker, DLQ) |
| **Plataforma analítica (Data Engineering)**          | Tu ejercicio de dbt + DuckDB de F4                                      | Modelado dimensional, transformaciones idempotentes, tests de calidad (`dbt test`), documentación de linaje — nunca subir notebooks `.ipynb` sueltos                         |
| **(Opcional) Systems/Distributed primitive**         | El shell en C de F1, o mejor, un ejercicio de Gossip Glomers/Raft de F5 | Diferencia real frente a otros candidatos — un shell en C básico no impresiona solo, pero un nodo distribuido tolerante a fallos en Go sí                                    |

**Estructura de README que convierte (case-study, no manual de instalación):** título +
una línea de problema → 1 diagrama de arquitectura → stack → decisiones de diseño
explicadas (por qué Kafka y no una cola simple, por qué ese esquema de particionamiento)
→ métricas/resultados (throughput, p95, error rate) → cómo correrlo (3-4 comandos, no
más) → links (repo, API docs/Swagger si aplica, dashboard de Grafana o screenshots).

**Qué hacer con el resto de tus proyectos:**

- **El shell en C:** no se borra ni se descarta, pero tampoco va como proyecto
  principal en el README/CV. Se usa como **contexto narrativo en la entrevista**: "mi
  formación empezó entendiendo syscalls y gestión de memoria, lo que hoy me permite
  diagnosticar contención de goroutines sin depender de abstracciones mágicas".
- **El ejercicio comparativo Lambda vs. Kappa (de F4):** no se deja como código suelto.
  Se convierte en un **write-up técnico / architecture decision record**: diagramas de
  ambas arquitecturas, decisiones justificadas, trade-offs de costo/latencia/
  complejidad — eso vale más que 500 líneas de boilerplate.
- Ejercicios aislados de observabilidad, CI/CD, etc.: quedan como "evidencia
  secundaria" mencionada en el README de perfil, no como proyectos propios.

---

### Entrevistas (Data/Backend Engineering + Behavioral + LatAm→Remoto)

#### Contenido técnico específico de Data/Backend

| Tema                                         | Qué evalúan realmente                                                                                                                                                                                                                                      | Recurso de referencia                                                                                                                                                                                                                    |
| -------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| SQL avanzado                                 | No la sintaxis de memoria, sino el modelo mental del motor de ejecución (`FROM→WHERE→GROUP BY→HAVING→SELECT→WINDOW→ORDER BY`), window functions (`ROW_NUMBER` vs `RANK` vs `DENSE_RANK`, `LAG/LEAD`), el problema canónico "Gaps and Islands", SARGability | [Use The Index, Luke!](https://use-the-index-luke.com) (ya la tenías de F2 — se reutiliza acá como referencia de entrevista)                                                                                                             |
| Optimización / EXPLAIN ANALYZE               | Por qué Postgres elige Seq Scan vs Index Scan vs Bitmap Index Scan, algoritmos de join (Nested Loop, Hash Join, Merge Join) y cuándo aplica cada uno                                                                                                       | Práctica directa con `EXPLAIN (ANALYZE, BUFFERS)` sobre un dataset sintético de varios millones de filas                                                                                                                                 |
| Diseño de pipelines                          | Trade-offs reales batch vs. streaming (no elegir streaming "por defecto" — justificar según el SLA), manejo de datos sucios/duplicados (Write-Audit-Publish, deduplicación técnica vs. de negocio)                                                         | Conecta directo con Lambda/Kappa de F4                                                                                                                                                                                                   |
| Kafka en entrevista                          | Orden solo a nivel de partición (no orden global), qué pasa cuando `max.poll.interval.ms` expira y gatilla un rebalance, cómo lograr "effectively once" (idempotencia + outbox)                                                                            | Conecta con Kafka de F4                                                                                                                                                                                                                  |
| dbt en entrevista                            | Cuándo usar `view`/`table`/`incremental`/`ephemeral`, el problema de "late arriving facts" en modelos incrementales (ventana de lookback + `unique_key`, no solo `WHERE event_time > max(...)`)                                                            | Conecta con dbt+DuckDB de F4                                                                                                                                                                                                             |
| Plataformas de práctica con problemas reales | `StrataScratch` (freemium, ~$30/mes, estándar de la industria para live-coding de DE) y `DataDriven.io` (gratis, con guía de prep de 8-10 semanas)                                                                                                         | Confianza media — plataformas más nuevas, no verificadas independientemente más allá de lo que reportan las dos IAs, pero el contenido específico que citan (tipos de preguntas) es coherente entre ambas fuentes de forma independiente |

#### Behavioral / "Work Experience" con proyectos propios

Framework estándar: **STAR** (Situation, Task, Action, Result), con distribución de
tiempo sugerida 20/10/60/10. La clave para proyectos de estudio sin experiencia laboral
formal: contarlos igual que casos reales, con **trade-offs de ingeniería explícitos**,
no como "hice un tutorial de Kafka".

Ejemplo de estructura (usando tu propio proyecto Go+Kafka+Postgres):

- _Situation_: "Escrituras directas a PostgreSQL saturaban el pool de conexiones bajo
  cargas de 5,000 req/s."
- _Task_: "Garantizar procesamiento asíncrono con durabilidad, sin perder mensajes si
  la DB se degradaba."
- _Action_: "Introduje Kafka como buffer de absorción, diseñé un bounded worker pool en
  Go (en vez de una goroutine por evento), implementé graceful shutdown interceptando
  `SIGTERM` para drenar el buffer antes de confirmar offsets."
- _Result_: "Throughput de 450 a 3,800 req/s con p99 bajo 25ms (medido con k6/vegeta).
  Aprendí que el tamaño de commit por lotes en Postgres afecta los checkpoints del WAL."

#### Plataformas para preparación LatAm → EE.UU./Europa

**Silver.dev — veredicto de ambas IAs (convergencia genuina, no reciclada):**

- **Qué es:** agencia que conecta talento LatAm con startups de EE.UU. Fundada y
  dirigida por **Gabriel Benmergui**, ingeniero full-stack con experiencia en
  OpenSea, Robinhood, Scribd y CircleMedical.

**Alternativas (confianza media — plataformas más nuevas, no household names, pero
coherentes entre las dos fuentes):**

| Recurso                    | Tipo                                   | Costo                       | Para qué                                                                                                                     |
| -------------------------- | -------------------------------------- | --------------------------- | ---------------------------------------------------------------------------------------------------------------------------- |
| `DataDriven.io`            | Plataforma de problemas + guía de prep | Gratis                      | Columna vertebral sugerida por ambas — SQL, Python, data modeling, pipeline design con soluciones de comunidad               |
| Exponent / Aced (curso DE) | Curso estructurado con mocks           | Pago (precio no confirmado) | Si buscás estructura tipo FAANG; posible overkill si solo necesitás lo básico                                                |
| Pramp / Exponent free tier | Mock interviews P2P                    | Gratis                      | Simulacros en vivo sin costo, útil para perder el miedo a hablar en inglés bajo presión                                      |
| interviewing.io            | Mocks con ingenieros de Big Tech       | Pago ($150-250/sesión)      | Caro para junior LatAm — su canal de YouTube gratis (grabaciones de mocks y negociación salarial) es de alto valor sin pagar |
| DataExpert.io              | Blog (behavioral + negociación)        | Gratis                      | Guía completa de behavioral con estructura STAR aplicada a DE                                                                |

#### Negociación de oferta sin historial salarial previo en USD

**Fuente central, de alta confianza (ensayo clásico, ampliamente citado y verificable):**
Patrick McKenzie (patio11) — ["Salary Negotiation: Make More Money, Be More Valued"](https://www.kalzumeus.com/2012/01/23/salary-negotiation/)
y su ["Kalzumeus Podcast Ep. 12"](https://www.kalzumeus.com/2016/06/03/kalzumeus-podcast-episode-12-salary-negotiation-with-josh-doody/)
con Josh Doody.

Principios centrales:

1. **Nunca des un número primero.** Ante "¿cuáles son tus expectativas salariales?",
   redirigir a "prefiero entender el alcance del rol antes de hablar de números" — y si
   insisten, anclar con investigación de mercado en vez de con tu salario previo en
   moneda local (revelarlo es la forma más común de quedar atrapado en una banda baja).
2. **Definir 3 números antes de negociar:** aspiracional (percentil 75+), target
   (lo que realmente querés), mínimo/walk-away.
3. **Negociar por valor de mercado, no por costo de vida.** Las guías LatAm-específicas
   remarcan esto con fuerza: no justificar el número por tus gastos personales, sino
   por lo que el mercado paga para el rol.
4. **Negociar el total comp**, no solo el base (bonus, equity, beneficios, budget de
   cursos, home office stipend) — especialmente relevante si la banda base es fija.
5. **Nunca aceptar en la llamada.** Pedir 48hs para revisar la oferta por escrito antes
   de contra-ofertar.

**Ruta sugerida (8 semanas, adaptando lo mejor de ambas propuestas):**

1. **S1-2 — SQL avanzado y planes de ejecución:** problemas diarios de window
   functions/dedup/joins complejos + `EXPLAIN (ANALYZE, BUFFERS)` sobre un dataset
   sintético grande en Postgres local.
2. **S3-4 — Arquitectura de pipelines:** documentar 4 escenarios de diseño
   (idempotencia en consumers, late-arriving data en dbt, particionamiento de Kafka,
   backpressure) con diagramas explicables en <5 minutos.
3. **S5-6 — Behavioral en inglés técnico:** escribir y ensayar en voz alta (grabándose,
   límite de 3 minutos) 5-6 historias STAR basadas en tus propios proyectos.
4. **S7-8 — Simulacros y prospección activa:** mocks P2P (Pramp), postulación activa
   (incluyendo el canal gratuito de Silver.dev si aplica), repasar principios de
   negociación de patio11 antes de cualquier llamada con reclutadores.

---

## Próximos pasos (actualizado)

- [x] RAG/Embeddings removido de scope — se cubre en el roadmap paralelo de AI
      Engineering (F2: `doc-rag`, pgvector, chunking), no se duplica acá
      bien en la práctica, para anotarlo como validación real de uso
- [ ] Al llegar a F4 en la práctica: verificar si Confluent Developer sigue 100% gratis
- [ ] Al llegar a F5 en la práctica: intentar corroborar en persona `runbook.academy` y
      `systeminternals.dev` (Kubernetes) antes de asignarles tiempo de estudio
- [ ] Al llegar a F6 en la práctica: si se considera usar Silver.dev, aplicar primero
      por el canal gratuito antes de evaluar el curso pago "Interview Ready"; verificar
      precio y contenido actualizado del curso directamente en su sitio al momento
