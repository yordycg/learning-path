# Status — Phase 1 (learning-c)

> **Estado operativo SOLO.** Conceptos → Obsidian · Historia → [`session-log.md`](session-log.md). Start each session: read this file + `git log -1`.

## Cómo operar este archivo

- "¿Qué toca hoy?" → se responde con la fila de hoy de _Current Week_ + el **Contrato diario** de abajo.
- Al cierre de sesión: `[ ]` → `[x]` en la fila del día + entrada al `session-log.md`.
- Al cerrar la semana (Dom): archivar las filas en el `session-log.md`, abrir la siguiente, dejar resumen de 2 líneas de la semana pasada.
- **Code-first:** cada día empieza con el intento de código (sin leer). El recurso se abre just-in-time solo cuando el código falla.
- En el tick semanal (Dom): consultar el **Backlog — conceptos previos** en [`README → Recovery Plan`](README.md#recovery-plan-f1-s0s10) para incluir el concepto pendiente de la semana que se abre.
- Ritmo semanal: [`calendario.md`](../calendario.md) (fuente única del modelo estacional y el horario).

## Contrato diario de respuesta (obligatorio para la IA)

Al pedir "¿qué toca hoy?", responder **siempre** con: (1) árbol de contexto (OS → Process → fork → mysh), (2) contexto de 2 min (QUÉ hace el concepto, sin el CÓMO), (3) archivo `.c` a crear con ruta exacta + comando gcc, (4) recurso **just-in-time** (nombre + link, se abre SOLO si el código falla), (5) 3 ejercicios progresivos opcionales en `exercises/01-*.c` / `02-*.c` / `03-*.c` (básico → aplicado → integrado con mysh), y (6) plantilla de comentarios para el `.c`. El Zettel de Obsidian lo genera la IA al cierre desde los comentarios.

**Sábado = milestone del proyecto:** avanza `mysh` a la versión de la semana (`v1.0` en S3). Commits por feature + `git tag vX.Y`. Detalle: `docs/roadmap.md → Ritmo del proyecto semana a semana`.

## Estado actual — S3 (Aug 31 – Sep 6)

> Processes (K&R 8, `man 2`, Sorber fork video): `fork`/`exec`/`wait`, zombies. Proyecto: **mysh v1.0** (comandos externos, `execvp` + `PATH`, **sin** `system()`).

| Día    | Tema                                                                                          | Archivo (intento code-first)                      | Recurso JIT                                                                                                                                  | Zettel al cierre (IA)                          | Estado |
| ------ | --------------------------------------------------------------------------------------------- | ------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------- | ------ |
| Lun 31 | **¿Qué es un proceso?** (PCB/PID, imagen de memoria, estado) + por qué mysh no usa `system()` | `4-systems/01-syscalls-processes/4-process.c`     | K&R 8.6 · [fork()](https://www.youtube.com/watch?v=ss1-REMJ9GA) (Sorber) · `man 2 fork`/`execve` · OSTEP caps. 4–6                            | `Linux - What is a Process.md`                  | [x]    |
| Mar 1  | **`fork`**: creación de proceso hijo, copia de memoria, fork/exec split                       | `4-systems/01-syscalls-processes/5-fork-basic.c`  | [fork()](https://www.youtube.com/watch?v=ss1-REMJ9GA) (Sorber) · K&R 8.6 · `man 2 fork`                                                       | `Linux - Fork and Process Creation.md`          | [x]    |
| Mié 2  | **`exec` family + `wait`**: reemplazo de imagen, zombies y reaping                            | `4-systems/01-syscalls-processes/6-exec-wait.c`   | [exec/execvp](https://www.youtube.com/watch?v=-_7BcxBr4P4) (Sorber) · K&R 8.6 · `man 2 execve`/`wait` · TLPI caps. 24–27                       | `Linux - exec and Zombie Reaping.md`            | [x]    |
| Jue 3  | **`execvp` + PATH**: búsqueda del binario en `$PATH`, por qué `execvp` y no `system()`        | `4-systems/01-syscalls-processes/7-execvp-path.c` | [exec/execvp](https://www.youtube.com/watch?v=-_7BcxBr4P4) (Sorber) · `man 3 execvp`/`man 7 environ`                                          | `Linux - execvp and PATH Lookup.md`             | [x]    |
| Vie 4  | Buffer / refuerzo — **errno** (`perror`/`strerror`, gotcha de guardar `errno`)                | `4-systems/01-syscalls-processes/8-errno.c`       | glibc [Checking for Errors](https://www.sourceware.org/glibc/manual/latest/html_node/Checking-for-Errors.html) · `man 3 errno`/`perror`/`strerror` | `Linux - errno and Error Handling.md`           | [x]    |
| Sáb 5  | **mysh v1.0**: fork + execvp para comandos externos, esperar hijo (sin `system()`)            | `projects/mysh/src/mysh.c` (v1.0)                 | Brennan (parte v1.0) + UCI 143A                                                                                                              | `C - return vs exit vs _exit` + `C - stdio Buffering and fflush` (+ macros `WIF*` en nota de wait) | [x]    |
| Dom 6  | Zettels + tick S3 + plan S4                                                                   | —                                                 | —                                                                                                                                            | Revisar Zettels IA + abrir S4                   | [ ]    |

- **Blockers:** none

## Próxima sesión — TODO

- **S3 Dom (Dom 6): CIERRE DE SEMANA** — Zettels pendientes revisados + tick S3 + **abrir S4** en `status.md`. Filas S3 ya cerradas; Dom queda de Zettels/tick. Consultar el **Backlog — conceptos previos** en [`README → Recovery Plan`](README.md#recovery-plan-f1-s0s10) para el concepto de refuerzo de la semana que se abre. Archivar filas S3 completadas en `session-log.md` y dejar resumen de 2 líneas en Historial. **Sáb 5 (milestone v1.0) quedó CERRADO** con `git tag -a v1.0` en `projects/mysh`.
- _Pendiente opcional de mysh (fuera de scope v1.0, para S4+): exercises de D3 (`zombie` en `Z` con `ps` y proto-mysh) como refuerzo._

## Historial

- **S3 D6 — MILESTONE mysh v1.0 (2026-09-05):** `projects/mysh/src/mysh.c` v1.0 cerrado y taggeado (`git tag -a v1.0`). Externos con `fork`+`execvp`+`wait` sin `system()`; propagación de estado `WIFEXITED`/`WIFSIGNALED` + `128+señal` + `last_status` (builtins incluidos); prompt con `fflush(stdout)`; errores a stderr con `fprintf`. Refactor portfolio (README + docs honestos). Zettels nuevos (`C - return vs exit vs _exit`, `C - stdio Buffering and fflush`) + macros `WIF*` en nota de wait. Ver session-log.
- **S3 D5 (2026-09-04):** `errno` + manejo de errores cerrado — `8-errno.c` (fork + execvp de un binario inexistente `ERROR__`; `strerror(errno)` en la rama de fallo; padre propaga el código real con `WEXITSTATUS`). Formalizado el gotcha: `errno` es global y otra llamada de libc puede pisarlo → leerlo ya o guardarlo. Exercise `03` (aplicado a mysh): `exercise/2-errno.c` — reporta "Binario no encontrado" y sale con `1`. Zettel `Linux - errno and Error Handling.md` generado y enlazado al MOC - Processes. Mañana: **milestone mysh v1.0**.
- **S3 D4 (2026-09-03):** `execvp` + PATH cerrado — `7-execvp-path.c` (A/B: `execv("ls")` falla ENOENT por no buscar en PATH vs `execv("/usr/bin/ls")` y `execvp("ls")` funcionan; la `p` hace el PATH lookup). De regalo: manejo de errores real (fork `-1`, `execvp` retorna solo al fallar, `errno`/`perror`, `wait` + `WIFEXITED`/`WEXITSTATUS` para propagar el código del hijo al `$?` — visto como adelanto de D5). Desvío metodológico: me llevé al usuario por el rabbit hole de la propagación de estado (D5/mysh) en vez de anclarlo a D4; corregido a tiempo. Pendiente anotado para mysh: rama `WIFSIGNALED`/`WTERMSIG` (muerte por señal) aún sin implementar. Zettel D4 generado. Ver session-log.
- **S3 D3 (2026-09-02):** `exec` family + `wait` cerrados — `6-exec-wait.c` (fork + execvp de `ls` + wait, reaping). De regalo: `argc`/`argv` (receptor) + mnemónico `l`/`v` resuelto vía Sócrates (P3: `l` solo compile-time; `v` = superconjunto compile+runtime). Pendientes: exercises 01–03 y Zettel `Linux - exec and Zombie Reaping.md`. Ver session-log.
- **S3 D2 (2026-09-01):** `fork` cerrado — `5-fork-basic.c` (creación padre/hijo, retornos -1/0/PID) + `exercise/1-for-pid.c` (getpid vs getppid; debugging: el padre imprimía el PID del shell con `getppid()`). Zettel `Linux - Fork and Process Creation.md`. Lección: el scheduler decide el orden, la sincronización se gestiona con wait/pipe.
- **Última sesión (2026-08-31):** S3 D1 cerrado (¿qué es un proceso?) + método actualizado a code-first/JIT/inverted PBL + reorganización Obsidian a MOC.
- **S2 (2026-08-17/20/24):** syscalls + FDs; mysh v0.5 en pseudocódigo.
- **S1 (2026-08-10/16):** stack vs heap, `malloc`/`free`; Zettel Stack vs Heap.
- **Historial completo:** [`session-log.md`](session-log.md)
