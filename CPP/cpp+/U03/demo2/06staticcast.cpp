#include <iostream>
int main() {
  double pi = 3.14;
  int whole = static_cast<int>(pi);
  std::cout << "double -> int: " << pi << " -> " << whole << "\n";

  int code = 65;
  char letter = static_cast<char>(code);
  std::cout << "int -> char: " << code << " -> '" << letter << "' \n";

  std::cout << static_cast<double>(1 / 2);
  std::cout << 1 / 2;
  

  return 0;
}