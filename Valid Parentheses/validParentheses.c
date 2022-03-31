#include <stdbool.h>
#include <assert.h>

static bool validParentheses(char *);

int main(int argc, char *argv[]) {
  assert(validParentheses("") == true);
  assert(validParentheses("()") == true);
  assert(validParentheses("(") == false);
  assert(validParentheses(")") == false);
  assert(validParentheses(")(") == false);
  assert(validParentheses("((()))((()))") == true);
  assert(validParentheses("(())((()())())") == true);
  assert(validParentheses("aaaaaaaaaaaAAAAAAAAAAAAAAA") == true);
  assert(validParentheses("((((((((((10))))))))))") == true);
  assert(validParentheses(")((((())))))") == false);
  return 0;
}

#define STR_MAX_LEN 101

static int numOfParentheses;

static bool validParentheses(char *str) {
  numOfParentheses = 0;
  int i;
  for(i = 0; i < STR_MAX_LEN-1 && str[i] != '\0'; ++i) {
    if(str[i] == '(')
      ++numOfParentheses;
    else if(str[i] == ')') {
      --numOfParentheses;
      if(numOfParentheses < 0)
        return false;
    }
  }
  if(numOfParentheses == 0)
    return true;
  else
    return false;
}