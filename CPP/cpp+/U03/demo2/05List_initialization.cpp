#include <iostream>
int main() {
  int a = 3.14;
  //int b{3.14};

  int arr[3]{1, 2, 3};

  char s[] = "abc";
  std::cout << "s = \"" << s << "\", sizeof(s)= " << sizeof(s) << "\n";
  return 0;
}