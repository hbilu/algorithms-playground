/*
  Perform Iterative Deepening Search (IDS) on a graph represented as an
  adjacency list (std::unordered_map<std::string, std::vector<std::string>>).
  IDS performs repeated Depth-Limited Searches (DLS) with increasing depth limits, combining
  the low memory usage of DFS with the completeness of BFS.
 
  Each DLS uses a visited set to avoid revisiting nodes within the same depth limit.
  The traversal respects the left-to-right neighbor order as listed in the adjacency list.
  Returns true if the target is found within the given depth limit; otherwise, false.
 
  Time Complexity: O(b^d)
  - b: branching factor (average number of neighbors per node)
  - d: depth of the target node
  - Note: nodes at shallower depths may be revisited in each iteration
 
  Space Complexity: O(d)
  - Only the recursion stack and visited set for the current depth-limited search are stored
 
  Example:
    std::unordered_map<std::string, std::vector<std::string>> graph = {
        {"A", {"B", "C"}},
        {"B", {"D", "E"}},
        {"C", {"F"}},
        {"D", {}},
        {"E", {"G"}},
        {"F", {}},
        {"G", {}}
    };
 
    IDS ids;
    ids.iterative_deepening_search(graph, "A", "G", 4); → true
 */

#include "iterative_deepening_search_IDS.hpp"

bool IDS::iterative_deepening_search(
    const std::unordered_map<std::string, std::vector<std::string>>& graph,
    const std::string& start,
    const std::string& target,
    int max_depth
){
    for (int depth = 0; depth < max_depth; ++ depth){
        std::unordered_set<std::string> visited;
        if (depth_limited_search(graph, start, target, depth, visited)){
            return true;
        }
    }
    return false;
}

bool IDS::depth_limited_search(
    const std::unordered_map<std::string, std::vector<std::string>>& graph,
    const std::string& current,
    const std::string& target,
    int limit,
    std::unordered_set<std::string>& visited
){
    visited.insert(current);
    if (current == target) return true;
    if (limit <= 0) return false;
    auto x = graph.find(current);
    if (x != graph.end()){
        for (const auto& neighbor : x->second){
            if (visited.find(neighbor) == visited.end()){
                if (depth_limited_search(graph, neighbor, target, limit -1, visited)){
                    return true;
                }
            }
        }
    }
    return false;
}