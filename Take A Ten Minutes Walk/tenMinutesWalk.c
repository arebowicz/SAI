/* https://www.codewars.com/kata/54da539698b8a2ad76000228/ */

#include <stdbool.h>
#include <assert.h>

static bool isValidWalk(const char *walk) {
  int ns = 0, ew = 0;
  int tenMin = 10;
  while(tenMin-- > 0 && *walk != '\0') {
    if(*walk == 'n')
      ++ns;
    else if(*walk == 's')
      --ns;
    else if(*walk == 'e')
      ++ew;
    else if(*walk == 'w')
      --ew;
    walk++;
  }
  if(!ns && !ew && tenMin == -1 && *walk == '\0')
    return true;
  else
    return false;
}

int main(int argc, char *argv[]) {
  assert(isValidWalk("nsnsnsnsns") == true);
  assert(isValidWalk("nsnsnsnsnn") == false);
  return 0;
}