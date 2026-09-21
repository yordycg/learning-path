# Status — DSA Track (learning-dsa)

> **Estado operativo SOLO.** Conceptos → Obsidian · Historia → [`session-log.md`](session-log.md). Start each session: read this file + `git log -1` + [`.agents/knowledge-map.md`](../.agents/knowledge-map.md) + [`.agents/teaching-contract.md`](../.agents/teaching-contract.md).

## Cómo operar este archivo

- "¿Qué toca hoy?" → se responde con la fila de hoy de _Current Week_ + el **Contrato de enseñanza** ([`../.agents/teaching-contract.md`](../.agents/teaching-contract.md)).
- Al cierre de sesión: `[ ]` → `[x]` en la fila del día + entrada al `session-log.md`.
- Al cerrar la semana (Dom): archivar las filas en el `session-log.md`, abrir la siguiente, dejar resumen de 2 líneas.
- **Por nivel:** el flujo del día lo dicta `.agents/knowledge-map.md` + `.agents/teaching-contract.md`. Nivel 0–1: explicación + ejemplo + recurso de apoyo (DESPUÉS del ejemplo). Nivel 2: code-first (recurso JIT solo si falla).
- **Meta del track:** no es "implementar X estructura", sino **elegir con criterio**. Cada estructura se cierra con su **tabla de decisión** ("¿cuándo SÍ / cuándo NO?").
- GDB y ASan se **pliegan JIT** en las katas (no hay semana dedicada a GDB).
- Ritmo semanal: [`calendario.md`](../calendario.md).

## Contrato de enseñanza (fuente única)

> El contrato completo (Paso 0 → escalera → pistas → cierre → domingo) vive en
> [`../.agents/teaching-contract.md`](../.agents/teaching-contract.md). Léelo y síguelo al pie; aquí NO se duplica.
> El skill `status-tracker` referencia el mismo archivo.

## Estado actual — S6 (Sep 21 – 27)

> **Pivote de rumbo (cierre de S5):** `mysh` se **pausa** en `v2.0` y deja de ser el vehículo. S6–S10 = **DSA** como track propio (`learning-dsa/`) con foco en **criterio de selección**.
> **Recovery (concepto previo al abrir S6):** **Big O** (nivel 0: explicación + ejemplo + quiz, sin recurso externo obligatorio) — antes de la primera estructura.
> **Orden por dependencias:** cada día usa solo lo de días anteriores. Cada estructura se cierra con su **tabla de decisión**.

| Día    | Tema                                                                                                                     | Archivo (según nivel) | Recurso (según nivel)                     | Zettel al cierre (IA)                 | Estado |
| ------ | ------------------------------------------------------------------------------------------------------------------------ | ---------------------------- | ------------------------------- | ------------------------------------- | ------ |
| Lun 21 | **Big O**: qué mide, peor caso y crecimiento (conteo de ops vs N). Ω/Θ y amortizado quedan FUERA de hoy (nivel 2+)        | `c/1-big-o.c`                | freeCodeCamp (opcional, DESPUÉS del ejemplo) | `DSA - Big O...` (revisar duplicados) | [ ]    |
| Mar 22 | **Dynamic array**: array vs dinámico, `realloc`, crecimiento amortizado                                                  | `c/2-dynamic-array.c`        | Beej 8–19 (memoria)             | `DSA - Dynamic Array...`              | [ ]    |
| Mié 23 | **Criterio array**: acceso O(1) vs inserción/borrado O(n); cache locality                                                | `c/3-array-tradeoffs.c`      | Beej 8–19 (arrays)              | `DSA - Array Tradeoffs...`            | [ ]    |
| Jue 24 | **Linked list I**: nodo, `head`, recorrido, insertar/borrar O(1) con puntero                                             | `c/4-linked-list.c`          | Beej 20.3 · CTCI                | `DSA - Linked List...`                | [ ]    |
| Vie 25 | **Criterio lista vs array**: acceso aleatorio vs inserción; patrón head-return                                           | `c/5-list-vs-array.c`        | CTCI                            | `DSA - List vs Array...`              | [ ]    |
| Sáb 26 | **Retos de selección** (vehículo = el problema): elegir DS/algoritmo + justificar; implementar el ganador + depurar con GDB/ASan | `c/exercises/`               | conceptos Lun–Vie               | revisar                               | [ ]    |
| Dom 27 | Zettels + tick S6                                                                                                        | —                            | —                               | Revisar Zettels IA                    | [ ]    |

- **Blockers S6:** ninguno.
- **Pendiente tuyo (cierre S5, en `learning-c`):** `git add` + commit (`feat(mysh): ...` y `docs(mysh): ...`, atómicos) y `git tag -a v2.0` en `projects/mysh/`.

## Próxima sesión — TODO (S6 D1 · Lun 21)

- **S6 D1 — Kata: Big O.** Nivel 0 (no visto) → la IA arranca por el **quiz de prerrequisitos**, luego explicación + ejemplo resuelto, luego quiz de comprensión + producción (el esqueleto `c/1-big-o.c` es para nivel 1).
- **Encuadre:** la meta no es "implementar para `mysh`", sino **elegir con criterio**. Cada estructura se cierra con su tabla "¿cuándo SÍ / cuándo NO?".

## Historial

- *(S6 inicia aquí. Historial C/systems S1–S5 en [`../learning-c/session-log.md`](../learning-c/session-log.md))*
