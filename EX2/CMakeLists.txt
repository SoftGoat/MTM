cmake_minimum_required(VERSION 3.26)
project(MTM)

set(CMAKE_CXX_STANDARD 14)

include_directories(EX2)

add_executable(MTM
        EX2/Card.cpp
        EX2/Card.h
        EX2/Mtmchkin.cpp
        EX2/Mtmchkin.h
        EX2/Player.cpp
        EX2/Player.h
        EX2/test.cpp
        EX2/utilities.cpp
        EX2/utilities.h)
