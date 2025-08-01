#pragma once
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

class IDS {
public:
    [[nodiscard]]
    bool iterative_deepening_search (
        const std::unordered_map<std::string, std::vector<std::string>>& graph,
        const std::string& start,
        const std::string& target,
        int max_depth = 5
    );

private:
    bool depth_limited_search(
        const std::unordered_map<std::string, std::vector<std::string>>& graph,
        const std::string& current,
        const std::string& target,
        int limit,
        std::unordered_set<std::string>& visited
    );
};