#include <stdio.h>
#include <string.h>

int main() {
    int number;
    int sum = 0;
    int count = 0;
    char input[100];

    printf("Enter numbers to sum. Type 'done' to finish.\n");

    // Priming read: 在循环开始前先获取一次输入
    printf("Enter a number: ");
    scanf("%s", input);

    // 使用第一次输入的值作为循环条件
    while (strcmp(input, "done") != 0) {
        // 处理输入
        if (sscanf(input, "%d", &number) == 1) {
            sum += number;
            count++;
        } else {
            printf("Invalid input. Please enter a number.\n");
        }
        
        // 获取下一次输入（为下一次循环迭代准备）
        printf("Enter a number: ");
        scanf("%s", input);  // 这里重复了输入代码
    }

    printf("You entered %d numbers. Sum: %d\n", count, sum);
    return 0;
}