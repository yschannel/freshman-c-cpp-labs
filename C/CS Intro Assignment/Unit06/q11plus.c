#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int main(){
    char str[10];
    
    if(fgets(str,sizeof(str),stdin)==NULL){
        printf("Invalid Input\n");
        return 1;
    }

    bool truncated = false;
    size_t len = strlen(str);
    truncated = (len > 0 && str[len-1] != '\n' && len == sizeof(str)-1);

    if(truncated){
        printf("Data Truncated.Keep only the first %zu characters\n",len);
        printf("Current content:%s\n",str);

        printf("Flushing the input buffer...\n");
        int c;
        int discarded_chars = 0;
        while((c=getchar()) != '\n' && c != EOF){
            discarded_chars++;
        }
        printf("%d extra characters discarded\n",discarded_chars);
    }else{
        if(len>0 && str[len-1] == '\n'){
            str[len-1]='\0';
            len--;
        }
        printf("Complete input:%s\n",str);
    }
    printf("Final length:%zu\n",len);
    return 0;
}