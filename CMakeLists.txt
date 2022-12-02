cmake_minimum_required(VERSION 3.24)
project(AdventOfCode2022)

set(CMAKE_CXX_STANDARD 20)

include_directories(includes)

add_executable(AdventOfCode2022 src/main.cpp src/Day.cpp src/Day1.cpp src/Day2.cpp)

target_link_libraries(AdventOfCode2022 fmt)