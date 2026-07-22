#include <stdio.h>

/*
 * En esta version mas simplificada, reducimos la asignacion
 * c = gechar(), la asignacion es una expresion y tiene un valor
 * como resultado, por lo tanto puede ser parte de una expresion
 * mas larga.
 *
 * Los parentesis (), al rededor de la asignacion son necesario,
 * porque el operador != tiene mucho mas peso al operador =.
 */

int main(void){
  int c;

  /*
   * 1ero obtenemos el caracter, lo asignamos a 'c'
   * luego lo comparamos con 'EOF', si la expresion es
   * verdadera entra al loop e imprime 'c', pasamos a
   * la siguiente iteracion, obtenemos el proximo caracter
   * y se compara con 'EOF' nuevamente, al ser verdadera,
   * imprime 'c' nuevamente... asi hasta que c sea igual
   * que 'EOF'
   */
  while((c = getchar()) != EOF)
    putchar(c);

  return 0;
}
