#include <iostream>

template <typename T, typename U>
auto sup(T t, U u) {
  return u > t ? u : t;
}

int main() {
  std::cout << sup(2, 3) << '\n';
  std::cout << sup(2.0, 3) << '\n';
  std::cout << sup(2, 3.0) << '\n';
  std::cout << sup(2.0, 3.0) << '\n';
}
