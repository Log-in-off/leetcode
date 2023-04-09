cmake_minimum_required(VERSION 3.10)
project(1857_)

set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")

add_executable(1857.out main.cpp)
target_compile_features(1857.out PRIVATE cxx_std_17)