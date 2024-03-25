cmake_minimum_required(VERSION 3.26)
project(ex4)

set(CMAKE_CXX_STANDARD 14)

include_directories(ex4)
include_directories(ex4/Cards)
include_directories(ex4/Players)

add_executable(ex4
        ex4/main.cpp
        ex4/utilities.cpp
        ex4/utilities.h
        ex4/Mtmchkin.h
        ex4/Mtmchkin.cpp
        ex4/Players/Player.cpp
        ex4/Players/Player.h
        ex4/Players/Behavior.h
        ex4/Players/Job.h
        ex4/Players/Responsible.cpp
        ex4/Players/Responsible.h
        ex4/Players/RiskTaking.cpp
        ex4/Players/Sorcerer.cpp
        ex4/Players/Warrior.cpp
        ex4/Cards/CardFactory.cpp
        ex4/Cards/Monster.cpp
        ex4/Cards/PotionsMerchant.cpp
        ex4/Cards/SolarEclipse.cpp
        ex4/Cards/Gang.cpp
        ex4/Cards/Gang.h
        ex4/Cards/EncounterCard.h

)