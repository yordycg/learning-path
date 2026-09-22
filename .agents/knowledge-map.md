# Knowledge Map — Nivel por Concepto (fuente de verdad del nivel)

> Escala: `0 = no visto` · `1 = visto (con ayuda)` · `2 = listo para kata libre` · `3 = en frío`.
> Campos por entrada:
> - `concepto`: nombre del concepto o técnica.
> - `tema`: perfil al que pertenece (`c`, `dsa`, `go`, etc.).
> - `tipo`: `vocabulario` (definición/terminología) o `mecanismo` (lógica/diseño con "por qué" y DAG).
> - `nivel`: `0` a `3`.
> - `último_repaso`: fecha de la última recuperación en frío (domingo).
> - `evidencia`: pregunta y respuesta literal del alumno (o hito/tag que lo respalda).

## Reglas
- Al abrir un tema, la IA consulta este registro (Paso 0 del contrato).
- Concepto ausente ⇒ `0` y se añade antes de continuar (clasificando su `tipo` con la guía del perfil).
- **En "evidencia" se registra la pregunta y tu respuesta literal (siempre tu mensaje exacto; la IA nunca redacta respuestas hipotéticas tuyas).** La IA te pide confirmación ANTES de cambiar cualquier nivel.
- Subir de nivel exige evidencia (gates de abajo).
- `3` solo se gana por recuperación en frío (domingo).

## Gates de subida
| Subida | Evidencia exigida |
| 0→1 | explicación + quiz de comprensión acertado **+ producción: predecir un número con un N no visto y justificar (la salida esperada no se muestra antes)** |
| 1→2 | esqueleto completado + 1 pregunta conceptual acertada |
| 2→3 | solo recuperación en frío (domingo) |

## Regla de descenso
- Si en una kata nivel 2 se necesitó el peldaño 3 de pistas (señalar el error) o superior, o reescribir de memoria ⇒ al cierre el concepto **baja a 1**.

## Registro de Conceptos

- concepto: Big O / complejidad algorítmica
  tema: dsa
  tipo: mecanismo
  nivel: 1 (visto con ayuda)
  último_repaso: —
  evidencia: "Producción (N=40 no visto): \"al ser unos loops anidados, es O(n^2), por lo tanto: 40^2, dando como resultado: 1600 operaciones\" ✅ · quiz comprensión \"O(n²)\" ✅ · ¿entendiste? \"s\""

- concepto: Dynamic array / `realloc` amortizado
  tema: dsa
  tipo: mecanismo
  nivel: 1 (visto con ayuda)
  último_repaso: —
  evidencia: "Producción (N=20, c₀=4): \"los x2 ocurren en 4, 8, y 16... por lo tanto son 3 realloc... y la capacidad final es de 32 de capacidad\" ✅ · quiz comprensión \"realloc ×2 → reasignar → insertar\" ✅ · prerrequisito \"malloc(N * sizeof(int))\" ✅ · ¿entendiste? \"s\""

- concepto: C — fork/exec/wait
  tema: c
  tipo: mecanismo
  nivel: 2 (provisional)
  último_repaso: —
  evidencia: "mysh v1.0 taggeado (S3)"

- concepto: C — señales / sigaction
  tema: c
  tipo: mecanismo
  nivel: 2 (provisional)
  último_repaso: —
  evidencia: "mysh v1.5 taggeado (S4)"

- concepto: C — pipes / IPC
  tema: c
  tipo: mecanismo
  nivel: 2 (provisional)
  último_repaso: —
  evidencia: "mysh v2.0 (S5) — commit+tag pendiente"

- concepto: C — malloc/free · stack vs heap
  tema: c
  tipo: mecanismo
  nivel: 1
  último_repaso: —
  evidencia: "S1 cerrado (sin milestone)"

- concepto: C — no cursado (threads, bitwise, variadic, oop-emulation, advanced pointers)
  tema: c
  tipo: mecanismo
  nivel: 0 (no visto)
  último_repaso: —
  evidencia: "—"

> `2 (provisional)` = listo para kata libre respaldado por milestone, pero sin recuperación en frío aún
> (nadie alcanza `3` todavía).
