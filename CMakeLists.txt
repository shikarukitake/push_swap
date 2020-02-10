cmake_minimum_required(VERSION 3.13)
project(cmake_testall)

set(CMAKE_CXX_STANDARD 11)

add_executable(cmake_testall checker.c)

add_executable(main main.c)