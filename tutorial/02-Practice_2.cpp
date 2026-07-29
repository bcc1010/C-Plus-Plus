// Given an array of integers and an integer k, return the number of subarrays whose sum equals k.
#include <unordered_map>
#include <vector>
using std::vector;
using std::unordered_map;

// Pattern: Prefix Sum + Hash Map

std::vector<int> buildPrefix(const std::vector<int>& arr) {
    int n = (int)arr.size();
    std::vector<int> prefix(n + 1, 0);  //  One larger than arr - prefix[0] = 0
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + arr[i];
    }
    return prefix;
}

int sumEqualsK(vector<int> arr, int k) {
    unordered_map<int, int> sumCount;
    if (arr.empty()) return 0;
    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
    }
}

int rangeSum(const std::vector<int>& prefix, int left, int right) {
    return prefix[right + 1] - prefix[left];
}