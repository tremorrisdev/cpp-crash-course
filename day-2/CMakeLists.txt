cmake_minimum_required(VERSION 3.30)
project(day-2)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(day2
  src/main.cpp
  src/timer.cpp
  src/person.cpp
)
