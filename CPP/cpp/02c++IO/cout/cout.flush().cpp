#include <iostream>
#include <thread> //延迟函数
using namespace std;

int main() {
  for (char c : "Hello") {
    cout.put(c);
    cout.flush();//立即输出缓冲，避免因其导致的的延迟
    this_thread::sleep_for(chrono::seconds(1));
  }
  return 0;
}