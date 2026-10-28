/**
 * @file q2.c
 * @brief Program to print a right angle triangle pattern using the "*" character
 */
#include<stdio.h>

int main(void)
{
    /* Outer loop to set counter of pattern line */
    for(int i = 1;i <= 5;i++){
        int j = 1;///< blank counter
        
        /* Output blank */
        while(j <= 5-i){
            printf(" ");
            j++;
        }
        
        int k = 1;///< star counter
        
        /* Output star */
        while(k<=i){
            printf("*");
            k++;
        }
  
        printf("\n");

    }

    return 0;//Program terminated successfully
}