/*
Problem: Find the Difference
LeetCode: 389
Link: https://leetcode.com/problems/find-the-difference/

Approach:
- Use an `unordered_map` to store the frequency of each character in string `s`.
- Traverse string `t` and reduce the frequency of each character if it exists in the map.
- If a character is not available or its frequency becomes zero, increase its count in the map.
- After processing both strings, traverse the map.
- The character with a positive frequency is the extra character added to `t`.
- Return that character.

Time Complexity: O(n) average
Space Complexity: O(1)
*/

#include<unordered_map>
#include<string>
using namespace std;

class Solution {
    public:
        char findTheDifference(string s, string t) {
            unordered_map<char,int>mp;
            for(auto i:s){
                mp[i]++;
            }
            for(auto i:t){
                if(mp[i]>0){
                    mp[i]--;
                }else{
                    mp[i]++;
                }
            }
            for(auto i:mp){
                if(i.second>0){
                    return i.first;
                }
            }
            return '\0';
        }
    };