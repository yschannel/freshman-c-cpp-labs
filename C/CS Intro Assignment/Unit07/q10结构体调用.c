/*Based on Quiz9, calculate the total grade and average 
grade of the student and output them. 
Then modify the program to make the codes into 
two functions: sumScore() and averageScore() 
which accept one parameter of the student grade structure type.*/
#include<stdio.h>

typedef struct {
    char name[100];
    int student_ID;
    float three_course_grades[3];
}Student_grade;

float sum_score(Student_grade student){
    float sum = 0;
    for (int i=0;i<3;i++){
        sum += student.three_course_grades[i];
    }
    return sum;
}

float average_score(Student_grade student){
    float sum = sum_score(student);
    return sum / 3;
}

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

    printf("\nSum:%.1f\n",sum_score(num1));
    printf("Average:%.1f\n",average_score(num1));

    return 0;
}