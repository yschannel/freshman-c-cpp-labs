// 7.Write a program that takes two integer inputs and outputs the sum,
// difference,
//  product, quotient and remainder. Use the +, -, *, / and % operators.
#include <stdio.h>
int main() {
  int a, b;
  printf("Please input the first integer:");
  scanf("%d", &a);
  printf("Please input the second integer:");
  scanf("%d", &b);

  printf("The sum:%d\n", a + b);
  printf("The difference:%d\n", a - b);
  printf("The product:%d\n", a * b);
  printf("The quotient:%d\n", a / b);
  printf("The remainder:%d\n", a % b);
  return 0;
}