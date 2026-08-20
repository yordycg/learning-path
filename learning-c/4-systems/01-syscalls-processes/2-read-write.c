/*
 * Ejercicio:
 * Copiar input terminal/keyword a un archivo usando read/write.
 *
 * Pseudocodigo:
 *
 * DEFINE file_path = "path";
 * DEFINE file_open = OPEN(file_path, w-only);
 * DEFINE n;
 * DEFINE buf[n];
 * DEFINE size_read_input;
 * // 0 == user input == terminal/keyword
 * WHILE((size_read_input = READ(0, buf, n)) > 0) THEN
 *  DEFINE size_earrings = size_read_input;
 *  DEFINE write_ptr = buf;
 *
 *  WHILE(size_earrings > 0) THEN
 *      DEFINE written = WRITE(file_open, write_ptr, size_earrings)
 *      IF written == -1 THEN
 *          ERROR;
 *      size_earrings -= written;
 *      write_ptr += written;
 *
 * CLOSE(file_open);
 *
 */
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
    char *file_path = "data/data.txt";
    int file_open = open(file_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (file_open == -1) {
        printf("[ERROR] No se pudo abrir el archivo.");
        return -1;
    }

    ssize_t size_read_input;
    size_t n = 1024;
    char buf[n];

    while ((size_read_input = read(0, buf, n)) > 0) {
        ssize_t size_earrings = size_read_input;
        char *write_ptr = buf;

        while (size_earrings > 0) {
            ssize_t written = write(file_open, write_ptr, size_earrings);
            if (written == -1) {
                printf("[ERROR] No se puede escribir en el archivo abierto.");
                return -1;
            }

            size_earrings -= written;
            write_ptr += written;
        }
    }

    int result_close;
    if ((result_close = close(file_open)) == -1) {
        printf("[ERROR] No se puede cerrar el archivo abierto.");
        return -1;
    }

    return 0;
}
