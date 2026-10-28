#include<stdio.h>
int main(){
    int a,b,c,d,e;
    int max,min;

    printf("Please input 5 number.\n");
    scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);

    max=min=a;

    if (max<=b) max=b;
    if (max<=c) max=c;
    if (max<=d) max=d;
    if (max<=e) max=e;

    if (min>=b) min=b;
    if (min>=c) min=c;
    if (min>=d) min=d;
    if (min>=e) min=e;

    printf("The largest:%d\n",max);
    printf("The smallest:%d\n",min);
    return 0;
}