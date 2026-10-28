#include <stdio.h>

int main() {
    double num1, num2, result;
    char operator;
    int choice;
    int usePreviousResult = 0;
    
    do {
        printf("\n=== 简易计算器 ===\n");
        printf("1. 新计算\n");
        printf("2. 使用上轮结果继续计算\n");
        printf("3. 退出\n");
        printf("请选择: ");
        scanf("%d", &choice);
        
        if(choice == 3) break;
        
        if(choice == 1 || !usePreviousResult) {
            printf("请输入第一个操作数: ");
            scanf("%lf", &num1);
        } else {
            num1 = result; // 使用上一次的结果
        }
        
        printf("请输入运算符 (+, -, *, /): ");
        scanf(" %c", &operator);
        
        // 验证运算符
        if(operator != '+' && operator != '-' && operator != '*' && operator != '/') {
            printf("错误: 无效的运算符!\n");
            continue;
        }
        
        printf("请输入第二个操作数: ");
        scanf("%lf", &num2);
        
        // 检查除零错误
        if(operator == '/' && num2 == 0) {
            printf("错误: 除数不能为0!\n");
            continue;
        }
        
        // 执行计算
        switch(operator) {
            case '+': result = num1 + num2; break;
            case '-': result = num1 - num2; break;
            case '*': result = num1 * num2; break;
            case '/': result = num1 / num2; break;
        }
        
        printf("结果: %.2lf %c %.2lf = %.2lf\n", num1, operator, num2, result);
        usePreviousResult = 1; // 标记有可用的结果
        
    } while(1);
    
    printf("感谢使用计算器!\n");
    return 0;
}