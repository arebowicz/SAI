/* https://www.codewars.com/kata/5629db57620258aa9d000014/ */

#include <stdlib.h>

#define NUM_OF_LETTERS 26

enum which { FIRST, SECOND, BOTH };

typedef struct list {
  char letter;
  int numOfOccurrences;
  enum which fromWhich;
  struct list *nextItem;
} list;

void addToList(list **l, char letter, int numOfOccurrences,
                    enum which fromWhich) {
  list *newItem = (list *) malloc(sizeof(list));
  if(newItem == NULL)
    return;
  newItem->letter = letter;
  newItem->numOfOccurrences = numOfOccurrences;
  newItem->fromWhich = fromWhich;
  newItem->nextItem = NULL;
  if(*l == NULL) {
    *l = newItem;
    return;
  }
  list *prev, *tmp;
  prev = NULL;
  tmp = *l;
  while(tmp != NULL) {
    if(newItem->numOfOccurrences > tmp->numOfOccurrences
          || (newItem->numOfOccurrences == tmp->numOfOccurrences
                && newItem->letter > tmp->letter)  )
      break;
    prev = tmp;
    tmp = tmp->nextItem;
  }
  if(prev == NULL) {
    newItem->nextItem = *l;
    *l = newItem;
  } else {
    newItem->nextItem = prev->nextItem;
    prev->nextItem = newItem;
  }
  return;
}

void frequencyOfEachLowercaseLetter(char *str1, int countS1[],
                                    char *str2, int countS2[]) {
  while(*str1 != '\0')
    if(*str1 >= 'a' && *str1 <= 'z')
      ++countS1[*(str1++) - 'a'];
  while(*str2 != '\0')
    if(*str2 >= 'a' && *str2 <= 'z')
      ++countS2[*(str2++) - 'a'];
  return;
}

char *mix(char *str1, char *str2) {
  int countS1[NUM_OF_LETTERS];
  int countS2[NUM_OF_LETTERS];
  for(int i = 0; i < NUM_OF_LETTERS; ++i)
    countS1[i] = countS2[i] = 0;
  frequencyOfEachLowercaseLetter(str1, countS1, str2, countS2);
  list *l = NULL;
  for(int i = 0; i < NUM_OF_LETTERS; ++i)
    if(countS1[i] > countS2[i] && countS1[i] > 1)
      addToList(&l, 'a'+i, countS1[i], FIRST);
    else if(countS1[i] < countS2[i] && countS2[i] > 1)
      addToList(&l, 'a'+i, countS2[i], SECOND);
    else if(countS1[i] == countS2[i] && countS1[i] > 1)
      addToList(&l, 'a'+i, countS1[i], BOTH);
  
}