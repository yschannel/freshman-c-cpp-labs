#include "Book.h"
#include <iostream>
#include<string>
int main() {
  Book book1;
  Book book2("C++ Primer", "Lippman", 89.5, 10);

  book2.printInfo();
  book2.setPrice(-10.0);
  book2.setStock(20);

  book1.printInfo();
  book2.printInfo();

  return 0;
}