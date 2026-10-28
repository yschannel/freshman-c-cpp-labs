/*18.Write a function char* concatenateStrings(char* s1, char* s2); which
 * concatenate two strings. The function will allocate memory to store the
 * concatenated strings.*/

/*方法2
#include <string.h>

char *concatenateStrings(char *s1, char *s2) {
    if (s1 == NULL || s2 == NULL) return NULL; // 健壮性检查
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    char *s = malloc(len1 + len2 + 1);
    if (s == NULL) return NULL; // 检查 malloc 是否成功
    strcpy(s, s1);
    strcpy(s + len1, s2);
    return s;
}*/

#include <stdio.h>
#include <stdlib.h>

char *concatenateStrings(char *s1, char *s2) {
  int count1 = 0;
  int count2 = 0;
  for (int i = 0; s1[i] != '\0'; i++) {
    count1++;
  }
  for (int j = 0; s2[j] != '\0'; j++) {
    count2++;
  }
  char *s =
      (char *)malloc(sizeof(char) * (count1 + count2 + 1)); // 留空间给'\0'
  if (s == NULL)
    return NULL; // 检查
  for (int k = 0; k < count1 + count2; k++) {
    if (k < count1) {
      s[k] = s1[k];
    } else {
      s[k] = s2[k - count1];
    }
  }
  s[count1 + count2] = '\0'; // 最后一位'\0'
  return s;
}

int main() {
  char s1[] = "Aloha,";
  char s2[] = "world!";
  char *s = concatenateStrings(s1, s2);
  printf("%s", s);
  free(s);  // 释放
  s = NULL; // 设空
  return 0;
}
