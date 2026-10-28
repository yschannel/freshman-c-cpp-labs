#include <iostream>
#include <stdexcept>

class Vec3D {
public:
    static constexpr int kDimension = 3;

    double& operator[](int index) {
        // 失败发现位置：operator[] 承诺返回一个合法元素的引用。
        if (index < 0 || index >= kDimension) {
            // 承诺无法完成时，抛出能够描述范围错误的标准异常类型。
            throw std::out_of_range("Vec3D index out of range");
        }
        return data_[index];
    }

private:
    double data_[kDimension]{};
};

int main() {
    Vec3D v;
    const int indices[] = {0, 3};

    for (int index : indices) {
        try {
            v[index] = 1.0;
            std::cout << "index " << index << " accepted\n";
            // index=3 抛出异常后，不会到达本次 try 块的正常结束位置。
        } catch (const std::out_of_range& e) {
            // 更具体的 out_of_range 优先处理越界失败。
            std::cout << "out_of_range: " << e.what() << '\n';
        } catch (const std::exception& e) {
            // 标准异常基类作为较一般的后备处理程序。
            std::cout << "exception: " << e.what() << '\n';
        }
        std::cout << "after attempt " << index << '\n';
    }
    return 0;
}
