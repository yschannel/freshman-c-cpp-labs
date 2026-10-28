#include <iostream>
#include <typeinfo> // 必须包含这个头文件

using namespace std;

int main() {
    int a = 10;
    auto au_a = a; // au_a 是 int

    // 获取类型信息对象
    const type_info& t = typeid(au_a);

    // 输出类型名称
    cout << "类型名称是: " << t.name() << endl;

    // 也可以直接比较类型
    if (typeid(au_a) == typeid(int)) {
        cout << "au_a 确实是 int 类型！" << endl;
    }

    return 0;
}