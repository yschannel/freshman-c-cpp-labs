#include<stdio.h>
#include<math.h>

int main(){
    long long N;
    printf("Check for Prime Number\n");
    printf("Please input a Number: ");
    scanf("%lld", &N);
    
    // 处理特殊情况
    if(N < 2){
        printf("%lld isn't a Prime Number\n", N);
        return 0;
    }
    if(N == 2){
        printf("%lld is a Prime Number\n", N);
        return 0;
    }
    if(N % 2 == 0){
        printf("%lld isn't a Prime Number\n", N);
        return 0;
    }
    
    int isPrime = 1; // 假设是素数
    
    // 只需检查到平方根，且跳过偶数
    for(long long i = 3; i <= sqrt(N); i += 2){
        if(N % i == 0){
            isPrime = 0; // 找到因子，不是素数
            break;
        }
    }
    
    if(isPrime){
        printf("%lld is a Prime Number\n", N);
    } else {
        printf("%lld isn't a Prime Number\n", N);
    }
    
    return 0;
}