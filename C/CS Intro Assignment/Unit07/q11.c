/*11.Based on Quiz10, define a student grade array 
that may contain 3 elements. Define a function calcAverage 
to compute the average score of the student grade array.*/
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

float calc_average(Student_grade student[],int count){
    float sum = 0;
    for(int i = 0;i < count;i++){
        sum += average_score(student[i]);
    }
    return sum / count;
}

int main(){
    Student_grade num[3];

    for(int i = 0;i < 3;i++){
        printf("Input student%d information\n",i+1);
        printf("Name:");
        scanf("%99s",num[i].name);
        printf("ID:");
        scanf("%d",&num[i].student_ID);
        printf("Input  grade\n");
        printf("Course1:");
        scanf("%f",&num[i].three_course_grades[0]);
        printf("Course2:");
        scanf("%f",&num[i].three_course_grades[1]);
        printf("Course3:");
        scanf("%f",&num[i].three_course_grades[2]);
    }
    
    printf("The average score:%.1f",calc_average(num,3));

    return 0;
}