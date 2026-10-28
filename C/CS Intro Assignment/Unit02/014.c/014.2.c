#include<stdio.h>
int main(){
    int N,total=1,i;
    printf("Calculate the Factorial of N.\n");
    printf("N is?");
    scanf("%d",&N);

    i=1;
    while(i<=N){
        total=total*i;
        i=i+1;
    }
    printf("The result is %d.\n",total);
    return 0;
}