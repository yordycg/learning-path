# Status — Phase 1 (learning-c)

> Maintained by the AI at the end of every session. Start each session by reading this file + `git log -1`. Day-by-day conceptual detail lives in Obsidian; this file is operational state only.

## Cómo operar este archivo

- Cada día preguntas "¿qué toca hoy?" → se responde con la fila de hoy de *Current Week* + sus recursos.
- Al cierre de sesión: marcar `[ ]` → `[x]` en la fila del día y añadir entrada al *Session log*.
- Al terminar la semana: las filas se archivan en el *Session log* y se abre la siguiente con la plantilla de *Next Week*.
- Los recursos completos por tema viven en [`README.md → Recursos por tema`](README.md#recursos-por-tema) (fuente única); aquí solo se referencian.

## Current Week — S0 (Aug 5–9, 2026)

> Prep (mid-week start) — close Beej 9–11, base Makefile, valgrind.

| Día | Tema | Recursos | Estado |
|-----|------|----------|--------|
| Mié 5 | Re-baseline F1 + estructura canónica + AGENTS.md; `functions.c` | — | [x] |
| Jue 6 | Beej 9 file I/O + Beej 10 typedef + Beej 11 pointer arithmetic | [README → Recursos por tema](README.md#recursos-por-tema) (`01-pointers`, `04-typedef-types`) | [x] |
| Vie 7 | Base Makefile + valgrind | [README → Recursos por tema](README.md#recursos-por-tema) (`11-tooling`: Makefiles, auto vars, Valgrind, GDB+Valgrind) | [ ] |
| Sáb 8 | Catch-up buffer / Beej 12 si vas adelantado | Beej §12 (ver S1) | [ ] |
| Dom 9 | Zettels + tick S0 + plan S1 | — | [ ] |

- **Blockers:** none

## Next Week — S1 (Aug 10–16)

> Stack/Heap + `malloc`/`free` (Beej 12) + `binary_search`. Plan día a día **provisional**: se ajusta el Dom 9 al planear S1. Recursos: [`README → Recursos por tema`](README.md#recursos-por-tema) (`05-memory-management`).

| Día | Tema | Recursos | Estado |
|-----|------|----------|--------|
| Lun 10 | Stack vs Heap, `malloc`/`free` | [README → `05-memory-management`](README.md#recursos-por-tema) | [ ] |
| Mar 11 | `calloc`/`realloc` + patrón NULL-check + valgrind | ídem | [ ] |
| Mié 12 | Beej 12.4–12.5 + `binary_search` | ídem | [ ] |
| Jue 13 | Buffer / refuerzo | — | [ ] |
| Vie 14 | Buffer / avance | — | [ ] |
| Sáb 15 | Buffer / avance | — | [ ] |
| Dom 16 | Zettels + tick S1 + plan S2 | — | [ ] |

---

## Session log

- 2026-08-07 — Rediseñado `status.md` a plan día a día: tabla de la semana con tema + recursos (referencia a `README.md#recursos-por-tema`, fuente única) + checkbox por día; regla de operación; plantilla S1 provisional. Comprometido `chore(docs):`.
- 2026-08-06 — Beej 10–11 closed: `2-advanced/04-typedef-types/typedef.c` (3 struct syntaxes + alias); `2-advanced/01-pointers/` split into `arithmetic-pointers.c` (incl. `my_strlen` subtraction), `void-pointers.c` (`my_memcpy`), `array-pointers.c` (array/pointer equivalence, fixed `*(a+i)` bug), `function-pointers.c`. All compiled `-Wall -Wextra -g`, no warnings. Committed `feat(c): learn typedef and pointer arithmetic (Beej 10-11)`. Next: Fri base Makefile + valgrind.
- 2026-08-06 — Added per-topic resources (Beej § + YouTube) to `README.md` (Recursos por tema) and roadmap video tables (threads, bitwise); marked `06-functions` done.
- 2026-08-06 — Beej 9 closed: `2-advanced/07-file-io/` read/write text + formatted + binary, all compiled `-Wall -Wextra -g`, valgrind 0 errors. Committed `feat(c): learn file input/output (Beej 9)`. Reorganized `learning-c/` into `1-basics/ 2-advanced/ 3-expert/ 4-systems/` (Obsidian mirror). Next: Beej 10 typedef + Beej 11 pointer arithmetic.
- 2026-08-05 — Planning: re-baseline F1, Recovery Plan S0–S10, canonical structure, AGENTS.md, daily-status mechanism. functions.c reviewed + committed (`feat(c): learn functions`). Next: Beej 9.
