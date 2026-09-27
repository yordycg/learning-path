# DSA Track — Data Structures & Algorithms en C (S1 a S5)

> **Cockpit de Estudio Autónomo.** El objetivo central es dominar la memoria manual en C y el **criterio de selección**: dado un problema, reconocer qué estructura de datos corresponde y por qué (acceso, inserción, memoria, orden, complejidad Big-O y *cache locality*).

---

## 1. Progreso Semanal

| Semana | Fechas (2026) | Tema Central | Archivos Clave | Estado |
| :--- | :--- | :--- | :--- | :--- |
| **S1** | **28 Sep – 4 Oct** | **Big O & Dynamic Array** | `c/1-big-o.c`, `c/2-dynamic-array.c`, `c/3-array-tradeoffs.c` | 🔄 **Activa** |
| **S2** | **5 – 11 Oct** | **Singly & Doubly Linked Lists** | `c/4-linked-list.c`, `c/5-list-vs-array.c` | [ ] Pendiente |
| **S3** | **12 – 18 Oct** | **Stack & Queue (Circular Buffer)** | `c/6-stack.c`, `c/7-queue.c` | [ ] Pendiente |
| **S4** | **19 – 25 Oct** | **Hash Table & Sorting (Merge Sort)** | `c/8-hash-table.c`, `c/9-merge-sort.c` | [ ] Pendiente |
| **S5** | **26 Oct – 1 Nov** | **Integración NeetCode & Cierre F1** | `c/exercises/*.c` + Checklist Cierre F1 | [ ] Pendiente |

*Nota:* El 1 de noviembre concluyen las 5 semanas de DSA en C, cerrando formalmente la **Fase 1**. A partir del 2 de noviembre (Fase 2 en Go), DSA se mantiene como un hábito continuo de 3h/semana resolviendo NeetCode Blind 75/150 en Go.

---

## 2. Syllabus Secuencial Prescriptivo

> **Regla de Ejecución:** No hay horarios fijos de reloj por día. Cada semana tiene una secuencia de pasos atómicos (`Paso 1` $\to$ `Paso 5`). Avanzas a tu propio ritmo según tu energía diaria, marcas la casilla y pasas al siguiente.

### 📍 Semana 1: Big O & Dynamic Array (28 Sep – 4 Oct)

- [ ] **Paso 1 — Fundamentos Big O (Lectura rápida, ~15 min):**
  - Leer [freeCodeCamp — Big O Notation Explained](https://www.freecodecamp.org/news/big-o-notation-why-it-matters-and-why-it-doesnt-1674cfa8a23c/).
  - Crear `c/1-big-o.c`: Comparar con `clock()` el tiempo de CPU de un bucle $O(n)$ contra un bucle anidado $O(n^2)$.
- [ ] **Paso 2 — Concepto Dynamic Array (Video troncal, ~30 min):**
  - Ver [William Fiset — Dynamic Arrays](https://www.youtube.com/watch?v=RBSGKlAvoiM&t=765s) (YouTube: min 12:45 a 45:10).
  - Entender modelo mental: puntero `data*`, `size`, `capacity`, resize $2\times$ amortizado. *(Apoyo visual si hace falta: [VisuAlgo Array](https://visualgo.net/))*.
- [ ] **Paso 3 — Implementación Base:**
  - Crear `c/2-dynamic-array.c`: Implementar `struct DynamicArray` con `darray_create`, `darray_destroy` y `darray_push_back` con crecimiento multiplicativo.
- [ ] **Paso 4 — Operaciones y Trade-offs:**
  - En `c/2-dynamic-array.c`: Implementar `darray_get`, `darray_set` (con bounds checking) y `darray_pop`.
  - Crear `c/3-array-tradeoffs.c`: Demostrar el costo de insertar en índice 0 ($O(n)$ por desplazamiento de memoria con `memmove`) vs insertar al final ($O(1)$ amortizado).
- [ ] **Paso 5 — Validación DoD & Cierre de Semana:**
  - Ejecutar: `just run learning-dsa/c/2-dynamic-array.c` insertando 100.000 elementos.
  - Verificar: **0 leaks y 0 errores de memoria** con AddressSanitizer.
  - Commit: `feat(dsa): implementar dynamic array con resize amortizado en c`.

---

### 📍 Semana 2: Singly & Doubly Linked Lists (5 – 11 Oct)

- [ ] **Paso 1 — Concepto Troncal (Video, ~40 min):**
  - Ver [William Fiset — Singly & Doubly Linked Lists](https://www.youtube.com/watch?v=RBSGKlAvoiM&t=2710s) (YouTube: min 45:10 a 1:24:20).
  - Punteros `head`, `tail`, `next`, `prev`, inserción en extremos y eliminación de nodos.
- [ ] **Paso 2 — Singly Linked List:**
  - Crear `c/4-linked-list.c`: `Node` struct (`data`, `next`), funciones `list_push_front`, `list_push_back`.
- [ ] **Paso 3 — Borrado Seguro:**
  - En `c/4-linked-list.c`: Implementar `list_delete_value` y `list_destroy` asegurando liberar la memoria nodo por nodo sin dejar punteros colgando.
- [ ] **Paso 4 — Criterio: Cache Locality:**
  - Crear `c/5-list-vs-array.c`: Benchmark comparando iteración secuencial sobre un array contiguo vs saltar entre nodos de linked list dispersos en el heap.
- [ ] **Paso 5 — Validación DoD & Cierre de Semana:**
  - Ejecutar: `just run learning-dsa/c/4-linked-list.c` con 10.000 nodos. ASan debe terminar limpio.
  - Commit: `feat(dsa): implementar linked list y benchmark de cache locality`.

---

### 📍 Semana 3: Stack & Queue (12 – 18 Oct)

- [ ] **Paso 1 — Concepto Troncal (Video, ~35 min):**
  - Ver [William Fiset — Stack & Queue](https://www.youtube.com/watch?v=RBSGKlAvoiM&t=5100s) (YouTube: min 1:25:00 a 2:05:00).
  - Principios LIFO vs FIFO y selección del backing store adecuado.
- [ ] **Paso 2 — Stack sobre Dynamic Array:**
  - Crear `c/6-stack.c`: `stack_push`, `stack_pop`, `stack_peek` reutilizando la lógica de array dinámico ($O(1)$ amortizado).
- [ ] **Paso 3 — Queue como Circular Buffer:**
  - Crear `c/7-queue.c`: Implementar Queue circular sobre array fijo con índices `head` y `tail` y operador `%` (evita el costo $O(n)$ al desencolar).
- [ ] **Paso 4 — Aplicación Práctica:**
  - Resolver el problema clásico de validación de paréntesis balanceados (`{[()]}`) usando `c/6-stack.c`.
- [ ] **Paso 5 — Validación DoD & Cierre de Semana:**
  - `just run learning-dsa/c/7-queue.c` validando wrapping circular sin leaks.
  - Commit: `feat(dsa): implementar stack y circular queue en c`.

---

### 📍 Semana 4: Hash Table & Sorting (19 – 25 Oct)

- [ ] **Paso 1 — Concepto Troncal (Video, ~45 min):**
  - Ver [William Fiset — Hash Tables](https://www.youtube.com/watch?v=RBSGKlAvoiM&t=15300s) (YouTube: min 4:15:00 a 5:05:00).
  - Hashing, colisiones, resolución por separate chaining y factor de carga.
- [ ] **Paso 2 — Hash Table con Separate Chaining:**
  - Crear `c/8-hash-table.c`: Función hash simple (`djb2`), arreglo de buckets con linked lists, `ht_put` y `ht_get`.
- [ ] **Paso 3 — Sorting Clásico (Merge Sort):**
  - Crear `c/9-merge-sort.c`: Algoritmo divide y vencerás $O(n \log n)$ implementado en C.
- [ ] **Paso 4 — Criterio de Selección:**
  - Documentar en Obsidian: ¿Cuándo usar Hash Table (búsqueda $O(1)$ sin orden) vs Array Ordenado con Búsqueda Binaria ($O(\log n)$)?
- [ ] **Paso 5 — Validación DoD & Cierre de Semana:**
  - Insertar y recuperar 500 strings en `c/8-hash-table.c` limpio con ASan.
  - Commit: `feat(dsa): implementar hash table con separate chaining y merge sort`.

---

### 📍 Semana 5: Integración NeetCode & Cierre Fase 1 (26 Oct – 1 Nov)

- [ ] **Paso 1 — Plataforma Troncal:**
  - [NeetCode — Arrays & Hashing](https://neetcode.io/practice) (filtro Blind 75).
- [ ] **Paso 2 — Retos en C (en `c/exercises/`):**
  - Resolver autónomamente en C:
    - `contains_duplicate.c`
    - `two_sum.c` (comparando fuerza bruta $O(n^2)$ vs Hash Table $O(n)$)
    - `valid_anagram.c` (conteo de frecuencias de caracteres)
- [ ] **Paso 3 — Verificación y Cierre Fase 1:**
  - Todos los ejercicios de S1 a S5 compilan y pasan `just run` sin errores ni fugas de memoria.
  - Actualizar checklist de Fase 1 en `calendario.md` y `docs/roadmap.md`.
- [ ] **Paso 4 — Cierre y Transición:**
  - Commit final: `chore(dsa): completar dsa en c y cerrar formalmente fase 1`.
  - Preparado para iniciar Fase 2 (Go + PostgreSQL) el 2 de noviembre.

---

## 3. Estructura del Módulo

```
learning-dsa/
├── README.md              # Cockpit operativo y checklist (este archivo)
├── c/                     # Código en C de Fase 1 (S1–S5)
│   ├── 1-big-o.c          # Análisis de complejidad empírico
│   ├── 2-dynamic-array.c  # Dynamic array con realloc amortizado
│   ├── 3-array-tradeoffs.c# Inserción O(n) vs acceso O(1)
│   ├── 4-linked-list.c    # Singly linked list manual
│   ├── 5-list-vs-array.c  # Benchmark de cache locality
│   ├── 6-stack.c          # Stack sobre dynamic array
│   ├── 7-queue.c          # Circular buffer queue
│   ├── 8-hash-table.c     # Hash table con separate chaining
│   ├── 9-merge-sort.c     # Merge sort O(n log n)
│   └── exercises/         # Retos NeetCode (contains_duplicate, two_sum, etc.)
├── go/                    # Futuro (F2 en adelante) — Hilo continuo semanal en Go
└── graphs/                # Futuro (F3/F5) — Algoritmos de grafos distribuidos
```

---

## 4. Reglas de Ejecución Técnica

1. **Compilación Estricta:** Ejecuta siempre mediante `just run <archivo.c>`. Las flags `-fsanitize=address,undefined` garantizarán que cualquier buffer overflow o memory leak se detecte de inmediato.
2. **Productive Failure (30–45 min):** Intenta resolver cada paso de forma autónoma. Si tras 30–45 minutos no logras avanzar, revisa el concepto o el pseudocódigo, cierra la referencia, y programa la solución tú mismo sin copiar.
3. **Persistencia Conceptual:** Los diagramas de memoria y trade-offs se anotan en el vault de Obsidian (`MOC - DSA`). Aquí reside el código fuente limpio y ejecutable.
