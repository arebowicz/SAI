/* https://www.codewars.com/kata/59fca81a5712f9fa4700159a/ */
/* TESTS PASSED: 70, FAILED: 0 */

unsigned long long power10(int i) {
  unsigned long long result = 1;
  while(i-- > 0)
    result *= 10;
  return result;
}

unsigned long long toBinary(unsigned short num) {
  unsigned long long result = 0ull;
  int e = 0;
  while(num > 0) {
    result += (power10(e++) * (num % 2));
    num /= 2;
  }
  return result;
}