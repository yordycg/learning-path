/*
 * - Comprar con 'clock()' el tiempo de CPU de O(n) y O(n^2).
 * - Usar n de 10000.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double loop_o_n(int elements);
double loop_o_n_2(int elements);

int main(void) {

  printf("--- Comparacion Loop O(n) vs O(n^2) ---\n");

  int cant_elements = 10000;
  double result_o_n = loop_o_n(cant_elements);
  double result_o_n_2 = loop_o_n_2(cant_elements);

  printf("\t- Loop O(n): %.6f\n", result_o_n);
  printf("\t- Loop O(n^2): %.6f\n", result_o_n_2);

  return EXIT_SUCCESS;
}

double loop_o_n(int elements) {
  clock_t start, end;
  long count = 0;

  start = clock();

  for (int i = 0; i < elements; i++) {
    count += i;
  }

  (void)count;

  end = clock();

  return (double)(end - start) / CLOCKS_PER_SEC;
}
double loop_o_n_2(int elements) {
  clock_t start, end;
  long count = 0;

  start = clock();

  for (int i = 0; i < elements; i++) {
    for (int j = i; j < elements; j++) {
      count += i + j;
    }
  }

  (void)count;

  end = clock();

  return (double)(end - start) / CLOCKS_PER_SEC;
}
