/*
Problem: Isomorphic Strings
LeetCode: 205
Link: https://leetcode.com/problems/isomorphic-strings/

Approach:
- If the two strings have different lengths, return `false`.
- Use two hash maps to maintain character mappings:
  - One from the first string to the second.
  - One from the second string to the first.
- Traverse both strings simultaneously.
- For each pair of characters, verify that any existing mapping is consistent.
- If no mapping exists, create it in both hash maps.
- If any mapping is inconsistent, return `false`.
- If all character mappings are valid, return `true`.

Time Complexity: O(n)
Space Complexity: O(n)
*/


#include<unordered_map>
#include<String>
using namespace std;

class Solution {
    public:
        bool isIsomorphic(string s, string t) {
            
            if(s.length() != t.length())
                return false;
            
            unordered_map<char, char> mapST;  // s -> t
            unordered_map<char, char> mapTS;  // t -> s
            
            for(int i = 0; i < s.length(); i++) {
                
                char c1 = s[i];
                char c2 = t[i];
                
                // If mapping exists, check consistency
                if(mapST.count(c1)) {
                    if(mapST[c1] != c2)
                        return false;
                }
                else {
                    mapST[c1] = c2;
                }
                
                // Reverse check (to prevent two chars mapping to same char)
                if(mapTS.count(c2)) {
                    if(mapTS[c2] != c1)
                        return false;
                }
                else {
                    mapTS[c2] = c1;
                }
            }
            
            return true;
        }
    };