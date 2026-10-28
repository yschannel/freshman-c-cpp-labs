#include<stdio.h>
int main(){
    int N,total=0;
    printf("Calculate the Sum of Integers from 1 to N.\n");
    printf("N is?");
    scanf("%d",&N);
    for (int i=1;i<=N;i++){
    total=total+i;
    }
    printf("The sum is %d.\n",total);
    return 0;
}