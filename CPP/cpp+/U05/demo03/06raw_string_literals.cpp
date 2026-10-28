#include<iostream>
const char *s1 = R"(Hello
World)";
const char *s2 = "Hello\nWorld";
const char *s3 = R"NoUse(Hello
World)NoUse";

int main(){
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << s3 << std::endl;

    return 0;
}