# Perform Uniform Cost Search (UCS) on a weighted graph (adjacency list) to find
# the least-cost path from a start node to a goal node. UCS uses a priority queue
# to always expand the node with the lowest cumulative cost first.

# Assumes the graph is positively weighted (no negative edge weights).
# Returns (path, cost) if the goal is reachable; otherwise (None, -1).

# Time Complexity: O(b^d)
# - b: branching factor
# - d: depth of the optimal solution (in terms of number of edges, not cost)

# Space Complexity: O(b^d)
# - Due to storing all frontier paths in the priority queue

# Example:
# graph = {
#     'A': [('B', 1), ('C', 5)],
#     'B': [('D', 2)],
#     'C': [('D', 2)],
#     'D': []
# }
# uniform_cost_search(graph, 'A', 'D') → (['A', 'B', 'D'], 3)

import heapq

class UCS:
    def uniform_cost_search(self, graph, start, goal):
        queue = [(0, start, [start])]    # Priority queue: (cost_so_far, current_node, path_to_node)
        visited = set()
        while queue:
            # The heapq module implements a min-heap, which keeps the smallest element always at the top
            cost, node, path = heapq.heappop(queue)    # Pop the smallest element O(log n)
            if node in visited:
                continue
            visited.add(node)
            if node == goal:
                return path, cost
            for neighbor, weight in graph.get(node, []):
                if neighbor not in visited:
                    heapq.heappush(queue, (cost + weight, neighbor, path + [neighbor])) # Add a new node O(log n)
        return None, -1

