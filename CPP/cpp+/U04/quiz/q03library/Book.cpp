#include "Book.h"
#include <iostream>


void Book::printInfo() {
  std::cout << "Title: " << title << "\n";
  std::cout << "Author: " << author << "\n";
  std::cout << "Price: " << price << "\n";
  std::cout << "Stock: " << stock << "\n";
}

void Book::setPrice(double p) {
  if (p < 0) {
    std::cout << "Invalid input! Set to 0.0.\n";
    this->price = 0.0;
  } else {
    this->price = p;
  }
}

void Book::setStock(int s) {
  if (s < 0) {
    std::cout << "Invalide input! Set to 0.\n";
    this->stock = 0;
  } else {
    this->stock = s;
  }
}
