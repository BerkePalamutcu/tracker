cmake_minimum_required(VERSION 3.24)
project(trackr)

set(CMAKE_CXX_STANDARD 23)

add_executable(trackr main.cpp src/repository/repository.h)
