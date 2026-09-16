/* ============================================================
* @title    Pipe EOF and closing the write-ends
* @phase    Phase 1 (learning-c) · S5 · Kata 3
* -------------------------------------------------------------
* @learn
*   - Recuerda siempre salir con _exit() desde un child.
*   - fork() -> duplica el descriptor, no el objeto, el hijo
*   hereda una REFERENCIA propia del write-end.
*   - Si no cerramos los fd[n] correspondientes el programa
*   se cuelga. Mientras una sola referencia siga viva, el read
*   bloquea; al cerrarse la ultima, retorna 0.
*
* @open_questions
*   - Que es un VLA?
*   - Porque EOF (read -> 0) el contador del kernel, a los
*   write-ends llega a cero?
*
* @connect_with
*   - MOC - Processes
*   - File Descriptors - Linux
============================================================ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    int status = 0;
    int fd[2];
    int size_buf = 1024;
    char buf[size_buf];

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
        close(fd[1]);

        ssize_t bytes_read;
        while ((bytes_read = read(fd[0], buf, size_buf)) > 0) {
            write(STDOUT_FILENO, buf, bytes_read);
        }

        close(fd[0]);

        _exit(EXIT_SUCCESS);
    default:
        close(fd[0]);

        const char *msg = "\tEnviado desde el padre.\n";
        write(fd[1], msg, strlen(msg));

        close(fd[1]);

        int wstatus;
        pid_t pid = waitpid(child_pid, &wstatus, 0);

        if (pid <= 0) {
            break;
        }

        if (WIFEXITED(wstatus)) {
            status = WEXITSTATUS(wstatus);
        } else if (WIFSIGNALED(wstatus)) {
            status = (int)128 + WTERMSIG(wstatus);
        }
    }

    exit(status);
}
