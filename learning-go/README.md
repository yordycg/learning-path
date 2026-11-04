# Go Track — Fase 2 (Go just-in-time, orientado a `taskapi`)

> **Cockpit de estudio de Go.** El objetivo no es "terminar un temario de Go": es tener `taskapi v1` funcionando y desplegada al final de F2 y saber defender cada línea. Go se aprende **construyendo**, no en un bloque de teoría previa.

- **Módulo:** `learning-go` (un único `go.mod` en esta carpeta).
- **Toolchain local:** Go 1.26.5 (`go version` verificado).
- **Período:** 2 nov 2026 – 15 feb 2027 (F2). Ver [`../calendario.md`](../calendario.md).
- **Entregable de la fase:** `taskapi v1` con URL pública, tests, CI y README/ADRs. Vive en su propio repo, [`../projects/taskapi/`](../projects/taskapi/), no en este módulo. Ver [`../docs/roadmap.md`](../docs/roadmap.md#fase-2--go--postgresql-profundo--seguridad).
- **DSA:** arranca el **16 nov** (semana 3), no en la semana 1. Las dos primeras semanas son sintaxis Go pura: el bloque de 40 min se reasigna a los capítulos. 2–3 problemas/semana desde entonces. Ver [`../learning-dsa/README.md`](../learning-dsa/README.md).

---

## 1. Regla de oro: ningún capítulo antes de que el proyecto lo pida

Este track es **just-in-time**, no secuencial:

1. Lees lo mínimo del capítulo.
2. Lo aplicas ese mismo día en `taskapi` (o en un ejercicio pequeño).
3. Si el proyecto no necesita el tema todavía, **no lo estudias**.

Presupuesto máximo de tutoriales: **20 % del tiempo** de la fase. El 80 % restante es escribir, romper, medir y desplegar.

---

## 2. Herramientas (Día 1, ~30 min)

- [x] `go version` → 1.26.x
- [x] `go env GOPATH GOMODCACHE GOTOOLCHAIN`
- [x] `gofmt -h` (viene con Go, no se instala aparte)
- [x] `go vet ./...` funciona dentro de este módulo
- [x] Editor con `gopls` (Neovim LSP) y formateo al guardar

`golangci-lint` **no** se instala todavía: se añade cuando exista código real y CI que lo ejecute (F2 tardía o F3).

---

## 3. Núcleo: 7 capítulos (obligatorios)

Fuente principal: [Learn Go with Tests](https://quii.gitbook.io/learn-go-with-tests) — es la columna vertebral, no un complemento. Referencias de sintaxis puntual: [Go by Example](https://gobyexample.com/) y [A Tour of Go](https://go.dev/tour/); el Tour **no se cursa linealmente**, se consulta cuando un capítulo pide algo que todavía no viste.

Ciclo obligatorio en cada capítulo: **escribir el test que falla → implementación mínima → refactor**. Nada de copiar la solución del libro antes de intentarlo.

| #   | Directorio                       | Contenido                                                                          | DoD (Definition of Done)                                                                      |
| :-- | :------------------------------- | :--------------------------------------------------------------------------------- | :-------------------------------------------------------------------------------------------- |
| 01  | `01-hello-world/`                | Estructura de paquetes, `testing.T`, subtests                                      | `go test ./...` verde y `go vet` limpio                                                       |
| 02  | `02-integers/`                   | Documentación de funciones, `ExampleAdd`                                           | `go test` ejecuta también el ejemplo                                                          |
| 03  | `03-iteration/`                  | `for`, benchmarks con `testing.B`                                                  | `just bench-go` produce números estables                                                      |
| 04  | `04-arrays-slices/`              | Arrays vs slices, `append`, variádicas, `cap`                                      | Explicar por escrito por qué `append` puede realocar                                          |
| 05  | `05-structs-methods-interfaces/` | Structs, receptores, interfaces implícitas, table-driven tests                     | Un test de mesa con ≥3 casos por función                                                      |
| 06  | `06-pointers-errors/`            | Punteros a struct, mutación de receptores, `error`, `errors.New`, `errors.Is`/`As` | Un error propio envuelto y comprobado en test                                                 |
| 07  | `07-maps/`                       | `map[K]V`, `make`, `comma-ok`, `delete`, `range` sobre maps                        | Un test que deduplique con `map` y otro que distinga clave ausente de valor cero (`comma-ok`) |

**Checkpoint del núcleo (sin directorio, al cerrar 01–07):** reescribir sin mirar un programa de ~40 líneas con struct, slice, map, método y `error`. El Tour de Go sirve como referencia aquí, no como capítulo.

Cierre del núcleo: un programa de ~80 líneas que lea un JSON de logs, filtre por nivel y escriba el resultado, usando solo la stdlib.

---

## 4. On demand: el resto se aprende dentro de `taskapi`

No son capítulos que se cursan "porque tocan". Se consultan **cuando el proyecto los exige**:

| Tema                                               | Cuándo se estudia                                         | En qué se nota             |
| :------------------------------------------------- | :-------------------------------------------------------- | :------------------------- |
| Dependency injection                               | Al inyectar el pool de Postgres o el logger en el handler | `08-dependency-injection/` |
| Mocking                                            | Al testear un handler sin DB real                         | `09-mocking/`              |
| Concurrencia (`goroutine`, `channel`, `WaitGroup`) | Al implementar rate limiting o procesar en background     | `10-concurrency/`          |
| `select`, timeouts, `sync`                         | Al agregar cancelación por `context` y graceful shutdown  | `11-select-sync/`          |
| `net/http`, `httptest`, `encoding/json`, `context` | **Semana 2**, al construir el primer endpoint             | `12-http-json/`            |

> Los capítulos 08–12 conservan su directorio porque son la referencia práctica del tema; se crean **solo cuando aparezca la necesidad** en `taskapi`, no por calendario. `07-maps` salió de esta lista: es obligatorio antes del 16 nov porque el primer bloque de DSA lo necesita.

---

## 5. Calendario: 3 semanas de semestre + exámenes + vacaciones

### Semanas de semestre (6 h efectivas/semana)

| Semana | Fechas      | Go / proyecto                                                                                                                                 | DSA                                             |
| :----- | :---------- | :-------------------------------------------------------------------------------------------------------------------------------------------- | :---------------------------------------------- |
| **S1** | 2 – 8 nov   | `01-hello-world` + `02-integers`                                                                                                              | — (bloque de 40 min reasignado a Go)            |
| **S2** | 9 – 15 nov  | `03-iteration` + `04-arrays-slices` + `07-maps`; esqueleto de [`taskapi`](../projects/taskapi/) (repo propio) + `docker compose` con Postgres | — (último bloque de sintaxis)                   |
| **S3** | 16 – 21 nov | `05-structs-methods-interfaces` + `06-pointers-errors`; 2 endpoints + table-driven tests                                                      | **DSA arranca:** 3 problemas (Arrays & Hashing) |
| **S4** | 22 – 30 nov | Semana de exámenes: sin temas nuevos, solo repaso                                                                                             | Repaso de errores                               |

**Criterio de éxito de las 3 semanas:** `taskapi` con esqueleto corriendo en Docker, ≥2 endpoints con test, CI verde y los 3 primeros problemas DSA resueltos. No hace falta que esté desplegada todavía.

### Vacaciones (dic 2026 – 15 feb 2027, ~24 h efectivas/semana)

| Bloque     | Foco                                                                                       | Resultado                          |
| :--------- | :----------------------------------------------------------------------------------------- | :--------------------------------- |
| Dic        | Auth completa, migraciones, tests de integración con Postgres, `08`–`09` si hicieron falta | `taskapi` con CRUD + auth + tests  |
| Ene        | Concurrencia aplicada (rate limiting), `slog`, Dockerfile multi-stage                      | API dockerizada                    |
| 1 – 15 feb | Hardening, deploy con HTTPS, README + ADRs, **gate G1**                                    | `taskapi v1` pública y presentable |

> Si el calendario se atrasa, se recorta alcance: primero los capítulos opcionales, después el deploy. **Nunca** se recorta DSA.

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
└── NN-tema/        # núcleo 01–07, se crea al empezar cada capítulo con su test primero
```

`taskapi` **no** vive aquí: es un repositorio independiente en [`../projects/taskapi/`](../projects/taskapi/), con su propio `go.mod`, build system y commits. Este módulo es solo el cuaderno de estudio de Go.

No se crean directorios vacíos ni tests de relleno: el primer commit de cada capítulo nace con el test que falla.

---

## 9. Referencias

- [A Tour of Go](https://go.dev/tour/) — referencia de sintaxis, no un capítulo del track.
- [Learn Go with Tests](https://quii.gitbook.io/learn-go-with-tests) — columna vertebral TDD.
- [Go by Example](https://gobyexample.com/) — sintaxis puntual.
- [Effective Go](https://go.dev/doc/effective_go) — idiomatismo.
- [Go Code Review Comments](https://go.dev/wiki/CodeReviewComments) — estilo.
- [Exercism Go track](https://exercism.org/tracks/go) — práctica extra opcional.

Catálogo completo de recursos: [`../docs/SOURCES.md`](../docs/SOURCES.md#f2--go--http--postgresql--deploy-26-oct-2026--28-feb-2027--activo).
