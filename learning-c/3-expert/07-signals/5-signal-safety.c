/*
 * @title: signal safety
 * @phase: learning-c - week 4, day 5
 * ----------------------------------
 * @learn:
 * - Una señal puede interrumpir una syscall lenta (`read`) en cualquier momento:
 *   la syscall devuelve -1 y el kernel deja `errno = EINTR`.
 * - `sa_flags` decide qué pasa con esa syscall interrumpida:
 *     A) `sa_flags = 0`    -> la syscall SE CORTA y te devuelve -1/EINTR
 *                             (evidencia: "[ERROR]: Interrupted system call" + exit 0)
 *     B) `SA_RESTART`      -> el kernel REINICIA la syscall por ti y tú no te enteras
 *                             (evidencia: el handler corre, pero `read` sigue bloqueada -> timeout
 * 124)
 * - No toda función se puede llamar dentro de un handler. Solo las de `man 7 signal-safety`:
 *     write()  OK   strlen() OK (POSIX.1-2008 TC2)
 *     printf() NO   -> no es reentrante: comparte el buffer y el lock de stdio, y el handler
 *                      puede interrumpir un printf() a medias -> corrupción del stream.
 * - La seguridad también aplica a `errno`: el handler lo GUARDA al entrar y lo RESTAURA
 *   antes de retornar, para no falsear el diagnóstico de la syscall que interrumpió.
 *   Escribir `errno = EINTR` dentro del handler NO es restaurar: es inventar la causa.
 *
 * @new_questions:
 * - ¿printf() se vuelve seguro usando un buffer propio, o el lock de stdio sigue siendo el
 * problema?
 * - Diferido de D4: la race "lost wakeup" entre el chequeo del flag y `pause()`
 *   (patrón `sigprocmask` + `sigsuspend`).
 *
 * @connect_with:
 * - Process (S3): fork/exec/wait; una señal puede interrumpir las syscalls del padre.
 * - Signals (S4): D4 reaping con SIGCHLD (`waitpid(WNOHANG)`) vs D5: qué es seguro dentro del
 * handler.
 * - mysh v1.5: en el `read()` del prompt NO queremos un `SA_RESTART` ciego (si la syscall se
 *   reiniciara siempre, el shell no notaría la señal); y el hijo debe resetear SIGINT a SIG_DFL
 *   entre fork y execvp.
 */
#define _POSIX_C_SOURCE 200809L

#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

void handler(int signum);

int main(void)
{
    struct sigaction sa;
    sa.sa_handler = &handler;
    sigemptyset(&sa.sa_mask);
    /* sa.sa_flags = 0; EXPERIMENTO A */
    sa.sa_flags = SA_RESTART;

    /* agregar handler al kernel... */
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("[SIGACTION ERROR]");
        exit(EXIT_FAILURE);
    }

    /* Process... */
    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("[FORK]");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        sleep(1);

        if (kill(getppid(), SIGUSR1) == -1) {
            perror("[ERROR]");
        }
    } else {
        char buf[1024];
        ssize_t ret = read(STDIN_FILENO, buf, sizeof buf);
        if (ret == -1) {
            perror("[ERROR]");
        }
    }
    exit(EXIT_SUCCESS);
}

void handler(int signum)
{
    (void)signum;

    int saved_errno = errno;

    const char *msj = "[MSJ]: Envio este msj desd el handler!\n";
    size_t len = strlen(msj);
    write(STDOUT_FILENO, msj, len);

    errno = saved_errno;
}
