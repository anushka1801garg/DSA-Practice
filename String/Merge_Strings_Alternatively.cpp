/*
Problem: Merge Strings Alternately
LeetCode: 1768
Link: https://leetcode.com/problems/merge-strings-alternately/

Approach:
- Use two pointers to traverse both strings simultaneously.
- Append one character from the first string, followed by one character from the second string.
- Continue until one of the strings is fully traversed.
- Append the remaining characters from the longer string, if any.
- Return the merged string.

Time Complexity: O(n + m)
Space Complexity: O(n + m)
*/

#include<string>
using namespace std;

class Solution {
    public:
        string mergeAlternately(string word1, string word2) {
            int i=0,j=0;
            string st="";
            while(i<word1.length() && j<word2.length()){
                st+=word1[i];
                st+=word2[j];
                i++;
                j++;
            }
            while(i<word1.length()){
                st+=word1[i];
                i++;
            }
            while(j<word2.length()){
                st+=word2[j];
                j++;
            }
            return st;
        }    
    };