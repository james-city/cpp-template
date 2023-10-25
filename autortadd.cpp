// matrix add that allows selection of return type and supports automatic
// inference in the case of matching input types.
#include <iostream>
#include <type_traits>
#include <vector>

template<typename RT, typename T, typename U>
RT matadd(T m1, U m2) {
  RT sum;
  // Copy sum from the right source so the types match up.
  if constexpr(std::is_same_v<RT, T>) {
    sum = m1;
  } else if constexpr(std::is_same_v<RT, U>) {
    sum = m2;
  }

  const auto cols = m1.size();
  const auto rows = m1[0].size();

  for (int i = 0; i < cols; ++i) {
    for (int j = 0; j < rows; ++j) {
      if constexpr(std::is_same_v<RT, T>) {
        sum[i][j] += m2[i][j];
      } else if constexpr(std::is_same_v<RT, U>) {
        sum[i][j] += m1[i][j];
      }
    }
  }
  return sum;
}

template <typename T>
T matadd(T m1, T m2) {
  return matadd<T>(m1, m2);
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
    matadd<std::vector<std::vector<int>>>(
      std::vector<std::vector<int>>({{1, 2}, {3, 4}}),
      std::array<std::array<int, 2>, 2>({
        std::array<int, 2>({1, 2}),
        std::array<int, 2>({3, 4})
      })
    )
  );

  print(
    matadd<std::array<std::array<int, 2>, 2>>(
      std::vector<std::vector<int>>({{1, 2}, {3, 4}}),
      std::array<std::array<int, 2>, 2>({
        std::array<int, 2>({1, 2}),
        std::array<int, 2>({3, 4})
      })
    )
  );

  print(
    matadd<std::vector<std::vector<int>>>(
      std::array<std::array<int, 2>, 2>({
        std::array<int, 2>({1, 2}),
        std::array<int, 2>({3, 4})
      }),
      std::vector<std::vector<int>>({{1, 2}, {3, 4}})
    )
  );

  print(
    matadd<std::array<std::array<int, 2>, 2>>(
      std::array<std::array<int, 2>, 2>({
        std::array<int, 2>({1, 2}),
        std::array<int, 2>({3, 4})
      }),
      std::vector<std::vector<int>>({{1, 2}, {3, 4}})
    )
  );

  print(
    matadd(
      std::vector<std::vector<int>>({{1, 2}, {3, 4}}),
      std::vector<std::vector<int>>({{1, 2}, {3, 4}})
    )
  );
}

