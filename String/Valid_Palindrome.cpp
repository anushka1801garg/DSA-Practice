/*
Problem: Valid Palindrome II
LeetCode: 680
Link: https://leetcode.com/problems/valid-palindrome-ii/

Approach:
- Use two pointers, one at the beginning and one at the end of the string.
- Move both pointers inward while the characters match.
- On encountering the first mismatch, try skipping either the left or the right character.
- Use a helper function to check whether the remaining substring is a palindrome.
- If either substring is a palindrome, return `true`; otherwise, return `false`.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include<string>
using namespace std;

class Solution {
    public:
        bool isPalindrome(string s) {
            int l=0;
            int r=s.length()-1;
            while(l<r){
                if(!isalnum(s[l])){
                    l++;
                }else if(!isalnum(s[r])){
                    r--;
                }else{
                    if(tolower(s[l])!=tolower(s[r])){
                        return false;
                    }else{
                        l++;
                        r--;
                    }
                }
            }
            return true;
        }
    };