#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define ONE_SECOND 1
#define ONE_MINUTE 60
#define ONE_HOUR 3600
#define ONE_DAY 86400
#define ONE_YEAR 31536000

#define STR_LEN 100

int intLen(int n) {
  int i = 0;
  while(n/10 > 0) {
    n /= 10;
    i++;
  }
  return i;
}

void intToStr(char *str, int *i, int n) {
  for(int j = intLen(n); j >= 0; --j) {
    str[(*i)++] = '0' + n / pow(10, j);
    n %= ((int) pow(10, j));
  }
  return;
}

void copyStr(char *str1, int *i, char *str2) {
  if(str2 == NULL)
    return;
  while(*str2 != '\0')
    str1[(*i)++] = *(str2++);
  return;
}

char *formatDuration(int n) {
  if(n == 0) {
    char *result = (char *) malloc(sizeof(char)*4);
    result[0] = 'n'; result[1] = 'o'; result[2] = 'w'; result[3] = '\0';
    return result;
  }
  int years, days, hours, minutes, seconds;
  years = days = hours = minutes = seconds = 0;
  if(n >= ONE_YEAR) {
    years = n / ONE_YEAR;
    n %= ONE_YEAR;
  }
  if(n >= ONE_DAY) {
    days = n / ONE_DAY;
    n %= ONE_DAY;
  }
  if(n >= ONE_HOUR) {
    hours = n / ONE_HOUR;
    n %= ONE_HOUR;
  }
  if(n >= ONE_MINUTE) {
    minutes = n / ONE_MINUTE;
    n %= ONE_MINUTE;
  }
  if(n >= ONE_SECOND) {
    seconds = n / ONE_SECOND;
    n %= ONE_SECOND;
  }
  char *result = (char *) malloc(sizeof(char)*STR_LEN);
  int i = 0;
  if(years) {
    intToStr(result, &i, years);
    copyStr(result, &i, years>1 ? " years" : " year");
  }
  if(days) {
    if(years && !(hours || minutes || seconds))
      copyStr(result, &i, " and ");
    else if(years)
      copyStr(result, &i, ", ");
    intToStr(result, &i, days);
    copyStr(result, &i, days>1 ? " days" : " day");
  }
  if(hours) {
    if((years || days) && !(minutes || seconds))
      copyStr(result, &i, " and ");
    else if(years || days)
      copyStr(result, &i, ", ");
    intToStr(result, &i, hours);
    copyStr(result, &i, hours>1 ? " hours" : " hour");
  }
  if(minutes) {
    if((years || days || hours) && !seconds)
      copyStr(result, &i, " and ");
    else if(years || days || hours)
      copyStr(result, &i, ", ");
    intToStr(result, &i, minutes);
    copyStr(result, &i, minutes>1 ? " minutes" : " minute");
  }
  if(seconds) {
    if(years || days || hours || minutes)
      copyStr(result, &i, " and ");
    intToStr(result, &i, seconds);
    copyStr(result, &i, seconds>1 ? " seconds" : " second");
  }
  result[i++] = '\0';
  return result;
}

int main(int argc, char *argv[]) {
  printf("%s\n", formatDuration(0));
  printf("%s\n", formatDuration(1));
  printf("%s\n", formatDuration(10));
  printf("%s\n", formatDuration(100));
  printf("%s\n", formatDuration(3600));
  printf("%s\n", formatDuration(120));
  printf("%s\n", formatDuration(62));
  printf("%s\n", formatDuration(3662));
}