#include "catch2/catch.hpp"
#include "../../cpp_playground/search/bfs_for_graph.hpp"

TEST_CASE("BFS - Example 1") {
    BFS graph;
    std::vector<std::vector<int>> adj = {{1}, {0,2}, {1,3}, {2}};
    REQUIRE(graph.bfs(adj) == std::vector<int>{0, 1, 2, 3});
}

TEST_CASE("BFS - Example 2") {
    BFS graph;
    std::vector<std::vector<int>> adj = {{1, 2}, {0, 2, 3}, {0, 1, 4}, {1, 4}, {2, 3}};
    REQUIRE(graph.bfs(adj) == std::vector<int>{0, 1, 2, 3, 4});
}

TEST_CASE("BFS - Single node") {
    BFS graph;
    std::vector<std::vector<int>> adj = {{}};
    REQUIRE(graph.bfs(adj) == std::vector<int>{0});
}

TEST_CASE("BFS - Two nodes") {
    BFS graph;
    std::vector<std::vector<int>> adj = {{1}, {0}};
    REQUIRE(graph.bfs(adj) == std::vector<int>{0, 1});
}

TEST_CASE("BFS - Star Topology") {
    BFS graph;
    std::vector<std::vector<int>> adj = {{1, 2, 3}, {0}, {0}, {0}};
    REQUIRE(graph.bfs(adj) == std::vector<int>{0, 1, 2, 3});
}

TEST_CASE("BFS - Cyclic graph") {
    BFS graph;
    std::vector<std::vector<int>> adj = {{1, 3}, {0, 2}, {1, 3}, {2, 0}};
    REQUIRE(graph.bfs(adj) == std::vector<int>{0, 1, 3, 2});
}

TEST_CASE("BFS - Fully connected graph") {
    BFS graph;
    std::vector<std::vector<int>> adj = {{1, 2}, {0, 2}, {0, 1}};
    REQUIRE(graph.bfs(adj) == std::vector<int>{0, 1, 2});
}

TEST_CASE("BFS - Shortest Path First") {
    BFS graph;
    std::vector<std::vector<int>> adj = {{1, 2}, {3}, {3}, {}};
    REQUIRE(graph.bfs(adj) == std::vector<int>{0, 1, 2, 3});
}