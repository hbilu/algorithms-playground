#include "dfs_of_graph.hpp"

void DFS::dfs_helper(int node, const std::vector<std::vector<int>>& adj,
                     std::vector<bool>& visited, std::vector<int>& result) {
    visited[node] = true;
    result.push_back(node);
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs_helper(neighbor, adj, visited, result);
        }
    }
}

std::vector<int> DFS::dfs(const std::vector<std::vector<int>>& adj) {
    int V = adj.size();
    std::vector<bool> visited(V, false);
    std::vector<int> result;
    dfs_helper(0, adj, visited, result);
    return result;
}