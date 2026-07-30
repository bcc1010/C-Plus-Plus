#include <vector>
using std::vector;

// Assume the nums array is sorted
int removeDuplicates(std::vector<int>& nums) {
    if (nums.empty()) return 0;     // Short circuit
    int slow = 0;

    for (int fast = 1; fast < (int)nums.size(); fast++) {
        if (nums[fast] != nums[slow]) {
            slow++;
            nums[slow] = nums[fast];
        }
    }
    return slow + 1;        // Length of deduplicated array (index + 1)
}