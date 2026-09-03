/*
 * @title: Execvp and PATH Resolution
 * @phase: learning-c - week 3, day 4
 * @zettel: Linux - execvp and PATH Lookup.md
 * ----------------------------------
 * @learn:
 * - execvp vs execv:
 *   - execvp: funcion que realiza una busqueda en el PATH en busqueda
 *     del programa/comando.
 *   - execv: esta funcion NO realiza una busqueda profunda, lo que
 *     le pasamos como 1er arg lo trata como un path.
 *
 * @new_questions:
 * - Que hace por detras execvp, especificamente la
 *   forma/grupo 'p', para buscar los programas?
 *   R// La forma 'p' hace una busqueda en el PATH por alguna coincidencia
 *       por el programa/comando pasado como argumento.
 *
 * @connect_with:
 * - Process / fork / WIFEXITED / WEXITSTATUS.
 */
#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        return 1;
    }
    if (child_pid == 0) { /* Proceso hijo... */
        /*
         * @modo: Test 1 - Comando erroneo.
        char *args[] = {"NO_EXISTE", "-la", NULL};

        if (execvp(args[0], args) == -1) {
            perror("[ERROR execvp]");
            // _exit(127); convencion: 127 = 'comando no encontrado'
            return 1;
        }
        */
        /*
         * @modo: Test 2 - Uso funcion execv:
         * - Ahora no usaremos el grupo/forma 'p',
         *   veremos que retorna.
         */
        // char *args[] = {"ls", "-la", NULL};
        char *args[] = {"/usr/bin/ls", "-la", NULL};

        if (execv(args[0], args) == -1) {
            perror("[ERROR execv]");
            return 1;
        }
    } else { /* Proceso padre... */
        int status;
        wait(&status);

        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        }
    }

    return 0;
}
