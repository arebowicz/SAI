/* https://www.codewars.com/kata/54d512e62a5e54c96200019e/ */

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100

void intToStr(char *str, int *strPosition, int num) {
  int i, tmp;
  i = 1;
  tmp = num;
  while(tmp/10 > 0) {
    i++;
    tmp /= 10;
  }
  while(--i >= 0)
    str[(*strPosition)++] = '0'
          + ((num / (int) pow(10, i)) % 10);
  return;
}

void addToStr(char *str, int divisor, int nTimes, int *strPosition) {
  str[(*strPosition)++] = '(';
  intToStr(str, strPosition, divisor);
  if(nTimes >= 2) {
    str[(*strPosition)++] = '*';
    str[(*strPosition)++] = '*';
    intToStr(str, strPosition, nTimes);
  }
  str[(*strPosition)++] = ')';
  return;
}

char *factors(int num) {
  char *str = (char *) malloc(sizeof(char)*MAX_SIZE);
  int end = num;
  int divisor, nTimes, strPosition;
  int tmpNum = num;
  for(divisor = 2, nTimes = 0, strPosition = 0;
          divisor < end; ++divisor) {
    if(tmpNum % divisor == 0) {
      while(tmpNum % divisor == 0) {
        tmpNum /= divisor;
        ++nTimes;
      }
      addToStr(str, divisor, nTimes, &strPosition);
      nTimes = 0;
    }
    if(tmpNum == 1)
      break;
  }
  if(tmpNum == num) {
    addToStr(str, num, 1, &strPosition);
  }
  str[strPosition] = '\0';
  return str;
}

/* SIMPLE TESTS */
int main(int argc, char *argv[]) {
  int num[] = { 2,
                4,
                8,
                7775460,
                7919,
                17*17*93*677,
                7537*123863 };
  char *str[] = { "(2)",
                  "(2**2)",
                  "(2**3)",
                  "(2**2)(3**3)(5)(7)(11**2)(17)",
                  "(7919)",
                  "(3)(17**2)(31)(677)",
                  "(7537)(123863)" };
  for(int i = 0; i < 7; ++i) {
    char *result = factors(num[i]);
    assert(!strcmp(result, str[i]));
    free(result);
  }
}