// Given a string, return the length of the longest substring that contains
// no repeating characters.

// Recognition trigger: variable sliding window

#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;

int findLongestSubstring(const string& s) {
    int left = 0;
    int max_len = 0;
    
    // Initialise a frequency array
    vector<int> char_count(26, 0);

    for (int right = 0; right < static_cast<int>(s.length()); right++) {
        char_count[s[right] - 'a']++;
        while (char_count[s[right] - 'a'] > 1) {
            char_count[s[left] - 'a']--;
            left++;
        }
        max_len = std::max(max_len, right - left + 1);
    }
    return max_len;
}

int main() {
    string ex = "blehblobfishermans";
    std::cout << findLongestSubstring(ex) << std::endl;
    return 0;
}