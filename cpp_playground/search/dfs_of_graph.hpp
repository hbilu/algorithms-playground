#pragma once
#include <vector>

class DFS {
public:
    std::vector<int> dfs(const std::vector<std::vector<int>>& adj);

private:
    void dfs_helper(int node, const std::vector<std::vector<int>>& adj,
                    std::vector<bool>& visited, std::vector<int>& result);
};