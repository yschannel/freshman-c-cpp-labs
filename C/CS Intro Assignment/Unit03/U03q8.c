//8.Write a program to input a year and check 
//if it is a leap year using logical operators && and ||.
#include<stdio.h>
int main(){
    int year;
    printf("Please input a year you want to check:");
    scanf("%d",&year);

    if(year<=0){
        printf("Year must be positive!");
        return 1;   
    }


    if((year%4==0 && year%100!=0) || (year%400==0)){
        printf("It is a leap year.");
    }else{
        printf("It is not a leap year.");
    }
    return 0;
}