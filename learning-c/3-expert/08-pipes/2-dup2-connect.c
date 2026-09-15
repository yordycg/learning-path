/* ============================================================
* @title    Connecting processes with dup2
* @phase    Phase 1 (learning-c) · S5 · Kata 2
* -------------------------------------------------------------
* @learn
*   - dup2(a, b) no copia datos: hace que el fd b pase a apuntar el mismo
*   objeto del kernel que fd a.
*       - fd b se cierra implicitamente si estaba abierto.
*   - Tras dup2, los comandos ejecutados (ls, cat, etc.) no saben que hay
*   un pipe: el comando directamente escribe a STDOUT y ya cae al pipe.
*       - Por eso para los comandos no necesitamos write()/read() porque
*       estos lo usan internamente.
*       - Usar write()/read() solo aparece cuando YO quiero consumir ese
*       output y hacer algo mas con el.
*   - execvp en exito nunca retorna: reemplaza la imagen, mismo PID, nuevo
*   programa. Por eso consumir un "cat" en el padre, EXCLUYE a "waitpid +
*   status".
*
* @open_questions
*
* @connect_with
*   - MOC - Processes
*   - File Descriptors - Linux
*   - Redirection and dup2 - Linux
============================================================ */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    int fd[2];
    if (pipe(fd) == -1) {
        perror("[ERROR PIPE()]");
        exit(EXIT_FAILURE);
    }

    pid_t child_pid = fork();

    switch (child_pid) {
    case -1:
        perror("[ERROR FORK()]");
        exit(EXIT_FAILURE);
    case 0:
        // dup2
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);

        // enviar output al padre
        // usar comando: ls -la
        char *args_child[] = {"ls", "-la", NULL};
        if (execvp(args_child[0], args_child) == -1) {
            perror("[ERROR EXECVP()]");
            _exit(EXIT_FAILURE);
        }
    default:
        // dup2
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        close(fd[1]);

        // consumir output desde el hijo
        // usar comando: cat
        char *args_parent[] = {"cat", NULL};
        if (execvp(args_parent[0], args_parent) == -1) {
            perror("[ERROR EXECVP (PARENT)]");
            exit(EXIT_FAILURE);
        }
    }
}
