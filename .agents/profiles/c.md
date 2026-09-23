# Perfil: C

## Verificación (Code-First)
- Toda teoría aterriza en código compilable. Build estricto:
  `just run <file>` / `just test <file>` / `just check <file>`
  (equivalente manual: `gcc -Wall -Wextra -Werror -pedantic -g -fsanitize=address,undefined <archivo>.c -o <bin>`)

## Diagnóstico guiado de bugs (code-diagnostic)
Nunca reescribir ni parchar el código del alumno. Guiarlo con, en este orden:
1. AddressSanitizer (heap/stack buffer overflow, use-after-free).
2. `gdb` (`b main`, `run`, `bt`, `watch`).
3. `strace` para inspeccionar llamadas al kernel.

## Convención de comentarios de aprendizaje
```c
/* APRENDÍ: ... */
/* DUDA RESUELTA: ... */
/* CONECTA CON: [[MOC - ...]] */
```

## Verdades incondicionales base del tema
- Toda variable en C es una dirección de memoria y un tamaño en bytes.
- Todo acceso a hardware en Linux pasa por una syscall.

## Clasificación por defecto de sub-conceptos nuevos
- `vocabulario`: sintaxis, tipos, nombres de funciones de la stdlib.
- `mecanismo`: gestión de memoria, punteros, preprocesador, multifile.

## Verificación externa
requiere_researcher: false
