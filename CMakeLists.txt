cmake_minimum_required(VERSION 3.10)

project(ProdimTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_executable(ProdimTest src/main.cpp src/LeastSquares.cpp)

file(COPY ${CMAKE_SOURCE_DIR}/points.txt DESTINATION ${CMAKE_BINARY_DIR})