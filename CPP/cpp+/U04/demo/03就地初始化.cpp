#include<string>
class S {
  int m = 7;
  // int n(7);  不可用()
  std::string s{'a', 'b', 'c'};
  std::string t{"Constructor run"};
  //int a[] = {1,2,3};
  int b[3] = {1, 2, 3};

public:
  S(){}
};