/* https://www.codewars.com/kata/55983863da40caa2c900004e/ */
/* BRUTE-FORCE METHOD */

#include <stdlib.h>
#include <stdio.h>

/* n >= 0 */
int intLen(int n) {
  int i = 0;
  while(n/10 > 0) {
    n /= 10;
    ++i;
  }
  return i;
}

/* i >= 0 */
int power10(int i) {
  int j = 0, result = 1;
  while(j++ < i)
    result *= 10;
  return result;
}

static int number;
static int next;
static int *arrayOfDigits;
static int numLen;

void setArrayOfDigits(int array[], int number) {
  for(int i = 0; i < numLen; ++i)
    array[numLen - 1 - i] = (number / power10(i)) % 10;
  return;
}

void createNumberByRecursion(int actualRecursionLvl, int actualNumber) {
  if(actualRecursionLvl == numLen) {
    if(intLen(actualNumber) == numLen && actualNumber > number
          && actualNumber < next)
      next = actualNumber;
    return;
  }
  for(int i = 0; i < numLen; ++i)
    createNumberByRecursion(actualRecursionLvl + 1,
                            actualNumber * power10(actualRecursionLvl) + arrayOfDigits[i]);
  return;
}

/* -1 when digits can't be rearranged to form a bigger number */
int nextBiggerNumber(int n) {
  number = n;
  arrayOfDigits = (int *) malloc(sizeof(int) * intLen(number));
  if(arrayOfDigits == NULL)
    return -1;
  numLen = intLen(number);
  setArrayOfDigits(arrayOfDigits, number);
  next = number*10;
  createNumberByRecursion(0, 0);
  return next;
}

int main(int argc, char *argv[]) {
  printf("1 -> %d\n", nextBiggerNumber(1));
  printf("23456 -> %d\n", nextBiggerNumber(23456));
  printf("65432 -> %d\n", nextBiggerNumber(65432));
  printf("12 -> %d\n", nextBiggerNumber(12));
  printf("837520347 -> %d\n", nextBiggerNumber(837520347));
  printf("97997977 -> %d\n", nextBiggerNumber(97997977));
  printf("324 -> %d\n", nextBiggerNumber(324));
}