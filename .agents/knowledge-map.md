# Knowledge Map — Nivel por Concepto (fuente de verdad del nivel)

> Escala: `0 = no visto` · `1 = visto (con ayuda)` · `2 = listo para kata libre` · `3 = en frío`.
> Columnas: **evidencia** (qué respalda el nivel, con pregunta y respuesta literal del alumno) y **último repaso** (fecha de recuperación en frío).

## Reglas
- Al abrir un tema, la IA consulta esta tabla (Paso 0 del contrato).
- Concepto ausente ⇒ `0` y se añade antes de continuar.
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

## Estado honesto (inicializado 2026-09-21)

| Concepto | Nivel | Evidencia | Último repaso |
|----------|-------|-----------|---------------|
| Big O / complejidad algorítmica | 1 (visto con ayuda) | Producción (N=40 no visto): "al ser unos loops anidados, es O(n^2), por lo tanto: 40^2, dando como resultado: 1600 operaciones" ✅ · quiz comprensión "O(n²)" ✅ · ¿entendiste? "s" | — |
| Dynamic array / `realloc` amortizado | 1 (visto con ayuda) | Producción (N=20, c₀=4): "los x2 ocurren en 4, 8, y 16... por lo tanto son 3 realloc... y la capacidad final es de 32 de capacidad" ✅ · quiz comprensión "realloc ×2 → reasignar → insertar" ✅ · prerrequisito "malloc(N * sizeof(int))" ✅ · ¿entendiste? "s" | — |
| C — fork/exec/wait | 2 (provisional) | mysh v1.0 taggeado (S3) | — |
| C — señales / sigaction | 2 (provisional) | mysh v1.5 taggeado (S4) | — |
| C — pipes / IPC | 2 (provisional) | mysh v2.0 (S5) — commit+tag pendiente | — |
| C — malloc/free · stack vs heap | 1 | S1 cerrado (sin milestone) | — |
| C — no cursado (threads, bitwise, variadic, oop-emulation, advanced pointers) | 0 (no visto) | — | — |

> `2 (provisional)` = listo para kata libre respaldado por milestone, pero sin recuperación en frío aún
> (nadie alcanza `3` todavía).
