#include <stdio.h>

// 定义一个枚举类型
enum Weekday {
    MONDAY,    // 0
    TUESDAY,   // 1
    WEDNESDAY, // 2
    THURSDAY,  // 3
    FRIDAY,    // 4
    SATURDAY,  // 5
    SUNDAY     // 6
};

// 也可以显式指定值
enum Status {
    OK = 200,
    NOT_FOUND = 404,
    SERVER_ERROR = 500
};

int main() {
    // 声明枚举变量
    enum Weekday today = WEDNESDAY;
    enum Status response = OK;
    
    // 使用枚举
    if (today == FRIDAY) {
        printf("It's Friday!\n");
    }
    
    // 枚举值可以直接当整数使用
    printf("Today is day number %d\n", today);      // 输出: Today is day number 2
    printf("Status code: %d\n", response);          // 输出: Status code: 200
    
    // 遍历枚举值 (注意：C语言枚举不是强类型，需要小心边界)
    for (int i = MONDAY; i <= SUNDAY; i++) {
        printf("Day %d\n", i);
    }
    
    return 0;
}