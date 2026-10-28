struct A {
  A(int i) {}
  A(double d, int i){}
};

struct B : A {
  using A::A; //继承基类ctor,除了A(int i)
  int d{0};
  B(int i) : A{i}, d{i} { }
};

int main() {
  B b(1); 
}