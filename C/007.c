#include <math.h>
#include <stdio.h>

char *isPrime(int num) {
  if (num == 1)
    return "NO";
  if (num == 2)
    return "Yes";
  if ((num % 2 == 0) && (num != 1) && (num != 2))
    return "No";
  if ((num % 2 == 1) && (num != 1)) {
    int x = sqrt(num);
    for (int i = 3; i <= x; i++) {
      if (num % i == 0)
        return "No";
    }
    return "Yes";
  }
}
int main() {
  int num = 101;
  if (isPrime(num) == "Yes") {
    printf("Yes");
  }
  if (isPrime(num) == "No") {
    printf("No");
  }
  return 0;
}