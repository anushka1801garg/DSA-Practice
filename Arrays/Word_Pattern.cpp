/*
Problem: Word Pattern
LeetCode: 290
Link: https://leetcode.com/problems/word-pattern/

Approach:
- First, split the string `s` into individual words and store them in a vector.
- Check whether the number of words is equal to the length of the pattern.
- Use two hash maps to maintain a two-way mapping:
  - `mp` maps each pattern character to a word.
  - `mp1` maps each word to a pattern character.
- Traverse the pattern and words together.
- If a character is already mapped, check whether it maps to the same word.
- If a word is already mapped, check whether it maps to the same character.
- If either mapping is inconsistent, return false.
- If all mappings remain consistent, return true.

Time Complexity: O(n) average
Space Complexity: O(n)
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
    public:
        bool wordPattern(string pattern, string s) {
            
            vector<string> words;
            string temp = "";
    
            for(int i = 0; i < s.length(); i++) {
                if(s[i] == ' ') {
                    words.push_back(temp);
                    temp = "";
                }
                else {
                    temp += s[i];
                }
            }
            words.push_back(temp);  
            
    
            if(words.size() != pattern.size())
                return false;
    
            unordered_map<char, string> mp;      
            unordered_map<string, char> mp1;     
            for(int i = 0; i < pattern.size(); i++) {
                
                char c = pattern[i];
                string word = words[i];
                if(mp.count(c)) {
                    if(mp[c] != word)
                        return false;
                } else {
                    mp[c] = word;
                }
                if(mp1.count(word)) {
                    if(mp1[word] != c)
                        return false;
                } else {
                    mp1[word] = c;
                }
            }
            
            return true;
        }
    };