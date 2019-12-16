cmake_minimum_required(VERSION 3.12)
project(P1)

set(CMAKE_CXX_STANDARD 14)

add_executable(C-Project main.cpp ui.cpp ui.h file_io.cpp file_io.h kb_io.cpp kb_io.h backend.cpp backend.h)