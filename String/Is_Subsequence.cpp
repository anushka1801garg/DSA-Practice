/*
Problem: Is Subsequence
LeetCode: 392
Link: https://leetcode.com/problems/is-subsequence/

Approach:
- Use two pointers to traverse both strings.
- Pointer `i` keeps track of the current character in `s`.
- Pointer `j` traverses through string `t`.
- If `s[i]` matches `t[j]`, increment both pointers and increase the matched character count.
- If the characters do not match, move only the pointer `j` forward.
- After traversing `t`, check whether all characters of `s` were matched.
- Return `true` if the count is equal to the length of `s`; otherwise, return `false`.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include<string>
using namespace std;

class Solution {
    public:
        bool isSubsequence(string s, string t) {
            int i=0,j=0;
            int count=0;
            while(j<t.length()){
                if(s[i]==t[j]){
                    count++;
                    i++;
                    j++;
                }else{
                    j++;
                }
            }
            if(count==s.length()) return true;
            else return false;
        }
    };