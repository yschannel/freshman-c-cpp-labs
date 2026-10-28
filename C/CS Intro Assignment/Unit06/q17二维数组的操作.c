//17.Write a program that creates a 3x3 two-dimensional 
//integer array, finds and prints the maximum and minimum values
// within the array.
#include<stdio.h>
int main(){
    int arr[3][3] = {{2,5,1},{6,3,1},{4,7,9}};
    int max=arr[0][0],min=arr[0][0];
    for (size_t i = 0;i < 3;i++){
        for(size_t j = 0;j < 3;j++){
            if(arr[i][j] >= max) max = arr[i][j];
            if(arr[i][j] <= min) min = arr[i][j];
        }
    }
    printf("max:%d min:%d",max,min);
    return 0;
}