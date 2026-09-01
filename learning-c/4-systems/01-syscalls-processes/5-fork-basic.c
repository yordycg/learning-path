/*
 * LEARN:
 * fork():
 * - Crea un nuevo proceso a partir del proceso que llama a la funcion.
 * - Nuevo proceso -> child process
 * - Proceso que hizo la llamada -> parent process
 * - Al momento de hacer un fork() ambos proceso tiene espacios de memoria
 *   diferentes, pero el contenido de ambos espacios es identico, y a partir
 *   de eso cada uno puede hacer cosas diferentes.
 *
 * QUESTION RESOLVED:
 * 1- Como crear un proceso dentro de otro proceso (proceso padre -> proceso hijo).
 *
 * CONNECT WITH:
 * - Process / Syscall / OS / Linux / Kernel.
 *
 * NEW QUESTIONS:
 * - Porque el proceso padre (printf) se ejecuta antes?
 *   R// El scheduler decide que proceso ejecuta primero, el codigo no tiene
 *   garantia de nada.
 *   Para una correcta cordinacion de los procesos es necesario usar mecanismo
 *   como 'wait()', un pipe, u otro mecanismo de sincronizacion.
 */

#include <stdio.h>
#include <sys/types.h> /* para el tipo: pid_t */
#include <unistd.h>    /* para usar fork() */

int main(void)
{
    pid_t child_pid = fork();

    if (child_pid == -1) {
        printf("[ERROR]: No se pudo crear un proceso hijo!\n");
        return 1;
    } else if (child_pid == 0) { /* Child Process - Memory Space */
        printf("[OK]: Proceso hijo creado!\n");
        printf("Este es el espacio del proceso hijo!\n");
    } else { /* Parent Process - Memory Space  */
        printf("Este es el espacio del proceso padre!\n");
    }

    return 0;
}
