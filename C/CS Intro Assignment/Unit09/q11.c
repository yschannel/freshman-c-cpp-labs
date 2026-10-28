/*11.Write a program to read words that input by the user and save the words
 * into a text file “Words.txt”. Try using both fputs and fprintf in your
 * program.*/
#include <stdio.h>

int main() {
  char buffer[20];
  scanf("%s", buffer);
  FILE *fp = fopen("Words.txt", "a+");
  if (fp == NULL) {
    printf("Objective file can't be opened\n");
    return 1;
  }
  fputs(buffer, fp);
  fputs("\n", fp);
  fprintf(fp, "%s\n", buffer);
  fputs(buffer, stdout);
  fputs("\n", stdout);
  fprintf(stdout, "%s\n", buffer);

  fclose(fp);
  /*
    fp = fopen("Words.txt", "ab+");
    fwrite(buffer, 100, 1, fp);
    fclose(fp);
  */
  return 0;
}