/*
 * Practica Basica:
 * - Abrir un archivo en modo lectura, mostrar en cli
 * y luego cerrar.
 * - Usar obligatoriamante: open, close
 *
 * Pseudocodigo:
 *
 * OPEN_FILE file.txt read-mode;
 * // Verificar posible error
 *
 * WHILE (READ_FILE > 0)
 *      SHOW line
 *
 * CLOSE_FILE file.txt
 *
 */
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main(void)
{
    int size_buf = 1024;
    char buf[size_buf];
    int file, line;

    if ((file = open("data/data.txt", O_RDONLY)) == -1) {
        printf("ERROR: No se pudo abrir el archivo, existe?");
        return 1;
    }

    while ((line = read(file, buf, size_buf)) > 0)
        printf("%s", buf);

    if (close(file) == -1) {
        printf("ERROR: No se pudo cerrar el archivo");
        return -1;
    }
    return 0;
}
