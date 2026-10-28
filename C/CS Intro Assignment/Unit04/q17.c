//Write a program that reads in the month (1-12) and 
//prints the number of days in that month using switch-case. Handle leap years properly.
#include<stdio.h>
int main(){
    int year,month;
    printf("Please input the year.");
    scanf("%d",&year);
    printf("PLease input the month.");
    scanf("%d",&month);
    switch(month){
        case 1:case 3:case 5:case 7:case 8:case 10:case 12:
        printf("It includes 31 days.");
        break;
        case 4:case 6:case 9:case 11:
        printf("It includes 30 days.");
        break;
        default:
        if (month !=2){
            printf("Please input a month!");
            break;
        }else if((year%4==0 && year%100!=0)||(year%400==0)){
            printf("It includes 29 days.");
            break;
        }else{
            printf("It includes 28 days.");
            break;
        }
    }
    return 0;
}