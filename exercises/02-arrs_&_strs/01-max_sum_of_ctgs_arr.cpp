// Given an array of integers, return the maximum sum of any contiguous subarray.
// The array contains at least one element and may contain negative numbers.

// Recognition trigger: Kadane's algorithm

#include <vector>
#include <iostream>
using std::vector;

int maxCtgsSum(const vector<int>& nums) {
    if (nums.empty()) return 0;
    int maxSum = nums[0];
    int currSum = nums[0];
    for (size_t i = 1; i < nums.size(); i++) {
        currSum = std::max(currSum + nums[i], nums[i]);
        maxSum = std::max(currSum, maxSum);
    }
    return maxSum;
}

int main() {
    vector<int> v1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> v2 = {-1, -2, -3};
    vector<int> v3 = {5};
    std::cout << maxCtgsSum(v1) << '\n';
    std::cout << maxCtgsSum(v2) << '\n';
    std::cout << maxCtgsSum(v3) << '\n';
}