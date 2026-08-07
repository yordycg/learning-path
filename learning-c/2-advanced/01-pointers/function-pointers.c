#include <stdio.h>

/*
 * POINTERS & FUNCTIONS
 * - Al definir un parametro como puntero, los datos
 *   que se le pasen a la funcion van a ser modificados
 *   desde dentro de la misma funcion.
 * - Beneficio: ya no se hace una copia local en el stack
 *   del dato que le pasamos a la funcion, por lo que no
 *   ocupamos recursos en eso, haciendo el programa mas
 *   eficiente.
 */

void increment(int *ptr_int);

int main(void)
{
    /* Incrementar valor usando punteros y una funcion */
    int value = 10;
    int *ptr_value = NULL;

    ptr_value = &value;

    printf("Valor ANTES: %d\n", value);

    increment(ptr_value); // incrementar en 1
    // Simplificar con: increment(&value);

    printf("Valor DESPUES: %d\n", value);

    return 0;
}

void increment(int *ptr_int) { *ptr_int += 1; }
