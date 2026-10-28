#ifndef DEEPCOPY_H
#define DEEPCOPY_H

#include <iostream>

class MathVector {
private:
  int *data;
  int size;

public:
  MathVector(int size);
  ~MathVector();
  MathVector(const MathVector &other);
  MathVector& operator=(const MathVector& other); //必须用&

  int getElement(int idx) const;
  void print();

  void transform(int (*func)(int)); //传入函数指针
};


#endif