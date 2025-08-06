#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>


class UCS {
public:
    using Node = std::string;
    using Edge = std::pair<Node, int>;
    using Graph = std::unordered_map<Node, std::vector<Edge>>;
    using PathResult = std::pair<std::vector<Node>, int>;

    // Returns (path, cost); if unreachable → ({}, -1)
    PathResult uniform_cost_search(const Graph& graph, const Node& start, const Node& goal);
};