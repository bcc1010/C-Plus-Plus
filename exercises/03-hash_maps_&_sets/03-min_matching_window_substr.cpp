#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using std::string;
using std::unordered_map;

string findMinMatchingWindowSubstr(const string& s, const string& t) {
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
        if (need.count(c) && need[c] == window[c]) {
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

int main() {
    std::cout << findMinMatchingWindowSubstr("ADOBECODEBANC", "ABC") << "\n";
    std::cout << findMinMatchingWindowSubstr("a", "a") << "\n";
    std::cout << findMinMatchingWindowSubstr("a", "b") << "\n";
    std::cout << findMinMatchingWindowSubstr("aa", "aa") << "\n";
}