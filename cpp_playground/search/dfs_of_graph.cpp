/*
Given a connected undirected graph containing V vertices represented by a 2D adjacency list adj[][],
where each adj[i] represents the list of vertices connected to vertex i.
Perform a Depth First Search (DFS) traversal starting from vertex 0,
visiting vertices from left to right as per the given adjacency list,
and return a list containing the DFS traversal of the graph.

Time Complexity: O(V + E)
- V: number of vertices
- E: number of edges
- Each vertex and edge is visited once in DFS traversal.

Space Complexity: O(V)
- visited[] and result[] take O(V) space
- recursion call stack may go as deep as O(V) in the worst case
*/

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