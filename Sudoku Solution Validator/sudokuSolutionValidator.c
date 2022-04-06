/* https://www.codewars.com/kata/529bf0e9bdf7657179000008/ */
/* TESTS PASSED: 8, FAILED: 0 */

#include <stdbool.h>

bool validSolution(unsigned int board[9][9]) {
  int sum, sum1, sum2, sum3;
  sum1 = sum2 = sum3 = 0;
  for(int i = 0; i < 9; ++i) {
    sum = 0;
    for(int j = 0; j < 9; ++j) {
      sum += board[i][j];
      if(j < 3)
        sum1 += board[i][j];
      else if (j < 6)
        sum2 += board[i][j];
      else
        sum3 += board[i][j];
    }
    if(sum != 45)
      return false;
    if(i % 3 == 2) {
      if(sum1 != 45 || sum2 != 45 || sum3 != 45)
        return false;
      sum1 = sum2 = sum3 = 0;
    }
  }
  sum1 = 0; sum2 = 0; sum3 = 0;
  for(int i = 0; i < 9; ++i) {
    sum = 0;
    for(int j = 0; j < 9; ++j) {
      sum += board[j][i];
      if(j < 3)
        sum1 += board[i][j];
      else if (j < 6)
        sum2 += board[i][j];
      else
        sum3 += board[i][j];
    }
    if(sum != 45)
      return false;
    if(i % 3 == 2) {
      if(sum1 != 45 || sum2 != 45 || sum3 != 45)
        return false;
      sum1 = sum2 = sum3 = 0;
    }
  }
  return true;
}