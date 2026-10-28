#include <iostream>
int v1 = 10;
int main() {
int v1 = 5;
std::cout << "local variable v1 is " << v1 << std::endl;
std::cout << "global variable v1 is " << ::v1 << std::endl;
return 0;
}
