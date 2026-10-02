/*
Problem: Find the Index of the First Occurrence in a String
LeetCode: 28
Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

Approach:
- Traverse the `haystack` string from the beginning.
- For each index, extract a substring of the same length as `needle`.
- Compare the extracted substring with `needle`.
- If both strings match, return the current index.
- If no matching substring is found, return `-1`.

Time Complexity: O(n * m)
Space Complexity: O(m)
*/

#include<string>
using namespace std;

class Solution {
    public:
        int strStr(string haystack, string needle) {
            for (int i = 0; i <= haystack.length(); i++) {
                if (haystack.substr(i, needle.length()) == needle) {
                    return i;
                }
            }
            return -1;
        }
    };