/*
 * EJERCICIO:
 * Redireccionar la salida stdout a un archivo txt.
 *
 * Patron:
 * open() -> dup2() -> close()
 *
 * Pseudocodigo:
 *
 * DEFINE output_file_name como string;
 * DEFINE fd como int; // donde se almacena el archivo abierto
 *
 * Abrir archivo: fd = OPEN(output_file_name, FLAGS);
 *
 * Redireccionar STDOUT (fd = 1) al nuevo archivo
 * dup2(fd, STDOUT);
 *
 * Cerrar fd abierto: CLOSE(fd);
 *
 * PRINT "..."; // mensaje a almacenar en el archivo
 *
 */
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

#define STDOUT 1

int main(void)
{
    int fd;
    char *output_file_name = "data/redirect-with-dup2.txt";

    fd = open(output_file_name, O_CREAT | O_TRUNC | O_WRONLY, /* create | trunc | only write to */
              S_IRUSR | S_IWUSR); /* user can read and write, if newly created */
    if (fd < 0) {
        printf("[ERROR] Al abrir el archivo.\n");
        return 1;
    }

    printf("Imprimir en STDOUT ANTES de hacer la redireccion!\n");
    dup2(fd, STDOUT);

    close(fd); // cerrar fd original

    printf("IMPRIMIENDO STDOUT DESPUES del dup2... esto esta en el archivo .txt!!\n");

    return 0;
}
