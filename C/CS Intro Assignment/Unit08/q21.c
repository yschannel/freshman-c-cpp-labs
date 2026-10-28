/*Write a program that reads simple data declarations and responds with the
 * amount of memory that would be allocated to that variable. */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

char *trim(char *ch) {
  if (ch == NULL || *ch == '\0')
    return ch;

  while (*ch && isspace((unsigned char)*ch)) {
    ch++;
  }

  if (*ch == '\0')
    return ch;

  char *end = ch + strlen(ch) - 1;
  while (end > ch && isspace((unsigned char)*end)) {
    end--;
  }

  *(end + 1) = '\0';

  return ch;
}

int main() {
  while (1) {
    char line[256];
    if (fgets(line, sizeof(line), stdin) == NULL) {
      break;
    };

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
    if (type == NULL) {
      continue;
    }
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
      int current_size = size;

      char *var_name = trim(token);

      if (*var_name == '\0')
        continue;

      if (var_name[0] == '*') {
        current_size = sizeof(void *);
        var_name = trim(var_name + 1);
      }

      char *bracket = strchr(var_name, '[');
      if (bracket != NULL) {
        int N;
        int set = sscanf(bracket, "[%d]", &N);
        if (set != 1)
          continue;
        current_size = current_size * N;
        bracket[0] = '\0';
      }

      printf("%s requires %d bytes\n", var_name, current_size);

      token = strtok(NULL, ",");
    }
  }

  return 0;
}