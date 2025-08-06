#include "catch2/catch.hpp"
#include "../../cpp_playground/search/uniform_cost_search_UCS.hpp"

UCS ucs;

TEST_CASE("UCS - Basic path") {
    UCS::Graph graph = {
        {"A", {{"B", 1}, {"C", 5}}},
        {"B", {{"D", 2}}},
        {"C", {{"D", 2}}},
        {"D", {}}
    };
    auto [path, cost] = ucs.uniform_cost_search(graph, "A", "D");
    REQUIRE(path == std::vector<std::string>{"A", "B", "D"});
    REQUIRE(cost == 3);
}

TEST_CASE("UCS - No path") {
    UCS::Graph graph = {
        {"A", {{"B", 1}}},
        {"B", {}},
        {"C", {{"D", 2}}}
    };
    auto [path, cost] = ucs.uniform_cost_search(graph, "A", "D");
    REQUIRE(path.empty());
    REQUIRE(cost == -1);
}

TEST_CASE("UCS - Start is goal") {
    UCS::Graph graph = {
        {"A", {{"B", 1}}},
        {"B", {{"A", 1}}}
    };
    auto [path, cost] = ucs.uniform_cost_search(graph, "A", "A");
    REQUIRE(path == std::vector<std::string>{"A"});
    REQUIRE(cost == 0);
}

TEST_CASE("UCS - Multiple paths") {
    UCS::Graph graph = {
        {"A", {{"B", 2}, {"C", 2}}},
        {"B", {{"D", 2}}},
        {"C", {{"D", 1}}},
        {"D", {{"E", 3}}},
        {"E", {}}
    };
    auto [path, cost] = ucs.uniform_cost_search(graph, "A", "E");
    REQUIRE(path == std::vector<std::string>{"A", "C", "D", "E"});
    REQUIRE(cost == 6);
}

TEST_CASE("UCS - Disconnected graph") {
    UCS::Graph graph = {
        {"A", {{"B", 1}}},
        {"B", {}},
        {"X", {{"Y", 1}}},
        {"Y", {}}
    };
    auto [path, cost] = ucs.uniform_cost_search(graph, "A", "Y");
    REQUIRE(path.empty());
    REQUIRE(cost == -1);
}

TEST_CASE("UCS - Cyclic graph") {
    UCS::Graph graph = {
        {"A", {{"B", 1}}},
        {"B", {{"C", 2}}},
        {"C", {{"A", 3}, {"D", 1}}},
        {"D", {}}
    };
    auto [path, cost] = ucs.uniform_cost_search(graph, "A", "D");
    REQUIRE(path == std::vector<std::string>{"A", "B", "C", "D"});
    REQUIRE(cost == 4);
}

TEST_CASE("UCS - Zero-cost edges") {
    UCS::Graph graph = {
        {"A", {{"B", 0}, {"C", 2}}},
        {"B", {{"D", 0}}},
        {"C", {{"D", 2}}},
        {"D", {}}
    };
    auto [path, cost] = ucs.uniform_cost_search(graph, "A", "D");
    REQUIRE(path == std::vector<std::string>{"A", "B", "D"});
    REQUIRE(cost == 0);
}

TEST_CASE("UCS - Equal cost paths") {
    UCS::Graph graph = {
        {"A", {{"B", 2}, {"C", 2}}},
        {"B", {{"D", 2}}},
        {"C", {{"D", 2}}},
        {"D", {}}
    };
    auto [path, cost] = ucs.uniform_cost_search(graph, "A", "D");
    REQUIRE((path == std::vector<std::string>{"A", "B", "D"} || path == std::vector<std::string>{"A", "C", "D"}));
    REQUIRE(cost == 4);
}
