cmake_minimum_required(VERSION 2.6)
project (reddit)
set(EXECUTABLE_OUTPUT_PATH ${dir} ../)
set(CXX_CMAKE_FLAGS "-std=c++14")
add_executable(json json.cpp main.cpp)
