/* ============================================================
* @title    Pipe Gotchas (SIGPIPE, buffer, pipe2)
* @phase    Phase 1 (learning-c) · S5 · Kata 5
* -------------------------------------------------------------
* @learn
*   - La disposicion de SIGPIPE y su handler son caminos EXCLUYENTES:
*     con SIG_DFL el kernel mata el proceso dentro del write() (exit 141 =
*     128+13, SIN mensaje y sin llegar al exit(status)); con handler el
*     proceso sobrevive, write() retorna -1 con errno=EPIPE ("Broken pipe")
*     y el codigo de salida lo decide el programador.
*   - Para que SIGPIPE se entregue tienen que estar cerrados TODOS los
*     read-ends. Si el propio proceso escritor mantiene fd[0] abierto, el
*     kernel todavia ve un lector y el write() tiene exito (exit=0).
*   - Nadie puede reapear su propia muerte: waitpid() solo reapea hijos. El
*     141 de una etapa lo observa el shell que la lanzo; por eso un handler
*     dentro del padre reapea al HIJO y no captura el SIGPIPE del padre.
*   - El pipe tiene capacidad (F_GETPIPE_SZ, 65536 tipico) distinta del
*     tamano de escritura ATOMICA (PIPE_BUF=4096). Con O_NONBLOCK y el
*     buffer lleno, write() devuelve -1/EAGAIN; un bloque que no divide la
*     capacidad produce una escritura PARCIAL (n < count) que no es error.
*   - pipe2(O_CLOEXEC) marca el descriptor con FD_CLOEXEC, que se lee con
*     F_GETFD (flag del descriptor), no con F_GETFL (flag de estado del
*     archivo). Evita que los FDs del pipe se filtren a los hijos via exec.
*   - $? de un pipeline: por defecto es el de la ULTIMA etapa (yes | head -n 1
*     -> 0); con `set -o pipefail` es el primer fallo de la cadena (-> 141).
*     mysh ya guarda el de la ultima etapa (Kata 4) -> imita el default bash.
*
* @open_questions
*   - Por que el bucle de write() no usa n == 0 como condicion de fin, a
*     diferencia del read() de katas anteriores?
*   - Por que con un bloque de 8192 la escritura nunca salio parcial?
*   - Por que SIG_DFL y handler no pueden coexistir en la misma corrida?
*
* @connect_with
*   - MOC - Processes
*   - Linux - Pipe Gotchas (SIGPIPE, buffer)
*   - Linux - Waiting on a Pipeline
*   - Linux - Async-Signal-Safe Functions
*   - File Descriptors - Linux
============================================================ */
#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE

#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int status = 0;

void handler(int signum);

int main(void)
{
    struct sigaction sa;
    sa.sa_handler = &handler; /* A: SIG_DFL | B: &handler */
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGPIPE, &sa, NULL) == -1) {
        perror("[ERROR SIGACTION()]");
        exit(EXIT_FAILURE);
    }

    int fd[2];
    if (pipe(fd) == -1) {
        perror("[ERROR PIPE()]");
        exit(EXIT_FAILURE);
    }

    /* Opcion C: */
    printf("PIPE_BUF: %d\n", PIPE_BUF);
    printf("pipe size: %d\n", fcntl(fd[1], F_GETPIPE_SZ));

    int cfd[2];
    if (pipe2(cfd, O_CLOEXEC) == -1) {
        perror("[ERROR PIPE2()]");
        exit(EXIT_FAILURE);
    }
    int flags = fcntl(cfd[0], F_GETFD);
    printf("pipe2 flags = %s\n", (flags & FD_CLOEXEC) ? "FD_CLOEXEC" : "sin FD_CLOEXEC");

    fcntl(cfd[1], F_SETFL, O_NONBLOCK);

    char buf[8192] = {0};
    ssize_t total = 0;
    ssize_t n;
    int parcial = 0;

    while ((n = write(cfd[1], buf, sizeof buf)) > 0) {
        total += n;
        if (n < (ssize_t)sizeof buf)
            parcial = 1;
    }
    if (errno == EAGAIN) {
        printf("escritos = %d bytes hasta EAGAIN (parcial): %s", (int)total,
               (parcial == 1) ? "si\n" : "no\n");
    }

    pid_t child_pid = fork();

    switch (child_pid) {
    case -1:
        perror("[ERROR FORK()]");
        exit(EXIT_FAILURE);
    case 0:
        close(fd[0]);

        _exit(0);
    default:
        close(fd[0]);

        sleep(1);

        const char *msg = "[WRITE]: Mensaje desde el padre\n";
        if (write(fd[1], msg, strlen(msg)) == -1) {
            perror("[ERROR WRITE()]");
            exit(EXIT_FAILURE);
        }

        close(fd[1]);
    }
    exit(status);
}

void handler(int signum)
{
    (void)signum;

    const char *msg = "[WRITE]: Mensaje enviado por la signal - SIGPIPE\n";

    write(STDOUT_FILENO, msg, strlen(msg));

    int wstatus;
    pid_t pid = waitpid(-1, &wstatus, 0);
    if (pid <= 0)
        return;

    if (WIFEXITED(wstatus)) {
        status = WEXITSTATUS(wstatus);
    } else if (WIFSIGNALED(wstatus)) {
        status = (int)128 + WTERMSIG(wstatus);
    }
}
