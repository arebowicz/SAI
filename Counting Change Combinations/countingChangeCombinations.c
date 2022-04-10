/* https://www.codewars.com/kata/541af676b589989aed0009e7/ */
/* TESTS PASSED: 108, FAILED: 0 */



#include <stdlib.h>
#include <stdbool.h>

#define MAX_NUM_OF_COINS 250

bool isCombinationSortedDesc(int combination[MAX_NUM_OF_COINS], int len) {
  for(int i = 0; i < len - 1; ++i)
    if(combination[i] < combination[i+1])
      return false;
  return true;
}

void combinations(int money, int nCoins, const int coins[nCoins],
                  int sum, int recursionLvl, int combination[MAX_NUM_OF_COINS],
                  int *count) {
  if(sum < money) {
    for(int i = 0; i < nCoins; ++i) {
      combination[recursionLvl] = coins[i];
      if(isCombinationSortedDesc(combination, recursionLvl + 1) == true)
        combinations(money, nCoins, coins, sum + coins[i],
                      recursionLvl + 1, combination, count);
    }
  } else if(sum == money && recursionLvl > 0) {
      ++*count;
  }
  return;
}

int countChange(int money, int nCoins, const int coins[nCoins]) {
  int count = 0;
  int combination[MAX_NUM_OF_COINS];
  combinations(money, nCoins, coins, 0, 0, combination, &count);
  return count;
}



#include <assert.h>

void tests() {

  int coins1[] = { 1, 2 };
  assert(countChange(4, 2, coins1) == 3);

  int coins2[] = { 5, 2, 3 };
  assert(countChange(10, 3, coins2) == 4);

  int coins3[] = { 5, 7 };
  assert(countChange(11, 2, coins3) == 0);

  int coins4[] = { 3, 14, 8 };
  assert(countChange(98, 3, coins4) == 19);

  int coins5[] = { 3, 5, 9, 15 };
  assert(countChange(199, 4, coins5) == 760);

  int coins6[] = { 5, 10, 20, 50, 100, 200, 500 };
  assert(countChange(300, 7, coins6) == 1022);

  int coins7[] = { 5, 10, 20, 50, 100, 200, 500 };
  assert(countChange(301, 7, coins7) == 0);

  int coins8[] = { 2, 5, 10, 20, 50 };
  assert(countChange(419, 5, coins8) == 18515);

}

int main(int argc, char *argv[]) {
  tests();
}