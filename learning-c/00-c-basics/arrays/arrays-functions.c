#include <stdio.h>

/*
 * ARRAYS TO FUNCTIONS
 * Tenemos 3 formas de pasar un array como args a una funcion:
 * - Pasar con notacion puntero - RECOMENDADA!:
 *   Ej: ...(type *param_array, int size_array)...
 * - Pasar con notacion array:
 *   Ej: ...(type param_array[], int size_array)...
 * - Pasar con notacion array + size:
 *   Ej: ...(type param_array[size], int size_array)...
 */

// Notacion puntero: RECOMENDADA!!
void times2(int *arry, int size);

// Notacion array:
void times3(int arry[], int size);

// Notacion array + size:
void times4(int arry[5], int size);

int main(void){
  int nums[5] = {11, 22, 33, 44, 55};

  printf("Times 2:\n");
  times2(nums, 5);
  printf("Times 3:\n");
  times3(nums, 5);
  printf("Times 4:\n");
  times4(nums, 5);

  return 0;
}

// RECOMENDADA!!
void times2(int *arry, int size){
  for(int i=0; i < size; i++)
    printf("%d\n", arry[i] * 2);
}
void times3(int arry[], int size){
  for(int i=0; i < size; i++)
    printf("%d\n", arry[i] * 3);
}
void times4(int arry[5], int size){
  for(int i=0; i < size; i++)
    printf("%d\n", arry[i] * 4);
}
