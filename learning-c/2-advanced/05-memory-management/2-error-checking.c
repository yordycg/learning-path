#include <stdio.h>
#include <stdlib.h>

/*
 * ERROR CHECKING:
 * - Siempre se recomienda proteger el codigo al gestionar
 *   la memoria.
 * - malloc(): puede retornar 2 escenarios:
 *   - Exito: retornar el puntero void *, apuntando a la memoria.
 *   - Error: retornar un NULL.
 */
int main(void)
{
    int *x;
    x = malloc(sizeof(int) * 10);

    if (x == NULL) {
        printf("ERROR: allocating 10 ints\n");
        // do something here to handle it...
    }

    free(x);

    /*
     * SHORT VERSION:
     *
     * int *num;
     * if ((num = malloc(sizeof(int) * 10)) == NULL){
     *    // do something...
     * }
     *
     */

    return 0;
}
