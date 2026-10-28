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
  Circle circle2(5.0);

  cout << "The area of the circle of radius " << circle1.radius << " is "
       << circle1.getArea() << endl;
  cout << "The area of the circle of radius " <<
      circle2.radius << " is " << circle2.getArea() << endl;

  // modify circle radius
  circle2.radius = 100.0;
  cout << "The area of the circle of radius " <<
      circle2.radius << " is " << circle2.getArea() << endl;

  return 0;
  }

