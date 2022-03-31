#include <assert.h>

static int lastDigit(const char *a, const char *b);

int main(int argc, char *argv[]) {
  assert(lastDigit("4", "1") == 4);
  assert(lastDigit("4", "2") == 6);
  assert(lastDigit("9", "7") == 9);
  assert(lastDigit("10", "10000000000") == 0);
  assert(lastDigit(
            "1606938044258990275541962092341162602522202993782792835301376",
            "2037035976334486086268445688409378161051468393665936250636140449354381299763336706183397376")
             == 6);
  assert(lastDigit(
            "3715290469715693021198967285016729344580685479654510946723",
            "68819615221552997273737174557165657483427362207517952651")
             == 7);
  assert(lastDigit("243", "0") == 1);
  assert(lastDigit("0", "94907") == 0);
  return 0;
}

/* a^b */
static int lastDigit(const char *a, const char *b) {
  int baseLastDigit = 0, powerLastTwoDigits = 0;
  int i = 0;
  while(a[i] != '\0')
    baseLastDigit = a[i++] - '0';
  int j = 0;
  while(b[j] != '\0')
    powerLastTwoDigits = (powerLastTwoDigits % 10) * 10 + (b[j++] - '0');
  if(powerLastTwoDigits == 0 && j == 1)
    return 1;
  if(powerLastTwoDigits == 1)
    return baseLastDigit;
  switch(baseLastDigit) {
    case 0: case 1: case 5: case 6:
      return baseLastDigit;
    case 4: case 9:
      if(powerLastTwoDigits%2)
        return baseLastDigit;
      else
        return (baseLastDigit*baseLastDigit)%10;
    case 2: case 3: case 7: case 8:
      switch(powerLastTwoDigits%4) {
        case 0:
          return (baseLastDigit*baseLastDigit*baseLastDigit
                    *baseLastDigit)%10;
        case 1:
          return baseLastDigit;
        case 2:
          return (baseLastDigit*baseLastDigit)%10;
        case 3:
          return (baseLastDigit*baseLastDigit*baseLastDigit)%10;
      }
  }
  return -1;
}