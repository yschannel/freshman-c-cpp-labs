#include <stdio.h>
#include <string.h>
int main() {
  char string1[11], string2[9];
  memset(string1, '1', 11);
  memset(string2, '2', 9);

  /* input: Hello Kitty */
  scanf("%10s %8s", string1, string2);
  printf("%10s\t%8s", string1, string2);
}
