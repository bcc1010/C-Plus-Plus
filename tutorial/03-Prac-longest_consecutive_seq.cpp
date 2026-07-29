// Longest consecutive sequence
// Given [100, 4, 200, 1, 3, 2], return 4 (sequence 1, 2, 3, 4)

#include <vector>
#include <unordered_set>
using std::vector;
using std::unordered_set;

int longestConsecutive(const vector<int>& nums) {
    unordered_set<int> numSet(nums.begin(), nums.end());
    int best = 0;

    for (int x : nums) {
        // Only start counting from the beginning of a sequence
        // A sequence beginning is a number with no left neighbour
        if (!numSet.count(x - 1)) {
            int curr = x;
            int len = 1;

            while (numSet.count(curr + 1)) {
                curr++;
                len++;
            }

            best = std::max(best, len);
        }
    }
    return best;
}