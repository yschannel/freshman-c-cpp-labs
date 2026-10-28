cmake_minimum_required(VERSION 3.10)
project(QUIZ04)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(QUIZ04
    main.cpp
    Character.cpp
    Mage.cpp
    Warrior.cpp
    GameLobby.cpp
)

target_include_directories(QUIZ04 PRIVATE .)