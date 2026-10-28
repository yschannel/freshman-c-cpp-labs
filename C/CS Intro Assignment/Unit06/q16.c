/*16.Implement a function Capitalize (str) 
that returns a string in which the initial character 
is capitalized (if it is a letter) and 
all other letters are converted 
so that they appear in lowercase form. 
Characters other than letters are not affected. 
For example, Capitalize (“BOOLEAN”) and 
Capitalize (“boolean”) should each return the string “Boolean”.*/
#include<stdio.h>
#include<ctype.h>
#include<string.h>
void Capitalize(char *str){
    if(strlen(str) == 0) return;
    if(isalpha(str[0])) str[0] = toupper(str[0]);
    for(size_t i = 1;str[i] != '\0';i++){
        if(isalpha(str[i])) str[i] = tolower(str[i]);
    }
}
int main(){
    char str[100];
    printf("Please input a string:");
    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")] = '\0';
    Capitalize(str);
    printf("%s",str);
    return 0;
}