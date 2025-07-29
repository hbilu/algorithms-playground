#include "catch2/catch.hpp"
#include "../../cpp_playground/search/dfs_of_graph.hpp"

TEST_CASE("DFS - Example 1") {
    DFS graph;
    std::vector<std::vector<int>> adj = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
    std::vector<int> expected = {0, 2, 4, 3, 1};
    REQUIRE(graph.dfs(adj) == expected);
}

TEST_CASE("DFS - Example 2") {
    DFS graph;
    std::vector<std::vector<int>> adj = {{1, 2}, {0, 2}, {0, 1, 3, 4}, {2}, {2}};
    std::vector<int> expected = {0, 1, 2, 3, 4};
    REQUIRE(graph.dfs(adj) == expected);
}

TEST_CASE("DFS - Single node") {
    DFS graph;
    std::vector<std::vector<int>> adj = {{}};
    std::vector<int> expected = {0};
    REQUIRE(graph.dfs(adj) == expected);
}

TEST_CASE("DFS - Linear graph") {
    DFS graph;
    std::vector<std::vector<int>> adj = {{1}, {2}, {3}, {}};
    std::vector<int> expected = {0, 1, 2, 3};
    REQUIRE(graph.dfs(adj) == expected);
}

TEST_CASE("DFS - Cyclic graph") {
    DFS graph;
    std::vector<std::vector<int>> adj = {{1}, {2}, {0}};
    std::vector<int> expected = {0, 1, 2};
    REQUIRE(graph.dfs(adj) == expected);
}

TEST_CASE("DFS - Fully connected graph") {
    DFS graph;
    std::vector<std::vector<int>> adj = {{1, 2}, {0, 2}, {0, 1}};
    std::vector<int> expected = {0, 1, 2};
    REQUIRE(graph.dfs(adj) == expected);
}