/*
Define a student structure that contains 
four member variables: name, student ID, age,
 and grade, with data types of string, integer, integer,
  and floating-point, respectively.
   You do NOT need to write a main() function.*/
#include<stdio.h>
typedef struct 
{
   char name[100];
   int student_ID;
   int age;
   float grade;
}Student;