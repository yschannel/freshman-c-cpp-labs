#include <iostream>
#include <stdexcept>

class Vec3D {
private:
    double data_[3]{};

public:
    double& operator[](int index) {
        // TODO 1: 判断 index < 0 || index >= 3。
        // TODO 2: 条件成立时 throw std::out_of_range("Vec3D index out of range");
        // 预测表：失败发现位置是 operator[]，抛出类型是 std::out_of_range。
        return data_[index];
    }
};

int main() {
    try {
        Vec3D v;
        v[0] = 1.0;
        v[3] = 2.0;
        std::cout << "This line will not execute after throw.\n";
    } catch (const std::out_of_range& e) {
        // 预测表：越界异常首先匹配此 catch。
        std::cout << e.what() << '\n';
    }
    return 0;
}
