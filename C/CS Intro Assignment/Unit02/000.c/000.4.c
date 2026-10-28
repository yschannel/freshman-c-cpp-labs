#include<stdio.h>
int main(){


int next,total;
printf("Add indeterminate numbers.\n");
printf("1st number?");
scanf("%d",&total);

do{
    printf("next number?('0'to stop)");
    scanf("%d",&next);
    total=total+next;
}while (next!=0);
printf("The total id %d.\n",total);
return 0;
}
