# Calendario Maestro — Modelo Semestre y Vacaciones

> **Fuente única** del ritmo y cronograma de estudio. Define los regímenes de dedicación según el período lectivo universitario y las vacaciones.

---

## 1. Regímenes de Horas y Dedicación

| Período | Rango de Fechas | Esquema Diario | Total Semanal |
| :--- | :--- | :--- | :--- |
| **Régimen Semestre** | 28 Sep – 22 Nov 2026 | Mar–Vie: 1h/día (4h) · Sáb–Dom–Lun: 4h/día (12h) | **16 horas / semana** |
| **Régimen Vacaciones** | Desde 23 Nov 2026 | 4 horas / día $\times$ 7 días *(a confirmar según trabajo)* | **28 horas / semana** |

- **Días de semana (Mar–Vie, 1h):** Asimilación de conceptos, lectura de documentación/papers y katas atómicas.
- **Fin de semana + Lunes (Sáb–Dom–Lun, 4h):** Bloques de deep work para implementación, testing, depuración (ASan/GDB) y proyectos de fin de fase.

---

## 2. Calendario del Semestre Universitario (Hasta 22 Nov 2026, 16h/sem)

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

## 3. Régimen Intensivo de Vacaciones (Desde 23 Nov 2026, 28h/sem proyectadas)

*(Sujeto a confirmación según compromisos laborales / pasantía).*

### Continuación de Fase 2 (Go + PostgreSQL + Seguridad + `taskapi`)
- **Semana 23 – 29 Nov 2026 (28h):** PostgreSQL y Modelado ER (pgexercises, CS50 SQL Designing, normalización).
- **Semana 30 Nov – 6 Dic 2026 (28h):** Índices y Rendimiento (`EXPLAIN ANALYZE`, MVCC, aislamiento, transacciones).
- **Semana 7 – 13 Dic 2026 (28h):** Seguridad Backend (PortSwigger labs: SQLi, Auth, JWT; defensas OWASP, bcrypt).
- **Semanas 14 – 27 Dic 2026 (56h):** Proyecto `taskapi` (REST API segura en Go + Postgres, tests de integración, Docker básico) y pulido final.
> 🎯 **Cierre Definitivo de Fase 2:** **27 de Diciembre de 2026**.

### Fase 3: Sistemas Distribuidos + Docker + Redis + Observabilidad + CI/CD
- **28 Dic 2026 – 21 Feb 2027 (8 semanas a 28h = 224 horas):** Docker multi-stage, Redis caché y rate limiting, OpenTelemetry + Prometheus/Grafana, Circuit Breaker, CI/CD con GitHub Actions y proyecto `resilient-api`.
> 🎯 **Cierre Definitivo de Fase 3:** **21 de Febrero de 2027**.

---

## 4. Estado Operativo y Enlaces

- **Seguimiento diario de DSA:** [`learning-dsa/README.md`](learning-dsa/README.md)
- **Hoja de ruta estratégica completa:** [`docs/roadmap.md`](docs/roadmap.md)
- **Fuentes técnicas verificadas:** [`docs/SOURCES.md`](docs/SOURCES.md)
