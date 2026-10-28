//11.Write a program that prompts the user
// to input a string and then prints the length of the string.
/*
#include<stdio.h>
#include<string.h>
int main(){
    char str[]={};
    scanf("%s",str);
    printf("%lld\n",strlen(str)/sizeof(str[0]));
    int len=0;
    for(;str[len] != '\0';){
        len ++;
    }
    printf("%lld",len/sizeof(str[0]));
    return 0;
}
*/

#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
    scanf("%99s",str);
//法一
    printf("%zu\n",strlen(str));
//法二
    size_t len = 0;
    while(str[len] != '\0'){
        len++;
    }
    printf("%zu",len);
    
    return 0;
}