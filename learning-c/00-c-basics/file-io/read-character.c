#include <stdio.h>

/*
 * READ A FILE
 * - FILE *: tipo para almacenar archivo.
 * - fopen(<path>, <type>): abrir archivo indicando su ruta,
 *   e indicando el estado (solo lectura, ...)
 * - fgetc(<file>): obtener caracter.
 * - fclose(<file>): cerrar archivo cuand no se use.
 */

int main(void)
{
    FILE *fp; // variable que representa el archivo abierto...

    fp = fopen("data/hello.txt", "r"); // archivo abierto para lectura

    int c = fgetc(fp); // obtener 1 caracter
    printf("%c\n", c);

    fclose(fp); // cerrar archivo cuando no lo ocupemos

    return 0;
}
