/*
 * Lista de compras:
 *
 * Pedir al usuario cuantos articulos quiere,
 * reservar memoria con malloc, pides cada nombre
 * con scanf, los muestras, y free.
 *
 * Pseudocodigo:
 *
 * MAIN:
 *  PRINT "Cuantos articulos debes comprar?"
 *  READ count como entero.
 *
 *  ALLOCATE items[count];
 *  IF items == NULL THEN
 *      PRINT "ERROR: no hay memoria"
 *      RETURN 1
 *  END IF
 *
 *  FOR i=0 TO count - 1:
 *      PRINT "Nombre del articulo:"
 *      READ items[i]
 *  END FOR
 *
 *  PRINT "Tu lista es:"
 *  FOR i=0 TO count-1:
 *      PRINT items[i]
 *  END FOR
 *
 *  DEALLOCATE items
 *  RETURN 0
 * END MAIN
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // 1.- Solicitar cantidad de articulos:
    printf("Cuantos articulos debes comprar?\n");
    // buffer[5]: si el usuario escribe "1000", fgets solo
    // lee "100" y el resto queda colgado en el buffer de
    // entrada (detalle conocido).
    char buffer[5];
    int count;
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        // Escanear el buffer para buscar un entero (%d)
        // y luego almacenarlo en 'count'
        //
        // Si sscanf falla, 'count' quedaria con basura
        // (sin valor definido). Salimos antes de usarlo
        // en los bucles de abajo.
        if (!(sscanf(buffer, "%d", &count) == 1)) {
            printf("ERROR: Por favor, introducir un numero valido!");
            return 1;
        }
    }

    // 2.- Asignar memoria dinamica para el array de strings.
    //
    // NOTE: reservamos SOLO los punteros (count * sizeof *tems).
    // Los strings de cada articulo se reservan por separado,
    // dentro del bucle.
    char **items = malloc(count * sizeof *items);
    if (items == NULL) {
        printf("ERROR: No hay memoria");
        return 1;
    }
    // Pedir el nombre de n articulos:
    for (int i = 0; i < count; i++) {
        printf("Nombre del articulo %d: \n", i + 1);
        char tmp[64];

        if (fgets(tmp, sizeof tmp, stdin) != NULL) {
            size_t r_size = strlen(tmp);

            // Limpieza del caracter newline (\n):
            //
            // fgets deja el '<ENTER>' al final ("pan\n"); lo
            // reemplazamos por \0 para que el string mida
            // exacto (r_size--) y no haya \n en la lista.
            // OJO: si el nombre supera 63 chars, fgets corta
            // y NO hay \n que quitar.
            if (tmp[r_size - 1] == '\n')
                tmp[--r_size] = '\0';

            items[i] = malloc(r_size + 1);

            strcpy(items[i], tmp);
        } else {
            printf("ERROR: No se pudo almacenar el articulo.");
            return 1;
        }
    }

    // 3.- Mostrar lista de todos los articulos:
    printf("Tu lista de compras es:\n");
    for (int i = 0; i < count; i++) {
        printf("\t* %d.- %s\n", (i + 1), items[i]);
    }

    // 4.- Limpiar memoria (dos niveles => dos pasadas):
    // 1) Libera cada string (items[i]) ANTES de items,
    //    o perderiamos las direcciones de los articulos.
    // 2) Libera el array de punteros.
    for (int i = 0; i < count; i++)
        free(items[i]); // limpiar cada elemento del array

    free(items); // limpiar array

    return 0;
}
