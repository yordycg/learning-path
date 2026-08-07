#include <stdio.h>

/*
 * POINTERS & ARRAYS
 * - Cuando apuntamos a un array, por detras estamos
 *   haciendo referencia al 1er elemento del array.
 */

int main(void)
{
    int array[5] = {11, 22, 33, 44, 55};
    int *ptr_array = NULL;

    // Esto...
    ptr_array = array;
    // Es esto, por detras!
    ptr_array = &array[0];

    printf("Valor 'ptr_array': %d\n", *ptr_array);
    printf("Direccion 'ptr_array': %p\n", ptr_array);

    printf("--- Equivalencia Array/Pointers ---");
    /*
     * expresion1[expresion2] == *((expresion1) + (expresion2))
     * a[b] == *((a) + (b))
     *
     * - El extra parentesis, es para forzar el orden en expresiones
     *   matematicas complejas!
     */
    int array2[] = {11, 22, 33, 44, 55};
    int *ptr_array2 = array2;

    // DIFERENCIAS NOTACIONES:
    for (int i = 0; i < 5; i++)
        printf("%d\n", array2[i]); // notacion array con array2

    for (int i = 0; i < 5; i++)
        printf("%d\n", ptr_array2[i]); // notacion array con ptr_array2

    for (int i = 0; i < 5; i++)
        printf("%d\n", *(array2 + i)); // notacion puntero con array2

    for (int i = 0; i < 5; i++)
        printf("%d\n", *(ptr_array2 + i)); // notacion puntero con ptr_array2

    for (int i = 0; i < 5; i++)
        printf("%d\n", *(ptr_array2++)); // puntero movil ptr_array2
    // printf("%d\n", *(array2++));  // Moviendo variable array2

    /*
     * EQUIVALENCIA en FUNCTIONS CALLS:
     *
     * - Funcion con arg/param puntero:
     *   int my_strlen(char *s);
     *
     * - Pasar array y puntero:
     *   char s[] = "Hola";
     *   char *t = "Adios";
     *
     *   my_strlen(s);  // funciona
     *   my_strlen(t);  // funciona igual!
     *
     * - Esto igual es equivalente:
     *   int my_strlen(char *s); // RECOMENDADO!
     *   int my_strlen(char s[]);
     *
     */

    return 0;
}
