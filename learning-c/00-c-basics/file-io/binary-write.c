#include <stdio.h>

int main(void)
{
    FILE *fp;
    unsigned char bytes[6] = {5, 37, 0, 88, 255, 12};

    fp = fopen("data/output.bin", "wb"); // modo: escritura binario

    // Funcion fwrite(POINTER, SIZE-DATA, COUNT-DATA, FILE):
    // - Puntero a los datos a escribir
    // - Tamano de cada pieza de dato
    // - Recuento de cada pieza de dato
    // - Archivo
    fwrite(bytes, sizeof(char), 6, fp);

    fclose(fp);

    return 0;
}
