#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "../../cpp_playground/search/binary_search.hpp"

TEST_CASE("binary_search - element found in the middle") {
    std::vector<int> data = {1, 3, 5, 7, 9};
    REQUIRE(binary_search(data, 5) == 2);
}

TEST_CASE("binary_search - element not found") {
    std::vector<int> data = {1, 3, 5, 7, 9};
    REQUIRE(binary_search(data, 4) == -1);
}

TEST_CASE("binary_search - first element found") {
    std::vector<int> data = {1, 3, 5, 7, 9};
    REQUIRE(binary_search(data, 1) == 0);
}

TEST_CASE("binary_search - last element found") {
    std::vector<int> data = {1, 3, 5, 7, 9};
    REQUIRE(binary_search(data, 9) == 4);
}

TEST_CASE("binary_search - value below lowest") {
    std::vector<int> data = {10, 20, 30};
    REQUIRE(binary_search(data, 5) == -1);
}

TEST_CASE("binary_search - value above highest") {
    std::vector<int> data = {10, 20, 30};
    REQUIRE(binary_search(data, 35) == -1);
}

TEST_CASE("binary_search - empty list") {
    std::vector<int> data;
    REQUIRE(binary_search(data, 42) == -1);
}

TEST_CASE("binary_search - single element found") {
    std::vector<int> data = {42};
    REQUIRE(binary_search(data, 42) == 0);
}

TEST_CASE("binary_search - single element not found") {
    std::vector<int> data = {42};
    REQUIRE(binary_search(data, 99) == -1);
}
