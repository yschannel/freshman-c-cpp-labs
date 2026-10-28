#include<iostream>
class Data{
private:
  int year{2019} , month{1};
  int day{1};
public:
    friend class Kid;
    friend void print(const Data &d);
};

void print(const Data& d){
    std::cout << d.year << "/" << d.month << "/" << d.day << std::endl;
}

class Kid {
private:
    Data birthday;
public:
  Kid(){
      std::cout << "I was born in " << birthday.year << std::endl;
  }
};

int main(){
    print(Data());
    Kid k;
    std::cin.get();

    return 0;
}