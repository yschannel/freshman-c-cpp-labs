// count_bytes.c
#include <stdio.h>

int main() {
  FILE *fp = fopen("TaoTeChing.txt", "rb"); // 二进制模式更准确
  if (!fp) {
    perror("Cannot open file");
    return 1;
  }

  int count = 0;
  int c;
  while ((c = fgetc(fp)) != EOF) {
    count++;
  }
  fclose(fp);
  printf("Total bytes in file: %d\n", count);
  return 0;
}