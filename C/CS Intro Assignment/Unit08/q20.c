/*20.Student Score Statistics. Define a struct Student that includes name
 * (string) and score (integer). Write a function averageScore() which receives
 * an array of Student type and its length through pointers, calculates and
 * returns the average score of all students.*/

#include <stdio.h>

typedef struct {
  char name[100];
  int score;
} Student;

float averageScore(Student *students, int *num) {
  int total = 0;
  int i = 0;
  while (i < *num) {
    total += students[i].score;
    i++;
  }
  return (float)total / *num;
}

int main() {
  Student group[3];
  int num = 3;
  group[0] = (Student){"yishui", 99};
  group[1] = (Student){"yiliu", 20};
  group[2] = (Student){"sekai", 59};
  printf("%.1f", averageScore(group, &num));
  return 0;
}