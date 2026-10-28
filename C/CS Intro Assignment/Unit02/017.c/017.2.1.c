#include<stdio.h>
#include<math.h>

int main(){
    long long N;
    printf("Check for Prime Number.\n");
    printf("Please input a number:");
    scanf("%lld",&N);

    //处理特殊情况
    if(N<2){
        printf("%lldisn't a Prime Number.",N);
        return 0;
    }
    if(N==2){
        printf("%lldis a Prime Number.",N);
        return 0;
    }
    if(N%2==0){
        printf("%lldisn't a Prime Number.",N);
        return 0;
    }

    int isPrime=1; //假设是素数
    //只需检查到平方根且跳过偶数
    for (long long i=3;i<=sqrt(N);i+=2){
        if(N%i==0){
            isPrime=0;
            break;
        }
    }

    if(isPrime){
        printf("%lldis a Prime Number.",N);
    }else{
        printf("%lldisn't a Prime Numcer.",N);
    }
    return 0;
}