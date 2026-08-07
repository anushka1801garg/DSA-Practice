/*
Problem: Find First Palindromic String in the Array
LeetCode: 2108
Link: https://leetcode.com/problems/find-first-palindromic-string-in-the-array/

Approach:
- Traverse each word in the given array.
- Use two pointers, `left` and `right`, starting from both ends of the current word.
- Compare the characters at both pointers while moving them toward the center.
- If any pair of characters does not match, the word is not a palindrome.
- If all characters match, return the current word immediately.
- If no palindromic word is found, return an empty string.

Time Complexity: O(n × m)
Space Complexity: O(1)
*/

#include<vector>
#include<string>
using namespace std;

class Solution {
    public:
        string firstPalindrome(vector<string>& words) {
    
            for(auto it : words) {
    
                int left = 0;
                int right = it.length() - 1;
                bool flag = true;
    
                while(left < right) {
    
                    if(it[left] != it[right]) {
                        flag = false;
                        break;
                    }
    
                    left++;
                    right--;
                }
    
                if(flag == true) {
                    return it;
                }
            }
    
            return "";
        }
    };