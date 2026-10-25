# Go Track — Fase 2 (Go Idiomático vía TDD)

> **Cockpit de estudio autónomo de Go.** El objetivo no es "saber sintaxis": es escribir Go idiomático y testeable — `slices`, `maps`, `structs`, interfaces implícitas, manejo explícito de errores, tests de mesa y concurrencia básica — antes de tocar `taskapi`.

- **Módulo:** `learning-go` (un único `go.mod` en esta carpeta).
- **Toolchain local:** Go 1.26.5 (`go version` verificado).
- **Duración:** rampa 26 oct – 1 nov 2026 + semanas 13–15 del calendario (2–22 nov).
- **Regla:** DSA permanece en pausa durante las tres primeras semanas (26 oct – 15 nov). Ver [`../learning-dsa/README.md`](../learning-dsa/README.md).

---

## 1. Herramientas (Día 1, ~30 min)

Verificar y dejar listo el entorno antes de escribir la primera línea:

- [ ] `go version` → 1.26.x
- [ ] `go env GOPATH GOMODCACHE GOTOOLCHAIN`
- [ ] `gofmt -h` (viene con Go, no se instala aparte)
- [ ] `go vet ./...` funciona dentro de este módulo
- [ ] Editor con `gopls` (Neovim LSP) y formateo al guardar

`golangci-lint` **no** se instala todavía: su configuración v2 y su ruido no aportan hasta que exista código real. Se añadirá en F2 tardía o F3.

---

## 2. Rampa de arranque: *A Tour of Go* (días 1–4)

Fuente oficial y gratuita: <https://go.dev/tour/>

| Día | Bloques del Tour | Qué debe quedar claro |
| :-- | :--- | :--- |
| 1 | Basics: packages, variables, tipos, constantes | Declaración corta vs `var`, cero values, tipos explícitos |
| 2 | Flow control: `for`, `if`, `switch`, `defer` | `for` es el **único** bucle; no hay `while` |
| 3 | Más tipos: structs, arrays, slices, maps | `len`/`cap`, `append`, diferencia array (valor) vs slice (descriptor) |
| 4 | Métodos e interfaces | Receptores por valor vs puntero, interfaces implícitas |

Cierre de la rampa: reescribir sin mirar un programa de ~40 líneas que use struct, slice, map, método y `error`.

---

## 3. Go idiomático con TDD: *Learn Go with Tests*

Fuente principal: <https://quii.gitbook.io/learn-go-with-tests>

Ciclo obligatorio en cada capítulo: **escribir el test que falla → implementación mínima → refactor**. Nada de copiar la solución del libro antes de intentarlo.

| # | Directorio | Contenido | DoD (Definition of Done) |
| :-- | :--- | :--- | :--- |
| 01 | `01-hello-world/` | Estructura de paquetes, `testing.T`, subtests | `go test ./...` verde y `go vet` limpio |
| 02 | `02-integers/` | Documentación de funciones, `ExampleAdd` | `go test` ejecuta también el ejemplo |
| 03 | `03-iteration/` | `for`, benchmarks con `testing.B` | `just bench-go` produce números estables |
| 04 | `04-arrays-slices/` | Arrays vs slices, `append`, variádicas, `cap` | Explicar por escrito por qué `append` puede realocar |
| 05 | `05-structs-methods-interfaces/` | Structs, receptores, interfaces implícitas, table-driven tests | Un test de mesa con ≥3 casos por función |
| 06 | `06-pointers-errors/` | Punteros a struct, mutación de receptores, `error`, `errors.New`, `errors.Is` | Un error propio envuelto y comprobado en test |
| 07 | `07-maps/` | `map`, comma-ok, borrado, iteración no ordenada | Test que demuestre lookup de clave ausente |
| 08 | `08-dependency-injection/` | Inyectar dependencias como interfaces/`io.Writer` | Test sin `os.Stdout` real |
| 09 | `09-mocking/` | Interfaces pequeñas, spies, fakes | Test de conteo de llamadas |
| 10 | `10-concurrency/` | Goroutines, channels, `sync.WaitGroup` | `go test -race` verde con N goroutines |
| 11 | `11-select-sync/` | `select`, timeouts, `sync.Mutex`/`RWMutex` | Test que corte por timeout sin colgarse |
| 12 | `12-http-json/` | `net/http`, `httptest`, `encoding/json`, `context` | Handler con test de integración vía `httptest` |

> Los capítulos 07–12 son el puente directo a `taskapi`: sin ellos, la fase de PostgreSQL llega con un hueco de HTTP/JSON/context.

---

## 4. Calendario de ejecución

| Semana | Fechas (2026) | Capítulos |
| :--- | :--- | :--- |
| Rampa + S1 | 26 oct – 8 nov | Tour, `01`–`04` |
| S2 | 9 – 15 nov | `05`–`09` |
| S3 | 16 – 22 nov | `10`–`11` (concurrencia) |
| Vacaciones | 23 nov en adelante | `12` (HTTP/JSON) → inicio `taskapi` |

A 16 h/semana en semestre el bloque es ajustado pero viable; si una semana se atrasa, **se recorta `09-mocking` y `12-http-json` se mueve a diciembre**, nunca la concurrencia.

---

## 5. Reglas de estudio

1. **Cero código regalado:** la lógica la escribes tú. La IA solo explica conceptos, trade-offs y guía el diagnóstico (`go test`, `-race`, `go vet`, `dlv`).
2. **Productive failure (30–45 min):** si el test no pasa en ese tiempo, lee la explicación del patrón, cierra la solución y reescríbela desde cero al día siguiente.
3. **Un commit por capítulo:** `feat(go): completar hello-world con TDD`, `feat(go): ...`.
4. **Nada de dependencias externas** durante el track: solo biblioteca estándar.
5. **DSA en pausa** hasta dominar `slices`, `maps`, `structs` y punteros (aprox. 15 nov).

---

## 6. Ejecución y verificación

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
- [ ] `just test-go` verde (cuando ya exista el primer test).

> `just test-go` avisa y sale con 0 mientras no exista ningún `*_test.go`; deja de ser un chequeo real hasta el capítulo 01.

---

## 7. Estructura

```
learning-go/
├── go.mod          # module learning-go (go 1.26)
├── README.md       # este archivo
└── NN-tema/        # se crea al empezar cada capítulo, con su test primero
```

No se crean directorios vacíos ni tests de relleno: el primer commit de cada capítulo nace con el test que falla.

---

## 8. Referencias

- [A Tour of Go](https://go.dev/tour/) — arranque oficial.
- [Learn Go with Tests](https://quii.gitbook.io/learn-go-with-tests) — columna vertebral TDD.
- [Go by Example](https://gobyexample.com/) — sintaxis puntual.
- [Effective Go](https://go.dev/doc/effective_go) — idiomatismo.
- [Go Code Review Comments](https://go.dev/wiki/CodeReviewComments) — estilo.
- [Exercism Go track](https://exercism.org/tracks/go) — práctica extra opcional.
