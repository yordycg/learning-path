# DSA Track — Data Structures & Algorithms (C & Go)

> **Cockpit de Estudio Autónomo.** El objetivo central es dominar el **criterio de selección**: dado un problema, reconocer qué estructura de datos corresponde y por qué (acceso, inserción, memoria, orden, complejidad Big-O y _cache locality_).

---

> [!IMPORTANT]
> **Decisión Técnica: Cierre del Track en C y Transición Estratégica a Go (21 Oct 2026)**
> - **Objetivo de bajo nivel consolidado:** Los fundamentos de memoria física contigua vs. no contigua, punteros y gestión en el heap quedaron asimilados mediante `mysh v2.0`, `1-big-o.c`, `2-dynamic-array.c`, `3-array-tradeoffs.c` y la base de `4-linked-list.c` (verificados sin fugas con AddressSanitizer).
> - **Maximización del ROI para Backend & Entrevistas:** Implementar desde cero estructuras auxiliares en C (stack, queue, hash table) aporta rendimientos decrecientes frente a la meta laboral. El entrenamiento algorítmico se traslada directamente a **Go** (`learning-dsa/go/` y NeetCode Blind 75), priorizando el **reconocimiento de patrones** (Two Pointers, Sliding Window, Monotonic Stack, Hash Sets), la fluidez idiomática con `slices` y `maps`, y el análisis de trade-offs en tiempo y espacio.
> - **Qué se gana y qué se sacrifica:** se sacrifica la implementación manual de hash table en C; se compensa leyendo los internals de `map` en Go (Swiss tables) y resolviendo la categoría Arrays & Hashing de NeetCode. El criterio de selección se conserva; solo cambia el lenguaje de práctica.
> - **DSA es hilo permanente, no fase:** arranca con la F2 (26 oct 2026) a **2–3 problemas/semana**, en paralelo a Go. Es requisito de entrevista, no un extra; por eso no se posterga ni se hace sprint final. Los problemas se resuelven **en Go** desde el inicio.
> - **Meta:** **~100–120 problemas** al cierre de F5 (nov 2027), organizados por patrón, con repaso de errores.

---

## 0. Objetivos y meta

| Aspecto | Definición |
| :--- | :--- |
| **Cadencia** | 2–3 problemas/semana (~3 h, incluyendo 1 h de repaso) |
| **Meta a nov 2027** | ~100–120 problemas |
| **Lenguaje** | Go (C solo como historia: memoria y punteros ya cubiertos) |
| **Fuente** | [NeetCode — Blind 75 → 150](https://neetcode.io/practice) por categorías |
| **Métrica real** | % de problemas que puedes reescribir desde cero una semana después |
| **Regla** | Si no puedes explicar el patrón en voz alta, el problema no cuenta |

**Progresión por patrones (orden sugerido):**
`Arrays & Hashing` → `Two Pointers` → `Sliding Window` → `Stack` → `Binary Search` → `Linked List` → `Trees` → `Heap / Priority Queue` → `Backtracking` → `Graphs` → `1-D DP` → `Greedy` → `Intervals`.

---

## 1. Progreso Semanal

### Track C — cerrado

| Semana | Fechas (2026)      | Tema Central                          | Archivos Clave                                                | Estado        |
| :----- | :----------------- | :------------------------------------ | :------------------------------------------------------------ | :------------ |
| **S1** | **28 Sep – 4 Oct** | **Big O & Dynamic Array**             | `c/1-big-o.c`, `c/2-dynamic-array.c`, `c/3-array-tradeoffs.c` | ✅ **Cerrado** |
| **S2** | **5 – 11 Oct**     | **Doubly Linked List (Base)**         | `c/4-linked-list.c`                                           | ✅ **Cerrado** |
| **S3** | **12 – 25 Oct**    | **Stack & Queue / Hash Table**        | Pivote a Go — no se implementan en C                          | ⏩ **Cerrado por decisión** |

### Track Go — activo

| Semana | Fechas | Patrón | Objetivo |
| :--- | :--- | :--- | :--- |
| **G1** | 26 oct – 1 nov | Arrays & Hashing | 3 problemas: `contains duplicate`, `valid anagram`, `two sum` |
| **G2** | 2 – 8 nov | Arrays & Hashing / Two Pointers | 3 problemas |
| **G3** | 9 – 15 nov | Two Pointers / Sliding Window | 3 problemas |
| **G4** | 16 – 22 nov | Stack | 3 problemas |
| **G5** | 23 – 29 nov | **Repaso** (exámenes) | Rehacer los 3 problemas que peor salieron |
| **dic 2026 – feb 2027** | Vacaciones | Binary Search → Linked List → Trees | 3/semana · acumulado ~40 |

> No hay pausa: la cadencia es baja a propósito (2–3/semana) para que sea sostenible durante 13 meses. Es preferible 3 problemas bien repasados que 10 vistos una vez.

---

## 2. Historia: syllabus en C (cerrado, se conserva como referencia)


### 📍 Semana 1: Big O & Dynamic Array (28 Sep – 4 Oct) — [Cerrado ✅]

- [x] **Paso 1 — Fundamentos Big O (Lectura rápida, ~15 min):**
  - Leer [freeCodeCamp — Big O Notation Explained](https://www.freecodecamp.org/news/big-o-notation-why-it-matters-and-why-it-doesnt-1674cfa8a23c/).
  - Crear `c/1-big-o.c`: Comparar con `clock()` el tiempo de CPU de un bucle $O(n)$ contra un bucle anidado $O(n^2)$.
- [x] **Paso 2 — Concepto Dynamic Array (Video troncal, ~30 min):**
  - Ver [William Fiset — Dynamic Arrays](https://www.youtube.com/watch?v=RBSGKlAvoiM&t=765s) (YouTube: min 12:45 a 45:10).
  - Entender modelo mental: puntero `data*`, `size`, `capacity`, resize $2\times$ amortizado. _(Apoyo visual si hace falta: [VisuAlgo Array](https://visualgo.net/))_.
- [x] **Paso 3 — Implementación Base:**
  - Crear `c/2-dynamic-array.c`: Implementar `struct DynamicArray` con `darray_create`, `darray_destroy` y `darray_push_back` con crecimiento multiplicativo.
- [x] **Paso 4 — Operaciones y Trade-offs:**
  - En `c/2-dynamic-array.c`: Implementar `darray_get`, `darray_set` (con bounds checking) y `darray_pop`.
  - Crear `c/3-array-tradeoffs.c`: Demostrar el costo de insertar en índice 0 ($O(n)$ por desplazamiento de memoria con `memmove`) vs insertar al final ($O(1)$ amortizado).
- [x] **Paso 5 — Validación DoD & Cierre de Semana:**
  - Ejecutar: `just run learning-dsa/c/2-dynamic-array.c` insertando 100.000 elementos.
  - Verificar: **0 leaks y 0 errores de memoria** con AddressSanitizer.
  - Commit: `feat(dsa): implement dynamic array with resize in C`.

---

### 📍 Semana 2: Doubly Linked List & Modelo de Nodos (5 – 11 Oct) — [Cerrado ✅]

- [x] **Paso 1 — Concepto Troncal (Video, ~40 min):**
  - Ver [William Fiset — Singly & Doubly Linked Lists](https://www.youtube.com/watch?v=RBSGKlAvoiM&t=2710s) (YouTube: min 45:10 a 1:24:20).
  - Punteros `head`, `tail`, `next`, `prev`, inserción en extremos y eliminación de nodos.
- [x] **Paso 2 — Implementación Base de Doubly Linked List en C:**
  - Crear `c/4-linked-list.c`: Estructuras `Node` y `LinkedList`, `list_create`, `list_push_front`, `list_push_back`, `list_destroy`, `list_len`, `list_is_empty`.
- [x] **Paso 3 — Validación DoD:**
  - Recorrido sin mutación de punteros y verificación con AddressSanitizer: **0 leaks y 0 errores**.
  - Documentación técnica estilo Linux Kernel Doc en todas las funciones y structs.
  - Commit: `feat(dsa): implement doubly linked list base in C`.
- [x] **Paso 4 — Cierre del track de C:**
  - Se consolida la comprensión del costo de memoria dispersa en el heap frente a la contigüidad de un array. Se formaliza el pivote a Go.

---

### 📍 Activo: NeetCode & DSA en Go

DSA está activo desde la semana 1 de F2, con la pista de **NeetCode Blind 75 / 150**:

- **Foco:** Resolución de problemas por categorías (Arrays & Hashing $\to$ Two Pointers $\to$ Sliding Window $\to$ Stack $\to$ Binary Search $\to$ Trees).
- **Régimen:** 2–3 problemas/semana (~3 h con repaso) integrado con el estudio de Go.
- **Entregables:** Soluciones comentadas y estructuradas en el directorio `learning-dsa/go/`, con el patrón y la complejidad anotados en el propio código.
- **Repaso:** cada error genera una nota breve; los problemas fallados se rehacen a los 3 días, 1 semana y 1 mes.
- **Criterio de avance:** no se pasa a un patrón nuevo hasta poder resolver un problema representativo del anterior sin mirar.

---

## 3. Estructura del Módulo

```
learning-dsa/
├── README.md              # Cockpit operativo y checklist (este archivo)
├── c/                     # Código en C (Fundamentos de memoria y estructuras base)
│   ├── 1-big-o.c          # Análisis de complejidad empírico
│   ├── 2-dynamic-array.c  # Dynamic array con realloc amortizado
│   ├── 3-array-tradeoffs.c# Inserción O(n) vs acceso O(1)
│   └── 4-linked-list.c    # Doubly linked list manual limpia con ASan
├── go/                    # ACTIVO — NeetCode Blind 75/150, 2–3 problemas/semana
└── graphs/                # Futuro (F5 en adelante) — grafos y problemas de sistemas
```

---

## 4. Reglas de Ejecución Técnica

1. **Compilación Estricta:** Ejecuta siempre mediante `just run <archivo.c>` para C o `go test ./...` para Go.
2. **Productive Failure (30–45 min):** Intenta resolver cada problema de forma autónoma. Si tras 30–45 minutos no logras avanzar, revisa la explicación del patrón, cierra la solución y prográmala tú mismo desde cero.
3. **Persistencia Conceptual:** Diagramas de memoria y trade-offs se anotan en el vault de Obsidian (`MOC - DSA`). Aquí reside el código fuente limpio y ejecutable.
