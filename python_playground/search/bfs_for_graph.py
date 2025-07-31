# Given a connected undirected graph containing V vertices represented by a 2D adjacency list adj[][],
# where each adj[i] represents the list of vertices connected to vertex i.
# Perform a Breadth First Search (BFS) traversal starting from vertex 0,
# visiting vertices from left to right as per the given adjacency list,
# and return a list containing the BFS traversal of the graph.

# Example:
# Input: adj = [[1, 2], [0, 2, 3], [0, 1, 4], [1, 4], [2, 3]]
# Output: [0, 1, 2, 3, 4]
# Explanation:
# Start BFS from vertex 0 → visit 1 and 2 → from 1 visit 3 → from 2 visit 4.

# Time Complexity: O(V + E)
# - V: number of vertices
# - E: number of edges
# - Each vertex and edge is visited once

# Space Complexity: O(V)
# - visited[] and result[] take O(V) space
# - queue used for BFS takes O(V) space in the worst case

from collections import deque

class BFS:
    
    def bfs(self, adj):
        visited = [False] * len(adj)
        result = []
        queue = deque()
        self.bfs_helper(0, adj, visited, queue, result)
        return result
    
    def bfs_helper(self, start, adj, visited, queue, result):
        visited[start] = True
        queue.append(start)
        while queue:
            current = queue.popleft()          # O(1) --> if queue is list (not dequeue), then queue.pop(0) is O(n), resulting time complexity O(V²)
            result.append(current)
            for neighbor in adj[current]:
                if not visited[neighbor]:
                    visited[neighbor] = True
                    queue.append(neighbor)