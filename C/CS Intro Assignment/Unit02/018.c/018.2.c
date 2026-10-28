#include <stdio.h>

int main() {
    int n;
    
    printf("Enter the number of Fibonacci numbers to generate: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Please enter a positive number.\n");
        return 1;
    }
    
    // Use long long to handle larger numbers
    long long fib[n];
    
    // Handle first two numbers
    if (n >= 1) fib[0] = 0;
    if (n >= 2) fib[1] = 1;
    
    // Generate remaining numbers
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    
    // Print the sequence
    printf("Fibonacci sequence: ");
    for (int i = 0; i < n; i++) {
        printf("%lld", fib[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("\n");
    
    return 0;
}