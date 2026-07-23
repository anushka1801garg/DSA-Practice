/*
Problem: Minimum Window Substring
LeetCode: 76
Link: https://leetcode.com/problems/minimum-window-substring/

Approach:
- Store the frequency of each character in the target string using a hash map.
- Use the sliding window technique with two pointers over the source string.
- Expand the window by moving the right pointer and updating the character frequencies.
- Keep track of the number of distinct characters whose required frequencies are not yet satisfied.
- Once all required characters are present in the window, shrink the window from the left to find the smallest valid window.
- Update the minimum window whenever a smaller valid substring is found.
- Return the smallest substring containing all characters of the target string, or an empty string if no such window exists.

Time Complexity: O(n + m)
Space Complexity: O(k)
*/

#include<string>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        string minWindow(string s, string t) {
    
            unordered_map<char, int> mp;
    
            for (char ch : t)
                mp[ch]++;
    
            int count = mp.size();
    
            int i = 0, j = 0;
    
            int start = 0;
            int mini = INT_MAX;
    
            while (j < s.length()) {
    
                // Acquire
                if (mp.find(s[j]) != mp.end()) {
                    mp[s[j]]--;
    
                    if (mp[s[j]] == 0)
                        count--;
                }
    
                // Window is valid
                while (count == 0) {
    
                    if (j - i + 1 < mini) {
                        mini = j - i + 1;
                        start = i;
                    }
    
                    // Release
                    if (mp.find(s[i]) != mp.end()) {
    
                        if (mp[s[i]] == 0)
                            count++;
    
                        mp[s[i]]++;
                    }
    
                    i++;
                }
    
                j++;
            }
    
            if (mini == INT_MAX)
                return "";
    
            return s.substr(start, mini);
        }
    };