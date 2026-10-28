#include<stdio.h>
int main(){
    int N,i;
    printf("Print Integers from 1 to N.\n");
    printf("N is?");
    scanf("%d",&N);

    i=1;
    while(i<=N){
        printf("%d\n",i);
        i=i+1;
    }
    return 0;
}