/*
Problem: Minimum Add to Make Parentheses Valid
LeetCode: 921
Link: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

Approach:
- Maintain `open` to keep track of unmatched opening parentheses.
- Traverse the string character by character.
- For `(`, increment `open`.
- For `)`, if an unmatched `(` exists, decrement `open`.
- Otherwise, this `)` has no matching `(`, so increment `ans`.
- After the traversal, any remaining unmatched `(` must be closed, so add `open` to `ans`.
- Return `ans` as the minimum number of parentheses that need to be added.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include<stdio.h>
#include<string>
using namespace std;

class Solution {
    public:
        int minAddToMakeValid(string s) {
            int open = 0;
            int ans = 0;
    
            for(int i = 0; i < s.length(); i++) {
                if(s[i] == '(') {
                    open++;
                }
                else {
                    if(open > 0) {
                        open--;
                    }
                    else {
                        ans++;
                    }
                }
            }
    
            ans += open;
    
            return ans;
        }
    };