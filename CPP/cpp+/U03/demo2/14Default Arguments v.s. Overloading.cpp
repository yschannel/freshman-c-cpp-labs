#include<iostream>
int add (int x, int y=1000) {
  return x + y;
}
int add (int x) {
  return x + 100;
}
int main() {
  add(1); //How to solve this?
  std::cin.get();
  return 0;
}