#include <stdio.h>
int main() {
  FILE *fp = fopen("hello.txt", "w");
  if (NULL == fp)
    printf("Error open file \"hello.txt\"\n");
  char ch = 'a';
  putc(ch, fp);       // 输出字符ch
  fputs("Hello", fp); // 输出字符串
  fprintf(fp, "%s, %d\n", "name", 100);

  fclose(fp);
}