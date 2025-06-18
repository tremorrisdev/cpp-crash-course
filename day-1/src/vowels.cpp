#include <iostream>
#include <regex>
#include <string>

int count_vowels(std::string &str) {
  int count = 0;
  std::regex vowels("a|e|i|o|u", std::regex_constants::icase);
  for (int i = 0; i < str.size(); i += 1) {
    if(std::regex_search(str.substr(i, 1), vowels))
      count += 1;
  }

  return count;
}

void run_vowels_example() {
  std::string foo("\"bread water makes me sleepy\"");
  std::cout << foo << " has " << count_vowels(foo) << " vowels." << "\n";
}
