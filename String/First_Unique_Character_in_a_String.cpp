/*
Problem: First Unique Character in a String
LeetCode: 387
Link: https://leetcode.com/problems/first-unique-character-in-a-string/

Approach:
- Use a hash map to count the frequency of each character in the string.
- Traverse the string once and update the frequency of every character.
- Traverse the string again and find the first character whose frequency is 1.
- Return the index of that character.
- If no unique character exists, return `-1`.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include<string>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        int firstUniqChar(string s) {
            unordered_map<char,int>mp;
            for(int i=0;i<s.length();i++){
                mp[s[i]]++;
            }
            for(int i=0;i<s.length();i++){
                if(mp[s[i]]==1){
                    return i;
                }
            }
            return -1;
        }
    };