#include<stdio.h>
int main(){
    int amount=0,next=0,total=0,i;
    printf("Add certain numbers.\n");
    printf("Enter the amount:");
    scanf("%d",&amount);
    printf("1st number?");
    scanf("%d",&total);

    i=1;
    while (i <= amount){
        printf("next number?");
        scanf("%d",&next);
        total=total+next;
        i=i+1;
    }
    printf("Total is %d.\n",total);
    return 0;
}