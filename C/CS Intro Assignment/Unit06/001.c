#include<stdio.h>
int main(int argc, char const* argv[]){
    char board[3][3] = {};
    for (size_t i = 0;i < sizeof(board) / sizeof(board[0]);i++){
        *((char*)board + i) = (char) ('a' + i);
    }

    for (size_t i = 0; i < 3; i++){
        for (size_t j = 0; j < 3; j++){
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    return 0;
}