/*
Given a connected undirected graph containing V vertices represented by a 2D adjacency list adj[][],
where each adj[i] represents the list of vertices connected to vertex i.
Perform a Breadth First Search (BFS) traversal starting from vertex 0,
visiting vertices from left to right as per the given adjacency list,
and return a list containing the BFS traversal of the graph.

Example:
Input: adj = [[1, 2], [0, 2, 3], [0, 1, 4], [1, 4], [2, 3]]
Output: [0, 1, 2, 3, 4]
Explanation:
Start BFS from vertex 0 → visit 1 and 2 → from 1 visit 3 → from 2 visit 4.

Time Complexity: O(V + E)
- V: number of vertices
- E: number of edges
- Each vertex and edge is visited once

Space Complexity: O(V)
- visited[] and result[] take O(V) space
- std::queue used for BFS holds up to O(V) nodes in the worst case
*/

#include "bfs_for_graph.hpp"

std::vector<int> BFS::bfs(const std::vector<std::vector<int>>& adj){
    int V = adj.size();
    std::vector<bool> visited(V, false);
    std::vector<int> result;
    std::queue<int> q;
    bfs_helper(0, adj, q, visited, result);
    return result;
}


void BFS:: bfs_helper(int node, const std::vector<std::vector<int>>& adj, std::queue<int>& q,
                    std::vector<bool>& visited, std::vector<int>& result){
    visited[node] = true;
    q.push(node);
    while (!q.empty()){
        int current = q.front();
        q.pop();
        result.push_back(current);
        for (int neighbor : adj[current]){
            if (!visited[neighbor]){
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}