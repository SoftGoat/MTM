cmake_minimum_required(VERSION 3.26)
project(MTM)

set(CMAKE_CXX_STANDARD 14)

include_directories(EX3MTM/EX3)


add_executable(EX3
        HealthPoints.cpp
        HealthPoints.h
        HealthPointsExampleTest.cpp
        Queue.h
        QueueExampleTest.cpp
        TestMain.cpp
        TestUtils.cpp
        TestUtils.h)
