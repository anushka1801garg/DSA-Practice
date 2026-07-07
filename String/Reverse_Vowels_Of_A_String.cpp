/*
Problem: Reverse Vowels of a String
LeetCode: 345
Link: https://leetcode.com/problems/reverse-vowels-of-a-string/

Approach:
- Store all vowels in a hash set for O(1) lookup.
- Use two pointers, one at the beginning and one at the end of the string.
- Move the left pointer forward until it points to a vowel.
- Move the right pointer backward until it points to a vowel.
- Swap the vowels at the two pointers and continue until the pointers meet.
- Return the modified string with the vowels reversed.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowel = {'a','e','i','o','u','A','E','I','O','U'};
        int i = 0;
        int j = s.size() - 1;
        
        while (i < j) {
            if (!vowel.count(s[i])) {
                i++;
            } else if (!vowel.count(s[j])) {
                j--;
            } else {
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                i++;
                j--;
            }
        }
        return s;
    }
};
