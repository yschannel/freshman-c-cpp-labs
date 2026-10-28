//Define a global variable sum, write function increment()
//to add 1 to it, and function getSum() to return the value of sum.
//Call the functions in main() to verify.
#include<stdio.h>
int sum=0;
void increment();
int getSum();
int main(){
    increment();
    printf("%d\n",getSum());
    return 0;
}
void increment(){
    sum++;
}
int getSum(){
    return sum;
}