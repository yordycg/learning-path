/*
 * FD:
 * - Tabla FDs:
 *   - 0 = STDIN (terminal input/keyboard).
 *   - 1 = STDOUT (terminal screen ).
 *   - 2 = STDERR (Terminal screen for errors).
 * - open()
 *
 * - Input/Ouput: Cada llamada retorna un recuento de bytes que es el numero
 *   de los bytes transferidos.
 *   - fd -> File Descriptor.
 *   - buf -> Buffer: donde vendran o iran los datos.
 *   - n -> numero de bytes a transferir.
 *      - n = 1 = un caracter a la vez ("unbuffered").
 *      - n = 512 = corresponde un bloque fisico con muchos dispositivos perifericos.
 *
 *   - write(fd, buf, n): Retorna el el numero de bytes escritors.
 *      - n bytes != return n bytes -> ERROR.
 *   - read(fd, buf, n): Puede retornar un numero menor a los bytes solicitados, depende
 *     del contenido a leer.
 *      - Retornar 0 == EOF.
 *      - Retornar -1 == ERROR.
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
        /* fd 1 = STDOUT = Terminal Screen */
        write(1, buf, line);

    if (close(file) == -1) {
        printf("ERROR: No se pudo cerrar el archivo");
        return -1;
    }
    return 0;
}
