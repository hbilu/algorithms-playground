#include "catch2/catch.hpp"
#include "../../cpp_playground/search/iterative_deepening_search_IDS.hpp"

struct GraphFixture {
    IDS ids;
    std::unordered_map<std::string, std::vector<std::string>> graph;

    GraphFixture() {
        graph = {
            {"A", {"B", "C"}},
            {"B", {"D", "E"}},
            {"C", {"F"}},
            {"D", {}},
            {"E", {"G"}},
            {"F", {}},
            {"G", {}}
        };
    }
};

TEST_CASE_METHOD(GraphFixture, "IDS - target exists", "[ids]") {
    REQUIRE(ids.iterative_deepening_search(graph, "A", "G", 5));        // requires true
}

TEST_CASE_METHOD(GraphFixture, "IDS - target does not exist", "[ids]") {
    REQUIRE_FALSE(ids.iterative_deepening_search(graph, "A", "Z", 5));
}

TEST_CASE_METHOD(GraphFixture, "IDS - root is target", "[ids]") {
    REQUIRE(ids.iterative_deepening_search(graph, "A", "A", 5));
}

TEST_CASE_METHOD(GraphFixture, "IDS - target at max depth", "[ids]") {
    REQUIRE_FALSE(ids.iterative_deepening_search(graph, "A", "G", 2));
    REQUIRE_FALSE(ids.iterative_deepening_search(graph, "A", "G", 3));
    REQUIRE(ids.iterative_deepening_search(graph, "A", "G", 4));
}

TEST_CASE("IDS - disconnected graph") {
    IDS ids;
    std::unordered_map<std::string, std::vector<std::string>> graph = {
        {"A", {"B"}},
        {"B", {}},
        {"C", {"D"}},
        {"D", {}}
    };
    REQUIRE_FALSE(ids.iterative_deepening_search(graph, "A", "D", 5));
    REQUIRE(ids.iterative_deepening_search(graph, "C", "D", 2));
}