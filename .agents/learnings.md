# Dynamic Learnings & Cognitive Profile — Learning Path (C & Systems)

Este archivo es la fuente de verdad para la memoria persistente cross-cliente (Pi, OpenCode, Antigravity) dentro de este repositorio.
Registra el perfil cognitivo del desarrollador, sus puntos ciegos detectados durante las katas y los gotchas técnicos cazados.

---

## Invariantes y Convenciones del Repositorio
- **Standard de Anotaciones:** Todo archivo de estudio documenta su aprendizaje usando el bloque `/* @title ... */` con `@phase`, `@learn`, `@open_questions` y `@connect_with`.
- **Cadencia Semanal:** Lunes a Viernes (Katas atómicas dirigidas por la IA) vs Sábado (Milestone de Proyecto en `projects/` donde el alumno es 100% autor y arquitecto) vs Domingo (Tick semanal y Zettels).
- **Autoría Exclusiva en Proyectos:** En `projects/*/docs/` y `projects/*/src/`, el alumno diseña, escribe pseudocódigo y programa. La IA actúa como Peer Reviewer crítico (desafiando edge cases); estrictamente prohibido prefabricar o redactar docs de proyectos.
- **Single-Focus Invariant:** Máximo 1 pregunta reflexiva o quiz por turno. Cero sobrecarga cognitiva.
- **Code is the Answer:** Si el alumno responde con código o comandos, se anulan preguntas previas sin acumular deuda.
- **Compilación Estricta:** `gcc -Wall -Wextra -Werror -pedantic -g -fsanitize=address,undefined` (o `just run <archivo.c>`).

---

## Perfil Cognitivo y Registro de Puntos Ciegos (IA append-only)

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
