#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <unordered_map>

std::unordered_map<int, std::string> example { {1, "foo" }, {2, "bar"}, {3, "foobar"}, {4, "fizzbuzz" }};

void run_frequency_example() {
  std::unordered_map<int, std::string> filtered;
  std::copy_if(example.begin(), example.end(), std::inserter(filtered, filtered.end()), [](auto &pair) {
    std::string &value = pair.second;
    return value.contains("foo");
  });

  std::cout << "Map has \"foo\"... " << filtered.size() << " times." << std::endl;
}
