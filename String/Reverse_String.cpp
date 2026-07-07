/*
Problem: Reverse String
LeetCode: 344
Link: https://leetcode.com/problems/reverse-string/

Approach:
- Use two pointers, one at the beginning and one at the end of the character array.
- Swap the characters at the two pointers.
- Move the left pointer forward and the right pointer backward.
- Continue until the two pointers meet or cross.
- The string is reversed in-place without using extra space.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include<String>
#include<vector>
using namespace std;

class Solution {
    public:
        void reverseString(vector<char>& s) {
            int i=0;
            int j=s.size()-1;
            while(i<j){
                char temp=s[i];
                s[i]=s[j];
                s[j]=temp;
                i++;
                j--;
            }
        }
    };