//11.Write a recursive function factorial 
//to calculate the factorial of a number.
//Call the function in main() to calculate the factorial of 5.
#include<stdio.h>
int factorial(unsigned int n){
    if(n==0)return 1;
    if(n==1){
        return 1;
    }else{
        return n*factorial(n-1);
    }
}
int main(){
    printf("%d",factorial(5));
    return 0;
}