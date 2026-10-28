#include <iostream>

using std::cout;
using std::endl;

void swap(int &x, int &y) {
  int t;
  t=x; x=y; y=t;
}

int main() {
  auto a{5}, b{10};
  cout << "Before: a=" << a << " b=" << b << endl;
  swap(a, b);
  cout << "After: a=" << a << " b=" << b << endl;
  return 0;
}