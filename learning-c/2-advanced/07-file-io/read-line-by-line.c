#include <stdio.h>

/*
 * READ LINE BY LINE
 * - 'char s[1024]' (1param - fgets): es el tamano maximo de caracteres
 *   POR LINEA que el programa puede leer en una sola iteracion.
 *
 * - fgets(1param, 2param, 3param):
 *   - Funcion que lee el flujo de un texto "linea por linea".
 *   - 1param - Puntero destino: es la direccion en memoria donde se
 *     almacenaran  temporalmente los caracteres leidos del archivo.
 *   - 2param - Tamano limite: indica el numero maximo de caracteres
 *     que fgets() tiene permitido escribir en el array/direccion de memoria.
 *     - fgets() lee de forma segura <size_array-1> y reserva el ultimo byte
 *       para el caracter nulo (\0), asi el resultado es tratado como string en C.
 *   - 3param - Archivo/Flujo: puntero de tipo FILE * que representa el archivo
 *     abierto anteriormente.
 *   - Al finalizar retorna el caracter EOF.
 *   - Al fallar retorna NULL.
 */
int main(void)
{
    FILE *fp;
    char s[1024]; // grande para cualquier linea que encuentre el programa
    int linecount = 0;

    fp = fopen("data/quote.txt", "r");

    // fgets(puntero_destino, tamano_limite, archivo/stream)
    while (fgets(s, sizeof s, fp) != NULL)
        printf("%d: %s", ++linecount, s);

    fclose(fp);

    return 0;
}
