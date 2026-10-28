#include<iostream>
#include<string>

class Shape{
public:
    std::string toString() { return "Shape\n"; }
};

class Circle: public Shape{
public:
    std::string toString(){
        return "Circle\n";
    }
    void g() { std::cout << toString(); }
};

int main(){
    Circle circle;
    std::cout << circle.toString();
    std::cout << circle.Shape::toString();
    return 0;
}