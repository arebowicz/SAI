/* https://www.codewars.com/kata/55983863da40caa2c900004e/ */
/* ALL OF OVER 150 TESTS PASSED */

#include <stdlib.h>
#include <stdio.h>

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
long long power10(int i) {
  int j = 0;
  long long result = 1;
  while(j++ < i)
    result *= 10;
  return result;
}

void setArrayOfDigits(int arrayOfDigits[], int arrLen, long long number) {
  for(int i = 0; i < arrLen; ++i)
    arrayOfDigits[arrLen - 1 - i] = (number / power10(i)) % 10;
  return;
}

int findFirstSmallest(int arrayOfDigits[], int arrLen) {
  int i;
  for(i = arrLen - 1; i >= 0; --i)
    for(int j = i + 1; j < arrLen; ++j)
      if(arrayOfDigits[i] < arrayOfDigits[j])
        return i;
  return i;
}

int findFirstGreater(int arrayOfDigits[], int arrLen, int i) {
  for(int j = arrLen - 1; j > i; --j)
    if(arrayOfDigits[i] < arrayOfDigits[j])
      return j;
  return -1;
}

void swap(int arrayOfDigits[], int i1, int i2) {
  int tmp = arrayOfDigits[i1];
  arrayOfDigits[i1] = arrayOfDigits[i2];
  arrayOfDigits[i2] = tmp;
  return;
}

void bubbleSortAscending(int arrayOfDigits[], int arrLen) {
  for(int i = 0; i < arrLen - 1; ++i)
    for(int j = 0; j < arrLen - 1 - i; ++j)
      if(arrayOfDigits[j] > arrayOfDigits[j+1])
        swap(arrayOfDigits, j, j+1);
  return;
}

long long arrayToLongLong(int arrayOfDigits[], int arrLen) {
  long long result = 0;
  for(int i = 0; i < arrLen; ++i)
    result = result*10 + arrayOfDigits[i];
  return result;
}

long long nextBiggerNumber(long long n) {
  int arrLen = intLen(n);
  int *arrayOfDigits = (int *) malloc(sizeof(int) * arrLen);
  if(arrayOfDigits == NULL)
    return -1;
  setArrayOfDigits(arrayOfDigits, arrLen, n);
  int firstSmallestIndex = findFirstSmallest(arrayOfDigits, arrLen);
  if(firstSmallestIndex == -1)
    return -1;
  int firstGreaterIndex = findFirstGreater(arrayOfDigits, arrLen, firstSmallestIndex);
  swap(arrayOfDigits, firstSmallestIndex, firstGreaterIndex);
  bubbleSortAscending(&arrayOfDigits[firstSmallestIndex + 1],
                          arrLen - (firstSmallestIndex + 1));
  return arrayToLongLong(arrayOfDigits, arrLen);
}

int main(int argc, char *argv[]) {
  printf("1 -> %lld\n", nextBiggerNumber(1));
  printf("23456 -> %lld\n", nextBiggerNumber(23456));
  printf("65432 -> %lld\n", nextBiggerNumber(65432));
  printf("12 -> %lld\n", nextBiggerNumber(12));
  printf("83752037 -> %lld\n", nextBiggerNumber(83752037));
  printf("97997977 -> %lld\n", nextBiggerNumber(97997977));
  printf("324 -> %lld\n", nextBiggerNumber(324));
  printf("11276543 -> %lld\n", nextBiggerNumber(11276543));
  printf("11576543 -> %lld\n", nextBiggerNumber(11576543));
  printf("1043210 -> %lld\n", nextBiggerNumber(1043210));
  printf("9876543210 -> %lld\n", nextBiggerNumber(9876543210));
  printf("59884848459853 -> %lld\n", nextBiggerNumber(59884848459853));
}