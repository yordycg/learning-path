#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Leer una linea de tamano arbitrario de un fichero:
 *
 * Devuelve un puntero a la linea.
 * Devuelve NULL en EOF o error.
 *
 * Es responsabilidad del que llama free() este
 * puntero cuando termine de usarlo.
 *
 * Tenga en cuenta que esto elimina la nueva linea
 * del resultado. Si necesita de el, probablemente
 * sea mejor cambiar esto, a un do-while.
 */
char *readline(FILE *fp)
{
    int offset = 0;  // indice del siguiente char en el buffer
    int bufsize = 4; // preferiblemente con un tamano inicial
                     // que sea potencia de 2
    char *buf;       // el buffer
    int c;           //  caracter que hemos leido

    // 1.- Asignar bufer inicial:
    buf = malloc(bufsize);

    // 1.2.- Comprobacion de errores:
    if (buf == NULL)
        return NULL;

    // 2.- Loop principal - leer hasta nueva linea o EOF
    //
    // Truco "operador coma":
    // Operador coma permite encadenar expresiones, se evalua
    // de izquiera a derecha y el resultado de toda la expresion
    // es unicamente el ULTIMO VALOR.
    //
    // 1.- Primero ejecuta 'c = fgetc(fp)', donde lee un caracter
    // y lo almacena en 'c'.
    // 2.- Luego evalua `c != '\n' && c != EOF`, es un salto de linea
    // o el fin del archivo?
    //
    // El bucle while decide si continua basandose unicamente en la
    // ultima condicion.
    while (c = fgetc(fp), c != '\n' && c != EOF) {
        // Comprobar si nos hemos quedado sin espacio en
        // el buffer contabilidad por el byte extra para
        // el terminador NULL
        //
        // "Acordeon" de  memoria (realloc dinamico)
        // Como no sabemos cuanto mide la linea que vamos a leer, la
        // estrategia es empezar con un presupuesto diminuto (bufsize = 4)
        // e ir duplicando conforme se necesite.
        //
        // - `offset == bufsize -1`: Nos detenemos un byte antes del limite
        // para asegurarnos que siempre quede un ESPACIO LIBRE para el
        // caracter terminador nulo (\0).
        // - `bufsize *= 2`: Si nos quedamos sin espacio, duplicamos el
        // tamano del buffer (de 4 a 8, luego 16, 32, etc...). Esta tecnica
        // se llama 'chunking' (o sobreasignacion), muy eficiente porque
        // reduce la cantidad de veces que tenemos que pedirle memoria
        // al SO.
        // - `realloc(buf, bufsize)`: Le pedimos al SO que agrande el
        // bloque de memoria actual (buf). Si hay espacio contiguo lo
        // agranda alli mismo, si no busca un nuevo espacio mas grande
        // en el heap, copia los datos viejos (automaticamente), libera
        // la memoria vieja y devuelve la nueva direccion (puntero).
        if (offset == bufsize - 1) { // -1 para el terminador NULL
            bufsize *= 2;            // 2x el espacio

            // Regla: puntero temporal
            // Si solo hacemos `buf = realloc(...)`:
            // - El sistema se queda sin memoria, fallara y devolvera NULL.
            // - Se hubiera sobrescrito la variable, hubieramos perdido
            // la direccion en memoria original, el bloque quedaria
            // huerfano causando una FUGA DE MEMORIA (memory leak)
            //
            // Usar `new_buf` es un escudo de seguridad, si falla liberamos
            // de forma segura la memoria vieja con `free(buf)`.
            char *new_buf = realloc(buf, bufsize);

            if (new_buf == NULL) {
                free(buf); // En caso de error, liberar y abortar
                return NULL;
            }

            buf = new_buf; // reasignacion correcta
        }

        buf[offset++] = c; // agregar el byte al buffer
    }

    // 3.- Llegamos a la nueva linea o a EOF:
    // Si es EOF y no leemos bytes, liberamos el buffer y
    // devuelve NULL para indicar que estamos en EOF
    if (c == EOF && offset == 0) {
        free(buf);
        return NULL;
    }

    // 4.-  Ajustar ("Shrink to Fit")
    //
    // Al terminal el loop lo mas seguro es que no hara sobrado
    // espacio, aqui hacemos un "encogimiento": llamamos a realloc
    // para reducir el bloque de memoria exacto de la cadena leida
    // mas uno (offset + 1) para el caracter nulo.
    // Asi devolvemos el espacio que no usamos para que otros
    // programas o partes de nuestro codigo puedan aprovecharlo.
    if (offset < bufsize - 1) {                   // si nos falta para el final
        char *new_buf = realloc(buf, offset + 1); // +1 por terminacion NULL

        // Si tiene exito, apunta a buf a new_buf;
        // de lo contrario dejaremos buf donde esta
        if (new_buf != NULL)
            buf = new_buf;
    }

    // 5.- Agregar el terminador NULl
    buf[offset] = '\0';

    return buf;
}

int main(void)
{
    FILE *fp = fopen("foo.txt", "r");

    if (fp == NULL) {
        printf("ERROR: no se pudo abrir 'foo.txt'\n");
        return 1;
    }

    char *line;

    while ((line = readline(fp)) != NULL) {
        printf("%s\n", line);

        // Como en `main` hacemos uso de `readline`
        // que usan malloc o realloc, es responsabilidad
        // de `main` liberar esa memoria
        free(line);
    }

    fclose(fp);

    return 0;
}
