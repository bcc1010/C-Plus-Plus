#include <iostream>
#include <string>
#include <unordered_map>
using std::iostream;
using std::string;
using std::unordered_map;

// Minimum window substring containing all characters of t
string minWindow(const string& s, const string& t) {
    unordered_map<char, int> need;
    for (char c : t) need[c]++;

    int have = 0;
    int required = (int)need.size();
    int left = 0;
    int bestStart = 0;
    int bestLen = INT_MAX;

    unordered_map<char, int> window;

    for (int right = 0; right < (int)s.size(); right++) {
        char c = s[right];
        window[c]++;

        // Check if this character's requirement is now satisfied
        if (need.count(c) && window[c] == need[c]) {
            have++;
        }

        // Shrink from left while window is valid
        while (have == required) {
            // Update best
            if (right - left + 1 < bestLen) {
                bestLen = right - left + 1;
                bestStart = left;
            }

            // Remove left character from window
            char lc = s[left];
            window[lc]--;
            if (need.count(lc) && window[lc] < need[lc]) {
                have--;     // This requirement is now satisfied
            }
            left++;
        }
    }

    return bestLen == INT_MAX ? "" : s.substr(bestStart, bestLen);
}