//15.Write a program that uses a character array 
//to store a string, finds and replaces a specified character 
//within the string.
#include<stdio.h>
int main(){
    char str[] = "abcdefghijklma";
    char spe,ex;
    scanf("%c %c",&spe,&ex);
    size_t i = 0;
    int found = 0;
    while(str[i] != '\0'){
        if(str[i] == spe){
            str[i] = ex;
            found++;
        }
        i++;
    }
    if(found){
        printf("%s",str);
    }else{
        printf("Not find");
    }
    return 0;
}
