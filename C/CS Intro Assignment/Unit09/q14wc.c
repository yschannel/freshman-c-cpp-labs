/*14.Write a program wc.c that reads a file and report how many lines, words,
 * and character appear in it. For the purposes of this program, a word consists
 * of a consecutive sequence of any characters except white-space characters.
 * For example, if the file TaoTeChing.txt contains the following passage from
 * Lao Tsi,*/
#include <stdio.h>
#include <string.h>
int main() {
  char file_name[256];
  printf("Input file name:");
  fgets(file_name, sizeof(file_name), stdin);
  file_name[strcspn(file_name, "\n")] = '\0';
  FILE *fp = fopen(file_name, "r");
  if (fp == NULL) {
    printf("Fail to open");
    return -1;
  }
  int line_count = 0;
  int word_count = 0;
  int char_count = 0;
  char line[1024];
  while (fgets(line, sizeof(line), fp) != NULL) {
    line_count++;
    char_count += strlen(line);
    char *token = strtok(line, " \t\n\r");
    while (token != NULL) {
      if (strlen(token) > 0) {
        word_count++;
      }
      token = strtok(NULL, " \t\n\r");
    }
  }
  printf("File:%s\n", file_name);
  printf("Lines:%d\n", line_count);
  printf("Word:%d\n", word_count);
  printf("Chars:%d\n", char_count);
  return 0;
}