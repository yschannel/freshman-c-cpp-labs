#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
    char spe,ex;

    printf("Enter a string:");
    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")] = '\0';//strcspn需要同类型，所以是"\n"

    printf("Enter a character to find:");
    scanf("%c",&spe);
    printf("Enter a character to replace with:");
    scanf(" %c",&ex);//细节空格处理换行符

    int found = 0;
    int count = 0;

    for(int i = 0;str[i] != '\0';i++){
        if(str[i] == spe){
            str[i] = ex;
            found = 1;
            count++;
        }
    }

    if(found){
        printf("After replacement:%s\n",str);
        printf("Replaced %d occurrence(s) of '%c' with '%c'\n",count,spe,ex);
    }else{
        printf("Character '%c' not found in the string\n",spe);
    }
    return 0;
}