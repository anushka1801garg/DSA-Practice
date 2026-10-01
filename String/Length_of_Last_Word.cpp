/*
Problem: Length of Last Word
LeetCode: 58
Link: https://leetcode.com/problems/length-of-last-word/

Approach:
- Traverse the string from the end.
- Ignore trailing spaces until the last word is reached.
- Count characters while they are not spaces.
- Once a space is encountered after counting characters, stop the loop.
- Return the count, which represents the length of the last word.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include<string>
using namespace std;

class Solution {
    public:
        int lengthOfLastWord(string s) {
            int count = 0;
            
            for(int i = s.length() - 1; i >= 0; i--) {
                if(s[i] != ' ') {
                    count++;
                } 
                else if(count == 0) {
                    continue;  
                }
                else {
                    break;   
                }
            }
            
            return count;
        }
    };