# Session Log — DSA Track (learning-dsa)

> Append-only, más reciente arriba. Cada sesión: fecha, archivos, concepto, lecciones, commits.
> Historia C/systems (S1–S5) en [`../learning-c/session-log.md`](../learning-c/session-log.md).

## 2026-09-22 — S6 D2 · Dynamic array (nivel 0 → 1)

- **Concepto:** Dynamic array — array vs dinámico, `realloc`, crecimiento amortizado (×2). Estructura `{ data, capacity, length }`.
- **Nivel:** 0 → 1 (confirmado por el alumno).
- **Evidencia:**
  - Quiz prerrequisito (heap vs VLA): "int *arr = malloc(N * sizeof(int));" ✅
  - ¿Entendiste?: "s"
  - Quiz comprensión (secuencia al crecer): "realloc ×2 → reasignar data al puntero devuelto → insertar" ✅
  - Producción (N=20, c₀=4 no vistos): "los x2 ocurren en 4, 8, y 16... por lo tanto son 3 realloc... y la capacidad final es de 32 de capacidad" ✅
  - Bonus (fórmula cerrada): derivó `k = ⌈log_g(N/c₀)⌉` paso a paso (Socrático); confusión inicial "capacity^k" (nombres) corregida con 1 pregunta.
- **Lecciones:** `realloc` puede MOVER el bloque → siempre reasignar el puntero devuelto (patrón seguro con `tmp`); crecer ×2, no +1; `capacity ≠ length`; fórmula `k = ⌈log₂(N/c₀)⌉` y `capacity_final = c₀·2^k`.
- **Archivos:** — (nivel 0, sin kata de código).
- **Commits:** (cierre de archivos).

## 2026-09-21 — S6 D1 · Big O (nivel 0 → 1)

- **Concepto:** Big O — qué mide, peor caso, crecimiento (conteo de ops vs N). Alcance del día: sin Ω/Θ ni amortizado.
- **Nivel:** 0 → 1 (confirmado por el alumno).
- **Evidencia:**
  - Quiz prerrequisito: "Se duplica (≈200 ops)" ✅
  - ¿Entendiste?: "s"
  - Quiz comprensión (nested loops): "O(n²)" ✅
  - Producción (N=40 no visto): "al ser unos loops anidados, es O(n^2), por lo tanto: 40^2, dando como resultado: 1600 operaciones" ✅
- **Lecciones:** conteo de ops escala con N; loops anidados ⇒ N²; Big O ignora constantes y términos menores; describe peor caso.
- **Archivos:** — (nivel 0, sin kata de código).
- **Commits:** — (cierre de archivos en curso).
