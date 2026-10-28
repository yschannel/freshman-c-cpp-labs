//13.Write a function equalString() to check 
//if two strings are equal.
// Call the function in main() to check 
//if "abc" and "abc" are equal.
#include<stdio.h>
#include<string.h>
int equalString(char str1[],char str2[]){
    if(!strcmp(str1,str2)){
        return 1;
    }else return 0;
}
int main(){
    if(equalString("abc","abc")){
        printf("equal");
    }else printf("not equal");
    return 0;
}
//法二 用bool
//#include<stdio.h>
//#include<string.h>
//#include<stdbool.h>

//bool equalString(char str1[], char str2[]){
//    return strcmp(str1, str2) == 0;
//}

//法三 自己设计
//int equalString(char str1[], char str2[]){
//    int i = 0;
//    while(str1[i] != '\0' && str2[i] != '\0'){
//        if(str1[i] != str2[i]){
//           return 0;
//        }
//        i++;
//    }
//    // 检查是否都到达字符串结尾
//    return (str1[i] == '\0' && str2[i] == '\0');
//}