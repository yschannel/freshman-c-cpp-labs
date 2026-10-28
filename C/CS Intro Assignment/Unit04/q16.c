//16.Write a program that reads in a character and 
//prints whether it is a vowel or consonant using a switch-case statement.
#include<stdio.h>
#include<ctype.h>  //字符库
int main(){
    char character;
    printf("Please input a character.");
    scanf("%c",&character);
    char lowerChar =tolower(character);//转成小写
    switch(lowerChar){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        printf("It is a vowel.");
        break;
        default:
        if (isalpha(character)){ //检查是否为字母
            printf("It is a consonant.");
        }else{
            printf("It is not a letter.");
        }
        
    }
    return 0;
}