#include<stdio.h>
int main(){
    long long N;
    printf("Check for Prime Number\n");
    printf("Please input a Number:");
    scanf("%lld",&N);
    for (long long i=2;i<N;i++){
        if(N%i==0){
            printf("%lld isn't a Prime Number\n",N);
            break;
        }
        
    }

}