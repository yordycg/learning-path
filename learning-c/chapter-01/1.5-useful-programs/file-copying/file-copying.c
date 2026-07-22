#include <stdio.h>

/*
 * Programa que copia el input en el output
 * un caracter a la vez.
 */

/*
 * read un caracter
 * while (caracter no es indicador de fin de archivo)
 *    write en el output el caracter recien leido
 *    read un caracter (nuevo caracter)
 */
int main(void){
  int c;  // se definio como 'int', para distinguir el fin del input valido
  c = getchar();

  /*
   * getchar, retorna el caracter EOF como fin de la entrada (input),
   * EOF (end of file) no puede ser con ningun otro caracter, por eso
   * definimos a 'c', como INT, para que pueda almacenar un valor grande
   *
   * En C moderno el valor de EOF esta definido en stdio.h y es -1.
   */
  while(c != EOF){
    putchar(c);
    c = getchar();
  }

  return 0;
}
