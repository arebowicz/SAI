/* https://www.codewars.com/kata/525f4206b73515bffb000b21/ */
/* TESTS PASSED: 108, FAILED: 0 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int strLen(const char *str) {
  int i = 0;
  while(*str++ != '\0')
    ++i;
  return i;
}

char *add(const char *a, const char *b) {
  int alen = strLen(a);
  int blen = strLen(b);
  if(alen < blen) {
    int cInt = alen;
    alen = blen;
    blen = cInt;
    const char *cChar = a;
    a = b;
    b = cChar;
  }
  char *result = (char *) malloc(sizeof(char) * (alen + 1 + 1));
  bool overflow = false;
  for(int i = alen, j = blen, k = 0; i > 0; --i, --j, ++k) {
    if(j > 0) {
      result[k] = '0' + ((overflow ? 1 : 0) + (a[i-1] - '0') + (b[j-1] - '0')) % 10;
      overflow = ((overflow ? 1 : 0) + (a[i-1] - '0') + (b[j-1] - '0')) / 10;
    } else {
      result[k] = '0' + ((overflow ? 1 : 0) + (a[i-1] - '0')) % 10;
      overflow = ((overflow ? 1 : 0) + (a[i-1] - '0')) / 10;
    }
  }
  int reslen;
  if(overflow) {
    result[alen] = '1';
    result[alen+1] = '\0';
    reslen = alen+1;
  } else {
    result[alen] = '\0';
    reslen = alen;
  }
  char tmp;
  for(int i = 0; i < reslen/2; ++i) {
    tmp = result[i];
    result[i] = result[reslen-i-1];
    result[reslen-i-1] = tmp;
  }
  result[reslen] = '\0';
  return result;
}

int main(int argc, char *argv[]) {
  printf("%s\n", add("111", "1"));
}