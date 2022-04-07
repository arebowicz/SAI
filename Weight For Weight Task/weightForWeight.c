/* https://www.codewars.com/kata/55c6126177c9441a570000cc/ */
/* TESTS PASSED: 106, FAILED: 0 */



#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

typedef struct list {
  char *value;
  int weight;
  struct list *next;
} list;

list *listConstructor(const char *);
void listBubbleSort(list *);
char *listToStr(list *);

char *orderWeight(const char *str) {
  list *l = listConstructor(str);
  listBubbleSort(l);
  return listToStr(l);
}

#define MAX_VALUE_SIZE 20
#define MAX_STR_SIZE 250

int calculateWeight(char *str) {
  int result = 0;
  while(*str != '\0') {
    result += (*str++ - '0');
  }
  return result;
}

list *listConstructor(const char *str) {
  list *head = (list *) malloc(sizeof(list));
  if(head == NULL)
    return NULL;
  head->value = NULL;
  head->weight = -1;
  head->next = NULL;
  list *tail = NULL;
  while(*str != '\0') {
    if(*str >= '0' && *str <= '9') {
      char *value = (char *) malloc(sizeof(char) * MAX_VALUE_SIZE);
      if(value == NULL)
        break;
      int i = 0;
      while(*str >= '0' && *str <= '9')
        value[i++] = *str++;
      --str;
      value[i] = '\0';
      if(tail == NULL) {
        head->value = value;
        head->weight = calculateWeight(value);
        head->next = NULL;
        tail = head;
      } else {
        list *l = (list *) malloc(sizeof(list));
        if(l == NULL)
          break;
        l->value = value;
        l->weight = calculateWeight(value);
        l->next = NULL;
        tail->next = l;
        tail = l;
      }
    }
    ++str;
  }
  return head;
}

void swap(list *l1, list *l2) {
  if(l1 == NULL || l2 == NULL)
    return;
  char *tmpValue = NULL;
  int tmpWeight = -1;
  if(l1->weight > l2->weight
      || ( (l1->weight == l2->weight)  &&  (strcmp(l1->value, l2->value) > 0) ) ) {
    tmpValue = l1->value;
    tmpWeight = l1->weight;
    l1->value = l2->value;
    l1->weight = l2->weight;
    l2->value = tmpValue;
    l2->weight = tmpWeight;
  }
  return;
}

void listBubbleSort(list *head) {
  if(head == NULL)
    return;
  list *tmp, *i = head;
  while(i->next != NULL) {
    tmp = head;
    while(tmp->next != NULL) {
      swap(tmp, tmp->next);
      tmp = tmp->next;
    }
    i = i->next;
  }
  return;
}

char *listToStr(list *head) {
  char *str = (char *) malloc(sizeof(char) * MAX_STR_SIZE);
  if(str == NULL)
    return NULL;
  int i = 0;
  char *tmp = NULL;
  while(head != NULL) {
    tmp = head->value;
    while(*tmp != '\0') {
      str[i++] = *tmp;
      ++tmp;
    }
    head = head->next;
    if(head != NULL)
      str[i++] = ' ';
  }
  str[i] = '\0';
  return str;
}



void test(const char *str, char *exp) {
    char *act = orderWeight(str);
    if(strcmp(act, exp))
        printf("Error. Expected \n%s\n but got \n%s\n", exp, act);
    assert(!strcmp(act, exp));
    free(act); act = NULL;
}

int main(int argc, char *argv[]) {
  test((const char *)"   1   2", "1 2");
  test((const char *)"103 123 4444 99 2000", "2000 103 123 4444 99");
  test((const char *)"2000 10003 1234000 44444444 9999 11 11 22 123", "11 11 2000 10003 22 123 1234000 44444444 9999");
  test((const char *)"10003 1234000 44444444 9999 2000 123456789", "2000 10003 1234000 44444444 9999 123456789");
}