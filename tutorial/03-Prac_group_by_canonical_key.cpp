// Group anagrams - words that are anagrams of each other
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using std::vector;
using std::unordered_map;
using std::string;

vector<vector<string>> groupAnagrams(const vector<string>& words) {
    unordered_map<string, vector<string>> groups;

    for (const auto& word : words) {
        string key = word;
        std::sort(key.begin(), key.end());  // Sorted form is canonical key
        groups[key].push_back(word);
    }

    vector<vector<string>> res;
    for (auto& [key, group] : groups) {
        res.push_back(std::move(group));    // Move to avoid copying
    }
    return res;
}