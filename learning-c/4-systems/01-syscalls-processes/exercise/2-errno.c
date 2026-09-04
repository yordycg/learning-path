/*
 * EJERCICIO - errno n3:
 * Simula la rama de error del shell:
 * intenta ejecutar un comando inexistente y
 * reporta de forma legible qué binario no se
 * encontró (usando strerror/errno).
 */
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("[ERROR]");
        exit(EXIT_FAILURE);
    }
    if (child_pid == 0) {
        char *args[] = {"ERROR", "-ls", NULL};

        if (execvp(args[0], args) == -1) {
            printf("[ERROR]: Binario no encontrado: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
    } else {
        int status;
        wait(&status);
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
