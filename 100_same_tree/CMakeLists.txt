cmake_minimum_required(VERSION 3.10)
project(100_)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-omit-frame-pointer -fsanitize=address")
set (CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -fno-omit-frame-pointer -fsanitize=address")

add_executable(100.out main.cpp)
target_compile_features(100.out PRIVATE cxx_std_17)