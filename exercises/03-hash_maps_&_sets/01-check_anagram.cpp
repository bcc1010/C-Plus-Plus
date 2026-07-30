#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;

bool checkAnagram(const string& s, const string& t) {
    if (s.size() == t.size()) return false;
    vector<int> freq(26);
    for (char c : s) freq[c - 'a']++;
    for (char c : t) freq[c - 'a']--;
    for (int x : freq) {
        if (x != 0) return false;
    }
    return true;
}

int main() {
    std::cout << checkAnagram("anagram", "nagaram");
    std::cout << checkAnagram("rat", "car");
    std::cout << checkAnagram("a", "a");
}