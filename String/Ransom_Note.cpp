/*
Problem: Ransom Note
LeetCode: 383
Link: https://leetcode.com/problems/ransom-note/

Approach:
- Use an `unordered_map` to store the frequency of each character in `magazine`.
- Traverse `ransomNote` character by character.
- Check whether the current character exists in the map.
- If the character is not available, return false.
- Otherwise, decrease its frequency to ensure each magazine character is used at most once.
- If all characters in `ransomNote` can be formed using `magazine`, return true.

Time Complexity: O(n + m) average
Space Complexity: O(1), since the character set is fixed.
*/

#include<unordered_map>
#include<string>
using namespace std;

class Solution {
    public:
        bool canConstruct(string ransomNote, string magazine) {
            unordered_map<char, int> mp;
    
            for(int i = 0; i < magazine.length(); i++) {
                mp[magazine[i]]++;
            }
    
            for(int i = 0; i < ransomNote.length(); i++) {
                if(mp.find(ransomNote[i]) == mp.end() ||
                   mp[ransomNote[i]] == 0) {
                    return false;
                }
                else {
                    mp[ransomNote[i]]--;
                }
            }
    
            return true;
        }
    };