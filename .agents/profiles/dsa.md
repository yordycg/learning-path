# Perfil: DSA (Estructuras de Datos y Algoritmos)

## Verificación
- run/test: según el lenguaje de implementación activo (hoy: perfil `c.md`).
  DSA no tiene su propio comando de build; hereda el del lenguaje en el que
  se está codeando la kata (`learning-dsa/c/`).

## Convención de vocabulario obligatoria en nivel 0
- Toda explicación de nivel 0 DEBE definir explícitamente, antes de usarlos:
  - **N**: qué representa en el problema concreto (tamaño de input).
  - **operación**: qué cuenta como una operación en ese contexto.
  - **ops**: la convención de conteo exacta (ej. "cada comparación cuenta
    como 1 op, cada swap cuenta como 1 op").
- **Fuera de alcance en nivel 0**: no introducir notación Ω/Θ ni análisis de
  complejidad amortizada. Eso pertenece a un nivel posterior del tema.

## Clasificación por defecto de sub-conceptos nuevos
- `vocabulario` (default): nombres de estructuras, definiciones de N/operación/ops,
  terminología (ej. "qué es un índice", "qué es una colisión").
- `mecanismo`: algo con un "por qué" de diseño real (ej. por qué el
  redimensionamiento amortizado de un array dinámico es O(1) amortizado, por
  qué un hash table usa buckets). Estos sí ameritan el Paso 0 completo con
  Principio I/II y DAG.

## Verdades incondicionales base del tema
- (completar a medida que aparezcan; ej. "todo algoritmo de comparación tiene
  un límite inferior de Ω(n log n) para ordenar")
