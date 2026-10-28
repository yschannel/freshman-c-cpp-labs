#include <stdio.h>
int main() {
  FILE *fp = fopen("Hello.txt", "r");
  int ch = getc(fp); // Read a character from the file
  if (ch != EOF)     // Not reach the end of the file
    putchar(ch);
  char buffer[40];
  int number;
  int len = fgets(buffer, 15, fp); // what if(len==0)?
  int flag = fscanf(fp, "%s %d\n", buffer, &number);
  fclose(fp);
}