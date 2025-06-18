cmake_minimum_required(VERSION 3.30)
project(day-1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(day1
  src/main.cpp
  src/swap.cpp
  src/factorial.cpp
  src/vowels.cpp
)
