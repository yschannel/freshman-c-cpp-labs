#ifndef MOVE_H
#define MOVE_H

#include <iostream>

class MathVector {
private:
  int *data;
  int size;

public:
  MathVector(int size);
  ~MathVector();
  MathVector(const MathVector &other);
  MathVector &operator=(const MathVector &other); // 必须用&

  MathVector(MathVector &&other) noexcept;
  MathVector &operator=(MathVector &&other) noexcept;
  void print_info() const;

  int getElement(int idx) const;
  void print();

  void transform(int (*func)(int)); //传入函数指针
};


#endif