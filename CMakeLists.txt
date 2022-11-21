cmake_minimum_required(VERSION 3.23)
project(PJ1)

set(CMAKE_CXX_STANDARD 14)

add_executable(PJ1 main.cpp priorityList.h priorityList.cpp Matrix.cpp Matrix.h Operation.cpp Operation.h)
