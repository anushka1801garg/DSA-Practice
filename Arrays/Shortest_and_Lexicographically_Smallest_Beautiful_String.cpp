/*
Problem: Shortest Beautiful Substring
LeetCode: 2904
Link: https://leetcode.com/problems/shortest-beautiful-substring/

Approach:
- Use the sliding window technique with two pointers.
- Maintain a frequency map to count the number of `1`s in the current window.
- Expand the window by moving the `j` pointer through the string.
- When the window contains exactly `k` ones:
  - Move the `i` pointer forward over leading zeros to get the shortest possible window.
  - Calculate the current window length and compare it with the minimum length found so far.
  - If the lengths are equal, compare the two substrings lexicographically and keep the smaller one.
  - Remove the leftmost `1` from the frequency map and move `i` forward to search for the next valid window.
- After processing the entire string, construct and return the shortest beautiful substring.
- If no valid substring exists, return an empty string.

Time Complexity: O(n²)
Space Complexity: O(n)
*/

#include<string>
using namespace std;

class Solution {
    public:
        string shortestBeautifulSubstring(string s, int k) {
            int i = 0, j = 0;
            int mini1 = INT_MAX, mini2 = INT_MAX;
            int startingindex = 0;
    
            unordered_map<char, int> mp;
            string ans = "";
    
            while (j < s.length()) {
                if (s[j] == '1')
                    mp[s[j]]++;
                if (mp['1'] == k) {
                    while (s[i] == '0')
                        i++;
    
                    mini1 = j - i + 1;
                    if (mini1 < mini2) {
                        mini2 = mini1;
                        startingindex = i;
                    }
                    else if (mini1 == mini2) {
                        string temp1 = s.substr(i, mini1);
                        string temp2 = s.substr(startingindex, mini2);
                        if (temp1 < temp2) {
                            startingindex = i;
                        }
                    }
                    if (s[i] == '1')
                        mp[s[i]]--;
    
                    i++;
                }
    
                j++;
            }
            if (mini2 != INT_MAX) {
                for (int x = startingindex; x < startingindex + mini2; x++) {
                    ans += s[x];
                }
            }
    
            return ans;
        }
    };