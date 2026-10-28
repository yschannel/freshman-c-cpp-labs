#include<stdio.h>
int main(){
    int N; 
    printf("打印N阶乘法表\n");
    printf("N=?");
    scanf("%d",&N);
    
    for (int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            printf("%d ",i*j);
        }
    printf(" \n");    
    }
    return 0;
}