#include <iostream>
#include <vector>

template<typename T>
requires requires(T x) { x < x;}
decltype(auto) min(std::vector<T> vec) {
  T *min = &vec[0];
  for (auto i = 0; i < vec.size(); i += 1) {
    T val = vec[i];
    if (!min || val < *min) *min = val;
  }

  return *min;
}

void run_min_example() {
  std::vector<int> vec { 5, 3, 2, 9, 88, 2, 1, 15, 11};
  std::cout << "min is: " << min(vec) << std::endl;
}
