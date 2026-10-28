#include <array>
int n = 1;
//n++; 全局不执行自增
//std::array<int, n> a1; n不是常量
const int cn = 2;
std::array<int, cn> a2; // cn is a const

const int rcn = n; //runtime constant,编译器不会在编译期知道它的值
//rcn = n++;  only-read
//std::array<int, rcn> a3;  在编译期未知

//=======================================================================//
//constexpr 编译期常量
constexpr int max(int a, int b){
    if(a>b) 
        return a;
    else
        return b;
}

int main(){
    int m = 1;
    const int rcm = m; //运行期常量
    const int cm = 4; //编译期常量

    int a1[max(m, rcm)]; //都不是编译期常量error
    std::array<char, max(cm, 5)> a2; //都是编译期常量

    return 0;
}

