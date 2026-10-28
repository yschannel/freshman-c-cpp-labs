/*Write a program. Ask the user to input a number and save the number
in variable n. Print n  lines  of star  "*".
You  decide  the  length  of the  line.
You  must  use  C++ programming style.*/
#include <iostream>
int main() {
  int n;
  std::cout << "please input a number: " << std::endl;
  std::cin >> n;
  for (int i = 0; i < 10; i++) {
    std::cout << "****" << std::endl;
  }
  return 0;
}