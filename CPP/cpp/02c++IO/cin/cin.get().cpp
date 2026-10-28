#include <iostream>
using namespace std;

int main() {
  char c1, c2;
  cout << "please input 2 characters(e.g. ab): ";
  c1 = cin.get();
  c2 = cin.get();
  cout << "read character1: " << c1 << endl;
  cout << "read character2: " << c2 << endl;
  return 0;
}