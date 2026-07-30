#include <iostream>
#include <vector>
#include <unordered_set>
using std::vector;
using std::unordered_set;

int findLongestConsecLen(const vector<int>& nums) {
    unordered_set<int> numsAsSet(nums.begin(), nums.end());
    int bestLen = 0;
    for (int x : nums) {
        if (!numsAsSet.count(x - 1)) {
            int curr = x;
            int length = 1;
            while (numsAsSet.count(curr + 1)) {
                curr++;
                length++;
            }
            bestLen = std::max(bestLen, length);
        }
    }
    return bestLen;
}

int main() {
    vector<int> v1 = {100, 4, 200, 1, 3, 2};                // 4
    vector<int> v2 = {0, 3, 7, 2, 5, 8, 4, 2, 6, 0, 1};     // 9
    vector<int> v3 = {1};                                   // 1
    std::cout << findLongestConsecLen(v1) << "\n";
    std::cout << findLongestConsecLen(v2) << "\n";
    std::cout << findLongestConsecLen(v3) << "\n";
}