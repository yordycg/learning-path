#include <stdio.h>

/*
 * POINTERS & ARRAYS
 * - Cuando apuntamos a un array, por detras estamos
 *   haciendo referencia al 1er elemento del array.
 */

int main(void){
  int array[5] = {11, 22, 33, 44, 55};
  int *ptr_array = NULL;

  // Esto...
  ptr_array = array;
  // Es esto, por detras!
  ptr_array = &array[0];

  printf("Valor 'ptr_array': %d\n", *ptr_array);
  printf("Direccion 'ptr_array': %p\n", ptr_array);

  return 0;
}
