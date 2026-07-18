/*
 * - #include
 *      - Encargado de indicarle al 'preprocesador' que
 *      saque todo el codigo de otro archivo y lo ponga ahi, donde
 *      se indico.
 *      - Todo lo que inicie con '#', es para que el preprocesador actue.
 * - <stdio.h>
 *      - archivo de encabezado (header file), este especificamente es el
 *      encargado de todo el Input/Output Estandar en C
 *
 * - Preprocesador, es el encargado de ACTUAR antes del compilador, luego
 * viene el compilar para realizar la compilacion con todo el codigo listo.
 * Como resultado retorna codigo maquina (0 y 1) para que la CPU lo entienda.
 */
#include <stdio.h>

/*
 * Funcion main
 * - Funcion especial donde el programa comienza
 * a ejecutarse.
 * - Todo programa debe tener una funcion main.
 * - Desde la funcion main, se puede llamar y
 * ejecutar otras funciones.
 */
int main(void) {

  /*
   * LLamada a una funcion:
   *      - printf() es la encargada de mostrar el output, y dar formateo.
   *      - "Hello, World!\n", es el argumento, de tipo character array o string
   * constants.
   *      - \n: es el caracter de newline en notacion C.
   */
  printf("Hello, World!\n");
}
