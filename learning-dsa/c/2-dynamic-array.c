/**************************************************************************************************
 * Dynami Array
 * - Este codigo va a representar el proceso de la creacion de un array
 * dinamico, para simplificar el proceso usaremos solo un tipo de dato - int.
 *************************************************************************************************/
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * struct DynamicArray - Arreglo dinamico redimensionable contiguo en memoria.
 * @data: Puntero al bufer en el heap que almacena los elementos.
 * @len: Cantidad de elementos actualmente ocupados (tamano logico).
 * @capacity: Cantidad total de slots reservados en memoria antes de requerir
 * realloc.
 *
 * Mantiene la invariante 'len <= capacity' en todo momento.
 * Cuando 'len = capacity', la estructura duplica geometricamente su capacidad.
 */
typedef struct {
  int *data;
  size_t len;
  size_t capacity;

} DynamicArray;

DynamicArray *darray_create(size_t initial_capacity);
void darray_destroy(DynamicArray *da);
bool darray_push_back(DynamicArray *da, int element);
bool darray_get(const DynamicArray *da, size_t index, int *out_value);
bool darray_set(DynamicArray *da, size_t index, int value);
bool darray_pop(DynamicArray *da, int *out_value);

int main(void) {
  DynamicArray *arr = darray_create(2);
  darray_push_back(arr, 3);
  darray_push_back(arr, 7);
  darray_push_back(arr, 6);
  darray_push_back(arr, -2);

  for (size_t i = 0; i < arr->len; i++) {
    int value = 0;
    if (darray_get(arr, i, &value)) {
      printf("Elemento [%zu]: %d\n", i, value);
    } else {
      printf("[ERROR]: Indice fuera de rango\n");
    }
  }

  darray_set(arr, 1, 99);
  int value_7 = 0;
  if (darray_get(arr, 1, &value_7)) {
    printf("\nElemento [1]: %d\n", value_7);
  } else {
    printf("[ERROR]: Indice fuera de rango\n");
  }

  int value_last = 0;
  if (darray_pop(arr, &value_last)) {
    printf("\nUltimo elemento (4): %d\n", value_last);
  }
  int value_last_2 = 0;
  if (darray_pop(arr, &value_last_2)) {
    printf("\nUltimo elemento (3): %d\n", value_last_2);
  }

  int value_999 = 0;
  if (darray_get(arr, 999, &value_999)) {
    printf("\nElemento [999]: %d\n", value_999);
  } else {
    printf("\n[ERROR]: Indice fuera de rango\n");
  }

  /* Insertar 100.000 elementos */
  for (size_t i = 0; i < 100000; i++)
    darray_push_back(arr, (int)i);

  darray_destroy(arr);

  return EXIT_SUCCESS;
}

/**
 * darray_create - Crea el arreglo dinamico.
 * @initial_capacity: Entero de capacidad inicial para el arreglo.
 *
 * Se asigna memoria para la estructura, en caso de fallo el arreglo no se crea.
 * Si nose se le pasa el parametro, se define una capacidad default de 2.
 * Se inicaliza la longitud del arreglo en 0.
 * Se asigna memoria para el contenedor de elementos, en caso de fallo el
 * arreglo no se crea.
 *
 * Return: @da estructura DynamicArray.
 * Complexity: O(1)
 */
DynamicArray *darray_create(size_t initial_capacity) {
  DynamicArray *da = malloc(sizeof(DynamicArray));
  if (!da)
    return NULL;

  da->capacity = (initial_capacity > 0) ? initial_capacity : 2;
  da->len = 0;
  da->data = malloc(da->capacity * sizeof(int));
  if (!da->data) {
    free(da);
    return NULL;
  }

  return da;
}

/**
 * darray_destroy - Destruye el arreglo dinamico.
 * @da: Puntero a la estructura DynamicArray.
 *
 * Liberar la memoria asignada para el contenedor de elementos.
 * Liberar la memoria asignada para la estructura DynamicArray.
 *
 * Return: void
 * Complexity: O(1)
 */
void darray_destroy(DynamicArray *da) {
  if (!da)
    return;

  free(da->data);
  free(da);
}

/**
 * darray_push_back - Insertar un elemento al final del arreglo dinamico.
 * @da: Puntero a la estructura DynamicArray.
 * @element: Entero a almancenar.
 *
 * Si la longitud alcanza la capacidad, duplica la capacidad (x2) mediante
 * realloc. Si realloc falla, el arreglo original no se modifica ni se pierde.
 *
 * Return: true si la inserccion fue exitosa, false si fallo la asignacion.
 * Complexity: O(1) amortizado, pero O(n) cuando hace resize.
 */
bool darray_push_back(DynamicArray *da, int element) {
  if (!da)
    return false;

  /* Crecimiento geometrico (x2):
   * - amortiza inserciones a O(1).
   * - tmp evita fugar data si realloc falla.
   */
  if (da->len >= da->capacity) {
    size_t new_capacity = da->capacity * 2;
    int *tmp = realloc(da->data, new_capacity * sizeof(int));
    if (!tmp)
      return false;
    da->data = tmp;
    da->capacity = new_capacity;
  }

  /* Insercion al final sin desplazamiento de memoria. */
  da->data[da->len++] = element;
  return true;
}

/**
 * darray_get - Obtener el valor en el indice especificado.
 * @da: Puntero al DynamicArray (const porque no se modifica).
 * @index: Posicion a consultar (tipo size_t).
 * @out_value: Puntero donde se almacenara el valor leido.
 *
 * Return: true si el indice es valido y la lectura fue exitosa; false en caso
 * contrario.
 * Complexity: O(1)
 */
/*
 * PATRON DE SISTEMAS: Punteros de Salida (Output Parameters: out_value)
 * Por que no retornar directamente 'int' en darray_get (o darray_pop)?
 *
 * 1. Ambiguedad de "Valor Magico" (In-Band Signaling):
 *    Si retornamos -1 o 0 para indicar errores de indices, que ocurre si el
 *    arreglo guarda legitimamente -1 o 0? No se podria distinguir un dato real
 *    de un error.
 * 2. C no tiene retornos multiples ni excepciones:
 *    A diferencia de Go (val, ok := ...) o Rust (Option<T>), C solo retorna un
 *    valor. Por convencion idiomatica de sistemas:
 *    - El valor de retorno (bool) se reserva para el ESTADO (true/false).
 *    - El puntero (*out_value) transporta el DATO (la carga util).
 * 3. Mecanica de Memoria ("Seguir la flecha"):
 *    - Invocador (main): Pasa la direccion de su variable local: &mi_variable.
 *    - Funcion: Usa desreferenciacion (*out_value = da->data[index]) para
 *    escribir directamente en la celda de memoria de main.
 * 4- Ergonomia de Control:
 *    Permite escribir codigo limpio y seguro en el invocador (main):
 *        int value;
 *        if (darray_get(arr, i, &value)) {
 *            // Aqui es 100% seguro usar 'value'
 *        }
 */
bool darray_get(const DynamicArray *da, size_t index, int *out_value) {
  if (!da || !out_value || index >= da->len)
    return false;

  *out_value = da->data[index];

  return true;
}

/**
 * darray_set - Actualizar el valor en el indice especificado.
 * @da: Puntero al DynamicArray.
 * @index: Posicion a actualizar (tipo size_t).
 * @value: Nuevo valor a asignar.
 *
 * Return: true si la posicion existe y fue modificada; false si esta fuera de
 * rango.
 * Complexity: O(1)
 */
bool darray_set(DynamicArray *da, size_t index, int value) {
  if (!da || index >= da->len)
    return false;

  da->data[index] = value;
  return true;
}

/**
 * darray_pop - Extrae el ultimo elemento del arreglo dinamico.
 * @da: Puntero al DynamicArray.
 * @out_value: Puntero donde se almacenara el elemento extraido.
 *
 * Decrementa la longitud logica sin liberar la capacidad reservada.
 *
 * Return: true si se extrajo un elemento; false si el arreglo estaba vacio
 * (underflow).
 * Complexity: O(1)
 */
bool darray_pop(DynamicArray *da, int *out_value) {
  if (!da || !out_value || da->len == 0)
    return false;

  *out_value = da->data[da->len - 1];
  da->len--;

  return true;
}
