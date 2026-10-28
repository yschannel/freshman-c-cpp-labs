/*13.Write a function void findMaxMin(int x, int y, int z, int* max, int* min);
 * which finds the maximum and minimum from x, y and z. The function return the
 * two values by its parameters max and min. Test the function in main().
 * [利用函数参数传出多个“返回值”] */
#include <stdio.h>

void findMaxMin(int x, int y, int z, int *max, int *min) {
  int temp_max = x;
  int temp_min = x;
  if (x < y || x < z) {
    if (y > z) {
      temp_max = y;
    } else {
      temp_max = z;
    }
  }
  if (x > y || x > z) {
    if (y < z) {
      temp_min = y;
    } else {
      temp_min = z;
    }
  }

  *max = temp_max;
  *min = temp_min;
}

int main() {
  int max, min;
  findMaxMin(2, 1, 3, &max, &min);
  printf("max:%d min:%d", max, min);
  return 0;
}