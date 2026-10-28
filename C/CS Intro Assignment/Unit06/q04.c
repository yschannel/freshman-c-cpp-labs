#include<stdio.h>
int main(){
    int array[11];
    int k = 0;
    for (size_t i = 0;i < sizeof(array)/sizeof(array[0]);i++,k++){
        array[i]=k*k;
    }
    for (size_t j =0;j < sizeof(array)/sizeof(array[0]);j++){
        printf("%d ",array[j]);
    }
    return 0;
}