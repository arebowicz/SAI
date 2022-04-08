/* https://www.codewars.com/kata/573992c724fc289553000e95/ */
/* BRUTE-FORCE METHOD */
/* TESTS PASSED: 113, FAILED: 0 */



#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h>

#define MAX_NUM_OF_DIGITS 19

int *arrayOfDigits;
int arrLen;
long long min;
long long minIndex;
long long insertIndex;

void setArrayOfDigits(long long n);
void findMin();

long long *smallest(long long n) {
  min = LLONG_MAX;
  setArrayOfDigits(n);
  findMin();
  free(arrayOfDigits);
  long long *result = (long long *) malloc(sizeof(long long) * 3);
  result[0] = min;
  result[1] = minIndex;
  result[2] = insertIndex;
  return result;
}

/* n >= 0 */
int longLongLen(long long n) {
  int i = 1;
  while(n / 10 > 0) {
    ++i;
    n /= 10;
  }
  return i;
}

void setArrayOfDigits(long long n) {
  arrLen = longLongLen(n);
  if(arrLen > MAX_NUM_OF_DIGITS)
    return;
  arrayOfDigits = (int *) malloc(sizeof(int) * arrLen);
  if(arrayOfDigits == NULL)
    return;
  int i = arrLen - 1;
  while(i >= 0) {
    arrayOfDigits[i--] = n % 10;
    n /= 10;
  }
  return;
}

long long getNewNumber(int i1, int i2) {
  long long result = 0LL;
  for(int i = 0; i < arrLen; ++i) {
    if(i1 == i2) {
      result = (result * 10) + arrayOfDigits[i];
    } else if(i1 < i2) {
      if(i < i1) {
        result = (result * 10) + arrayOfDigits[i];
      } else if(i >= i1 && i < i2) {
        result = (result * 10) + arrayOfDigits[i+1];
      } else if(i == i2) {
        result = (result * 10) + arrayOfDigits[i1];
      } else {  /* i > i2 */
        result = (result * 10) + arrayOfDigits[i];
      }
    } else {  /* i1 > i2 */
      if(i < i2) {
        result = (result * 10) + arrayOfDigits[i];
      } else if(i == i2) {
        result = (result * 10) + arrayOfDigits[i1];
      } else if(i > i2 && i <= i1) {
        result = (result * 10) + arrayOfDigits[i-1];
      } else {  /* i > i1 */
        result = (result * 10) + arrayOfDigits[i];
      }
    }    
  }
  return result;
}

void findMin() {
  int i, j;
  long long tmp;
  for(i = 0; i < arrLen; ++i) {
    for(j = 0; j < arrLen; ++j) {
      if((tmp = getNewNumber(i, j)) < min) {
        min = tmp;
        minIndex = i;
        insertIndex = j;
      }
    }
  }
  return;
}



void test(long long n, long long *exp) {
  long long *act = smallest(n);
  if(act[0] != exp[0] || act[1] != exp[1] || act[2] != exp[2])
    printf("Error. Expected \n{ %lld, %lld, %lld }\n but got \n{ %lld, %lld, %lld }\n",
                             exp[0], exp[1], exp[2],          act[0], act[1], act[2] );
  assert(act[0] == exp[0] && act[1] == exp[1] && act[2] == exp[2]);
  free(act); act = NULL;
  return;
}

int main(int argc, char *argv[]) {
  long long exp[][3] = { { 126235LL, 2LL, 0LL }, 
                         { 29917LL, 0LL, 1LL },
                         { 238565LL, 3LL, 1LL },
                         { 239687LL, 4LL, 1LL } };
  test(261235, exp[0]);
  test(209917, exp[1]);
  test(285365, exp[2]);
  test(296837, exp[3]);
  return 0;
}