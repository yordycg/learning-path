#include <stdio.h>

/*
 * SIEMPRE definir los nuevos TYPEs, para evitar errores al compilar!
 * Ej. si 1ero indicamos el tipo: struct car ... en la funcion protipo
 * y la declarabamos ANTES que el struct car{...}, teniamos error!
 */

struct car{
  char *name;
  float price;
  int speed;
};

void set_price(struct car *c, float new_price);

int main(void){
  struct car saturn = {.speed=170, .name="Saturn SL/2"};

  set_price(&saturn, 950.005);

  printf("Saturn Price: %f\n", saturn.price);

  return 0;
}

void set_price(struct car *c, float new_price){
  // ERROR:
  // No podemos usar el operador punto en un puntero (c), el compilador retorna error...
  // c.price = new_price; // ERROR!

  // (*c).price = new_price;  // derefernciar el puntero para asignar el valor al campo real.
  c->price = new_price;  // azucar sintaxtico, mas claro y evita errores, lo mismo que lo anterior.
}
