/*16.Write a function stringLen() that takes a string str as input, and returns
 * the length of str.*/

#include <stdio.h>
#include <string.h>

int stringLen(char *str) {
  int len = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    len++;
  }
  return len;
}

int main() {
  char str[] = "chaididjdw?2124";
  printf("%d %llu", stringLen(str), strlen(str));
}