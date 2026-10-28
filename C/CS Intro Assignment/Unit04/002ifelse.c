#include "stdio.h"
#include "stdlib.h"
int main() {
    int op1, op2, result;
    char op;
    printf("A simple calculator.\n");
    printf("Enter the expression:");
    scanf("%d", &op1);
    op = getchar();
    scanf("%d", &op2); 
    if (op == '+')
        result = op1 + op2;
    else if (op == '-')
        result = op1 - op2;
    else if (op == '*')
        result = op1 * op2;
    else
        result = op1 / op2;
    printf(" = %d.\n", result);
 
#if defined(_WIN32)
    system("pause");
#endif
 
    return 0;
}
