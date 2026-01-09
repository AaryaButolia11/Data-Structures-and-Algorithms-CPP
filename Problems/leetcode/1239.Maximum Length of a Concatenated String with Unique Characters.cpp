#include <vector>
#include <string>
#include <algorithm>
#include <bitset>

using namespace std;

class Solution {
public:
    int maxLength(vector<string>& arr) {
        // First, filter out strings with duplicate characters
        vector<string> filtered;
        for (const string& s : arr) {
            bitset<26> chars;
            bool valid = true;
            for (char c : s) {
                if (chars.test(c - 'a')) {
                    valid = false;
                    break;
                }
                chars.set(c - 'a');
            }
            if (valid) {
                filtered.push_back(s);
            }
        }

        // Sort the filtered strings by length in descending order
        sort(filtered.begin(), filtered.end(), [](const string& a, const string& b) {
            return a.size() > b.size();
        });

        // Use backtracking to find the maximum length
        bitset<26> current;
        return backtrack(filtered, current, 0);
    }

private:
    int backtrack(const vector<string>& arr, bitset<26>& current, int index) {
        int max_len = current.count();
        for (int i = index; i < arr.size(); ++i) {
            bool canAdd = true;
            bitset<26> temp;
            for (char c : arr[i]) {
                if (current.test(c - 'a')) {
                    canAdd = false;
                    break;
                }
                temp.set(c - 'a');
            }
            if (canAdd) {
                current |= temp;
                max_len = max(max_len, backtrack(arr, current, i + 1));
                current ^= temp; // backtrack
            }
        }
        return max_len;
    }
};
