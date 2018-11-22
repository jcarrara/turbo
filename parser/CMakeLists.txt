cmake_minimum_required(VERSION 3.12)
project(parser)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES HTMLPage.h HTMLPage.cpp main.cpp)

add_executable(parser main.cpp HTMLPage.cpp)