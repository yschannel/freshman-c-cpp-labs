/*17.Write a program that takes an integer n as input from the keyboard, then
 * dynamically allocates memory for n integers, reads n integers from the
 * keyboard, and finally frees the memory.*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  printf("input n=");
  scanf("%d", &n);
  int *arr = (int *)malloc(sizeof(int) * n);
  if (arr == NULL) {
    printf("memory allocation failed\n");
    return 1;
  }
  printf("input n integers\n");
  for (int i = 0; i < n; i++) {
    printf("%d:", i + 1);
    scanf("%d", &arr[i]);
  }
  free(arr);
  arr = NULL;
  return 0;
}