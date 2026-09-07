/*
 * @title: signals
 * @phase: learning-c - week 4, day 1
 * ----------------------------------
 * @learn:
 * - signal:
 *   - Es una notificacion enviada a un proceso, indica que un
 *     evento a ocurrido.
 *   - Es descrita como: software interrupts.
 *   - Puede ser utilizada como una tecnica de sincronizacion.
 *   - Es definido como un entero pequeno unico, que inician
 *     desde 1. Estos enteros estan definidos en <signal.h>,
 *     sus nombres comienzan con SIGxxxx.
 *   - Una senal es "generada" por un eveneto, una vez generada
 *     es "enviada" al proceso. El tiempo entre que es generada
 *     y es enviada una senal, se dice que esta "pendiente".
 *   - some linux signal:
 *     - SIGKILL: matar el proceso.
 *     - SIGBUS: error al acceder a la memoria.
 *     - SIGSTOP: pausa el proceso.
 *     - SIGCONT: continuar si esta pausado.
 *     - SIGINT: interrupcion: normalmente usar "ctrl-c".
 *     - SIGTERM: interrupcion solicitada.
 *   - functions:
 *     - kill(): un proceso puede enviar una senal a otro proceso
 *       - int kill(pid_t pid, int sig);
 *         - Retorna 0 en exito, o -1 en error.
 *       - Podemos comprobar la existencia de un proceso:
 *         TLPI - Cap. 20.6
 *     - raise(): un proceso se envia a si mismo una senal, equivalente
 *       a hacer: kill(getpid(), sig);
 *       - int raise(int sig);
 *         - Retornar 0 en exito, o un valor nonzero en error.
 *
 * @new_questions:
 * - que ocurre si hago 'Ctrl-C' antes que termine el loop de 5seg?
 *   - El kernel a traves del driver de la terminal o TTY envia la
 *     la misma senal a todo el grupo de proceso: proceso hijo y
 *     proceso padre SIMULTANEAMENTE.
 *   - Como funciona por debajo:
 *     - a. Cada proceso en Linux pertenece a un grupo de proceso (PGID).
 *     - b. Cuando el padre hace un 'fork()', el hijo HEREDA el PGID del
 *       padre, por lo tanto, ambos procesos pertenecen al mismo grupo.
 *     - c. Cuando hacemos 'Ctrl-C', la terminal genera el 'SIGINT' y se
 *       envia a todos los proceso pertenecientes a ese grupo.
 *     - PD: La terminal al ejecutar un programa, asigna ese proceso al
 *       grupo 'Foreground Process Group', grupo en primer plano.
 *
 * @connect_with:
 * - Process.
 */
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    pid_t child_pid = fork();

    if (child_pid == -1) {
        exit(EXIT_FAILURE);
    }
    if (child_pid == 0) { /* proceso hijo... */
        int count = 0;
        while (1) {
            printf("Mi PID: %d\n", getpid());
            sleep(1);
            count++;

            if (count == 5) {
                raise(SIGINT);
            }
        }
    } else { /* proceso padre... */
        int status;
        wait(&status);
        printf("Parent process: %d\n", getpid());

        if (WIFEXITED(status)) {
            printf("Hijo muerto normalmente!!\n");
            return WEXITSTATUS(status);
        }
        if (WIFSIGNALED(status)) {
            printf("Hijo muerto por signal!!\n");

            if (SIGINT == WTERMSIG(status))
                printf("--- SIGINT == WTERMSIG(status) ---\n");

            return 128 + WTERMSIG(status);
        }
    }

    exit(EXIT_SUCCESS);
}
