# Status — DSA Track (learning-dsa)

> **Estado operativo SOLO.** Conceptos → Obsidian · Historia → [`session-log.md`](session-log.md). Start each session: read this file + `git log -1`.

## Cómo operar este archivo

- "¿Qué toca hoy?" → se responde con la fila de hoy de _Current Week_ + el **Contrato diario** de abajo.
- Al cierre de sesión: `[ ]` → `[x]` en la fila del día + entrada al `session-log.md`.
- Al cerrar la semana (Dom): archivar las filas en el `session-log.md`, abrir la siguiente, dejar resumen de 2 líneas.
- **Code-first:** cada día empieza con el intento de código (sin leer). El recurso se abre just-in-time solo cuando el código falla.
- **Meta del track:** no es "implementar X estructura", sino **elegir con criterio**. Cada estructura se cierra con su **tabla de decisión** ("¿cuándo SÍ / cuándo NO?").
- GDB y ASan se **pliegan JIT** en las katas (no hay semana dedicada a GDB).
- Ritmo semanal: [`calendario.md`](../calendario.md).

## Contrato diario de respuesta (obligatorio para la IA)

Al pedir "¿qué toca hoy?", el agente DEBE evaluar si corresponde a una **Kata de Concepto (Lunes a Viernes)** o a un **Reto de Selección (Sábado)**:

### 🟢 Modo A: Kata Diaria de Concepto (Lunes a Viernes)
1. **Árbol de contexto + Bridge:** cadena jerárquica + **impacto en el Reto de Selección del Sábado** (1 oración: por qué dominar esto hoy es indispensable para elegir/justificar el sábado).
2. **La Kata del Día:** objetivo preciso en 1 oración + archivo `.c` con ruta exacta + compilación estricta (`just run <archivo.c>`).
3. **Especificación Técnica:** APIs/funciones requeridas + flujo esperado + salida y exit code (`echo $?`) + prueba en 1 línea.
4. **Recurso JIT:** nombre + link, se abre SOLO si el código falla o falta la firma.
5. **Plantilla de comentarios:** cabecera con `@title`, `@phase`, `@learn`, `@open_questions`, `@connect_with`.
6. *(Opcional)* **Stretch Goal:** 1 caso de borde.

### 🟡 Modo B: Reto de Selección (Sábado)
**Invariante de Cero Cucharas:** el alumno es 100% autor. La IA NO pre-diseña la solución.
1. **El Reto:** problema(s) de selección (vehículo = el problema, NO `mysh`).
2. **Fase 1 (Diseño por el Alumno):** elegir DS/algoritmo + justificar (trade-offs) + pseudocódigo + checklist, en `c/exercises/`.
3. **Pausa para Peer Review Socrático:** la IA desafía la elección con preguntas de casos de borde ANTES de implementar.
4. **Fase 2 (Implementación):** el alumno codifica y depura con GDB/ASan.

> **Reglas de Interacción:** Single-Focus (1 pregunta por turno). Código = respuesta (anular preguntas previas sin acumular deuda). Diagramas ASCII en chat; Zettel de Obsidian con Mermaid (IA al cierre).

## Estado actual — S6 (Sep 21 – 27)

> **Pivote de rumbo (cierre de S5):** `mysh` se **pausa** en `v2.0` y deja de ser el vehículo. S6–S10 = **DSA** como track propio (`learning-dsa/`) con foco en **criterio de selección**.
> **Recovery (concepto previo al abrir S6):** **Big O** (Fiset intro + Silver.dev) y complejidad amortizada — antes de la primera estructura.
> **Orden por dependencias:** cada día usa solo lo de días anteriores. Cada estructura se cierra con su **tabla de decisión**.

| Día    | Tema                                                                                                                     | Archivo (intento code-first) | Recurso JIT                     | Zettel al cierre (IA)                 | Estado |
| ------ | ------------------------------------------------------------------------------------------------------------------------ | ---------------------------- | ------------------------------- | ------------------------------------- | ------ |
| Lun 21 | **Big O**: qué mide, peor caso, O/Θ/Ω, reglas; complejidad amortizada                                                    | `c/1-big-o.c`                | Fiset (intro) · Silver.dev · AlgoMaster OS | `DSA - Big O...` (revisar duplicados) | [ ]    |
| Mar 22 | **Dynamic array**: array vs dinámico, `realloc`, crecimiento amortizado                                                  | `c/2-dynamic-array.c`        | Fiset                           | `DSA - Dynamic Array...`              | [ ]    |
| Mié 23 | **Criterio array**: acceso O(1) vs inserción/borrado O(n); cache locality                                                | `c/3-array-tradeoffs.c`      | Fiset                           | `DSA - Array Tradeoffs...`            | [ ]    |
| Jue 24 | **Linked list I**: nodo, `head`, recorrido, insertar/borrar O(1) con puntero                                             | `c/4-linked-list.c`          | Fiset · Beej 20.3 · CTCI        | `DSA - Linked List...`                | [ ]    |
| Vie 25 | **Criterio lista vs array**: acceso aleatorio vs inserción; patrón head-return                                           | `c/5-list-vs-array.c`        | Fiset · CTCI                    | `DSA - List vs Array...`              | [ ]    |
| Sáb 26 | **Retos de selección** (vehículo = el problema): elegir DS/algoritmo + justificar; implementar el ganador + depurar con GDB/ASan | `c/exercises/`               | conceptos Lun–Vie               | revisar                               | [ ]    |
| Dom 27 | Zettels + tick S6                                                                                                        | —                            | —                               | Revisar Zettels IA                    | [ ]    |

- **Blockers S6:** ninguno.
- **Pendiente tuyo (cierre S5, en `learning-c`):** `git add` + commit (`feat(mysh): ...` y `docs(mysh): ...`, atómicos) y `git tag -a v2.0` en `projects/mysh/`.

## Próxima sesión — TODO (S6 D1 · Lun 21)

- **S6 D1 — Kata: Big O (análisis de complejidad).** Code-first en `c/1-big-o.c` **sin abrir el recurso**. La IA entregará el contrato completo (objetivo + spec + salida/exit code + JIT + anotaciones) cuando se pida "¿qué toca hoy?".
- **Encuadre:** la meta no es "implementar para `mysh`", sino **elegir con criterio**. Cada estructura se cierra con su tabla "¿cuándo SÍ / cuándo NO?".

## Historial

- *(S6 inicia aquí. Historial C/systems S1–S5 en [`../learning-c/session-log.md`](../learning-c/session-log.md))*
