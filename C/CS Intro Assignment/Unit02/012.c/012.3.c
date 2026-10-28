#include<stdio.h>
int main(){
    int N,i=1;
    printf("Print Integers from 1 to N.\n");
    printf("N is?");
    scanf("%d",&N);

    do{
        printf("%d\n",i);
        i=i+1;
    }while(i<=N);
    return 0;
}