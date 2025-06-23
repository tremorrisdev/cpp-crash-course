#include <iostream>
#include <variant>

void run_setting_example() {
  std::variant<int, float> var = 1;
  std::cout << "int value = " << std::get<int>(var) << std::endl;

  var = 42.0f;
  std::cout << "new float value = " << std::get<float>(var) << std::endl;
}
