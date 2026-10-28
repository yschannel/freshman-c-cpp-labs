#include <iostream>
using namespace std;

class Counter
{
    int val;

public:
    Counter(int v = 0) : val(v) {}
    Counter &operator++()
    { // 前置
        ++val;
        cout << "Prefix: " << val << " ";
        return *this;
    }
    Counter operator++(int)
    { // 后置
        Counter old = *this;
        ++(*this); // 复用前置
        cout << "Postfix(temp): " << old.val << " ";
        return old;
    }
    int get() const { return val; }
};

int main()
{
    Counter c(5);
    cout << (c++).get() << endl;
    cout << (++c).get() << endl;
    return 0;
}