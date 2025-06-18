#include <climits>
#include <iostream>

void run_swap_example();
void run_factorial_example(); 
void run_vowels_example();

int main() {
  run_swap_example();
  run_factorial_example();
  run_vowels_example();

  std::cout << "Input a temperature in Celcius\n>? ";
  int degrees;
  std::cin >> degrees;
  while (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
    std::cout << "\n>? ";
    std::cin >> degrees;
  }

  float fahrenheit = degrees * 9.0f / 5.0f + 32;
  std::cout << fahrenheit << "F\n";
}
