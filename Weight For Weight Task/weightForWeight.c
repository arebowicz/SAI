/* https://www.codewars.com/kata/55c6126177c9441a570000cc/ */
/* TESTS PASSED:, FAILED: */



#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct list {
  char *value;
  int weight;
  struct list* next;
} list;

list *listConstructor(const char *);

char *orderWeight(const char *str) {
  list *l = listConstructor(str);
  listBubbleSort(l);
  return listToStr(l);
}

list *listConstructor(const char *str) {
  list *l = (list *) malloc(sizeof(list));
  if(l == NULL)
    return NULL;
  while(*str != '\0') {

  }
}



void test(const char *str, char *exp) {
    char *act = orderWeight(str);
    if(strcmp(act, exp))
        printf("Error. Expected \n%s\n but got \n%s\n", exp, act);
    free(act); act = NULL;
    assert(!strcmp(act, exp));
}

int main(int argc, char *argv[]) {
  test((const char *)"   1   2", "1 2");
  test((const char *)"103 123 4444 99 2000", "2000 103 123 4444 99");
  test((const char *)"2000 10003 1234000 44444444 9999 11 11 22 123", "11 11 2000 10003 22 123 1234000 44444444 9999");
  test((const char *)"10003 1234000 44444444 9999 2000 123456789", "2000 10003 1234000 44444444 9999 123456789");
}