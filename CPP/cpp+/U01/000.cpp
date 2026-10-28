#include <iostream>
using std::cout;

int main() {
  std::cout << "Hello,World!" << std::endl;//立即输出
  cout << "Hello,World\n";//大量数据性能好
  int x;
  std::cin >> x;
  return 0;
}