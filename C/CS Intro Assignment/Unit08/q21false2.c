/*Write a program that reads simple data declarations and responds with the
 * amount of memory that would be allocated to that variable. */

#include <stdio.h>
#include <string.h>

char *trim(char *ch) {
  while (*ch == ' ') {
    ch++;
  }

  char *end = ch + strlen(ch) - 1;
  while (*end == ' ') {
    end--;
  }
  *(end + 1) = '\0';

  return ch;
}

int main() {
  while (1) {
    char line[256];
    fgets(line, sizeof(line), stdin);

    if (line[0] == '\n' || line[0] == '\0') {
      break;
    }

    char *ch = strchr(line, ';');
    if (ch == NULL) {
      break;
    } else {
      *ch = '\0';
    }

    char *type = strchr(line, ' ');
    *type = '\0';
    char *variable = type + 1;
    char *token = strtok(variable, ",");

    int size;

    if (strcmp(line, "char") == 0) {
      size = sizeof(char);
    } else if (strcmp(line, "int") == 0) {
      size = sizeof(int);
    } else if (strcmp(line, "short") == 0) {
      size = sizeof(short);
    } else if (strcmp(line, "long") == 0) {
      size = sizeof(long);
    } else if (strcmp(line, "float") == 0) {
      size = sizeof(float);
    } else if (strcmp(line, "double") == 0) {
      size = sizeof(double);
    } else {
      break;
    }

    while (token != NULL) {

      token = trim(token);
      if (token[0] == '*') {
        size = sizeof(char *);
        token++;
      }

      char *bracket = strchr(token, '[');
      if (bracket != NULL) {
        int N;
        int set = sscanf(bracket, "[%d]", &N);
        if (set != 1)
          continue;
        size = size * N;
        bracket[0] = '\0';
      }

      printf("%s requires %d bytes\n", token, size);
    }
  }

  return 0;
}