cmake_minimum_required(VERSION 3.7)
project(NewMap)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp MAPA.hpp String.hpp)
add_executable(NewMap ${SOURCE_FILES})