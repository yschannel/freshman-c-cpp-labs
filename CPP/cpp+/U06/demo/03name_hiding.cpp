class P {
public:
  void f() {}
};


class C :public P {
public:
  using P::f; //类似达成重载，而不是被隐藏
  void f(int x) {}
};
int main() {
  C c;
  c.f();
}