cmake_minimum_required (VERSION 3.5)

project(lab4)

add_executable(oop_exercise_04
  main.cpp
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g3")

set_target_properties(oop_exercise_04 PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)