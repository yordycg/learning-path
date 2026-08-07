#include <stdio.h>
#include <string.h>

/*
 * VOID POINTERS
 * - Tener un puntero del que no sabemos el tipo, es util en algunos casos:
 *   - Una funcion que opera byte a byte, iteramos sobre los bytes de un
 *     objeto sin importar el tipo del objeto, por ejemplo: memcpy().
 *   - Una funcion recibe datos de otra funcion (como callback), tu sabes que
 *     datos retorna la 1era funcion, pero la que lo recibe no, ahi esta su uso.
 *   - Con void * no conocemos el tamano del tipo apuntado.
 *   - memcpy():
 *   - Limites:
 *     - No se puede hacer aritmetica sobre un void *
 *     - No se puede desreferenciar un void *
 *     - No se puede usar el operador arrow (igual es una desreferencia)
 *     - No se puede usar notacion array en un void *
 */

// Mi propio - memcpy()
void *my_memcpy(void *dest, void *src, int byte_count);

int main(void)
{
    // Ejemplo con memcpy()
    //
    char s[] = "Goats!";
    char t[100];

    // t -> 1er param, donde se copia dato.
    // s -> 2do param, desde el lugar que se copia.
    // 7 -> 3er param, indicar los bytes a copiar.
    // NOTA: para copiar string es mejor usar 'strcpy()'.
    memcpy(t, s, 7); // copia 7 bytes, incluyendo el caracter nulo

    printf("%s\n", t); // output: Goats!

    return 0;
}

/*
 * my_memcpy(dest, src, byte_count);
 * -
 */
void *my_memcpy(void *dest, void *src, int byte_count)
{
    // Convertir void*s en char*s
    char *s = src, *d = dest;

    // Mientras byte_count no sea 0... desreferenciar y copiar
    while (byte_count--) {
        *d++ = *s++;
    }

    // Retornamos el destino
    return dest;
}
