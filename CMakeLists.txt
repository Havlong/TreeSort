cmake_minimum_required(VERSION 3.15)
project(TreeSort)

set(CMAKE_CXX_STANDARD 14)

add_executable(TreeSort main.cpp measurement.cpp measurement.h TreeSorter.h MergeSorter.h QuickSorter.h)