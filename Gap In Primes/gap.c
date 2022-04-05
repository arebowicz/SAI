/* https://www.codewars.com/kata/561e9c843a2ef5a40c0000a4/ */
/* TESTS PASSED: 61, FAILED: 0 */

#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

/* NUM_OF_PRIMES = ~~ n / (ln(n) - 1) */
/* for max_n = 1.100.000 NUM_OF_PRIMES is below 100.000 */
#define MAX_N 1100000
#define NUM_OF_PRIMES 100000

static int PRIMES[NUM_OF_PRIMES];
static int N = 0;   /* actual NUM_OF_PRIMES */
static bool isPRIMESInitialized = false;

static void initPRIMES() {
  PRIMES[0] = 2;
  int n, i, j;
  for(n = 3, i = 1; n <= MAX_N; ++n) {
    int end = (int) sqrt(n);
    for(j = 0; PRIMES[j] <= end; ++j) {
      if(n % PRIMES[j] == 0)
        break;
    }
    if(PRIMES[j] > end)
     PRIMES[i++] = n;
  }
  PRIMES[i] = 0;
  N = i;
  isPRIMESInitialized = true;
}

static enum returnIndex { PREDECESSOR, SUCCESOR };

/* searching for first PRIME >= value */
int binarySearchInPRIMES(int value, enum returnIndex which) {
  int i, j, center;
  i = 0;
  j = N-1;
  while(i <= j) {
    center = (i + j) / 2;
    if(PRIMES[center] < value)
      i = center + 1;
    else if(PRIMES[center] > value)
      j = center - 1;
    else
      return center;
  }
  if(which == PREDECESSOR) {
    if(PRIMES[i] < value)
      return i;
    else
      return i-1;
  } else {
    if(PRIMES[i] < value)
      return i+1;
    else
      return i;
  }
}

long long *gap(int g, long long m, long long n) {
  if(isPRIMESInitialized == false)
    initPRIMES();
  long long *result = (long long *) malloc(sizeof(long long)*2);
  result[0] = 0;
  result[1] = 0;
  int i = binarySearchInPRIMES(m, SUCCESOR);
  int end = binarySearchInPRIMES(n, PREDECESSOR);
  for(; i < end; ++i) {
    if(PRIMES[i+1] - PRIMES[i] == g) {
      result[0] = PRIMES[i];
      result[1] = PRIMES[i+1];
      break;
    }
  }
  return result;
}

int main(int argc, char *argv[]) {
  long long *result = gap(4, 11, 23);
  for(int i = 0; i < 10; ++i)
    printf("%d ", PRIMES[i]);
  printf("\nN = %d\n", N);
  printf("%lld %lld\n", result[0], result[1]);
}