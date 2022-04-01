/* https://www.codewars.com/kata/602afedfd4a64d0008eb4e6e/ */
/* TESTS PASSED: 1686, FAILED: 0 */

#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define STR_MAX_LEN 14

enum DAYS_IN_MONTHS { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL,
                        AUG, SEP, OCT, NOV, DEC };

int DAYS[][13] = { { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
                   { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };

const char *MONTHS_NAMES[] = { "",
                               "January",
                               "February",
                               "March",
                               "April",
                               "May",
                               "June",
                               "July",
                               "August",
                               "September",
                               "October",
                               "November",
                               "December" };

/* The pointer returned will be freed */ 
char *get_day(int day, bool is_leap) {
  char *str = (char *) malloc(sizeof(char)*STR_MAX_LEN);
  int i = 1;
  while(day > DAYS[is_leap][i])
    day -= DAYS[is_leap][i++];
  int j = 0;
  while(MONTHS_NAMES[i][j] != '\0') {
    str[j] = MONTHS_NAMES[i][j];
    j++;
  }
  str[j++] = ',';
  str[j++] = ' ';
  if(day >= 10) {
    str[j++] = '0' + (day/10);
    day %= 10;
  }
  str[j++] = '0' + day;
  str[j] = '\0';
  return str;
}

/* SIMPLE TESTS */
int main(int argc, char *argv[]) {
  int d[] = {15, 41, 59, 60, 60, 365, 366};
  bool b[] = {false, false, false, false, true, false, true};
  char *e[] = {"January, 15", "February, 10", "February, 28", "March, 1",
                  "February, 29", "December, 31", "December, 31" };
  for(int i = 0; i < 7; i++) {
    char *r = get_day(d[i], b[i]);
    assert(!strcmp(r, e[i]));
    free(r);
  }
}