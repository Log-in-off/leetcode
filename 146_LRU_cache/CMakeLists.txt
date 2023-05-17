cmake_minimum_required(VERSION 3.10)
project(146_)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-omit-frame-pointer -fsanitize=address")
set (CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -fno-omit-frame-pointer -fsanitize=address")

add_executable(146.out main.cpp)
target_compile_features(146.out PRIVATE cxx_std_17)