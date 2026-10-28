#include <iostream>
#include <string>

using std::string;

void swap(string *person1, int idx1, string* person2, int idx2) {
  string temp = person1[idx1];
  person1[idx1] = person2[idx2];
  person2[idx2] = temp;
}

int main() {
  string *person1 = new string[5];
  string *person2 = new string[5];

  for (int i = 0; i < 5; i++) {
    person1[i] = "item" + std::to_string(i);
    person2[i] = "item" + std::to_string(i+10);
  }

  for (int i = 0; i < 5; i++) {
    std::cout << person1[i] << "\n";
  }
  for (int i = 0; i < 5; i++) {
    std::cout << person2[i] << "\n";
  }

  swap(person1, 1, person2, 4);

  for (int i = 0; i < 5; i++) {
    std::cout << person1[i] << "\n";
  }
  for (int i = 0; i < 5; i++) {
    std::cout << person2[i] << "\n";
  }

  delete[] person1;
  person1 = nullptr;
  delete[] person2;
  person2 = nullptr;
  return 0;
}