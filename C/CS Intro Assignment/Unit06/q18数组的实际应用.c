//18.Write a program that simulates student score entry and output.
// Create a two-dimensional array to store the names of 10 students
// and their scores for 3 courses, and then print out 
//the name of each student along with their average score.
#include <stdio.h>
#include <string.h>

#define NUM_STUDENTS 10
#define NUM_COURSES 3

int main() {
    // 定义二维数组存储学生姓名和成绩
    char names[NUM_STUDENTS][50];  // 存储10个学生姓名，每个姓名最多49个字符
    int scores[NUM_STUDENTS][NUM_COURSES];  // 存储10个学生的3门课程成绩
    
    // 输入学生姓名和成绩
    printf("请输入10个学生的姓名和3门课程的成绩：\n");
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("\n学生 %d:\n", i + 1);
        printf("姓名: ");
        scanf("%s", names[i]);
        
        printf("请输入3门课程的成绩: ");
        for (int j = 0; j < NUM_COURSES; j++) {
            scanf("%d", &scores[i][j]);
        }
    }
    
    // 计算并输出每个学生的平均分
    printf("\n学生成绩汇总：\n");
    printf("姓名\t\t平均分\n");
    printf("----------------------\n");
    
    for (int i = 0; i < NUM_STUDENTS; i++) {
        int sum = 0;
        for (int j = 0; j < NUM_COURSES; j++) {
            sum += scores[i][j];
        }
        float average = (float)sum / NUM_COURSES;
        printf("%s\t\t%.2f\n", names[i], average);
    }
    
    return 0;
}