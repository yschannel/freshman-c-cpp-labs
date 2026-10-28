#include<memory>
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;


int main() {
  std::string* person1[]{new std::string[5]};
  auto person2 = new std::string[5];

  for (int i = 0; i < 5; i++) {
    person1[i] = "item" + std::to_string(i);
    person2[i] = "item" + std::to_string(i + 10);
  }

  for (int i = 0; i < 5; i++) {
    cout << person1[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < 5; i++) {
    cout << person2[i] << " ";
  }

  delete[] person1[0];
  person1[0] = nullptr;
  delete[] person2;
  person2 = nullptr;

}