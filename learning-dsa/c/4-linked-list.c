/**************************************************************************************************
 * Doubly Linked List
 * - Este código representa la creación de una lista doblemente enlazada en C
 *   con operaciones en ambos extremos. Para simplificar, usamos tipo int.
 *************************************************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * struct Node - Nodo individual de la lista doblemente enlazada.
 * @data: Valor entero almacenado en el nodo.
 * @prev: Puntero al nodo anterior en la secuencia (NULL si es la cabeza).
 * @next: Puntero al nodo siguiente en la secuencia (NULL si es la cola).
 */
typedef struct Node {
  int data;
  struct Node *prev;
  struct Node *next;
} Node;

/**
 * struct LinkedList - Estructura controladora de la lista doblemente enlazada.
 * @head: Puntero al primer nodo de la lista.
 * @tail: Puntero al último nodo de la lista.
 * @size: Cantidad de elementos actualmente presentes en la lista.
 */
typedef struct {
  Node *head;
  Node *tail;
  size_t size;
} LinkedList;

LinkedList *list_create(void);
void list_destroy(LinkedList *list);

bool list_push_front(LinkedList *list, int value);
bool list_push_back(LinkedList *list, int value);

size_t list_len(const LinkedList *list);
bool list_is_empty(const LinkedList *list);

int main(void) {

  LinkedList *list = list_create();

  list_push_front(list, 33);
  list_push_front(list, 7);
  list_push_front(list, 8);
  list_push_back(list, 9);

  printf("--- Size Linked List ---\n");
  printf("\tsize: %zu\n", list_len(list));

  Node *trav = list->head;

  printf("--- Traverse Linked List ---\n");
  while (trav != NULL) {
    printf("%d\n", trav->data);

    trav = trav->next;
  }

  list_destroy(list);

  return EXIT_SUCCESS;
}

/**
 * list_create - Crea e inicializa una lista doblemente enlazada vacía.
 *
 * Reserva memoria en el heap para la estructura controladora LinkedList.
 * Inicializa head y tail en NULL y size en 0.
 *
 * Return: Puntero a la estructura LinkedList creada, o NULL si falla malloc.
 * Complexity: O(1)
 */
LinkedList *list_create(void) {
  LinkedList *list = malloc(sizeof(LinkedList));
  if (!list)
    return NULL;

  list->head = NULL;
  list->tail = NULL;
  list->size = 0;

  return list;
}

/**
 * list_destroy - Libera toda la memoria ocupada por la lista y sus nodos.
 * @list: Puntero a la estructura LinkedList.
 *
 * Recorre la lista de inicio a fin liberando cada struct Node secuencialmente.
 * Finalmente libera la estructura controladora LinkedList.
 *
 * Return: void
 * Complexity: O(n)
 */
void list_destroy(LinkedList *list) {
  if (!list)
    return;

  Node *trav = list->head;
  while (trav != NULL) {
    Node *next = trav->next;
    free(trav);
    trav = next;
  }

  free(list);
}

/**
 * list_push_front - Inserta un nuevo elemento al inicio de la lista (cabeza).
 * @list: Puntero a la estructura LinkedList.
 * @value: Valor entero a almacenar en el nuevo nodo.
 *
 * Reserva memoria para un nuevo Node y lo enlaza antes de head.
 * Si la lista estaba vacía, head y tail apuntan al nuevo nodo.
 *
 * Return: true si la inserción fue exitosa, false si falló la asignación o list es NULL.
 * Complexity: O(1)
 */
bool list_push_front(LinkedList *list, int value) {
  if (!list)
    return false;

  Node *node = malloc(sizeof(Node));
  if (!node)
    return false;

  node->data = value;
  node->prev = NULL;
  node->next = list->head;

  if (list->head != NULL) {
    list->head->prev = node;
  } else {
    list->tail = node;
  }

  list->head = node;
  list->size++;
  return true;
}

/**
 * list_push_back - Inserta un nuevo elemento al final de la lista (cola).
 * @list: Puntero a la estructura LinkedList.
 * @value: Valor entero a almacenar en el nuevo nodo.
 *
 * Reserva memoria para un nuevo Node y lo enlaza después de tail.
 * Si la lista estaba vacía, head y tail apuntan al nuevo nodo.
 *
 * Return: true si la inserción fue exitosa, false si falló la asignación o list es NULL.
 * Complexity: O(1)
 */
bool list_push_back(LinkedList *list, int value) {
  if (!list)
    return false;

  Node *node = malloc(sizeof(Node));
  if (!node)
    return false;

  node->data = value;
  node->prev = list->tail;
  node->next = NULL;

  if (list->tail != NULL) {
    list->tail->next = node;
  } else {
    list->head = node;
  }

  list->tail = node;
  list->size++;
  return true;
}

/**
 * list_len - Obtiene la cantidad actual de nodos en la lista.
 * @list: Puntero de solo lectura a la estructura LinkedList.
 *
 * Return: Cantidad de elementos (size), o 0 si list es NULL.
 * Complexity: O(1)
 */
size_t list_len(const LinkedList *list) {
  if (!list)
    return 0;

  return list->size;
}

/**
 * list_is_empty - Verifica si la lista no contiene elementos.
 * @list: Puntero de solo lectura a la estructura LinkedList.
 *
 * Return: true si la lista está vacía o es NULL, false en caso contrario.
 * Complexity: O(1)
 */
bool list_is_empty(const LinkedList *list) {
  if (!list)
    return false;

  if (list->head == NULL && list->tail == NULL && list->size == 0)
    return true;

  return false;
}
