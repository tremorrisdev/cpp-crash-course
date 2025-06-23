cmake_minimum_required(VERSION 3.30)
project(day-4)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(day4
  src/main.cpp
  src/min.cpp
  src/maybe.cpp
  src/setting.cpp
)
