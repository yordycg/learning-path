# Status — Phase 1 (learning-c)

> Maintained by the AI at the end of every session. Start each session by reading this file + `git log -1`. Day-by-day conceptual detail lives in Obsidian; this file is operational state only.

## Cómo operar este archivo

- Cada día preguntas "¿qué toca hoy?" → se responde con la fila de hoy de _Current Week_ + sus recursos.
- Al cierre de sesión: marcar `[ ]` → `[x]` en la fila del día y añadir entrada al _Session log_.
- Al terminar la semana: las filas se archivan en el _Session log_ y se abre la siguiente con la plantilla de _Next Week_.
- **Concept-first:** cada semana se abre con los día(s) de concepto antes de los ejercicios. Todo concepto nuevo se investiga y se le asigna recurso antes de codearlo (nada se da por hecho).
- En el tick semanal (Dom): consultar el _Backlog — conceptos previos (S3–S10)_ para incluir el concepto pendiente de la semana que se abre.
- Los recursos completos por tema viven en [`README.md → Recursos por tema`](README.md#recursos-por-tema) (fuente única); aquí solo se referencian.

## Modelo estacional (a partir de ago 31)

> Este roadmap y el de IA (`../ai-learning-path/`) operan en **bloques estacionales**: durante el semestre universitario (31 ago – 22 nov 2026) este roadmap es **LP 100%**, semanas contiguas. El de IA está pausado (Fase 0 cerrada). **S3 (31 ago – 6 sep)** abre el tramo LP contiguo; S-weeks S3–S10 van seguidas (ver [`calendario.md`](../calendario.md)).

| Semana universitaria | Fechas | LP |
| -------------------- | ------ | -- |
| 4 | 31 ago – 6 sep | **S3: procesos** |
| 5 | 7–13 sep | S4: señales |
| 6 | 14–20 sep | S5: pipes |
| 7 | 21–27 sep | S6: GDB/ASan |
| 8 | 28 sep – 4 oct | S7: DSA linked list |
| 9 | 5–11 oct | S8: stack+queue |
| 10 | 12–18 oct | S9: hash+sorting |
| 11 | 19–25 oct | S10: integración |
| 12–15 | 26 oct – 22 nov | F1 continuación (a definir) |

- **Contrato diario de respuesta (obligatorio para la IA):** al pedir "¿qué toca hoy?", la respuesta **siempre** incluye: (1) archivos/directorios a crear con ruta exacta, (2) notas `.md` a crear con su nombre exacto, (3) recursos con **nombre + link**, y (4) zettels de Obsidian con nombre.

## Current Week — S3 (Aug 31 – Sep 6)

> **AI Engineering:** pausado durante el semestre (modelo estacional, ver arriba). Esta es la semana de este roadmap (C/procesos). Sprint de IA en vacaciones → `../ai-learning-path/`.

> Processes (K&R 8, `man 2`, Sorber fork video): `fork`/`exec`/`wait`, zombies. Proyecto: **mysh v1.0** (comandos externos, `execvp` + búsqueda en `PATH`, **sin** `system()`). Concepto previo a incluir: ¿Qué es un proceso? (PCB/PID, imagen de memoria). Referencia: [`README → Recovery Plan`](README.md#recovery-plan-f1-s0s10) (S3).

| Día    | Tema                                                                                          | Recursos                                                                                                                                           | Estado |
| ------ | --------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------- | ------ |
| Lun 31 | **¿Qué es un proceso?** (PCB/PID, imagen de memoria, estado) + por qué mysh no usa `system()` | K&R 8.6 · [fork()](https://www.youtube.com/watch?v=ss1-REMJ9GA) (Sorber) · `man 2 fork`/`execve` · OSTEP caps. 4–6                                                          | [ ]    |
| Mar 1  | **`fork`**: creación de proceso hijo, copia de memoria, fork/exec split                       | [fork()](https://www.youtube.com/watch?v=ss1-REMJ9GA) (Sorber) · K&R 8.6 · `man 2 fork`                                                                                     | [ ]    |
| Mié 2  | **`exec` family + `wait`**: reemplazo de imagen, zombies y reaping                            | [exec/execvp](https://www.youtube.com/watch?v=-_7BcxBr4P4) (Sorber) · K&R 8.6 · `man 2 execve`/`wait` · TLPI caps. 24–27                                                    | [ ]    |
| Jue 3  | **`execvp` + PATH**: búsqueda del binario en `$PATH`, por qué `execvp` y no `system()`        | [exec/execvp](https://www.youtube.com/watch?v=-_7BcxBr4P4) (Sorber) · `man 3 execvp`/`man 7 environ`                                                                        | [ ]    |
| Vie 4  | Buffer / refuerzo — **errno** (`perror`/`strerror`, gotcha de guardar `errno`)                | glibc [Checking for Errors](https://www.sourceware.org/glibc/manual/latest/html_node/Checking-for-Errors.html) · `man 3 errno`/`perror`/`strerror` | [ ]    |
| Sáb 5  | **mysh v1.0**: fork + execvp para comandos externos, esperar hijo (sin `system()`)            | Brennan (parte v1.0) + UCI 143A                                                                                                                    | [ ]    |
| Dom 6  | Zettels + tick S3 + plan S4                                                                   | Zettel: `Linux - Processes and fork.md`                                                                                                            | [ ]    |

- **Blockers:** none

---

## Cambios de método & notas (2026-08-31)

- **Nuevo flujo diario (aprobado):** contexto breve (2 min) → **código primero** (intento sin leer, fallar con propósito) → video/recurso (15-25 min, ahora con preguntas reales) → código corregido + ejercicios progresivos → comentarios en el `.c` → yo genero el Zettel al cierre.
- **Obsidian sale del flujo diario:** ya no escribes notas a mano. Tú escribes comentarios en el código; yo leo el `.c` y genero la nota en Obsidian con la jerarquía conectada.
- **Estructura MOC en Obsidian:** notas índice renombradas a `MOC - <Tema>.md` (31), nuevo `MOC - Home.md` (MoC de MoCs) y `MOC - Processes.md` (clúster S3). Hubs de concepto general (`Functions.md`, `Loops.md`) completados con sus variantes por lenguaje.

## Próxima sesión — TODO

- S3 D1 (Lun 31): **¿Qué es un proceso?** (PCB/PID, imagen de memoria) + por qué mysh no usa `system()` (K&R 8.6, Sorber fork, `man 2 fork`). Contexto en `MOC - Processes` (Obsidian).

## Backlog — conceptos previos (S3–S10)

> Análisis 2026-08-16. Al abrir cada semana, incluir como día de concepto lo que aún no se ha visto. Detalle: [`README → Recovery Plan`](README.md#recovery-plan-f1-s0s10).

- **S3** — ¿Qué es un proceso? (PCB/PID, imagen de memoria) + `execvp`/`PATH` (por qué no `system()`).
- **S4** — v1.5 simplificado: shell ignora `SIGINT` mientras espera al hijo. Process groups diferidos.
- **S5** — Semántica de pipes (blocking, EOF, buffer) + diseño de la cadena en papel antes de codear.
- **S6** — Valgrind no corre en este entorno → fallback **AddressSanitizer** (`-fsanitize=address`).
- **S7** — Big O (Fiset intro) + linked list **head-return** (evita `Node**`, Beej 23 diferido).
- **S9** — Recursión (día de concepto antes de merge sort).

## Session log

- 2026-08-31 — **Reorganización Obsidian a MOC + nuevo método de estudio.** Auditoría de las ~655 notas del vault: identificadas 41 notas índice; 31 renombradas a `MOC - <Tema>.md` (9 lenguajes + 22 dominios) con cirugía de links (no quedan referencias a nombres viejos; `[[Database]]` case-insensitive mapeado a `MOC - DataBase`). Creados `MOC - Home.md` (MoC de MoCs agrupando por dominio: Lenguajes, OS/Linux, DSA, DB, Web, Mobile, Backend, IA, Tools, Arquitectura) y `MOC - Processes.md` (clúster S3: OS Processes, PCB, Diagram - Status of Process, Unix Process Pattern, System Calls, FDs, dup2, Unix, conectado a MOC - Operating Systems). Hubs de concepto general completados con sus variantes: Functions.md (+C/Dart/Kotlin/Python), Loops.md (+Bash/C/C++/C-Sharp/Dart/JS/Python), Variables.md (+C/Python/C-Sharp/Dart/JS/Kotlin), Arrays.md (+Kotlin/TS/C), Constantes.md (+C-Sharp), Scope.md (+C++), Estructuras Condicionales.md (fix typo `]]]` + Dart/JS/Python). Notas concepto (Unix, ML, DL, API, Backend, Cloud) intactas. **Nuevo flujo diario aprobado:** código primero → video → ejercicios progresivos → notas IA desde comentarios del `.c`. ZenNotes auto-backup `4bfa646` + commit `62b9ef7`.

- 2026-08-24 — **S2 cerrada.** v0.5 mysh terminada en pseudocódigo (deliverable S2 completo): REPL (read → parse → execute), lectura byte a byte con `read(0,&c,1)` + buffer creciente con `realloc`/temp-pointer shield, parseo con `strtok` → `args[]` NULL-terminado, dispatch de builtins `cd`/`echo`/`exit` con `strcmp == 0`, guard de línea vacía → `CONTINUE`, `chdir(args[1]) == -1` con guard `args[1] != NULL` y error → `CONTINUE` (no cierra el shell), `status = 1` inicial / `exit` → 0, `malloc`/`free` en lados opuestos del loop resueltos (use-after-free eliminado). NOTA para el C real: `echo` debe separar args con espacios y añadir `\n`. Pendiente D5 (errno) absorbido como concepto de refuerzo en S3 Vie 28. Tick S2 → `[x]` en Recovery Plan. S3 abierta (fork/exec/wait, mysh v1.0). Concepto `dup`/`dup2` + redirección: duplicar entradas de la tabla de FDs; el `>` de un shell es un `dup2(fd, 1)`. Ejercicio `4-systems/01-syscalls-processes/3-dup2-redirect.c`: patrón `open → dup2 → close` redirigiendo stdout a `data/redirect-with-dup2.txt` (`O_CREAT | O_TRUNC | O_WRONLY`, 0600, chequeo `== -1`). Lección del día: buffering de stdio — sin `\n` el `printf` "ANTES" se flushaba después del `dup2` y también caía al archivo (line-buffering solo en TTY, full buffering por pipe); con `\n` el primer mensaje sale por terminal y el segundo se guarda. Nota Obsidian nueva `Redirection and dup2 - Linux.md` (dup vs dup2, caso `oldfd == newfd`, patrón completo) + enlaces cruzados con la nota FD. Compila `-Wall -Wextra -g` sin warnings. Commit `d0181f5`.

- 2026-08-20 — **S2 D2 (Mar 18) cerrado.** Concepto FD (tabla 0/1/2, todo es un archivo) en notas Obsidian. Ejercicio `4-systems/01-syscalls-processes/2-read-write.c`: copiar input de terminal (fd 0) a `data/data.txt` (`O_WRONLY | O_CREAT | O_TRUNC`, 0644). Diseño con bucle externo de `read` hasta EOF (Ctrl+D) y bucle interno anti-partial-write (`write_ptr` + descuento de pendiente, chequeos `== -1` en open/write/close). Tipos: `ssize_t` para retornos de read/write, `size_t` para tamaño de buffer, `int` para open/close; includes `<fcntl.h>`/`<unistd.h>`. Compila `-Wall -Wextra -g` sin warnings y persiste el input tecleado. En `1-open-close.c` aplicado el fix del terminador: `write(1, buf, line)` (read no agrega `\0`). Commit `f7984f2`.

- 2026-08-17 — **S2 D1 (Lun) cerrado.** Concepto syscall (modo usuario vs kernel, trap, wrapper libc) en notas Obsidian. Código: `4-systems/01-syscalls-processes/1-open-close.c` — `open("data/data.txt", O_RDONLY)` + chequeo `== -1`, bucle `read(file, buf, size_buf)` > 0 mostrando con `printf("%s", buf)`, `close()` con chequeo. Depurado con Sócrates: faltaba `<fcntl.h>` (`implicit declaration of open`); segfault por `printf("%s", line)` (imprimía el byte-count, no la data — la data va en `buf`). Compila `-Wall -Wextra -g` sin warnings. NOTA: `buf` sin `\0` (read no lo agrega) → refinar con `write(1, buf, line)` o `buf[line]='\0'` en D2. Commit `feat(c): first open/close with read (S2)`.

- 2026-08-16 — **S1 cerrada.** Zettel `C - Stack vs Heap Memory Model.md` creado en Obsidian: stack (LIFO, crece abajo, lifetime = scope) vs heap (crece arriba, lifetime manual), las 4 leyes del heap (use-after-free / double-free / leak / OOB), `malloc` como wrapper de `brk`/`mmap`. Tick S1 → `[x]` en Recovery Plan (README). S2 abierta: syscalls + FDs (K&R 8, `man 2`); deliverable **mysh v0.5** (Sáb 22).

- 2026-08-15 — `2-dynamic-note-recording.c` (ej. 2) completed: growing-realloc pattern (capacity 1→2→4→8), invariant `count <= capacity`, temp-pointer shield on realloc failure, note range 0–7 (Chilean grading), EOF (Ctrl+D) = end of input via break, `buffer[32]` + `sscanf` per-line validation, senior-style comments + synced pseudocode. Compiled `-Wall -Wextra -g`, tested: averages, boundaries 0/7, rejection >7, `-1` only, Ctrl+D with/without notes. Committed `feat(c):`.
- 2026-08-12 — Beej 12 closed: `4-change-allocated-size.c` (realloc + NULL-protection; fixed loop range `0..39`) and `5-complete-example.c` (growing readline: comma-operator loop, doubling `realloc` + temp-pointer shield, shrink-to-fit; fixed missing `return NULL;` on realloc failure). Both compiled `-Wall -Wextra -g`, no warnings, exit 0 incl. missing-file case. NOTA: valgrind no ejecutable en este entorno (falta libc6-dbg / glibc debuginfo); verificado por ejecución directa.
- 2026-08-10 — Beej 12 dynamic memory allocation: created 1-allocating-deallocating.c, 2-error-checking.c, and 3-array-example.c (malloc, free, NULL protection, calloc, memset).
- 2026-08-07 — Rediseñado `status.md` a plan día a día: tabla de la semana con tema + recursos (referencia a `README.md#recursos-por-tema`, fuente única) + checkbox por día; regla de operación; plantilla S1 provisional. Comprometido `chore(docs):`.
- 2026-08-06 — Beej 10–11 closed: `2-advanced/04-typedef-types/typedef.c` (3 struct syntaxes + alias); `2-advanced/01-pointers/` split into `arithmetic-pointers.c` (incl. `my_strlen` subtraction), `void-pointers.c` (`my_memcpy`), `array-pointers.c` (array/pointer equivalence, fixed `*(a+i)` bug), `function-pointers.c`. All compiled `-Wall -Wextra -g`, no warnings. Committed `feat(c): learn typedef and pointer arithmetic (Beej 10-11)`. Next: Fri base Makefile + valgrind.
- 2026-08-06 — Added per-topic resources (Beej § + YouTube) to `README.md` (Recursos por tema) and roadmap video tables (threads, bitwise); marked `06-functions` done.
- 2026-08-06 — Beej 9 closed: `2-advanced/07-file-io/` read/write text + formatted + binary, all compiled `-Wall -Wextra -g`, valgrind 0 errors. Committed `feat(c): learn file input/output (Beej 9)`. Reorganized `learning-c/` into `1-basics/ 2-advanced/ 3-expert/ 4-systems/` (Obsidian mirror). Next: Beej 10 typedef + Beej 11 pointer arithmetic.
- 2026-08-05 — Planning: re-baseline F1, Recovery Plan S0–S10, canonical structure, AGENTS.md, daily-status mechanism. functions.c reviewed + committed (`feat(c): learn functions`). Next: Beej 9.
