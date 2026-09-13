/*
 * @title: exercise - sigign survives exec
 * @phase: learning-c - week 4, day 6
 * ----------------------------------
 * @goal: Demostrar que un SIG_IGN instalado por el padre sobrevive al execvp del hijo -
 *        mientras que en 3-fork-exec-disposition.c (parte B) un handler capturado
 *        se reseteaba a SIG_DFL al hacer exec.
 * @learn:
 * 1- sa_handler es un puntero a funcion que puede aceptar cosas distintas:
 *    - sa.sa_handler = &handler || handler; -> puntero REAL a mi funcion (usar o no '&' da igual).
 *      (kernel la llama!).
 *    - sa.sa_handler = SIG_DFL; -> sentinela (ptr=0) -> kernel aplica DEFAULT.
 *    - sa.sa_handler = SIG_IGN; -> sentinela (ptr=1) -> kernel IGNORA.
 *
 * @open_questions:
 *
 * @connect_with:
 * - Process
 * - Signal
 * - mysh
 */
#define _POSIX_C_SOURCE 200809L

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    struct sigaction sa;
    sa.sa_handler = SIG_IGN;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGINT, &sa, NULL);

    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("ERROR FORK");
        exit(EXIT_FAILURE);
    }
    if (child_pid == 0) {
        char *args[] = {"sleep", "5", NULL};
        if (execvp(args[0], args) == -1) {
            perror("[ERROR EXECVP]");
            _exit(EXIT_FAILURE);
        }
    } else {
        sleep(1);
        kill(child_pid, SIGINT);

        int wstatus;
        wait(&wstatus);
        if (WIFEXITED(wstatus)) {
            printf("[NOTE]: Salida normal del hijo!\n");
            return WEXITSTATUS(wstatus);
        } else if (WIFSIGNALED(wstatus)) {
            printf("[NOTE]: Salida por SIGNAL del hijo!\n");
            return (int)128 + WTERMSIG(wstatus);
        }
    }
}
