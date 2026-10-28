#include<stdio.h>
int main(){
    int N,total=1;
    printf("Calculate the Factorial of N.\n");
    printf("N is?");
    scanf("%d",&N);
    for (int i=1;i<=N;i++){
    total=total*i;
    }
    printf("The result is %d.\n",total);
    return 0;
}