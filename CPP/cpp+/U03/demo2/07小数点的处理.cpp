#include <iostream>
#include <iomanip>

using std::cout;

int main() {
  double pi = 3.141592653589793;
  double val = 10.0;

  cout << "default output: " << pi << "\n";

  cout << std::fixed;
  cout << std::setprecision(2);

  cout << "keep two decimal places: " << pi << "\n";
  cout << "integer is also affected: " << val << "\n";

  cout << std::setprecision(5);
  cout << "keep five decimal places: " << pi << "\n";

  cout << std::defaultfloat;
  cout << "restore defaults: " << pi << "\n";

  return 0;
  
}