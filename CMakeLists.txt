cmake_minimum_required(VERSION 3.9)
project(hello_mnist)

set(CMAKE_CXX_STANDARD 17)

add_executable(hello_mnist src/hellonet.cpp src/main.cpp)