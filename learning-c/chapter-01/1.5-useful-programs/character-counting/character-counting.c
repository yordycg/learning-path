/* Count characters in input */
#include <stdio.h>

/*
 * Crear variable contador
 * Definir variable contador en cero
 * While (el valor del caracter obtenido no sea el fin del archivo)
 *    Aumentar en 1, la variable contador
 * Mostrar el valor de contador, total de caracteres
 */

int main(void){
  long nc;
  nc = 0;

  while(getchar() != EOF)
    ++nc;  // abreviacion de nc = nc + 1, la abreviacion es mas eficiente

  printf("%ld\n", nc);  // con %ld, podemos mostrar valores de tipo long

  /*
   * Contar numeros mas grandes
   * - Debemos usar 'double'.
   * - Podemos usar un loop 'for'.
   * double nc;
   *
   * for(nc = 0; getchar() != EOF; ++nc)
   *    ;  // proposicion nula, satisface el requisito que 'for' tenga un cuerpo
   *
   * printf("%.0f\n", nc);
   */

  return 0;
}
