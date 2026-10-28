//15.Write a program that reads in three integers and 
//prints the smallest number. Use nested if-else statements.
#include<stdio.h>
int get_integer_input(int *num1,int *num2,int *num3){
    printf("Please input three integers:");
    return scanf("%d %d %d",num1,num2,num3);
}

int main(){
    int num1,num2,num3;
    if(get_integer_input(&num1,&num2,&num3)!=3){
        printf("Invaid input!Please input integer.\n");
        return 1;
    }
    
    if(num1<=num2&&num1<=num3){
        printf("The smallest number:%d",num1 );
    }else if(num2<=num3){
        printf("The smallest number:%d",num2 );
    }else{
        printf("The smallest number:%d",num3);
    }
    return 0;
}