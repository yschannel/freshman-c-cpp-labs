//Write a program that reads in two integers and 
//prints out the larger number. Use if-else statements.
#include<stdio.h>
int get_integer_input(int *num1,int *num2){  //函数声明定义
    printf("Please input two integers:");
    return scanf("%d %d",num1,num2);  //成功会返回2
}
int main(){
    int num1,num2;

    if(get_integer_input(&num1,&num2)!=2){
        printf("Invaid input!Pliease input integer.\n");
        return 1;  //异常结束
    }

    if(num1<=num2){
        printf("The largest number:%d",num2);
    }else{
        printf("The largest number:%d",num1);
    }
    return 0;
}
