#include "move.h"
#include <iostream>
#include <new>

MathVector::MathVector(int size) : size(size) {
  this->data = new int[size]();
  for (int i = 0; i < size; i++) {
    std::cout << "Element" << i + 1 << ": ";
    std::cin >> this->data[i];
  }
}

MathVector::~MathVector() { delete[] this->data; }

MathVector::MathVector(const MathVector &other) {
  this->size = other.size;
  this->data = new int[this->size];
  for (int i = 0; i < this->size; i++) {
    this->data[i] = other.data[i];
  }
}

MathVector& MathVector::operator=(const MathVector &other) {
  if (this == &other) {
    return *this;
  }

  int* new_data = new int[other.size];
  for(int i = 0; i < other.size; ++i) new_data[i] = other.data[i];
  delete[] data;
  data = new_data;
  size = other.size;
  return *this;
}

MathVector::MathVector(MathVector &&other) noexcept: size(other.size), data(other.data) {
  other.data = nullptr;
  other.size = 0;
  std::cout << "used move ctor" << std::endl;
}

MathVector &MathVector::operator=(MathVector &&other) noexcept{
  if (this == &other) {
    return *this;
  }

  delete[] data;
  data = other.data;
  size = other.size;

  other.data = nullptr;
  other.size = 0;
  std::cout << "used move assignment operator." << std::endl;
}

void MathVector::print_info() const {
   std::cout << "Vector size: " << size << ", data address: " << data << std::endl;
}

int MathVector::getElement(int idx) const {
  if (idx < 0 || idx >= size) {
    std::cout << "invalid input, return default val (0)\n";
    return 0;
  }

  return data[idx];
}

void MathVector::print() {
  std::cout << "content: ";
  for (int i = 0; i < size; i++) {
    std::cout << data[i] << " ";
  }
  std::cout << "\n";
}

void MathVector::transform(int (*func)(int)) {
  for (int i = 0; i < size; i++) {
    data[i] = func(data[i]);
  }
}

int square(int x) { return x * x; }

int main() {
  MathVector v1(3);
  v1.print_info();
  std::cout << "\n";
  MathVector v2(std::move(v1));
  v2.print_info();

  std::cout << "\n";
  MathVector v3(2);
  v3.print_info();
  std::cout << "\n";
  v3 = std::move(v2);
  v3.print_info();
  
  return 0;
}