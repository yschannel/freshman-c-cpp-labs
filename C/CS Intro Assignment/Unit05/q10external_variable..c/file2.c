//file2.c
#include<stdio.h>
#include<stdlib.h>
extern int count;
void print_count();
int main(){
    printf("count2:%d\n",count);
    print_count();
    system("pause");//停留
    return 0;
}