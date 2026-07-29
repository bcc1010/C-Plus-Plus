#include <string>
#include <vector>
using std::string;
using std::vector;

// Check if a string is a palindrome
bool isPalindrome(const string& s) {
    int left = 0;
    int right = (int)s.size() - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// Fast character frequency array
auto make_frequency_array(const string& s) {
    int freq[26] = {};                  // Zero init freq array
    for (char c : s) freq[c - 'a']++;   // Count each letter
    return freq;
}

// Split by a specific character
vector<string> splitBy(const string& s, char delim) {
    vector<string> parts;
    string curr;
    for (char c : s) {
        if (c == delim) {
            if (!curr.empty()) parts.push_back(curr);
            curr = "";
        } else {
            curr += c;
        }
    }
    if (!curr.empty()) parts.push_back(curr);   // flush the final word!
    return parts;
}

// Build prefix sums
vector<int> buildPrefix(const vector<int>& arr) {
    int n = (int)arr.size();
    vector<int> prefix(n + 1, 0);   // One larger than arr
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + arr[i];
    }
    return prefix;
}

// Sum of arr[left..right] inclusive
int rangeSum(const vector<int>& prefix, int left, int right) {
    return prefix[right + 1] - prefix[left];
}

// Remove all instances of value val from vector, and return new length
int removeElement(vector<int>& nums, int val) {
    int slow = 0;
    for (int fast = 0; fast < (int)nums.size(); fast++) {
        if (nums[fast] != nums[slow]) {
            nums[slow] = nums[fast];
            slow++;
        }
    }
    return slow;
}

// Rotating an array
void rotate(vector<int>& nums, int k) {
    int n = (int)nums.size();
    k %= n;
    if (k == 0) return;

    // Reverse entire array
    // Reverse first k elements
    // Reverse remaining n - k elemets
    std::reverse(nums.begin(), nums.end());
    std::reverse(nums.begin(), nums.begin() + k);
    std::reverse(nums.begin() + k, nums.end());
}

std::pair<int, int> twoSum(const vector<int>& nums, int target) {
    int left = 0;
    int right = (int)nums.size() - 1;

    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            return {left, right};
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
}

// Kadane's algorithm
int maxSubarraySum(const vector<int>& nums) {
    // currSum: the max sum of a subarray ending at the curr pos
    // best: the max sum seen so far
    int currSum = nums[0];
    int best = nums[0];

    for (int i = 1; i < (int)nums.size(); i++) {
        currSum = std::max(nums[i], currSum + nums[i]);
        best = std::max(currSum, best);
    }
    
    return best;
}