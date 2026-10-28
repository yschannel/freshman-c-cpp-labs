//18.Write a program to display the following diagram on the screen.
// The number of rows in the figure should be a #define constant, 
//which has the value 8 for this sample run.
// You should output the first 4 lines and then the following 8 lines.
#include<stdio.h>
#define Rows 8
int main(){
    for(int i=1;i<=4;i++){
        for(int j=1;j<=i;j++){
            printf("*");
        }
        printf("\n");
    }

    for (int i=1;i<=Rows;i++){
        for (int j=1;j<=Rows-i;j++){
            printf(" ");
        }
        for(int k=1;k<=(2*i-1);k++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}