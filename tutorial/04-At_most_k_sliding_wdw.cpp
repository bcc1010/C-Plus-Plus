#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;

// Count subarrays with exactly k distinct integers
int exactlyK(const vector<int>& nums, int k) {
    return atMostK(nums, k) - atMostK(nums, k - 1);
}

int atMostK(const vector<int>& nums, int k) {
    unordered_map<int, int> window;
    int left = 0, count = 0;

    for (int right = 0; right < (int)nums.size(); right++) {
        window[nums[right]]++;

        // Shrink while we have more than k distinct elements
        while ((int)window.size() > k) {
            int leftElem = nums[left];
            window[leftElem]--;
            if (window[leftElem] == 0) window.erase(leftElem);
            left++;
        }

        // All subarrays ending at right and starting at left..right are valid
        count += right - left + 1;
    }
    return count;
}