cmake_minimum_required(VERSION 3.23)
project(spell_swap_3_4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(spell_swap_3_4
        check.cpp
        g1.cpp
        naive.cpp
        s.cpp
        tester_gen.cpp
        testlib.h
        v.cpp)
