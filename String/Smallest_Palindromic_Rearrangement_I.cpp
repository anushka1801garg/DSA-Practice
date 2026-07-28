/*
Problem: Lexicographically Smallest Palindrome
LeetCode: Weekly Contest Problem

Approach:
- Find the midpoint of the palindrome.
- Sort the first half of the string in ascending order.
- Copy the sorted first half to the second half in reverse order to maintain the palindrome property.
- Return the resulting lexicographically smallest palindrome.

Time Complexity: O(n log n)
Space Complexity: O(1)
*/

#include<string>
using namespace std;

class Solution {
    public:
        string smallestPalindrome(string s) {
            int len = s.length();
            int partition = len / 2;
    
            sort(s.begin(), s.begin() + partition);
    
            for (int i = 0; i < partition; ++i) {
                s[len - 1 - i] = s[i];
            }
    
            return s;
        }
    };