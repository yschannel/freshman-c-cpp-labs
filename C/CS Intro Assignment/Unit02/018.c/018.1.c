#include <stdio.h>

int main() {
    int n;
    
    printf("Enter the number of Fibonacci numbers to generate: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Please enter a positive number.\n");
        return 1;
    }
    
    printf("Fibonacci sequence: ");
    
    if (n == 1) {
        printf("0\n");
    } else if (n == 2) {
        printf("0, 1\n");
    } else {
        long long first = 0, second = 1, next;
        
        printf("0, 1");
        
        for (int i = 3; i <= n; i++) {
            next = first + second;
            printf(", %lld", next);
            first = second;
            second = next;
        }
        printf("\n");
    }
    
    return 0;
}