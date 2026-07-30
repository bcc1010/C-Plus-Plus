#include <vector>
using std::vector;

void moveZeros(vector<int>& nums) {
    int slow = 0;
    for (int fast = 0; fast < (int)nums.size(); fast++) {
        if (nums[fast] != 0) {
            nums[slow] = nums[fast];
            slow++;
        }
    }
    // Fill remainder with zeros
    while (slow < (int)nums.size()) {
        nums[slow++] = 0;
    }
}