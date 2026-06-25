/*
Problem: Valid Anagram
LeetCode: 242
Link: https://leetcode.com/problems/valid-anagram/

Approach:
Use two unordered maps to store the
frequency of characters in both strings.
Traverse each string and count occurrences.
Compare both maps:
- If frequencies match, return true.
- Otherwise, return false.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp,mp1;
        for(auto i:s){
            mp[i]++;
        }
        for(auto i:t){
            mp1[i]++;
        }
        if(mp==mp1){
            return true;
        }
        else{
            return false;
        }
    }
};