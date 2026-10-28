/*17.Based on Quiz16, write a function insertRecord() which opens the file
 * “Students.dat” and insert a new Student record after the first student record
 * in the file.*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
  char name[50];
  int age;
  bool gender;
} Student;
void insertRecord() {
  Student oldgroup[2];
  FILE *fp = fopen("Students.dat", "rb");
  if (fp == NULL) {
    printf("Fail to open");
    return;
  }

  size_t result = fread(oldgroup, sizeof(Student), 2, fp); // 直接读取就可了
  if (result != 2) {
    printf("Error: Failed to read 2 student records from file.\n");
    fclose(fp);
    return;
  }

  fclose(fp);
  Student new_student;
  while (1) {
    char buffer[100];
    printf("New student\n");
    printf("name:");
    if ((fgets(buffer, sizeof(buffer), stdin)) == NULL) {
      printf("Input error. Try again.\n");
      continue;
    }
    buffer[strcspn(buffer, "\n")] = '\0';
    if (strlen(buffer) == 0) {
      printf("Input error. Try again.\n");
      continue;
    }
    strncpy(new_student.name, buffer,
            sizeof(new_student.name) - 1);                 // 复制，不用sscanf()
    new_student.name[sizeof(new_student.name) - 1] = '\0'; // 避免无效

    printf("age:");
    if ((fgets(buffer, sizeof(buffer), stdin)) == NULL) {
      printf("Invalid age.again\n");
      continue;
    }
    buffer[strcspn(buffer, "\n")] = '\0';

    char *endptr;
    long val = strtol(buffer, &endptr, 10); // 转换为10进制
    if (buffer[0] == '\0' || *endptr != '\0') {
      printf("Invalid age.again\n");
      continue;
    }
    new_student.age = (int)val;

    printf("gender(man:0;woman:1):");
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
      printf("Input error. Try again.\n");
      continue;
    }
    if (buffer[0] == '0') {
      new_student.gender = false;
    } else if (buffer[0] == '1') {
      new_student.gender = true;
    } else {
      printf("Invalid gender.again\n");
      continue;
    }
    break;
  }
  Student newgroup[3];
  newgroup[0] = oldgroup[0];
  newgroup[1] = new_student;
  newgroup[2] = oldgroup[1];

  FILE *file = fopen("Students.dat", "wb");
  if (file == NULL) {
    printf("fail to open");
    return;
  }
  fwrite(newgroup, sizeof(Student), 3, file);
  fclose(file);
  return;
}
int main() {
  insertRecord();
  return 0;
}