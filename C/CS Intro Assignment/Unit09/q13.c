/*13.Based on Quiz12, write a function search(char* keyword) to search keyword
 * in “Words.txt”. If find, print out the line that contains the keyword.*/
#include <stdio.h>
#include <string.h>
void search(char *keyword) {
  FILE *fp = fopen("Words.txt", "r");
  if (fp == NULL) {
    printf("Fail to open");
    return;
  }
  /*其实没有必要这样做，每次fgets都会从头录入
    while (1) {
      char line[1024];
      if (fgets(line, sizeof(line), fp) != NULL) {
        if (strstr(line, keyword) != NULL) {
          printf("%s", line);还有这里可以不用加\n，fgets会存入\n
        }
      } else {
        break;
      }
    }
  */
  char line[1024];
  while (fgets(line, sizeof(line), fp) != NULL) {
    if (strstr(line, keyword) != NULL) {
      printf("%s", line);
    }
  }
  fclose(fp);
  return;
}
int main() {
  printf("Input the keyword:");
  char keyword[20];
  fgets(keyword, sizeof(keyword), stdin);
  keyword[strcspn(keyword, "\n")] = '\0';
  search(keyword);
  return 0;
}