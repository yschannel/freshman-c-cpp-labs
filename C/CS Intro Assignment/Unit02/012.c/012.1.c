#include<stdio.h>
int main(){
    int N;
    printf("Print Integers from 1 to N.\n");
    printf("N is?");
    scanf("%d",&N);
    for (int i=1;i<=N;i++){
    printf("%d\n",i);
    }
    return 0;
}