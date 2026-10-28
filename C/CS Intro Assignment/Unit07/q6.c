/*6.Declare a student structure variable and 
input the information of the student from the keyboard,
Then output the information of the student.*/
#include<stdio.h>
typedef struct 
{
   char name[100];
   int student_ID;
   int age;
   float grade;
}Student;

int main(){
    Student num1;

    printf("Input your information\n");
    printf("Name:");
    scanf("%99s",num1.name);
    printf("ID:");
    scanf("%d",&num1.student_ID);
    printf("Age:");
    scanf("%d",&num1.age);
    printf("Grade:");
    scanf("%f",&num1.grade);    

    printf("Name:%s\n",num1.name);
    printf("Student ID:%d\n",num1.student_ID);
    printf("Age:%d\n",num1.age);
    printf("Grade:%.1f\n",num1.grade);
    return 0;
}