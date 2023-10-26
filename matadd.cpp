#include <iostream>
#include <vector>

template<typename T>
T matadd(const T& m1, const T& m2) {
  const auto cols = m1.size();
  const auto rows = m1[0].size();

  T sum = m1;
  for (int i = 0; i < cols; ++i) {
    for (int j = 0; j < rows; ++j) {
      sum[i][j] += m2[i][j];
    }
  }
  return sum;
}

template<typename T>
void print(const T& mat) {
  const auto cols = mat.size();
  const auto rows = mat[0].size();

  for (int i = 0; i < cols; ++i) {
    for (int j = 0; j < rows; ++j) {
      std::cout << mat[i][j] << ' ';
    }
    std::cout << '\n';
  }
}

int main() {
  print(
    matadd(
      std::vector<std::vector<int>>({{1, 2}, {3, 4}}),
      std::vector<std::vector<int>>({{1, 2}, {3, 4}})
    )
  );

  print(
    matadd(
      std::array<std::array<int, 2>, 2>({
        std::array<int, 2>({1, 2}), 
        std::array<int, 2>({3, 4})
      }),
      std::array<std::array<int, 2>, 2>({
        std::array<int, 2>({1, 2}),
        std::array<int, 2>({3, 4})
      })
    )
  );
}
