#include <iostream>
using namespace std;

int main() {
  char str[5];
  cout << "input 1-line text(e.g. Hello World): ";
  cin.getline(str, 10);
  cout << "read text: " << str << endl;//最后一个存'\0'
  return 0;
}