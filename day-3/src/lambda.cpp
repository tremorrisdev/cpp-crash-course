#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

void run_lambda_example() {
  std::vector<int> numbers { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  std::vector<int> odds;
  std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(odds), [](auto i) {
    return i % 2 != 0;               
  });

  std::for_each(odds.begin(), odds.end(), [odds](auto i){
    if(i != odds[0]) std::cout << ", ";
    std::cout << i;
  });

  std::cout << std::endl;
}
