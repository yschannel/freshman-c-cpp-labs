#include <iostream>
using std::cout;
using std::endl;

class Circle {
public:
  double radius;
  Circle() { radius = 1; }
  Circle(double newRadius) { radius = newRadius; }
  double getArea() {
    return radius * radius * 3.14159;
  }
};

int main() {
  Circle circle1;
  Circle *pCircle = &circle1;

  cout << "The radius is " << (*pCircle).radius << endl;
  cout << "The area is " << (*pCircle).getArea() << endl;

  (*pCircle).radius = 5.5;

  cout << "The radius is " << pCircle->radius << endl;
  cout << "The area is " << pCircle->getArea() << endl;
  
}