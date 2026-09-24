# Status — DSA Track (learning-dsa)

> **Estado operativo SOLO.** Conceptos → Obsidian · Historia → [`session-log.md`](session-log.md). Start each session: read this file + `git log -1` + [`.agents/knowledge-map.md`](../.agents/knowledge-map.md) + [`.agents/teaching-contract.md`](../.agents/teaching-contract.md).

## Cómo operar este archivo

- "¿Qué toca hoy?" → se responde con la fila de hoy de _Current Week_ + el **Contrato de enseñanza** ([`../.agents/teaching-contract.md`](../.agents/teaching-contract.md)).
- Al cierre de sesión: `[ ]` → `[x]` en la fila del día + entrada al `session-log.md`.
- Al cerrar la semana (Dom): archivar las filas en el `session-log.md`, abrir la siguiente, dejar resumen de 2 líneas.
- **Por nivel:** el flujo del día lo dicta `.agents/knowledge-map.md` + `.agents/teaching-contract.md`. Nivel 0–1: explicación + ejemplo + recurso principal (★, DESPUÉS del ejemplo). Nivel 2: code-first (recurso JIT solo si falla).
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
> **Recurso:** `★` = principal (ideal, se cita primero); el resto = apoyo opcional.

| Día    | Tema                                                                                                                     | Archivo (según nivel) | Recurso (según nivel)                     | Zettel al cierre (IA)                 | Estado |
| ------ | ------------------------------------------------------------------------------------------------------------------------ | ---------------------------- | ------------------------------- | ------------------------------------- | ------ |
| Lun 21 | **Big O**: qué mide, peor caso y crecimiento (conteo de ops vs N). Ω/Θ y amortizado quedan FUERA de hoy (nivel 2+)        | `c/1-big-o.c`                | ★ freeCodeCamp · Fiset/Silver.dev/AlgoMaster (apoyo) | `DSA - Big O...` (revisar duplicados) | [x]    |
| Mar 22 | **Dynamic array**: array vs dinámico, `realloc`, crecimiento amortizado                                                  | `c/2-dynamic-array.c`        | ★ Fiset · Beej 8–19 (apoyo)    | `DSA - Dynamic Array...`              | [x]    |
| Mié 23 | **Criterio array**: acceso O(1) vs inserción/borrado O(n); cache locality                                                | `c/3-array-tradeoffs.c`      | ★ Fiset · Beej 8–19 (apoyo)    | `DSA - Array Tradeoffs...`            | [x]    |
| Jue 24 | **Linked list I**: nodo, `head`, recorrido, insertar/borrar O(1) con puntero                                             | `c/4-linked-list.c`          | ★ Fiset · Beej 20.3 · CTCI (apoyo) | `DSA - Linked List...`                | [ ]    |
| Vie 25 | **Criterio lista vs array**: acceso aleatorio vs inserción; patrón head-return                                           | `c/5-list-vs-array.c`        | ★ Fiset · CTCI (apoyo)         | `DSA - List vs Array...`              | [ ]    |
| Sáb 26 | **Retos de selección** (vehículo = el problema): elegir DS/algoritmo + justificar; implementar el ganador + depurar con GDB/ASan | `c/exercises/`               | conceptos Lun–Vie               | revisar                               | [ ]    |
| Dom 27 | Zettels + tick S6                                                                                                        | —                            | —                               | Revisar Zettels IA                    | [ ]    |

- **Blockers S6:** ninguno.
- ~~Pendiente tuyo (cierre S5)~~ ✅ **mysh v2.0 cerrado** (commit `b8a66cc` + tag `v2.0`).

## Próxima sesión — TODO (S6 D4 · Jue 24)

- **S6 D4 — Kata: Linked list I.** nodo, `head`, recorrido, insertar/borrar O(1) con puntero. Nivel 0 (no visto) → quiz de prerrequisitos → explicación + ejemplo resuelto → quiz de comprensión + producción. Recurso: ★ Fiset · Beej 20.3 · CTCI (apoyo).
- **Encuadre:** la meta no es "implementar para `mysh`", sino **elegir con criterio**. Cada estructura se cierra con su tabla "¿cuándo SÍ / cuándo NO?".

## Historial

- **S6 D1 (2026-09-21) — Big O:** nivel 0→1. Prerrequisitos ✅, quiz comprensión ✅ (nested loops ⇒ O(n²)), producción ✅ (N=40 → 1600 ops, justificada) y pregunta conceptual ✅ (término dominante). Zettel no creado (concepto ya cubierto en vault).
- **S6 D2 (2026-09-22) — Dynamic array:** nivel 0→1. Prerrequisito ✅ (heap vs VLA), quiz comprensión ✅ (realloc ×2 + reasignar), producción ✅ (3 realloc → 32, justificado) + bonus: derivó la fórmula k = ⌈log_g(N/c₀)⌉. ¿entendiste? "s".
- **S6 D3 (2026-09-24) — Criterio array:** nivel 0→1. Prerrequisito ✅ (arr[i] O(1) por contigüidad), quiz comprensión ✅ (N=1000 → 1000 shifts), producción ✅ (N=9 borrar índice 2 → 6 a la izquierda, off-by-one detectado en `arr[i]=arr[i+1]`) y conceptual ✅ (grilla píxeles → array por O(1) acceso). ¿entendiste? "s". Zettel: `Array Tradeoffs - C`.
- *(S6 inicia aquí. Historial C/systems S1–S5 en [`../learning-c/session-log.md`](../learning-c/session-log.md))*
