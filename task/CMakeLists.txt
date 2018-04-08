cmake_minimum_required(VERSION 3.10)
project(experimental)

set(CMAKE_CXX_STANDARD 17)

file (GLOB P_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

#target_include_directories(experimental PRIVATE)
add_executable(experimental main.cpp ${P_HEADERS})