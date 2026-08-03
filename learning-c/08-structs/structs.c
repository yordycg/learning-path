#include <stdio.h>

/*
 * STRUCT
 * - Forma de definir nuevos tipos.
 * - Conjunto de variables de diferentes tipos, bajo un mismo nombre.
 * - Se asemeja a una clase (OOP), pero solo de miembros (o campos),
 *   sin metodos.
 */
void section(char *msj);

int main(void){
  section("Declaracion + Asignacion");

  // Declarar
  struct car {
    char *name;
    float price;
    int speed;
  };

  // Declarar variable
  // TYPE: struct car NAME;
  struct car saturn;

  // Asignar
  // Usar operador punto
  saturn.name = "Saturn SL/2";
  saturn.price = 15999.95;
  saturn.speed = 175;

  printf("Name: %s\n", saturn.name);
  printf("Price (USD): %.2f\n", saturn.price);
  printf("Speed (KM): %d\n", saturn.speed);

  section("Inicializacion (Declaracion + Asignacion)");

  struct car2 {
    char *name;
    float price;
    int speed;
  };

  // Inicializar con valores en ORDEN
  // struct car2 saturn2 = {"Saturn2 SL/2", 16000.99, 180};
  // Inicializar con nombres, mas especifico sin orden
  struct car2 saturn3 = {.speed=180, .name="Saturn3 SL/2"};

  printf("Name: %s\n", saturn3.name);
  printf("Price (USD): %.2f\n", saturn3.price); // inicializado en 0.00
  printf("Speed (KM): %d\n", saturn3.speed);

  section("Copiar Struct");
  // Solo debemos asignar una struct a otra...
  struct car saturn4;

  saturn4 = saturn;

  if (saturn4.name == saturn.name)
    printf("saturn 4 es igual a saturn\n");
  else
    printf("son diferentes!\n");

  return 0;
}

void section(char *msj){
  printf("\n----- %s -----\n", msj);
}
