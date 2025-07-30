#pragma once
#include <span>

template <typename T>
[[nodiscard]]
int binary_search(std::span<const T> arr, T target);