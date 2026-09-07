/*
 * @title: Exercise: mysh-preview
 * @phase: learning-c - week 4, day 1
 * ----------------------------------
 * @exercise:
 * - Proceso padre simula 'mysh', imprime su PID y su PGID.
 * - Proceso hijo, imprime su propio PID y su PGID.
 * - Comprobar que PGID(padre) == PGID(hijo).
 * - Proceso hijo duerme 10 seg. y el kernel despacha
 *   la senal a ambos procesos, por pertenecer al mismo PGID.
 *
 * @learn:
 *
 * @new_questions:
 *
 * @connect_with:
 * - Process.
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void show_process_id(char *process_name);

int main(void)
{

    pid_t child_pid = fork();
    pid_t parent_pgid;
    parent_pgid = getpgrp();

    if (child_pid == -1) {
        exit(EXIT_FAILURE);
    }
    if (child_pid == 0) {
        show_process_id("Hijo");

        int child_pgid = getpgrp();
        if (parent_pgid == child_pgid) {
            printf("--- Ambos procesos pertenecen al mismo PGID! ---\n");
        }

        sleep(10);

    } else {
        show_process_id("Padre");

        int status;
        wait(&status);
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else if (WIFSIGNALED(status)) {
            return (int)128 + WTERMSIG(status);
        }
    }

    exit(EXIT_SUCCESS);
}

void show_process_id(char *process_name)
{
    printf("[Proceso %s]\n", process_name);
    printf("- PID: %d\n", getpid());
    printf("- PGID: %d\n", getpgrp());
}
