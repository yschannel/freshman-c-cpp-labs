#include<stdio.h>
int main(){
    int N,total=1,i=1;
    printf("Calculate the Factorial of N.\n");
    printf("N is?");
    scanf("%d",&N);
    do{
        total=total*i;
        i=i+1;
    }while(i<=N);
    printf("The result is %d.\n",total);
    return 0;
}