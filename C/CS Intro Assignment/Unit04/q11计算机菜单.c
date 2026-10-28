#include <stdio.h>

int main() {
    int a, b, choice;
    
    while (1) {
        printf("\n=== Calculator ===\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 5) {
            printf("Goodbye!\n");
            break;
        }
        
        if (choice < 1 || choice > 4) {
            printf("Invalid choice!\n");
            continue;  // 跳过本次循环剩余部分
        }
        
        printf("Enter two numbers: ");
        scanf("%d %d", &a, &b);
        
        switch (choice) {
            case 1: printf("Result: %d\n", a + b); break;
            case 2: printf("Result: %d\n", a - b); break;
            case 3: printf("Result: %d\n", a * b); break;
            case 4: 
                if (b != 0) {
                    printf("Result: %.2f\n", (float)a / b);  //格式的转换
                } else {
                    printf("Error: Division by zero!\n");
                }
                break;
        }
    }
    
    return 0;
}