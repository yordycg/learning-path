/*
 * Dynamic Note Recording:
 *
 * Pseudocode:
 *
 * MAIN:
 *  ALLOCATE notes[sizeof(float)]; // memoria para la 1era nota
 *  // Proteccion contra NULL
 *  VAR INT count = 0; // notas GUARDADAS
 *  VAR INT capacity = 1; // notas que CABEN (N bytes / sizeof(float))
 *  VAR FLOAT tmp_note;
 *
 *  PRINT "Indique sus notas a continuacion:";
 *  PRINT "PD: Para terminar debe ingresar un '-1'.";
 *
 *  DO
 *      PRINT "Indique su nota: ";
 *      READ buffer -> sscanf -> tmp_note;
 *
 *      // fin de los inputs...
 *      IF fgets devuelve NULL (EOF/Ctrl+D) THEN:
 *          BREAK;
 *
 *      IF sscanf no parsea (garbage) THEN:
 *          PRINT "ERROR";
 *          CONTINUE;
 *
 *      IF tmp_note == -1 THEN:
 *          BREAK;
 *
 *      // Guardia de rango: solo notas validas entran al array
 *      IF tmp_note < 0.0 OR tmp_note > 7.0 THEN:
 *          PRINT "ERROR";
 *          CONTINUE;
 *
 *      // Como sabe el programa que la memoria esta llena?
 *      // El bloque esta lleno cuando: count == capacity
 *      // Invariante: count <= capacity -> no podemos almacenar otra nota
 *      // Bloque lleno -> aumentar -> 1 -> 2 -> 4 -> 8...
 *      IF count == capacity THEN:
 *          capacity = capacity * 2
 *          REALLOCATE notes, (capacity * sizeof(float));
 *          // tmp pointer + NULL-check (nunca usar el puntero original)
 *      END IF
 *
 *      notes[count] = tmp_note;
 *      count++;
 *  WHILE 1; // loop infinito; la salida es por break
 *
 *  VAR FLOAT sum_notes = 0.0;
 *  FOR i=0 TO count-1:
 *      sum_notes =  sum_notes + notes[i];
 *  END FOR
 *
 *  IF count == 0 THEN;
 *      PRINT "No se ingresaron notas!";
 *      DEALLOCATE notes;
 *      RETURN 1;
 *  END IF
 *
 *  VAR FLOAT avg_notes;
 *  avg_notes = sum_notes / count;
 *  PRINT "Tu promedio es: ", avg_notes;
 *
 *  DEALLOCATE notes;
 *
 *  RETURN 0;
 * END MAIN
 *
 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // NULL-check obligatorio: malloc puede fallar y desreferenciar NULL es UB.
    // Patron: asignar y verificar en una sola expresion.
    float *notes = NULL;
    if ((notes = malloc(sizeof(float))) == NULL) {
        printf("\n\nERROR: Al asignar memoria.\n");
        return 1;
    }

    // El heap no se recuerda a si mismo: malloc entrega bytes, no "slots".
    // capacity = cuantas caben, count = cuantas hay.
    // Invariante central: count <= capacity.
    int count = 0;    // notas guardadas
    int capacity = 1; // cuantas notas CABEN (N bytes / sizeof(float))
    float tmp_note;

    printf("Indique sus notas a continuacion:\n");
    printf("PD: Para terminar debe ingresar un '-1'.\n");

    // -- Siempre preguntarse:
    // Cual es el maximoo legitimo de mi dato que puedo tener...
    // y que pasa si el usuario excede mi suposicion?
    char buffer[32];
    do {
        printf("Indique su nota: ");
        // -- Obtener buffer -> escanear buffer para buscar
        // un valor de tipo 'float' -> almacenar valor.
        //
        // fgets(buffer, sizeof, stdin) nunca desborda (lee sizeof -1 chars).
        // Buffer fijo = una apuesta; aqui 32 basta para "7.5\n\0".
        // Alternativa real: getline() crece solo.
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (!(sscanf(buffer, "%f", &tmp_note) == 1)) {
                printf("\n\nERROR: Por favor, introducir una nota valida!\n");
                continue;
            }
        } else {
            // Aqui manejamos los casos: EOF y ctrl+d
            break;
        }

        // Bucle hasta centilena: la salida es el BREAK, no la condicion, por eso while(1).
        // EOF (Ctrl+D) -> fgets devuelve NULL -> break = fin de entrada (igual que -1).
        // sscanf sobre buffer es mas seguro que scanf directo: valida linea completa.
        //
        // -1 sirve como centilena SOLO porque esta fuera del rango valido 0-7.
        // Un centilena que colisiona con datos validos es un bug por diseno.
        if (tmp_note == -1)
            break;

        // -- Solo permitir entre 0 <= notes <= 7.0:
        //
        // Guard clause: los datos invalidos nunca entran al array.
        // Mantiene el Invariante: todo notes[i] esta en [0,7].
        if (tmp_note < 0.0 || tmp_note > 7.0) {
            printf("\n\nERROR: Ingrese notas entre 0 y 7, intente nuevamente\n");
            continue;
        }

        // -- Como saber si la memoria esta llena?
        // El bloque esta lleno cuando: count == capacity
        //
        // count == capacity -> el proximo notes[count] escribira fuera del bloque (UB).
        // Doblar amortiza el costo a O(1) promedio por nota.
        // temp pointer: si realloc falla el bloque original sigue vivo;
        // asignar directo perderia el puntero y filtraria memoria.
        if (count == capacity) {
            capacity *= 2; // 1 -> 2 -> 4 -> 8...
            float *new_notes = realloc(notes, (capacity * sizeof(float)));
            if (new_notes == NULL) {
                printf("\n\nERROR: Al reasignar la memoria.\n");
                free(notes);
                return 1;
            }
            notes = new_notes; // mas memoria
        }

        // notes[count] es el primer slot libre; count++ mantiene el invariante.
        notes[count] = tmp_note;
        count++;
    } while (1);

    float avg_note;
    float sum_notes = 0.0;
    // Recorrido sobre los count elementos validos (0...count-1).
    for (int i = 0; i < count; i++)
        sum_notes += notes[i];

    // Nunca dividir sin verificar: count == 0 -> division por cero.
    // free en TODOS los caminos de salida (disciplina anti-leak).
    if (count == 0) {
        printf("\nNo se ingresaron notas!\n");
        free(notes);
        return 1;
    }

    // sum_notes es float, count int: C promueve count a float.
    // Si ambos fueran int, 7/2 truncaria a 3, no 3.5.
    avg_note = sum_notes / count;

    printf("\nTu promedio es: %0.2f\n", avg_note);

    // Todo malloc/realloc termina en free: cierre del ciclo de vida del heap.
    free(notes);

    return 0;
}
