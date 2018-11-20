cmake_minimum_required(VERSION 3.10)
project(suanfa)

set(CMAKE_CXX_STANDARD 11)

add_executable(suanfa
        main.cpp
        Header/BinarySearch.h
        BinarySearch.cpp
        Header/Comparable.h
        Comparable.cpp
        Header/BaseSort.h BaseSort.cpp SelectSort.cpp Header/SelectSort.h InsertionSort.cpp Header/InsertionSort.h ShellSort.cpp Header/ShellSort.h MergeSort.cpp Header/MergeSort.h QuickSort.cpp Header/QuickSort.h Header/HeapSort.h HeapSort.cpp)
