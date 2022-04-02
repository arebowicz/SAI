# https://www.codewars.com/kata/55905b7597175ffc1a00005a/
# TESTS PASSED: 205, FAILED: 0

def pageDigits(pages):
  digits = 1
  tmp = pages
  while tmp // 10 > 0:
    digits += 1
    tmp //= 10
  i = 1
  sum = 0
  while i < digits:
    sum += (i * 9 * pow(10, i-1))
    i += 1
  sum += (digits * (pages - pow(10, digits-1) + 1))
  return sum