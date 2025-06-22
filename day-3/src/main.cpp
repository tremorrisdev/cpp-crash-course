#include <iostream>
#include <map>
#include <string>
#include <vector>

void run_frequency_example();
void run_dedupe_example();
void run_lambda_example();

double get_avg(std::map<std::string, std::vector<int>> &map){
  int sum = 0, count = 0;
  std::map<std::string, std::vector<int>>::iterator iter;
  for (iter = map.begin(); iter != map.end(); iter++) {
    auto scores = (*iter).second;
    for (int i = 0; i < scores.size(); i += 1) {
      count += 1;
      sum += scores[i];
    }
  }

  return sum / (double)count;
}

int get_max(std::map<std::string, std::vector<int>> &map){
  int max = 0;
  std::map<std::string, std::vector<int>>::iterator iter;
  for (iter = map.begin(); iter != map.end(); iter++) {
    auto scores = (*iter).second;
    for (int i = 0; i < scores.size(); i += 1) {
      int score = scores[i];
      if (score > max) max = score;
    }
  }

  return max;
}

void print_leaderboard(std::map<std::string, std::vector<int>> &map) {
  // moving on lol
}


int main() {
  run_frequency_example();
  run_dedupe_example();
  run_lambda_example();

  std::map<std::string, std::vector<int>> grades {
    { "foo", {77, 89, 98}},
    { "bar", {88, 22, 99}},
    { "fizz", {81, 99, 99}}
  };

  std::cout << "Average score is " << get_avg(grades) << std::endl;
  std::cout << "Max score is " << get_max(grades) << std::endl;
}
