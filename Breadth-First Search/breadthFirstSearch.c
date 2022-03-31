#include "dataStructures.h"

static void algorithmTests();

int main(int argc, char *argv[]) {
  algorithmTests();
  return 0;
}

static void testAction(char *);

static void algorithmTests() {
  testAction("20. 10.");
  testAction("20. 10 30 40 50.");
  testAction("20. 10. 30. 40. 50. 60. 70.");
  testAction("20. 10 30. . 40.");
  testAction("20. 10 30 40 50. . 31 32. . 51 52.");
  testAction("20. 10 30. 5 15. . 3 8. 12 17.");
  testAction("20. 10 30. 5 15. 100. 3 8. 12 17. 110. . . . . 105 115.");
  testAction("20. 10 30. 5 15. 100. 3 8. 12 17. 110. . . . . 105 115. 104 106. 114 116. 103. . . . 102. 101.");
  return;
}

static int numOfTests = 0;

static void testAction(char *strTree) {
  if(numOfTests)
    printf("\n\n");
  printf("------------------\n");
  printf("   TEST NO.: %d\n", ++numOfTests);
  printf("------------------\n");
  printf("Input: \"%s\"\n", strTree);
  initTree(strTree);
  printTreeInBFSOrder();
  deleteTree();
  return;
}