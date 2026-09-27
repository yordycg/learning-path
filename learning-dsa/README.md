# DSA Track — Data Structures & Algorithms (Criterio de Selección)

Track de primer nivel de Fase 1 (semanas S6–S10), enfocado en **criterio de selección y trade-offs**: dado un problema, reconocer qué estructura de datos y algoritmo corresponden, y por qué (acceso, inserción, memoria, orden, complejidad Big-O y cache locality).

---

## Plan de Estudio & Progreso (S6–S10)

| Semana | Fechas | Tema | Recursos Principales | Entregable / Práctica | Estado |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **S6** | Sep 21–27 | Big O + Dynamic Array | [Princeton Part I](https://www.coursera.org/learn/algorithms-part1) · [OpenDSA](https://opendsa-server.cs.vt.edu/) · [freeCodeCamp Big O](https://www.freecodecamp.org/news/big-o-notation-why-it-matters-and-why-it-doesnt-1674cfa8a23c/) | `c/1-big-o.c`, `c/2-dynamic-array.c`, `c/3-array-tradeoffs.c`; criterio array vs lista | 🔄 En curso (D1-D3 listos) |
| **S7** | Sep 28 – Oct 4 | Linked List | [Princeton Part I](https://www.coursera.org/learn/algorithms-part1) · [VisuAlgo](https://visualgo.net/) | `c/4-linked-list.c`, `c/5-list-vs-array.c`; criterio lista vs array | [ ] Pendiente |
| **S8** | Oct 5–11 | Stack + Queue | [Princeton Part I](https://www.coursera.org/learn/algorithms-part1) · [OpenDSA](https://opendsa-server.cs.vt.edu/) | Stack y queue manuales; criterio LIFO/FIFO y backing store | [ ] Pendiente |
| **S9** | Oct 12–18 | Hash Table + Sorting | [Princeton Part I](https://www.coursera.org/learn/algorithms-part1) · [Open Data Structures](https://opendatastructures.org/) | Hash table (separate chaining), merge sort; criterio búsqueda vs orden | [ ] Pendiente |
| **S10** | Oct 19–25 | Integración & Cierre | [NeetCode](https://neetcode.io/practice) · Retos integradores | Ejercicios de selección y cierre de fase | [ ] Pendiente |

*Nota:* Las 3 primeras semanas se resuelven en C (dynamic array, linked list, hash table) para afianzar el modelo de memoria. A partir de Fase 2 (Go), DSA se mantiene como un hilo continuo de práctica semanal (~3h/semana con [NeetCode Blind 75/150](https://neetcode.io/practice)).

---

## Estructura de Archivos

```
learning-dsa/
├── c/                     # Implementaciones en C (S6–S10)
│   ├── 1-big-o.c          # Análisis de complejidad empírico
│   ├── 2-dynamic-array.c  # Dynamic array con realloc y crecimiento amortizado
│   ├── 3-array-tradeoffs.c# Inserción/borrado O(n) vs acceso O(1)
│   ├── 4-linked-list.c    # Implementación manual de nodos y punteros
│   ├── 5-list-vs-array.c  # Comparativa y trade-offs
│   └── exercises/         # Problemas y retos de selección
├── go/                    # Futuro (F2) — Hilo continuo en Go (NeetCode)
└── graphs/                # Futuro (F3/F5) — Grafos y algoritmos distribuidos
```

> Los **conceptos teóricos** (Big O, criterios de selección, tablas de decisión) son agnósticos del lenguaje y se documentan en el vault de Obsidian (`MOC - DSA`). Aquí reside el **código de práctica**.

---

## Recursos Verificados

- **Concepto (Teoría y videos):** [Princeton Algorithms Part I](https://www.coursera.org/learn/algorithms-part1) (Kevin Wayne, Robert Sedgewick — auditable gratis).
- **Apoyo Interactivo:** [OpenDSA](https://opendsa-server.cs.vt.edu/) y [VisuAlgo](https://visualgo.net/) (visualización interactiva de estructuras).
- **Práctica Continua (LeetCode Patterns):** [NeetCode — Blind 75 → 150](https://neetcode.io/practice).
- **Referencia Abierta:** [Open Data Structures](https://opendatastructures.org/) (Pat Morin).
- **Lectura y Problemas de Referencia:** *The Algorithm Design Manual* (Skiena, caps. 1–4) y *Cracking the Coding Interview* (CTCI, 6ª ed.).

---

## Metodología de Práctica Personal

1. **Compilación estricta:** `just run <archivo.c>` ejecuta el código con AddressSanitizer y UndefinedBehaviorSanitizer activados para capturar leaks o accesos indebidos inmediatamente.
2. **Productive Failure:** Dedicar 30–45 minutos a resolver un problema de forma autónoma. Si tras ese tiempo no se llega a la solución, consultar el patrón en NeetCode/referencia, entenderlo, y al día siguiente reescribir la solución desde cero sin mirar.
3. **Repaso Espaciado:** Anotar errores y patrones de trade-offs en Anki o notas Zettelkasten personales.
