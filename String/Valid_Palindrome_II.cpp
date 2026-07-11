/*
Problem: Valid Palindrome II
LeetCode: 680
Link: https://leetcode.com/problems/valid-palindrome-ii/

Approach:
- Use two pointers to compare characters from both ends of the string.
- Move the pointers inward while the characters match.
- If a mismatch occurs, try skipping either the left or the right character.
- Use a helper function to check whether the remaining substring is a palindrome.
- If either substring forms a palindrome, return `true`; otherwise, return `false`.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include<string>
using namespace std;

bool helper(int i,int j,string& s){
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
class Solution {
public:

bool validPalindrome(string s) {
    int i=0;
    int j=s.length()-1;
    while(i<j){
        if(s[i]==s[j]){
            i++;
            j--;
        }else{
            return helper(i+1,j,s)||helper(i,j-1,s);
        }
    }
    return true;
}
};