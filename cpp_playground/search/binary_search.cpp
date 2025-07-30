/*
Binary Search

Given a sorted vector `arr` and a target value `target`, this function
returns the index of `target` in the vector using binary search.
If the target is not found, it returns -1.

Time Complexity: O(log N)
Space Complexity: O(1)
*/

#include "binary_search.hpp"

template <typename T>
int binary_search(std::span<const T> arr, T target) {
    int left = 0, right = static_cast<int>(arr.size()) - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }

    return -1;
}

template int binary_search<int>(std::span<const int>, int);