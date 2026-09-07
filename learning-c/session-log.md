# Session Log — Phase 1 (learning-c)

> **Append-only archive.** Nuevas entradas arriba. Referenciado desde [`status.md`](status.md). Este archivo es historia; el panel operativo (semana/día actual, próximo día) vive en `status.md`.

## 2026-09-07 — S4 D1 cerrado

Inicio de Semana 4 (Signals): concepto de señal como interrupción por software (*software interrupt*), ciclo de vida (generada → pendiente → entregada; TLPI cap. 20) y disposiciones por defecto en Linux (`man 7 signal`: Term, Core, Ign, Stop, Cont). Archivo principal `3-expert/07-signals/1-signals-intro.c`: proceso hijo en bucle con auto-envío sincrónico `raise(SIGINT)`, padre inspeccionando estado con `wait(&status)` + `WIFSIGNALED`/`WTERMSIG` y propagando el código estándar `128 + señal` (`$?` = 130). Experimento con `raise(SIGCHLD)` comprobó que las señales con disposición `Ign` no interrumpen la ejecución. Ejercicio aplicado a mysh `3-expert/07-signals/exercises/01-mysh-preview.c`: verificación empírica de grupos de procesos (`getpgrp()`) demostrando que padre e hijo heredan y comparten el *Foreground Process Group* asignado por la terminal (TTY); presionar `Ctrl+C` envía la señal a todo el grupo a la vez y mata a ambos procesos, motivando la necesidad de ignorar `SIGINT` en la shell para el hito `mysh v1.5` del sábado. Zettel `Linux - Signals Intro.md` generado y enlazado en `MOC - Processes`. Próximo: Mar 8 — instalación de handlers con `sigaction` (`2-signal-sigaction.c`).

## 2026-09-06 — S3 Dom: CIERRE DE SEMANA S3 (Processes)

Semana S3 (Aug 31 – Sep 6) cerrada: procesos con `fork`/`exec`/`wait`, zombies y reaping, `execvp`+PATH, `errno`. **MILESTONE mysh v1.0** (Sáb 5, `git tag -a v1.0`): externos con fork+execvp+wait sin `system()`, propagación de estado `WIF*`/`128+señal`, `fflush` en prompt. 8 Zettels de la semana generados y enlazados (MOC - Processes / MOC - C). Blocker: none. Pendiente opcional diferido a S4+: exercises zombie de D3. Próximo: **abrir S4 (Signals)** para Lun 7 — conceptos: qué es una señal, disposiciones, `signal()` vs `sigaction()`, `kill`/`raise`, handler async-safe; milestone **mysh v1.5** (Ctrl+C mata solo al hijo).

## 2026-09-05 — S3 D6: MILESTONE mysh v1.0 cerrado

`projects/mysh/src/mysh.c` v1.0 implementado, compilando limpio (`-Wall -Wextra -Wpedantic -std=c11`), verificado con ASan+UBSan (sin fugas/UB) y `git tag v1.0`. Sesión guiada Socráticamente (3 bugs encontrados y resueltos por el alumno con diagnóstico): **(1) `echo`** — el fix de "espacio-prefijo" sin condición dejaba leading space; y un intento de tocar `args[arg_count]` (el slot `NULL` terminador) produjo segfault diagnosticado con AddressSanitizer (`strlen(NULL)`, `rdi=0`, línea 107). Solución limpia: `if/else` con espacio-prefijo solo para `i>1` (un `printf` por token, ramas exclusivas). **(2) `cd` sin arg** — el gotcha de errno invertido: usaba `perror` sin syscall fallida → imprimía `: Success` (`strerror(0)`). Aprendida la clasificación senior: error de SO → `perror`/`errno`; error de uso lógico → `fprintf(stderr, ...)`. **(3) propagación de estado** — rama `WIFEXITED`/`WIFSIGNALED` mutuamente excluyentes; `last_status` (uninit arreglado → `=0`), convención `128+señal` (SIGSEGV→139), builtins también actualizan `last_status`. Aprendido el mapa `return`≡`exit` (vacían buffers/atexit) vs `_exit` (hijo post-fork, no flushea buffers copiados). Aprendido el bug del prompt: `printf("mysh> ")` sin `\n` en stdout line-buffered no se ve → `fflush(stdout)` antes del `read()` (no `fflush(stdin)`). Refactor portfolio: header `@learn`/comentarios-qué removidos, quedan 2 porqués; `README.md` y `docs/pseudocode-v0.5/v1.0` reescritos honestos (implementado vs roadmap "en veremos"). Commits: `feat(mysh): implement v1.0 shell...` (`b90af5c`), `git tag -a v1.0`. Zettels: **nuevos** `C - return vs exit vs _exit`, `C - stdio Buffering and fflush`; **modificados** `Linux - exec and Zombie Reaping` (macros `WIF*` + `128+señal`), `Linux - errno and Error Handling` (rama señal), `MOC - C`, `MOC - Processes`. Próximo (Dom): tick S3 + abrir S4.

## 2026-09-04 (mañana) — S3 D5 cerrado

`errno` + manejo de errores formalizado sobre el andamiaje `fork` → `exec` → `wait` de D3/D4. Principal `4-systems/01-syscalls-processes/8-errno.c`: fork + `execvp` de un binario inexistente (`ERROR__`) para **forzar** la rama de error real — `strerror(errno)` imprime "No such file or directory" y el padre propaga el código con `WEXITSTATUS(status)` → exit code `1` (no disfrazado de `0`). Gotcha del día (debate mentoría): `errno` es una variable **global** y *cualquiera* otra llamada de libc puede pisarla aunque no falle → la regla "léelo ya o guárdalo en un int local". No se escribió un bug a propósito; se documentó el contrato en comentario y se confirmó que el patrón usado (leer `strerror(errno)` en la misma expresión que el `exec` fallido) es el seguro. Exercise `03` aplicado a mysh: `exercise/2-errno.c` — reporta "Binario no encontrado" legible y sale con `1`. Zettel `Linux - errno and Error Handling.md` generado y enlazado en `MOC - Processes`. Próximo: **milestone mysh v1.0 (Sábado)** — comando externo con `fork`+`execvp`+`wait` sin `system()`.


## 2026-09-03 (mañana) — S3 D4 cerrado

`execvp` + PATH — la `p` hace el PATH lookup. Archivo principal `4-systems/01-syscalls-processes/7-execvp-path.c`: experimento A/B sobre el andamiaje `fork` → `exec` → `wait` de D3. **Movimiento A:** `execvp` con un comando inexistente → falla y deja `errno`. **Movimiento B:** contraste `execv("ls",...)` (sin `p`) → falla `ENOENT` "No such file or directory" porque trata `"ls"` como ruta literal relativa al cwd y NO busca en `$PATH`; `execv("/usr/bin/ls",...)` → funciona; `execvp("ls",...)` (con `p`) → funciona porque recorre `$PATH`. Conclusión del día: la `p` solo añade el PATH lookup cuando el nombre NO lleva `/`; si lleva `/`, `execvp` se comporta como `execv`. Comentarios `@learn` y `@new_questions` R// correctos en el archivo.

**De regalo (adelanto de D5, no el foco de D4):** error-handling real en el patrón fork/exec/wait — `perror`/`errno` vistos de pasada, y `wait(&status)` + `WIFEXITED(status)`/`WEXITSTATUS(status)` para PROPAGAR el código real del hijo al `$?` del programa (antes `main` devolvía `0` aunque el hijo fallara → `echo $?` mentía; se arregló devolviendo `WEXITSTATUS(status)`). Usuario descubrió la diferencia entre `printf` (imprimir) y `return` (devolver a la shell). Definición formal de errno/perror/WIF* queda para D5.

**Nota metodológica (error mío, corregido):** pedí revisar el manejo de errores y me llevé al usuario por el rabbit hole de la propagación de estado (`WIFSIGNALED`/`WTERMSIG`, `128+`, fall-through) — contenido de D5/robustez de mysh, NO de D4. El usuario me frenó con feedback válido: me estaba haciendo ver conceptos nuevos fuera de plan y sin sintaxis clara sobre la marcha. Reconocido, frenado a tiempo, y re-anclado al objetivo real de D4 (A/B del PATH). Lección: anclar cada sesión a la fila del día y no abrir cajas de temas futuros aunque el usuario pregunte; dar tarjeta-patrón canónica de sintaxis cuando pida estructura en vez de hacerlo buscar a ciegas.

**Pendientes anotados para mysh/robustez (NO de D4, se aplazan):** rama `WIFSIGNALED`/`WTERMSIG` (muerte por señal) aún sin implementar en el padre — fall-through a `return 0` si el hijo es matado por señal. Exercises de D3 `02` (zombie en `Z`) y `03` (proto-mysh) siguen abiertos. Jue 3 → `[x]`. Próxima: Vie 4 errno (`8-errno.c`). Zettel D4 `Linux - execvp and PATH Lookup.md` generado + enlazado en `MOC - Processes`.

## 2026-09-02 (tarde) — S3 D3 cerrado

`exec` family + `wait` — reemplazo de imagen de proceso + reaping. Archivo principal `4-systems/01-syscalls-processes/6-exec-wait.c`: `fork` → hijo hace `execvp("ls", {"ls","-l","/tmp",NULL})` (array NULL-terminado, `argv[0]` = nombre del programa, imita a la shell) → padre `wait(&status)`. Compila `-Wall -Wextra -g` sin warnings, ejecuta bien (salida `ls -l /tmp`, exit 0).

**Dudas previas resueltas vía Sócrates (sin spoonfeed):** el usuario no conocía `argc`/`argv` (receptor). Se construyó el modelo por capas: (1) quién está vivo cuando (la shell espera la línea, `ls` nace después con args ya agrupados), (2) la shell entrega un array de strings terminado en `NULL` que `main` recibe como `argc` (cuenta incl. `argv[0]`) + `argv` (vector de strings NULL-terminado); tabla `ls -l /tmp` → argv[0..2] + NULL, argc=3.

**Trampa `l` vs `v` desenmascarada:** NO es la estructura interna (lista/vector = sinónimos para él) sino la FORMA de la llamada — `v` = pasar un puntero a array ya construido (por eso un shell, con args desconocidos hasta runtime, usa `v`), `l` = escribirlos sueltos separados por coma en la llamada. Bug socrático detectado en revisión: el usuario reutilizaba `status` para el retorno de `execvp` Y para `wait` (funciona por copia de memoria tras fork pero es vicio de diseño) → rediseñado a `if (execvp(...) == -1)` directo, `status` solo para `wait`. Nueva pregunta 3 (compile-time vs runtime) auto-resuelta por el usuario tras señalarle la contradicción de SU código (usó `v` con literales compile-time): concluyó que `l` solo sirve en compile-time (nº de args fijo) y `v` es superconjunto (compile-time Y runtime) — correcto.

**Pendientes (se acabó el tiempo):** exercises 01 (estado de salida `WIFEXITED`/`WEXITSTATUS`), 02 (zombie en estado `Z` con `ps` mientras el padre `sleep` sin `wait`), 03 (proto-mysh: bucle `fgets` → array runtime → `fork`+`execvp`+`wait`) — NO hechos. Zettel Obsidian `Linux - exec and Zombie Reaping.md` NO generado aún (lo genera la IA; pendiente para D4). Mié 2 → `[x]`. Próxima: Jue 3 `execvp` + PATH (`7-execvp-path.c`).

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
