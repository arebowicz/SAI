#include <stdio.h>
#include <stdbool.h>

#define MAX 1000000

static bool narcissistic(int);

int main(int argc, char *argv[]) {
  int i = 0;
  while(i<=MAX) {
    if(narcissistic(i))
      printf("%d ", i);
    i++;
  }
  return 0;
}

/*  number >= 0  */
static int numOfDigits(int number) {
  int n = 1;
  while(number /= 10)
    ++n;
  return n;
}

/*  number >= 0  */
/*  n >= 1       */
static int power(int number, int n) {
  int tmp = number;
  while(--n)
    tmp *= number;
  return tmp;
}

/*  number >= 0  */
static bool narcissistic(int number) {
  int n = numOfDigits(number);
  int i = number;
  int sum = 0;
  do {
    sum += power(i%10, n);
  } while(i /= 10);
  if(number == sum)
    return true;
  else
    return false;
}