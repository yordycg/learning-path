# Go Track — Fase 2 (Go just-in-time, orientado a `taskapi`)

> **Cockpit de estudio de Go.** El objetivo no es "terminar un temario de Go": es tener `taskapi v1` desplegada al final de F2 y saber defender cada línea. Go se aprende **construyendo**, no en un bloque de teoría previa.

- **Módulo:** `learning-go` (un único `go.mod` en esta carpeta).
- **Toolchain local:** Go 1.26.5 (`go version` verificado).
- **Período:** 26 oct 2026 – 28 feb 2027 (F2).
- **Entregable de la fase:** `taskapi v1` con URL pública, tests, CI y README/ADRs. Ver [`../docs/roadmap.md`](../docs/roadmap.md#5-fase-2--go--http--postgresql--deploy).
- **DSA:** ya **no está en pausa**. 2–3 problemas/semana desde la semana 1. Ver [`../learning-dsa/README.md`](../learning-dsa/README.md).

---

## 1. Regla de oro: ningún capítulo antes de que el proyecto lo pida

Este track es **just-in-time**, no secuencial:

1. Lees lo mínimo del capítulo.
2. Lo aplicas ese mismo día en `taskapi` (o en un ejercicio pequeño).
3. Si el proyecto no necesita el tema todavía, **no lo estudias**.

Presupuesto máximo de tutoriales: **20 % del tiempo** de la fase. El 80 % restante es escribir, romper, medir y desplegar.

---

## 2. Herramientas (Día 1, ~30 min)

- [ ] `go version` → 1.26.x
- [ ] `go env GOPATH GOMODCACHE GOTOOLCHAIN`
- [ ] `gofmt -h` (viene con Go, no se instala aparte)
- [ ] `go vet ./...` funciona dentro de este módulo
- [ ] Editor con `gopls` (Neovim LSP) y formateo al guardar

`golangci-lint` **no** se instala todavía: se añade cuando exista código real y CI que lo ejecute (F2 tardía o F3).

---

## 3. Núcleo: 6 capítulos (obligatorios)

Fuente principal: <https://quii.gitbook.io/learn-go-with-tests> + <https://go.dev/tour/>

Ciclo obligatorio en cada capítulo: **escribir el test que falla → implementación mínima → refactor**. Nada de copiar la solución del libro antes de intentarlo.

| # | Directorio | Contenido | DoD (Definition of Done) |
| :-- | :--- | :--- | :--- |
| 00 | *(sin directorio)* | [A Tour of Go](https://go.dev/tour/) — Basics, Flow control, More types, Methods & interfaces | Reescribir sin mirar un programa de ~40 líneas con struct, slice, map, método y `error` |
| 01 | `01-hello-world/` | Estructura de paquetes, `testing.T`, subtests | `go test ./...` verde y `go vet` limpio |
| 02 | `02-integers/` | Documentación de funciones, `ExampleAdd` | `go test` ejecuta también el ejemplo |
| 03 | `03-iteration/` | `for`, benchmarks con `testing.B` | `just bench-go` produce números estables |
| 04 | `04-arrays-slices/` | Arrays vs slices, `append`, variádicas, `cap` | Explicar por escrito por qué `append` puede realocar |
| 05 | `05-structs-methods-interfaces/` | Structs, receptores, interfaces implícitas, table-driven tests | Un test de mesa con ≥3 casos por función |
| 06 | `06-pointers-errors/` | Punteros a struct, mutación de receptores, `error`, `errors.New`, `errors.Is`/`As` | Un error propio envuelto y comprobado en test |

Cierre del núcleo: un programa de ~80 líneas que lea un JSON de logs, filtre por nivel y escriba el resultado, usando solo la stdlib.

---

## 4. On demand: el resto se aprende dentro de `taskapi`

No son capítulos que se cursan "porque tocan". Se consultan **cuando el proyecto los exige**:

| Tema | Cuándo se estudia | En qué se nota |
| :--- | :--- | :--- |
| `maps` | Al modelar índices en memoria o deduplicar | `07-maps/` |
| Dependency injection | Al inyectar el pool de Postgres o el logger en el handler | `08-dependency-injection/` |
| Mocking | Al testear un handler sin DB real | `09-mocking/` |
| Concurrencia (`goroutine`, `channel`, `WaitGroup`) | Al implementar rate limiting o procesar en background | `10-concurrency/` |
| `select`, timeouts, `sync` | Al agregar cancelación por `context` y graceful shutdown | `11-select-sync/` |
| `net/http`, `httptest`, `encoding/json`, `context` | **Semana 2**, al construir el primer endpoint | `12-http-json/` |

> Los capítulos 07–12 conservan su directorio porque son la referencia práctica del tema; se crean **solo cuando aparezca la necesidad** en `taskapi`, no por calendario.

---

## 5. Calendario: 5 semanas de semestre + vacaciones

### Semanas de semestre (18 h efectivas/semana)

| Semana | Fechas | Go / proyecto | DSA |
| :--- | :--- | :--- | :--- |
| **S1** | 26 oct – 1 nov | Tour + `01-hello-world` + `02-integers` | 3 problemas (arrays / hash maps) |
| **S2** | 2 – 8 nov | `03-iteration` + `04-arrays-slices`; esqueleto de `taskapi` + `docker compose` con Postgres | 3 problemas |
| **S3** | 9 – 15 nov | `05-structs-methods-interfaces` + `06-pointers-errors`; 2 endpoints + table-driven tests | 3 problemas |
| **S4** | 16 – 22 nov | `12-http-json`; auth (hash de passwords) + primer middleware; CI con `go vet` + `go test -race` | 3 problemas |
| **S5** | 23 – 29 nov | Semana de exámenes: buffer, cerrar esqueleto, retrospectiva. **Sin temas nuevos** | Repaso de errores |

**Criterio de éxito de las 5 semanas:** `taskapi` con esqueleto corriendo en Docker, ≥2 endpoints con test, CI verde y 12–15 problemas DSA resueltos. No hace falta que esté desplegada todavía.

### Vacaciones (dic 2026 – feb 2027, ~25 h efectivas/semana)

| Bloque | Foco | Resultado |
| :--- | :--- | :--- |
| Dic | Auth completa, migraciones, tests de integración con Postgres, `07`–`09` si hicieron falta | `taskapi` con CRUD + auth + tests |
| Ene | Concurrencia aplicada (rate limiting), `slog`, Dockerfile multi-stage, deploy | **URL pública con HTTPS** |
| Feb | Hardening, README + ADRs, hoja de ofertas, CV/LinkedIn | `taskapi v1` cerrada y presentable |

> Si el calendario se atrasa, se recorta alcance: primero el deploy, después los capítulos opcionales. **Nunca** se recorta DSA ni el deploy.

---

## 6. Reglas de estudio

1. **Cero código regalado:** la lógica la escribes tú. La IA solo explica conceptos, trade-offs y guía el diagnóstico (`go test`, `-race`, `go vet`, `dlv`, `pprof`).
2. **Productive failure (30–45 min):** si el test no pasa en ese tiempo, lee la explicación del patrón, cierra la solución y reescríbela desde cero al día siguiente.
3. **Un commit por capítulo o por feature:** `feat(go): completar hello-world con TDD`, `feat(taskapi): agregar auth con argon2id`.
4. **Nada de dependencias externas durante el núcleo:** solo biblioteca estándar. En `taskapi` se permiten `pgx`, router y poco más, **cada una justificada en un ADR**.
5. **Cada semana termina con algo que corre:** un test verde, un endpoint, un deploy o una medición. Si no, la semana siguiente se recorta alcance.
6. **Examen semanal (15 min):** 5 preguntas sobre lo construido, respondidas sin mirar el código. Si no puedes explicarlo, no lo aprendiste.

---

## 7. Ejecución y verificación

Desde la raíz del repositorio:

```bash
just test-go     # go test -v -race -count=1 ./...
just bench-go    # benchmarks
just fmt-go      # gofmt -l -w .
just lint-go     # go vet ./...
just check learning-go/01-hello-world/hello.go
```

Verificación manual antes de cada commit:

- [ ] `gofmt -l learning-go` no imprime nada.
- [ ] `just lint-go` sin hallazgos.
- [ ] `just test-go` verde.

---

## 8. Estructura

```
learning-go/
├── go.mod          # module learning-go (go 1.26)
├── README.md       # este archivo
├── NN-tema/        # núcleo 01–06, se crea al empezar cada capítulo con su test primero
└── taskapi/        # el proyecto real (se crea en S2)
```

No se crean directorios vacíos ni tests de relleno: el primer commit de cada capítulo nace con el test que falla.

---

## 9. Referencias

- [A Tour of Go](https://go.dev/tour/) — arranque oficial.
- [Learn Go with Tests](https://quii.gitbook.io/learn-go-with-tests) — columna vertebral TDD.
- [Go by Example](https://gobyexample.com/) — sintaxis puntual.
- [Effective Go](https://go.dev/doc/effective_go) — idiomatismo.
- [Go Code Review Comments](https://go.dev/wiki/CodeReviewComments) — estilo.
- [Exercism Go track](https://exercism.org/tracks/go) — práctica extra opcional.

Catálogo completo de recursos: [`../docs/SOURCES.md`](../docs/SOURCES.md#f2--go--http--postgresql--deploy-26-oct-2026--28-feb-2027--activo).
