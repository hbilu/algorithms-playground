cmake_minimum_required(VERSION 3.10)
project(algorithm_playground)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(binary_search
    cpp_playground/search/binary_search.cpp
)

add_executable(test_binary_search
    tests/cpp/test_binary_search.cpp
)

target_include_directories(test_binary_search PRIVATE tests/cpp)

target_link_libraries(test_binary_search binary_search)