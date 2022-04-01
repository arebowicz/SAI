/* https://www.codewars.com/kata/622de76d28bf330057cd6af8/ */
/* TESTS PASSED: 108, FAILED: 0 */

#include <assert.h>
#include <math.h>

unsigned amountOfPages(unsigned summary) {
  unsigned n = 1, sum = 0, tmpSum = 0;
  while(tmpSum < summary) {
    sum = tmpSum;
    tmpSum += (n * 9 * (unsigned) pow(10, n-1));
    ++n;
  }
  unsigned m = (summary - sum)/(n-1);
  unsigned result = 0, i = 0;
  while(++i < n-1)
    result += (9 * (unsigned) pow(10, i-1));
  result += m;
  return result;
}

/* SIMPLE TESTS */
int main(int argc, char *argv[]) {
  unsigned summary[] = { 5,
                         25,
                         1095,
                         185,
                         660 };
  unsigned expected[] = { 5,
                          17,
                          401,
                          97,
                          256 };
  for(int i = 0; i < 5; ++i) {
    unsigned result = amountOfPages(summary[i]);
    assert(result == expected[i]);
  }
}