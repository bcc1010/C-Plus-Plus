#include <vector>
using std::vector;

// Merge two sorted arrays into one sorted array
vector<int> mergeSorted(const vector<int>& a, const vector<int>& b) {
    vector<int> res;
    int i = 0, j = 0;

    while (i < (int)a.size() && j < (int)b.size()) {
        if (a[i] <= b[j]) {
            res.push_back(a[i++]);
        } else {
            res.push_back(b[j++]);
        }
    }

    // Append remaining elements from whichever array is not exhausted
    while (i < (int)a.size()) res.push_back(a[i++]);
    while (j < (int)b.size()) res.push_back(b[j++]);

    return res;
}