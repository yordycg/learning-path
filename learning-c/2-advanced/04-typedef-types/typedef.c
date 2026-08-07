#include <stdio.h>

/*
 * TYPEDEF
 * - Forma de dar un alias a un tipo especifico.
 * - Beej's no recomieda su uso, en casos especificos mejora
 *   la claridad del codigo, en la mayoria de caso es lo contrario!
 * - Es aplicable en arrya, pointers, basic types, etc.
 */
int main(void)
{
    // CASO MAS USADO: typedef & struct
    // Sintaxis 1 - Normal
    struct animal {
        char *name;
        int leg_count, speed;
    };

    //     |name-original| |new-name|
    // typedef struct animal animal;

    // struct animal y; // funciona
    // animal z;        // funciona igual!

    // Sintaxis 2 - Simplificada
    // typedef struct animal2 {
    //     char *name;
    //     int leg_count, speed;
    // } animal2;

    // animal2 gato;

    // Sintaxis 3 - Simplificada - Struct Anonimas
    typedef struct {
        char *name;
        int leg_count, speed;
    } animal3;

    animal3 perro = {.name = "Fenrir"};

    printf("Animal Name: %s\n", perro.name);

    // CASO: typedef & Others Types
    // Cuando en una app tenemos muchas/millones de uso de una variable
    // con un tipo especifico, podriamos cambiarla en un solo lugar...
    // typedef float app_float;
    // typedef long double app_float; // renombrar en un solo lugar

    // app_float f1, f2, f3; // nunca se modifica

    return 0;
}
