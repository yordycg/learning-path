# Status — Phase 1 (learning-c)

> Maintained by the AI at the end of every session. Start each session by reading this file + `git log -1`. Day-by-day conceptual detail lives in Obsidian; this file is operational state only.

## Cómo operar este archivo

- Cada día preguntas "¿qué toca hoy?" → se responde con la fila de hoy de *Current Week* + sus recursos.
- Al cierre de sesión: marcar `[ ]` → `[x]` en la fila del día y añadir entrada al *Session log*.
- Al terminar la semana: las filas se archivan en el *Session log* y se abre la siguiente con la plantilla de *Next Week*.
- Los recursos completos por tema viven en [`README.md → Recursos por tema`](README.md#recursos-por-tema) (fuente única); aquí solo se referencian.

## Current Week — S1 (Aug 10–16)

> Stack/Heap + `malloc`/`free` (Beej 12) + `binary_search`. Recursos: [`README → Recursos por tema`](README.md#recursos-por-tema) (`05-memory-management`).

| Día | Tema | Recursos | Estado |
|-----|------|----------|--------|
| Lun 10 | Stack vs Heap, `malloc`/`free` | [README → `05-memory-management`](README.md#recursos-por-tema) | [x] |
| Mar 11 | `calloc`/`realloc` + patrón NULL-check + valgrind (primera toma de contacto con valgrind, ya hay heap) | ídem | [x] |
| Mié 12 | Beej 12.4–12.5 + `binary_search` | ídem | [x] |
| Jue 13 | Buffer / refuerzo | — | [ ] |
| Vie 14 | Buffer / avance | — | [ ] |
| Sáb 15 | Buffer / avance — **ej. 2 dynamic note recording cerrado** | — | [x] |
| Dom 16 | Zettels + tick S1 + plan S2 | — | [ ] |

- **Blockers:** none

## Next Week — S2 (Aug 17–23)

> Syscalls + FDs (K&R 8, `man 2`). Plan día a día **provisional**: se abre el Dom 16 al tick de S1. Referencia: [`README → Recovery Plan`](README.md#recovery-plan-f1-s0s10) (S2).

---

## Próxima sesión — TODO

- Investigar + crear Zettels sobre **Stack vs Heap memory model**. Beej 12 no cubre stack (README nota: "stack no en Beej"). Recursos: Sorber — [Pulling Back the Curtain on the Heap](https://www.youtube.com/watch?v=GIWeQ2I67rk) + [Your Variables are Not Real](https://www.youtube.com/watch?v=YO6K5K1TUj4). Zettel planificado: `C - Stack vs Heap Memory Model.md`.

## Session log

- 2026-08-15 — `2-dynamic-note-recording.c` (ej. 2) completed: growing-realloc pattern (capacity 1→2→4→8), invariant `count <= capacity`, temp-pointer shield on realloc failure, note range 0–7 (Chilean grading), EOF (Ctrl+D) = end of input via break, `buffer[32]` + `sscanf` per-line validation, senior-style comments + synced pseudocode. Compiled `-Wall -Wextra -g`, tested: averages, boundaries 0/7, rejection >7, `-1` only, Ctrl+D with/without notes. Committed `feat(c):`.
- 2026-08-12 — Beej 12 closed: `4-change-allocated-size.c` (realloc + NULL-protection; fixed loop range `0..39`) and `5-complete-example.c` (growing readline: comma-operator loop, doubling `realloc` + temp-pointer shield, shrink-to-fit; fixed missing `return NULL;` on realloc failure). Both compiled `-Wall -Wextra -g`, no warnings, exit 0 incl. missing-file case. NOTA: valgrind no ejecutable en este entorno (falta libc6-dbg / glibc debuginfo); verificado por ejecución directa.
- 2026-08-10 — Beej 12 dynamic memory allocation: created 1-allocating-deallocating.c, 2-error-checking.c, and 3-array-example.c (malloc, free, NULL protection, calloc, memset).
- 2026-08-07 — Rediseñado `status.md` a plan día a día: tabla de la semana con tema + recursos (referencia a `README.md#recursos-por-tema`, fuente única) + checkbox por día; regla de operación; plantilla S1 provisional. Comprometido `chore(docs):`.
- 2026-08-06 — Beej 10–11 closed: `2-advanced/04-typedef-types/typedef.c` (3 struct syntaxes + alias); `2-advanced/01-pointers/` split into `arithmetic-pointers.c` (incl. `my_strlen` subtraction), `void-pointers.c` (`my_memcpy`), `array-pointers.c` (array/pointer equivalence, fixed `*(a+i)` bug), `function-pointers.c`. All compiled `-Wall -Wextra -g`, no warnings. Committed `feat(c): learn typedef and pointer arithmetic (Beej 10-11)`. Next: Fri base Makefile + valgrind.
- 2026-08-06 — Added per-topic resources (Beej § + YouTube) to `README.md` (Recursos por tema) and roadmap video tables (threads, bitwise); marked `06-functions` done.
- 2026-08-06 — Beej 9 closed: `2-advanced/07-file-io/` read/write text + formatted + binary, all compiled `-Wall -Wextra -g`, valgrind 0 errors. Committed `feat(c): learn file input/output (Beej 9)`. Reorganized `learning-c/` into `1-basics/ 2-advanced/ 3-expert/ 4-systems/` (Obsidian mirror). Next: Beej 10 typedef + Beej 11 pointer arithmetic.
- 2026-08-05 — Planning: re-baseline F1, Recovery Plan S0–S10, canonical structure, AGENTS.md, daily-status mechanism. functions.c reviewed + committed (`feat(c): learn functions`). Next: Beej 9.
