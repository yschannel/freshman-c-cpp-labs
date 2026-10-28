#include<stdio.h>

int main() {
    int N;
    printf("计算1到N的所有正整数的阶乘和\n");
    printf("请输入N:");
    scanf("%d", &N);
    
    long long total_sum = 0;  // 累计总和
    long long factorial = 1;  // 当前阶乘值
    
    for(int i = 1; i <= N; i++) {
        factorial *= i;           // 计算i的阶乘
        total_sum += factorial;   // 累加到总和
        printf("1!+2!+...+%d! = %lld\n", i, total_sum);
    }
    
    return 0;
}
