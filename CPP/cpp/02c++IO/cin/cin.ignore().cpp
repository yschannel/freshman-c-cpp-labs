#include <iostream>
using namespace std;

int main() {
  int num;
  char str[100];
  cout << "input a number:";
  cin >> num;//读取后换行符会留在留在流中
  cin.ignore(); // 默认跳过一个换行符
  cout << "input 1-line text: ";
  cin.getline(str, 100);
  cout << "num: " << num << endl;
  cout << "text: " << str << endl;
  return 0;
}