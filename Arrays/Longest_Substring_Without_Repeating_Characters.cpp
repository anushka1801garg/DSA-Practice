/*
Problem: Longest Substring Without Repeating Characters
LeetCode: 3
Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

Approach:
- Use the sliding window technique with two pointers.
- Maintain a hash map to store the frequency of characters in the current window.
- Expand the window by moving the right pointer and adding the current character.
- If duplicate characters exist in the window, shrink the window from the left until all characters are unique.
- Update the maximum window length whenever the current window contains only unique characters.
- Return the length of the longest substring without repeating characters.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include<unordered_map>
#include<string>
using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int i=0,j=0,maxi=0;
            unordered_map<char,int>mp;
            while(j<s.length()){
                mp[s[j]]++;
                if(mp.size()==(j-i+1)){
                    maxi=max(maxi,j-i+1);
                    j++;
                }else if(mp.size()<j-i+1){
                    while(mp.size()<j-i+1){
                        mp[s[i]]--;
                        if(mp[s[i]]==0){
                            mp.erase(s[i]);
                        }
                        i++;
                    }
                    j++;
                }
            }
            return maxi;
        }
    };