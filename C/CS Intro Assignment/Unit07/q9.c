/*9.Define a student grade structure that 
contains three member variables: name, student ID, 
and three course grades, with data types of string, integer, 
and floating-point array, respectively. 
Declare a student grade structure variable and input the name,
 student ID, and three course grades of the student 
 from the keyboard.*/
#include<stdio.h>

typedef struct {
    char name[100];
    int student_ID;
    float three_course_grades[3];
}Student_grade;

int main(){
    Student_grade num1;
    printf("Input your information\n");
    printf("Name:");
    scanf("%99s",num1.name);
    printf("ID:");
    scanf("%d",&num1.student_ID);
    printf("Input your grade\n");
    printf("Course1:");
    scanf("%f",&num1.three_course_grades[0]);
    printf("Course2:");
    scanf("%f",&num1.three_course_grades[1]);
    printf("Course3:");
    scanf("%f",&num1.three_course_grades[2]);

    return 0;
}