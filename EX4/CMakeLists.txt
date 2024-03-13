cmake_minimum_required(VERSION 3.26)
project(ex4)

set(CMAKE_CXX_STANDARD 14)

include_directories(ex4_supplied1)
include_directories(ex4_supplied1/Cards)
include_directories(ex4_supplied1/Players)

add_executable(ex4
        ex4_supplied1/Cards/Card.h
        ex4_supplied1/Players/Player.h
        ex4_supplied1/main.cpp
        ex4_supplied1/Mtmchkin.cpp
        ex4_supplied1/Mtmchkin.h
        ex4_supplied1/utilities.cpp
        ex4_supplied1/utilities.h
        ex4_supplied1/Players/Player.cpp
        ex4_supplied1/Cards/Card.cpp
        ex4_supplied1/Players/Behavior.cpp
        ex4_supplied1/Players/Behavior.h
        ex4_supplied1/Players/Job.cpp
        ex4_supplied1/Players/Job.h)
