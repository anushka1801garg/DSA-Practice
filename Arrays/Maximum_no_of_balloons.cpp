/*
Problem: Maximum No of Balloons
LeetCode: 1189
Link: https://leetcode.com/problems/maximum-number-of-balloons/

Approach:
Use a hash map.
Count frequency of each character and store it in hashmap.
Then find the minimum possible count of "balloon".

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <unordered_map>
#include <string>

using namespace std;
class Solution {
    public:
        int maxNumberOfBalloons(string text) {
            unordered_map<char,int>mp;
            for(int i=0;i<text.size();i++){
                mp[text[i]]++;
            }
            int result = INT_MAX;
    
            result = min(result,mp['b']);
            result = min(result,mp['a']);
            result = min(result,mp['l'] / 2);
            result = min(result,mp['o'] / 2);
            result = min(result,mp['n']);
    
            return result;
        }
    };