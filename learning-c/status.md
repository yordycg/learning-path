# Status — Phase 1 (learning-c)

> Maintained by the AI at the end of every session. Start each session by reading this file + `git log -1`. Day-by-day conceptual detail lives in Obsidian; this file is operational state only.

## Current Week — S0 (Aug 5–9, 2026)

- **Topic:** Prep (mid-week start) — close Beej 9–11, base Makefile, valgrind.
- **Done:**
  - [x] functions.c
  - [x] Re-baseline F1 + canonical structure + AGENTS.md (commits a244180..d65db2b)
  - [x] Beej 9 — file I/O → `2-advanced/07-file-io/` (read/write text + formatted + binary)
- **Next:**
  - [x] Thu: Beej 10 typedef + Beej 11 pointer arithmetic → `2-advanced/04-typedef-types/typedef.c` + `2-advanced/01-pointers/arithmetic-pointers.c` + `void-pointers.c` + `array-pointers.c` + `function-pointers.c`
  - [ ] Fri: base Makefile (by me) + valgrind + commit
  - [ ] Sat: catch-up buffer / advance Beej 12 if ahead
  - [ ] Sun: zettels + tick S0 checkbox + plan S1
- **Resources (this week):** typedef → [Beej §10](https://beej.us/guide/bgc/html/split/typedef-making-new-types.html) (no video) · pointer arithmetic → [Beej §11](https://beej.us/guide/bgc/html/split/pointers2.html) + [Check Your Pointers at Runtime](https://www.youtube.com/watch?v=yM9zteeTCiI) (Sorber). Full per-topic list in `README.md → Recursos por tema`.
- **Blockers:** none

## Next Week — S1 (Aug 10–16)

- Stack/Heap + `malloc`/`free` (Beej 12) + `binary_search`.

---

## Session log

- 2026-08-06 — Beej 10–11 closed: `2-advanced/04-typedef-types/typedef.c` (3 struct syntaxes + alias); `2-advanced/01-pointers/` split into `arithmetic-pointers.c` (incl. `my_strlen` subtraction), `void-pointers.c` (`my_memcpy`), `array-pointers.c` (array/pointer equivalence, fixed `*(a+i)` bug), `function-pointers.c`. All compiled `-Wall -Wextra -g`, no warnings. Committed `feat(c): learn typedef and pointer arithmetic (Beej 10-11)`. Next: Fri base Makefile + valgrind.
- 2026-08-06 — Added per-topic resources (Beej § + YouTube) to `README.md` (Recursos por tema) and roadmap video tables (threads, bitwise); marked `06-functions` done.
- 2026-08-06 — Beej 9 closed: `2-advanced/07-file-io/` read/write text + formatted + binary, all compiled `-Wall -Wextra -g`, valgrind 0 errors. Committed `feat(c): learn file input/output (Beej 9)`. Reorganized `learning-c/` into `1-basics/ 2-advanced/ 3-expert/ 4-systems/` (Obsidian mirror). Next: Beej 10 typedef + Beej 11 pointer arithmetic.
- 2026-08-05 — Planning: re-baseline F1, Recovery Plan S0–S10, canonical structure, AGENTS.md, daily-status mechanism. functions.c reviewed + committed (`feat(c): learn functions`). Next: Beej 9.
