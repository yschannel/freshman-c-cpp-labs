#include <iostream>
#include <string>

int main() {
  std::string s1 = "Hello";
  std::string s2 = "World";

  std::cout << s1 << std::endl;

  //int count = 3;
  //std::cout << s1 + count << std::endl;

  int arr[] = {1, 2, 3};
  for (const int &i : arr) {         //遍历数组才用
    std::cout << s1 + " " + s2 + std::to_string(i) << std::endl;
  }
  return 0;
}