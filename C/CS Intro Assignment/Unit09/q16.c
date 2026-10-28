/*16.Write a program to read 2 students’ information (including string name, int
 * age and bool gender) input by the user and save the information into a file
 * “Students.dat” in binary mode. You should construct a “Student” struct data
 * type in your program and save each student’s information just as a binary
 * form struct. */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[50];
  int age;
  bool gender;
} Student;
int main() {
  Student group[2];
  for (int i = 0; i < 2; i++) {
    char buffer[100];
    printf("Student%d\n", i + 1);
    printf("name:");
    if ((fgets(buffer, sizeof(buffer), stdin)) == NULL) {
      printf("Input error. Try again.\n");
      i--;
      continue;
    }
    buffer[strcspn(buffer, "\n")] = '\0';
    if (strlen(buffer) == 0) {
      printf("Input error. Try again.\n");
      i--;
      continue;
    }
    strncpy(group[i].name, buffer,
            sizeof(group[i].name) - 1);              // 复制，不用sscanf()
    group[i].name[sizeof(group[i].name) - 1] = '\0'; // 避免无效

    printf("age:");
    if ((fgets(buffer, sizeof(buffer), stdin)) == NULL) {
      printf("Invalid age.again\n");
      i--;
      continue;
    }
    buffer[strcspn(buffer, "\n")] = '\0';

    char *endptr;
    long val = strtol(buffer, &endptr, 10); // 转换为10进制
    if (buffer[0] == '\0' || *endptr != '\0') {
      printf("Invalid age.again\n");
      i--;
      continue;
    }
    group[i].age = (int)val;

    printf("gender(man:0;woman:1):");
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
      printf("Input error. Try again.\n");
      i--;
      continue;
    }
    if (buffer[0] == '0') {
      group[i].gender = false;
    } else if (buffer[0] == '1') {
      group[i].gender = true;
    } else {
      printf("Invalid gender.again\n");
      i--;
      continue;
    }
  }

  FILE *fp = fopen("Students.dat", "wb");
  if (fp == NULL) {
    printf("Fail to open");
    return -1;
  }
  fwrite(group, sizeof(Student), 2,
         fp); // fwrite(group, sizeof(group), 1, fp);可读性差
  fclose(fp);
}