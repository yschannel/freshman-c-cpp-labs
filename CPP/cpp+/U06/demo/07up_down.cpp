// 上转换隐式转换
Shape *s = nullptr;
Circle *c = new Circle(2);
s = c;

// 下转换显示转换
Shape *s = new Circle(1);
Circle *c = nullptr;
c = dynamic_cast<Circle *>(s); // 必须用dynamic_cast