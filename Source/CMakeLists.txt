cmake_minimum_required(VERSION 2.6)
project(Economy)


set(CMAKE_CXX_FLAGS "-g -Wall -Wextra -pedantic")

add_subdirectory(Participants)
add_subdirectory(World)
add_executable(main main.cpp)