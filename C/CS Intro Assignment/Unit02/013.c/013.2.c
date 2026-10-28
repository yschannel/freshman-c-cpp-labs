#include<stdio.h>
int main(){
    int N,total=0,i;
    printf("Calculate the Sum of Integers from 1 to N.\n");
    printf("N is?");
    scanf("%d",&N);

    i=1;
    while(i<=N){
        total=total+i;
        i=i+1;
    }
    printf("The sum is %d.\n",total);
    return 0;
}