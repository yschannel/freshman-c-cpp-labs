//13.In a sorted one-dimensional array, 
//write a program that finds and returns 
//the position of a specified element.

/*回复地址了
#include<stdio.h>
int main(){
    int str[] = {1,2,3,4,5,6,7,8,9};
    int element; 
    scanf("%d",&element);
    for(size_t i =0;i < sizeof(str) / sizeof(str[0]);i++){
        if(str[i] == element){
            printf("%p",str+i);
            return 0;
        }
    }
    printf("Not found");
    return 1;
}
    */
#include<stdio.h>
int main(){
    int str[] = {1,2,3,4,5,6,7,8,9};
    int element; 
    scanf("%d",&element);
    for(size_t i =0;i < sizeof(str) / sizeof(str[0]);i++){
        if(str[i] == element){
            printf("%zu",i);
            return 0;
        }
    }
    printf("Not found");
    return 1;
}