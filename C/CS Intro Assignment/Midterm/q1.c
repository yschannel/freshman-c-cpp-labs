/**
 * @file q1.c
 * @brief Program to calculate sum and average of three sets of integers
 */
#include<stdio.h>

int main(void)
{
    int i=1;  /**< Loop counter for the three iterations */
    
    do{
        int num1, num2, num3;  /**< Variables to store user input */
        char next_char;

        printf("Please input three integers:");
        
        int result = scanf("%d %d %d",&num1,&num2,&num3);

        /* Check if input buffer ends with newline (no trailing characters) */
        _Bool is_clean = (scanf("%c",&next_char) == 1 && next_char == '\n');
        
        /* Handle invalid input */
        if(result != 3 || !is_clean){
            /* Clear input buffer */
            while(getchar() != '\n'){
                /* Empty loop body */
            }
            printf("Invalid input!Please input correct three integers.\n");
            continue;
        }
        
        /** Calculate the sum of the three integers */
        int sum = num1 + num2 + num3;
        
        /** Calculate the average with float type casting */
        double average = (double)sum / 3.0;
        
        /* Display the calculated results */
        printf("Sum: %d, Average: %.2f\n",sum,average);
        
        i++;///< Increment loop counter

    } while (i <= 3);
    
    return 0;///< program terminated successfully
}