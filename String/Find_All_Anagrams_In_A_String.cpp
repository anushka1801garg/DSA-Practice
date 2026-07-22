/*
Problem: Find All Anagrams in a String
LeetCode: 438
Link: https://leetcode.com/problems/find-all-anagrams-in-a-string/

Approach:
- Store the frequency of each character in the pattern string using a hash map.
- Use a sliding window of size equal to the length of the pattern over the given string.
- As the window expands, decrease the frequency of matching characters and track the number of distinct characters whose required frequency has not yet been satisfied.
- When the window reaches the required size:
  - If all frequencies are matched, record the starting index of the window.
  - Restore the frequency of the outgoing character before sliding the window forward.
- Return the list of all starting indices where an anagram of the pattern is found.

Time Complexity: O(n + m)
Space Complexity: O(k)
*/

#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
    public:
        vector<int> findAnagrams(string s, string p) {
    
            int k = p.length();
            unordered_map<char, int> mp;
            vector<int> ans;
    
            for (int i = 0; i < p.length(); i++) {
                mp[p[i]]++;
            }
    
            int i = 0, j = 0;
            int count = mp.size();
    
            while (j < s.length()) {
                if (mp.find(s[j]) != mp.end()) {
                    mp[s[j]]--;
    
                    if (mp[s[j]] == 0) {
                        count--;
                    }
                }
    
                if (j - i + 1 < k) {
                    j++;
                }
                else if (j - i + 1 == k) {
    
                    if (count == 0)
                        ans.push_back(i);
                    if (mp.find(s[i]) != mp.end()) {
    
                        if (mp[s[i]] == 0)
                            count++;
    
                        mp[s[i]]++;
                    }
    
                    i++;
                    j++;
                }
            }
    
            return ans;
        }
    };