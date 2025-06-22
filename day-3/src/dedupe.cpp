#include <iostream>
#include <set>
#include <vector>

void run_dedupe_example() {
  std::vector<int> numbers {1, 1, 1, 2, 3, 3};
  std::set<int> deduped;
  for (auto i = 0; i < numbers.size(); i += 1)
    deduped.insert(numbers[i]);

  std::set<int>::iterator iter;
  for (iter = deduped.begin(); iter != deduped.end(); iter++) {
    if (iter != deduped.begin()) std::cout << ", ";
    std::cout << *iter;
  }

  std::cout << std::endl;
}
