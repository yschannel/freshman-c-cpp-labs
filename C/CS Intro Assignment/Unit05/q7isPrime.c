//Write a function isPrime() to determine if a number is prime. 
//Call the function in main() to check if 101 is prime.
#include<stdio.h>
#include<math.h>
int isPrime(unsigned int num){
    if(num==1)return 0;
    if(num==2)return 1;
    if(num%2==0)return 0;
    int mid = sqrt(num);
    if(num>2&&num%2!=0)
        for(int i=3;i<=mid;i+=2){
            if(num%i==0)return 0;
        }
    return 1;
}
int main(){
    int n=isPrime(101);
    if(n)printf("Yes");
    if(!n)printf("No");
    return 0;
}