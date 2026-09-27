# Calendario Maestro — Modelo Semestre, Vacaciones y Dos Etapas

> **Fuente única** del ritmo y cronograma de estudio. Define los regímenes de dedicación según el período lectivo universitario, las vacaciones y la estrategia en Dos Etapas.

---

## 1. Regímenes de Horas y Dedicación

| Período | Rango de Fechas | Esquema Diario | Total Semanal |
| :--- | :--- | :--- | :--- |
| **Régimen Semestre** | 28 Sep – 22 Nov 2026 (y semestres 2027) | Mar–Vie: 1h/día (4h) · Sáb–Dom–Lun: 4h/día (12h) | **16 horas / semana** |
| **Régimen Vacaciones** | Ene–Feb 2027 (y pausas académicas) | 4 horas / día $\times$ 7 días *(ajustable según trabajo)* | **20–28 horas / semana** |

- **Días de semana (Mar–Vie, 1h):** Asimilación de conceptos, lectura de documentación/papers y katas atómicas.
- **Fin de semana + Lunes (Sáb–Dom–Lun, 4h):** Bloques de deep work para implementación, testing, depuración (ASan/GDB) y proyectos de fin de fase.

---

## 2. Calendario Semestral Inmediato (Hasta 22 Nov 2026, 16h/sem)

| Sem. Univ. | Fechas (2026) | Módulo / Fase | Foco Técnico | Estado |
| :--- | :--- | :--- | :--- | :--- |
| **4** | 31 ago – 6 sep | F1 · C/Systems | Procesos (`fork`, `exec`, `wait`, zombies) | ✅ Cerrado (`mysh v1.0`) |
| **5** | 7 – 13 sep | F1 · C/Systems | Señales (`sigaction`, `SIGINT`, `SIGCHLD`) | ✅ Cerrado (`mysh v1.5`) |
| **6** | 14 – 20 sep | F1 · C/Systems | Pipes e IPC (`pipe`, FIFOs, descriptores) | ✅ Cerrado (`mysh v2.0`) |
| **7** | 21 – 27 sep | Transición | C/Linux cerrado; revisión de fuentes y roadmap | ✅ Cerrado |
| **8** | **28 sep – 4 oct** | **F1 · DSA S1** | **Big O + Dynamic Array (desde cero)** | 🔄 Arranca mañana |
| **9** | **5 – 11 oct** | **F1 · DSA S2** | **Linked Lists** (nodos, punteros, `binary_search`) | [ ] Pendiente |
| **10** | **12 – 18 oct** | **F1 · DSA S3** | **Stack + Queue** (LIFO/FIFO, backing stores) | [ ] Pendiente |
| **11** | **19 – 25 oct** | **F1 · DSA S4** | **Hash Table + Sorting** (colisiones, merge sort) | [ ] Pendiente |
| **12** | **26 oct – 1 nov** | **F1 · DSA S5** | **Integración & Cierre Fase 1** (criterio de selección) | [ ] **Cierre F1 (1 Nov)** |
| **13** | **2 – 8 nov** | **F2 · Go S1** | Fundamentos de Go (sintaxis, structs, slices, pointers) | [ ] Inicio Fase 2 |
| **14** | **9 – 15 nov** | **F2 · Go S2** | Go Idiomático & TDD (*Learn Go with Tests*, interfaces, mocking) | [ ] Pendiente |
| **15** | **16 – 22 nov** | **F2 · Go S3** | Concurrencia en Go (goroutines, channels, context) | [ ] **Fin de clases (22 Nov)** |

---

## 3. Cronograma Maestro Etapa 1: Pre-Graduación (Hasta Dic 2027)

| Fase | Período Proyectado | Duración | Foco Técnico Principal | Proyecto / Hito |
| :--- | :--- | :--- | :--- | :--- |
| **F1** | 14 jun – 1 nov 2026 | 20 sem. | Linux Internals, C & DSA Fundamentos | `mysh v2.0` (cerrado) + DSA en C |
| **F2** | 2 nov 2026 – 31 ene 2027 | 13 sem. | Go Idiomático + PostgreSQL + Seguridad | Proyecto `taskapi` (REST API segura) |
| **F3** | 1 feb – 28 mar 2027 | 8 sem. | Docker + Redis + Observabilidad + CI/CD | Proyecto `resilient-api` (microservicio resiliente) |
| **F4** | 29 mar – 13 jun 2027 | 11 sem. | Arquitectura Hexagonal, DDD & System Design | Proyecto `architecture-docs` (Fly.io retos 1-4, C4, ADRs) |
| **F5** | 14 jun – 29 ago 2027 | 11 sem. | Portfolio de Alto Impacto & Preparación Entrevistas | 2 proyectos estrella pulidos + mocks STAR (Silver.dev) |
| **BUFFER** | **30 ago – 15 dic 2027** | **~15 sem.** | **Tesis de grado, exámenes finales y postulaciones remotas USD** | 🎓 **Graduación universitaria con empleo en USD** |

---

## 4. Etapa 2: Especializaciones Post-Graduación (2028+)

Especializaciones a cursar mientras se trabaja en la industria o se emprende:
- **Especialización A — Data Engineering:** Python idiomático, Apache Kafka streaming, dbt Core, DuckDB, arquitecturas Lambda/Kappa (`eventpipe`).
- **Especialización B — Cloud (AWS) & Kubernetes:** AWS (ECS/EKS, RDS, S3), *Kubernetes the Hard Way*, Terraform, certificaciones AWS SAA-C03.
- **Especialización C — Mobile Multiplataforma:** Kotlin Multiplatform (KMP) + Compose Multiplatform para Android e iOS (`mobile-app`).

---

## 5. Estado Operativo y Enlaces

- **Seguimiento diario de DSA:** [`learning-dsa/README.md`](learning-dsa/README.md)
- **Hoja de ruta estratégica completa:** [`docs/roadmap.md`](docs/roadmap.md)
- **Fuentes técnicas verificadas:** [`docs/SOURCES.md`](docs/SOURCES.md)
