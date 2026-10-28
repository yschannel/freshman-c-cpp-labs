//9.Write a program to input 5 numbers and find the largest and smallest 
//using conditional and relational operators.
#include<stdio.h>
int main(){
    int a,b,c,d,e;
    printf("Please input 5 number:");
    scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);

    if(a>=b && a>=c && a>=d && a>=e ){
        printf("The largest:%d\n",a);
    }else if (b>=c && b>=d && b>=e ){
        printf("The largest:%d\n",b);
    }else if (c>=d && c>=e ){
        printf("The largest:%d\n",c);
    }else if (d>=e ){
        printf("The largest:%d\n",d);
    }else{
        printf("The largest:%d\n",e);
    }
    
    if(a<=b && a<=c && a<=d && a<=e ){
        printf("The smallest:%d\n",a);
    }else if (b<=c && b<=d && b<=e ){
        printf("The smallest:%d\n",b);
    }else if (c<=d && c<=e ){
        printf("The smallest:%d\n",c);
    }else if (d<=e ){
        printf("The smallest:%d\n",d);
    }else{
        printf("The smallest:%d\n",e);
    }
    return 0;
}