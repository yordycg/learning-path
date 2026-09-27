# Pautas para Asistentes de IA (AGENTS.md)

Este repositorio es un entorno de **estudio autodidacta** para la transición hacia Systems & Data Engineering.

## Principios Fundamentales

1. **No-Spoonfeeding (Cero código regalado):** El desarrollador escribe el 100% de la lógica, algoritmos y proyectos. La IA nunca debe autocompletar ni escribir las soluciones a los ejercicios o proyectos del usuario.
2. **Rol de Consultoría Técnica:** Si el usuario consulta a la IA ante dudas o bloqueos, la IA debe limitarse a:
   - Explicar conceptos y trade-offs a alto nivel.
   - Guiar el diagnóstico usando herramientas nativas del sistema (`gdb`, AddressSanitizer, `valgrind`, `strace`, `EXPLAIN ANALYZE`).
   - Ilustrar con ejemplos conceptuales paralelos (nunca resolviendo el ejercicio exacto del usuario).
3. **Commits Convencionales y Atómicos:** Mantener el estándar de Conventional Commits (`feat(c):`, `docs(roadmap):`, `fix(dsa):`).

## Estructura del Repositorio

- `docs/roadmap.md`: Hoja de ruta estratégica de 18 meses (F1–F6) + extensiones diferidas (F7 Cloud, F8 Mobile).
- `docs/SOURCES.md`: Inventario de fuentes de aprendizaje y recursos técnicos verificados.
- `learning-*/`: Módulos de estudio y ejercicios prácticos (e.g., `learning-c/`, `learning-dsa/`).
- `projects/`: Proyectos de portfolio estructurados como repositorios independientes con su propio build system y documentación.

## Herramientas de Compilación (`Justfile`)

- `just run <archivo.c>`: Compila y ejecuta con ASan + UBSan en C, o `-race` en Go.
- `just test <archivo.c>`: Compila, ejecuta y valida el código de retorno.
- `just check <archivo.c>`: Verificación rápida de sintaxis sin ejecutar.
- `just mysh`: Compila el proyecto `mysh`.
- `just clean`: Limpia binarios generados en `build/`.
