// Given an array of integers, find the length of the longest subarray where
// all elements are distinct.

#include <iostream>
#include <vector>
#include <unordered_set>
using std::vector;
using std::unordered_set;

int findLongestAllDistSubarray(const vector<int>& arr) {
    int left = 0;
    int bestLen = 0;
    unordered_set<int> seen;

    for (int right = 0; right < (int)arr.size(); right++) {
        int rightElem = arr[right];
        while (seen.count(rightElem)) {
            seen.erase(arr[left]);
            left++;
        }
        seen.insert(rightElem);
        if (right - left + 1 > bestLen) {
            bestLen = right - left + 1;
        }
    }

    return bestLen;
}

int main() {
    vector<int> nums = {1, 2, 3, 1, 2, 3, 4};
    std::cout << findLongestAllDistSubarray(nums);
}