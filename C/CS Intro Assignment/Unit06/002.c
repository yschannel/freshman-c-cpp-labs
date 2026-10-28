#include<stdio.h>
int main(){
    char str[4] = {'A','B','\n'};
    for (size_t i = 0;i <= sizeof(str) && str[i] != '\0';i++){
        printf("%c",str[i]);
    }
    return 0;
}