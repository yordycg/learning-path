#include <stdio.h>

/*
 *
 */

void section(char *msj);

int main(void){
  section("Ejemplo Array");
  int i;
  float array_f[4];  // declarar array de 4 elementos float

  // Asignar valores...
  array_f[0] = 3.14159;  // siempre inicia en 0
  array_f[1] = 1.41432;
  array_f[2] = 1.61803;
  array_f[3] = 2.71812;

  // Mostrar
  for(i = 0; i < 4; ++i)
    printf("%f\n", array_f[i]);

  section("Formas de Inicializar");
  // Inicializar cada elemento:
  // int array_1[5] = {22, 37, 3490, 18, 94};

  // Inicializar algunos elemento, resto son siempre 0:
  // int array_2[5] = {22, 37, 3490};  // output: 22, 37, 3490, 0, 0

  // Inicializar todos los elementos a 0:
  // int array_3[5] = {0};  // output: 0, 0, 0, 0, 0

  // Inicializar indice especifico:
  // int array_4[5] = {22, [3] = 77};  // output: 22, 0, 0, 77, 0
                                    //
  // Inicializar sin indicar el size del array:
  // int array_5[] = {22, 37, 3490};  // output: 22, 37, 3490 | size = 3

  section("Obtener SIZE de un Array");

  /*
   * 1.- Obtener total de bytes de la variable array.
   * 2.- Obtener total de bytes del TYPE de la variable.
   * 3.- SIZE = byte_array / byte_type.
   */

  double array_double[45]; // 12 elements

  printf("Bytes array: %zu\n", sizeof(array_double));
  printf("Bytes type array: %zu\n", sizeof(double));

  printf("SIZE Array: %zu\n", sizeof(array_double) / sizeof(double));

  return 0;
}

void section(char *msj){
  printf("\n----- %s -----\n", msj);
}
