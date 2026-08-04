#include <stdio.h>

void section(char *msj);

/*
 * POINTERS
 * - Variable especial que almacena una direccion de memoria,
 *   donde se almacena un valor 'x'.
 * - Definir un pointer:
 *   - Usar el operador(?) '*'.
 *   - Ej: int *ptr_name;
 * - Recomendacion: se recomienda siempre inicializar los punteros
 *   a NULL o 0, si no le vamos a asignar una direccion de memoria.
 *   - Ej: int *ptr_int = NULL;
 *
 * - Obtener direccion de memoria de una variable:
 *   - Debemos usar el operador '&'.
 *   - Ej: &variable_name = direccion de memoria
 *
 * - Tipos de punteros:
 *   Dependera del valor que queremos referenciar...
 *     - Si es un valor 'int', el puntero debe ser 'int'.
 *     - Si es un valor 'float', el puntero debe ser 'float'.
 *
 * - Dereference:
 *   Nos permite obtener el valor real, al que la direccion
 *   de memoria apunta. Caracteristica principal de los punteros.
 */

int main(void){
  section("Obtener Direccion de Memoria");
  int age = 31;

  // TYPE *PTR_NAME;
  int *ptr_age = &age;

  printf("Valor 'age': %d\n", age);
  printf("Direccion 'age': %p\n", ptr_age);  // %p sufijo para mostrar/formatear puntero

  section("Dereference");
  int x = 10;
  int *ptr_x = NULL;  // recomendacion, siempre inicializar a NULL

  printf("x ANTES (cambio con ptr): %d\n", x);

  ptr_x = &x;  // asignar direccion de memoria a puntero...

  // Dereference
  *ptr_x = 20;  // asignar nuevo valor, usando el puntero...

  printf("x DESPUES (cambio con ptr): %d\n", x);
  printf("x DESPUES (usando dereference): %d\n", *ptr_x);

  return 0;
}

void section(char *msj){
  printf("\n----- %s -----\n", msj);
}
