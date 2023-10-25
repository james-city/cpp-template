class A {
public:
  template <typename T>
  T nothing() {}
};

int main() {
  A a;
  a.nothing<void>();
}
