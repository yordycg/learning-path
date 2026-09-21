# Contrato de Enseñanza (Single Source of Truth)

> Fuente ÚNICA del "qué toca hoy". Referenciado por `learning-*/status.md` y el skill `status-tracker`.
> Reglas base: `AGENTS.md` raíz + skills `socratic-mentor`, `code-diagnostic`, `obsidian-query`.

## Paso 0 — Nivel del concepto (antes de asignar NADA)
1. Consultar `.agents/knowledge-map.md`.
2. Si el concepto es **nivel 0** ⇒ NO asignar ejercicio todavía. Ejecutar la herramienta `quiz` (una interacción; pregunta única del prerrequisito más crítico, nunca texto plano) de **PRERREQUISITOS** del concepto (no el concepto en sí).
3. Concepto ausente ⇒ `0` y se añade antes de continuar.
4. En nivel 0, la explicación define **N**, **operación** y **ops** ANTES de usarlos, fija una convención de conteo explícita (qué cuenta como 1 op) y **NO** introduce Ω/Θ ni complejidad amortizada (fuera del alcance del día).

## Carril rápido (nivel 0 → 1)
- SOLO si el alumno lo pide ("ya lo sé") Y acierta **en frío un ítem de producción sobre el concepto en sí**.
- NUNCA por pasar el quiz de prerrequisitos (ese quiz mide prerrequisitos, no el concepto).

## Escalera de andamiaje (según nivel)
| Nivel | Qué entrega la IA | Recurso |
|-------|-------------------|---------|
| 0 | Explicación con TODOS los términos + ejemplo resuelto PARALELO (mismo concepto, distinto escenario y distinto cuerpo: no copiable a la kata) + recurso de apoyo + quiz de comprensión + producción | ANTES (apoyo, DESPUÉS del ejemplo) |
| 1 | Ejercicio con esqueleto/pasos borrados: la IA da el andamio (main, contadores, impresión); el alumno escribe la lógica | ANTES |
| 2 | **Kata concreta** (archivo + objetivo + spec), sin explicación previa ni plantilla con marcadores (code-first) | JIT (solo si falla) |
| 3 | Recuperación en frío (sin recurso, sin andamio) | prohibido |

> **Excepción de andamiaje (nivel 1):** el andamio puede contener huecos `/* TODO: … */`. La regla "No Placeholders" NO aplica a andamios pedagógicos.

## Gates de subida (exige evidencia)
| Subida | Evidencia exigida |
| 0→1 | explicación + quiz de comprensión acertado + producción (predecir un número con un N que el alumno NO vio en el ejemplo y justificar; la salida esperada NO se muestra antes) |
| 1→2 | esqueleto completado + 1 pregunta conceptual acertada |
| 2→3 | solo recuperación en frío (domingo) |

## Regla de descenso
- Kata nivel 2 que llegó al peldaño 3 de pistas o superior, o reescribió de memoria ⇒ al cierre baja a `1`.

## Pistas (sin medición de tiempo por la IA)
- La IA NO mide tiempo. El alumno marca el inicio, o la IA pregunta "¿cuánto llevas?". Objetivo: ~20 min de intento real antes de subir peldaño.
- Peldaños, uno por turno, nunca la solución:
  1. Releer enunciado / recordar firma.
  2. Una pregunta guía socrática.
  3. Señalar la línea/error sin dar el fix.
  4. Diagrama ASCII del mecanismo (sin código).
  5. Abrir el recurso, cerrarlo y reescribir de memoria.
- La IA **nunca** entrega el código de la kata. Solo ejemplos resueltos paralelos (nivel 0).

## Cabecera `@attempt` (desde nivel 1)
- Desde nivel 1. Además de `@title/@phase/@learn/@open_questions/@connect_with`:
```c
/* @attempt
 *   probé:    <qué escribí antes de mirar cualquier recurso>
 *   esperaba: <qué pensé que iba a pasar>
 *   pasó:     <qué pasó en realidad>
 */
```
- Ausencia de `@attempt` NO es sanción: se registra en `learnings.md` como dato de calibración.

## Captura de comprensión (nivel 0)
- Al cierre de toda explicación de nivel 0, la IA pregunta en UNA tecla: **"¿Entendiste? s / a medias / n"** y registra la respuesta literal en `session-log.md` (señal de ritmo, no es el quiz de comprensión).

## Carga del alumno (máx 3 acciones manuales/día, además de la kata)
- La **contabilidad** (`knowledge-map.md`, `learnings.md`, `session-log.md`, Zettel) y los campos `@learn`/`@open_questions`/`@connect_with` los completa la **IA** (el alumno NO los escribe).
- Acciones manuales (además de resolver la kata/producción): **nivel 0** = quiz prerrequisito · quiz comprensión · `¿entendiste?`; **nivel 1** = `@attempt` · 1 pregunta conceptual · confirmar subida; **nivel 2** = 1 pregunta conceptual · confirmar subida/bajada; **domingo** = 1 pregunta conceptual (la recuperación en frío es la "kata").

## Cierre de kata (obligatorio)
1. `[x]` en la fila del día + entrada en `session-log.md` + actualizar `knowledge-map.md` (nivel, evidencia con pregunta y **respuesta literal del alumno — incluidos errores y ayudas recibidas**, último repaso) — **pidiendo confirmación al alumno antes de cambiar nivel**. La evidencia es SIEMPRE el mensaje literal del alumno; la IA nunca redacta respuestas hipotéticas suyas.
2. **1 pregunta conceptual** post-resolución.
3. Generar Zettel (`obsidian-query`).

## Domingo — recuperación en frío (15 min)
- 15 min en frío de un tema anterior (empezando por C), sin recurso.
- Elegir del `knowledge-map.md` el de mayor nivel con más tiempo sin repasar.
- Falla ⇒ bajar nivel + actualizar "último repaso". Acierta ⇒ registrar "último repaso".

## Modo A — Kata (Lun–Vie)
Aplicar Paso 0 → escalera → pistas → cierre.
1. Árbol de contexto + Bridge.
2. Kata según **nivel** (0 = explicación+paralelo+quiz · 1 = esqueleto · 2 = libre). Nunca asumir 2 si es 0.
3. Especificación técnica (APIs, flujo, salida, exit code, prueba en 1 línea).
4. Recurso: **nivel 0–1 ANTES** (apoyo explicativo, DESPUÉS del ejemplo resuelto) · **nivel 2 JIT**.
5. Plantilla de comentarios + `@attempt` (desde nivel 1).

## Modo B — Reto / Milestone (Sáb)
Invariante de Cero Cucharas (alumno 100% autor) + Peer Review Socrático + tag.

## Regla de calendario
- Concepto nivel 0 que no cabe en 2h ⇒ se parte en dos días y se corre el calendario (`status.md`).
- El **Reto de Selección del Sábado SOLO se mantiene si los conceptos de la semana están en nivel 2**; si no, el sábado es **consolidación**. El desfase se absorbe en el bloque reservado W12–15 (ver `calendario.md`).

## Regla anti-dilución
- En sesiones de estudio NO se hace mantenimiento del repo (refactors, URLs, PDFs, config, skills).
- **EXCEPCIÓN:** commits/tags del milestone (incluido el pendiente de `mysh v2.0`) SÍ son cierre.
- **Actualizar `knowledge-map.md`, `learnings.md` y `session-log.md` al cierre NO es mantenimiento:** es parte del cierre.
- Mantenimiento real ⇒ anotar en `learnings.md` ("Pendiente de mantenimiento") y tratarlo aparte.
