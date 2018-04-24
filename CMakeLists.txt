cmake_minimum_required(VERSION 3.10)
project(pa5a)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES grades.cpp listFuncs.cpp Table.cpp)

add_executable(grades ${SOURCE_FILES})