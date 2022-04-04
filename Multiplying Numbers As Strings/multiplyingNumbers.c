/* https://www.codewars.com/kata/55911ef14065454c75000062/ */

#include <stdlib.h>
#include <stdio.h>

int len(char *s) {
  int i = 0;
  while(*(s++) != '\0')
    ++i;
  return i;
}

char *multiply(char *a, char *b) {
  int alen, blen;
  alen = len(a);
  blen = len(b);
  if(alen == 0 || blen == 0)
    return "";
  char *result = (char *) malloc(sizeof(char)*(alen + blen + 1));
  if(result == NULL)
    return NULL;
  for(int i = 0; i < alen + blen; ++i)
    result[i] = '0';
  result[alen + blen] = '\0';
  int tmp, plus;
  for(int i = 0; i < alen; ++i) {
    tmp = plus = 0;
    for(int j = 0; j < blen; ++j) {
      tmp = result[i+j] - '0';
      result[i+j] = '0' + (((result[i+j] - '0') + (a[alen-1-i] - '0') * (b[blen-1-j] - '0') + plus) % 10);
      plus = ((tmp + (a[alen-1-i] - '0') * (b[blen-1-j] - '0') + plus) / 10);
    }
  }
  if(plus > 0) {
    result[alen+blen-1] = '0' + plus;
    result[alen+blen] = '\0';
  } else
    result[alen+blen-1] = '\0';
  int reslen = plus ? alen+blen-1 : alen+blen-2;
  for(int i = 0; i < reslen/2+1; ++i) {
    tmp = result[i];
    result[i] = result[reslen-i];
    result[reslen-i] = tmp;
  }
  result[reslen+1] = '\0';
  return result;
}

int main(int argc, char *argv[]) {
  //printf("%s\n", multiply("1", "1"));
  //printf("%s\n", multiply("123", "1"));
  printf("%s\n", multiply("123", "123333"));
}