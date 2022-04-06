/* https://www.codewars.com/kata/55983863da40caa2c900004e/ */
/* BRUTE-FORCE METHOD */

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
int pow10(int i) {
  int j = 0, result = 1;
  while(j++ < i)
    result *= 10;
  return result;
}

/* -1 when digits can't be rearranged to form a bigger number */
int nextBiggerNumber(int n) {
  int len = intLen(n);
  int next;

  return -1;
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