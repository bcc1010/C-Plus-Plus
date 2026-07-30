#include <vector>
#include <algorithm>
using std::vector;

vector<vector<int>> threeSum(const vector<int>& nums, int k) {
    // This approach requires a sorted array
    vector<int> sorted_nums = nums;
    std::sort(sorted_nums.begin(), sorted_nums.end());

    // Initialise variables
    vector<vector<int>> res;
    int n = (int)nums.size();

    for (int i = 0; i < n - 2; i++) {
        // Skip duplicate values for the fixed element
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        // Set up two pointers
        int left = i + 1;
        int right = n - 1;

        // The core of the algorithm
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == k) {
                res.push_back({nums[i], nums[left], nums[right]});
                // Skip duplicates for left and right
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;
                left++;
                right--;
            } else if (sum < k) {
                // Too small
                left++;
            } else {
                // Too big
                right--;
            }
        }
    }
    return res;
}