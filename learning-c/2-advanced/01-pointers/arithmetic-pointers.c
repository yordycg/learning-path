#include <stdio.h>

void section(char *msj);
int my_strlen(char *s);

int main(void)
{
    section("Adding to Pointers");
    section("Ir al siguiente elemento de un array");
    int arry[5] = {11, 22, 33, 44, 55};
    int *ptr_arry = arry; // int *ptr_arry = &a[0];

    printf("%d\n", *ptr_arry); // output: 11

    // Aritmetica: sumar 1...
    // C conoce que ptr_arry es un tipo int, y tambien conoce los bytes de un int
    // por lo tanto sabe cuantos n bytes debe saltar para llegar al siguiente int.
    printf("%d\n", *(ptr_arry + 1)); // output: 22

    section("Iterando un Array con un puntero");
    for (int i = 0; i < 5; i++)
        printf("%d\n", *(ptr_arry + i)); // *(ptr_arry + i) == arry[i]

    section("Cambio de puntero");
    int arry2[6] = {11, 22, 33, 44, 55, 999};
    int *ptr_arry2 = arry2;

    // Mientras 'valor_puntero' no sea 999... imprimir... ir al siguiente 'valor_puntero'
    while (*ptr_arry2 != 999) {
        printf("%d\n", *ptr_arry2);
        ptr_arry2++;
    }

    section("Subtractig Pointers");
    // Obviamente tiene el mismo fucionamiento que sumar 1, ahora quitamos 1...
    // RECORDAR: solo podemos restar punteros, entre 2 punteros que apunten
    // al mismo array/elemento...

    // Mi propio strlen()
    printf("%d\n", my_strlen("Hello, world!"));

    return 0;
}

void section(char *msj) { printf("\n----- %s -----\n", msj); }

/*
 * Obtener el tamano de un string, al string ser un puntero
 * iremos iterando sobre el string, caracter por caracter...
 * al finalizar le restamos el string, y obtenemos el tamano
 */
int my_strlen(char *s)
{
    char *ptr = s; // escanear desde el inicio

    while (*ptr != '\0')
        ptr++;

    return ptr - s;
}
