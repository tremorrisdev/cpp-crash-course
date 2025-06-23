#include <iostream>
#include <optional>
#include <vector>

std::optional<int> find_index(int val, std::vector<int> &vec) {
  for (auto i = 0; i < vec.size(); i += 1) {
    if (vec[i] == val) return i;
  }

  return std::nullopt;
}

void run_maybe_example() {
  std::vector<int> vec = {0, 0, 1, 34, 11, 19, 2, 5};
  auto result = find_index(35, vec);

  if (result.has_value())
    std::cout << "found at index " << result.value() << std::endl;
  else
    std::cout << "not found" << std::endl;
}
