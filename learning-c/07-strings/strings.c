#include <stdio.h>
#include <string.h>

/*
 * Strings:
 * Tenemos 2 formas de inicializar una variable string:
 * - Notacion Puntero:
 *   - `char *s = "Yordy Carmona";`
 *   - Es una variable de SOLO LECTURA.
 *   - Como funciona en memoria: Se almacena en un segmento de la memoria donde
 *   solo se pueden leer los datos. En caso de intentar modificar, el compilador
 *   retorna un fallo de segmentacion (Segmentation Fault/Crash).
 *   - Regla: Si definimos un string como puntero, se recomienda de igual manera
 *   definirlo como una `constante`, para indicarle al compilador.
 *
 * - Notacion Array:
 *   - `char s1[size] = "Nicolas Gonzalez";`
 *   - Es una copia local y mutable.
 *   - Como funciona en memoria: Se almacena en el STACK, donde no existen inter-
 *   mediarios ni protecciones.
 *   - Regla: Usar cuando queramos modificar, concatenar, recortar, o usar funciones
 *   que alteren el texto.
 */
void section(char *msj);

int main(void){

  section("String Variables as Pointer");
  char *s1 = "String *s1 puntero!";
  printf("%s\n", s1);

  section("String Variables as Array");
  char s2[14] = "Hello, world!";  // RECOMENDADA!
  char s3[] = "Hello, array!";  // no es necesario indicar el tamano, el compilador lo conoce

  printf("%s\n", s2);
  printf("%s\n", s3);

  section("String Length");
  // Usar la funcion 'strlen(string)' que esta en la libreria 'string.h'
  const char *str = "Yordy";  // output: 5 size

  printf("%s -> Tiene %zu bytes de longitud.\n", str, strlen(str));

  section("String Copy");
  // Usar la funcion 'strcpy(copy, original)' de 'string.h'
  char s_original[] = "Carmona Yordy";
  char s_copy[100];  // espacio suficiente para almacenar la copia

  strcpy(s_copy, s_original);

  s_copy[0] = 'z';

  printf("String Original: %s\n", s_original);

  printf("String Copy: %s\n", s_copy);

  return 0;
}

void section(char *msj){
  printf("\n----- %s -----\n", msj);
}
