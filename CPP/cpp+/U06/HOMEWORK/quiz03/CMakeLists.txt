cmake_minimum_required(VERSION 3.10)
project(QUIZ03)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(QUIZ03
    main.cpp
    Character.cpp
    Mage.cpp
    Warrior.cpp
)

target_include_directories(QUIZ03 PRIVATE .)