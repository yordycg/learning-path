/* -----------------------------------------------------------------------------
 * @title   Big O — medir la complejidad empíricamente
 * @phase   learning-dsa · S6 D1 (nivel 1)
 * -----------------------------------------------------------------------------
 * @learn
 *   - (completar al cierre: qué aprendiste hoy)
 * @open_questions
 *   - (completar: qué te quedó dudando)
 * @connect_with
 *   - MOC - DSA
 *   - DSA - Dynamic Array (mañana: crecimiento amortizado)
 * -----------------------------------------------------------------------------
 * @attempt
 *   probé:    (qué escribiste antes de mirar cualquier recurso)
 *   esperaba: (qué pensaste que iba a pasar)
 *   pasó:     (qué pasó en realidad)
 * -------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

#define N 1000

int main(void) {
    long ops_o_1   = 0;  /* O(1)    : constante  */
    long ops_o_n   = 0;  /* O(n)    : lineal     */
    long ops_o_n_2 = 0;  /* O(n^2)  : cuadrática */

    /* TODO 1 — O(1): hacé que ops_o_1 valga 1 para cualquier N
     *         (no debe depender de N). */

    /* TODO 2 — O(n): hacé que ops_o_n se DUPLIQUE cuando N se duplica
     *         (que quede proporcional a N). */

    /* TODO 3 — O(n^2): hacé que ops_o_n_2 se CUADRIPLIQUE cuando N se duplica
     *         (que quede proporcional a N*N). */

    printf("N = %d\n", N);
    printf("O(1)   ops = %ld\n", ops_o_1);
    printf("O(n)   ops = %ld\n", ops_o_n);
    printf("O(n^2) ops = %ld\n", ops_o_n_2);
    return EXIT_SUCCESS;
}
