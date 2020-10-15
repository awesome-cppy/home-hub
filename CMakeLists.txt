cmake_minimum_required(VERSION 3.16)

# Project name
project(home-hub VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(PROJECT_BINARY_DIR "build")

add_executable(home-hub src/main.cpp)
