#include<stdio.h>
int main(){
    int amount,next,total,i=1;
    printf("Adds certian numbers.\n");
    printf("Enter the amount:");
    scanf("%d",&amount);
    printf("1st number?");
    scanf("%d",&total);
    
    //i=1;
    do {
        printf("next number?");
        scanf("%d",&next);
        total=total+next;
        i=i+1;
    } while (i<=amount);
    printf("The total is %d.\n",total);
    return 0;
}