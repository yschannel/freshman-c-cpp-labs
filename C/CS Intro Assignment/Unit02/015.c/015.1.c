#include<stdio.h>
int main(){
    int N; 
    printf("打印N阶乘法表\n");
    printf("N=?");
    scanf("%d",&N);
    
    for (int i=1,j=1,k;i<=N;i++){
        printf("\n");
        k=i*j;
        printf("%d",k);
        if (N==1)
        break;
        for (int i2=i,j2=j+1,k2;j<=N;j2++){
            k2=i2*j2;
            printf(" %d",k2);
        }

    }
    return 0;
}