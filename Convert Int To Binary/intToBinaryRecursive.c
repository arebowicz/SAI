unsigned long long toBinary(unsigned short num) {
  if(num == 1)
    return num;
  else
    return (num % 2  +  10 * toBinary(num/2));
}