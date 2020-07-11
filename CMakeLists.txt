cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(leetcode)
set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_executable(1-Two-Sum leetcode/1-Two-Sum.cpp)
