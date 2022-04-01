#include <assert.h>
#include <stdbool.h>

/* https://www.codewars.com/kata/5518a860a73e708c0a000027/ */
/* tests passed: 891, failed: 0 */

bool OVERFLOW = false;
bool OVERFLOW2 = false;

/*  x^y                  */
/* 0 <= x,y <= 99        */
/* 0 <= return val <= 99 */
int twoLastDigits(int x, int y) {
  if(OVERFLOW == true) {
    y = 100;
    OVERFLOW = false;
  }
  if(OVERFLOW2) {
    y += 100;
    OVERFLOW2 = false;
  }
  if(y == 0)
    return 1;
  if(x == 0 || x == 1)
    return x;
  if(x % 10 == 0 && y >= 2)
    OVERFLOW = true;
  int i;
  int result = x; // 0 <= result <= 99
  for(i=0; i<y-1; ++i)
    result = (result%10)*(x%10) + 
             10*((result/10)%10)*(x%10) +
             (result%10)*(x/10)*10;
  return result%100;
}

int lastDigit(const unsigned long int *arr, int arr_size) {
  if(arr_size == 0)
    return 1;
  if(arr_size == 1)
    return arr[0]%10;
  int i, result;
  result = arr[arr_size-1];
  for(i=arr_size-1; i>0; --i) {
    if(arr[i]%100==0 && arr[i]>=100)
      result = twoLastDigits(arr[i-1]%100, 100);
    result = twoLastDigits(arr[i-1]%100, result%100);
    if((arr[i-1]/10)%10 == 0 && arr[i-1]>=100)
      OVERFLOW2 = true;
  }
  OVERFLOW = false;
  return result%10;
}

int main(int argc, char *argv[]) {
  const unsigned long arr0[] = {};
  assert(lastDigit(arr0, 0) == 1);
  const unsigned long arr1[] = { 0, 0 };
  assert(lastDigit(arr1, 2) == 1);
  const unsigned long arr2[] = { 0, 0, 0 };
  assert(lastDigit(arr2, 3) == 0);
  const unsigned long arr3[] = { 1, 2 };
  assert(lastDigit(arr3, 2) == 1);
  const unsigned long arr4[] = { 3, 4, 5 };
  assert(lastDigit(arr4, 3) == 1);
  const unsigned long arr5[] = { 4, 3, 6 };
  assert(lastDigit(arr5, 3) == 4);
  const unsigned long arr6[] = { 7, 6, 21 };
  assert(lastDigit(arr6, 3) == 1);
  const unsigned long arr8[] = { 2, 2, 2, 0 };
  assert(lastDigit(arr8, 4) == 4);
  const unsigned long arr9[] = { 937640, 767456, 981242 };
  assert(lastDigit(arr9, 3) == 0);
  const unsigned long arr10[] = { 123232, 694022, 140249 };
  assert(lastDigit(arr10, 3) == 6);
  const unsigned long arr11[] = { 499942, 898102, 846073 };
  assert(lastDigit(arr11, 3) == 6);
  const unsigned long arr7[] = { 12, 30, 21 };
  assert(lastDigit(arr7, 3) == 6);
  return 0;
}