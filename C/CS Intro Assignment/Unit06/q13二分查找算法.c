//13.查找元素：In a sorted one-dimensional array,
// write a program that finds and returns 
//the position of a specified element.
#include<stdio.h>
#include<sys/types.h>//ssize_t有符号
ssize_t binary_search (size_t arr[],size_t size,size_t target){
    if(size == 0) return -1;
    size_t high = size - 1;
    size_t low = 0;
    while(high>=low){
        size_t mid = low + (high - low)/2;//避免上溢
        if(arr[mid] == target){
            return (ssize_t)mid;
        }else if(arr[mid] < target){
            low = mid + 1;
        }else{
            if(mid == 0)break;//避免下溢
            high = mid - 1;
        }
    } 
    return -1;
}
int main(){
    size_t arr[]={1,2,3,4,5,6,7,8,9,19};
    size_t target;
    printf("Input element:");
    scanf("%zu",&target);
    size_t size = sizeof(arr) / sizeof(arr[0]);
    ssize_t position = binary_search(arr,size,target);
    if(!position){
        printf("Not find\n");
        return 1;
    }
    printf("Its position:%zd",position);
    return 0;
}