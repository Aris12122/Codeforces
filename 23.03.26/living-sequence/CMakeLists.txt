cmake_minimum_required(VERSION 3.23)
project(living_sequence)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(living_sequence
        check.cpp
        g1.cpp
        naive.cpp
        s.cpp
        tester_gen.cpp
        testlib.h
        v.cpp)
