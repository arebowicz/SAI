/* https://www.codewars.com/kata/521c2db8ddc89b9b7a0000c1/ */
/* TESTS PASSED: 187, FAILED: 0 */

#include <stdlib.h>

int *snail(size_t *outsz, const int **mx, size_t rows, size_t cols) {
  *outsz = rows*cols;
  int *result = (int *) malloc(sizeof(int) * *outsz);
  int i, j, k, el;
  for(i = 0, j = 0, k = 0, el = 0; k < ((int) rows + 1) / 2; ++k) {
    if(el ==  ((int) rows * (int) cols) - 1) {
      result[el] = mx[((int) rows + 1) / 2 - 1][((int) cols + 1) / 2 - 1];
      return result;
    }
    for(i = k, j = k; j < (int) cols - k; ++j)
      result[el++] = mx[i][j];
    for(i = k + 1, j = (int) cols - 1 - k; i < (int) rows - k; ++i)
      result[el++] = mx[i][j];
    for(i = (int) rows - 1 - k, j = (int) cols - 1 - 1 - k; j >= k; --j)
      result[el++] = mx[i][j];
    for(i = (int) rows - 1 - 1 - k, j = k; i >= k + 1; --i)
      result[el++] = mx[i][j];
  }
  return result;
}