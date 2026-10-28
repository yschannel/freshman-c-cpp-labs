/*12.Write a function countWords(), open “Words.txt” and count how many words
 * are there in the file. Try using both fgets and fscanf. You also need to deal
 * with the situation that the file does NOT exist.*/
#include <stdio.h>
#include <string.h>
int countWords_fscanf() {
  FILE *fp = fopen("Words.txt", "r");
  if (fp == NULL) {
    printf("Fail to open\n");
    return -1;
  }
  int count = 0;
  while (1) {
    char buffer[100];
    if (fscanf(fp, "%s", buffer) == 1) {
      count++;
    } else {
      break;
    }
  }
  fclose(fp);
  return count;
}
int countWords_fgets() {
  FILE *fp = fopen("Words.txt", "r");
  if (fp == NULL) {
    printf("fail to open\n");
    return -1;
  }
  int count = 0;
  char line[256];
  while (fgets(line, sizeof(line), fp) != NULL) {
    char *token = strtok(line, " \t\n\r");
    while (token != NULL) {
      if (strlen(token) > 0) {
        count++; // 关键的一步，要不然误数了
      }
      token = strtok(NULL, " \t\n\r");
    }
  }
  fclose(fp);
  return count;
}

int main() {
  int count1 = countWords_fscanf();
  printf("%d\n", count1);
  int count2 = countWords_fgets();
  printf("%d\n", count2);
  return 0;
}