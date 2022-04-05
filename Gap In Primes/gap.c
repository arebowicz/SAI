/* https://www.codewars.com/kata/561e9c843a2ef5a40c0000a4/ */

#include <stdbool.h>
#include <math.h>

#include <stdio.h>

/* NUM_OF_PRIMES = ~~ n / (ln(n) - 1) */
/* for max_n = 1.100.000 NUM_OF_PRIMES is below 100.000 */
#define MAX_N 1100000
#define NUM_OF_PRIMES 100000

static int PRIMES[NUM_OF_PRIMES];
static int N = 0;
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

long long *gap(int g, long long m, long long n) {
  if(isPRIMESInitialized == false)
    initPRIMES();
  return NULL;
}

int main(int argc, char *argv[]) {
  gap(0, 0, 0);
  for(int i = 0; i < 10; ++i)
    printf("%d ", PRIMES[i]);
}