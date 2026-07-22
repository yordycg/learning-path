/* Count lines in input */
#include <stdio.h>

/*
 * Definir variables: valor caracter y contador
 * Inicializar contador en 0
 * While (valor caracter sea diferente a fin del archivo)
 *    If (valor caracter sea igual a fin de linea)
 *        aumentar contador en 1
 * Mostrar valor del contador
 */

int main(void){
  int c, nl;
  nl = 0;

  while((c = getchar()) != EOF)
    if (c == '\n')
      ++nl;

  printf("%d\n", nl);

  return 0;
}
