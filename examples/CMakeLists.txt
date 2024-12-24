cmake_minimum_required(VERSION 3.18)

add_executable(example0
    example0.cc
)
target_include_directories(example0 PRIVATE ../src)
