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
    int required = (int)t.size();
    int bestStart = 0;
    int bestLen = INT_MAX;
    int left = 0;
    
    for (int right = 0; right < (int)s.size(); right++) {
        // Check if increment have
        char c = s[right];
        window[c]++;
        if (need.count(c) && window[c] == need[c]) {
            have++;
        }

        while (have == required) {
            if (right - left + 1 < bestLen) {
                bestLen = right - left + 1;
                bestStart = left;
            }

            char lc = s[left];
            window[lc]--;
            if (need.count(lc) && window[lc] < need[lc]) {
                have--;
            }
            left++;
        }
    }
    return bestLen == INT_MAX ? "" : s.substr(bestStart, bestLen);
}