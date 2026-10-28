/*18.Based on Quiz17, write a function insertRecordSorted() which opens the file
 * “Students.dat” and insert a new Student record according to the sequence of
 * the name. Hint: you need to read in all the students/student names from the
 * file and then find which position the new record should be insert into.*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
  char name[50];
  int age;
  bool gender;
} Student;

void compare_alpha(int stu1, int stu2, Student *group) {
  int result = strcmp(group[stu1].name, group[stu2].name);
  if (result > 0) {
    Student temp = group[stu1];
    group[stu1] = group[stu2];
    group[stu2] = temp;
  }
}

void insertRecordSorted() {
  Student group[3];
  FILE *fp = fopen("Students.dat", "rb");
  if (fp == NULL) {
    printf("Fail to open");
    return;
  }

  size_t result = fread(group, sizeof(Student), 3, fp); // 直接读取就可了
  if (result != 3) {
    printf("Error: Failed to read 2 student records from file.\n");
    fclose(fp);
    return;
  }

  fclose(fp);

  compare_alpha(0, 1, group);
  compare_alpha(1, 2, group);
  compare_alpha(0, 1, group);

  FILE *file = fopen("Students.dat", "wb");
  if (file == NULL) {
    printf("fail to open");
    return;
  }
  fwrite(group, sizeof(Student), 3, file);
  fclose(file);
  return;
}
int main() {
  insertRecordSorted();
  return 0;
}