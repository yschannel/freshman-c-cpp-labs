#include <iostream>
#include <string>
#include <vector>

// Stack<T> 是类模板。T 表示元素类型；Stack<int>、Stack<double>
// 和 Stack<string> 是不同的具体实例类型。
template <typename T>
class Stack {
public:
    void push(const T& value);
    const T& top() const;
    std::size_t size() const;
    bool empty() const;

private:
    std::vector<T> data_;
};

// 类模板成员函数在类外实现时，需要重复模板前缀，
// 再用 Stack<T>:: 指明这个成员属于哪个类模板。
template <typename T>
void Stack<T>::push(const T& value) {
    data_.push_back(value);
}

template <typename T>
const T& Stack<T>::top() const {
    return data_.back();
}

template <typename T>
std::size_t Stack<T>::size() const {
    return data_.size();
}

template <typename T>
bool Stack<T>::empty() const {
    return data_.empty();
}

int main() {
    Stack<int> scores;
    scores.push(86);
    scores.push(92);

    Stack<double> ratios;
    ratios.push(0.25);
    ratios.push(0.5);

    Stack<std::string> names;
    names.push("Ada");
    names.push("Bjarne");

    std::cout << "Stack<int>    top=" << scores.top()
              << ", size=" << scores.size() << '\n';
    std::cout << "Stack<double> top=" << ratios.top()
              << ", size=" << ratios.size() << '\n';
    std::cout << "Stack<string> top=" << names.top()
              << ", size=" << names.size() << '\n';

    return 0;
}
