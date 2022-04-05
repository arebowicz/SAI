/* https://www.codewars.com/kata/5672682212c8ecf83e000050/ */
/* TESTS PASSED: 0, FAILED: 0 */

#include <stdlib.h>

#define SINGLE_ARRAY_MAXSIZE 10000

typedef struct doublyLinkedList {
  int value;
  struct doublyLinkedList *prevItem;
  struct doublyLinkedList *nextItem;
} doublyLinkedList;

typedef struct array {
  int array[SINGLE_ARRAY_MAXSIZE];
  struct array *nextItem;
} array;

int NUM_OF_ARRAYS = 0;
int INDEX_OF_LAST_ELEMENT = 0;

array *arrayHead = NULL;
doublyLinkedList *listHead = NULL;
doublyLinkedList *listTail = NULL;

int getElementFromArray(int);

int dblLinear(int n) {
  if(n == 0)
    return 1;
  if(n <= (NUM_OF_ARRAYS - 1) * SINGLE_ARRAY_MAXSIZE + INDEX_OF_LAST_ELEMENT - 1)
    return getElementFromArray(n);
  
}

int getElementFromArray(int n) {
  if(arrayHead == NULL)
    return -1;
  array *tmp = arrayHead;
  while(tmp->nextItem != NULL && n >= SINGLE_ARRAY_MAXSIZE) {
    tmp = tmp->nextItem;
    n -= SINGLE_ARRAY_MAXSIZE;
  }
  return tmp->array[n];
}