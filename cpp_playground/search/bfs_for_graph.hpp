#pragma once
#include <vector>
#include <queue>

class BFS {
public:
    [[nodiscard]]
    std::vector<int> bfs(const std::vector<std::vector<int>>& adj);

private:
    void bfs_helper(int node, const std::vector<std::vector<int>>& adj, std::queue<int>& q,
                    std::vector<bool>& visited, std::vector<int>& result);
};