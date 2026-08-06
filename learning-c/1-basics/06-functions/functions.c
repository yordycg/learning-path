#include <stdio.h>

/*
 * FUNCTIONS
 * - Siempre indicar los tipos respectivos, tanto para el retorno,
 *   como para tambien los parametros.
 * - Con 'void' le indicamos al compilador que no tiene valor,
 *   por lo tanto, NO TIENE un tipo.
 *
 * - Function Prototype:
 *   - Le indica al compilador la existencia de una funcion.
 *   - Nos permite definir el cuerpo de la funcion desde cualquier lugar.
 *   - Siempre se deben definir ANTES de la funcion 'main()'.
 *   - Debe tener el header de la funcion: type_return name_function(type params);
 *
 * - Function Void:
 *   - Son funcion que NO retornan datos, por lo tanto nunca llevan la keyword
 *   'return'.
 *   - Siempre usar la keyword 'void', que hace referecia a "vacio", y sin tipo.
 *   - Si una funcion no usa parametros, se recomieda indicar el tipo 'void'.
 */

// Prototype
int plus_one(int num);
void hello(void);

int main(void){
  int my_age = plus_one(30);

  printf("Mi edad es: %d\n", my_age);

  hello();

  return 0;
}

/*
 * SINTAXIS
 * type_return name_function(type param[s]){
 *    return data;
 * }
 */
int plus_one(int num){
  return num + 1;
}

// Funcion VOID
void hello(void){
  printf("Saludos desde la funcion 'hello'\n");
}
