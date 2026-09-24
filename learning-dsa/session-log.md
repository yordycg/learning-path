# Session Log — DSA Track (learning-dsa)

> Append-only, más reciente arriba. Cada sesión: fecha, archivos, concepto, lecciones, commits.
> Historia C/systems (S1–S5) en [`../learning-c/session-log.md`](../learning-c/session-log.md).

## 2026-09-24 — S6 D3 · Criterio array (nivel 0 → 1)

- **Concepto:** Criterio array — acceso O(1) vs inserción/borrado O(n); cache locality. La contigüidad como causa raíz de AMBOS (ventaja y costo).
- **Nivel:** 0 → 1 (confirmado por el alumno).
- **Evidencia:**
  - Quiz prerrequisito (¿por qué arr[i] es O(1)?): "El array vive en memoria contigua: la CPU calcula la dirección base + i·sizeof(tipo) y salta directo" ✅
  - Quiz comprensión (N=1000 insertar índice 0): "1000 — hay que mover todos los elementos para abrir el hueco en el índice 0" ✅
  - Producción (N=9 borrar índice 2): "correr 6 elementos / izquierda / iniciar loop en i=2, arr[i] = arr[i+1], tener cuidado en la última iteración" ✅ (off-by-one detectado: parar en i < N-1)
  - Conceptual (grilla de píxeles): "si no se insertan o borran celdas, si el array es la eleccion correcta por su O(1) en el acceso" ✅
  - ¿Entendiste?: "s"
- **Lecciones:** insertar en índice i = correr N-i; borrar en i = correr N-i-1 (peor caso O(n)); cache locality = líneas de caché (~64 B) → recorrido secuencial rápido; criterio = por patrón de uso, no por estructura en abstracto.
- **Archivos:** — (nivel 0, sin kata de código).
- **Commits:** — (cierre de archivos).

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
