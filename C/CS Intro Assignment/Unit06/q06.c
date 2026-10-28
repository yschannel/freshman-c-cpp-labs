//6.Write a C expression that computes 
//the number of bytes needed to represent an array 
//containing NElements values of type double.

/*  错解！！！！
#include<stdio.h>
int main(){
    size_t N = scanf("%llu",&N);
    double array[N];
    printf("%llu",sizeof(array));
    return 0; 
}
*/
#include<stdio.h>
int main(){
    size_t N;
    scanf("%zu",&N);
    size_t bytes_needed = N * sizeof(double);
    printf("%zu",bytes_needed);
    return 0;
}