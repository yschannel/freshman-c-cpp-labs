#include<stdio.h>
int main(){
    int amount,next,total;
    printf("Add certain numbers.\n");
    scanf("%d",&amount);
    printf("first number?");
    scanf("%d",&total);

    for (int i=1;i<=amount;i++){
        printf("next number?");
        scanf("%d",&next);
        total=total+next;
    }
    printf("total is %d.\n",total);
    return 0;
}