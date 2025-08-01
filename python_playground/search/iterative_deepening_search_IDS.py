
# Perform Iterative Deepening Search (IDS) on a graph represented as an adjacency list (dict),
# starting from a given node and searching for a target node up to a specified max_depth.
# IDS performs repeated Depth-Limited Searches (DLS) with increasing depth limits, combining
# the low memory usage of DFS with the completeness of BFS.

# Each DLS uses a visited set to avoid revisiting nodes within that depth limit.
# The search respects the left-to-right order of neighbors as listed in the adjacency dict.
# Returns True if the target is found within the given depth limit; otherwise, False.

# Time Complexity: O(b^d)
# - b: branching factor
# - d: depth of the target node
# - Nodes at shallow depths may be revisited in each iteration

# Space Complexity: O(d)
# - Only the recursion stack and visited set for the current depth-limited search are stored

# Example:
# graph = {
#     'A': ['B', 'C'],
#     'B': ['D', 'E'],
#     'C': ['F'],
#     'D': [], 
#     'E': ['G'], 
#     'F': [], 
#     'G': []
# }
# IDS().iterative_deepening_search(graph, 'A', 'G', max_depth=4) → True


class IDS:

    def depth_limited_search(self, graph, current, target, limit, visited):
        visited.add(current)
        if current == target:
            return True
        if limit <= 0:
            return False
        for neighbor in graph.get(current, []):
            if neighbor not in visited:
                if self.depth_limited_search(graph, neighbor, target, limit-1, visited):
                    return True
        return False

    def iterative_deepening_search(self, graph, start, target, max_depth=5):
        for depth in range(max_depth):
            visited = set()
            if self.depth_limited_search(graph, start, target, depth, visited):
                return True
        return False