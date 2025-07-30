cmake_minimum_required(VERSION 3.10)
project(algorithm_playground)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(algorithms
    cpp_playground/search/binary_search.cpp
    cpp_playground/search/dfs_of_graph.cpp
)

add_executable(cpp_tests
    tests/cpp/test_main.cpp
    tests/cpp/test_binary_search.cpp
    tests/cpp/test_dfs_of_graph.cpp
)

target_include_directories(cpp_tests PRIVATE cpp_playground tests/cpp)

target_link_libraries(cpp_tests PRIVATE algorithms)