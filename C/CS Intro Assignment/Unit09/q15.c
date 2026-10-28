/*15.Write a program, Open a binary file “Numbers.dat” and write 10 double
 * numbers to the file. Then read back these numbers and print them out.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 要使用fwrite 和 fread 来处理数
int main() {
  FILE *fp = fopen("Numbers.dat", "wb");
  if (fp == NULL) {
    printf("Fail to open");
    return -1;
  }
  printf("Input 10 double numbers(one per line):\n");
  char buffer[256];
  for (int i = 0; i < 10; i++) {
    if ((fgets(buffer, sizeof(buffer), stdin)) == NULL) { // fgets
      printf("Input error\n");
      fclose(fp);
      return -1;
    }
    buffer[strcspn(buffer, "\n")] = '\0'; //

    char *endptr;                         // 结束位置
    double val = strtod(buffer, &endptr); // 转换成double 注意这里是指针的指针

    if (*endptr != '\0' || buffer == endptr) { // 判断
      printf("Invalid input at line %d: '%s'.Please enter a valid number.\n",
             i + 1, buffer);
      i--;
      continue;
    }

    fwrite(&val, sizeof(double), 1, fp);
  }
  fclose(fp);

  FILE *file = fopen("Numbers.dat", "rb");
  if (file == NULL) {
    printf("Fail to open");
    return -1;
  }
  double val;
  while ((fread(&val, sizeof(double), 1, file)) == 1) {
    printf("%.6lf\n", val);
  }
  fclose(file);
  return 0;
}