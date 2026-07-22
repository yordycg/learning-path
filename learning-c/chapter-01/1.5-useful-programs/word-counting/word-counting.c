/* Count lines, words, chars in input */
#include <stdio.h>

#define YES 1   // en una palabra
#define NO 0  // fuera de una palabra

/*
 * - inword: variable que identifica si estamos sobre una palabra,
 * por eso la inicializamos en NO.
 * - Inicializamos 3 variables en 0, porque son variables contadores.
 */
int main(void){
  int c, nl, nw, nc, inword;

  nl = nw = nc = 0;
  inword = NO;

  while((c = getchar()) != EOF){
    ++nc;
    if (c == '\n')
      ++nl;
    if (c == ' ' || c == '\n' || c == '\t')
      inword = NO;
    else if (inword == NO){
      inword = YES;
      ++nw;
    }
  }

  printf("%d %d %d\n", nl, nw, nc);

  return 0;
}
