# Justfile — Learning Path Cockpit (C, Systems & Inverted PBL)
# Automatización ergonómica para el desarrollador y agentes de IA.

set shell := ["bash", "-uc"]

default:
    @just --list

# Muestra el panel operativo actual de la fase activa
status:
    @head -n 50 learning-c/status.md

# Compila y ejecuta un archivo C con AddressSanitizer y UndefinedBehaviorSanitizer
run FILE:
    #!/usr/bin/env bash
    set -euo pipefail
    FILE="{{FILE}}"
    if [ ! -f "$FILE" ]; then
        echo "Error: archivo '$FILE' no encontrado."
        exit 1
    fi
    mkdir -p build
    case "$FILE" in
        *.c)
            echo "==> Compilando C con ASan + UBSan..."
            gcc -Wall -Wextra -Werror -pedantic -g -fsanitize=address,undefined "$FILE" -o build/out
            echo "==> Ejecutando build/out..."
            ./build/out
            ;;
        *.go)
            go run -race "$FILE"
            ;;
        *.py)
            python3 "$FILE"
            ;;
        *)
            echo "Extensión no soportada por runner: $FILE"
            exit 1
            ;;
    esac

# Ejecuta el archivo y reporta el código de retorno exacto ($?)
test FILE:
    #!/usr/bin/env bash
    set -euo pipefail
    FILE="{{FILE}}"
    echo "==> Testeando $FILE..."
    just run "$FILE"
    RET=$?
    echo "==> Código de retorno (exit code): $RET"
    exit $RET

# Comprueba la sintaxis en modo rápido sin enlazar binario
check FILE:
    @gcc -fsyntax-only -Wall -Wextra -Werror -pedantic {{FILE}}
    @echo "✓ Sintaxis correcta en {{FILE}}"

# Compila el proyecto semanal mysh
mysh:
    @make -C projects/mysh

# Limpia los binarios y artefactos de compilación
clean:
    @rm -rf build/ *.out
    @if [ -d projects/mysh ]; then make -C projects/mysh clean 2>/dev/null || true; fi
    @echo "✓ Artefactos de compilación eliminados."
