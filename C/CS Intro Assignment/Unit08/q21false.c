/*Write a program that reads simple data declarations and responds with the
 * amount of memory that would be allocated to that variable. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *variable_extract(char *str, int pos1, int pos2) {
  char *variable = (char *)malloc(sizeof(char) * (pos2 - pos1 + 2));
  for (int i = 0; i < (pos2 - pos1 + 1); i++) {
    variable[i] = str[pos1 + i];
  }
  return variable;
}

int main() {
  int pos1 = 0;
  int pos2 = 0;
  char *variable;
  int byte;

  while (1) {
    char arr[256];
    fgets(arr, sizeof(arr), stdin);
    if (arr[0] == '\0' || arr[0] == '\n')
      break;

    for (int i = 1; arr[i] != ' '; i++) {
      pos2++;
    }

    char *type = variable_extract(arr, pos1, pos2);
    pos2++;

    if (strcmp(type, "int") == 0) {
      while (arr[pos2] != ';' && arr[pos2] != '\0') {
        while (arr[pos2] == ' ') {
          pos2++;
        }

        if (arr[pos2] == '*') {
          byte = sizeof(int *);
          pos2++;
        } else {
          byte = sizeof(int);
        }

        pos1 = pos2;

        while (arr[pos2] != ',' && arr[pos2] != ';') {
          pos2++;
          if (arr[pos2] == '[') {
            pos2++;
            int pos3 = pos2;
            while (arr[pos2] != ']') {
              pos2++;
            }
            int count = atoi(variable_extract(arr, pos3, pos2 - 1));
            byte = sizeof(int) * count;
          }
        }

        variable = variable_extract(arr, pos1, pos2 - 1);

        printf("%s requires %d bytes\n", variable, byte);
      }
    }
  }
}