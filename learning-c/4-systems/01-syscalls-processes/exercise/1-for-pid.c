/*
 * Ejercicio 1 - Basico
 * Imprimir PID y PPID en padre e hijo.
 *
 * LEARN:
 * NONE
 *
 * QUESTION RESOLVED:
 * NONE
 *
 * NEW QUESTIONS:
 * - Como obtener el PID del proceso padre?
 *   R// con la funcion getppid() puedo obtener el PID del proceso padre,
 *   OJO de donde lo llamas!
 *
 * CONNECT WITH:
 * - Process / Syscall / OS / Linux / Kernel.
 */
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{

    pid_t child_pid = fork();

    if (child_pid == -1) {
        printf("[ERROR]: Child process not created!\n");
        return 1;
    }
    if (child_pid == 0) {
        printf("[CHILD PROCESS]: Success child process created!\n");
        printf("[CHILD PROCESS]: PID: %d\n", getpid());
    } else {
        printf("[PARENT PROCESS]: In execution!\n");
        printf("[PARENT PROCESS]: PID: %d\n", getpid());
    }

    return 0;
}
