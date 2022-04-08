/* https://www.codewars.com/kata/573992c724fc289553000e95/ */
/* BRUTE-FORCE METHOD */



#include <stdlib.h>

long long *smallest(long long n) {

}



void test(long long n, long long *exp) {
  long long *act = smallest(n);
  if(act[0] != exp[0] || act[1] != exp[1] || act[2] != exp[2])
    printf("Error. Expected \n{ %lld, %lld, %lld }\n but got \n{ %lld, %lld, %lld }\n",
                             exp[0], exp[1], exp[2],          act[0], act[1], act[2] );
  assert(act[0] == exp[0] && act[1] == exp[1] && act[2] == exp[2]);
  free(act); act = NULL;
  free(exp); exp = NULL;
}

int main(int argc, char *argv[]) {
  test(261235, (long long *) { 126235, 2, 0 });
  test(209917, (long long *) { 29917, 0, 1 });
  test(285365, (long long *) { 238565, 3, 1 });
  test(296837, (long long *) { 239687, 4, 1 });
}