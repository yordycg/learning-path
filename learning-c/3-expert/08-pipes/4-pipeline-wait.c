/* ============================================================
* @title    Waiting on a Pipeline (N hijos)
* @phase    Phase 1 (learning-c) · S5 · Kata 4
* -------------------------------------------------------------
* @learn
*   - N procesos necesitan N-1 pipes: cada pipe une la salida de una
*   etapa con la entrada de la siguiente.
*   - pipe() se crea en el PADRE antes del fork; el hijo solo HEREDA
*   los extremos. Un pipe creado dentro del hijo es privado y ningun
*   hermano puede alcanzarlo.
*   - prev_read arrastra el read-end del pipe anterior entre vueltas
*   del loop: el hijo i lee de prev_read y escribe al pipe nuevo.
*   - El padre cierra en cada vuelta lo que no usa: el write-end que
*   pasa al hijo y el read-end viejo ya consumido. Sin esos closes,
*   el EOF nunca llega y el pipeline se cuelga.
*   - Se reapizan los N hijos con waitpid(-1, ...) en bucle, pero el
*   status SOLO se guarda cuando pid == last_child: asi el $? es el de
*   la ultima etapa aunque los hijos mueran en cualquier orden.
*
* @open_questions
*   - Por que el padre debe cerrar el read-end viejo (prev_read)
*   DESPUES de forkear al siguiente hijo y no antes?
*   - Que pasa con el EOF si el padre no cierra el write-end del pipe
*   que acaba de crear?
*   - Por que waitpid(0) y waitpid(-1) se comportan distinto al esperar
*   varios hijos?
*   - Si una etapa intermedia muere primero, por que el gate
*   pid == last_child evita pisar el status final?
*
* @connect_with
*   - MOC - Processes
*   - Linux - Waiting on a Pipeline
*   - File Descriptors - Linux
============================================================ */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    /*
     * Flujo:
     * 1 hijo:
     *  - envia: ls -la
     * 2 hijo:
     *  - recibe: anterior
     *  - envia: grep .c
     * 3er hijo:
     *  - recibe: anterior
     *  - envia: wc -l
     */
    int status = 0;
    int prev_read;
    int childs = 3;
    int last_child = -1;
    for (int i = 0; i < childs; i++) {

        int fd[2];
        /* Solo crear 2 pipe */
        if (i < childs - 1) {
            if (pipe(fd) == -1) {
                perror("[ERROR PIPE()]");
                exit(EXIT_FAILURE);
            }
        }

        pid_t child_pid = fork();

        switch (child_pid) {
        case -1:
            perror("[ERROR FORK()]");
            exit(EXIT_FAILURE);
        case 0:
            if (i == 0) { /* Primer hijo... */
                dup2(fd[1], STDOUT_FILENO);
                close(fd[0]);
                close(fd[1]);

                char *args[] = {"ls", "-la", NULL};
                if (execvp(args[0], args) == -1) {
                    perror("[ERROR EXECVP()]");
                    _exit(EXIT_FAILURE);
                }
            } else if (i == 1) { /* Segundo hijo... */
                dup2(prev_read, STDIN_FILENO);
                dup2(fd[1], STDOUT_FILENO);
                close(prev_read);
                close(fd[0]);
                close(fd[1]);

                char *args[] = {"grep", ".c", NULL};
                if (execvp(args[0], args) == -1) {
                    perror("[ERROR EXECVP()]");
                    _exit(EXIT_FAILURE);
                }
            } else if (i == 2) { /* 3er hijo... */
                dup2(prev_read, STDIN_FILENO);
                close(prev_read);

                char *args[] = {"wc", "-l", NULL};
                if (execvp(args[0], args) == -1) {
                    perror("[ERROR EXECVP()]");
                    _exit(EXIT_FAILURE);
                }
            }

            break;
        default: /* Padre... */
            if (i == 0) {
                prev_read = fd[0];
                close(fd[1]);
            } else if (i == 1) {
                close(prev_read);
                prev_read = fd[0];
                close(fd[1]);
            } else {
                last_child = child_pid;
                close(prev_read);
            }
        }
    }

    int wstatus;
    pid_t pid;
    while ((pid = waitpid(-1, &wstatus, 0)) > 0) {
        if (pid == last_child) {
            if (WIFEXITED(wstatus)) {
                status = WEXITSTATUS(wstatus);
            }
            if (WIFSIGNALED(wstatus)) {
                status = (int)128 + WTERMSIG(wstatus);
            }
        }
    }

    exit(status);
}
