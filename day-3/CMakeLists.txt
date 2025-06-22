cmake_minimum_required(VERSION 3.30)
project(day-3)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(day3
  src/main.cpp
  src/frequency.cpp
  src/dedupe.cpp
  src/lambda.cpp
)
