//12.Write a program that creates a 3x3 two-dimensional 
//integer array and 1) uses a single loop to iterate through 
//and print all elements, 2) uses nested loops to 
//iterate through the array, and prints each element.
#include<stdio.h>
int main(){
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};//嵌套初始化
    printf("1)\n");
    for (size_t i = 0;i < 9;i++){
        printf("%d ",*(*arr + i));//正确的访问 x:arr[i]指第i行地址
    }
    printf("\n2)\n");
    for(size_t j = 0;j < 3;j++){
        for(size_t k = 0;k < 3;k++){
            printf("%d ",arr[j][k]);
        }
        printf("\n");
    }
    return 0;
}