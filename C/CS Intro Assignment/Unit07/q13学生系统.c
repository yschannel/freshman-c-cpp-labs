#include<stdio.h>

typedef enum{
    A,B,C,D,F
}Grade;

typedef struct{
    char name[50];
    int id;
    Grade grades[5];
}Student;

float student_GPA(Student student){
    float sum = 0;
    for(int i = 0;i < 5;i++){
        switch(student.grades[i]){
            case A:{
                sum += 4.0;
                break;
            }
            case B:{
                sum += 3.0;
                break;
            }
            case C:{
                sum += 2.0;
                break;
            }
            case D:{
                sum += 1.0;
                break;
            }
            case F:{
                sum += 0.0;
                break;
            }
            default:break;
        }
    }
    return sum / 5;
}

float class_average_GPA(Student class[],int count){
    float sum = 0;
    for(int i = 0;i < count;i++){
        sum += student_GPA(class[i]);
    }
    return sum / count;
}

int main(){
    int count;
    printf("Enter number of students:");
    scanf("%d",&count);
    Student class[count];
    for(int i = 0;i < count;i++){
        printf("Enter name, ID, and grades for student %d\n",i+1);
        printf("Name:");
        scanf("%s",class[i].name);
        printf("ID:");
        scanf("%d",&class[i].id);
        printf("Grades: ");
        for(int j = 0;j < 5;j++){
            char grade_c;
            scanf(" %c",&grade_c);
            switch(grade_c){
                case 'A':class[i].grades[j] = A;break;
                case 'B':class[i].grades[j] = B;break;
                case 'C':class[i].grades[j] = C;break;
                case 'D':class[i].grades[j] = D;break;
                case 'F':class[i].grades[j] = F;break;
                default:{
                    printf("Invalid Input!Instead by 'F");
                    class[i].grades[j] = F;
                    break;
                }
            }
        }
        char c;
        while((c=getchar()) != '\n' && c != EOF);
    }

    for(int i = 0;i < count;i++){
        printf("Student %s's GPA:%.1f\n",class[i].name,student_GPA(class[i]));
    }
    printf("Class Average GPA: %.1f",class_average_GPA(class,count));
    return 0;
}