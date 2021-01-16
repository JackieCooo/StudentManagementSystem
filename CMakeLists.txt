cmake_minimum_required(VERSION 3.17)
project(StudentManagementSystem)

set(CMAKE_CXX_STANDARD 14)

add_executable(StudentManagementSystem main.cpp StudentManager.h StudentManager.cpp Student.h Student.cpp GlobalPath.h Score.h Score.cpp)