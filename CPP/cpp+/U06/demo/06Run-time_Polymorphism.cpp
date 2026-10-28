#include <iostream>
#include <vector>
#include <memory>

class Shape
{
public:
    virtual double calculateArea() const = 0; // 纯虚函数，使 Shape 成为抽象类
    virtual ~Shape() = default;
};

class Circle : public Shape
{
    double radius;

public:
    Circle(double r) : radius(r) {}

    double calculateArea() const override
    {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape
{
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double calculateArea() const override
    {
        return width * height;
    }
};

void printArea(const Shape *shape)
{
    std::cout << "Area: " << shape->calculateArea() << std::endl;
}

int main()
{
    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);

    printArea(&circle);
    printArea(&rectangle);

    std::vector<std::unique_ptr<Shape>> shapes;              // 使用智能指针管理 Shape 对象
    shapes.push_back(std::make_unique<Circle>(3.0));         // 添加一个 Circle 对象
    shapes.push_back(std::make_unique<Rectangle>(2.0, 5.0)); // 堆区创建，打包到容器

    for (const auto &shape : shapes) // 引用&避免智能指针被拷贝，浪费性能
    {
        printArea(shape.get());
    }

    return 0;
}