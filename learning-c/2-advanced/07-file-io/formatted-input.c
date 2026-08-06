#include <stdio.h>

/*
 * FORMATTED INPUT
 *
 * - fscanf():
 *   - Lee datos con formto de un stream, analiza los caracteres del stream,
 *     los compara con un patron (nosotros los indicamos) y CONVIERTE el texto
 *     en los tipos correspondientes (enteros, flotantes, etc).
 *   - File - Puntero al archivo: Indicar de que archivo (abierto) se leeran
 *     los caracteres.
 *   - String Format: Indicamos el patron de los datos que se esperan encontrar.
 *     - %s: Lee un string.
 *     - %f: Lee un float.
 *     - etc...
 *   - Storage Destinations: Indicar la lista de direccon de memoria (punteros)
 *     que apuntan a las variables donde se guardaran los resultados obtenidos.
 *
 */
int main(void)
{
    FILE *fp;
    char name[1024]; // suficientemente grande para cualquier linea...
    float length;
    int mass;

    fp = fopen("data/whales.txt", "r");

    // fscanf(<FILE>, <STRING-FORMAT>, <STORAGE-DESTINATIONS>)
    // fp -> archivo abierto.
    // "%s %f %d" -> patron de los datos que esperamos encontrar.
    // name, &length, &mass -> punteros donde guardar los datos obtenidos.
    //
    // * name es un array de 'char', los array son tratados como punteros en C
    // por eso no es necesario pasar su direccion de memoria, como las
    // otra variables!
    while (fscanf(fp, "%s %f %d", name, &length, &mass) != EOF)
        printf("%s whale, %d tonnes, %.1f meters\n", name, mass, length);

    fclose(fp);

    return 0;
}
