/*
 *
 */
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
  int *data;
  size_t len;
  size_t capacity;
} DynamicArray;

DynamicArray *darray_create(size_t initial_capacity);
void darray_destroy(DynamicArray *da);
bool darray_push_back(DynamicArray *da, int element);
bool darray_push_front(DynamicArray *da, int element);

double benchmark_push_back(size_t n);
double benchmark_push_front(size_t n);

int main(void) {

  size_t n = 30000;

  printf("--- Comparacion Insercion Dynamic Array (n = %zu)---\n", n);

  double time_back = benchmark_push_back(n);
  double time_front = benchmark_push_front(n);

  printf("\t- Push Back [O(1) amortizado]:          %.6f segundos\n",
         time_back);
  printf("\t- Push Front [O(n) por desplazamiento]: %.6f segundos\n",
         time_front);
  printf("\t- Penalizacion:                         %.1fx mas lento\n",
         time_front / time_back);

  return EXIT_SUCCESS;
}

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

void darray_destroy(DynamicArray *da) {
  if (!da)
    return;

  free(da->data);
  free(da);
}

bool darray_push_back(DynamicArray *da, int element) {
  if (!da)
    return false;

  if (da->len >= da->capacity) {
    size_t new_capacity = da->capacity * 2;
    int *tmp = realloc(da->data, new_capacity * sizeof(int));
    if (!tmp)
      return false;

    da->data = tmp;
    da->capacity = new_capacity;
  }

  da->data[da->len++] = element;

  return true;
}

/**
 * darray_push_front - Insertar un elemento en la posicion 0 desplazando el
 * resto.
 * @da: Puntero al DynamicArray.
 * @element: Valor a insertar al inicio.
 *
 * Si len == capacity, duplica la capacidad usando realloc.
 * Si el arreglo no esta vacio, desplaza los elementos hacia la derecha:
 *     memmove(&da->data[1], &da->data[0], da->len * sizeof(int));
 * Luego coloca el elemento en da->data[0] e incrementa da->len.
 *
 * Retorna: true si la inserccion fue exitosa; false si fallo la asignacion.
 * Complexity: O(n)
 */
bool darray_push_front(DynamicArray *da, int element) {
  if (!da)
    return false;

  if (da->len >= da->capacity) {
    size_t new_capacity = da->capacity * 2;
    int *tmp = realloc(da->data, new_capacity * sizeof(int));
    if (!tmp)
      return false;

    da->data = tmp;
    da->capacity = new_capacity;
  }

  if (da->len > 0) {
    memmove(&da->data[1], &da->data[0], da->len * sizeof(int));
  }

  da->data[0] = element;
  da->len++;

  return true;
}

double benchmark_push_back(size_t n) {
  clock_t start, end;
  start = clock();

  DynamicArray *da = darray_create(2);

  for (size_t i = 0; i < n; i++)
    darray_push_back(da, i);

  darray_destroy(da);

  end = clock();
  return (double)(end - start) / CLOCKS_PER_SEC;
}

double benchmark_push_front(size_t n) {
  clock_t start, end;
  start = clock();

  DynamicArray *da = darray_create(2);

  for (size_t i = 0; i < n; i++)
    darray_push_front(da, i);

  darray_destroy(da);

  end = clock();
  return (double)(end - start) / CLOCKS_PER_SEC;
}
