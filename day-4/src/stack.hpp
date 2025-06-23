#pragma once

#include <optional>
#include <vector>

template<typename T>
class Stack {
  private:
    std::vector<T> items;

  public:
    void push(T value);
    std::optional<T> pop();
    std::optional<T> peek();
};

template<typename T>
void Stack<T>::push(T value) {
  items.push_back(value);
}

template<typename T>
std::optional<T> Stack<T>::pop() {
  auto val = peek();
  if(val.has_value()) items.pop_back();
  return val;
}

template<typename T>
std::optional<T> Stack<T>::peek() {
  if(items.size() == 0) return std::nullopt;
  return items.back();
}
