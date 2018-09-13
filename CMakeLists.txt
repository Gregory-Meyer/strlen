cmake_minimum_required(VERSION 3.8)

project(strlen)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)

option(STRLEN_BUILD_BENCHMARKS "build benchmark for strlen" OFF)
if(STRLEN_BUILD_BENCHMARKS)
    find_package(Threads REQUIRED)
    find_package(benchmark REQUIRED)

    include_directories(${benchmark_INCLUDE_DIRS})

    add_executable(bench bench/string_length.cpp)
    target_link_libraries(bench benchmark benchmark_main Threads::Threads)
endif()

option(STRLEN_BUILD_TESTS "build tests for strlen" OFF)
if(STRLEN_BUILD_TESTS)
    include_directories(external/catch2)

    add_executable(test test/main.cpp test/string_length.cpp)
endif()
