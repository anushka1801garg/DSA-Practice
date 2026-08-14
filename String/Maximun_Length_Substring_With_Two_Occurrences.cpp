/*
Problem: Maximum Length Substring With at Most Two Occurrences
LeetCode: 3090
Link: https://leetcode.com/problems/maximum-length-substring-with-at-most-two-occurrences-of-each-character/

Approach:
- Iterate through every possible starting position of the substring.
- For each starting position, maintain a frequency array of 26 lowercase English letters.
- Expand the substring by moving the `right` pointer forward.
- Increase the frequency of the current character.
- If any character appears more than twice, stop expanding the current substring.
- Update `res` with the maximum valid substring length found.
- Return the maximum length after checking all possible starting positions.

Time Complexity: O(n²)
Space Complexity: O(1)
*/

#include<string>
#include<array>
using namespace std;

class Solution {
    public:
        int maximumLengthSubstring(string s) {
            int n = s.size();
            int res = 0;
            for (int left = 0; left < n; ++left) {
                array<int, 26> count{};
                for (int right = left; right < n; ++right) {
                    const int index = s[right] - 'a';
                    ++count[index];
                    if (count[index] > 2) {
                        break;
                    }
                    res = max(res, right - left + 1);
                }
            }
            return res;
        }
    };