/* https://www.codewars.com/kata/573992c724fc289553000e95/ */
/* BRUTE-FORCE METHOD */



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

void findMin() {
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