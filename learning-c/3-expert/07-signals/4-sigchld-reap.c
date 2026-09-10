/*
 * @title:
 * @phase: learning-c - week 4, day 4
 * ----------------------------------
 * @learn:
 * 1- SIGCHLD: es la senal enviada del kernel al PADRE cuando uno
 *     de sus hijos termina, se detiene o se reanuda.
 * 2- 'reaping': proceso en el cual el padre limpia y elimina
 *    los registros del hijo cuando este termina su ejecucion.
 *    - wait() -> reaping sincrono.
 *    - SIGCHLD + waitpid() -> reaping asincrono.
 * 3- waitpid(): recoge el estado de un hijo.
 *    - pid_t waitpid(pid_t pid, int *wstatus, int options);
 *    - ejemplo: pid_t result_waitpid = waitpid(-1, &wstatus, WNOHANG);
 *      - pid = -1 -> cualquiera de mis hijos.
 *      - WNOHANG -> no bloquea:
 *        - retorna 0 -> no hay hijo listo en ese instante, retorna el control
 *          de inmediato.
 *      - result_waitpid puede retornar:
 *        - PID del hijo recogido.
 *        - 0 (WNOHANG y nadie listo).
 *        - -1 + errno (ECHILD = no tengo hijos).
 *    - Es async-signal-safe -> podemos llamarla dentro de un handler.
 *    - Diferencia con wait() -> permite elegir cual hijo y si bloquear.
 * 4- Notificacion: sincrono vs asincrono.
 *    - Sincrono: wait() -> el padre se congela hasta que el hijo muere.
 *    - Asincorno: handler para SIGCHLD + waitpid(WNOHANG) + pause() ->
 *      el kernel avisa y el padre reacciona cuando pasa, no cuando el decide.
 * 5- 'volatile sig_atomic_t': El handler corre asicronamente, el compilador
 *    no la ve la escritura del handler -> puede cachear en registro o eliminar la relectura.
 *    - 'volatile': relee de memoria, alguien invisible te la cambia.
 *    - 'sig_atomic_t': acceso que no se parte frente a una senal. Solo para
 *       variables compartidas entre handler y resto.
 * 6- Zombie vs Huerfano:
 *    - Zombie: hijo muerto, NO RECOGIDO, con el padre vivo.
 *    - Huerfano: el padre muere primero, el hijo se reparenta a init (PPID 1).
 *
 * @new_questions:
 *
 * @connect_with:
 * - Process.
 * - Signals.
 */
#define _POSIX_C_SOURCE 200809L

#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

volatile sig_atomic_t child_status;

void handler(int signum);

int main(void)
{
    struct sigaction sa;
    sa.sa_handler = &handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGCHLD, &sa, NULL);

    pid_t child_pid = fork();

    if (child_pid == -1)
        exit(EXIT_FAILURE);

    if (child_pid == 0) {

        sleep(5);

        exit(7);
    } else {

        pause(); // porque necesitamos esperar a que el hijo termine.

        return child_status;
    }

    exit(EXIT_SUCCESS);
}

void handler(int signum)
{
    (void)signum; /* omitir warning */

    int wstatus;

    while (1) {
        pid_t pid = waitpid(-1, &wstatus, WNOHANG);
        if (pid <= 0)
            break;

        if (WIFEXITED(wstatus)) {
            child_status = WEXITSTATUS(wstatus);
        } else if (WIFSIGNALED(wstatus)) {
            child_status = (int)128 + WTERMSIG(wstatus);
        }
    }
    return;
}
