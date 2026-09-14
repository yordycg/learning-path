/* ============================================================
* @title    Intro to pipe
* @phase    Phase 1 (learning-c) · S5 · Kata 1
* -------------------------------------------------------------
* @learn
*   - pipe:
*       - Mecanismo que permite la comunicacion entre procesos.
*       - El output de un proceso puede ser usado directamente
*       como el input de otro proceso.
*       - Es la forma mas simple y efectiva de crear un canal
*       de flujo de datos, pero solo UNIDIRECCIONALMENTE.
*   - Tipos de pipe:
*       - Unnamed pipes: son usados para la comunicacion entre
*       procesos RELACIONADOS, tipicamente entre un padre y su
*       hijo. Se usa la syscall: pipe().
*       - Named pipes (FIFOs): permite la comunicacion entre
*       procesos NO RELACIONADOS. Se usa la syscall: mkfifo().
*   - Como funciona un pipe:
*       - 1ero cuando se crea un pipe(), el kernel asigna un
*       buff de memoria, este almacena temporalmente los datos
*       transmitidos entre procesos.
*       - 2do pipe() llena una matriz con 2 fd:
*           - pipefd[0] -> extremo de lectura -> recibe los datos.
*           - pipefd[1] -> extremo de escritura -> envia los datos.
*       - 3ero Comportamientos relevantes:
*           - Buff lleno: fd[1] se bloquea hasta haya espacio.
*           - Buff vacio: fd[0] se bloquea hasta que escriban datos.
*           - Una vez completada la comunicacion, cada proceso debe CERRAR sus
*           fd[n].
*   - Uso de pipe:
*       - 1ero debemos crear el pipe(), y luego podemos hacer el fork(),
*       para que asi ambos procesos tengan los mismos fd[n].
*       - Para lectura debemos usar -> read().
*       - Para escritura debemos usar -> write().
*
*   - EOF: read() retorna 0 cuando todos los write-ends estan cerrados y no
*   quedan datos. Ese 0 es la senal del fin.
*   - Bloqueo vs EOF: con un write-end abierto, un read() sobre buffer vacio
*   BLOQUEA esperando mas datos.
*   - Loop hasta EOF: para un flujo de longitud desconocido el lector itera
*   while((n = read(...)) > 0).
*   - close(write-end) = "no voy a escribir MAS". De ahi que la senal que
*   produce el EOF.
*   - read/write son syscalls sobre fd crudos (int).
*   - Herencia tras fork(): ambos procesos heredan copias de los 2 extremos ->
*   cada uno cierra el que no usa, sin lo cual el EOF nunca llega.
*
* @open_questions
*   - Que es un IPC?
*       - IPC = Inter-Process Communication | Canales de comunicacion entre
*       procesos.
*       - El pipe es la forma mas simple.
*   - pipe() vs pipe2()?
*
* @connect_with
*   - MOC - Processes
*   - File Descriptors - Linux
*   - Redirection and dup2 - Linux
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
    /*
     * array de 2 elementos:
     * fd[0] ->  read
     * fd[1] -> write
     */
    int fd[2];
    int size_buf = 1024;
    char buf[size_buf];

    if (pipe(fd) == -1) {
        perror("[ERROR PIPE]");
        exit(EXIT_FAILURE);
    }

    pid_t child_pid = fork();

    switch (child_pid) {
    case -1:
        perror("[ERROR FORK]");
        exit(EXIT_FAILURE);
    case 0:           /* Child */
        close(fd[1]); /* cerrar fd que no usa el hijo... */

        // read msg from the parent...
        ssize_t bytes_reads;
        while ((bytes_reads = read(fd[0], buf, size_buf)) > 0) {
            write(STDOUT_FILENO, buf, bytes_reads);
        }
        close(fd[0]);

        if (bytes_reads == -1) {
            perror("[ERROR READ()]");
            _exit(EXIT_FAILURE);
        }

        _exit(EXIT_SUCCESS);
    default:          /* Parent */
        close(fd[0]); /* cerrar fd que no usa el padre... */

        const char *msg_parent = "Message for the child process: \n";
        write(STDOUT_FILENO, msg_parent, strlen(msg_parent));

        const char *msg = "Enviado desde WRITE()\n";
        write(fd[1], msg, strlen(msg));

        close(fd[1]); /* cerrar fd que no usa el padre... */

        int wstatus;
        pid_t pid = waitpid(child_pid, &wstatus, 0);
        if (pid <= 0)
            break;

        if (WIFEXITED(wstatus)) {
            status = WEXITSTATUS(wstatus);
        } else if (WIFSIGNALED(wstatus)) {
            status = (int)128 + WTERMSIG(wstatus);
        }
    }

    exit(status);
}
