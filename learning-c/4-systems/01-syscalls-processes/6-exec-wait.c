/*
 *
 * LEARN:
 * - exec():
 *   - Familia de funciones que ejecutan un nuevo programa en el proceso de
 *     llamada, NO crea nuevos procesos, sobre escribe el programa actual
 *     con un nuevo proceso, esto es llamado: new-process image.
 *   - SOLO retornan un valor cuando ocurre un error, retornan el valor -1
 *     con 'errno' podemos obtener mas informacion del error.
 *   - Grupos de la familia exec**:
 *     - 'l' -> usar cuando el que llama, ya sabe que argumentos va a pasar,
 *       y se lo pasa como argumentos separados de la funcion.
 *     - 'v' -> usar cuando no sabemos la cantidad de argumentos a pasar,
 *       se lo pasamos como un puntero de array.
 *
 * - wait() - waitpid():
 *   - Hacen que el proceso padre ESPERE a que termine el proceso hijo.
 *   - wait -> espera a que cualquier hijo termine.
 *   - waipid -> permite esperar un hijo especifico.
 *   - Ambas funciones retornan el PID del proceso hijo que termino.
 *
 *   - pid_t wait(int *status);
 *   - pid_t waitpid(pid_t pid, int *status, int options);
 *   - *status -> puntero, se almacena el estado de salida del proceso hijo.
 *
 * - Params argc & argv:
 *   - argc (arg count) -> entero que indica cuants argumentoos hay, incluye
 *     el nombre del programa.
 *   - argv (arg vector) -> array de strings, terminado en NULL, cn los args
 *     individuales, cada elemento es un string.
 *   - Ejemlo: --- ls -l /tmp ---
 *     - argv[0] -> "ls"
 *     - argv[1] -> "-l"
 *     - argv[2] -> "/tmp"
 *     - argv[3] -> NULL
 *     - argc -> 3
 *
 * QUESTION RESOLVED:
 *
 * NEW QUESTIONS:
 * 1- como identificar que funcion de la familia exec**() usar?
 * 2- Cual es la diferencia entre pasar argumentos como una "lista de args"
 *    y pasar argumentos como un "vector de args"?
 *    R// En el contexto de la familia exec**() nos referimos a:
 *        - lista de args -> cuando el que llama el archivo/programa/comando
 *          sabe que argumentos le va a pasar, y los indica separadamente.
 *        - vextor de args -> cuando el que llama NO conoce la cantidad de
 *          argumentos que necesita pasar al archivo/programa/comando a ejecutar.
 * 3- Diferencias de pasar args en compile-time, con args en runtime?
 *    R// Pasar args en compile-time nos referimos a que en el codigo YA SABEMOS
 *        que argumentos vamos a pasar y de que tipo (siempre strings), y en
 *        runtime estodo lo contrario, ahi no tenemos idea de la cantidad de args,
 *        ni de que tipo, nada.
 *        En este contexto, usar el grupo 'l' solo funcionaria con args en compile-time
 *        porque NO puede recibir un numero variable/indeterminado de args. Y usar la
 *        el grupo 'v', puede recibir TANTO compile-time como runtime, ya que la
 *        cantidad de argumentos a recibir es dinamica (hasta NULL).
 *
 * CONNECT WITH:
 * - Process / Syscall / OS / Linux / Kernel / fork.
 *
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    pid_t child_pid = fork();
    int status;

    if (child_pid == -1) {
        printf("[ERROR]: No se pudo crear el proceso hijo.\n");
        return 1;
    }

    if (child_pid == 0) {
        // Proceso hijo:

        /* Usando modo: lista de argumentos */
        char *args_list[] = {"ls", "-l", NULL};

        if (execvp(args_list[0], args_list) == -1) {
            printf("[ERROR]: Programa a ejecutar no existe!\n");
            return 1;
        }
    } else {
        // Proceso padre:
        wait(&status);
    }

    return 0;
}
