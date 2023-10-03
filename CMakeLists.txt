cmake_minimum_required(VERSION 3.22)
project(PageRank2)

set(CMAKE_CXX_STANDARD 14)

add_executable(PageRank2 test_main.cpp AdjacencyList.cpp AdjacencyList.h)
