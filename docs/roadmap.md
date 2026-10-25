# Roadmap — Backend & Systems Engineering

> **Ingeniería en Informática → Backend Engineer (Go + PostgreSQL)**
>
> **Horizonte real:** 26 oct 2026 → nov/dic 2027 (graduación). El objetivo de este período **no es cubrir un temario**, es sentar bases backend empleables y salir al mercado antes de graduarse.
>
> **Estrategia en Dos Etapas:**
> 1. **Etapa 1 (Pre-Graduación, hasta Nov/Dic 2027):** Go, HTTP, PostgreSQL, testing, Docker, CI/CD, deploy y observabilidad básica, todo aplicado sobre un proyecto real desplegado. Inglés, DSA y búsqueda de empleo como disciplinas transversales.
> 2. **Etapa 2 (Post-Graduación, 2028+):** Data Engineering, Cloud/Kubernetes y Mobile, decididas **con el mercado y la experiencia del primer empleo**, no antes.
>
> Los recursos concretos de cada tema viven en [`docs/SOURCES.md`](SOURCES.md). Este documento define **qué, cuándo y con qué entregable**.

---

## 1. Resumen de fases — Etapa 1

| Fase | Período | Duración | Foco técnico | Entregable verificable |
| :--- | :--- | :--- | :--- | :--- |
| **F1** | 14 jun – 30 sep 2026 | ~15 sem. | Linux Internals, C & DSA fundamentos | `mysh v2.0` + dynamic array + linked list ✅ |
| **F2** | 26 oct 2026 – 28 feb 2027 | ~18 sem. | Go just-in-time, HTTP, PostgreSQL, testing, deploy | `taskapi v1` **desplegada** con tests, CI y README/ADRs |
| **F3** | 1 mar – 31 may 2027 | 13 sem. | Hardening, SQL profundo, Redis, métricas, postulaciones | `taskapi v2` + 30 postulaciones + ≥2 entrevistas técnicas |
| **F4** | 1 jun – 31 jul 2027 | 9 sem. | Portfolio, benchmark, system design básico | Benchmark reproducible + README/ADRs finales + mocks |
| **F5** | 1 ago – 30 nov 2027 | 17 sem. | **Tesis (bloque reservado)**, entrevistas, cierre | Tesis cerrada + oferta o pipeline activo |
| **Buffer** | dic 2027 – feb 2028 | ~10 sem. | Negociación, plan B, inserción laboral | Primer empleo o puente freelance |
| **Etapa 2** | 2028+ | — | Data / Cloud / Mobile | Después del primer empleo |

### Regímenes de dedicación

| Período | Capacidad nominal | Capacidad planificada |
| :--- | :--- | :--- |
| Semestre (6to, 7mo, 8vo) | 20–23 h/sem | **18 h/sem** |
| Vacaciones (dic–feb, jun–jul) | 25–30 h/sem | **25 h/sem** |
| Semanas de exámenes | 8–10 h/sem | 8 h/sem, sin culpa |

Detalle de calendario, hitos y regla del 80% en [`calendario.md`](../calendario.md).

---

## 2. Alcance del período

### Entra (todo se aprende construyendo `taskapi`)

- **Go:** sintaxis, slices/maps, structs, interfaces, errores, `context`, concurrencia básica (`goroutine`, `channel`, `sync`), `net/http`, `database/sql`/`pgx`, `testing` table-driven, `slog`.
- **Backend:** diseño de endpoints REST, validación de entrada, autenticación (hash de passwords + JWT o sesiones), autorización por propietario, paginación, modelo de errores, idempotencia.
- **PostgreSQL:** modelado relacional, normalización, índices, transacciones y niveles de aislamiento, `EXPLAIN (ANALYZE, BUFFERS)`, migraciones SQL puras (sin ORM).
- **Infra mínima:** Dockerfile multi-stage, `docker compose`, GitHub Actions (test + lint + build), deploy en VPS/PaaS con HTTPS.
- **Observabilidad mínima:** logs estructurados con `request_id`, métricas Prometheus, un dashboard, health checks.
- **Redis:** solo cuando `taskapi` lo pida (cache-aside, rate limiting).
- **Profundidad de sistemas:** lectura y profiling con `pprof`; `dlv`; `go test -race`, `go vet`, `golangci-lint`.
- **System design básico:** estimaciones de capacidad, caché, colas, rate limiting, idempotencia — sobre lo que ya construiste.
- **Transversales:** DSA (2–3/semana), inglés (fuera del repo), búsqueda de empleo (desde mar 2027).

### Se difiere a Etapa 2 o "on demand" en el trabajo

| Tema | Por qué no ahora |
| :--- | :--- |
| DDD táctico/estratégico, Clean/Hexagonal como fase | Sobreingeniería para proyectos individuales; se usa ADRs cortos dentro de `taskapi` |
| Kubernetes, Terraform, AWS profundo | No es requisito para un junior backend; se aprende en el trabajo |
| Kafka, dbt, DuckDB, Python, Data Engineering | Especialización posterior al primer empleo |
| gRPC, microservicios, service mesh | Un monolito modular bien hecho es mejor señal para junior |
| Mobile (KMP), segundo/tercer lenguaje | Diluye foco; el diferenciador es profundidad en Go + SQL + Linux |
| Certificaciones (AWS CCP/SAA, etc.) | Impacto casi nulo en hiring backend junior |
| Catálogo GoF completo, `architecture-docs` como proyecto | Se absorbe en README/ADRs de `taskapi` |
| `resilient-api` como proyecto separado | Redis, rate limiting y métricas se integran en `taskapi v2` |

> **Regla anti-sobreingeniería:** cada fase cierra con algo **desplegado, medido o mergeado**. Si un proyecto no está perfecto al terminar su ventana, se despliega como está y se documentan las limitaciones en el README.

---

## 3. Disciplinas transversales

| Disciplina | Cadencia | Meta al cierre de F5 | Dónde se registra |
| :--- | :--- | :--- | :--- |
| **DSA** | 2–3 problemas/semana desde nov 2026, por patrón | ~100–120 problemas, con repaso de errores | [`learning-dsa/`](../learning-dsa/README.md) |
| **Inglés** | 30 min/día + 1–2 conversaciones/semana | B1 en jun 2027 · B1+ en dic 2027 | Fuera de este repo |
| **Empleo** | Hoja de 50 ofertas en nov 2026; postulaciones desde mar 2027 (5–10/sem) | 30+ postulaciones y ≥2 entrevistas antes de F5 | [`yordycg-portfolio`](https://github.com/yordycg/yordycg-portfolio) |
| **Documentación técnica** | ADR de 1 párrafo por decisión relevante, dentro del proyecto | README + 4–6 ADRs defendibles en entrevista | `taskapi/docs/` |
| **Retrospectiva** | 15 min/semana; 60 min/mes; 90 min/trimestre | Recortar alcance, no duplicar horas | Notas personales |

**Política de IA:** la IA explica conceptos, diagnostica con herramientas (`dlv`, `EXPLAIN`, `pprof`, `-race`) y examina. **No escribe el código de los ejercicios ni del proyecto.** Una vez por semana, 5 preguntas de recuperación activa sin mirar el código.

---

## 4. FASE 1 — Linux Internals, C & DSA Fundamentos ✅

**Período:** 14 jun – 30 sep 2026 · **Estado: cerrada**

Lo aprendido y lo que se conserva como diferenciador:

- Aritmética de punteros, gestión manual de heap, modelo de memoria.
- Syscalls (`read`, `write`, `open`, `fork`, `exec`, `wait`), señales, pipes/FIFOs.
- Makefiles, GDB, Valgrind, AddressSanitizer/UBSan.
- DSA inicial en C: dynamic array y linked list (donde la memoria manual enseña algo).

**Entregables:** `mysh v2.0` (parseo, `fork`+`exec`, pipes, redirecciones, `Ctrl+C`, historial con linked list propia), dynamic array y linked list.

**Por qué importa:** es el argumento de "entiendo qué hay debajo del runtime de Go" y la base para leer código de sistemas (containers, Redis, schedulers) más adelante.

---

## 5. FASE 2 — Go + HTTP + PostgreSQL + Deploy

**Período:** 26 oct 2026 – 28 feb 2027 (~18 semanas: 5 de semestre + vacaciones + arranque del 7mo)

### Objetivo

Pasar de "sé C" a "construyo y opero un servicio backend en Go", con un artefacto público que puedas mostrar. **No hay bloque de teoría previa:** el Tour de Go y los capítulos de *Learn Go with Tests* se consumen en paralelo a la construcción de `taskapi`.

### Contenido

1. **Go esencial (5–6 capítulos, no 12):** Tour de Go → `hello-world` → `integers` → `iteration` → `arrays-slices` → `structs/interfaces` → `pointers-errors` → `maps`. El resto (DI, mocking, concurrencia, HTTP) se aprende cuando `taskapi` lo exige.
2. **HTTP y API:** `net/http` con ruteo por método (Go 1.22+), middleware (logging, recuperación de panics), `context`, JSON, códigos de estado, paginación.
3. **PostgreSQL:** schema modelado (ER primero), migraciones SQL, `pgx`, transacciones, índices, `EXPLAIN`.
4. **Seguridad aplicada:** queries parametrizadas, `argon2id`/`bcrypt`, JWT o sesiones, validación de entrada, autorización por propietario (IDOR), secrets fuera de git.
5. **Testing:** table-driven tests, tests de integración contra Postgres en Docker, `go test -race`.
6. **Deploy:** Dockerfile multi-stage, `docker compose`, GitHub Actions (vet + lint + test + build), URL pública con HTTPS.
7. **Documentación:** README con arquitectura + 3–4 ADRs cortos (por qué `pgx`, por qué sin ORM, por qué JWT vs sesiones).

### Entregable — `taskapi v1`

API de tareas/usuarios **desplegada y accesible por URL pública**, con: CRUD completo, auth, Postgres con migraciones, tests, CI verde, logs estructurados, README y ADRs. Benchmark inicial (aunque sea simple) para tener una línea base.

### Criterio de cierre

- [ ] La URL responde y el servicio corre en un entorno que no es tu máquina.
- [ ] `docker compose up` levanta todo desde cero en un clon limpio.
- [ ] CI verde y tests que fallan si rompes algo.
- [ ] Puedes defender cada decisión técnica sin mirar el código.
- [ ] ~30–40 problemas DSA resueltos y hoja de 50 ofertas completada.

---

## 6. FASE 3 — Hardening + SQL profundo + Primera exposición al mercado

**Período:** 1 mar – 31 may 2027 (13 semanas, 7mo semestre)

### Objetivo

Convertir `taskapi v1` en un servicio que aguanta condiciones reales y empezar a postular **antes** de sentirte listo. Esta fase es la bisagra: si no hay postulaciones aquí, el plan falla.

### Contenido

1. **SQL profundo:** window functions, joins complejos, índices parciales/compuestos, planes de ejecución, transacciones multi-step, niveles de aislamiento, `SKIP LOCKED` como introducción a colas.
2. **Redis acotado:** cache-aside, invalidación, rate limiting (token bucket), por qué Redis y no Postgres para eso.
3. **Observabilidad:** `slog` JSON con `request_id`, métricas Prometheus (counter/gauge/histogram), dashboard mínimo en Grafana, health/readiness checks.
4. **Resiliencia básica:** timeouts, reintentos con backoff, idempotencia, graceful shutdown.
5. **Testing serio:** cobertura de casos borde, tests de integración con Postgres/Redis en CI, un test de carga con `k6` o `vegeta`.
6. **Búsqueda de empleo activa:** CV (es/en), LinkedIn, GitHub curado, tracker, 5–10 postulaciones/semana + 5 mensajes de outreach/semana.

### Entregable — `taskapi v2`

`taskapi v1` + Redis, rate limiting, métricas, dashboard, un benchmark reproducible con números (p50/p99, req/s) documentado en `BENCHMARKS.md`, y la primera versión del CV/portfolio lista.

### Criterio de cierre

- [ ] 30+ postulaciones personalizadas enviadas y ≥2 entrevistas técnicas realizadas.
- [ ] Benchmark reproducible por un tercero con un comando.
- [ ] Un post-mortem escrito de un fallo provocado a propósito (saturación de conexiones, caída de Redis).
- [ ] 60–80 problemas DSA acumulados.

> **Si en marzo la tesis ya está asignada y consume horas:** se recorta el punto 4 y el dashboard; **no** se recortan las postulaciones.

---

## 7. FASE 4 — Portfolio, benchmark y System Design básico

**Período:** 1 jun – 31 jul 2027 (9 semanas, vacaciones)

### Objetivo

Pulir el artefacto que te va a conseguir entrevistas y aprender a **defenderlo** en una conversación de diseño. Un proyecto profundo vale más que tres a medias: aquí no se agrega un proyecto nuevo.

### Contenido

1. **Portfolio final:** README que convierte (problema, arquitectura, decisiones, benchmark, quickstart en 3 comandos), ADRs definitivos, `RUNBOOK.md` con qué hacer si se cae.
2. **System design básico:** estimaciones de capacidad (QPS, storage, bandwidth), caché, colas, rate limiting distribuido, idempotencia, consistencia — **siempre sobre lo que ya construiste**.
3. **Práctica de entrevistas:** 2–4 casos resueltos con cronómetro (rate limiter, URL shortener, cola de trabajos, feed), 1–2 mock interviews.
4. **Segundo artefacto (opcional, uno solo):** cola de trabajos con `SKIP LOCKED` **o** `mini-redis` en Go **o** 2 PRs reales en un repo Go. Solo si el portfolio principal ya está cerrado.
5. **Puente freelance (si no hay empleo):** experimento de 90 días, tope 2 h/semana, nicho APIs/automatización; éxito = 1 cliente pagado o 3 calls de descubrimiento.

### Entregable

Portfolio listo para entrevistas: `taskapi v2` + benchmark + README/ADRs/RUNBOOK + 2–4 casos de system design documentados.

### Criterio de cierre

- [ ] Un reclutador entiende el proyecto en 60 segundos leyendo el README.
- [ ] Explicas la arquitectura y los trade-offs en 5 minutos, en español y en inglés.
- [ ] Resuelves un caso de system design básico en 45 minutos sin ayuda.
- [ ] 80–100 problemas DSA acumulados.

---

## 8. FASE 5 — Tesis (bloque reservado) + Entrevistas + Cierre

**Período:** 1 ago – 30 nov 2027 (17 semanas, 8vo semestre)

> ⚠️ **La tesis es una variable, no una fase planificada.** A la fecha de escritura de este documento no hay información sobre tema, fechas de entrega ni alcance del "proyecto X". Por eso esta fase **reserva** 15–18 h/semana y se ajusta cuando la universidad lo defina (revisión de julio 2027 como límite).

### Contenido

1. **Tesis / proyecto X:** prioridad universitaria. Si el tema lo permite, reutilizar `taskapi` como base para no construir dos cosas distintas.
2. **Entrevistas:** pipeline activo, take-homes, live coding, behavioral en inglés, negociación.
3. **Mantenimiento del portfolio:** no agregar features; corregir bugs, actualizar dependencias, mantener CI verde.
4. **Postulaciones:** full-time junior/nearshore + remoto USD **solo si el inglés ya es B1+**.
5. **Cierre:** graduación, traspaso de proyectos a estado "presentable", retrospectiva de la etapa.

### Entregable

Tesis cerrada · oferta firmada **o** pipeline activo con entrevistas en curso · portfolio estable · B1+ de inglés.

### Criterio de cierre

- [ ] Tesis entregada y aprobada.
- [ ] Al menos una oferta recibida o 3 procesos en etapa final.
- [ ] Plan B ejecutándose si no hay oferta (nearshore, part-time, freelance con cliente).

---

## 9. Buffer — dic 2027 a feb 2028

No es una fase de estudio. Es el colchón para:

- Negociar la primera oferta (48 h de análisis, nunca aceptar en vivo).
- Si no hay oferta: plan B (nearshore, part-time, freelance) y reintento del remoto USD con más inglés y experiencia.
- Primeras semanas del empleo: adaptarse, no estudiar.

---

## 10. Etapa 2 — Especializaciones (2028+)

> **No se planifica en detalle hoy.** Se decide en la revisión de fin de Etapa 1 con datos: qué piden las ofertas que viste, en qué trabajas, y qué te gustó de verdad. Los recursos ya están catalogados en [`docs/SOURCES.md`](SOURCES.md#etapa-2--especializaciones-post-graduación-2028).

| Especialización | Foco | Se activa cuando |
| :--- | :--- | :--- |
| **A — Data Engineering** | Python idiomático, Kafka, dbt + DuckDB, Lambda/Kappa, proyecto `eventpipe` | Un rol o proyecto real lo pida |
| **B — Cloud (AWS) & Kubernetes** | ECS/EKS, *Kubernetes the Hard Way*, Terraform, RDS | El trabajo use cloud/orquestación |
| **C — Mobile Multiplataforma** | Kotlin + Compose Multiplatform (KMP) | Exista un producto propio o un rol mobile |
| **Transversal — Arquitectura** | DDD táctico, Clean/Hexagonal, patrones GoF | El tamaño del sistema lo justifique |

**Regla:** nada de Etapa 2 compite con la tesis ni con la búsqueda de empleo de 2027.
