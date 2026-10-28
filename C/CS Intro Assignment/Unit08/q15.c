/*15.Write a function compare() that takes two integer arrays arr1 and arr2 as
 * input, and compares whether the two arrays are equal.*/

#include <stdio.h>

int compare(int arr1[], int arr2[], int size) {
  for (int i = 0; i < size; i++) {
    if (arr1[i] != arr2[i]) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int arr1[5] = {1, 2, 3, 4, 5};
  int arr2[5] = {1, 2, 3, 4, 5};

  int size = sizeof(arr1) / sizeof(arr1[0]);

  printf("%s\n", compare(arr1, arr2, size) ? "Equal" : "Not equal");

  return 0;
}