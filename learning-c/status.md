# Status — Phase 1 (learning-c)

> Maintained by the AI at the end of every session. Start each session by reading this file + `git log -1`. Day-by-day conceptual detail lives in Obsidian; this file is operational state only.

## Current Week — S0 (Aug 5–9, 2026)

- **Topic:** Prep (mid-week start) — close Beej 9–11, base Makefile, valgrind.
- **Done:**
  - [x] functions.c
  - [x] Re-baseline F1 + canonical structure + AGENTS.md (commits a244180..d65db2b)
  - [x] Beej 9 — file I/O → `00-c-basics/file-io/` (read/write text + formatted + binary)
- **Next:**
  - [ ] Thu: Beej 10 typedef + Beej 11 pointer arithmetic → `01-memory-pointers/pointer-arithmetic.c` (N.B. Beej 10 typedef is a *types* topic, not basic: decide placement, do NOT drop into `00-c-basics/basic/`)
  - [ ] Fri: base Makefile (by me) + valgrind + commit
  - [ ] Fri: base Makefile (by me) + valgrind + commit
  - [ ] Sat: catch-up buffer / advance Beej 12 if ahead
  - [ ] Sun: zettels + tick S0 checkbox + plan S1
- **Blockers:** none

## Next Week — S1 (Aug 10–16)

- Stack/Heap + `malloc`/`free` (Beej 12) + `binary_search`.

---

## Session log

- 2026-08-06 — Beej 9 closed: `file-io/` read/write text + formatted + binary, all compiled `-Wall -Wextra -g`, valgrind 0 errors. Committed `feat(c): learn file input/output (Beej 9)`. Next: Beej 10 typedef + Beej 11 pointer arithmetic.
- 2026-08-05 — Planning: re-baseline F1, Recovery Plan S0–S10, canonical structure, AGENTS.md, daily-status mechanism. functions.c reviewed + committed (`feat(c): learn functions`). Next: Beej 9.
