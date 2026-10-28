#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

// D6 课后任务载体。ArrayView<T> 只观察外部数组；
// 它不拥有这段内存，因此不能 delete data_。
template <typename T>
class ArrayView
{
public:
    ArrayView(T *data, std::size_t length) : data_(data), length_(length) {}

    std::size_t size() const
    {
        return length_;
    };
    void print() const
    {
        for (std::size_t i = 0; i < length_; i++)
        {
            std::cout << data_[i] << ' ';
        }
        std::cout << '\n';
    }
    int seek(const T &target) const
    {
        int pos = 0;
        for (size_t i = 0; i < length_; i++, pos++)
        {
            if (data_[i] == target)
            {
                return pos;
            }
        }
        return -1;
    }

    // 实现前先说明 T 必须支持哪些操作。
    // A:拷贝构造，+=符合运算符，==比较运算符
    T sum() const
    {
        if (length_ > 0)
        {
            T result = data_[0];
            for (size_t i = 1; i < length_; i++)
            {
                result += data_[i];
            }
            return result;
        }
    }

    // 可选扩展。本练习不要使用 std::reverse。
    void reverseInPlace()
    {
        std::size_t left = 0;
        std::size_t right = length_ - 1;
        while (left < right)
        {
            T temp = data_[left];
            data_[left] = data_[right];
            data_[right] = temp;
            left++;
            right--;
        }
    };

private:
    T *data_;
    std::size_t length_;
};

// TODO：实现上面的成员函数。
// 提交时必须说明：
// 1. T 必须支持哪些操作？加法运算
// 2. ArrayView<T> 是否拥有数组？否，其成员并没有涉及内存分配。
// 3. 为什么 length_ 是数据成员，而不是模板类型参数？length_在runtime才被定义下来，而模板类型参数需要在编译器确定

int main()
{
    int numbers[] = {1, 2, 3, 4};
    double scores[] = {1.5, 2.5, 3.0};
    std::string names[] = {"Ada", "Bjarne", "Grace"};

    /*
    (void)numbers;
    (void)scores;
    (void)names;
*/

    ArrayView<int> numberView(numbers, 4);
    ArrayView<double> scoreView(scores, 3);
    ArrayView<std::string> nameView(names, 3);

    /*
        TODO：用 int 和 double 测试 print、seek 和 sum。
        TODO：用 string 测试 seek 和 print；说明 sum 是否有意义。
        TODO：如果实现了 reverseInPlace，展示反转前后的输出。
        */
    // 测试 int
    std::cout << "=== Int Test ===\n";
    numberView.print();
    std::cout << "pos of 3: " << numberView.seek(3) << "\n";
    std::cout << "sum: " << numberView.sum() << "\n";

    // 测试 double
    std::cout << "\n=== Double Test ===\n";
    scoreView.print();
    std::cout << "pos of 3.0: " << scoreView.seek(3.0) << "\n";
    std::cout << "sum: " << scoreView.sum() << "\n";

    // 测试 string
    std::cout << "\n=== String Test ===\n";
    nameView.print();
    std::cout << "pos of Ada: " << nameView.seek("Ada") << "\n";
    std::cout << "sum: " << nameView.sum() << "\n";

    // 测试反转
    std::cout << "\n=== Reverse Test ===\n";
    std::cout << "Before reverse: ";
    nameView.print();
    nameView.reverseInPlace();
    std::cout << "After reverse:  ";
    nameView.print();

    std::cout << "D6 shell: implement ArrayView<T>, then record evidence.\n";

    return 0;
}
