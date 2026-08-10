#include <stdio.h>
#include <stdlib.h>

/*
 *
 */
int main(void)
{
    // Asignar espacio para un int
    int *p = malloc(sizeof(int)); // size of puede recibir una
                                  // expresion constante como:
                                  // sizeof *p... variable que
                                  // definimos como int.

    *p = 12; // asignar un valor a guardar en memoria

    printf("Valor de *p: %d\n", *p);

    free(p); // memoria libre...

    // printf("Memoria limpia con free()...");
    // printf("Valor de *p: %d\n", *p);  // ERROR!

    return 0;
}
