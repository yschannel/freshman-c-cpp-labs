#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
  int n;
  cout << "Please input an number:";
  if (cin >> n) {
    if (n < 0) {
      cout << "number must be non-negative!" << endl;
      return 1;
    }

    const int line_length = 6;
    std::string star_line(line_length, '*');
    for (int i = 0; i < n; i++) {
      cout << star_line << endl;
    }
  } else {
    cout << "invalid input!please input an integer." << endl;
    return 1;
  }

  return 0;
}