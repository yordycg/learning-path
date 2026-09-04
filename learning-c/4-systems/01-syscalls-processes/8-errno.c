/*
 * @title: errno: manejo de errores
 * @phase: learning-c - week 3, day 5
 * ----------------------------------
 * @learn:
 * - errno:
 *   - Guarda el codigo del ultimo error tras una
 *     llamada fallida.
 *   - El codigo identifica con precision el tipo
 *     de error que acaba de suceder.
 *   - Al ser una variable **global**, cualquier otra
 *     llamada a libc puede sobreescribir/modificar el
 *     codigo especifico que "recogio" de la llamada fallida.
 *   - perror() y strerror() pueden traducir ese
 *     error a formato texto, mucho mas claro.
 *   - perror(): Recibe un string, y formatea el
 *     mensaje del error junto al string. Por ejemplo
 *     - perror("[ERROR]") -> "[ERROR]: <msj_error".
 *   - strerror(): Recibe el numero de error (errno) y
 *     retorna el puntero al mensaje de error, permitiendo
 *     a nosotros controlar el formato del mensaje.
 *     - Esta en la libreria: <string.h>
 * - exit status:
 *   - Indica cuando un programa termina de forma
 *     erronea o de forma exitosa.
 *   - exit(): retorna el codigo de estado al OS usando
 *     unas constantes definidas en '<stdlib.h>'.
 *     - EXIT_SUCCESS: indica que el programa termino
 *       exitosamente.
 *     - EXIT_FAILURE: indica que el programa termino
 *       con un error.
 *
 * @new_questions:
 *
 * @connect_with:
 * - Process / fork / exec**.
 */
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("[CHILD ERROR]");
        exit(EXIT_FAILURE);
    }
    if (child_pid == 0) { /* Proceso hijo... */
        char *args[] = {"ERROR__", "-la", NULL};

        if (execvp(args[0], args) == -1) {
            printf("[ERROR EJECUCION - CHILD]: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
    } else { /* Proceso padre... */
        int status;
        wait(&status);
        /* Gestion de wait */
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
