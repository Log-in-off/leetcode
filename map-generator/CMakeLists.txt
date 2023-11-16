cmake_minimum_required(VERSION 3.10)

project (map_generator)

add_executable(generator src/main.cpp src/map_generator.cpp src/svg.cpp src/test_svg.cpp)
target_compile_features(generator PRIVATE cxx_std_17)