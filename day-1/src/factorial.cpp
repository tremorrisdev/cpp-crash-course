#include <iostream>

constexpr int factorial(int n) {
  return n < 2 ? 1 : n * factorial(n - 1);
}

void run_factorial_example() {
  std::cout << 3 << "! = " << factorial(3) << "\n"; 
  std::cout << 4 << "! = " << factorial(4) << "\n"; 
  std::cout << 8 << "! = " << factorial(8) << "\n"; 
}
