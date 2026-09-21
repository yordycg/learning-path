# DSA Track — Data Structures & Algorithms (criterio de selección)

> Track de primer nivel de F1 (semanas S6–S10), extraído de `learning-c/3-expert/02-dsa/`. La meta **no** es "implementar X estructura", sino **elegir con criterio**: dado un problema, reconocer *qué* estructura y *qué* algoritmo corresponden y *por qué* (trade-offs de acceso / inserción / memoria / orden / complejidad).

## Progress Tracker

| Week | Dates          | Topic                  | Resource          | Deliverable                                                                                              | ✔ |
| ---- | -------------- | ---------------------- | ----------------- | -------------------------------------------------------------------------------------------------------- | - |
| S6   | Sep 21–27      | Big O + dynamic array  | Fiset + Silver.dev | análisis de complejidad + dynamic array; **criterio array vs lista**; GDB/ASan JIT                        | [ ] |
| S7   | Sep 28 – Oct 4 | Linked list            | Beej 20.3 + Fiset | linked list desde cero + `binary_search`; **criterio lista vs array**                                    | [ ] |
| S8   | Oct 5–11       | Stack + queue          | Fiset             | stack y queue manuales; **criterio LIFO/FIFO y elección de backing store**                               | [ ] |
| S9   | Oct 12–18      | Hash table + sorting   | Beej 24 + Fiset   | hash (separate chaining), merge sort; **criterio de búsqueda vs orden**                                  | [ ] |
| S10  | Oct 19–25      | Integración & cierre   | —                 | retos de selección + checklist de fase                                                                   | [ ] |

## Estructura por lenguaje

```
learning-dsa/
├── c/          # DSA en C (S6–S10, activo)
│   ├── 1-big-o.c
│   ├── 2-dynamic-array.c
│   ├── 3-array-tradeoffs.c
│   ├── 4-linked-list.c
│   ├── 5-list-vs-array.c
│   └── exercises/
├── go/         # futuro (F2) — antes learning-go/07-dsa-go/
└── graphs/     # futuro (F3) — antes learning-distributed/07-dsa-graphs/
```

> Los **conceptos** (Big O, criterios de selección, trade-offs) son agnósticos del lenguaje y viven en el vault de Obsidian (`MOC - DSA`), compartido por todas las fases. Acá solo vive el **código vehículo**.

## Recursos

- **Big O / complejidad:** [Fiset — Data Structures intro](https://www.youtube.com/watch?v=Qmt0QwzEmh0) · Silver.dev · AlgoMaster OS
- **Estructuras:** [Data Structures Easy to Advanced — Full (Fiset/freeCodeCamp)](https://www.youtube.com/watch?v=RBSGKlAvoiM) — ver por secciones
- **Problemas reales por estructura:** [70 Leetcode problems in 5+ hours (Stoney codes)](https://www.youtube.com/watch?v=lvO88XxNAzs) — ver solo la sección de la semana (método JIT)
- **Libro:** *Cracking the Coding Interview* (CTCI) — [PDF gratis](https://github.com/conanbatt/interview-ready/tree/main/technical-fundamentals/cracking-the-coding-interview/book)
- **Profundizar:** *The Algorithm Design Manual* (Skiena) — caps. 1–4

## Ritmo y operación

- Panel operativo semanal: [`status.md`](status.md) · Historia: [`session-log.md`](session-log.md)
- **Code-first:** cada día empieza con el intento de código, sin leer el recurso (JIT solo si el código falla).
- Compilación estricta: `just run <archivo.c>` (ASan + UBSan).
- Cadencia: Lun–Vie katas atómicas · Sáb reto de selección · Dom tick + Zettels.
