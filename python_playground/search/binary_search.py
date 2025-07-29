
# Binary Search

# Given a sorted list `arr` and a target value `target`, this function
# returns the index of `target` in the list using binary search.
# If the target is not found, it returns -1.

# Time Complexity: O(log N)
# Space Complexity: O(1)

def binary_search(arr, target):
    left, right = 0, len(arr)-1
    while left <= right:
        middle = (left + right) // 2
        if arr[middle] == target:
            return middle
        elif arr[middle] < target:
            left = middle + 1
        else:
            right = middle - 1
    return -1