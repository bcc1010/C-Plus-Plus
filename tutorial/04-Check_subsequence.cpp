// Is s a subsequence of t?
// "ace" is a subsequence of "abcde" - a, c, e appear in order
bool isSubsequence(const std::string& s, const std::string& t) {
    int i = 0, j = 0;

    while (i < (int)s.size() && j < (int)t.size()) {
        if (s[i] == t[j]) {
            i++;
        }
        j++;
    }

    return i = s.size();
}