#include <stdio.h>

/*
 * EOF: Caracter especial que indica el FIN de un archivo.
 *
 * - Al momento de definir la variable que almacenara los caracteres
 *   la definimos como 'int', es porque en algun momento igual
 *   almacenara a EOF, y al ser EOF mayor a un tipo 'char', dara un
 *   error.
 */
int main(void)
{
    const char *file_path = "data/hello.txt";
    FILE *fp;
    int c;

    fp = fopen(file_path, "r");

    // Mientras c sea diferente a EOF, imprimir c...
    while ((c = fgetc(fp)) != EOF)
        printf("%c", c);

    fclose(fp);

    return 0;
}
