#include "deepcopy.h"
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
  
  delete[] data;

  size = other.size;
  data = new int[size];
  for (int i = 0; i < size; i++) {
    data[i] = other.data[i];
  }

  // 先分配新内存再赋值删除（更高级）
  // int* new_data = new int[other.size];
  // for(itn i = 0; i < other.size; ++i) new_data[i] = other.data[i];
  // delete[] data;
  // data = new_data;
  // size = other.size;
  return *this;
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
  MathVector v2 = v1;
  v1.transform(square);
  v1.print();
  v2.print();

  return 0;
}