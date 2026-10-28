#include<stdio.h>
int print_line(unsigned int len){
    unsigned int i=len;
    while (i-->0)
        printf("-");
    printf("\n");
    return len;
}
int main(){
    print_line(0);
    return 0;
}