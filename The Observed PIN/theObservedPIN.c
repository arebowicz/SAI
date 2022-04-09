/* https://www.codewars.com/kata/5263c6999e0f40dee200059d/ */
/* TESTS PASSED: , FAILED: */



#include <stdlib.h>

int **digits = NULL;

void init() {
  digits = (int **) malloc(sizeof(int *) * 10);
  digits[0] = (int *) malloc(sizeof(int) * 2);
  digits[0][0] = 1; digits[0][1] = 8;
  digits[1] = (int *) malloc(sizeof(int) * 4);
  digits[1][0] = 3; digits[1][1] = 1; digits[1][2] = 2; digits[1][3] = 4;
  digits[2] = (int *) malloc(sizeof(int) * 5);
  digits[2][0] = 4; digits[2][1] = 1; digits[2][2] = 2; digits[2][3] = 3; digits[2][4] = 5;
  digits[3] = (int *) malloc(sizeof(int) * 4);
  digits[3][0] = 3; digits[3][1] = 2; digits[3][2] = 3; digits[3][3] = 6;
  digits[4] = (int *) malloc(sizeof(int) * 5);
  digits[4][0] = 4; digits[4][1] = 1; digits[4][2] = 4; digits[4][3] = 5; digits[4][4] = 7;
  digits[5] = (int *) malloc(sizeof(int) * 6);
  digits[5][0] = 5; digits[5][1] = 2; digits[5][2] = 4; digits[5][3] = 5; digits[5][4] = 6; digits[5][5] = 8;
  digits[6] = (int *) malloc(sizeof(int) * 5);
  digits[6][0] = 4; digits[6][1] = 3; digits[6][2] = 5; digits[6][3] = 6; digits[6][4] = 9;
  digits[7] = (int *) malloc(sizeof(int) * 4);
  digits[7][0] = 3; digits[7][1] = 4; digits[7][2] = 7; digits[7][3] = 8;
  digits[8] = (int *) malloc(sizeof(int) * 6);
  digits[8][0] = 5; digits[8][1] = 5; digits[8][2] = 7; digits[8][3] = 8; digits[8][4] = 9; digits[8][5] = 0;
  digits[9] = (int *) malloc(sizeof(int) * 4);
  digits[9][0] = 3; digits[9][1] = 6; digits[9][2] = 8; digits[9][3] = 9;
  return;
}

const char **getPins(const char *observed, size_t *count) {
  init();
  *count = 1;
  const char *tmp = observed;
  int n = 0;
  while(*tmp != '\0') {
    *count *= digits[*tmp++ - '0'][0];
    ++n;
  }
  char **pins = (char **) malloc(sizeof(char *) * *count);
  for(int i = 0; i < *count; ++i)
    pins[i] = (char *) malloc(sizeof(char) * (n + 1));
  int i, j, k, l, m, o, p, r;
  for(j = 0; j < n; ++j) {
    m = 1;
    for(l = 0; l < j; ++l)
      m *= digits[observed[l] - '0'][0];
    p = 1; ++l;
    while(l < n)
      p *= digits[observed[l++] - '0'][0];
    i = 0;
    for(k = 0; k < m; ++k)
      for(o = 1; o <= digits[observed[j] - '0'][0]; ++o)
        for(r = 0; r < p; ++r)
          pins[i++][j] = digits[observed[j] - '0'][o] + '0';
  }
  for(i = 0; i < *count; ++i)
    pins[i][n] = '\0';
  return (const char **) pins;
}

void freePins(const char **pins, size_t count) {
  return;
}



#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

bool compareIfEqual(const char *pin1, const char *pin2) {
  while(*pin1 != '\0' && *pin2 != '\0')
    if(*pin1++ != *pin2++)
      return false;
  if(*pin1 != '\0' || *pin2 != '\0')
    return false;
  return true;
}

int compare(const char *pin1, const char *pin2) {
  while(*pin1 != '\0' && *pin2 != '\0') {
    if(*pin1 < *pin2)
      return *pin1 - *pin2;
    else if(*pin1 > *pin2)
      return *pin1 - *pin2;
    ++pin1; ++pin2;
  }
  if(*pin1 != '\0')
    return *pin1;
  if(*pin2 != '\0')
    return -1 * *pin2;
  return 0;
}

void swap(const char **pins, size_t i1, size_t i2) {
  const char *tmp = pins[i2];
  pins[i2] = pins[i1];
  pins[i1] = tmp;
  return;
}

void bubblePINsSort(const char **pins, size_t count) {
  for(size_t i = 0; i < count - 1; ++i)
    for(size_t j = 0; j < count - 1 - i; ++j)
      if(compare(pins[j], pins[j+1]) > 0)
        swap(pins, j, j+1);
  return;
}

void test(const char *observed, const size_t expectedCount, const char *expectedPins[]) {
  size_t count = 0;
  const char **pins = getPins(observed, &count);
  if(count != expectedCount)
    printf("Error. ExpectedCount: %zu\nGot: %zu\n", expectedCount, count);
  assert(count == expectedCount);
  bubblePINsSort(pins, count);
  for(size_t i = 0; i < count; ++i)
    if(compareIfEqual(pins[i], expectedPins[i]) == false) {
      printf("Error. %zuth PIN expected to be %s but got %s\n", i, expectedPins[i], pins[i]);
      assert(false);
    }
  freePins(pins, count); pins = NULL; count = 0;
}

int main(int argc, char *argv[]) {
  
  const char *observed01 = "8";
  size_t expectedCount01 = 5;
  const char *expectedPins01[] = { "0", "5", "7", "8", "9" };

  const char *observed02 = "11";
  size_t expectedCount02 = 9;
  const char *expectedPins02[] = { "11", "12", "14", "21", "22", "24", "41", "42", "44" };

  const char *observed03 = "369";
  size_t expectedCount03 = 36;
  const char *expectedPins03[] = { "236", "238", "239", "256", "258", "259", "266", "268", "269", "296", "298", "299", "336", "338", "339", "356", "358", "359", "366", "368", "369", "396", "398", "399", "636", "638", "639", "656", "658", "659", "666", "668", "669", "696", "698", "699" };
  
  test(observed01, expectedCount01, expectedPins01);
  test(observed02, expectedCount02, expectedPins02);
  test(observed03, expectedCount03, expectedPins03);

  return 0;

}