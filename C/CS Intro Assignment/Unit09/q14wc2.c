/*按字符读*/
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
  char file_name[256];
  printf("Input file name: ");
  fgets(file_name, sizeof(file_name), stdin);
  file_name[strcspn(file_name, "\n")] = '\0';

  FILE *fp = fopen(file_name, "r");
  if (fp == NULL) {
    printf("Fail to open\n");
    return -1;
  }

  int line_count = 0;
  int word_count = 0;
  int char_count = 0;
  int in_word = 0; // 0: not in word, 1: in word
  int c;

  while ((c = fgetc(fp)) != EOF) {
    char_count++;
    if (c == '\n') {
      line_count++;
    }
    if (isspace(c)) {
      if (in_word) {
        word_count++;
        in_word = 0;
      }
    } else {
      in_word = 1;
    }
  }
  // Handle file without trailing newline
  // (line count is number of '\n', so no adjustment needed for lines)
  // But word might be pending
  if (in_word) {
    word_count++;
  }
  if (char_count > 0 && c != '\n') {
    line_count++;
  }

  fclose(fp);
  printf("File: %s\n", file_name);
  printf("Lines: %d\n", line_count);
  printf("Words: %d\n", word_count);
  printf("Chars: %d\n", char_count);

  return 0;
}
