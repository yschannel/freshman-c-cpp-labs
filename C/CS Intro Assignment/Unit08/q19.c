/*19.Write a function int wordCount(char* s) to count the number of words in a
 * string. Assuming the words are delimited by one or more space character.
SCAN the string {
  SKIP any spaces
  WordCount++
  FORWARD to next space (SKIP any character that is not space or ‘\0’)
}*/

//!!!不要混用 while for!!!千万当心判断顺序

/*错解
int wordCount(char *s) {
  int count = 0;
  for (int i = 0; s[i] != '\0'; i++) {
    if (i == 0 && s[i] == '\0')
      continue;
    if (s[i] != ' ')
      continue;
    if (s[i] == ' ' && s[i - 1] != ' ')
      count++;
    if (s[i + 1] == '\0' && s[i] != ' ')
      count++;
  }
  return count;
}
*/
#include <stdio.h>

int wordCount(char *s) {
  int count = 0;
  int i = 0;
  while (s[i] != '\0') {
    while (s[i] == ' ') {
      i++;
    }

    if (s[i] == '\0')
      break;

    count++;

    while (s[i] != ' ' && s[i] != '\0') {
      i++;
    }
  }
  return count;
}

int main() {
  char s[] =
      " The function will allocate memory to store the concatenated strings";
  printf("%d", wordCount(s));
  return 0;
}
