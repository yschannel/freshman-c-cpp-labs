#include <stdio.h>
#include <string.h>

// 定义结构体类型
struct Student {
    char name[50];
    int age;
    float score;
};

// 结构体作为函数参数
void printStudent(struct Student s) {
    printf("Name: %s, Age: %d, Score: %.1f\n", s.name, s.age, s.score);
}

int main() {
    // 声明结构体变量
    struct Student student1;
    
    // 访问成员并赋值
    strcpy(student1.name, "Alice");
    student1.age = 20;
    student1.score = 95.5;
    
    // 声明时初始化
    struct Student student2 = {"Bob", 21, 88.0};
    
    // 使用结构体
    printStudent(student1);
    printStudent(student2);
    
    // 结构体数组
    struct Student classroom[3] = {
        {"Charlie", 19, 92.0},
        {"David", 20, 85.5},
        {"Eve", 22, 90.0}
    };
    
    printf("\nClassroom:\n");
    for (int i = 0; i < 3; i++) {
        printStudent(classroom[i]);
    }
    
    // 结构体指针
    struct Student *ptr = &student1;
    printf("\nUsing pointer: %s\n", ptr->name);  // 使用 -> 操作符访问成员
    printf("Age via pointer: %d\n", (*ptr).age); // 等价写法
    
    return 0;
}