#include <iostream>
#include <stdexcept>

class Vec3D {
private:
    static constexpr int kDimension = 3;
    double data_[kDimension]{};

public:
    double& operator[](int index) {
        // operator[] 无法返回非法下标对应的引用，因此在这里发现失败。
        if (index < 0 || index >= kDimension) {
            throw std::out_of_range("Vec3D index out of range");
        }
        return data_[index];
    }
};

int main() {
    const int indices[] = {0, 3};
    for (int index : indices) {
        // TODO: 运行前先预测 index、抛出类型、第一个匹配 catch 与输出。
        try {
            Vec3D v;
            v[index] = 1.0;
            std::cout << "index " << index << " ok\n";
        } catch (const std::out_of_range& e) {
            // 具体类型在前，index=3 时命中此分支。
            std::cout << "out_of_range: " << e.what() << '\n';
        } catch (const std::exception& e) {
            // TODO: 调换两个 catch 的顺序并解释为何会损失具体处理。
            std::cout << "exception: " << e.what() << '\n';
        }
    }
    return 0;
}
