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

## Estado actual — S4 (Sep 7 – 13)

> Signals (Beej 29, TLPI caps. 20–22, Sorber videos): entrega async, disposiciones, `signal()` vs `sigaction()`, disposiciones en fork/exec, `SIGCHLD`, async-signal-safe. Proyecto: **mysh v1.5** (Ctrl+C mata solo al hijo, no el shell).
> **Orden por dependencias (lección de S3):** cada día usa SOLO lo de días anteriores + S3. El milestone (Sáb) requiere Lun–Jue, nada futuro.

| Día    | Tema                                                                                                                 | Archivo (intento code-first)                    | Recurso JIT                                                                                                                                                      | Zettel al cierre (IA)                                                          | Estado |
| ------ | -------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------ | ------ |
| Lun 7  | **¿Qué es una señal?** entrega async, disposiciones default (terminar/ignorar/núcleo), señales comunes; generar con `raise()` y Ctrl+C | `3-expert/07-signals/1-signals-intro.c` | [intro señales](https://www.youtube.com/watch?v=5We_HtLlAbs) · Beej 29 · `man 7 signal` · TLPI cap. 20 | `Linux - Signals Intro.md`                                                     | [x]    |
| Mar 8  | **Instalar handlers**: `signal()` vs `sigaction()`, `SIG_DFL`/`SIG_IGN`/custom, `volatile sig_atomic_t`, enviar con `kill()`/`raise()` | `3-expert/07-signals/2-signal-sigaction.c` | [kill/signal/sigaction](https://www.youtube.com/watch?v=83M5-NPDeWs) · `man 2 sigaction`/`kill` · TLPI caps. 20–21 | `Linux - sigaction and Handler Installation.md`                               | [ ]    |
| Mié 9  | **Disposiciones en fork/exec** (corazón de mysh v1.5): herencia por fork, exec resetea handlers capturados→default pero **mantiene SIG_IGN** → hijo debe resetear a `SIG_DFL` antes de `exec` | `3-expert/07-signals/3-fork-exec-disposition.c` | `man 7 signal` (disposiciones) · `man 2 sigaction`/`execve` · TLPI caps. 20–22 | `Linux - Signal Dispositions across fork and exec.md`                          | [ ]    |
| Jue 10 | **`SIGCHLD` + reaping async**: instalar handler + `waitpid(WNOHANG)`; conecta wait de S3, prepara mysh                  | `3-expert/07-signals/4-sigchld-reap.c`          | `man 2 waitpid`/`sigaction` · TLPI caps. 20–26 · Sorber (reap) | `Linux - SIGCHLD and Asynchronous Reaping.md`                                 | [ ]    |
| Vie 11 | Gotchas: **async-signal-safe** (`write` no `printf` en handler), `SA_RESTART`, refuerzo de la semana                     | `3-expert/07-signals/5-signal-safety.c`         | `man 7 signal-safety` · `man 2 sigaction` (flags) · TLPI caps. 20–22 | `Linux - Async-Signal-Safe Functions.md` + refuerzo                            | [ ]    |
| Sáb 12 | **mysh v1.5**: shell ignora SIGINT mientras espera al hijo; hijo resetea SIGINT a default antes de `execvp`          | `projects/mysh/src/mysh.c` (v1.5)                | Brennan (v1.5) + conceptos Lun–Jue (sin recursos futuros)                                            | `C - mysh v1.5 Ignoring SIGINT` + revisar | [ ]    |
| Dom 13 | Zettels + tick S4 + plan S5                                                                                           | —                                                 | —                                                                                                                                                                | Revisar Zettels IA + abrir S5                                                   | [ ]    |

- **Blockers:** none

## Próxima sesión — TODO

- **S4 Mar (Mar 8): D2 — Instalar handlers**: `signal()` vs `sigaction()`, `SIG_DFL`/`SIG_IGN`/custom, `volatile sig_atomic_t`, enviar con `kill()`/`raise()`. Crear `3-expert/07-signals/2-signal-sigaction.c` con el Contrato diario.
- _Recordar: cada día de S4 usa solo lo de días anteriores (orden por dependencias). No adelantar conceptos futuros._

## Historial

- **S4 D1 (2026-09-07):** Signals intro cerrado — `1-signals-intro.c` (software interrupts, ciclo generada→pendiente→entregada, `raise(SIGINT)`, inspección de `status` con `WIFSIGNALED`/`WTERMSIG` + retorno `128+señal`). Exercise `01-mysh-preview.c`: verificación de PGID heredado (`getpgrp()`) y entrega simultánea de `SIGINT` por la TTY en primer plano. Zettel `Linux - Signals Intro.md` generado y enlazado en `MOC - Processes`. Próxima: Mar 8 sigaction (`2-signal-sigaction.c`).

- **S3 — CIERRE DE SEMANA (2026-09-06):** Processes cerrada (fork/exec/wait, zombies, errno). **MILESTONE mysh v1.0** (`git tag -a v1.0`): externos sin `system()`, estado `WIF*`/`128+señal`. 8 Zettels. Próximo: S4 Signals + mysh v1.5.
- **S3 D6 — MILESTONE mysh v1.0 (2026-09-05):** `projects/mysh/src/mysh.c` v1.0 cerrado y taggeado (`git tag -a v1.0`). Externos con `fork`+`execvp`+`wait` sin `system()`; propagación de estado `WIFEXITED`/`WIFSIGNALED` + `128+señal` + `last_status` (builtins incluidos); prompt con `fflush(stdout)`; errores a stderr con `fprintf`. Refactor portfolio (README + docs honestos). Zettels nuevos (`C - return vs exit vs _exit`, `C - stdio Buffering and fflush`) + macros `WIF*` en nota de wait. Ver session-log.
- **S3 D5 (2026-09-04):** `errno` + manejo de errores cerrado — `8-errno.c` (fork + execvp de un binario inexistente `ERROR__`; `strerror(errno)` en la rama de fallo; padre propaga el código real con `WEXITSTATUS`). Formalizado el gotcha: `errno` es global y otra llamada de libc puede pisarlo → leerlo ya o guardarlo. Exercise `03` (aplicado a mysh): `exercise/2-errno.c` — reporta "Binario no encontrado" y sale con `1`. Zettel `Linux - errno and Error Handling.md` generado y enlazado al MOC - Processes. Mañana: **milestone mysh v1.0**.
- **S3 D4 (2026-09-03):** `execvp` + PATH cerrado — `7-execvp-path.c` (A/B: `execv("ls")` falla ENOENT por no buscar en PATH vs `execv("/usr/bin/ls")` y `execvp("ls")` funcionan; la `p` hace el PATH lookup). De regalo: manejo de errores real (fork `-1`, `execvp` retorna solo al fallar, `errno`/`perror`, `wait` + `WIFEXITED`/`WEXITSTATUS` para propagar el código del hijo al `$?` — visto como adelanto de D5). Desvío metodológico: me llevé al usuario por el rabbit hole de la propagación de estado (D5/mysh) en vez de anclarlo a D4; corregido a tiempo. Pendiente anotado para mysh: rama `WIFSIGNALED`/`WTERMSIG` (muerte por señal) aún sin implementar. Zettel D4 generado. Ver session-log.
- **S3 D3 (2026-09-02):** `exec` family + `wait` cerrados — `6-exec-wait.c` (fork + execvp de `ls` + wait, reaping). De regalo: `argc`/`argv` (receptor) + mnemónico `l`/`v` resuelto vía Sócrates (P3: `l` solo compile-time; `v` = superconjunto compile+runtime). Pendientes: exercises 01–03 y Zettel `Linux - exec and Zombie Reaping.md`. Ver session-log.
- **S3 D2 (2026-09-01):** `fork` cerrado — `5-fork-basic.c` (creación padre/hijo, retornos -1/0/PID) + `exercise/1-for-pid.c` (getpid vs getppid; debugging: el padre imprimía el PID del shell con `getppid()`). Zettel `Linux - Fork and Process Creation.md`. Lección: el scheduler decide el orden, la sincronización se gestiona con wait/pipe.
- **Última sesión (2026-08-31):** S3 D1 cerrado (¿qué es un proceso?) + método actualizado a code-first/JIT/inverted PBL + reorganización Obsidian a MOC.
- **S2 (2026-08-17/20/24):** syscalls + FDs; mysh v0.5 en pseudocódigo.
- **S1 (2026-08-10/16):** stack vs heap, `malloc`/`free`; Zettel Stack vs Heap.
- **Historial completo:** [`session-log.md`](session-log.md)
