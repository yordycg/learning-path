# Dynamic Learnings & Cognitive Profile — Learning Path (C & Systems)

Este archivo es la fuente de verdad para la memoria persistente cross-cliente (Pi, OpenCode, Antigravity) dentro de este repositorio.
Registra el perfil cognitivo del desarrollador, sus puntos ciegos detectados durante las katas y los gotchas técnicos cazados.

---

## Invariantes y Convenciones del Repositorio
- **Contrato de Enseñanza (fuente única):** el flujo diario, la escalera por nivel, las pistas, el `@attempt`, el cierre y la recuperación dominical viven en `.agents/teaching-contract.md`; el nivel por concepto vive en `.agents/knowledge-map.md`. El "código primero" ya NO es el default: aplica solo desde nivel 2.
- **Standard de Anotaciones:** Todo archivo de estudio documenta su aprendizaje usando el bloque `/* @title ... */` con `@phase`, `@learn`, `@open_questions`, `@connect_with` y `@attempt` (desde nivel 1).
- **Cadencia Semanal:** Lunes a Viernes (katas según nivel) vs Sábado (Milestone de Proyecto en `projects/` donde el alumno es 100% autor y arquitecto) vs Domingo (Tick semanal + recuperación en frío + Zettels).
- **Autoría Exclusiva en Proyectos:** En `projects/*/docs/` y `projects/*/src/`, el alumno diseña, escribe pseudocódigo y programa. La IA actúa como Peer Reviewer crítico (desafiando edge cases); estrictamente prohibido prefabricar o redactar docs de proyectos.
- **Single-Focus Invariant:** Máximo 1 pregunta reflexiva o quiz por turno. Cero sobrecarga cognitiva.
- **Code is the Answer:** Si el alumno responde con código o comandos, se anulan preguntas previas sin acumular deuda.
- **Compilación Estricta:** `gcc -Wall -Wextra -Werror -pedantic -g -fsanitize=address,undefined` (o `just run <archivo.c>`).

---

## Perfil Cognitivo y Registro de Puntos Ciegos (IA append-only)

- **[2026-09-12 - S4 D6 / Milestone mysh v1.5]: Documentar cambios como *delta anclado*, no reescribir.**
  - *Patrón aprendido:* un design doc de una versión que evoluciona no repite el pseudocódigo entero; escribe el **delta sobre la versión anterior**: lista anclada (`D1. <ancla>, <landmark relativo>: <cambio>`) + un diff `+/-` con hunks `@@ <ancla> @@`. El ancla es un nombre/rama estable (`main`, `pid == 0`, `execvp`), **nunca** un número de línea.
  - *Anti-patrones a vigilar en los docs:* ramas comentadas tipo `// IF builtin-cd...` (placeholders disfrazados), `@open_questions` suelto en vez de sección `Open Questions`, y mezcla de idioma dentro de un mismo documento.

- **[2026-09-12 - S4 D6 / Milestone mysh v1.5]: No asumir features de shell que no se implementaron.**
  - *Gotcha cazado:* la checklist de v1.5 verificaba `echo $?` *dentro* de mysh, pero el tokenizer no expande `$?` → imprime `$?` literal. `last_status` se observa por el **exit code de mysh** (`exit` + `echo $?` en el shell anfitrión), no por expansión interna.
  - *Regla de alcance:* features fuera del milestone (p. ej. `$?`) no se cuelan en la versión; se aplazan y se registran como `Open Questions`. El tag de la versión debe significar una sola cosa.

- **[2026-09-12 - S4 D6 / Milestone mysh v1.5]: Anti-patrón de autoría del diseño de proyectos por la IA.**
  - *Gotcha cazado:* La IA redactó el documento completo `projects/mysh/docs/pseudocode-v1.5.md` (problema, solución, diagrama, decisiones y checklist), robándole al desarrollador la fase cognitiva de mayor valor (identificar el problema → evaluar trade-offs → elegir arquitectura → formular pseudocódigo).
  - *Regla fija e inquebrantable:* En días de Milestone (Sábado), la IA tiene PROHIBIDO diseñar la solución o redactar archivos en `projects/<p>/docs/*.md`. La IA actúa como Peer Reviewer Socrático que desafía con preguntas críticas después de que el alumno redacta su propuesta.

- **[2026-09-11 - S4 D5]: Declaración de buffers vs arreglos de punteros.**
  - *Gotcha cazado:* Confusión entre `char *buf[1024]` (arreglo de 1024 punteros = 8192 bytes) y `char buf[1024]` (buffer de 1024 bytes). En C compilaba sin warning por la conversión implícita a `void *` en `read()`.
  - *Acción:* La IA debe vigilar la declaración de buffers en syscalls de I/O.

- **[2026-09-11 - S4 D5]: Manejo y restauración de `errno` en Handlers de Señales.**
  - *Gotcha cazado:* Asignar `errno = EINTR` dentro del handler en lugar de preservar el `errno` preexistente al entrar y restaurarlo al salir.
  - *Regla fija:* Guardar `int saved_errno = errno;` al inicio del handler y `errno = saved_errno;` antes del retorno.

- **[2026-09-11 - S4 D5]: Async-Signal-Safety en TTY.**
  - *Regla fija:* Dentro de un signal handler NUNCA usar `printf()`. Emplear siempre `write(STDERR_FILENO, msg, sizeof(msg) - 1)` con strings literales.
  - *Lección verificada:* `strlen()` sí es async-signal-safe (POSIX.1-2008 TC2).

- **[2026-09-10 - S4 D4]: `SIGCHLD` y Reaping Asíncrono.**
  - *Principio anclado:* `SIGCHLD` lo genera el kernel al morir un hijo. Para recolectar múltiples hijos terminados simultáneamente sin bloquear el padre, el handler debe drenar en bucle: `while (waitpid(-1, &wstatus, WNOHANG) > 0);`.
  - *Gotcha de tipos:* Variables compartidas entre el flujo principal y el handler DEBEN ser `volatile sig_atomic_t`.

- **[2026-09-09 - S4 D3]: Asimetría de Señales en `fork` vs `execvp`.**
  - *Gotcha crítico para `mysh v1.5`:* Un proceso hijo hereda los handlers instalados tras `fork()`. Sin embargo, al ejecutar `execvp()`, los handlers capturados se resetean automáticamente a `SIG_DFL`, pero **`SIG_IGN` sobrevive intacto**.
  - *Consecuencia para shells:* Si el shell ignora `SIGINT`, el hijo antes de `execvp()` DEBE resetear `SIGINT` explícitamente a `SIG_DFL` (`signal(SIGINT, SIG_DFL)`).

---

## Registro de Decisiones de Arquitectura y Gotchas Resueltos
- `mysh v1.0`: Eliminado el uso de `system()`. Procesos externos implementados con `fork()` + `execvp()` + `waitpid()`. Propagación de códigos con macros `WIFEXITED`, `WEXITSTATUS`, `WIFSIGNALED` (`128 + WTERMSIG`).
- Flujo de salida: En shells interactivos usar siempre `fflush(stdout)` tras imprimir el prompt para asegurar que los buffers de stdio se vacíen en modo interactivo.

- **[2026-09-14 - S5 D1 / Pipes Intro]: stdio (`FILE *`) vs syscalls sobre fd crudo.**
  - *Gotcha cazado:* Confusión sobre "cuántas formas hay de leer/escribir". El pipe entrega `int fd`, no `FILE *`; se usa `read()`/`write()` (retornan `ssize_t`, pueden ser parciales, van directo al kernel), no `fread`/`fwrite`/`printf` (buffered, sobre `FILE *`, requieren `flush`).
  - *Anti-patrón:* iterar el buffer buscando `'\n'` o `EOF` para encontrar el fin de línea. El *boundary* es el **count que devuelve `read`**; `EOF` es el centinela de retorno (no un byte). El loop correcto para flujo desconocido es `while ((n = read(...)) > 0)`.

- **[2026-09-14 - S5 D1 / Pipes Intro]: `close(write-end)` = "no escribo MÁS", no "ya escribí".**
  - *Modelo anclado:* el EOF (`read` → `0`) solo se produce cuando se cierran **todas las referencias a ambos extremos** (contador de referencias del kernel). Un lector de un solo `read` nunca lo percibe; solo un lector en bucle hasta EOF. Verificado con `timeout 2`: sin `close` → exit `124` (bloqueo), con `close` → exit `0`.
  - *Consecuencia para `mysh v2.0`:* en `cmd1 | cmd2`, si `cmd1` deja un write-end abierto, `cmd2` espera para siempre. El cierre de extremos es requisito, no higiene.

- **[2026-09-14 - entorno]: El vault `obsidian-notes` auto-sincroniza vía ZenNotes.**
  - *Gotcha de entorno:* el plugin `ZenNotes` corre `git add/commit/push` automático (`vault: auto-sync (ZenNotes)`); un commit manual del Zettel puede encontrar el working tree ya limpio. No forzar el commit manual del vault: verificar `git log`/`git status` después de escribir la nota.

- **[2026-09-15 - S5 D2 / dup2]: `exec` es de un solo sentido; no confundir con `fork`.**
  - *Principio anclado:* `execvp` en éxito **nunca retorna**: reemplaza la imagen en el mismo PID. `fork` retorna dos veces (PID/0) y el padre se entera por el valor de retorno; `exec` no retorna y **no notifica** al padre (el único canal hijo→padre es terminación + `wait()`/`SIGCHLD`).
  - *Regla de diseño:* en un mismo proceso, "consumir con un comando `exec`" (p. ej. `execvp("cat")`) y "`waitpid` + `status`" son **mutuamente excluyentes**. Si el padre se transforma en `cat`, el exit status del productor se pierde (queda para `init` o para un `waitpid` de otra etapa).

- **[2026-09-15 - S5 D2 / dup2]: La redirección es transparente para comandos `exec`.**
  - *Modelo anclado:* `dup2(a, b)` no copia datos, re-apunta `b` al mismo objeto del kernel que `a`. Tras `dup2(fd[1], STDOUT_FILENO)`, `ls` escribe a su `stdout` y ya cae al pipe → **no** se necesita `write()` en el productor; con `execvp("cat")` el padre lee el pipe por su `stdin` → **no** se necesita `read()`.
  - *Contraste:* `write()`/`read()` manuales solo aplican cuando el proceso sigue siendo *mi programa* y yo decido consumir/producir el flujo.
  - *Consecuencia para `mysh v2.0`:* el `dup2` es la pieza que enchufa cada etapa del pipeline a `stdin`/`stdout`, sin que los comandos sepan que hay un pipe.

- **[2026-09-16 - S5 D3 / Pipe EOF]: El EOF del pipe es el contador `writers` del kernel, no los datos.**
  - *Modelo anclado:* `read` → `0` requiere que **todas** las referencias al write-end se cierren; `fork()` **duplica el descriptor, no el objeto**, así que el write-end heredado de un hijo mantiene el pipe vivo aunque el padre cierre el suyo. Regla: cada proceso cierra el extremo que no usa.
  - *Diagnóstico:* `exit=124` bajo `timeout` **no es un crash**: es un proceso bloqueado en `read`. Y una corrida con `exit=0` **antes** de recompilar puede venir de un **binario viejo en `build/`** → verificar el binario con `stat`/`ls -l` antes de dar por buena la evidencia.

- **[2026-09-16 - S5 D3]: VLA accidental y `_exit()` en el hijo.**
  - *Gotcha:* `int size_buf = 1024; char buf[size_buf];` es un **VLA** (tamaño runtime en stack, opcional en C11). Preferir `#define BUF_SIZE 1024` / `enum`.
  - *Regla ya conocida reaplicada:* el hijo post-`fork` sale con `_exit()` (no `exit()`/`return`) para no flushear buffers de stdio copiados.

- **[2026-09-19 - S5 cierre / Milestone mysh v2.0]: Si el tamaño lo fija la entrada del usuario, el arreglo va al heap.**
  - *Gotcha reincidente:* `char **cmds[128]` en pila + 129 etapas → **stack-buffer-overflow** (ASan: `index 128 out of bounds`). Es la **misma clase** que el `char *buf[1024]` de S4: un arreglo en pila cuyo tamaño depende de la entrada. Corregir con heap + crecimiento geométrico (`malloc(16)` + `realloc(*2)`) y el chequeo de límite **antes** de escribir.
  - *Regla de verificación:* para bugs de memoria, forzar el borde con la entrada real (generar 130/500/1000 pipes) y compilar con `-fsanitize=address,undefined`; el compilador no avisa de este error.

- **[2026-09-19 - S5 cierre]: `stdio` block-buffered + built-in + `_exit` = datos perdidos.**
  - *Gotcha:* un built-in (`echo`) que escribe con `printf` dentro de un pipe y sale con `_exit(0)` **pierde su salida**: al redirigir `STDOUT` a un pipe, libc pasa `stdout` a block-buffering y `_exit` no vacía el buffer. `echo hola | wc -w` daba `0`.
  - *Regla:* `fflush(stdout)` antes de `_exit` en cualquier built-in que escriba en un pipe. El modo de buffering se fija en la primera operación sobre el stream y se **hereda por `fork`** (por eso el bug solo aparecía con stdout redirigido).
  - *Decisión de rumbo:* `mysh` se **pausa en `v2.0`** como portfolio; el vehículo de la fase pasa a ser el **problema** (DSA). El criterio de éxito de DSA no es "implementar X" sino **selección**: reconocer qué estructura/algoritmo y justificar por qué.

- **[2026-09-19 - entorno / vault]: Diferir el commit manual del vault.**
  - Reconfirmado: `ZenNotes` auto-sincroniza el vault; al generar Zettels, verificar `git log`/`git status` del vault después de escribir y no forzar commits manuales.

- **[2026-09-21 - S6 D1 / estructura del repo]: DSA extraído a su propio track `learning-dsa/`.**
  - *Decisión del alumno:* un único directorio de primer nivel para DSA (antes `learning-c/3-expert/02-dsa/`), con subcarpetas por lenguaje (`c/` activo; `go/` y `graphs/` futuros, antes `learning-go/07-dsa-go/` y `learning-distributed/07-dsa-graphs/`).
  - *Distinción anclada:* los **conceptos** (Big O, criterios de selección) son agnósticos del lenguaje y viven en Obsidian `MOC - DSA`; el repo solo guarda el **código vehículo**.
  - *Consecuencia operativa:* el panel activo es `learning-dsa/status.md` (S6–S10); `learning-c/status.md` queda en pausa hasta W12–15. `just status` apunta a `learning-dsa/status.md`.

- **[2026-09-21 - S6 D1 / Big O]: Punto ciego — Big O / complejidad algorítmica NO vistos.**
  - *Hecho:* el alumno no sabía qué es `N`, `ops` ni `O(n)`; el kata del día 1 se asignó asumiendo piso inexistente y el alumno recurrió a Gemini (muleta) por falta de andamiaje.
  - *Regla fija:* antes de asignar un concepto, consultar `.agents/knowledge-map.md`. Nivel 0 ⇒ quiz de prerrequisitos + explicación con todos los términos + ejemplo resuelto paralelo. Nunca asumir conocimiento no verificado.

- **[2026-09-22 - S6 D2 / Dynamic array]: Confusión de nombres en la derivación de la fórmula de crecimiento.**
  - *Hecho:* al derivar `capacity(k)`, el alumno propuso `capacity(k) = 4 · capacity^k` — usó la variable `capacity` (el resultado) como base del crecimiento, en vez del factor constante `2`.
  - *Regla fija:* en derivaciones algebraicas, distinguir explícitamente la **variable resultado** del **factor de crecimiento constante** (doblado ×2 ⇒ base 2, no "capacity").
  - *Positivo:* con una sola pregunta socrática ("¿por qué número multiplicas en cada salto?") resolvió la confusión y completó la derivación `k = ⌈log₂(N/c₀)⌉` sin ayuda adicional.

---

## Pendiente de Mantenimiento (Backlog técnico — tratar fuera de sesiones de estudio)

- **[Desacoplamiento / Go]: Generalizar 'Build & Debug Commands' en `AGENTS.md` y `Justfile`:**
  - *Contexto:* `AGENTS.md` raíz hoy hardcodea `just run <archivo.c>` y el fallback `gcc -Wall...` bajo "Build & Debug Commands".
  - *Tarea:*
    1. Delegar esa sección en `AGENTS.md` a la sección "Verificación" del perfil activo (`.agents/profiles/<perfil>.md`), o presentarla como tabla multi-lenguaje.
    2. En `Justfile`, extender el recipe `check FILE` (que hoy solo corre `gcc -fsyntax-only`) para soportar `.go` (`go vet` / `go build -n`), `.py` (`py_compile`), etc., alineándolo con el runner multi-lenguaje de `just run`.
  - *Momento:* Resolver antes de iniciar la fase de Go (o al cerrar DSA).
