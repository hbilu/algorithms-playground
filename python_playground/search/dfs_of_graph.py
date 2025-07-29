# Given a connected undirected graph containing V vertices represented by a 2-d adjacency list adj[][], 
# where each adj[i] represents the list of vertices connected to vertex i. 
# Perform a Depth First Search (DFS) traversal starting from vertex 0, 
# visiting vertices from left to right as per the given adjacency list, 
# and return a list containing the DFS traversal of the graph.

# Time Complexity: O(V + E)
# - V: number of vertices
# - E: number of edges
# - Each vertex and edge is visited once in DFS traversal.

# Space Complexity: O(V)
# - visited[] and result[] take O(V) space
# - recursion call stack may go as deep as O(V) in the worst case

class DFS:

    def dfs_helper(self, node, adj, visited, result):
        visited[node] = True
        result.append(node)
        for neighbor in adj[node]:
            if not visited[neighbor]:
                self.dfs_helper(neighbor, adj, visited, result)
    
    def dfs(self, adj):
        V = len(adj)
        visited = [False] * V
        result = []
        self.dfs_helper(0, adj, visited, result)
        return result
        