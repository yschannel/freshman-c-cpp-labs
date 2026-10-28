//Write a program to separate and print the high and low bytes of an integer
// in hexadecimal format. 
#include<stdio.h>
int main(){
    int num=0x12345678;
    int high_bytes,low_byets;

    high_bytes=num>>16;
    low_byets=num&0x0000FFFF;

    printf("The original integer:%x\n",num);
    printf("The high bytes:%x\n",high_bytes);
    printf("The low bytes:%x\n",low_byets);
    return 0;
}