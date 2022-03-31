#include <stdlib.h>   /* malloc, free */
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
void printTreeInBFSOrder();
void deleteTree();
static void recursiveDelete(node *);

void initTree(char *strTree) {
  queue *queueStart = NULL;
  queue *queueEnd = NULL;  // to speed up adding items to queue...
  queue *queuePointer = NULL;   // points to next item that is expected to be a child
  queue *tmp = NULL;
  int numOfChildren = 0;
  while(*strTree != '\0') {
    if(*strTree == '.') {
      if(queueStart == queueEnd) {  // first dot
        if(ROOT == NULL)
          ROOT = queueStart->item;
      } else if(*(strTree-1) == ' ' && numOfChildren == 1) {  // there was no child
        tmp = queueStart;
        queueStart = queueStart->nextItem;
        deleteQueueItem(tmp);
      } else {  // queueStart != queueEnd && numOfChildren > 0
        queueStart->item->children = childrenConstructor(numOfChildren);
        queueStart->item->numOfChildren = numOfChildren;
        int i;
        for(i=0; i<numOfChildren; ++i) {
          queueStart->item->children[i] = queuePointer->item;
          queuePointer = queuePointer->nextItem;
        }
        tmp = queueStart;
        queueStart = queueStart->nextItem;
        deleteQueueItem(tmp);
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
      if(numOfChildren == 1)  // set pointer to the first (== 1) child
        queuePointer = queueEnd;
    }
    // remember to:
    ++strTree;
  }
  //deleteRestOfQueueDeep(queueStart);
  while(queueStart != NULL) {
    tmp = queueStart->nextItem;
    deleteQueueItem(queueStart);
    queueStart = tmp;
  }
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

void printTreeInBFSOrder() {
  if(ROOT == NULL)
    return;
  node *dummyNode = nodeConstructor(0);   // "dummy node" to know if we're changing a level
  queue *queueStart = queueItemConstructor(dummyNode);
  queue *queueEnd = queueItemConstructor(ROOT);
  queueStart->nextItem = queueEnd;
  int i = 0;  // level of the tree
  while(queueStart->nextItem != NULL) {
    if(queueStart->item == dummyNode) {
      printf("%cOn the %d level of the tree: ", (i ? '\n' : '\0'), i);
      queueEnd->nextItem = queueItemConstructor(dummyNode);
      queueEnd = queueEnd->nextItem;
      ++i;
    }
    else {
      printf("%d ", queueStart->item->value);
      int j;
      for(j = 0; j < queueStart->item->numOfChildren; ++j) {
        queueEnd->nextItem = queueItemConstructor(queueStart->item->children[j]);
        queueEnd = queueEnd->nextItem;
      }
    }
    queue *tmp = queueStart;
    queueStart = queueStart->nextItem;
    deleteQueueItem(tmp);
  }
  recursiveDelete(dummyNode);
  deleteQueueItem(queueStart);
}

void deleteTree() {
  recursiveDelete(ROOT);
  ROOT = NULL;
  return;
}

static void recursiveDelete(node *n) {
  if(n == NULL)
    return;
  int i;
  for(i=0; i<n->numOfChildren; ++i)
    recursiveDelete(n->children[i]);
  if(n->children != NULL)
    free(n->children);
  free(n);
  return;
}