#include<stdio.h>
int main(){
    int N;
    printf("计算1到N的所有正整数的阶乘和\n");
    printf("请输入N:");
    scanf("%d",&N);

    for(int i=1;i<=N;i++){
        for(int result=1,total=0,i1=1;i1<=i;i1++){
            result=result*i1;
            total=total+result;
            if (i1==i){
                printf("%d\n",total);
            }
        }
    }
    return 0;
}