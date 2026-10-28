#include <iostream>

int main() {
  bool passed = true;
  bool online = false;

  std::cout << "Default input: passed=" << passed << ", online=" << online
            << "\n";

  std::cout << std::boolalpha;
  std::cout << "boolalpha output: passed=" << passed << ", online=" << online
            << "\n";

  std::cout << std::noboolalpha;
  std::cout << "Restore default: passed=" << passed << ", online=" << online
            << "\n";

  return 0;
}