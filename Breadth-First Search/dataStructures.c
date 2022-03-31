#include <stdlib.h>
#include "dataStructures.h"

/* declaration for queue structure */
typedef struct node node;

/* queue structure for algorithms */
typedef struct queue {
  node *item;
  struct queue *nextItem;
} queue;

/* tree node */
typedef struct node {
  int value;
  int numOfChildren;    // to avoid the necessity of creating "dummy nodes" at the end of children array
  struct node **children;
} node;

node *ROOT = NULL;

void initTree(char *);
static node **childrenConstructor(int);
static queue *strToInt(char **);
static node *nodeConstructor(int);
static queue *queueItemConstructor(node *);
static queue *queueAndNodeConstructor(int);
static void deleteQueueItem(queue *);
static void deleteQueueItemDeep(queue *);
static void deleteRestOfQueueDeep(queue *);
void printTreeInBFSOrder();
void deleteTree();

void initTree(char *strTree) {
  queue *queueStart = NULL;
  queue *queueEnd = NULL;  // to speed up adding items to queue...
  queue *queuePointer = NULL;
  int numOfChildren = 0;
  while(*strTree != '\0') {
    if(*strTree == '.') {
      if(queueStart == queueEnd) {  // first dot
        if(ROOT == NULL)
          ROOT = queueStart->item;
      } else if(*(strTree-1) == ' ' && numOfChildren == 1) {
        queueStart = queueStart->nextItem;
      } else {  // queueStart != queueEnd && numOfChildren > 0
        queueStart->item->children = childrenConstructor(numOfChildren);
        queueStart->item->numOfChildren = numOfChildren;
        if(queueStart == queuePointer)
          queuePointer = queueStart->nextItem;
        int i;
        for(i=0; i<numOfChildren; ++i) {
          queueStart->item->children[i] = queuePointer->item;
          //printf("%d\n", queueStart->item->children[i]->value);
          queuePointer = queuePointer->nextItem;
        }
        queue *tmp = queueStart;
        queueStart = queueStart->nextItem;
        //deleteQueueItemDeep(tmp);
      }
      numOfChildren = 0;
    } else if(*strTree == ' ') {
      ++numOfChildren;
    } else {  // *strTree >= '0' && *strTree <= '9'
      if(queueStart == NULL) {
        queueStart = queueEnd = strToInt(&strTree);
        queuePointer = queueStart;
      } else {
        queueEnd->nextItem = strToInt(&strTree);
        queueEnd = queueEnd->nextItem;
      }
      if(numOfChildren == 1)
        queuePointer = queueEnd;
    }
    // remember to:
    ++strTree;
  }
  //deleteRestOfQueueDeep(queueStart);
}

static node **childrenConstructor(int numOfChildren) {
  node **children = (node **) malloc(sizeof(node *)*numOfChildren);
  if(children == NULL)
    return NULL;
  while(--numOfChildren >= 0)
    children[numOfChildren] = NULL;
  return children;
}

static queue *strToInt(char **strTree) {
  queue *tmp = NULL;
  int value = 0;
  while(**strTree >= '0' && **strTree <= '9') {
    value = value * 10 + (**strTree - '0');
    ++(*strTree);
  }
  --(*strTree);
  tmp = queueAndNodeConstructor(value);
  return tmp;
}

static node *nodeConstructor(int value) {
  node *tmp = (node *) malloc(sizeof(node));
  if(tmp == NULL)
    return NULL;
  tmp->value = value;
  tmp->numOfChildren = 0;
  tmp->children = NULL;
  return tmp;
}

static queue *queueItemConstructor(node *n) {
  queue *tmp = (queue *) malloc(sizeof(queue));
  if(tmp == NULL)
    return NULL;
  tmp->item = n;
  tmp->nextItem = NULL;
  return tmp;
}

static queue *queueAndNodeConstructor(int value) {
  queue *tmp = (queue *) malloc(sizeof(queue));
  if(tmp == NULL)
    return NULL;
  tmp->item = nodeConstructor(value);
  tmp->nextItem = NULL;
  return tmp;
}

static void deleteQueueItem(queue *qItem) {
  if(qItem != NULL)
    free(qItem);
  return;
}

static void deleteQueueItemDeep(queue *qItem) {
  if(qItem != NULL)
    free(qItem->item);
  free(qItem);
  return;
}

static void deleteRestOfQueueDeep(queue *qItem) {
  if(qItem == NULL)
    return;
  queue *tmp = NULL;
  while(qItem != NULL) {
    tmp = qItem->nextItem;
    deleteQueueItemDeep(qItem);
    qItem = tmp;
  }
  return;
}

void simpleRecursiveTreePrint(node *n) {
  if(n == NULL)
    return;
  printf("value %d (num of children: %d)\n", n->value, n->numOfChildren);
  int i;
  for(i=0; i<n->numOfChildren; ++i)
    simpleRecursiveTreePrint(n->children[i]);
  return;
}

void printTreeInSimpleWay() {
  simpleRecursiveTreePrint(ROOT);
  return;
}

void printTreeInBFSOrder() {
  if(ROOT == NULL)
    return;
  node *dummyNode = nodeConstructor(0);
  queue *queueStart = queueItemConstructor(dummyNode);
  queue *queueEnd = queueItemConstructor(ROOT);
  queueStart->nextItem = queueEnd;
  int i = 0;
  queue *tmp;
  while(queueStart->nextItem != NULL) {
    if(queueStart->item == dummyNode) {
      printf("%cOn the %d level of the tree: ", (i ? '\n' : '\0'), i);
      // ?
      queueEnd->nextItem = queueItemConstructor(dummyNode);
      queueEnd = queueEnd->nextItem;
      if(i == 0) {
        int j = 0;
        while(j < queueEnd->item->numOfChildren) {
          queueEnd->nextItem = queueItemConstructor(queueEnd->item->children[j]);
          queueEnd = queueEnd->nextItem;
          ++j;
        }
      }
      ++i;
    }
    else {
      printf("%d ", queueStart->item->value);
      int j = 0;
      while(j < queueStart->item->numOfChildren) {
        queueEnd->nextItem = queueItemConstructor(queueStart->item->children[j]);
        //printf("\nin while: %d ", queueStart->item->children[j]->value);
        queueEnd = queueEnd->nextItem;
        ++j;
      }
    }
    tmp = queueStart;
    queueStart = queueStart->nextItem;
    //deleteQueueItem(tmp);
  }
}

void deleteTree() {
  ROOT = NULL;
  return;
}