#include <stdio.h>
// 将一个二维数组 char board[3][3] 填入 字母 a, b, c, d, e, f, g, h, i

int main(int argc, char const* argv[]) {
    char board[3][3] = {};

    // for 循环填满9个元素,  size_t : typedef unsigned long int size_t;
    for (size_t i = 0; i < sizeof(board) / sizeof(board[0][0]); i++) {
        *((char*)board + i) = (char)('a' + i);  // 将二维数组展成一维数组使用
    }

    // 输出二维数组的内容
    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}
