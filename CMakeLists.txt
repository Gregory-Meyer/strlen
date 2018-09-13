cmake_minimum_required(VERSION 3.8)

project(strlen)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Threads REQUIRED)

find_package(benchmark REQUIRED)

include_directories(${benchmark_INCLUDE_DIRS})

add_executable(bench bench.cpp)
target_link_libraries(bench benchmark benchmark_main Threads::Threads)

add_executable(test catch_main.cpp test.cpp)
