/* https://www.codewars.com/kata/55847fcd3e7dadc9f800005f/ */
/* TESTS PASSED: 117, FAILED: 0 */

#include <stdlib.h>
#include <stdbool.h>

typedef struct treeNode {
  int val;
  struct treeNode *left, *right;
} treeNode;

bool equalTrees(const treeNode *a, const treeNode *b) {
  if(a == NULL && b == NULL)
    return true;
  else if(a != NULL && b != NULL)
    return a->val == b->val && equalTrees(a->left, b->left)
                            && equalTrees(a->right, b->right);
  else
    return false;
}