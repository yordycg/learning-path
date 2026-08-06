#include <stdio.h>

/*
 * WRITE TEXT FILE
 * - Tenemos funcion especificas con diferentes caracteristicas para
 *   escribir un archivo de texto:
 *   - 'fputc': Escribir un caracter.
 *   - 'fprintf': Escribir y poder concatenar/formatear variables.
 *   - 'fputs': Escribir strings.
 */
int main(void)
{
    FILE *fp;
    int my_age = 31;

    fp = fopen("data/output.txt", "w"); // indicar modo escritura
    // archivo se sobreescribe con 0 bytes
    // En lugar de usar fopen(), si usamos stdout, en lugar
    // de escribir un archivo, sale por la consola!
    // fp = stdout;

    fputc('Y', fp); // escribir caracter
    fputc('\n', fp);

    // Escribir usando funcion fprintf():
    // fprintf(<FILE>, <STRING>);
    fprintf(fp, "Mi edad es: %d\n", my_age);

    fputs("Hello, world!\n", fp);
    fputs("Bye!\n", fp);

    fclose(fp);

    return 0;
}
