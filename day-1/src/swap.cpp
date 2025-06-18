#include <iostream>

void swap(int &a, int &b) {
  int tmp = b;
  b = a;
  a = tmp;
}

void run_swap_example() {
  int a = 42;
  int b = 77;
  swap(a, b);

  std::cout << a << ", " << b << "\n";
}
