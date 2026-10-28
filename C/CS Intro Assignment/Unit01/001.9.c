#include<stdio.h>
int main(void){
    int num1,num2,total;
    printf("The program adds two numbers.\n");
    
    printf("Please input number1:");
    scanf("%d",&num1);
    printf("Please input number2:");
    scanf("%d",&num2);
    total=num1 + num2;
    printf("The sum of two number is %d\n",total);
    return 0;
}