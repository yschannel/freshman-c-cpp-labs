#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main() {
    char str[3001];
    fgets(str, 3001, stdin);
    
    int digit_count = 0;
    int max_gap = 0;
    
    // 统计数字个数
    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) {
            digit_count++;
        }
    }
    
    // 寻找所有e和g的位置，计算最大间隔
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'e' || str[i] == 'E') {
            // 从这个e开始向后找g
            for (int j = i + 1; str[j] != '\0'; j++) {
                if (str[j] == 'g' || str[j] == 'G') {
                    int gap = j - i - 1;  // 计算e和g之间的字符数
                    if (gap > max_gap) {
                        max_gap = gap;
                    }
                    break;  // 找到第一个g就计算间隔，然后继续找下一个e
                }
            }
        } else if (str[i] == 'g' || str[i] == 'G') {
            // 从这个g开始向后找e
            for (int j = i + 1; str[j] != '\0'; j++) {
                if (str[j] == 'e' || str[j] == 'E') {
                    int gap = j - i - 1;  // 计算g和e之间的字符数
                    if (gap > max_gap) {
                        max_gap = gap;
                    }
                    break;  // 找到第一个e就计算间隔，然后继续找下一个g
                }
            }
        }
    }
    
    printf("%d %d\n", digit_count, max_gap);
    return 0;
}