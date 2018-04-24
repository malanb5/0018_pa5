cmake_minimum_required(VERSION 3.10)
project(pa5a)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES concord.cpp listFuncs.cpp Table.cpp)

add_executable(concord ${SOURCE_FILES})