# Calendario Maestro — Modelo Semestre/Vacaciones y Dos Etapas

> **Fuente única** del ritmo y cronograma de estudio. Define los regímenes de dedicación según el período lectivo, los hitos de empleabilidad y la estrategia en Dos Etapas.

---

## 1. Regímenes de Horas y Dedicación

| Período | Rango de Fechas | Esquema | Total Semanal |
| :--- | :--- | :--- | :--- |
| **Semestre** | Oct–Nov 2026 · mar–may 2027 · ago–nov 2027 | Lun–Vie 2 h/día · Sáb–Dom–Lun 5 h/día | **20–23 h / semana** |
| **Vacaciones** | dic 2026 – feb 2027 · jun–jul 2027 | 5 h/día × 5–6 días | **25–30 h / semana** |
| **Semanas de exámenes** | Según calendario universitario | 2–3 h/día | **8–10 h / semana** |

- **Regla del 80%:** planifica como máximo el 80% de tu capacidad. El 20% restante es para exámenes, imprevistos, salud y vida.
- **Días de deep work (Sáb–Dom–Lun):** implementación, testing, debug (`go test`, `-race`, `go vet`, `dlv`) y proyectos.
- **Días de semana (Lun–Vie, 2 h):** conceptos, documentación, katas atómicas y lectura.
- **Nunca** se compensa una semana perdida duplicando horas: se recorta alcance.

---

## 2. Calendario Inmediato (Oct 2026 – Nov 2027)

| Periodo | Fase | Situación | Foco | Hito |
| :--- | :--- | :--- | :--- | :--- |
| **26 oct – 29 nov 2026** | F2 (arranque) | Últimas 5 semanas del 6to semestre | Tour de Go + esqueleto de `taskapi` + diagnóstico de inglés | `taskapi` esqueleto con Postgres en Docker |
| **dic 2026 – feb 2027** | F2 | Vacaciones (3 meses) | Go aplicado + `taskapi v1` + inglés intensivo | **`taskapi v1` desplegada**, tests, CI, README/ADRs · B1 en curso |
| **mar – may 2027** | F3 | 7mo semestre | Endurecer `taskapi` + SQL + Docker/CI + postulaciones | 30+ postulaciones, entrevistas, `taskapi v2` |
| **jun – jul 2027** | F4 | Vacaciones | Portfolio + system design básico + benchmark | README/ADRs pulidos, benchmark reproducible |
| **ago – nov 2027** | F5 | 8vo semestre | **Tesis (bloque reservado)** + entrevistas + remoto USD | Tesis cerrada · oferta o pipeline activo |
| **nov/dic 2027** | — | Graduación | Cierre de Etapa 1 | Titulación · B1+ |
| **dic 2027 – feb 2028** | Buffer | Post-graduación | Negociación, plan B, primeras semanas de empleo | Oferta aceptada o plan B en marcha |

> **Tesis:** la universidad aún no asigna tema ni fechas. F5 la reserva como bloque de 15–18 h/semana y se ajusta cuando exista información. Hasta entonces no se planifica `project X` en detalle.

---

## 3. Hitos de Empleabilidad

| Fecha | Hito | Dónde se trabaja |
| :--- | :--- | :--- |
| Nov 2026 | `taskapi` esqueleto + entorno Go listo | `learning-go/` |
| Feb 2027 | `taskapi v1` pública + CV, LinkedIn y GitHub listos | `learning-go/` + [`yordycg-portfolio`](https://github.com/yordycg/yordycg-portfolio) |
| Mar–May 2027 | 30+ postulaciones, 2+ entrevistas técnicas | `yordycg-portfolio` |
| Jun 2027 | Inglés B1 (fuera de este repo) | Plan personal |
| Jul 2027 | Portfolio pulido + benchmark reproducible | `yordycg-portfolio` |
| Ago–Nov 2027 | Tesis + postulaciones full-time/remoto | Universidad + `yordycg-portfolio` |
| Nov/Dic 2027 | Graduación + B1+ | — |

> **Búsqueda laboral:** el detalle (CV, LinkedIn, tracker, canales, outreach) vive en [`yordycg-portfolio`](https://github.com/yordycg/yordycg-portfolio). Aquí solo se registran los hitos que condicionan el estudio.

---

## 4. Cronograma Maestro — Etapa 1: Pre-Graduación

| Fase | Período | Duración | Foco Técnico Principal | Entregable / Hito |
| :--- | :--- | :--- | :--- | :--- |
| **F1** | 14 jun – 30 sep 2026 | ~15 sem. | Linux Internals, C & DSA Fundamentos | `mysh v2.0` + dynamic array + linked list |
| **F2** | 26 oct 2026 – 28 feb 2027 | ~18 sem. | Go, HTTP, PostgreSQL, testing, deploy | `taskapi v1` desplegada |
| **F3** | 1 mar – 31 may 2027 | 13 sem. | Hardening, SQL, Docker/CI, primera experiencia | `taskapi v2` + 30+ postulaciones |
| **F4** | 1 jun – 31 jul 2027 | 9 sem. | Portfolio, system design básico, benchmark | Portfolio listo para entrevistas |
| **F5** | 1 ago – 30 nov 2027 | 17 sem. | Tesis, entrevistas, remoto USD, cierre | Titulación + oferta/pipeline |
| **BUFFER** | dic 2027 – feb 2028 | ~10 sem. | Negociación, plan B, inserción laboral | Primer empleo o puente freelance |
| **ETAPA 2** | 2028+ | — | Especializaciones (Data, Cloud, Mobile) | Después del primer empleo |

**Disciplinas transversales:**

- **DSA:** 2–3 problemas/semana desde nov 2026; ~100–120 al cierre de F5. Patrones, no problemas sueltos.
- **Inglés:** fuera de este repo. Hito B1 en jun 2027 y B1+ en dic 2027.
- **Empleo:** postulaciones desde mar 2027; el detalle vive en `yordycg-portfolio`.
- **Documentación:** README/ADRs dentro de `taskapi`; no hay fase separada de arquitectura.

---

## 5. Etapa 2: Especializaciones Post-Graduación (2028+)

Especializaciones a cursar **después del primer empleo**, no en paralelo con la tesis:
- **Especialización A — Data Engineering:** Python idiomático, Kafka streaming, dbt Core, DuckDB, arquitecturas Lambda/Kappa (`eventpipe`).
- **Especialización B — Cloud (AWS) & Kubernetes:** AWS (ECS/EKS, RDS, S3), *Kubernetes the Hard Way*, Terraform, certificación AWS SAA-C03.
- **Especialización C — Mobile Multiplataforma:** Kotlin Multiplatform (KMP) + Compose Multiplatform.
- **Transversal — Arquitectura:** DDD táctico, Clean/Hexagonal, patrones GoF idiomáticos. Se estudia cuando el trabajo lo pida, no antes.

---

## 6. Estado Operativo y Enlaces

- **Seguimiento diario de Go:** [`learning-go/README.md`](learning-go/README.md)
- **Seguimiento diario de DSA:** [`learning-dsa/README.md`](learning-dsa/README.md)
- **Hoja de ruta estratégica:** [`docs/roadmap.md`](docs/roadmap.md)
- **Fuentes técnicas verificadas:** [`docs/SOURCES.md`](docs/SOURCES.md)
- **Carrera, CV y postulaciones:** [`yordycg-portfolio`](https://github.com/yordycg/yordycg-portfolio)
