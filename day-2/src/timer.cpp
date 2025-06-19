#include "timer.hpp"
#include <chrono>
#include <iostream>
#include <thread>

Timer::Timer() {
  _start = std::chrono::system_clock::now();
}

Timer::~Timer() {
  auto now = std::chrono::system_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(now - _start);
  std::cout << "Timer ran for " << elapsed.count() << " microseconds.\n";
}

void run_timer_example() {
  auto timer = new Timer();
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  delete timer;
}
