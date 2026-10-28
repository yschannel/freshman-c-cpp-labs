//14.Write a program that stores 10 integers 
//using a one-dimensional array and sorts these integers 
//in ascending or descending order.
#include<stdio.h>
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubbling(int arr[],size_t size){
    for(size_t i = 0;i < size-1;i++){
        for(size_t j = 0;j < size-1-i;j++){
            if(arr[j]>arr[j+1]) swap(&arr[j],&arr[j+1]);//int要地址啊
        }
    }
}
int main(){
    int arr[10] = {9,8,7,6,5,4,3,2,1,0};
    bubbling(arr,sizeof(arr) / sizeof(arr[0]));
    for(size_t k = 0;k < 10;k++){
        printf("%d ",arr[k]);
    }
    return 0;
}