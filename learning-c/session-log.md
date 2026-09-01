# Session Log — Phase 1 (learning-c)

> **Append-only archive.** Nuevas entradas arriba. Referenciado desde [`status.md`](status.md). Este archivo es historia; el panel operativo (semana/día actual, próximo día) vive en `status.md`.

## 2026-09-01 (tarde) — S3 D2 cerrado

`fork` — creación de procesos. Archivo principal `4-systems/01-syscalls-processes/5-fork-basic.c`: `fork()` crea un hijo (copia de memoria, espacios separados, contenido idéntico), retornos gestionados en 3 ramas (`-1` error, `0` hijo, `child_pid` padre). Ejercicio `exercise/1-for-pid.c` (PID/PPID): debugging socrático con 3 iteraciones — (1) ambas ramas imprimían el PID del hijo (padre usaba `child_pid`), (2) el padre imprimía `getppid()` = PID del **shell** (su padre, no él), (3) fix: `getpid()` en la rama padre + invariante `getppid()` del hijo == `getpid()` del padre. Lección clave: `getppid()` devuelve el padre *del que la llama*, no el propio PID. Aprendido que el scheduler decide el orden de ejecución (sin garantías) y que la coordinación se gestiona con `wait()`/pipe/otros mecanismos de sincronización. Zettel Obsidian `Linux - Fork and Process Creation.md` generado y enlazado en `MOC - Processes`. Mar 1 → `[x]`. Próxima: Mié 2 `exec` family + `wait` (zombies y reaping), `6-exec-wait.c`.

## 2026-08-31 (tarde) — S3 D1 cerrado

Estudiado ¿qué es un proceso? (PCB/PID, imagen de memoria, estados) + por qué mysh no usa `system()` — notas conceptuales escritas por el usuario (última vez a mano; de aquí en adelante las genera la IA al cierre desde los comentarios del `.c`). **Método actualizado en docs:** roadmap reescrito a code-first + just-in-time + inverted PBL (`4941595`), tabla "el artefacto del día según la fase" + status.md con contrato diario code-first (`ed50e18`), convención `exercises/01-*.c` opcionales + ritmo del sábado (milestone mysh semana a semana, git tags) (`cf8ab52` en learning-path, `0ce8d55` en projects/mysh). Lun 31 → `[x]`. Próxima: Mar 1 `fork` (5-fork-basic.c).

## 2026-08-31 — Reorganización Obsidian a MOC + nuevo método de estudio

Auditoría de las ~655 notas del vault: identificadas 41 notas índice; 31 renombradas a `MOC - <Tema>.md` (9 lenguajes + 22 dominios) con cirugía de links (no quedan referencias a nombres viejos; `[[Database]]` case-insensitive mapeado a `MOC - DataBase`). Creados `MOC - Home.md` (MoC de MoCs agrupando por dominio: Lenguajes, OS/Linux, DSA, DB, Web, Mobile, Backend, IA, Tools, Arquitectura) y `MOC - Processes.md` (clúster S3: OS Processes, PCB, Diagram - Status of Process, Unix Process Pattern, System Calls, FDs, dup2, Unix, conectado a MOC - Operating Systems). Hubs de concepto general completados con sus variantes: Functions.md (+C/Dart/Kotlin/Python), Loops.md (+Bash/C/C++/C-Sharp/Dart/JS/Python), Variables.md (+C/Python/C-Sharp/Dart/JS/Kotlin), Arrays.md (+Kotlin/TS/C), Constantes.md (+C-Sharp), Scope.md (+C++), Estructuras Condicionales.md (fix typo `]]]` + Dart/JS/Python). Notas concepto (Unix, ML, DL, API, Backend, Cloud) intactas. **Nuevo flujo diario aprobado:** código primero → video → ejercicios progresivos → notas IA desde comentarios del `.c`. ZenNotes auto-backup `4bfa646` + commit `62b9ef7`.

## 2026-08-24 — S2 cerrada

v0.5 mysh terminada en pseudocódigo (deliverable S2 completo): REPL (read → parse → execute), lectura byte a byte con `read(0,&c,1)` + buffer creciente con `realloc`/temp-pointer shield, parseo con `strtok` → `args[]` NULL-terminado, dispatch de builtins `cd`/`echo`/`exit` con `strcmp == 0`, guard de línea vacía → `CONTINUE`, `chdir(args[1]) == -1` con guard `args[1] != NULL` y error → `CONTINUE` (no cierra el shell), `status = 1` inicial / `exit` → 0, `malloc`/`free` en lados opuestos del loop resueltos (use-after-free eliminado). NOTA para el C real: `echo` debe separar args con espacios y añadir `\n`. Pendiente D5 (errno) absorbido como concepto de refuerzo en S3 Vie 28. Tick S2 → `[x]` en Recovery Plan. S3 abierta (fork/exec/wait, mysh v1.0). Concepto `dup`/`dup2` + redirección: duplicar entradas de la tabla de FDs; el `>` de un shell es un `dup2(fd, 1)`. Ejercicio `4-systems/01-syscalls-processes/3-dup2-redirect.c`: patrón `open → dup2 → close` redirigiendo stdout a `data/redirect-with-dup2.txt` (`O_CREAT | O_TRUNC | O_WRONLY`, 0600, chequeo `== -1`). Lección del día: buffering de stdio — sin `\n` el `printf` "ANTES" se flushaba después del `dup2` y también caía al archivo (line-buffering solo en TTY, full buffering por pipe); con `\n` el primer mensaje sale por terminal y el segundo se guarda. Nota Obsidian nueva `Redirection and dup2 - Linux.md` (dup vs dup2, caso `oldfd == newfd`, patrón completo) + enlaces cruzados con la nota FD. Compila `-Wall -Wextra -g` sin warnings. Commit `d0181f5`.

## 2026-08-20 — S2 D2 (Mar 18) cerrado

Concepto FD (tabla 0/1/2, todo es un archivo) en notas Obsidian. Ejercicio `4-systems/01-syscalls-processes/2-read-write.c`: copiar input de terminal (fd 0) a `data/data.txt` (`O_WRONLY | O_CREAT | O_TRUNC`, 0644). Diseño con bucle externo de `read` hasta EOF (Ctrl+D) y bucle interno anti-partial-write (`write_ptr` + descuento de pendiente, chequeos `== -1` en open/write/close). Tipos: `ssize_t` para retornos de read/write, `size_t` para tamaño de buffer, `int` para open/close; includes `<fcntl.h>`/`<unistd.h>`. Compila `-Wall -Wextra -g` sin warnings y persiste el input tecleado. En `1-open-close.c` aplicado el fix del terminador: `write(1, buf, line)` (read no agrega `\0`). Commit `f7984f2`.

## 2026-08-17 — S2 D1 (Lun) cerrado

Concepto syscall (modo usuario vs kernel, trap, wrapper libc) en notas Obsidian. Código: `4-systems/01-syscalls-processes/1-open-close.c` — `open("data/data.txt", O_RDONLY)` + chequeo `== -1`, bucle `read(file, buf, size_buf)` > 0 mostrando con `printf("%s", buf)`, `close()` con chequeo. Depurado con Sócrates: faltaba `<fcntl.h>` (`implicit declaration of open`); segfault por `printf("%s", line)` (imprimía el byte-count, no la data — la data va en `buf`). Compila `-Wall -Wextra -g` sin warnings. NOTA: `buf` sin `\0` (read no lo agrega) → refinar con `write(1, buf, line)` o `buf[line]='\0'` en D2. Commit `feat(c): first open/close with read (S2)`.

## 2026-08-16 — S1 cerrada

Zettel `C - Stack vs Heap Memory Model.md` creado en Obsidian: stack (LIFO, crece abajo, lifetime = scope) vs heap (crece arriba, lifetime manual), las 4 leyes del heap (use-after-free / double-free / leak / OOB), `malloc` como wrapper de `brk`/`mmap`. Tick S1 → `[x]` en Recovery Plan (README). S2 abierta: syscalls + FDs (K&R 8, `man 2`); deliverable **mysh v0.5** (Sáb 22).

## 2026-08-15

`2-dynamic-note-recording.c` (ej. 2) completed: growing-realloc pattern (capacity 1→2→4→8), invariant `count <= capacity`, temp-pointer shield on realloc failure, note range 0–7 (Chilean grading), EOF (Ctrl+D) = end of input via break, `buffer[32]` + `sscanf` per-line validation, senior-style comments + synced pseudocode. Compiled `-Wall -Wextra -g`, tested: averages, boundaries 0/7, rejection >7, `-1` only, Ctrl+D with/without notes. Committed `feat(c):`.

## 2026-08-12

Beej 12 closed: `4-change-allocated-size.c` (realloc + NULL-protection; fixed loop range `0..39`) and `5-complete-example.c` (growing readline: comma-operator loop, doubling `realloc` + temp-pointer shield, shrink-to-fit; fixed missing `return NULL;` on realloc failure). Both compiled `-Wall -Wextra -g`, no warnings, exit 0 incl. missing-file case. NOTA: valgrind no ejecutable en este entorno (falta libc6-dbg / glibc debuginfo); verificado por ejecución directa.

## 2026-08-10

Beej 12 dynamic memory allocation: created 1-allocating-deallocating.c, 2-error-checking.c, and 3-array-example.c (malloc, free, NULL protection, calloc, memset).

## 2026-08-07

Rediseñado `status.md` a plan día a día: tabla de la semana con tema + recursos (referencia a `README.md#recursos-por-tema`, fuente única) + checkbox por día; regla de operación; plantilla S1 provisional. Comprometido `chore(docs):`.

## 2026-08-06

Beej 10–11 closed: `2-advanced/04-typedef-types/typedef.c` (3 struct syntaxes + alias); `2-advanced/01-pointers/` split into `arithmetic-pointers.c` (incl. `my_strlen` subtraction), `void-pointers.c` (`my_memcpy`), `array-pointers.c` (array/pointer equivalence, fixed `*(a+i)` bug), `function-pointers.c`. All compiled `-Wall -Wextra -g`, no warnings. Committed `feat(c): learn typedef and pointer arithmetic (Beej 10-11)`. Next: Fri base Makefile + valgrind.

## 2026-08-06

Added per-topic resources (Beej § + YouTube) to `README.md` (Recursos por tema) and roadmap video tables (threads, bitwise); marked `06-functions` done.

## 2026-08-06

Beej 9 closed: `2-advanced/07-file-io/` read/write text + formatted + binary, all compiled `-Wall -Wextra -g`, valgrind 0 errors. Committed `feat(c): learn file input/output (Beej 9)`. Reorganized `learning-c/` into `1-basics/ 2-advanced/ 3-expert/ 4-systems/` (Obsidian mirror). Next: Beej 10 typedef + Beej 11 pointer arithmetic.

## 2026-08-05

Planning: re-baseline F1, Recovery Plan S0–S10, canonical structure, AGENTS.md, daily-status mechanism. functions.c reviewed + committed (`feat(c): learn functions`). Next: Beej 9.
