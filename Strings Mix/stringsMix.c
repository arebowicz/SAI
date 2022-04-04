/* https://www.codewars.com/kata/5629db57620258aa9d000014/ */
/* TESTS PASSED: 68, FAILED: 0 */

#include <stdlib.h>
#include <string.h>
#include <assert.h>

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
                && newItem->fromWhich < tmp->fromWhich)
          || (newItem->numOfOccurrences == tmp->numOfOccurrences
                && newItem->fromWhich == tmp->fromWhich
                && newItem->letter < tmp->letter)  )
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
  while(*str1 != '\0') {
    if(*str1 >= 'a' && *str1 <= 'z')
      ++countS1[*str1 - 'a'];
    ++str1;
  }
  while(*str2 != '\0') {
    if(*str2 >= 'a' && *str2 <= 'z')
      ++countS2[*str2 - 'a'];
    ++str2;
  }
  return;
}

void listToStr(list *l, char *str, int len) {
  int i = 0;
  while(l != NULL) {
    if(l->fromWhich == FIRST)
      str[i++] = '1';
    else if(l->fromWhich == SECOND)
      str[i++] = '2';
    else
      str[i++] = '=';
    str[i++] = ':';
    for(int j = 0; j < l->numOfOccurrences; ++j)
      str[i++] = l->letter;
    str[i++] = '/';
    l = l->nextItem;
  }
  str[len-1] = '\0';
}

char *mix(char *str1, char *str2) {
  int countS1[NUM_OF_LETTERS];
  int countS2[NUM_OF_LETTERS];
  for(int i = 0; i < NUM_OF_LETTERS; ++i)
    countS1[i] = countS2[i] = 0;
  frequencyOfEachLowercaseLetter(str1, countS1, str2, countS2);
  list *l = NULL;
  int n = 0;
  for(int i = 0; i < NUM_OF_LETTERS; ++i)
    if(countS1[i] > countS2[i] && countS1[i] > 1) {
      addToList(&l, 'a'+i, countS1[i], FIRST);
      n += countS1[i] + 1 + 1 + 1;  /* 1 for '1'/'2' char  and  1 for ':' char  and  1 for '/' char */
    } else if(countS1[i] < countS2[i] && countS2[i] > 1) {
      addToList(&l, 'a'+i, countS2[i], SECOND);
      n += countS2[i] + 1 + 1 + 1;
    } else if(countS1[i] == countS2[i] && countS1[i] > 1) {
      addToList(&l, 'a'+i, countS1[i], BOTH);
      n += countS1[i] + 1 + 1 + 1;
    }
  if(n == 0)
    return "";
  char *result = (char *) malloc(sizeof(char)*n);
  if(result == NULL)
    return NULL;
  listToStr(l, result, n);
  return result;
}

int main(int argc, char *argv[]) {
  char s1[][100] = { "Are they here",
                     "looping is fun but dangerous",
                     " In many languages" };
  char s2[][100] = { "yes, they are here",
                     "less dangerous than coding",
                     " there's a pair of functions" };
  char out[][100] = { "2:eeeee/2:yy/=:hh/=:rr",
                      "1:ooo/1:uuu/2:sss/=:nnn/1:ii/2:aa/2:dd/2:ee/=:gg",
                      "1:aaa/1:nnn/1:gg/2:ee/2:ff/2:ii/2:oo/2:rr/2:ss/2:tt" };
  for(int i = 0; i < 3; ++i) {
    char *result = mix(s1[i], s2[i]);
    assert(!strcmp(result, out[i]));
    free(result);
  }
}