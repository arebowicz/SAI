/* https://www.codewars.com/kata/5263c6999e0f40dee200059d/ */
/* TESTS PASSED: , FAILED: */



#include <stdlib.h>

const char **getPins(const char *observed, size_t *count) {
  *count = 1;
  return NULL;
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

void test(const char *observed, const size_t expectedCount, const char *expectedPins) {
  size_t count = 0;
  const char **pins = getPins(observed, &count);
  if(count != expectedCount)
    printf("Error. ExpectedCount: %zu\nGot: %zu", expectedCount, count);
  assert(count == expectedCount);
  bubblePINsSort(pins, count);
  for(size_t i = 0; i < count; ++i)
    if(compareIfEqual(pins[i], expectedPins[i]) == false)
      printf("Error. %zuth PIN expected to be %s but got %s\n", expectedPins[i], pins[i]);
  freePins(pins, count); pins = NULL; count = 0;
}

int main(int argc, char *argv[]) {
  
  const char *observed01 = "8";
  size_t expectedCount01 = 5;
  const char **expectedPins01 = { "0", "5", "7", "8", "9" };

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