/* Test power function */
#include <stdio.h>

// Prototype: Le indica al compilador la existencia
// de la funcion, lo que permite que se pueda definir
// en cualquier lugar, incluso otro archivo.
// Se debe indicar:
// - Tipo del return
// - Nombre de la funcion
// - Tipo de los parametros
int power(int x, int n);

int main(void){
  int i;

  for(i=0; i<10; ++i)
    printf("%d %d %d\n", i, power(2,i), power(-3,i));

  return 0;
}

// Definicion de la funcion...
// Raise x to n-th power; n > 0
int power(int x, int n){
  int i,p;

  p = 1;
  for(i = 1; i <= n; ++i)
    p = p * x;

  return (p);
}

