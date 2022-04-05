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
int INDEX_OF_LAST_ELEMENT = -1;

array *arrayHead = NULL;
doublyLinkedList *listHead = NULL;
doublyLinkedList *listTail = NULL;

int getElementFromArray(int);
int addElementsToArrays(int);

int dblLinear(int n) {
  if(n == 0)
    return 1;
  if(n <= (NUM_OF_ARRAYS - 1) * SINGLE_ARRAY_MAXSIZE + INDEX_OF_LAST_ELEMENT)
    return getElementFromArray(n);
  return addElementsToArrays(n);
}

int getElementFromArray(int n) {
  if(arrayHead == NULL)
    return -1;
  array *tmp = arrayHead;
  while(tmp->nextItem != NULL && n >= SINGLE_ARRAY_MAXSIZE) {
    tmp = tmp->nextItem;
    n -= SINGLE_ARRAY_MAXSIZE;
  }
  if(n > INDEX_OF_LAST_ELEMENT)
    return -1;
  return tmp->array[n];
}

array *arrayConstructor() {
  array *tmp = (array *) malloc(sizeof(array));
  if(tmp == NULL)
    return NULL;
  tmp->nextItem = NULL;
  return tmp;
}

doublyLinkedList *listConstructor(int value, doublyLinkedList *nextItem,
                                    doublyLinkedList *prevItem) {
  doublyLinkedList *tmp = (doublyLinkedList *) malloc(sizeof(doublyLinkedList));
  if(tmp == NULL)
    return NULL;
  tmp->value = value;
  tmp->nextItem = nextItem;
  tmp->prevItem = prevItem;
  return tmp;
}

void addToList(int value) {
  doublyLinkedList *tmp = listTail;
  doublyLinkedList *add = listConstructor(value, NULL, NULL);
  while(tmp->value > add->value)
    tmp = tmp->prevItem;
  if(tmp->value < add->value) {
    add->nextItem = tmp->nextItem;
    add->prevItem = tmp;
    tmp->nextItem = add;
    if(tmp == listTail)
      listTail = add;
  }
  return;
}

void addToArray(array **tmp) {
  if(INDEX_OF_LAST_ELEMENT == SINGLE_ARRAY_MAXSIZE - 1) {
    (*tmp)->nextItem = arrayConstructor();
    (*tmp) = (*tmp)->nextItem;
    INDEX_OF_LAST_ELEMENT = -1;
  }
  ++INDEX_OF_LAST_ELEMENT;
  (*tmp)->array[INDEX_OF_LAST_ELEMENT] = listHead->value;
  doublyLinkedList *l = listHead;
  listHead = listHead->nextItem;
  if(listHead != NULL)
    listHead->prevItem = NULL;
  free(l);
  return;
}

int addElementsToArrays(int n) {
  array *tmp = arrayHead;
  int numOfAddedElements = 0;
  if(arrayHead == NULL) {
    tmp = arrayHead = arrayConstructor();
    if(arrayHead == NULL)
      return -1;
  } else
    while(tmp->nextItem != NULL) {
      tmp = tmp->nextItem;
      numOfAddedElements += SINGLE_ARRAY_MAXSIZE;
    }
  if(listHead == NULL) {
    listHead = listTail = listConstructor( (INDEX_OF_LAST_ELEMENT >= 0) ?
                              tmp->array[INDEX_OF_LAST_ELEMENT] : 1, NULL, NULL);
    
  }
  numOfAddedElements += (INDEX_OF_LAST_ELEMENT + 1);
  while(numOfAddedElements <= n) {
    addToList(listHead->value * 2 + 1);
    addToList(listHead->value * 3 + 1);
    addToArray(&tmp);
    ++numOfAddedElements;
  }
  return tmp->array[INDEX_OF_LAST_ELEMENT];
}

int main(int argc, char *argv[]) {
  int n = dblLinear(10);
  n = dblLinear(20);
  n = dblLinear(30);
  n = dblLinear(50);
  return 0;
}