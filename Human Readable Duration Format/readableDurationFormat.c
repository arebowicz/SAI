#include <stdlib.h>
#include <stdio.h>

#define ONE_SECOND 1
#define ONE_MINUTE 60
#define ONE_HOUR 3600
#define ONE_DAY 86400
#define ONE_YEAR 31536000

char *formatDuration(int n) {
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
  printf("%d %d %d %d %d\n", years, days, hours, minutes, seconds);
  return NULL;
}

int main(int argc, char *argv[]) {
  formatDuration(0);
  formatDuration(1);
  formatDuration(3600);
  formatDuration(120);
  formatDuration(62);
  formatDuration(3662);
}