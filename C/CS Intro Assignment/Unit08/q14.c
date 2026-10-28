/*14.Write a function search() that takes an integer array arr, the size of the
 * array size and an integer x as input, and returns whether x exists in arr.
 * Test the function in main().
 * [数组作为函数参数会退化为指针，丢失数组大小信息]*/

#include <stdio.h>

int search(int arr[], int size, int x) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == x) {
      return i;
    }
  }
  return -1;
}

int main() {
  int arr[10] = {4, 1, 6, 8, 3, 6, 3, 2, 9, 7};
  int size = sizeof(arr) / sizeof(arr[0]);
  int index = search(arr, size, 7);
  printf("%d", index);
  return 0;
}