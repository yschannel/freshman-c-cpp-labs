//12.Write a function letterCount() to count the number 
//of letters in a string. Call the function in main() 
//to count letters in "Hello World".
#include<stdio.h>
#include<string.h>
long long unsigned int letterCount(char str[]){
    long long unsigned int num=0;
    for (long long unsigned int i=0;i<=strlen(str)-1;i++){
        for(long long unsigned int j=65;j<=90;j++){
            if (str[i]==j) num++;
        }
        for(long long unsigned int k=97;k<=122;k++){
            if (str[i]==k) num++;
        }
    }
    return num;
}
//优化
//#include <stdio.h>
//#include <string.h>

//int letterCount(char str[]) {
//    int num = 0;
//    for (int i = 0; i < strlen(str); i++) {
//        if ((str[i] >= 'A' && str[i] <= 'Z') || 
//            (str[i] >= 'a' && str[i] <= 'z')) {
//            num++;
//        }
//    }
//    return num;
//}
int main(){
    printf("%lld",letterCount("Hello World"));
    return 0;
}