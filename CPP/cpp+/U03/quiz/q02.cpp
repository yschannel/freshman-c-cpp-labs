#include <iostream>

double add(double op1, double op2) { return op1 + op2; }
double add(double op1) { return op1 += 0.5; }

int main() {
  auto year{0.0};
  year = add(year, 5);
  year = add(year, 4);
  year = add(year, 1);
  year = add(year);
  year = add(year, 2);
  year = add(year, 3);
  std::cout << "Result:" << year << "\n";
  return 0;
}