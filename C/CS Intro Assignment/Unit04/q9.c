#include <stdio.h>

int main() {
    int a = 0;
    int b = 10;
    
    // 逻辑与的短路求值
    if (a != 0 && b / a > 1) {
        printf("这行不会打印\n");
    } else {
        printf("由于a为0，逻辑与短路，避免了除以0的错误\n");
    }
    
    // 逻辑或的短路求值
    if (a == 0 || b / a > 1) {
        printf("由于a为0，逻辑或的第一个条件为真，短路，不会计算第二个条件，避免了除以0的错误\n");
    } else {
        printf("这行不会打印\n");
    }
    
    return 0;
}