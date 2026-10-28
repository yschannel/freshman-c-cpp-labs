#include<stdio.h>
int main(){
    int N,total=0,i=1;
    printf("Calculate the Sum of Integers from 1 to N.\n");
    printf("N is?");
    scanf("%d",&N);
    do{
        total=total+i;
        i=i+1;
    }while(i<=N);
    printf("The sum is %d.\n",total);
    return 0;
}