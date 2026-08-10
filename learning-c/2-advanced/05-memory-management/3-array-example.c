#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{

    // Asignar espacio para 10 ints <-> array de 10 ints
    int *array_int = malloc(sizeof(int) * 10);

    // Proteccion
    if (array_int == NULL)
        return 1;

    // Limpiar memoria asignada - memset():
    // memset(&POINTER, NEW-VALUE, ELEMENTS);
    // PD: incluir libreria <string.h>
    memset(array_int, 0, 10 * sizeof(int)); // pone en 0

    // Asignar espacio para 10 ints, inicializados en 0:
    // calloc(SIZE/ELEMENTS, TYPE_BYTES);
    // int *array_int = calloc(10, sizeof(int));

    // Asignar valores de 5 en 5 a cada elemento:
    for (int i = 0; i < 10; i++)
        array_int[i] = i * 5;

    // Mostrar array:
    for (int i = 0; i < 10; i++)
        printf("Array[%d] = %d\n", i + 1, array_int[i]);

    // Liberar espacio:
    free(array_int);

    return 0;
}
