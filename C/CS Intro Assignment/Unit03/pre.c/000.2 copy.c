#include<stdio.h>
int main(){
    printf("Bytes of data types:\n");
    printf("%-12s is: %zu\n", "short int", sizeof(short int));
    printf("%-12s is: %zu\n", "int", sizeof(int));
    printf("%-12s is: %zu\n", "long int", sizeof(long int));
    printf("%-12s is: %zu\n", "float", sizeof(float));
    printf("%-12s is: %zu\n", "double", sizeof(double));
    printf("%-12s is: %zu\n", "char", sizeof(char));
    return 0;
}  //%-12s的使用  -为左对齐标志 12是字段宽度 %格式说明符