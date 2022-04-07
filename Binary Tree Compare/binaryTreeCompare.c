/* https://www.codewars.com/kata/55847fcd3e7dadc9f800005f/ */
/* TESTS PASSED: 117, FAILED: 0 */

#include <stdlib.h>
#include <stdbool.h>

typedef struct treeNode {
  int val;
  struct treeNode *left, *right;
} treeNode;

bool equal;

void checkIfEqual(const treeNode *a, const treeNode *b) {
  if(!equal) {
    return;
  } else if(a != NULL && b == NULL || a == NULL && b != NULL) {
    equal = false;
    return;
  } else if(a == NULL && b == NULL) {
    return;
  } else if(a->val != b->val) {
    equal = false;
    return;
  } else {
    checkIfEqual(a->left, b->left);
    if(equal)
      checkIfEqual(a->right, b->right);
  }
}

bool equalTrees(const treeNode *a, const treeNode *b) {
  equal = true;
  checkIfEqual(a, b);
  return equal;
}