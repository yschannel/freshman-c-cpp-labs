#include <ctime>
#include <iostream>
#include <random>
#include <array>
int main() {
  auto min = 1, max = 100;
  static std::default_random_engine e(time(0));
  static std::uniform_int_distribution<unsigned> u(min, max);
  std::array<int,10> arr;
  for (int i = 0; i < 10 ; i++){
    arr[i] = u(e);
  }
  for (int i = 0; i < 10; i++) {
    std::cout << arr[i] << "\n";
  }
  return 0;
}