#include <iostream>

int main() {
  const int n = 5;

  int *p = new int[n];

  for (int i = 0; i < n; ++i) {
    p[i] = (i + 1) * 10;
  }
  std::cout << "content of array: ";
  for (int i = 0; i < n; ++i) {
    std::cout << p[i] << (i + 1 == n ? '\n' : ' ');
  }

  delete[] p;
  p = nullptr;

  return 0;
}