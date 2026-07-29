/*
Problem: Rearrange String
LeetCode: Weekly Contest Problem

Approach:
- Traverse the string and append all characters except `x` and `y` to the result.
- Traverse the string again and append all occurrences of `y`.
- Traverse the string one final time and append all occurrences of `x`.
- Return the rearranged string.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include<string>
using namespace std;

class Solution {
    public:
        string rearrangeString(string s, char x, char y) {
            string ans="";
            for(auto it:s){
                if(it!=x && it!=y) ans+=it;
            }
            for(auto it:s){
                if(it==y) ans+=it;
            }
            for(auto it:s){
                if(it==x) ans+=it;
            }
            return ans;
        }
    };