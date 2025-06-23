#include "stack.hpp"
#include <iostream>

void run_min_example();
void run_maybe_example();
void run_setting_example();

int main() {
  run_min_example();
  run_maybe_example();
  run_setting_example();

  Stack<int> stack;
  stack.push(1);
  stack.push(4);
  stack.push(19);

  auto peekd = stack.peek();
  if (peekd.has_value()) std::cout << "peek revealed " << peekd.value() << std::endl;

  auto removed = stack.pop();
  if (removed.has_value()) std::cout << "pop returned " << removed.value() << std::endl;
}
