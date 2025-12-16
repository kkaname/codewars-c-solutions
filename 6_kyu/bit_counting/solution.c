#include <stdio.h>

size_t countBits(unsigned value)
{
  if (value == 0)
    return 0;

  int num_of_ones = 0;
  while (value != 0){
    if (value % 2 == 1)
      ++num_of_ones;
    value = value / 2;
  }

  return num_of_ones;
}

int main(void) {
    unsigned int num;
    printf("Enter a non-negative integer: ");
    scanf("%u", &num);
    printf("Number of bits equal to one: %zu\n", countBits(num));

    return 0;
}
