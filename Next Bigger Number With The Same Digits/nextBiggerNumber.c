/* https://www.codewars.com/kata/55983863da40caa2c900004e/ */
/* BRUTE-FORCE METHOD */
/* TO OBSERVE SOME DEPENDENCIES AND PROPERTIES */
/* AND ALSO TO TRAIN PROGRAMMING SKILL */
/* BASIC TESTS - OK */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/* n >= 0 */
int intLen(long long n) {
  int i = 1;
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

static long long number;
static int numLen;
static long long next;
static int *arrayOfDigits;

void setArrayOfDigits() {
  for(int i = 0; i < numLen; ++i)
    arrayOfDigits[numLen - 1 - i] = (number / power10(i)) % 10;
  return;
}

/* number >= 0 */
bool isDigitProper(int digit, long long number) {
  int i = 0;
  while(number/10 > 0) {
    if(number % 10 == digit)
      ++i;
    number /= 10;
  }
  if(number % 10 == digit)
    ++i;
  int j = 0;
  for(int k = 0; k < numLen; ++k)
    if(arrayOfDigits[k] == digit)
      ++j;
  if(i < j)
    return true;
  else
    return false;
}

void createNumberByRecursion(int actualRecursionLvl, long long actualNumber) {
  if(actualRecursionLvl == numLen) {
    if(intLen(actualNumber) == numLen && actualNumber > number
          && actualNumber < next)
      next = actualNumber;
    return;
  }
  for(int i = 0; i < numLen; ++i) {
    if(isDigitProper(arrayOfDigits[i], actualNumber))
      createNumberByRecursion(actualRecursionLvl + 1,
                                actualNumber * 10 + arrayOfDigits[i]);
  }
  return;
}

/* -1 when digits can't be rearranged to form a bigger number */
long long nextBiggerNumber(long long n) {
  number = n;
  numLen = intLen(number);
  arrayOfDigits = (int *) malloc(sizeof(int) * numLen);
  if(arrayOfDigits == NULL)
    return -1;
  setArrayOfDigits();
  next = number*10;
  createNumberByRecursion(0, 0);
  if(next == number*10)
    return -1;
  else
    return next;
}

int main(int argc, char *argv[]) {
  printf("1 -> %lld\n", nextBiggerNumber(1));
  printf("23456 -> %lld\n", nextBiggerNumber(23456));
  printf("65432 -> %lld\n", nextBiggerNumber(65432));
  printf("12 -> %lld\n", nextBiggerNumber(12));
  printf("83752037 -> %lld\n", nextBiggerNumber(83752037));
  printf("97997977 -> %lld\n", nextBiggerNumber(97997977));
  printf("324 -> %lld\n", nextBiggerNumber(324));
}