// Given an array of integers nums and an integer k, return the number of contiguous subarrays whose sum equals k.

// Recognition trigger: Prefix sum + hash map
#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;

int countCtgsSubarraysSumK(const vector<int>& nums, const int& k) {
    unordered_map<int, int> prefixCount;
    prefixCount[0] = 1;
    int currSum = 0;
    int count = 0;

    for (int x : nums) {
        currSum += x;
        int cpl = currSum - k;
        if (prefixCount.count(cpl)) {
            count += prefixCount[cpl];
        }
        prefixCount[currSum]++;
    }

    return count;
}