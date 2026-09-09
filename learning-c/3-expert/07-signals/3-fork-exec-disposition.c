/*
 * @title: fork, exec and dispositions
 * @phase: learning-c - week 4, day 3
 * ----------------------------------
 * @learn:
 * 1.- La sigaction() debe ocurrir antes del fork(), para qu el hijo HEREDE tambien
 *     esas caracteristicas agregadas al kernel.
 * 2.- En este ejemplo es IMPORTANTE enviar las senales ANTES del wait(&status)
 *     porque sino el padre se queda en espera y no podria enviar ninguna senal.
 * 3.- Familia exec**:
 *     - Todas las funciones de la familia exec son wrappers de la misma syscall:
 *       execve.
 *     - Todas hacen lo mismo, respecto al reseteo de algunas caracteristicas,
 *       como las senales. La diferencia es como se pasan los argumentos y el PATH.
 *       - l vs v -> lista de args sueltos vs vector (W3 D4).
 *       - p -> buscan en el $PATH (W3 D4).
 *       - e -> pasan un entorno custom.
 *
 *     > NOTE1: No es un "reseteo", el kernel reemplaza la imagen del proceso hijo.
 *     > NOTE2: Lo unico que se mantiene respecto a una senal es el SIG_IGN.
 *
 * @new_questions:
 *
 * @connect_with:
 * - Process.
 * - Signals.
 * - exec** family.
 */
#define _POSIX_C_SOURCE 200809L

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

volatile sig_atomic_t count = 0;

void handler(int signum);

int main(void)
{
    struct sigaction sa;
    sa.sa_handler = &handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    /* Creamos handler en el kernel...
     * Antes del fork() para que se propague al hijo...
     */
    sigaction(SIGINT, &sa, NULL);

    pid_t child_pid = fork();

    if (child_pid == -1)
        exit(EXIT_FAILURE);

    if (child_pid == 0) {
        /* EXPERIMENTO A:
        while (count < 3) {
            printf("[CHILD PID]: %d\n", getpid());
            pause();
        }
        exit(EXIT_SUCCESS); // salir con 0
        */
        char *args[] = {"sleep", "5", NULL};
        if (execvp(args[0], args) == -1) {
            perror("[ERROR execv]");
            exit(EXIT_FAILURE);
        }
    } else {
        /* EXPERIMENTO A:
         * Enviar signal al hijo desde el padre...
        for (int i = 0; i < 3; i++) {
            sleep(1);
            kill(child_pid, SIGINT);
        }
        */
        sleep(1);
        kill(child_pid, SIGINT);

        int child_status;
        wait(&child_status);

        if (WIFEXITED(child_status)) {
            printf("[CONCLUSION]: El hijo hereda el handler");
            printf("Y muere de forma normal.\n");
            return WEXITSTATUS(child_status);
        }
        if (WIFSIGNALED(child_status)) {
            printf("[CONCLUSION]: El hijo hereda el handler, pero 'exec' lo resetea\n");
            printf("Y muere por senal\n");
            return (int)128 + WTERMSIG(child_status);
        }
    }

    exit(EXIT_SUCCESS);
}

void handler(int signum)
{
    if (signum == SIGINT) {
        count++;
        write(STDOUT_FILENO, "\nSIGINT recibido!\n", 18);
    }
}
