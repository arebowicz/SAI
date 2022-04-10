/* https://www.codewars.com/kata/56c04261c3fcf33f2d000534/ */
/* TESTS PASSED: 10, FAILED: ? */
/* TIME-OUT... */
/* FOR "DOUBLE" (NOT "LONG DOUBLE") TESTS PASSED: ~50 */
/* SO: POW FUNCTION IS VERY SLOW */
/* IT'S BETTER TO CREATE AN ARRAY TO LIMIT POW() FUNCTION CALLS */
/* (CALL POW() ONLY AT THE VERY BEGINNING OF THE PROCESS, AS MANY TIMES AS NEEDED)  */



#include <math.h>

double doubles(int maxk, int maxn) {
  double sum = 0.0;
  for(int k = 1; k <= maxk; ++k)
    for(int n = 1; n <= maxn; ++n)
      sum += ((1 / (double) k) * pow(n + 1, -2 * k));
  return sum;
}



#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

void assertFuzzyEquals(double act, double exp) {
  bool inrange; double merr = 1e-12; long double e;
  if(exp == 0.0)
    e = fabsl(act);
  else
    e = fabsl((act - exp) / exp);
  inrange = (e <= merr);
  if(inrange == false)
    printf("Error. Expected should be near: %1.16e, but got: %1.16e\n", exp, act);
  assert(inrange == true);
  return;
}

void test(int maxk, int maxn, double expected) {
  assertFuzzyEquals(doubles(maxk, maxn), expected);
  return;
}

void tests() {
  test(1, 10, 0.5580321939764581);
  test(10, 1000, 0.6921486500921933);
  test(10, 10000, 0.6930471674194457);
  return;
}

int main(int argc, char *argv[]) {
  tests();
  return 0;
}