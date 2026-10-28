#include<stdio.h>
#include<string.h>
#include<ctype.h>
//法一 isalpha在ctype
size_t letterCount(char str[]){  //用size_t防止sizeof退化成指针
    size_t count =0;
    for(size_t i=0;str[i]!='\0';i++){
        if(isalpha(str[i])) count++;
    }
    return 0;
}
//法二 不用ctype
size_t letterCountB(char str[]){
    size_t count=0;
    for(size_t i=0;str[i]!='\0';i++){
        if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z'))
            count++;
    }
    return 0;
}
