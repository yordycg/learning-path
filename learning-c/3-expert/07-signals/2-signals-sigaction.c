/*
 * @title: sigaction and signal dispositions
 * @phase: learning-c - week 4, day 2
 * ----------------------------------
 * @learn:
 * - signal handlers: es una funcion que es llamada cuando una senal especifica
 *   es enviada a un proceso. Los handlers interrumpen el hilo principal de
 *   ejecucion de forma asincrona.
 *
 *   Un proceso puede realizar las siguientes acciones cuando recibe una senal:
 *   - El proceso hace la accion por defecto de la senal recibida.
 *   - El proceso puede bloquear la senal (algunas pueden ignorarse).
 *   - El proceso puede atender la senal con un handler.
 *
 *   El hanlder se ejecuta en el stack del proceso, lo que implica que al
 *   terminar el handler retorna al punto en que la ejecucion fue interrumpida.
 *
 * > senales asicrona: un proceso no sabe con anticipacion que un evento
 *   ocurrira.
 *
 * - signal mask: bloquear senales diliveradmante, el kernel mantiene un signal
 *   mask, un conjunto de senales cuya entrega a ese proceso esta bloqueada en
 *   ese momento, si se envia a un proceso una senal bloqueda, al entrega de
 *   dicha senal se retrasa hasta que se desbloquee al eliminar la signal mask
 *   de ese proceso.
 *
 * - sigaction(): forma estandarizada para definir de forma determinista
 *   que funcion manejara el senal (sa_handler), que senales enmascarar
 *   durante la ejecucion (sa_mask) y flags especiales (sa_flags como
 *   SA_RESTART).
 *   - estructura de sigaction:
 *     - sa_handler: puntero a una funcion handler basica (void hand(int sig)).
 *       - La usaremos el 90% de los casos.
 *     - sa_sigaction: handler mas avanzado, usar cuando necesitemos metadados
 *       (quien envio la senal, memoria que fallo, etc.).
 *     - sa_mask: set de senales adicionales a bloquear durante el handler.
 *       - Siempre inicializar en 'sigemptyset()' para evitar basura en memoria.
 *     - sa_flags: banderas que alteran el comportamiento del kernel frente a
 *       la senal. Por defecto '0', o flags como 'SA_RESTART' o 'SA_SIGINFO'.
 *
 *     > Nunca se pueden usar sa_handler y sa_sigaction a la vez, comparten
 *       memoria interna.
 *
 *  - plantilla base:
 *     volatile sig_atomic_t status = 0;
 *
 *     void handler(int sig){
 *          status = 1;
 *          // aqui debemos construir lo que necesitemos al recibir x senal.
 *     }
 *
 *     in main(void){
 *          struct sigaction sa;
 *          sa.sa_handler = handler; // asignar el handler
 *          // limpiar mascara, no bloquear senales extras
 *          sigemptyset(&sa.sa_mask);
 *          sa.sa_flags = 0; // 0 flags por defecto
 *
 *          // agregarla al kernel:
 *          // sigaction(SENAL, &nueva_accion, &antigua_o_NULL)
 *          sigaction(SIGINT, &sa, NULL);
 *
 *          while(!status){
 *              pause(); // esperar senal
 *          }
 *
 *          return 0;
 *     }
 *
 * - disposiciones de senales:
 *   - SIG_DFL: accion por defecto del kernel (terminar, volca core,
 *     ignorar, etc.).
 *   - SIG_IGN: descarta la senal silencionamente.
 *   - custom handler:
 *     - 'void (*sa_handler)(int)': interrumpir la ejecucion normal para
 *       invocar una funcion tuya en el stack.
 *
 * - Flags y atomicidad:
 *   - Si el hanlder y 'main()' comparten una variable de estado (una flag tipo
 *     'recibi la senal'), esa variable debe declararse como 'volatile
 *     sig_atomic_t'
 *     para evitar que el compilador optimice su lectura en registros y para
 *     garantizar lecturas/escrituras atomicas.
 *   - volatile sig_atomic_t:
 *
 * - Disparo intencional:
 *   - raise(): envia una senal sig al proceso en ejecucion (se envia a si
 *     mismo).
 *   - kill(): el proceso que ejecuta kill envia una senal a proceso
 *     especificado con pid. Si pid == 0 la senal es envidada a todos los
 *     procesos, excepto los procesos del sistema.
 *     - int kill(int pid, int signal);
 *       - Si retorna 0 es exitoso, sino retorna un error en 'errno'.
 *
 * @new_questions:
 * - signal vs sigaction:
 *   -
 *
 * @connect_with:
 * - Process
 * - Signals
 */
#define _POSIX_C_SOURCE 200809L

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

volatile sig_atomic_t count = 0;

void handler(int signum)
{
    if (signum == SIGINT) {
        count++;
        write(STDOUT_FILENO, "\nSIGINT recibido!\n", 18);
    }
}

int main(void)
{
    printf("[PID]: %d\n", getpid());

    struct sigaction sa;
    sa.sa_handler = &handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGINT, &sa, NULL);

    while (count < 3) {
        pause();
    }

    exit(EXIT_SUCCESS);
}
