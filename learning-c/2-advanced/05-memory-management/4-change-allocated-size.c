#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * CHANGING ALLOCATED SIZE:
 * -
 */
int main(void)
{
    // Asignar memoria para un array float de 20 elementos:
    float *ptr_f = NULL;
    if ((ptr_f = malloc(20 * sizeof(float))) == NULL) {
        printf("ERROR: al asignar memoria\n");
        return 1;
    }

    // Settear a 0, todos los elementos:
    memset(ptr_f, 0, 20 * sizeof(float));

    // NOTA: necesitamos cambiar a un array de 40 elementos:
    // Usamos realloc(<NEW-PTR>, <NEW-SIZE-BYTES>);
    float *new_ptr_f = realloc(ptr_f, 40 * sizeof *ptr_f);

    // Proteccion/Comprobacion que la reasignacion sea correcta:
    if (new_ptr_f == NULL) {
        printf("ERROR: al reasignar la memoria\n");
        return 1;
    }

    // Con la proteccion hecha, ahora podemos volver
    // a utilizar el mismo puntero:
    ptr_f = new_ptr_f;

    // Dar valores:
    for (int i = 0; i < 40; i++)
        ptr_f[i] = 1.0 + i;

    // Mostrar valores:
    for (int i = 0; i < 40; i++)
        printf("%.1f\n", ptr_f[i]);

    // Liberar memoria:
    // - Porque no necesitamos liberar 'new_ptr_f'?
    free(ptr_f);

    return 0;
}
