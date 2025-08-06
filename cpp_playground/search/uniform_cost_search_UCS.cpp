/**
 Perform Uniform Cost Search (UCS) on a weighted graph (adjacency list) to find
 the least-cost path from a start node to a goal node.

 UCS uses a priority queue to always expand the node with the lowest cumulative cost first.
 It guarantees an optimal path when all edge weights are non-negative.

 Assumptions:
 - The graph is positively weighted (no negative edge weights).
 
 Returns:
 - A pair (path, cost) where `path` is a vector of node names (std::string) and `cost` is the total path cost.
 - If the goal is unreachable, returns (empty vector, -1).
 
 Time Complexity: O(b^d)
 - b: branching factor
 - d: depth of the optimal solution (in terms of number of edges)
 
 Space Complexity: O(b^d)
 - Due to storing all frontier paths in the priority queue
 
 Example:
  UCS::Graph graph = {
     {"A", {{"B", 1}, {"C", 5}}},
     {"B", {{"D", 2}}},
     {"C", {{"D", 2}}},
    {"D", {}}
  };
  UCS ucs;
  auto [path, cost] = ucs.uniform_cost_search(graph, "A", "D");
  result --> path = {"A", "B", "D"}, cost = 3
 */














#include "uniform_cost_search_UCS.hpp"

UCS::PathResult UCS::uniform_cost_search(const Graph& graph, const Node& start, const Node& goal){
    using QueueNode = std::tuple<int, Node, std::vector<Node>>;   // (cost_so_far, current_node_name, path_to_node)
    // Lambda comparator: sort by cost (lowest first)
    auto comparator = [](const QueueNode& a, const QueueNode& b){
        return std::get<0>(a) > std::get<0>(b);   // min-heap: smaller cost has higher priority
    };
    // std::priority_queue is by default a max-heap, meaning it always pops the largest element first, so comparator function is applied.
    std::priority_queue<QueueNode, std::vector<QueueNode>, decltype(comparator)> queue(comparator);
    std::set<Node> visited;

    queue.emplace(0, start, std::vector<Node>{start});

    while (!queue.empty()){
        auto [cost, node, path] = queue.top();
        queue.pop();
        if (visited.contains(node)) continue;
        visited.insert(node);
        if (node == goal) return {path, cost};
        if (graph.contains(node)) {
            for (const auto& [neighbor, weight] : graph.at(node)) {
                if (!visited.contains(neighbor)) {
                    auto new_path = path;
                    new_path.push_back(neighbor);
                    queue.emplace(cost + weight, neighbor, new_path);
                }
            }
        }
    }
    return {{}, -1}; 
}